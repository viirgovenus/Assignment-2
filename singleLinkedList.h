
#ifndef singleLinkedList
#define singleLinkedList

#include<iostream>

class Node {
public:
    int info;
    Node* next;
};

class List : public Node {
private:
    Node *first, *last;

public:
    List();
    void create();
    void insert();
    void delet();
    void display();
    void search();
};

#endif // singleLinkedList.h