#include "RBTree.h"
#include "RBNode.h"
#include <iostream>
#include <string.h>
#include "Queue.h"

static string *BLACK = new string("Black");
static string *RED = new string("Red");
static string *GRAY = new string("Gray");

RBTree::RBTree()
{
    this->tnil = new RBNode();
    this->tnil->setColor(BLACK);
    this->troot = tnil;
}

RBTree::~RBTree()
{
    //dtor
}

void RBTree::preOrderTreeWalk(RBTree *rbtree, RBNode *x, int level)
{
    if(x != rbtree->tnil)
    {
        cout << "Level " << level++ << " node key " << x->getKey()  << " node color " << *(x->getColor()) <<endl;
        RBTree::preOrderTreeWalk(rbtree, x->getLeft(), level);
        RBTree::preOrderTreeWalk(rbtree, x->getRight(), level);

    }
}


void RBTree::POTWAddToQueue(RBNode *x, Vertex *f, Queue<Vertex> *q)
{
    if(x != this->tnil)
    {
        Vertex *v = x->getVertex();

        if(v->getColor()->compare("White") == 0)
        {
            v->setColor(GRAY);
            v->setDistance(f->getDistance() + 1);
            v->setPredecessor(f);
            q->enqueue(v);
        }
        this->POTWAddToQueue(x->getLeft(), f, q);
        this->POTWAddToQueue(x->getRight(), f, q);
    }
}


void RBTree::inOrderTreeWalk(RBTree *rbtree, RBNode *x, int level)
{
    level++;
    if(x != rbtree->tnil)
    {
        RBTree::inOrderTreeWalk(rbtree, x->getLeft(), level);
        cout << "Level " << level << " node key " << x->getKey()  << " node color " << *(x->getColor()) <<endl;
        RBTree::inOrderTreeWalk(rbtree, x->getRight(), level);

    }
}


void RBTree::rightRotate(RBNode *x)
{
    RBNode *y = x->getLeft();
    x->setLeft(y->getRight());

    if(y->getRight() != this->getTnil())
        y->getRight()->setFather(x);

    y->setFather(x->getFather());
    cout << x->getKey();
    if(x->getFather() == this->getTnil())
        this->setRoot(y);
    else if(x->getFather()->getRight() == x)
        x->getFather()->setRight(y);
    else
        x->getFather()->setLeft(y);

    y->setRight(x);
    x->setFather(y);
}


void RBTree::leftRotate(RBNode *x)
{
    RBNode *y = x->getRight();
    x->setRight(y->getLeft());

    if(y->getLeft() != this->getTnil())
        y->getLeft()->setFather(x);

    y->setFather(x->getFather());
    if(x->getFather() == this->getTnil())
        this->setRoot(y);
    else if(x->getFather()->getLeft() == x)
        x->getFather()->setLeft(y);
    else
        x->getFather()->setRight(y);

    y->setLeft(x);
    x->setFather(y);
}

void RBTree::rbInsert(Vertex *vertex_j)
{
    RBNode *z = new RBNode(vertex_j);
    RBNode *y = this->tnil;
    RBNode *x = this->troot;
    while(x != tnil)
    {
        y = x;
        if(z->getKey() < x->getKey())
            x = x->getLeft();
        else
            x = x->getRight();
    }
    z->setFather(y);
    if(y == this->tnil)
        this->troot = z;
    else if(z->getKey() < y->getKey())
        y->setLeft(z);
    else
        y->setRight(z);
    z->setLeft(this->tnil);
    z->setRight(this->tnil);
    z->setColor(RED);
    this->rbInsertFixup(z);
}


RBNode* RBTree::treeMinimum(RBNode *x)
{
    while(x->getLeft() != this->getTnil())
        x = x->getLeft();
    return x;
}

void RBTree::rbInsertFixup(RBNode *z)
{
    while(z->getFather()->getColor()->compare("Red") == 0)
    {
        if(z->getFather() == z->getFather()->getFather()->getLeft())
        {
            RBNode *y = z->getFather()->getFather()->getRight();
            if(y->getColor()->compare("Red") == 0)
            {
                // 1 case scenario
                z->getFather()->setColor(BLACK);
                y->setColor(BLACK);
                z->getFather()->getFather()->setColor(RED);
                z = z->getFather()->getFather();
            }
            else
            {
                if(z == z->getFather()->getRight())
                {
                // 2 case scenario
                z = z->getFather();
                this->leftRotate(z);
                }
                // 3 case scenario
                z->getFather()->setColor(BLACK);
                z->getFather()->getFather()->setColor(RED);
                this->rightRotate(z->getFather()->getFather());
            }
        }
        else
        {
            RBNode *y = z->getFather()->getFather()->getLeft();
            if(y->getColor()->compare("Red") == 0)
            {
                // 1 case scenario
                z->getFather()->setColor(BLACK);
                y->setColor(BLACK);
                z->getFather()->getFather()->setColor(RED);
                z = z->getFather()->getFather();
            }
            else
            {
                if(z == z->getFather()->getLeft())
                {
                    // 2 case scenario
                    z = z->getFather();
                    this->rightRotate(z);
                }
                // 3 case scenario
                z->getFather()->setColor(BLACK);
                z->getFather()->getFather()->setColor(RED);
                this->leftRotate(z->getFather()->getFather());
            }

        }
    }
    this->getRoot()->setColor(BLACK);

}


