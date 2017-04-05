#include <iostream>
#include "w7integer.h"

using std::cout;
int main() {

  Integer i("1234");
  Integer j("12");
  cout << i << '/' << j << '=' << (i / j) << 'r' << i % j << '=' << (i / j)*j + i % j << '\n';

  i = -1234;
  j = -12;
  cout << i << '/' << j << '=' << (i / j) << 'r' << i % j << '=' << (i / j)*j + i % j << '\n';

  i = -1234;
  j = 12;
  cout << i << '/' << j << '=' << (i / j) << 'r' << i % j << '=' << (i / j)*j + i % j << '\n';

  i = 1234;
  j = -12;

  cout << i << '/' << j << '=' << (i / j) << 'r' << i % j << '=' << (i / j)*j + i % j << '\n';

  i = 200;
  j = 25;
  cout << i << '/' << j << '=' << (i / j) << 'r' << i % j << '=' << (i / j)*j + i % j << '\n';

  i = 25;
  j = 200;
  cout << i << '/' << j << '=' << (i / j) << 'r' << i % j << '=' << (i / j)*j + i % j << '\n';

  Integer k(12);
  cout << k / 2 << ' ' << 30 / k << ' ' <<  30 % k << ' ' << k % 7 << '\n';

  return 0;
}