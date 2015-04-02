#ifndef NODE_H_
#define NODE_H_ value

class Node
{
public:
  enum nodeType {Closed, Open, Checkpoint, Start, End, Unknown};
  Node (int _id, Node::nodeType _type) {
    type = _type;
    id = _id;
  };

  Node (int _id, char c) {
    type = parseType(c);
    id = _id;
  }
  Node::nodeType parseType(char c) {
    switch (c) {
      case '#': return Closed;
      case '.': return Open;
      case '@': return Checkpoint;
      case 'S': return Start;
      case 'G': return End;
    }
    return Unknown;
  }
private:
  int id;
  Node::nodeType type;
};

#endif /* NODE_H_ */
