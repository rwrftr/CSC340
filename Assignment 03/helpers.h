#ifndef HELPERS_H
#define HELPERS_H

#include <string>
#include <vector>
#include "dictionary.h"

using namespace std;

namespace Helpers{
  // Print header line (dictionary title + counts)
  void printHeader(int keywordCount, int definitionCount);

  // Print the PARAMETER HOW-TO block
  void printHowTo();

  // Print bars like " |"
  void printBar();

  // Print results
  void printEntries(const string &keyword, const vector<Entry> &entries);

  // Print warnings for bad parameters (2nd, 3rd, 4th)
  void printWarning2(const string &bad);
  void printWarning3(const string &bad);
  void printWarning4(const string &bad);

  // Print NOT FOUND block
  void printNotFound();

  // Print thank you
  void printThankYou();
}

#endif // HELPERS_H
