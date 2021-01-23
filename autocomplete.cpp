#include "autocomplete.h"
#include <sstream>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

void testBSTAll();

void Autocomplete::readFile(const string &fileName) {
    string s;
    uint64_t i;
    string t;
    ifstream ifs(fileName);
    getline(ifs, s);
    vector<pair<string, uint64_t>> v;
    if(ifs.is_open()){
    while(getline(ifs, s))
      {
          stringstream ss(s);
          ss >> i;
          getline(ss, t);
          pair<string, uint64_t> p;
          p.first = t;
          p.second = i;
          v.push_back(p);
      }
      ifs.close();
    }
    return;
}

bool Autocomplete::sortByWeight(BSTMap::value_type &a, BSTMap::value_type &b) 
{
  return a.second > b.second;
}

vector<BSTMap::value_type> Autocomplete::complete(const string &prefix) const 
{
  vector<BSTMap::value_type> v =  phrases.getAll(prefix);
  return v;
}