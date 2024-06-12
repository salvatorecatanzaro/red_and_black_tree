#include "RBNode.h"
#include <iostream>
using namespace std;
RBNode::RBNode()
{
    //ctor
}

RBNode::RBNode(Vertex *vertex)
{
    this->key = vertex->getValue();
    this->setVertex(vertex);
}

RBNode::~RBNode()
{
    //dtor
}
