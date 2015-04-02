#include "map.h"

Map::Map() {
  start = -1;
  end = -1;
}

//release all Node stored in data vector
Map::~Map() {
  vector<Node *>::iterator it;
  for (it = data.begin(); it != data.end(); ++it) {
    delete *it;
  }
}

void Map::parse() {
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
}
