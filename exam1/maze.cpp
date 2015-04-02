#include <set>
#include <climits>
#include <algorithm>

using namespace std;

#include "maze.h"

Maze::Maze() {
  start = -1;
  end = -1;
}

//release all Node stored in data vector
Maze::~Maze() {
  vector<Node *>::iterator it;
  for (it = data.begin(); it != data.end(); ++it) {
    delete *it;
  }
}

int **
Maze::buildGraph()
{
  int size = checkpoints.size() + 2;
  //initial distance table
  int **disTable = new int *[size];
  for (int i = 0; i < size; ++i) {
    disTable[i] = new int[size];
    disTable[i][i] = 0;
  }

  return disTable;
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
  if (data[idx]->getType() != Node::nodeType::Closed) {
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
  vec.reserve(checkpoints.size() + 2);
  queue<int> open;
  set<int> closed;

  open.push(node->getId());
  closed.insert(node->getId());
  node->setDistance(0);
  while(!open.empty()) {
    int current = open.front();
    addEdge(current, open);
    closed.insert(current);
    open.pop();
  }
}

int
Maze::parse() {
  cin >> width >> height;

  string buf;
  string::const_iterator it;
  int id = 0;
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
  if (start == -1 or end == -1) {
    return -1;
  }
  return 0;
}
