#include <algorithm>
#include <climits>

#include "maze.h"

class Orienteering {
public:
  void main();
private:
  Maze *maze;
};

void Orienteering::main() {
  maze = new Maze();
  if(maze->parse()) {
    cout << -1;
    return;
  }
  vector<vector<int> >vec;
  maze->buildGraph(vec);

  for (auto row : vec) {
    if (find(row.begin(), row.end(), INT_MAX) != row.end()) {
      cout << -1;
      return;
    }
  }

}

int main(int argc, char* argv[]) {
  Orienteering o;
  o.main();
  return 0;
}
