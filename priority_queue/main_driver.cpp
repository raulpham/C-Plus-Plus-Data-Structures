//*****************************************************************************************************
//
//  This program tests functions defined in PriorityQueue ADT.
//
//
//  Other files required:
//   1. PriorityQueue.h
//   2. Stock.h
//   3. StockDriver.cpp
//   5. Stock.txt
//
//*****************************************************************************************************

#include "PriorityQueue.h"
#include "Stock.h"

//*****************************************************************************************************

#include <iostream>
#include <fstream>
#include <string>

//*****************************************************************************************************

using namespace std;

//*****************************************************************************************************

int main ()
{
  PriorityQueue <Stock> stockObj;
  Stock obj;
  
  Stock stockItem1 ("Apple Inc", "APPL", 121.73);
  Stock stockItem2 ("Advanced Micro Devices", "AMD", 84.51);
  Stock stockItem3 ("Tesla", "TSLA", 564.33);
  Stock stockItem4 ("AT&T Inc.", "T", 23.87);
  Stock stockItem5 ("Intel", "INTC", 60.78);
  
  ifstream inFile ("Stock.txt");
  
  if (!inFile.fail ())
  {
    while (inFile >> obj)
    {
      stockObj.enqueue (obj);
    }
    cout << string (50, '*') << endl;
    cout << "Finished enqueue\n";
    cout << string (50, '*') << endl;
    stockObj.display ();
    cout << string (50, '*') << endl;
  }
  
  for (int i = 0; i <= 5; i++)
  {
    stockObj.dequeue (obj);
    cout << obj << "was dequeue\n";
    cout << string (50, '*') << endl;
    stockObj.display ();
    cout << string (50, '*') << endl;
  }
  
  inFile.close ();
  
  return 0;
}

//*****************************************************************************************************

/*
 **************************************************
 Finished enqueue
 **************************************************
 Alphabet Inc Class A
 GOOGL
 2829.11
 Tesla
 TSLA
 564.33
 Microsoft Corporation
 MSFT
 310.7
 Verizon Communications Inc.
 VZ
 51.17
 Meta Platforms Inc
 FB
 223.59
 Atlassian Corporation PLC
 TEAM
 302.31
 Motorola Inc.
 MOT
 17.49
 General Electric
 GE
 12.54
 AT&T Inc.
 T
 23.87
 Intel
 INTC
 60.78
 Advanced Micro Devices
 AMD
 84.51
 Ford Motor
 F
 11.7
 Apple
 AAPL
 121.73

 **************************************************
 Alphabet Inc Class A
 GOOGL
 2829.11
 was dequeue
 **************************************************
 Tesla
 TSLA
 564.33
 Meta Platforms Inc
 FB
 223.59
 Microsoft Corporation
 MSFT
 310.7
 Verizon Communications Inc.
 VZ
 51.17
 Apple
 AAPL
 121.73
 Atlassian Corporation PLC
 TEAM
 302.31
 Motorola Inc.
 MOT
 17.49
 General Electric
 GE
 12.54
 AT&T Inc.
 T
 23.87
 Intel
 INTC
 60.78
 Advanced Micro Devices
 AMD
 84.51
 Ford Motor
 F
 11.7

 **************************************************
 Tesla
 TSLA
 564.33
 was dequeue
 **************************************************
 Microsoft Corporation
 MSFT
 310.7
 Meta Platforms Inc
 FB
 223.59
 Atlassian Corporation PLC
 TEAM
 302.31
 Verizon Communications Inc.
 VZ
 51.17
 Apple
 AAPL
 121.73
 Ford Motor
 F
 11.7
 Motorola Inc.
 MOT
 17.49
 General Electric
 GE
 12.54
 AT&T Inc.
 T
 23.87
 Intel
 INTC
 60.78
 Advanced Micro Devices
 AMD
 84.51

 **************************************************
 Microsoft Corporation
 MSFT
 310.7
 was dequeue
 **************************************************
 Atlassian Corporation PLC
 TEAM
 302.31
 Meta Platforms Inc
 FB
 223.59
 Advanced Micro Devices
 AMD
 84.51
 Verizon Communications Inc.
 VZ
 51.17
 Apple
 AAPL
 121.73
 Ford Motor
 F
 11.7
 Motorola Inc.
 MOT
 17.49
 General Electric
 GE
 12.54
 AT&T Inc.
 T
 23.87
 Intel
 INTC
 60.78

 **************************************************
 Atlassian Corporation PLC
 TEAM
 302.31
 was dequeue
 **************************************************
 Meta Platforms Inc
 FB
 223.59
 Apple
 AAPL
 121.73
 Advanced Micro Devices
 AMD
 84.51
 Verizon Communications Inc.
 VZ
 51.17
 Intel
 INTC
 60.78
 Ford Motor
 F
 11.7
 Motorola Inc.
 MOT
 17.49
 General Electric
 GE
 12.54
 AT&T Inc.
 T
 23.87

 **************************************************
 Meta Platforms Inc
 FB
 223.59
 was dequeue
 **************************************************
 Apple
 AAPL
 121.73
 Intel
 INTC
 60.78
 Advanced Micro Devices
 AMD
 84.51
 Verizon Communications Inc.
 VZ
 51.17
 AT&T Inc.
 T
 23.87
 Ford Motor
 F
 11.7
 Motorola Inc.
 MOT
 17.49
 General Electric
 GE
 12.54

 **************************************************
 Apple
 AAPL
 121.73
 was dequeue
 **************************************************
 Advanced Micro Devices
 AMD
 84.51
 Intel
 INTC
 60.78
 Motorola Inc.
 MOT
 17.49
 Verizon Communications Inc.
 VZ
 51.17
 AT&T Inc.
 T
 23.87
 Ford Motor
 F
 11.7
 General Electric
 GE
 12.54

 **************************************************
 Program ended with exit code: 0
 */
