// heap.h
// Binary heap tree header file for CS 24 lab
// Diba Mirza

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>

class Heap {

  public:
    Heap() {} // default constructor
    Heap(
        std::vector<int>::iterator start,
        std::vector<int>::iterator
            end);         // build a heap from a range using heapify
    void push(int value); // insert value; //duplicates are allowed
    void pop();           // delete the min element
    int top() const;
    bool empty() const;

  private:
    std::vector<int> vdata; // store the binary heap tree as a dynamic array
    void bubble_down(int i);
    void bubble_up(int i);
};

#endif
