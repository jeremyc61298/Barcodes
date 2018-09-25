#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using std::ofstream;
using std::ifstream;
using std::stack;
using std::string;
using std::cerr;
using std::endl;

void readNum(ifstream &fin, stack<short> &s)
{
    char digit;
    fin.get(digit);
    
    while (digit != '\n')
    {
        s.push(digit - '0');
        fin.get(digit);
    }
}

void hasEvenNumOfDigits(stack<short> &s)
{
    if ((s.size() % 2) != 0)
        s.push(0);
}

// Creates an array where a code for each index (0 - 9) is stored
void initializeNumCodes(string numCodes[])
{
    numCodes[0] = "nnwwn";
    numCodes[1] = "wnnnw";
    numCodes[2] = "nwnnw";
    numCodes[3] = "wwnnn";
    numCodes[4] = "nnwnw";
    numCodes[5] = "wnwnn";
    numCodes[6] = "nwwnn";
    numCodes[7] = "nnnww";
    numCodes[8] = "wnnwn";
    numCodes[9] = "nwnwn";
}

string buildBarcode(stack<short> idNumber)
{
    string barcode;
    const string START_SEQ = "NnNn";
    const string END_SEQ = "WnN";
    const size_t MAX_DIGITS = 10;
    string numCodes[MAX_DIGITS];
    
    //Create an array of all codes for numbers 1-9
    initializeNumCodes(numCodes);
    
    // Take the 2 top numbers and convert them
    
    
    return barcode;
}

int main() 
{
  ifstream fin("barcode.in");
  if (!fin)
  {
      cerr << "Input file not found." << endl;
      return -1;
  }
  
  ofstream fout("barcode.out");
  stack<short> idNumber;
  readNum(fin, idNumber);
  
  while (idNumber.top() != 0)
  {
      hasEvenNumOfDigits(idNumber);
      
      
      readNum(fin, idNumber);
  }
}