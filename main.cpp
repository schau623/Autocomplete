#include "bstmap.h"
#include "autocomplete.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <map>

using namespace std;

/*void testBSTAll();
void testACAll();

void testMain() {
  testBSTAll();
  testACAll();
}
*/
int main(int argc, char *argv[]) {
  /*if (argc == 3) {
    Autocomplete ac;
    string filename = argv[1];
    string prefix = argv[2];
    ac.readFile(filename);
    auto results = ac.complete(prefix);
    for (auto &p : results) {
      cout << p.first << "\t" << p.second << endl;
    }
  } else {
    testMain();
  }
  return EXIT_SUCCESS;*/
  BSTMap tree;
  pair<string, int> a;
  a.first = "Seattle";
  a.second = 750000;
  tree.insert(a);
  pair<string, int> b;
  a.first = "Kirkland";
  a.second = 89438;
  tree.insert(b);
  pair<string, int> c;
  a.first = "Bellevue";
  a.second = 83128;
  tree.insert(c);
  cout << tree << endl;
}