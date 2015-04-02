#ifndef MAP_H_
#define MAP_H_ value

#include <vector>
#include <iostream>

using namespace std;

#include "node.h"

class Map
{
public:
  Map ();
  ~Map();
  void parse();
private:
  vector<Node *> data;
  vector<int> checkpoints;
  int start, end;

  int height, width;
};
#endif /* MAP_H_ */
