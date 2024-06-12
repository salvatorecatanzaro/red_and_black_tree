#ifndef RBGRAPH_H
#define RBGRAPH_H
#include "LinkedListNode.h"
#include "Vertex.h"
#include <string>
#include "Queue.h"

using namespace::std;

class RBGraph
{
    public:
        /** Default constructor */
        RBGraph();
        /** Default destructor */
        ~RBGraph();
        Vertex* findNode(Vertex *head, int i);
        void printRBGraph();
        void addEdge(Vertex *i, Vertex *j);
        void removeEdge(int i, int j);
        bool findEdge(int i, int j);
        void BFS(Vertex *s);
        int getSize(){return this->gsize;};
        void setSize(int gsize){this->gsize = gsize;};
        Vertex** getVertexList(){return this->v;};
        void setVertexList(Vertex** v){this->v = v;};
    protected:

    private:
        Vertex **v;
        int gsize;
};

#endif // RBGRAPH_H
