#include "autocomplete.h"
#include <algorithm>
#include <fstream>

using namespace std;

void testBSTAll();

void Autocomplete::readFile(const string &fileName) 
{
  ifstream ifs(fileName);
  ifs.open(fileName);
  mapped_type a;
  key_type b;
  while(ifs >> a >> b)
  {
    pair<key_type, mapped_type> to_add;
    to_add.first = a;
    to_add.second = b;
    phrases.insert(to_add);
  }
  ifs.close();
  phrases.rebalance();
}

bool Autocomplete::sortByWeight(BSTMap::value_type &a, BSTMap::value_type &b) 
{
  return a.second > b.second;
}

vector<BSTMap::value_type>
Autocomplete::complete(const BSTMap::key_type &prefix) const 
{
  vector<BSTMap::value_type> v;
  // TODO(student)
  return v;
}
