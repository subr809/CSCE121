#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include "Node.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

//////////////////////////////////////////////////////////////////////////////
//                         class template definition                        //
//////////////////////////////////////////////////////////////////////////////

template<typename T>
class DoublyLinkedList {
public:
    /* uncomment the declarations as you implement them */
    DoublyLinkedList();
    DoublyLinkedList(T);
    DoublyLinkedList(const DoublyLinkedList<T>&);
    DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>&);
    ~DoublyLinkedList();
    unsigned int size() const;
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;
    void push_back(T);
    void push_front(T);
    void pop_back();
    void pop_front();
    void erase(unsigned int);
    void insert(T data, unsigned int idx);
    void clear();
    std::string to_str() const;
    // breaks encapsulation... gives operator== access to private data... not great approach, but makes the homework easier for you since we haven't talked about iterators :).
    template<typename U> friend bool operator==(DoublyLinkedList<U> const&, DoublyLinkedList<U> const&);
private:
    // do not change ordering.
    Node<T> *head;
    Node<T> *tail;
    unsigned int sz;
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), sz(0) {}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(T data) : head(nullptr), tail(nullptr), sz(0) {
	head = new Node<T>(data);
	tail = head;
	sz += 1;
}

template <typename T> 
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& rhs) : head(nullptr), tail(nullptr) {*this = rhs;}

template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& rhs) {
    if (this != &rhs) {
        clear();
        Node<T> *temp = rhs.head;
		while (temp) {
			this->push_back(temp->data);
			temp = temp->next;
		}
    }
    return *this;
}

template <typename T> 
DoublyLinkedList<T>::~DoublyLinkedList() {
	clear();
}

template <typename T> 
unsigned int DoublyLinkedList<T>::size() const { return sz; }

template <typename T>
T& DoublyLinkedList<T>::front() {return head->data;}

template <typename T>
T& DoublyLinkedList<T>::back() {return tail->data;}

template <typename T>
const T& DoublyLinkedList<T>::front() const {return head->data;}

template <typename T>
const T& DoublyLinkedList<T>::back() const {return tail->data;}

template <typename T>
void DoublyLinkedList<T>::clear() {
    Node<T> *prev = head;
    while (prev) {
        Node<T> *next = prev->next;
        delete prev;
        prev = next;
    }
    sz = 0;
    head = nullptr;
    tail = nullptr;
}

template <typename T>
void DoublyLinkedList<T>::insert(T data, unsigned int idx) {
	Node<T>* n = new Node<T>(data);
	if (idx >= sz) {
		return;
	}
	if (sz == 0) {
		throw std::out_of_range("empty list");
	}
	if (idx == 0) {
		n->next = head;
		n->prev = nullptr;
		if (head == nullptr) {
			tail = n;
		}
		else {
			head->prev = n;
		}
		head = n;
		sz++;
		return;
	}
	Node<T>* current = head;
	for (unsigned int i = 0; i < idx; i++) {
		current = current->next;
	}
	if (idx == sz - 1) {
		current->prev->next = n;
		n->prev = current->prev;
		n->next = current;
		current->prev = n;
		current->next = nullptr;
		tail = current;
		sz++;
		return;
	}
	current->prev->next = n;
	n->prev = current->prev;
	n->next = current;
	current->prev = n;
	sz++;
}

template <typename T> 
void DoublyLinkedList<T>::erase(unsigned int idx) {
	Node<T> *n = head;
	if (head == nullptr) {
		return;
	}
	if (idx > sz) {
		return;
	}
	if (idx == 0) {
		head = n -> next;
		n -> next -> prev = nullptr;
		delete n;
		sz--;
		return;
	}
	if (idx == sz - 1) {
		tail = tail -> prev;
		tail -> next = nullptr;
		sz--;
		return;
	}
	for (int i = 0; i < idx; ++i) {
		n = n -> next;
	}
	n -> prev -> next = n -> next;
	n -> next -> prev = n -> prev;
	delete n;
	sz--;
}

