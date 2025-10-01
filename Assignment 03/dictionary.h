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
  void loadData(const vector<tuple<string, string, string>> &rawData, const string path);

  // Query with optional filters (returns matching entries).
  vector<Entry> query(const string &keyword,
                           const string *posFilter,
                           bool useDistinct,
                           bool useReverse) const;

  // Counts for header display
  size_t keywordCount() const;
  size_t definitionCount() const;

  // Validate if given token is a part of speech
  static bool isValidPartOfSpeech(const string &token);

private:
  // Main storage: keyword → list of entries
  unordered_map<string, vector<Entry>> dict_;

  size_t keywordCount_;
  size_t definitionCount_;

  static string normalizeKeyword(const string &s);
};

#endif // DICTIONARY_H
