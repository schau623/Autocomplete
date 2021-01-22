#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include "bstmap.h"

using namespace std;

class Autocomplete {
public:
  using key_type = string;
  using mapped_type = uint64_t;
  using value_type = pair<key_type, mapped_type>;
  Autocomplete() = default;
  void readFile(const string &fileName);
  vector<BSTMap::value_type> complete(const string &prefix) const;

private:
  // BST of phrases and their frequency
  BSTMap phrases;

  // sorter
  bool static sortByWeight(BSTMap::value_type &a, BSTMap::value_type &b);
};

#endif // AUTOCOMPLETE_H
