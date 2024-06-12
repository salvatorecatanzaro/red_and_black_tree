#ifndef RBTREE_H
#define RBTREE_H
#include "RBNode.h"
#include "Queue.h"
#include "Vertex.h"


// Since there is a cyclic dependency, I need to forward declare Vertex
class Vertex;
class RBNode;


class RBTree
{
    public:
        /** Default constructor */
        RBTree();
        /** Default destructor */
        ~RBTree();

        /** Utilities */
        void rbInsert(Vertex *j);
        void leftRotate(RBNode *x);
        void rightRotate(RBNode *x);
        RBNode* treeSearch(RBNode *x, int j);
        static void preOrderTreeWalk(RBTree *rbtree, RBNode *x, int level);
        void POTWAddToQueue(RBNode *x, Vertex *father, Queue<Vertex> *q);
        static void inOrderTreeWalk(RBTree *rbtree, RBNode *x, int level);
        void rbInsertFixup(RBNode *z);
        void rbDelete(RBNode *z);
        void rbTransplant(RBNode *u, RBNode *v);
        int getBHeight();
        RBNode* treeMinimum(RBNode *x);
        void rbDeleteFixup(RBNode *x);

        /** Setters */
        void setRoot(RBNode *troot){this->troot = troot;};
        void setTnil(RBNode *tnil){this->tnil = tnil;};

        /** Getters */
        RBNode* getRoot(){return this->troot;};
        RBNode* getTnil(){return this->tnil;};

    protected:

    private:
        RBNode *tnil;
        RBNode *troot;
};

#endif // RBTREE_H
