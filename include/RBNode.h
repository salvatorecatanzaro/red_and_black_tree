#ifndef RBNODE_H
#define RBNODE_H
#include "Vertex.h"
#include <string>

using namespace std;


// Since there is a cyclic dependency, I need to forward declare Vertex
class Vertex;


class RBNode
{
    public:
        /** Default constructor */
        RBNode();
        RBNode(Vertex *v);
        /** Default destructor */
        virtual ~RBNode();

        /** Setters */
        void setColor(string *color){this->color = color;};
        void setKey(int key){this->key = key;};
        void setLeft(RBNode *left){this->left = left;};
        void setRight(RBNode *right){this->right = right;};
        void setFather(RBNode *father){this->father = father;};
        void setVertex(Vertex *vertex){this->vertex = vertex;};

        /** Getters */
        string* getColor(){return this->color;};
        int getKey(){return this->key;};
        RBNode* getLeft(){return this->left;};
        RBNode* getRight(){return this->right;};
        RBNode* getFather(){return this->father;};
        Vertex* getVertex(){return this->vertex;};

    protected:

    private:
        string *color;
        int key;
        RBNode *left;
        RBNode *right;
        RBNode *father;
        Vertex *vertex;
};

#endif // RBNODE_H
