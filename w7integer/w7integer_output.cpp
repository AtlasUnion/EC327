#include <iostream>
#include "w7integer.h"

using std::cout;
int main() {

  Integer i("1234");
  Integer j(123);
  Integer k("-1230001");
  Integer z;

  std::cout << i << j << ' ' << k << ' ' << z << '\n';
  return 0;
}
