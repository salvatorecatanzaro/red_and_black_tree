#ifndef VERTEX_H
#define VERTEX_H
#include "RBTree.h"
#include <string>
using namespace std;

class RBTree;

class Vertex
{
    public:
        /** Default constructor */
        Vertex();
        Vertex(int val);
        /** Default destructor */
        virtual ~Vertex();

        /** Setters */
        void setValue(int value){this->value = value;};
        void setRBTree(RBTree *rbtree){this->rbtree = rbtree;};
        void setColor(string *color){this->color = color;};
        void setPredecessor(Vertex *v){this->predecessor = v;};
        void setDistance(int distance){this->distance = distance;};

        /** Getters */
        RBTree* getRBTree(){return this->rbtree;};
        int getValue(){return this->value;};
        string* getColor(){return this->color;};
        Vertex* getPredecessor(){return this->predecessor;};
        int getDistance(){return this->distance;};
    protected:

    private:
        int value;
        RBTree *rbtree;
        string *color;
        Vertex *predecessor;
        int distance;
};

#endif // VERTEX_H
