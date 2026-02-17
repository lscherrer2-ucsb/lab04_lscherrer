// heap.cpp
// Diba Mirza

#include "heap.h"
#include <utility>

// Builds a heap from the range [start, end) using the heapify algorithm
// Should run in O(n) time
Heap::Heap(std::vector<int>::iterator start, std::vector<int>::iterator end) {
    vdata.assign(start, end);
    int n = vdata.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        bubble_down(i);
    }
}

void Heap::bubble_down(int i) {
    int leafBoundary = vdata.size() / 2;
    int curr = i;
    while (curr < leafBoundary) {
        int smallest = curr;
        int left = curr * 2 + 1;
        int right = curr * 2 + 2;

        bool changed = false;

        if (left < vdata.size() && vdata[left] < vdata[smallest]) {
            smallest = left;
            changed = true;
        }

        if (right < vdata.size() && vdata[right] < vdata[smallest]) {
            smallest = right;
            changed = true;
        }

        if (!changed) {
            break;
        }
        std::swap(vdata[curr], vdata[smallest]);
        curr = smallest;
    }
}
void Heap::bubble_up(int i) {
    int curr = i;
    if (curr >= vdata.size()) return;
    while (curr) {
        int parent = (curr - 1) / 2;
        if (vdata[curr] >= vdata[parent]) {
            break;
        }
        std::swap(vdata[curr], vdata[parent]);
        curr = parent;
    }
}

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value) {
    vdata.push_back(value);
    bubble_up(vdata.size() - 1);
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop() {
    if (vdata.empty()) return;
    vdata[0] = vdata[vdata.size() - 1];
    vdata.pop_back();
    bubble_down(0);
}

// Returns the minimum element in the heap
int Heap::top() const {
    return empty() ? 0 : vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty() const {
    return vdata.empty();
}
