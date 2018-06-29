#ifndef DEQUE_H
#define	DEQUE_H

template <typename T>
class Deque {
public:
  Deque();
  T& operator[] (int index)const;
  T& operator[] (int index);
  void resize();
  void pop_back();
  void push_back(const T &value);
  void pop_front();
  void push_front(const T &value);
  void print();
  bool hasone();
  int abs(int george);
  // void print()const; 
private:
int f,b,bf,bb;
int arrsize,bsize;
T ** arr;


}; // class Deque 

#include "deque.cpp"

#endif	// DEQUE_H

