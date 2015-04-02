#include "map.h"

Map::Map() {
}

//release all Node stored in data vector
Map::~Map() {
  vector<Node *>::iterator it;
  for (it = data.begin(); it != data.end(); ++it) {
    delete *it;
  }
}
