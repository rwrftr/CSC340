#include <iostream>
#include <string>
#include "dictionary.h"
#include "helpers.h"
using namespace std;

int main(){
  Dictionary dict;
  const string path = "inputFile.txt";
  dict.loadData(path);
  Helpers::printHeader(dict.keywordCount(), dict.definitionCount());
  string line;

  int searchCount = 1;
  while (true){
    cout << "Search [" << searchCount++ << "]: ";
    
    if (!getline(cin, line))
      break;

    if (line == "!q" || line == "!Q"){
      Helpers::printThankYou();
      break;
    }

    if (line == "!help" || line.empty()){
      Helpers::printBar();
      Helpers::printHowTo();
      Helpers::printBar();
      continue;
    }
    
    // parse line into {keyword, optional pos, distinct?, reverse?}
    vector<string> inputs = Helpers::parseInput(line);
    // query(keyword, pos, bool, bool);
    vector<Entry> results = dict.query(inputs.at(0),
                                        inputs.at(1),
                                        (inputs.at(1) != ""),
                                        (inputs.at(2) != "")); 
    
    if(results.size() < 1){
      // print no results
      cout << "no results found" << endl;
      continue;
    }
                              
    // print results                                  
    Helpers::printEntries(inputs.at(0), results);

    // TODO: print warnings if needed
  }

  return 0;
}
