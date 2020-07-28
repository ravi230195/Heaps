//
// Created by ravi on 7/28/20.
//

#ifndef HEAPS_HEAP_H
#define HEAPS_HEAP_H

#include <algorithm>
#include <queue>

using namespace std;

class Heap {
    int size;
    vector<int> heap;
public:
    inline Heap(int n = 100)
    {
        heap.resize(n);
        size = 0;
    }

    void insert(int n);
    int getMax();
    void removeMax();
    void removeNode(int index);
    void print();

private:
    void propogateUp(int index);
    void heapify(int index);
    int findParent(int i);
    int left_val(int index);
    int right_val(int index);
};


#endif //HEAPS_HEAP_H
