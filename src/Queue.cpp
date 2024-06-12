#include "Queue.h"
#include "Vertex.h"
#include <iostream>

using namespace std;


template <typename T>
Queue<T>::Queue(int len)
{
    this->queue = new T*[len]();
    this->top = 0;
    this->bottom = -1;
    this->capacity = len;
    this->q_size = 0;
}


template <typename T>
Queue<T>::~Queue()
{
    //dtor
}


template <typename T>
void Queue<T>::enqueue(T *element)
{
    this->setBottom((this->getBottom() + 1) % this->getCapacity());
    this->getQueue()[this->getBottom()] = element;
    int currentSize = this->getSize();
    this->setSize(++currentSize);
}


template <typename T>
T* Queue<T>::dequeue()
{
    T *frontElement;
    if(this->getSize() == 0)
    {
        cout << "The queue is empty" <<endl;
        return frontElement;
    }
    frontElement = this->getQueue()[this->getTop()];
    this->setTop((this->top + 1) % this->getCapacity());
    int currentSize = this->getSize();
    this->setSize(--currentSize);
    return frontElement;
}


template <typename T>
void Queue<T>::printQueue()
{
    cout << "===================================================" << endl;
    cout << "Queue size: " << this->getSize() <<" Queue top: " << this->getTop() << " Queue bottom" << this->getBottom() <<endl;
    T **q = this->getQueue();
    for(int i=this->getTop(); i<=this->getBottom(); i++)
    cout << "Q Elem:" << q[i]->getValue() << endl;
    cout << "===================================================" << endl;
}

// Telling compiler which class template can assume
template class Queue<Vertex>;
