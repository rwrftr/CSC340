#include <iostream>
#include <string>
#include "dictionary.h"
#include "helpers.h"
using namespace std;

int main(){
  Dictionary dict;
  const string path = "./[path]";

  // TODO: load data (from file or hardcoded rawData vector of tuples)
  // dict.loadData(rawData);

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

    // TODO: parse line into {keyword, optional pos, distinct?, reverse?, warnings}
    // - call dict.query(...)
    // - print warnings if needed
    // - print results or not found
  }

  return 0;
}
