#ifndef MAZE_H_
#define MAZE_H_ value

#include <vector>
#include <iostream>

using namespace std;

#include "node.h"

class Maze
{
public:
  Maze ();
  ~Maze();
  void parse();
private:
  vector<Node *> data;
  vector<int> checkpoints;
  int start, end;

  int height, width;
};
#endif /* MAZE_H_ */
