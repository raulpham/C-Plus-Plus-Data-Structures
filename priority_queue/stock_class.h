//*****************************************************************************************************
//
//  This program defines Stock ADT.
//
//
//  Other files required:
//   1. PriorityQueueDriver.h
//   2. StockDriver.cpp
//   3. PriorityQueue.h
//   5. Stock.txt
//
//*****************************************************************************************************

#ifndef STOCK_H
#define STOCK_H

//*****************************************************************************************************

#include <iostream>

//*****************************************************************************************************

class Stock
{
private:
  std::string companyName;
  std::string stockSymbol;
  double price;
  
public:
  Stock (const std::string & name = "", const std::string & symbol = "", double price = 0.0);
  Stock (const Stock &);
  void display () const;
  std::string getName () const;
  std::string getSymbol () const;
  double getPrice () const;
  int hash (int size) const;
  bool operator == (const Stock &) const;
  bool operator != (const Stock &) const;
  bool operator < (const Stock & s) const;
  bool operator > (const Stock & s) const;
  friend std::ostream & operator << (std::ostream & o, const Stock & r);
  friend std::istream & operator >> (std::istream & i, Stock & r);
};

//*****************************************************************************************************

inline
std::string Stock :: getName () const
{
  return this -> companyName;
}

//*****************************************************************************************************

inline
std::string Stock :: getSymbol () const
{
  return this -> stockSymbol;
}

//*****************************************************************************************************

inline
double Stock :: getPrice () const
{
  return this -> price;
}

//*****************************************************************************************************

inline
void Stock :: display () const
{
  std::cout << companyName << " " << stockSymbol << " $" << price;
}

//*****************************************************************************************************

inline
bool Stock :: operator == (const Stock & s) const
{
  return this -> price == s.price ? true : false;
}

//*****************************************************************************************************

inline
bool Stock :: operator != (const Stock & s) const
{
  return this -> price != s.price ? true : false;
}

//*****************************************************************************************************

inline
bool Stock :: operator > (const Stock & s) const
{
  return this -> price > s.price ? true : false;
}

//*****************************************************************************************************

inline
bool Stock :: operator < (const Stock & s) const
{
  return this -> price < s.price ? true : false;
}

//*****************************************************************************************************

#endif
