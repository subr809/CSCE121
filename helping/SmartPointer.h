// SmartPointer.h
#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

template <typename T>
class SmartPointer {
  T* data;
public:
  SmartPointer(const T&);
  T& operator*(); // gets value held
  const T& operator*() const; // gets value held
  SmartPointer<T>& operator=(const T&); // assigns value
  SmartPointer<T>& operator=(const SmartPointer<T>&);
  SmartPointer();
  ~SmartPointer();

};

template <typename T>
SmartPointer<T>::SmartPointer(const T& data) {
  this->data = new T(data); 
  // allocate on heap for T (regardless of size)
}

template <typename T>
T& SmartPointer<T>::operator*() { 
  // get value held in smart pointer
  return *data;
}

template <typename T>
const T& SmartPointer<T>::operator*() const { 
  // get value held in smart pointer
  return *data;
}

// note: this is _not_ copy assignmewnt
template <typename T>
SmartPointer<T>& SmartPointer<T>::operator=(const T& data) { 
  // assign value to smart pointer
  *(this->data) = data;
  return *this;
}

template <typename T> 
SmartPointer<T>& SmartPointer<T>::operator=(const SmartPointer<T>&) {
      return *this;
}
template <typename T> 
SmartPointer<T>::SmartPointer() {};

template <typename T>
SmartPointer<T>::~SmartPointer() {
    delete[] data;
}
#endif
