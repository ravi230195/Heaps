#include <iostream>
#include "Heap.h"

using namespace std;
int main() {
    std::cout << "Heap Data Structure " << std::endl;
    Heap* h = new Heap();
    h->insert(1);
    std::cout << "Max Val " << h->getMax()<<std::endl;
    h->insert(10);
    std::cout << "Max Val " << h->getMax()<<std::endl;
    h->insert(2);
    std::cout << "Max Val " << h->getMax()<<std::endl;
    h->insert(5);
    std::cout << "Max Val " << h->getMax()<<std::endl;
    h->insert(6);
    h->insert(9);
    h->print();
    h->removeMax();
    h->print();
    std::cout << "Max Val " << h->getMax()<<std::endl;
    h->insert(15);
    h->print();
    h->removeMax();
    std::cout << "Max Val " << h->getMax()<<std::endl;
    h->insert(20);
    std::cout << "Max Val " << h->getMax()<<std::endl;
    h->removeMax();
    h->print();
    return 0;
}
