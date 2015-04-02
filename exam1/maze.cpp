#include <climits>
#include <algorithm>

using namespace std;

#include "maze.h"

Maze::Maze() {}

//release all Node stored in data vector
Maze::~Maze() {
  vector<Node *>::iterator it;
  for (it = data.begin(); it != data.end(); ++it) {
    delete *it;
  }
}

void
Maze::buildGraph(vector<vector<int> > &disTable)
{
  int size = checkpoints.size();
  //initial distance table
  disTable.resize(size);
  for (int i = 0; i < size; ++i) {
    disTable[i].resize(size);
  }

  vector<int> vec;

  for (int i = 0; i < checkpoints.size(); ++i) {
    bfs(data[checkpoints[i]], vec);
    copy(vec.begin(), vec.end(), disTable[i].begin());
  }
}

void
Maze::addEdge(int current, queue<int> &open)
{
  //up
  if (current - width >= 0) {
    updateNode(current - width, data[current]->getDistance() + 1, open);
  }
  //down
  if (current + width < width * height) {
    updateNode(current + width, data[current]->getDistance() + 1, open);
  }
  //left
  if (current % width != 0) {
    updateNode(current - 1, data[current]->getDistance() + 1, open);
  }
  //right
  if (current % width != (width -1)) {
    updateNode(current + 1, data[current]->getDistance() + 1, open);
  }
}

void Maze::updateNode(int idx, int distance, queue<int> &open)
{
  if (data[idx]->getType() != Node::nodeType::Closed and
      data[idx]->getDistance() == INT_MAX) {
    data[idx]->setDistance(distance);
    open.push(idx);
  }
}

//Run bfs search on specific node
//filled the vec with distance to start, checkpoints, end
void
Maze::bfs(Node *node, vector<int> &vec)
{
  //clear all node distance as int_MAX
  for (auto i : data) {
    i->setDistance(INT_MAX);
  }
  vec.resize(checkpoints.size());
  queue<int> open;

  open.push(node->getId());
  node->setDistance(0);
  while(!open.empty()) {
    int current = open.front();
    addEdge(current, open);
    open.pop();
  }

  //update distance table
  for (int i = 0; i < checkpoints.size(); ++i) {
    vec[i] = data[checkpoints[i]]->getDistance();
  }
}

int
Maze::parse() {
  cin >> width >> height;

  string buf;
  string::const_iterator it;
  int id = 0;
  int start = -1;
  int end = -1;
  for (int i = 0; i < height; ++i) {
    cin >> buf;
    for (it = buf.cbegin(); it != buf.cend(); it++) {
      data.push_back(new Node(id, *it));

      Node::nodeType type = data.back()->getType();
      if (type == Node::nodeType::Checkpoint) {
        checkpoints.push_back(id);
      } else if (type == Node::nodeType::Start) {
        start = id;
      } else if (type == Node::nodeType::End) {
        end = id;
      }

      id++;
    }
  }
  checkpoints.insert(checkpoints.begin(), start);
  checkpoints.push_back(end);
  if (start == -1 or end == -1) {
    return -1;
  }
  return 0;
}
