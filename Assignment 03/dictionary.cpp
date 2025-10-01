#include "dictionary.h"
#include <algorithm>
#include <cctype>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

Dictionary::Dictionary() : keywordCount_(0), definitionCount_(0) {}

void Dictionary::loadData(string path){
  fstream ioFile;

  cout << "! Opening data file... " << path << endl;

  // while the current path doesn't exist, prompt user for new path
  while(!(filesystem::exists(path))){
    cout << "<!>ERROR<!> ===> File could not be opened." << endl <<
            "<!>ERROR<!> ===> provided file path: " << path << endl <<
            "<!>Enter the CORRECT data file path: ";
    getline(cin, path);
  }
  
  // once current path DOES exist...
  ioFile.open(path, ios::in);
  string line, keyword, pos, definition;
  vector<Entry> newVector;

  // for every line, separate keyword, part of speech, then definition
  while (getline(ioFile, line)) {
    newVector.clear(); // erase last time's entry

    // cut off keyword
    keyword = line.substr(0,line.find_first_of(" ")+1); 
    line = line.substr(line.find_last_of(" ")+1); 

    // cut off pos
    pos = line.substr(0,line.find_first_of(" ")+1); 
    line = line.substr(line.find_last_of(" ")+1);
    
    // cut off definition
    definition = line;

    // if the dictionary already has the keyword, grab the existing vector
    if(dict_.find(keyword) != dict_.end()){ newVector = dict_.at(keyword); } 

    // add pos and definition, then add vector to dictionary
    newVector.push_back({pos, definition});
    dict_.insert({keyword, newVector});
  }

  keywordCount_ = dict_.size();
  //definitionsCount_

  ioFile.close();
  return;
}

vector<Entry> Dictionary::query(const string &keyword,
                                const string *posFilter,
                                bool useDistinct,
                                bool useReverse) const
{
  vector<Entry> results;
  // TODO:
  // 1) normalize keyword, find in dict_
  set<int> set{};
  vector<Entry> Entries = dict_.at(keyword);

  // only if posFilter exists
  for(Entry current : Entries){
    if (current.partOfSpeech != *posFilter){
      //Entries.erase(current);
    }
  }

  if(useDistinct){}
  if(useReverse){}

  // 2) filter by pos if provided
  // 3) apply distinct (deduplicate by definition)
  // 4) apply reverse (reverse order)
  return results;
}

int Dictionary::keywordCount() const{
  return keywordCount_;
}

int Dictionary::definitionCount() const{
  return definitionCount_;
}

string Dictionary::normalizeKeyword(const string &s){
  string out = s;
  for (auto &c : out)
    c = tolower(c);
  return out;
}

bool Dictionary::isValidPartOfSpeech(const string &token)
{
  static unordered_set<string> POS = {
      "noun", "verb", "adjective", "adverb",
      "conjunction", "interjection", "preposition", "pronoun"};
  string t = normalizeKeyword(token);
  return POS.count(t) > 0;
}
