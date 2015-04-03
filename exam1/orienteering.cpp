#include <algorithm>
#include <climits>
#include <vector>
#include <cstring>

#include "maze.h"

class Orienteering {
public:
  // a number that is large enough for this map
  enum {largeNum = 1000};

  void main();
  int solveTSP();
  int dp(int at, int mask);
private:
  Maze *maze;
  vector<vector<int> > disTable;
  int numPoints;
  bool **visited;
  int  **distance;
};

int
Orienteering::solveTSP()
{
  //add dummy node only connect to end node, force TSP stop there
  disTable.push_back(vector<int>(numPoints-1, -1));
  for (int i = 0; i < numPoints; ++i) {
    disTable[i].push_back(-1);
    disTable[i][i] = -1;
  }
  disTable[numPoints-2][numPoints-1] = 0;
  disTable[numPoints-1][numPoints-2] = 0;

  //initial data structure used in dp
  visited = new bool *[numPoints];
  distance = new int *[numPoints];
  for (int i = 0; i < numPoints; ++i) {
    visited[i] = new bool[1 << numPoints];
    memset(visited[i], false, (1 << numPoints));
    distance[i] = new int[1 << numPoints];
    memset(distance[i], 0, (1 << numPoints));
  }

  return dp(0, 1);
}

int
Orienteering::dp(int at, int mask)
{
  // all visited
  if (mask == (1<<numPoints)-1) {
    visited[at][mask] = true;
    return distance[at][mask];
  }
  if (visited[at][mask]) {
    return distance[at][mask];
  }

  visited[at][mask] = true;

  int ans = largeNum;
  int cost;

  for (int i = 0; i < numPoints; ++i) {
    if (disTable[at][i] != -1 and !(mask & (1 << i))) {
      cost = dp(i, mask | (1 << i)) + disTable[at][i];
      if (ans > cost) {
        ans = cost;
      }
    }
  }
  return distance[at][mask] = ans;
}

void Orienteering::main() {
  maze = new Maze();
  if(maze->parse()) {
    cout << -1;
    return;
  }
  maze->buildGraph(disTable);

  //search unreachable checkpoints, print -1 if there is unreachable
  for (auto row : disTable) {
    if (find(row.begin(), row.end(), INT_MAX) != row.end()) {
      cout << -1;
      return;
    }
  }

  numPoints = disTable.size() + 1;
  cout << solveTSP();
}

int main(int argc, char* argv[]) {
  Orienteering o;
  o.main();
  return 0;
}
