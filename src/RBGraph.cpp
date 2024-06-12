#include "RBGraph.h"
#include "Vertex.h"
#include "LinkedListNode.h"
#include "Queue.h"
#include <iostream>

static string *WHITE = new string("White");
static string *GRAY = new string("Gray");
static string *BLACK = new string("Black");

RBGraph::RBGraph()
{
    this->v = nullptr;
    //ctor
}

RBGraph::~RBGraph()
{
    //dtor
}


bool RBGraph::findEdge(int i, int j)
{
    Vertex *v = this->getVertexList()[i];
    if(v == nullptr)
        return false;
    RBNode *result = v->getRBTree()->treeSearch(v->getRBTree()->getRoot(), j);
    if(result == v->getRBTree()->getTnil())
        return false;
    return true;
}


void RBGraph::removeEdge(int i, int j)
{
    Vertex *v = this->getVertexList()[i];
    if(v == nullptr)
    {
        cout << "not found" << endl;
        return;
    }
    RBNode *z = v->getRBTree()->treeSearch(v->getRBTree()->getRoot(), j);
    if(z != v->getRBTree()->getTnil())
        v->getRBTree()->rbDelete(z);
    else
        cout << "not found" << endl;
}


void RBGraph::addEdge(Vertex *i, Vertex *j)
{
    // FIND EDGE, SE ESISTE, NON INSERIRE
    i->getRBTree()->rbInsert(j);// add red black
}


void RBGraph::printRBGraph()
{
    Vertex** vList = this->getVertexList();
    for(int i = 0; i < this->getSize(); i++)
    {
        if(vList[i] == nullptr)
            continue;
        cout << "===================================================" << endl;
        cout << "Vertex: " << vList[i]->getValue() << endl;
        cout << "RBTree B altezza " << vList[i]->getRBTree()->getBHeight() << endl;
        cout << "Livelli:" << endl;
        RBTree::preOrderTreeWalk(vList[i]->getRBTree(), vList[i]->getRBTree()->getRoot(), 0);
        cout << "===================================================" << endl;
    }
}


void RBGraph::BFS(Vertex *source)
{
    Vertex **vlist = this->getVertexList();
    Vertex *v;
    // init all the nodes but the source
    for(int i = 0; i < this->getSize(); i++)
    {
        v = vlist[i];
        if(v == source)
            continue;

        v->setColor(WHITE);
        v->setDistance(0);
        v->setPredecessor(nullptr);
    }
    source->setColor(GRAY);
    source->setDistance(0);
    source->setPredecessor(nullptr);

    Queue<Vertex> *q = new Queue<Vertex>(this->getSize());
    q->enqueue(source);
    cout <<"BFS: " << endl;
    int distance = 1;
    while(q->getSize() != 0)
    {
        Vertex *u = q->dequeue();
        cout << "Node value " << u->getValue() << "  distance " << u->getDistance() << endl;
        RBTree *vertexTree = u->getRBTree();
        if(vertexTree->getRoot() == vertexTree->getTnil())
            continue;   // empty tree
        vertexTree->POTWAddToQueue(vertexTree->getRoot(), u, q);
        u->setColor(BLACK);
    }
    cout <<"BFS: END" << endl;
}
