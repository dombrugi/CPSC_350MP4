#ifndef LISTQUEUE_H
#define LISTQUEUE_H

#include "DblList.h"
#include <iostream>

template<class T>
class ListQueue{
    public:
        ListQueue();
        virtual ~ListQueue();

        int size();
        bool isEmpty();
        void insert(T d);
        T remove();
        T peek();

    private:
        DblList<T> *mQueue; //doubly-linked list that makes up the queue
};

template <class T>
ListQueue<T>::ListQueue(){
    mQueue = new DblList<T>();
}

template <class T>
ListQueue<T>::~ListQueue(){
    if(mQueue != NULL)
        delete mQueue;
}

template <class T>
int ListQueue<T>::size(){
    return mQueue->getSize();
}

template <class T>
bool ListQueue<T>::isEmpty(){
    return mQueue->isEmpty();
}

template <class T>
void ListQueue<T>::insert(T d){
    mQueue->insertBack(d);
}

template <class T>
T ListQueue<T>::remove(){
    return mQueue->removeFront();
}

template <class T>
T ListQueue<T>::peek(){
    return mQueue->getFront();
}

#endif