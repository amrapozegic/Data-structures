#pragma once
#include <stack>
#include <algorithm>
#include <iostream>
#include <utility>

template <typename T>
class Heap {
  public:
  Heap(size_t capacity = 50);
  Heap(const Heap& heap);
  Heap(Heap&& heap);
  Heap& operator=(const Heap& heap);
  Heap& operator=(Heap&& heap);
  ~Heap();
  size_t size()  { return size_ - 1; }
  template <typename U>
  void insert(U&& elem);
  T& max();
  T& min();
  void removeMax();
  void removeMin();

 friend std::ostream& operator<<(std::ostream& out, const Heap& h)
{
out<<"Inorder :";
  if (h.size_ == 1) {
  return out;
  }
    std::stack<int> s;
    int index =1;
    s.push(index);

    while (!s.empty()) {

      while (s.top()==index&&index*2 < h.size_) {
        index *=2;
        s.push(index);
      }
      index = s.top();
      s.pop();
      out<<h.array_[index]<<" ";

      if (index*2+1 < h.size_) {
        index =index*2+1;
        s.push(index);
      }
    }
  
return out;
}

private:
  void expand();
  void balanceDown(size_t);
  void balanceUp(size_t);
  size_t size_;
  size_t capacity_;
  T* array_;

};

template <typename T>
Heap<T>::Heap(size_t capacity)
:capacity_{capacity},size_{1},array_{new T[capacity]}
{}

template <typename T>
Heap<T>::~Heap() {
  delete[] array_;
  size_=0;
  capacity_=0;
}

template <typename T>
Heap<T>::Heap(const Heap& heap)
 :size_{heap.size_},capacity_{heap.capacity_},  array_{new T[capacity_]} {
  std::copy(heap.array_, heap.array_ + size_, array_);}

template <typename T>
Heap<T>::Heap(Heap&& heap)
    :size_{heap.size_},  capacity_{heap.capacity_}, array_{heap.array_} {
  heap.size_ = 1;
  heap.capacity_=0;
  heap.array_ = nullptr;
}

template <typename T>
Heap<T>& Heap<T>::operator=(Heap&& heap) {
  array_ = heap.array_;
  size_ = heap.size_;
  capacity_ = heap.capacity_;
  heap.array_ = nullptr;
  heap.size_=1;
  heap.capacity_=0;
  return *this;
}

template <typename T>
Heap<T>& Heap<T>::operator=(const Heap& heap) {
return *this=Heap(heap);
}




template <typename T>
template <typename E>
void Heap<T>::insert(E&& elem) {
  if (size_ == capacity_) 
    expand();
  int index = size_;
  array_[index] = std::forward<E>(elem);
  while (index != 1) {
    int parent = index / 2;
    if (array_[index] > array_[parent]) {
      std::swap( array_[parent],array_[index]);
      index = parent;
    } else {
      break;
    }
  }
  size_++;
}


template <typename T>
void Heap<T>::expand() {
  capacity_ = capacity_*2;
  auto temp = new T[capacity_];
  std::copy(array_, array_ + size_, temp);
  delete[] array_;
  array_ = temp;
}

template <typename T>
T& Heap<T>::max() {
    return array_[1];
}


template <typename T>
void Heap<T>::balanceDown(size_t index) {

if (index >= size_)
  return;
      
  size_t left = (index * 2) + 1;
  size_t right = (index * 2) + 2;
  if (left < size_ && right < size_ &&
    (array_[index] < array_[left] || array_[index] < array_[right])) {
      size_t maxIndex = array_[left] < array_[right] ? right : left;
        std::swap(array_[index], array_[maxIndex]);
        balanceDown(maxIndex);
      } else if (left < size_ && right >= size_ && array_[index] < array_[left]) {
        std::swap(array_[index], array_[left]);
        balanceDown(left);
      } else if (left >= size_ && right < size_ && array_[index] < array_[right]) {
        std::swap(array_[index], array_[right]);
        balanceDown(right);
      }
    
}

template <typename T>
void Heap<T>::removeMax() {
  array_[1] = array_[size_ - 1];
  balanceDown(1);
  size_--;
}


template <typename T>
T& Heap<T>::min()  {
    int minIndex = 1;
    while ( minIndex * 4 < size_) {
      minIndex = minIndex * 2;
    }
  for (int i = minIndex; i <= size_-2; i++) {
    if (array_[i] <= array_[minIndex])
      minIndex=i;
  }
  return array_[minIndex];
}

template <typename T>
void Heap<T>::removeMin() {
    int minIndex = 1;
    while ( minIndex * 4 < size_) 
      minIndex = minIndex * 2;
  for (int i = minIndex; i <= size_-2; i++) {
    if (array_[i] <= array_[minIndex])
      minIndex=i;
  }
  std::swap(array_[minIndex],array_[size_-1]);
--size_;
  balanceUp(minIndex);

 
}
template<typename T>
void Heap<T>::balanceUp(size_t index) {
    while (index > 0 && array_[(index) / 2] < array_[index]) {
      std::swap(array_[(index - 1) / 2], array_[index]);
      index = (index - 1) / 2;
    }
  }

