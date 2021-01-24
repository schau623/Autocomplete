#include "autocomplete.h"
#include <sstream>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

void testBSTAll();
inline string Autocomplete::trim(string& str)
{
    str.erase(0, str.find_first_not_of(' '));       //erase spaces before
    str.erase(str.find_last_not_of(' ')+1);         //erase spaces after
    return str;
}

void Autocomplete::readFile(const string &fileName){
    string s;
    uint64_t i;
    string t;
    ifstream ifs(fileName);
    getline(ifs, s);
    vector<pair<string, uint64_t>> v;
    if(ifs.is_open()){
    while(getline(ifs, s)) //getline(ifs, s)
      {
          stringstream ss(s);
          ss >> i;
          getline(ss, t);
          pair<string, uint64_t> p;
          p.first = trim(t);
          cout << t << endl;
          p.second = i;
          //cout << p.first << ", " << p.second << endl;
          phrases.insert(p);
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

