#include "Stock.h"

#include <iostream>
#include <string>

using namespace std;

Stock :: Stock (const string & name, const string & symbol, double price)
{
  companyName = name;
  stockSymbol = symbol;
  this -> price = price;
}

Stock :: Stock (const Stock &s)
{
  this -> companyName = s.companyName;
  this -> stockSymbol = s.stockSymbol;
  this -> price = s.price;
}

int Stock :: hash (int size) const
{
  int val = 0;
  
  for (int i = 0; i < stockSymbol.size (); i++)
  {
    val = val + stockSymbol [i];
  }
  
  return val % size;
}

ostream & operator << (ostream & o, const Stock & r)
{
  o << r.companyName << endl;
  o << r.stockSymbol << endl;
  o << r.price << endl;
  
  return o;
}

istream & operator >> (istream & i, Stock & r)
{
  getline (i, r.companyName);
  getline (i, r.stockSymbol);
  i >> r.price;
  
  if (!i.eof ())
  {
    i.get ();
  }
  
  i.ignore ();
  
  return i;
}
