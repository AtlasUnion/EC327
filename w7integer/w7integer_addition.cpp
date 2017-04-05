#include <iostream>
#include "w7integer.h"

using std::cout;
int main() {

  Integer i("1234");
  Integer j(2847);

  i + j;
  j + j + j + j + j + j;
  i + 14;
  cout << 14 + j;

  return 0;
}
