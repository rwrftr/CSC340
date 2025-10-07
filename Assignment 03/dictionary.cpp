#include "dictionary.h"
#include <algorithm>
#include <cctype>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <filesystem>
using namespace std;

Dictionary::Dictionary() : keywordCount_(0), definitionCount_(0) {}

void Dictionary::loadData(string path){
  fstream ioFile;
  cout << "! Opening data file... " << path << endl;

  ioFile.open(path, ios::in);

  // while the current path doesn't exist, prompt user for new path
  while(!(ioFile.is_open())){
    cout << "<!>ERROR<!> ===> File could not be opened." << endl <<
            "<!>ERROR<!> ===> provided file path: " << path << endl <<
            "<!>Enter the CORRECT data file path: ";
    getline(cin, path);
    ioFile.open(path, ios::in);
  }
  
  // once current path DOES exist...
  string line, keyword, pos, definition;

  // for every line, separate keyword, part of speech, then definition
  while (getline(ioFile, line)) {
    if(line.length() <1) {continue;}
    
    // parse: keyword pos definition (space separated; definition may contain spaces)
    size_t p1 = line.find(' ');
    if (p1 == string::npos) continue; // malformed line -> skip
    keyword = line.substr(0, p1);
    keyword.at(0) = toupper(keyword.at(0));
    cout << keyword << " ";
    size_t p2 = line.find(' ', p1 + 1);
    if (p2 == string::npos) continue; // malformed line -> skip
    pos = line.substr(p1 + 1, p2 - (p1 + 1));
    cout << pos << " ";
    definition = line.substr(p2 + 1);
    cout << definition << endl;

    // normalize: remove any stray leading/trailing spaces (if needed)
    // (keeping case as-is may be desired; adapt if needed)
    
    // add pos and definition to dictionary; using operator[] ensures vector exists
    Entry e;
    e.partOfSpeech = pos;
    e.definition = definition;
    dict_[keyword].push_back(e);
    ++definitionCount_;
  }

  keywordCount_ = dict_.size();
  //definitionsCount_
 
  ioFile.close();
  return;
}

vector<Entry> Dictionary::query(const string &keyword,
                                const string posFilter,
                                bool useDistinct,
                                bool useReverse) const
{
  vector<Entry> results;

  // if keyword not found, return empty results
  auto it = dict_.find(keyword);
  if(it == dict_.end()){
    return results;
  }

  // grab the entries (copy)
  results = it->second;

  // filter by POS if provided (posFilter expected to be empty string if not used)
  if(!posFilter.empty()){
    vector<Entry> filtered;
    for (const Entry &current : results) {
      if (current.partOfSpeech == posFilter) filtered.push_back(current);
    }
    results = std::move(filtered);
  } 
  
  if(useDistinct){
    // TODO

    // a set containing all the checked definitions
    // iterate through the results vector and remove entries that already 
    //.   got checked i.e. are already in the set

  }
  if(useReverse){ reverse(results.begin(), results.end()); }

  return results;
}

int Dictionary::keywordCount() const{
  return keywordCount_;
}

int Dictionary::definitionCount() const{
  return definitionCount_;
}


