#include <iostream>
#include <string>
#include "dictionary.h"
#include "helpers.h"
using namespace std;

int main(){
  Dictionary dict;
  const string path = "inputFile.txt";

  // TODO: load data (from file or hardcoded rawData vector of tuples)
  dict.loadData(path);
  Helpers::printHeader(dict.keywordCount(), dict.definitionCount());

  int searchCount = 1;
  while (true){
    cout << "Search [" << searchCount++ << "]: ";
    string line;
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
    vector<Entry> results = dict.query(inputs.at(0),
                                        inputs.at(1),
                                        (inputs.at(1) != ""),
                                        (inputs.at(2) != "")); // query(keyword, pos, bool, bool);
    
    Helpers::printEntries(inputs.at(0), results);

    // - print warnings if needed
    // - print results or not found
  }

  return 0;
}
