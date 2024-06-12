#ifndef LINKEDLISTNODE_H
#define LINKEDLISTNODE_H
#include "Vertex.h"
template <typename T>
class LinkedListNode
{
    public:
        /** Default constructor */
        LinkedListNode();
        LinkedListNode(T *data);
        /** Default destructor */
        virtual ~LinkedListNode();

        /** Utility methods*/
        void addnode(LinkedListNode<T> *head, T *new_element);

        /** Getters */
        T* getData(){return this->data;};
        LinkedListNode<T>* getNext(){return this->next;};

        /** Setters */
        void setNext(LinkedListNode<T> *node){this->next = node;};
        void setData(T *data){this->data = data;};

    protected:

    private:
        LinkedListNode<T> *next;
        T *data;

};

#endif // LINKEDLISTNODE_H
