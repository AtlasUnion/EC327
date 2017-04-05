#include <iostream>
#include "w7integer.h"

using std::cout;
int main() {

  Integer i(999);
  Integer j(1002);
  Integer k(100000);

  i += Integer(2);
  j *= Integer(3);
  k -= Integer("122");

  cout << i << ' ' << j << ' ' << k << '\n';

  i /= Integer(2);
  k = 18;
  k /= Integer(6);
  j %= Integer(6);


  cout << i << ' ' << j << ' ' << k << '\n';

  return 0;
}