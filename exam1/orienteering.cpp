
#include "maze.h"

class Orienteering {
public:
  void main();
private:
  Maze *maze;
};

void Orienteering::main() {
  maze = new Maze();
  maze->parse();
}

int main(int argc, char* argv[]) {
  Orienteering o;
  o.main();
  return 0;
}
