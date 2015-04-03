#include <algorithm>
#include <climits>
#include <vector>

#include "maze.h"

class Orienteering {
public:
  void main();
  int solveTSP(vector<vector<int> > &);
private:
  Maze *maze;
  int numPoints;
};

int
Orienteering::solveTSP(vector<vector<int> > &disTable)
{
  //add dummy node only connect to end node, force TSP stop there
  disTable.push_back(vector<int>(numPoints-1, -1));
  for (int i = 0; i < numPoints; ++i) {
    disTable[i].push_back(-1);
    disTable[i][i] = -1;
  }
  disTable[numPoints-2][numPoints-1] = 0;
  disTable[numPoints-1][numPoints-2] = 0;

  return 0;
}

void Orienteering::main() {
  maze = new Maze();
  if(maze->parse()) {
    cout << -1;
    return;
  }
  vector<vector<int> >vec;
  maze->buildGraph(vec);

  //search unreachable checkpoints, print -1 if there is unreachable
  for (auto row : vec) {
    if (find(row.begin(), row.end(), INT_MAX) != row.end()) {
      cout << -1;
      return;
    }
  }

  numPoints = vec.size() + 1;
  cout << solveTSP(vec);
}

int main(int argc, char* argv[]) {
  Orienteering o;
  o.main();
  return 0;
}
