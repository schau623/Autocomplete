#include "bstmap.h"
#include "autocomplete.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <map>

using namespace std;

/**/void testBSTAll();
void testACAll();

void testMain() {
  testBSTAll();
  testACAll();
}

int main(int argc, char *argv[]) {
  if (argc == 3) {
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
  return EXIT_SUCCESS;
 /* BSTMap tree;
  pair<string, int> a;
  a.first = "Seattle";
  a.second = 750000;
  tree.insert(a);
  pair<string, int> b;
  b.first = "Sea";
  b.second = 89438;
  tree.insert(b);
  pair<string, int> c;
  c.first = "Seaatle";
  c.second = 83128;
  tree.insert(c);
  tree["Bandori"] = 30;
  tree.rebalance();



  BSTMap tree2;
  pair<string, int> a2;
  a2.first = "Seattle";
  a2.second = 750000;
  tree2.insert(a2);
  pair<string, int> b2;
  b2.first = "Sea";
  b2.second = 89438;
  tree2.insert(b2);
  pair<string, int> c2;
  c2.first = "Seaatle";
  c2.second = 83128;
  tree2.insert(c2);
  tree2["Bandori"] = 30;
  tree2.rebalance();
  cout << tree2.size() << endl;
  cout << tree2 << endl;

  tree.clear();
  cout << tree.empty() << endl;
  cout << tree.size() << endl;*/
}