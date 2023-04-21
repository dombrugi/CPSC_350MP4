#ifndef DBLLIST_H
#define DBLLIST_H

#include <exception>
#include <iostream>
#include "ListNode.h"

template<class T>
class DblList{
    private:
        ListNode<T> *front;
        ListNode<T> *back;
        unsigned int size;

    public:
        DblList();
        virtual ~DblList();
        
        void insertFront(T d);
        void insertBack(T d);
        T removeFront();
        T getFront();
        T removeBack();
        T removeNode(int value);
        int find(T value);
        bool isEmpty();
        unsigned int getSize();
};

template<class T>
DblList<T>::DblList(){
    front = NULL;
    back = NULL;
    size = 0;
}

template<class T>
DblList<T>::~DblList(){}


template<class T>
void DblList<T>::insertFront(T d){
    ListNode<T> *node = new ListNode<T>(d);

    if(isEmpty()){
        back = node;
    }
    else{
        node->next = front;
        front->prev = node;
    }
    front = node;
    size++;
}

template<class T>
void DblList<T>::insertBack(T d){
    ListNode<T> *node = new ListNode<T>(d);

    if(isEmpty()){
        front = node;
    }
    else{
        node->prev = back;
        back->next = node;
    }
    back = node;
    size++;
}

template<class T>
T DblList<T>::removeFront(){
    if(isEmpty()){
        cerr << "List is empty";
        return NULL;
    }

    ListNode<T> *temp = front;

    if(front->next == NULL){
        back = NULL;
    }
    else{
        //theres more than one node in the list
        front->next->prev = NULL;
    }
    front = front->next;
    temp->next = NULL;
    T data = temp->data;
    size--;
    delete temp;

    return data;
}

template<class T>
T DblList<T>::removeBack(){
    if(isEmpty()){
        cerr << "List is empty";
        return -1;
    }

    ListNode<T> *temp = back;

    if(back->prev == NULL){
        front = NULL;
    }
    else{
        //theres more than one node in the list
        back->prev->next = NULL;
    }
    back = back->prev;
    temp->prev = NULL;
    T data = temp->data;
    size--;
    delete temp;

    return data;
}

template<class T>
T DblList<T>::removeNode(int value){
    if(isEmpty()){
        cerr << "List is empty";
        return -1;
    }

    ListNode<T> *curr = front;
    while (curr->data != value){
        curr = curr->next;

        if (curr == NULL){
            return -1;
        }
    }


    //if we make it here, that means we found the value
    //curr is at the location of the node to be deleted
    if (curr != front && curr != back){
        //the node is somewhere in the middle
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }

    //check if front
    if (curr == front){
        front = curr->next;
        front->prev = NULL;
    }

    //check if back
    if (curr == back){
        back = curr->prev;
        back->next = NULL;
    }

    curr->prev = NULL;
    curr->next = NULL;
    T data = curr-> data;
    --size;
    delete curr;

    return data;
}

template<class T>
int DblList<T>::find(T value){
    int pos = -1;

    ListNode<T> *curr = front;
    while(curr->data != value){
        ++pos;
        if(curr->data == value){
            break;
        }
        curr = curr->next;
    }

    if(curr == NULL){
        //we did not find it
        pos = -1;
    }

    return pos;
}

template<class T>
unsigned int DblList<T>::getSize(){
    return size;
}

template<class T>
bool DblList<T>::isEmpty(){
    return (size == 0);
}

template<class T>
T DblList<T>::getFront(){
    return front->data;
}


#endif