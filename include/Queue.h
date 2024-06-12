#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class Queue
{
    public:
        /** Default constructor */
        Queue();

        Queue(int len);
        /** Default destructor */
        ~Queue();

        /** Utilities */
        T* dequeue();
        void enqueue(T* element);
        void printQueue();

        /** Setters */
        void setQueue(T **queue){this->queue = queue;};
        void setTop(int top){this->top = top;};
        void setBottom(int bottom){this->bottom = bottom;};
        void setCapacity(int capacity){this->capacity = capacity;};
        void setSize(int q_size){this->q_size = q_size;};

        /** Getters */
        T** getQueue(){return this->queue;};
        int getTop(){return this->top;};
        int getBottom(){return this->bottom;};
        int getCapacity(){return this->capacity;};
        int getSize(){return this->q_size;};

    protected:

    private:
        T **queue;
        int top;
        int bottom;
        int capacity;
        int q_size;
};

#endif // QUEUE_H
