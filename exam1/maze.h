#ifndef MAZE_H_
#define MAZE_H_ value

#include <queue>
#include <vector>
#include <iostream>

using namespace std;

#include "node.h"

class Maze
{
public:
  Maze ();
  ~Maze();
  int parse();

  int **buildGraph();
private:
  void bfs(Node *, vector<int> &);
  void addEdge(int, queue<int> &);
  vector<Node *> data;
  vector<int> checkpoints;
  int start, end;

  int height, width;
};
#endif /* MAZE_H_ */
