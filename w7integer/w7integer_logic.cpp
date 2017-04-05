#include <iostream>
#include "w7integer.h"

using std::cout;

void compare(string i, string j) {
  Integer ii(i);
  Integer jj(j);

  std::cout << ( (ii > jj) ? (i + ">" + j) : ("not " + i + ">" + j)) << '\n';
  std::cout << ( (ii < jj) ? (i + "<" + j) : ("not " + i + "<" + j)) << '\n';

  std::cout << ( (ii == jj) ? (i + "==" + j) : ("not " + i + "==" + j)) << '\n';
  std::cout << ( (ii != jj) ? (i + "!=" + j) : ("not " + i + "!=" + j)) << '\n';

  std::cout << ( (ii >= jj) ? (i + ">=" + j) : ("not " + i + ">=" + j)) << '\n';
  std::cout << ( (ii <= jj) ? (i + "<=" + j) : ("not " + i + "<=" + j)) << '\n';

}

void testbool(string s)  {
  std::cout << ( Integer(s) ? s + " is true" : s + " is false")  << '\n';
}

int main() {
  string val1[] = {"6291021234", "100", "-100", "1099", "-200", "-400", "-301"};
  string val2[] = {"6291021234", "99", "100", "911", "-100", "300", "-301"};

  for (int i = 0; i < 7; i++)
    compare(val1[i], val2[i]);

  string s[] = {"2", "0", "-3", "100", "-0"};

  for (int i = 0; i < 5; i++)
    testbool(s[i]);

}