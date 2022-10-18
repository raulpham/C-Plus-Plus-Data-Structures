#ifndef Queue_h
#define Queue_h
#include <iostream>
#include <new>

using namespace std;

#include "node.h"

template <typename T>
class Queue
{
private:
  Node <T> * front;
  Node <T> * back;
  int numValues;
public:
  Queue ();
  ~Queue ();
  bool enqueue (const T &);
  bool dequeue (T &);
  bool viewFront (T &) const;
  bool viewBack (T &) const;
  int getNumValues () const;
  bool isFull () const;
  bool isEmpty () const;
};

template <typename T>
Queue <T> :: Queue ()
{
  front = back = nullptr;
  numValues = 0;
}

template <typename T>
Queue <T> :: ~Queue ()
{
  Node <T> * pTemp = nullptr;
    
  while (front != nullptr)
  {
    pTemp = front;
    front = pTemp -> next;
    delete pTemp;
  }
}

template <typename T>
bool Queue <T> :: enqueue (const T & dataIn)
{
  bool success = false;
  Node <T> * pNew = new (nothrow) Node <T> (dataIn);
  
  if (pNew != nullptr)
  {
    if (back != nullptr)
    {
      back -> next = pNew;
    }
    else
    {
      front = pNew;
    }
    back = pNew;
    numValues++;
    success = true;
  }
  
  return success;
}

template <typename T>
bool Queue <T> :: dequeue (T & dataOut)
{
  bool success = false;
  Node <T> * pTemp = front;
  
  if (pTemp != nullptr)
  {
    if (front == back)
    {
      back = nullptr;
    }
    dataOut = pTemp -> data;
    front = pTemp -> next;
    delete pTemp;
    numValues--;
    success = true;
  }
  
  return success;
}

template <typename T>
bool Queue <T> :: viewFront (T & dataOut) const
{
  bool success = false;
  Node <T> * pTemp = front;
  
  if (pTemp != nullptr)
  {
    dataOut = pTemp -> data;
    success = true;
  }
  return success;
}

template <typename T>
bool Queue <T> :: viewBack (T & dataOut) const
{
  bool success = false;
  Node <T> * pTemp = back;
  
  if (pTemp != nullptr)
  {
    dataOut = pTemp -> data;
    success = true;
  }
  return success;
}

template <typename T>
int Queue <T> :: getNumValues () const
{
  int size = 0;
  Node <T> * pTemp = front;
    
  while (pTemp != nullptr)
  {
    pTemp = pTemp -> next;
    size++;
  }
  return size;
}

template <typename T>
bool Queue <T> :: isFull () const
{
  bool success = false;
  Node <T> * pNew = new (nothrow) Node <T>;
  
  if (pNew == nullptr)
  {
    delete pNew;
    success = true;
  }
  
  return success;
}

template <typename T>
bool Queue <T> :: isEmpty () const
{
  bool success = false;
  
  if (front == nullptr)
  {
    success = true;
  }
  
  return success;
}

#endif
