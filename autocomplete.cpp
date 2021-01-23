#include "autocomplete.h"
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

void testBSTAll();

void Autocomplete::readFile(const string &fileName) {
    ifstream ifs(fileName);
    string line;
    uint64_t weight;
    string location;
    vector<pair<string, uint64_t>> v;
    if(ifs.is_open()){
      getline(ifs, line); //To get rid of first line from file.
        while(getline(ifs, line)){
            stringstream ss(line);
            ss >> weight;
            getline(ss, location);
            pair<string, uint64_t> p;
            p.first = location;
            p.second = weight;
            cout << p.first << " " << p.second;
            phrases.insert(p);
        }
    }
  ifs.close();

  phrases.rebalance();
  // cout << phrases << endl;
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