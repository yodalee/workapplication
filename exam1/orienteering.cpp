
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
  }
}

int main(int argc, char* argv[]) {
  Orienteering o;
  o.main();
  return 0;
}
