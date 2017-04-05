#include <iostream>
#include "w7integer.h"
#include <string>
using std::cout;
using std::string;

int main() {
  Integer i(12);
  cout << i * 2 << ' ' << 3 * i << ' ' <<  i*i + 4 << '\n';

  string val1[] = {"6291021234", "100", "-100", "1099", "-200", "-400", "-301", "12", "0", "-12"};
  string val2[] = {"6291021234", "99", "100", "911", "-100", "300", "-301", "0", "122", "0"};

  for (int i = 0; i < 10; i++) {
    Integer ii(val1[i]);
    Integer jj(val2[i]);

    cout << ii*jj << '\n';
  }
  return 0;
}
