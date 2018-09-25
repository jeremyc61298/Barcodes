// ------------------------------------------------------------------
// barcode.cpp
// Jeremy Campbell
// This program will convert a number into a corresponding barcode
// represented by a string with the characters N (narrow bar),
// n (narrow space), W (wide bar), w, (wide space).
// ------------------------------------------------------------------
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
    string number;
    getline(fin, number);
    
    for (int i = number.size() - 1; i >= 0; i--)
    {
        s.push(number[i] - '0');
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

string buildBarcode(stack<short> &idNumber, const string numCodes[], const int NUM_CODE_SIZE)
{
    string barcode;
    const string START_SEQ = "NnNn";
    const string END_SEQ = "WnN";
    
    barcode = START_SEQ;
    
    // Take the 2 top numbers and interleave their codes
    while (!idNumber.empty())
    {
        short barNum = idNumber.top(); idNumber.pop();
        short spaceNum = idNumber.top(); idNumber.pop();
        
        for (int i = 0; i < NUM_CODE_SIZE; i++)
        {
            // barNum and spaceNum index numCodes to find the correct code for that number, then
            // letter by letter, insert the code into the barcode string, making the letters
            // representing the bars uppercase.
            barcode += toupper(numCodes[barNum].at(i));
            barcode += numCodes[spaceNum].at(i);
        }
    }
    
    barcode += END_SEQ;
    return barcode;
}

void printBarcode(ofstream &fout, string barcode, int size, short top)
{
    fout << barcode;
    
    // If not the last number, print an end line
    if(size != 1 || top != 0)
        fout << endl;
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
  
  //Create an array of all codes for numbers 1-9
  const size_t MAX_DIGITS = 10;
  const int NUM_CODE_SIZE = 5;
  string numCodes[MAX_DIGITS];
  initializeNumCodes(numCodes);
  
  readNum(fin, idNumber);
  
  // While the number that was just read in is not zero
  while (idNumber.size() != 1 || idNumber.top() != 0)
  {
      hasEvenNumOfDigits(idNumber);
      string barcode = buildBarcode(idNumber, numCodes, NUM_CODE_SIZE);
      readNum(fin, idNumber);
      printBarcode(fout, barcode, idNumber.size(), idNumber.top());
  }
}