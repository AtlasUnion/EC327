#include <iostream>
#include "w7integer.h"

using std::cout;
int main() {

  Integer z1("0000");
  Integer z2("-0");
  Integer large("1000000000000000");
  std::cout << "zero: " << z1 << '\n';
  std::cout << "zero: " << z2 << '\n';

  std::cout << "zero: " << Integer(100) + Integer(-100) << '\n';
  std::cout << "zero: " << Integer(100) - 100 << '\n';
  std::cout << "zero: " << 1000  - Integer(1000) << '\n';
  std::cout << "zero: " << large - large << '\n';
  z1 = large - large;
  std::cout << "zero: " << z1 << '\n';

  std::cout << "zero: " << (Integer("1000000000000000") - Integer("1000000000000000")) << '\n';

  z2 = Integer(300) - Integer(400) + Integer(100);
  std::cout << "zero: " << z2 << '\n';

  return 0;
}