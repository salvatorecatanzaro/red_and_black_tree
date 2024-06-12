#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "ListElement.h"

class LinkedList
{
    public:
        /** Default constructor */
        LinkedList();
        /** Default destructor */
        virtual ~LinkedList();
        void insert_element(ListElement *element);
    protected:

    private:
        int list_size;
        ListElement *head;
        ListElement *tail;
};

#endif // LINKEDLIST_H
