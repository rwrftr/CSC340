#include "dictionary.h"
#include <algorithm>
#include <cctype>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Dictionary::Dictionary() : keywordCount_(0), definitionCount_(0) {}

void Dictionary::loadData(const vector<tuple<string, string, string>> &rawData, string path){
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

  ioFile.close();
  
  
  // TODO: Insert each triple {keyword, pos, definition} into dict_
  // - normalize keyword
  // - push_back an Entry into the vector
  // - update counts
}

vector<Entry> Dictionary::query(const string &keyword,
                                const string *posFilter,
                                bool useDistinct,
                                bool useReverse) const
{
  vector<Entry> results;
  // TODO:
  // 1) normalize keyword, find in dict_
  // 2) filter by pos if provided
  // 3) apply distinct (deduplicate by definition)
  // 4) apply reverse (reverse order)
  return results;
}

size_t Dictionary::keywordCount() const{
  return keywordCount_;
}

size_t Dictionary::definitionCount() const{
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
