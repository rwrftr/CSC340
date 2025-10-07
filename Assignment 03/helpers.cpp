#include "helpers.h"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set> // added
#include <cctype>        // added for tolower
using namespace std;

namespace Helpers{

  void printHeader(int keywordCount, int definitionCount){
    cout << "! Loading data..." << endl;
    cout << "! Loading completed..." << endl;
    cout << "! Closing data file..." << endl;          // need to add path here
    cout << "====== DICTIONARY 340 C++ =====" << endl;
    cout << "------ Keywords: " << keywordCount << endl;
    cout << "------ Definitions: " << definitionCount << endl << endl;
    return;
  }

  void printHowTo(){
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
    printBar();
    for (const Entry &entry : entries) { 
      cout << "    " << keyword << " [" << entry.partOfSpeech << "] : " << entry.definition << endl;
    }
    printBar();

    return;
  }

  string normalizeString(const string &s){
    string out = s;
    for (auto &c : out){
      c = (char)tolower((unsigned char)c);
    }
    return out;
  }

  bool isValidPartOfSpeech(const string &token){
    // avoid C++11 braced init so code compiles w/o -std=c++11 if needed
    static unordered_set<string> POS;
    if (POS.empty()) {
      POS.insert("noun");
      POS.insert("verb");
      POS.insert("adjective");
      POS.insert("adverb");
      POS.insert("conjunction");
      POS.insert("interjection");
      POS.insert("preposition");
      POS.insert("pronoun");
    }
    string t = normalizeString(token);
    return POS.count(t) > 0;
  }
 
  vector<string> parseInput(string line){
    // returns exactly 4 slots: {keyword, pos?, distinct?, reverse?}
    // avoid braced initializer for older compilers: create 4 empty slots
    vector<string> parameters(4);
     
     line = normalizeString(line);
     line.at(0) = toupper(line.at(0));

    // cut out the keyword (robustly)
    size_t space = line.find(' ');
    if (space == string::npos) {
      // single token only -> that is the keyword
      parameters[0] = line;
      return parameters;
    }
    parameters[0] = line.substr(0, space);
    // remove keyword + following spaces
    line = line.substr(space + 1);
    // trim leading spaces
    while (!line.empty() && line.front() == ' ') line.erase(0, 1);

    string currentParam;
    while (!line.empty()) {
      space = line.find(' ');
      if (space == string::npos) {
        currentParam = line;
        line.clear();
      } else {
        currentParam = line.substr(0, space);
        line = line.substr(space + 1);
        // trim leading spaces
        while (!line.empty() && line.front() == ' ') line.erase(0, 1);
      }

      if (currentParam.empty()) continue;

      if(isValidPartOfSpeech(currentParam)){ 
        if (parameters.at(1).empty()) parameters.at(1) = currentParam;
      }
      else if(currentParam == "distinct"){ 
        if (parameters.at(2).empty()) parameters.at(2) = "distinct"; 
      }
      else if(currentParam == "reverse"){ 
        if (parameters.at(3).empty()) parameters.at(3) = "reverse";
      }
      else {
        // unknown token - we ignore here; main can check and warn if necessary
      }
    }

    return parameters;
  };

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
