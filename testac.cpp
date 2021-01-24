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

void studentACTest01()
{
  Autocomplete ac;
  cout << "Starting studentACTest01" << endl;
  ac.readFile("wiktionary.txt");
  auto v = ac.complete("cat");
  assert(v.size() == 11);
  assert(v[0].first == "catch");
  assert(v[0].second == 4971880);
  assert(v[10].first == "catharine");
  assert(v[10].second == 423969);
  cout << "Ending studentACTest" << endl;
}

void studentACTest02()
{
  Autocomplete ac;
  cout << "Starting studentACTest02" << endl;
  ac.readFile("Top30Players.txt");
  auto v = ac.complete("Nikola");
  assert(v.size() == 2);
  assert(v[0].first == "Nikola Jokic");
  assert(v[0].second == 15);
  assert(v[1].first == "Nikola Vucevic");
  assert(v[1].second == 9);
  auto v2 = ac.complete("J");
  assert(v2.size() == 4);
  assert(v2[3].first == "Jayson Tatum");
  assert(v2[3].second == 0);
  cout << "Ending studentACTest02" << endl;
}

// // Calling all test functions
void testACAll() {
  testAC01();
  testAC02();
  studentACTest01();
  studentACTest02();

}