template <typename T>
void DoublyLinkedList<T>::push_back(T data) {
    Node<T> *node = new Node<T>(data);
	node -> next = nullptr;
	node -> prev = tail;
    if (head == nullptr) {
        head = node;
    }
	else {
		tail -> next = node;
	}
    tail = node;
    sz++;
}

template <typename T>
void DoublyLinkedList<T>::push_front(T data) {
    Node<T> *node = new Node<T>(data);
	node -> next = head;
	node -> prev = nullptr;
    if (head == nullptr) {
        tail = node;
    } 
	else {
        head -> prev = node;
    }
    head = node;
    sz++;
}

template <typename T>
void DoublyLinkedList<T>::pop_back() {
    if (tail) {
		Node<T> *n = tail;
		tail = tail->prev;
		if (tail){
			tail -> next = nullptr;
		}
		else {
			head = nullptr;
		}
		delete n;
		sz--;
	}
}

template <typename T>
void DoublyLinkedList<T>::pop_front() {
    if (head) {
		Node<T> *n = head;
		head = head->next;
		if (head){
			head -> prev = nullptr;
		}
		else {
			tail = nullptr;
		}
		delete n;
		sz--;
	}
}

//////////////////////////////////////////////////////////////////////////////
//                       helper function declarations                       //
//////////////////////////////////////////////////////////////////////////////
template<typename T> std::ostream& operator<<(std::ostream &, DoublyLinkedList<T> const&);

template<typename T> bool operator==(DoublyLinkedList<T> const&, DoublyLinkedList<T> const&);

template<typename T> bool operator!=(DoublyLinkedList<T> const&, DoublyLinkedList<T> const&);

//////////////////////////////////////////////////////////////////////////////
//                     member template function definitions                 //
//////////////////////////////////////////////////////////////////////////////
template<typename T>
std::string DoublyLinkedList<T>::to_str() const
{
    std::stringstream os;
    const Node<T> *curr = head;
    os << std::endl << std::setfill('-') << std::setw(80) << '-' << std::setfill(' ') << std::endl;
    os << "head: " << head << std::endl;
    os << "tail: " << tail << std::endl;
    os << "  sz: " << sz << std::endl;
    os << std::setw(16) << "node" << std::setw(16) << "node.prev" << std::setw(16) << "node.data" <<  std::setw(16) << "node.next" << std::endl;
    while (curr) {
        os << std::setw(16) << curr;
        os << std::setw(16) << curr->prev;
        os << std::setw(16) << curr->data;
        os << std::setw(16) << curr->next;
        os << std::endl;
        curr = curr->next;
    }
    os << std::setfill('-') << std::setw(80) << '-' << std::setfill(' ') << std::endl;
    return os.str();
}

//////////////////////////////////////////////////////////////////////////////
//                     helper template function definitions                 //
//////////////////////////////////////////////////////////////////////////////
template<typename T> bool operator==(DoublyLinkedList<T> const& lhs, DoublyLinkedList<T> const& rhs) { 
	if (lhs.sz != rhs.sz) {
		return false;
	}
	else {
		Node<T> *node = lhs.head;
		Node<T> *node2 = rhs.head;
		int counter = 0;
		while (counter < lhs.sz) {
			if (node -> data != node2 -> data) {
				return false;
			}
			counter += 1;
			node = node -> next;
			node2 = node2 -> next;
		}
	}
	return true;
} 
template<typename T> bool operator!=(DoublyLinkedList<T> const& lhs, DoublyLinkedList<T> const& rhs) {
	if (lhs.sz != rhs.sz) {
		return true;
	}
	else {
		Node<T> *node = lhs.head;
		Node<T> *node2 = rhs.head;
		int counter = 0;
		while (counter < lhs.sz) {
			if (node -> data != node2 -> data) {
				return true;
			}
			counter += 1;
			node = node -> next;
			node2 = node2 -> next;
		}
	}	
	return false;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, DoublyLinkedList<T> const& rhs)
{
    os << rhs.to_str();
    return os;
}

#endif