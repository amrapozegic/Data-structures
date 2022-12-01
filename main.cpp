#include <iostream>
#include "Heap.hpp"

int main() {
  Heap<int> heap1;
  heap1.insert(100);
  heap1.insert(50);
  heap1.insert(6);
  heap1.insert(20);
  heap1.insert(45);
  heap1.insert(43);
  heap1.insert(10);
  heap1.insert(15);
  heap1.insert(1);
  heap1.insert(35);
  heap1.insert(30);
  heap1.insert(5);
  
  std::cout<<"Heap1  " << heap1 << std::endl;
  std::cout << "Maximalni element iz heap1: " << heap1.max() << std::endl;
  heap1.removeMax();
  std::cout <<"Heap1 bez svog maximalnog elementa "<< heap1 << std::endl;
  std::cout << "Minimalni element heapa1: " << heap1.min() << std::endl;
  heap1.removeMin();
  std::cout<<"Heap1 bez svog minmalnog elementa " << heap1 << std::endl;

  Heap<int> heap2=heap1;
  std::cout << "Copy constructor heap2 "<<heap2 << std::endl;
 Heap<int> heap3=std::move(heap2);
  std::cout << "Move constructor heap3 "<<heap3 << std::endl;
  std::cout << "Heap2 novo stanje nakon move "<<heap2 << std::endl;
  heap2=heap3;
  std::cout << "Operator = za heap3 "<< heap2<< std::endl;
  heap3=std::move(heap1);
  std::cout << "Move operator= za heap3 nad heap1 " <<heap3<< std::endl;
  std::cout<<"Stanje heap1 " << heap1 << std::endl;

  return 0;
}
