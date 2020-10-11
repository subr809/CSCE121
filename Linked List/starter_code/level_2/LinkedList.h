#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <stdexcept>
#include <string>

class LinkedList {
    struct Node {
        int data;
        Node* next;
        
        Node(int data) : data(data), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    unsigned int size;
    
    public:
    LinkedList();

    int& front() const;
    void push_front(const int&);
    unsigned int length() const;
    void pop_front();
    
    friend std::ostream& operator<<(std::ostream& os, const LinkedList& list) {
        os << "[WARNING] ostream operator<< not yet implemented";
        return os;
    }
    
};

LinkedList::LinkedList() : head(nullptr), tail(nullptr), size(0) {}

int& LinkedList::front() const {
    if (size == 0) {
        throw std::out_of_range("empty list");
    }
    return head->data;
}

void LinkedList::push_front(const int& data) {
    Node* node = new Node(data);
    if (head) {
        node->next = head;
    } else {
        tail = node;
    }
    head = node;
    size++;
}

unsigned int LinkedList::length() const {
    return size;
}

void LinkedList::pop_front() {
    if (size == 0) {
        throw std::out_of_range("empty list");
    }
    if (head == tail) {
        // 1 node
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        // > 1 node
        Node* next = head->next;
        delete head;
        head = next;
    }
    size--;
}

#endif