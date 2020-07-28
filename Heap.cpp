//
// Created by ravi on 7/28/20.
//

#include <climits>
#include "Heap.h"
#include <iostream>


int Heap::findParent(int i)
{
    return (i-1)/2;
}

int Heap::left_val(int index)
{
    return (index*2 + 1) < size ? heap[(index*2 + 1)] : INT_MIN;
}

int Heap::right_val(int index)
{
    return (index*2 + 2) < size ? heap[(index*2 + 2)] : INT_MIN;
}

void Heap::propogateUp(int index)
{
    while(index > 0 && heap[findParent(index)] < heap[index])
    {
        swap(heap[findParent(index)], heap[index]);
        index = findParent(index);
    }
}

void Heap::insert(int n) {
    int index = size;
    heap[size++] = n;
    int parent = findParent(index);
    if(heap[parent] < n)
        propogateUp(index);
}

int Heap::getMax() {
    if(size == 0)
        return INT_MIN;
    else
        return heap[0];
}

void  Heap::print() {
    for (int i = 0; i < size; ++i) {
        std::cout<<heap[i]<<" ";
    }
    cout<<endl;
}
void Heap::heapify(int index)
{
    if(size == 0)
        return;
    else{
        int l = left_val(index);
        int r = right_val(index);
        int max_v = max(l, max(r, heap[index]));
        //cout<<l<<" "<<r<<" "<<heap[index]<<endl;
        int max_index = index;
        if(max_v == l)
            max_index = index*2 + 1;
        else if(max_v == r)
            max_index = index*2 + 2;
        //cout<<max_index<<" "<<index<<endl;
        swap(heap[max_index], heap[index]);
        if(max_index != index)
            heapify(max_index);
    }
}

void Heap::removeMax() {
    swap(heap[size - 1], heap[0]);
    size--;
    heapify(0);
}

void Heap::removeNode(int index) {
    if(index >= size)
        return;
    else{
        size--;
        swap(heap[size - 1], heap[index]);
        if(index > 0 && heap[findParent(index)] < heap[index])
            propogateUp(index);
        else
            heapify(index);
    }
}