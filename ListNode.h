#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>

using namespace std;

template<class T>
class ListNode{
    public:
        ListNode(); //default constructor
        ListNode(T d); //overloaded constructor
        virtual ~ListNode(); //destructor
        T data;
        ListNode<T> *next;
        ListNode<T> *prev;
};

template<class T>
ListNode<T>::ListNode(T d){
    data = d;
    next = NULL;
    prev = NULL;
}

template <class T>
ListNode<T>::~ListNode(){
    next = NULL;
    prev = NULL;
}

#endif