#include <iostream>
#include "w7integer.h"

using std::cout;
int main() {

  Integer i("1234");
  Integer j, k;

  j = i++;
  k = ++i;
  cout << i << ' ' << j << ' ' << k << '\n';

  i = string("1000000");
  j = i--;
  k = --i;
  cout << i << ' ' << j << ' ' << k << '\n';

  i = string("-1000000");
  j = i--;
  k = --i;
  cout << i << ' ' << j << ' ' << k << '\n';

  i = string("9999999999");
  j = i++;
  k = ++i;
  cout << i << ' ' << j << ' ' << k << '\n';

  return 0;
}