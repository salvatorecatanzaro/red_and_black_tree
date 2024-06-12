#include "LinkedListNode.h"
#include "Vertex.h"
#include <iostream>


template <typename T>
LinkedListNode<T>::LinkedListNode()
{
    this->data = nullptr;
    this->next = nullptr;
}

template <typename T>
LinkedListNode<T>::~LinkedListNode()
{
    //dtor
}

template <typename T>
LinkedListNode<T>::LinkedListNode(T *data)
{
     this->data = data;
     this->next = nullptr;
}


template <typename T>
void LinkedListNode<T>::addnode(LinkedListNode<T> *head, T *new_element)
{
    LinkedListNode<T> *new_node = new LinkedListNode<T>(new_element);

    new_node->setData(new_element);
    while(head->getNext() != nullptr)
    {
        std::cout << "test"<< head->getData()->getValue() << std::endl;
        head = head->getNext();
    }
    head->setNext(new_node);
}


// Telling compiler which class template can assume
template class LinkedListNode<Vertex>;
