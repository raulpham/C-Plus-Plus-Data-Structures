#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#include "queue.h"

void displayQueue (Queue <int> &);
void addValue (Queue <int> &, const int [], int);
double getAverage (Queue <int> &);
void clearQueue (Queue <int> &);

int main ()
{
  const int size = 11;
  int arr [size] = {3, 7, 9, 12, 33, 51, 67, 89, 1, 42, 11};
  Queue <int> myQ;
  double avg;
  int front,
      back,
      qSize;
  
  cout << string (16, '*' );
  cout << "Add The Values";
  cout << string (14, '*') << endl;
  addValue (myQ, arr, size);
  displayQueue (myQ);
  
  cout << endl;
  if (!myQ.isEmpty ())
  {
    cout << "Now Queue is Not Empty \n";
  }
  else
  {
    cout << "Now Queue is Empty \n";
  }
  if (!myQ.isFull ())
  {
    cout << "Now Queue is Not Full \n";
  }
  else
  {
    cout << "Now Queue is Full \n";
  }
  
  cout << "Avg is: ";
  avg = getAverage (myQ);
  cout << fixed << setprecision (4) << avg << endl;
  
  cout << "Front value is: ";
  if (myQ.viewFront (front))
  {
    cout << front << endl;
  }
  else
  {
    cout << "Cannot view front \n";
  }
  cout << "Back value is: ";
  if (myQ.viewBack (back))
  {
    cout << back << endl;
  }
  else
  {
    cout << "Cannot view back \n";
  }
  
  qSize = myQ.getNumValues ();
  cout << "Size is: " << qSize << endl;
  
  cout << string (16, '*' );
  cout << "Clear the queue";
  cout << string (14, '*') << endl;
  clearQueue (myQ);
  if (myQ.isEmpty ())
  {
    cout << "Now Queue is Empty \n";
  }
  else
  {
    cout << "Now Queue is Not Empty \n";
  }
  
  return 0;
}

void displayQueue (Queue <int> & myQ)
{
  int data = 0;
  bool success = true;
  Queue <int> tempQ;
  
  while (myQ.dequeue (data))
  {
    cout << data << " ";
    if (!tempQ.enqueue (data))
    {
      success = false;
    }
  }
  while (tempQ.dequeue (data))
  {
    if (!myQ.enqueue (data))
    {
      success = false;
    }
  }
}

void addValue (Queue <int> & myQ, const int arr [], int size)
{
  bool success = true;
  
  for (int i = 0; i < size; i++)
  {
    if (!myQ.enqueue (arr [i]))
    {
      success = false;
    }
  }
}

double getAverage (Queue <int> & myQ)
{
  double sum = 0;
  double average = 0;
  int data = 0;
  double size = myQ.getNumValues ();
  Queue <int> tempQ;
  bool success = true;
  
  while (myQ.dequeue (data))
  {
    sum += data;
    if (!tempQ.enqueue (data))
    {
      success = false;
    }
  }
  
  average = sum / size;
  
  while (tempQ.dequeue (data))
  {
    if (!myQ.enqueue (data))
    {
      success = false;
    }
  }
  
  return average;
}

void clearQueue (Queue <int> & myQ)
{
  bool success = true;
  int data;
  
  while (!myQ.isEmpty ())
  {
    if (!myQ.dequeue (data))
    {
      success = false;
    }
  }
}

/*
 ****************Add The Values**************
 3 7 9 12 33 51 67 89 1 42 11
 Now Queue is Not Empty
 Now Queue is Not Full
 Avg is: 29.5455
 Front value is: 3
 Back value is: 11
 Size is: 11
 ****************Clear the queue**************
 Now Queue is Empty
 Program ended with exit code: 0
 */
