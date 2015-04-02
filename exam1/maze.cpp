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

int Maze::parse() {
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
