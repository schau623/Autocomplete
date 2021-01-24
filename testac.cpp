#include "autocomplete.h"
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void testAC01() {
  cout << "Starting AC test01" << endl;
  cout << "* Testing basic autocomplete" << endl;
  Autocomplete ac;
  ac.readFile("small.txt");
  auto v = ac.complete("hel");
  assert(v.size() == 2);
  assert(v[0].first == "help");
  assert(v[0].second == 20);
  assert(v[1].first == "hello");
  assert(v[1].second == 10);
  cout << "Ending tesAC01" << endl;
}

void testAC02() {
  cout << "Starting AC test02" << endl;
  cout << "* Testing cities autocomplete" << endl;
  Autocomplete ac;
  ac.readFile("cities.txt");
  auto v = ac.complete("Sea");
  assert(v.size() == 47);
  assert(v[0].first == "Seattle, Washington, United States");
  assert(v[0].second == 608660);
  assert(v[46].first == "Seabeck, Washington, United States");
  assert(v[46].second == 1105);
  cout << "Ending tesAC02" << endl;
}

void studentACTest()
{
  Autocomplete ac;
  cout << "Starting studentACTest" << endl;
  ac.readFile("wiktionary.txt");
  auto v = ac.complete("cat");
  assert(v.size() == 11);
  assert(v[0].first == "catch");
  assert(v[0].second == 4971880);
  assert(v[10].first == "catharine");
  assert(v[10].second == 423969);
  cout << "Ending studentACTest" << endl;

}


// // Calling all test functions
void testACAll() {
  testAC01();
  testAC02();
  studentACTest();

}