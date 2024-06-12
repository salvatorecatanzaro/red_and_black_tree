#include "Vertex.h"
#include "RBTree.h"


Vertex::Vertex()
{
    this->rbtree = new RBTree();//ctor
}

Vertex::Vertex(int val)
{
    this->value = val;
    this->rbtree = new RBTree();//ctor
}

Vertex::~Vertex()
{
    //dtor
}
