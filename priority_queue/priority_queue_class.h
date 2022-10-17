//*****************************************************************************************************
//
//  This program defines PriorityQueue ADT.
//
//
//  Other files required:
//   1. PriorityQueueDriver.h
//   2. Stock.h
//   3. StockDriver.cpp
//   5. Stock.txt
//
//*****************************************************************************************************

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

//*****************************************************************************************************

#include <iostream>
#include <new>

//*****************************************************************************************************

template <typename T>
class PriorityQueue
{
private:
  int capacity;
  int size;
  T * elements;
  void heapify (int i);
  bool _resize ();
  
public:
  PriorityQueue ();
  ~PriorityQueue ();
  void enqueue (const T& value);
  bool dequeue (T& value);
  void display () const;
};

//*****************************************************************************************************

template <typename T>
PriorityQueue <T> :: PriorityQueue ()
{
  size = 0;
  capacity = 12;
  elements = new T [capacity];
}

//*****************************************************************************************************

template <typename T>
PriorityQueue <T> :: ~PriorityQueue ()
{
  size = 0;
  capacity = 0;
  delete [] elements;
  elements = nullptr;
}

//*****************************************************************************************************

template <typename T>
bool PriorityQueue <T> :: _resize ()
{
  bool success = false;
  T * temp;
  
  temp = new (std::nothrow) T [capacity + (capacity + 10)];
  
  if (temp != nullptr)
  {
    capacity += capacity + 10;
    
    for (int i = 0; i < size; i++)
    {
      temp [i] = elements [i];
    }
    
    delete [] elements;
    elements = temp;
    success = true;
  }
  return success;
}

//*****************************************************************************************************

template <typename T>
void PriorityQueue <T> :: heapify (int i)
{
  int leftChild,
        rightChild,
        largest;
  bool stop = false;
  T temp = elements [i];
  leftChild = i * 2 + 1;
  
  while ((leftChild < size) && !stop)
  {
    rightChild = leftChild + 1;
    if (rightChild >= size)
    {
      largest = leftChild;
    }
    else
    {
      if (elements [leftChild] > elements [rightChild])
      {
        largest = leftChild;
      }
      else
      {
        largest = rightChild;
      }
    }
    if (elements [largest] > temp)
    {
      elements [i] = elements [largest];
      i = largest;
      leftChild = i * 2 + 1;
    }
    else
    {
      stop = true;
    }
  }
  elements [i] = temp;
}

//*****************************************************************************************************

template <typename T>
void PriorityQueue <T> :: enqueue (const T& value)
{
  bool added = false;
  int child = size;
  int parent = (child - 1) / 2;
  
  if (size == capacity)
  {
    _resize ();
  }
  else
  {
    while ((child > 0) && (value > elements [parent]))
    {
      elements [child] = elements [parent];
      child = parent;
      parent = (parent - 1) / 2;
    }
    elements [child] = value;
    size++;
    added = true;
  }
}

//*****************************************************************************************************

template <typename T>
bool PriorityQueue <T> :: dequeue (T& value)
{
  bool removed = false;
  
  if (size > 0)
  {
    value = elements [0];
    removed = true;
    elements [0] = elements [size - 1];
    size--;
    heapify (0);
  }
  return removed;
}

//*****************************************************************************************************

template <typename T>
void PriorityQueue <T> :: display () const
{
  for (int i = 0; i < size; i++)
  {
    std::cout << elements [i];
  }
  std::cout << std::endl;
}

//*****************************************************************************************************

#endif
