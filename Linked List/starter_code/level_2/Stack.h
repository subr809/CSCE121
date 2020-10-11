#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "LinkedList.h"

template <typename T>
class Stack {
    LinkedList list;
    
    public:
    bool empty();
    T& peek();
    void pop();
    void push(const T&);
    
    friend std::ostream& operator<<(std::ostream& os, const Stack& stack) {
        os << "[WARNING] ostream operator<< not yet implemented";
        return os;
    }
};

template <typename T>
bool Stack<T>::empty() {
    std::cout << "[WARNING] Stack<T>::empty() not yet implemented" << std::endl;
    return true;
}

template <typename T>
T& Stack<T>::peek() {
    std::cout << "[WARNING] Stack<T>::peek() not yet implemented" << std::endl;
    return *(new T());
}

template <typename T>
void Stack<T>::pop() {
    std::cout << "[WARNING] Stack<T>::pop() not yet implemented" << std::endl;
}

template <typename T>
void Stack<T>::push(const T& elem) {
    std::cout << "[WARNING] Stack<T>::push() not yet implemented" << std::endl;
}

#endif