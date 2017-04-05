#include <iostream>
using std::cin;
using std::cout;

#include "w7integer.h"

int main() {
  Integer i;
  Integer total;

  while (cin >> i) {
    cout << i << '\n';
    total = total + i;
  }

  cout << total << '\n';
  return 0;
}