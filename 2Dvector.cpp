#include <iostream>
#include <vector>
using std::cout;
using std::vector;

void mirror(std::vector<std::string> &test) { //have not test for MxN matrix
  int ii, jj;
  std::vector<std::string> mirror1 = test;
  for(int i=0; i<test.size(); i++)
    {
       for(int j=0; j<test[i].size(); j++)
       {
          ii = i;
          jj = test[i].size() - 1 - j;
          mirror1[i][j]=test[ii][jj];
       }
    }
    test = mirror1;
}

void rotate(std::vector<std::string> &test) {
  char temp('\0');
  std::string base(test.size(), '.');
  std::vector<std::string> mirror(test[0].size(), base);
  for (int i=0; i<test.size(); i++){
	for (int j=0;j<test[i].size(); j++){
		mirror [j][test.size()-1-i] = test[i][j];
    }
}
  test = mirror;
}
bool isBlank(std::string test) {
  for (int i = 0; i < test.size(); i++) {
    if (test[i] == '*') {
      return false;
    }
  }
  return true;
}

void removeBlankLine(vector<std::string> &test) {
  for (int i = 0; i < test.size();) {
    if (isBlank(test.at(i))) {
      test.erase(test.begin()+i);
    }
    else {
        i++;
    }
  }
  rotate(test);
  for (int i = 0; i < test.size();) {
    if (isBlank(test.at(i))) {
      test.erase(test.begin()+i);
    }
    else {
        i++;
    }
  }
}

int main() {
    std::string base(5, '.');
    std::vector<std::string> mirror1(5, base);
    std::vector<std::string> blank(5, base);
    std::vector<std::string> blank2(5, base);
    std::vector<std::string> blank3(5, base);
    mirror1[0][1] = '*';
    mirror1[0][0] = '*';
    mirror1[0][2] = '*';
    mirror1[1][0] = '*';

    for (std::string a : mirror1) {
        std::cout << a << "\n";
    }
    std::cout << "\n";
    removeBlankLine(mirror1);
    // for (std::string a : blank) {
    //     std::cout << a << "\n";
    // }
    // std::cout << "\n";
    // rotate(mirror1);
    for (std::string a : mirror1) {
        std::cout << a << "\n";
    }
    // blank = rotate(mirror);
    // for (std::string a : blank) {
    //     std::cout << a << "\n";
    // }
    // std::cout << "\n";
    // blank2 = rotate(blank);
    // for (std::string a : blank2) {
    //     std::cout << a << "\n";
    // }
    // std::cout << "\n";
    // blank3 = rotate(blank2);
    // for (std::string a : blank3) {
    //     std::cout << a << "\n";
    // }
}
