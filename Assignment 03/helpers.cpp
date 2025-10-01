#include "helpers.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace Helpers{

  void printHeader(int keywordCount, int definitionCount){
    // TODO: match sample run header exactly
    /*
    ! Opening data file... C:\Users\MickeyMouse\AbsolutePath\DB\Data.CS.SFSU.txt
    <!>ERROR<!> ===> File could not be opened.
    <!>ERROR<!> ===> Provided file path: C:\Users\MickeyMouse\AbsolutePath\DB\Data.CS.SFSU.txt
    <!>Enter the CORRECT data file path: ./Data.CS.SFSU.txt
    ! Loading data...
    ! Loading completed...
    ! Closing data file... ./Data.CS.SFSU.txt
    ====== DICTIONARY 340 C++ =====
    ------ Keywords: 19
    ------ Definitions: 61
    */

    cout << "! Loading data..." << endl;
    cout << "! Loading completed" << endl;
    cout << "! closing data file..." << endl;          // need to add path here
    cout << "====== DICTIONARY 340 C++ =====" << endl;
    cout << "------ Keywords: " << keywordCount << endl;
    cout << "------ Definitions: " << definitionCount <<endl << endl;

    return;
  }

  void printHowTo(){
    /*
        PARAMETER HOW-TO,  please enter:
        1. A search key -then 2. An optional part of speech -then
        3. An optional 'distinct' -then 4. An optional 'reverse'
    */

    cout << 
    "   PARAMETER HOW-TO,  please enter:" << endl << 
    "   1. A search key -then 2. An optional part of speech -then" << endl << 
    "   3. An optional 'distinct' -then 4. An optional 'reverse'" << endl;

    return;
  }

  void printBar(){
    cout << "   |" << endl;
  }

  void printEntries(const string &keyword, const vector<Entry> &entries){
    // TODO: print each entry in required format
    // for (vector<Entry>::iterator itr = entries.begin(); itr != entries.end(); ++itr) { 
    //   cout << *itr << " ";
    // }

    for (Entry entry : entries) { 
      
    }
  }

  void printWarning2(const string &bad){
    // TODO: print 5-line 2nd parameter warning block
  }

  void printWarning3(const string &bad){
    // TODO: print 4-line 3rd parameter warning block
  }

  void printWarning4(const string &bad){
    // TODO: print 3-line 4th parameter warning block
  }

  void printNotFound(){
    // TODO: match "<NOT FOUND> To be considered..."
  }

  void printThankYou(){
    cout << "----- THANK YOU -----" << endl;
  }

}
