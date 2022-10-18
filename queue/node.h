#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
  public:
    T data;
    Node <T> * next;
    Node ();
    Node (const T &, Node <T> * next = nullptr);
};

template <typename T>
Node <T> :: Node()
{
  data = 0;
  next = nullptr;
}

template <typename T>
Node <T> :: Node (const T & data, Node <T> * next)
{
  this -> data = data;
  this -> next = next;
}

#endif