int RBTree::getBHeight()
{
    RBNode *x = this->getRoot();
    int height = 0;
    while(x != this->getTnil())
    {
        if(x->getColor()->compare("Black") == 0)
            height++;
        x = x->getLeft();
    }
    return height;
}


RBNode* RBTree::treeSearch(RBNode *x, int j)
{
    if(x == this->getTnil() || j == x->getKey())
        return x;
    if(j < x->getKey())
        return treeSearch(x->getLeft(), j);
    else
        return treeSearch(x->getRight(), j);
}


void RBTree::rbTransplant(RBNode *u, RBNode *v)
{
    if(u->getFather() == this->getTnil())
        this->setRoot(v);
    else if(u->getFather()->getLeft() == u)
        u->getFather()->setLeft(v);
    else
        u->getFather()->setRight(v);
    v->setFather(u->getFather());
}


void RBTree::rbDelete(RBNode *z)
{
    RBNode *x;
    RBNode *y = z;
    string *yOriginalColor = y->getColor();
    cout << z->getKey();
    if(z->getLeft() == this->getTnil())
    {
        x = z->getRight();
        this->rbTransplant(z, z->getRight());
    }
    else if(z->getRight() == this->getTnil())
    {
        x = z->getLeft();
        this->rbTransplant(z, z->getLeft());
    }
    else
    {
        y = treeMinimum(z->getRight());
        yOriginalColor = y->getColor();
        x = y->getRight();
        if(y->getFather() == z)
            x->setFather(y);
        else
        {
            this->rbTransplant(y, y->getRight());
            y->setRight(z->getRight());
            y->getRight()->setFather(z);
        }
        this->rbTransplant(z, y);
        y->setLeft(z->getLeft());
        y->getLeft()->setFather(y);
        y->setColor(z->getColor());
    }
    if(yOriginalColor->compare("Black") == 0)
        this->rbDeleteFixup(x);

}

void RBTree::rbDeleteFixup(RBNode *x)
{
    RBNode *w;
    while(x != this->getRoot() && (x->getColor()->compare("Black") == 0))
    {
        if(x == x->getFather()->getLeft())
        {
            w = x->getFather()->getRight();
            if(w->getColor()->compare("Red"))
            {
                // 1 case scenario (used to transform this scenario in scenario [2, 3 or 4])
                w->setColor(BLACK);
                x->getFather()->setColor(RED);
                this->leftRotate(x->getFather());
                w = x->getFather()->getRight();
            }
            if((w->getLeft()->getColor()->compare("Black") == 0) && (w->getRight()->getColor()->compare("Black") == 0))
            {
                // 2 case scenario
                w->setColor(RED);
                x = x->getFather();
            }
            else
            {
                if(w->getRight()->getColor()->compare("Black"))
                {
                    w->getLeft()->setColor(BLACK);
                    w->setColor(RED);
                    rightRotate(w);
                    w = x->getFather()->getRight();
                }
                w->setColor(x->getFather()->getColor());
                x->getFather()->setColor(BLACK);
                w->getRight()->setColor(BLACK);
                leftRotate(x->getFather());
                x = this->getRoot();
            }
        }
        else
        {
            w = x->getFather()->getLeft();
            if(w->getColor()->compare("Red"))
            {
                // 1 case scenario (used to transform this scenario in scenario [2, 3 or 4])
                w->setColor(BLACK);
                x->getFather()->setColor(RED);
                this->rightRotate(x->getFather());
                w = x->getFather()->getLeft();
            }
            if((w->getRight()->getColor()->compare("Black") == 0) && (w->getLeft()->getColor()->compare("Black") == 0))
            {
                // 2 case scenario
                w->setColor(RED);
                x = x->getFather();
            }
            else
            {
                if(w->getLeft()->getColor()->compare("Black"))
                {
                    w->getRight()->setColor(BLACK);
                    w->setColor(RED);
                    leftRotate(w);
                    w = x->getFather()->getLeft();
                }
                w->setColor(x->getFather()->getColor());
                x->getFather()->setColor(BLACK);
                w->getLeft()->setColor(BLACK);
                rightRotate(x->getFather());
                x = this->getRoot();
            }

        }
    }
    x->setColor(BLACK);
}
