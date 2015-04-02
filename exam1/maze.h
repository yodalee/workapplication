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

  void buildGraph(vector<vector<int> > &);
private:
  void bfs(Node *, vector<int> &);
  void addEdge(int, queue<int> &);
  void updateNode(int, int, queue<int> &);
  vector<Node *> data;
  vector<int> checkpoints;

  int height, width;
};
#endif /* MAZE_H_ */
