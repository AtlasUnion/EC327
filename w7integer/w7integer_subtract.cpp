#include <iostream>
#include "w7integer.h"

using std::cout;
int main() {

  Integer i("1234");
  Integer j(2847);

  cout << i - j << ' ' << j - i << '\n';

  i = 10000;
  j = 9912;
  cout << i - j << ' ' << j - i << '\n';

  i = 0;
  j = 1990;
  cout << i - j << ' ' << j - i << '\n';

  i = -689;
  j = 1232;
  cout << i - j << ' ' << j - i << '\n';

  i = -689;
  j = -1232;
  cout << i - j << ' ' << j - i << '\n';

  i = 689;
  j = -1232;
  cout << i - j << ' ' << j - i << '\n';

  i = 689;
  j = 1232;
  cout << i - j << ' ' << j - i << '\n';

  return 0;
}