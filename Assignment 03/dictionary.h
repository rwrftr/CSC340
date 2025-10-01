#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Represents one definition (part of speech + definition text)
struct Entry{
  string partOfSpeech;
  string definition;
};

class Dictionary{
public:
  Dictionary();

  // Load all keyword data (called once at start).
  void loadData(const string path);

  // Query with optional filters (returns matching entries).
  vector<Entry> query(const string &keyword,
                           const string *posFilter,
                           bool useDistinct,
                           bool useReverse) const;

  // Counts for header display
  int keywordCount() const;
  int definitionCount() const;

  // Validate if given token is a part of speech
  static bool isValidPartOfSpeech(const string &token);

private:
  // Main storage: keyword → list of entries
  unordered_map<string, vector<Entry>> dict_;

  int keywordCount_;
  int definitionCount_;

  static string normalizeKeyword(const string &s);
};

#endif // DICTIONARY_H
