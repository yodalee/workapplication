
#include "map.h"

class Orienteering {
public:
  void main();
private:
  Map *map;
};

void Orienteering::main() {
  map = new Map();
  map->parse();
}

int main(int argc, char* argv[]) {
  Orienteering o;
  o.main();
  return 0;
}
