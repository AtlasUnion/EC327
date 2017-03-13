#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using std::cout;
using std::cin;
using std::string;
using std::vector;

bool validLineInput(string test) {
    for (char a: string test) {
        if (a != '*' && a!='.') {
            return false;
        }
    }
    return true;
}
int main (int argc, char const *argv[]) {
    int textboxSize, count, countNum;
    string inputName;
    string outputName;
    count = 0;
    countNum = 0;

    switch (argc)
    {
    case 1:
        textboxSize = 5;
        string s;
        while (cin >> s) {

         }
        break;
    case 2:
        textboxSize = std::stoi(argv[1]);
        break;
    case 3:
        break;
    default:
        ifstream inFile;
        ifstream outFile;
        vector < vector < string >> input;
        textboxSize = std::stoi(argv[1]);
        inputName = argv[2];
        outputName = argv[3];
        inFile.open(inputName);
        outFile.open(outputName);
        while(getline(inFile,line)) {
            if (!validLineInput(line)) {
                inFile.close();
                outFile.close();
                return 1;
            }
          input.push_back(vector<string>(line));
    }
    for (int i = 0; i < input.size(); i++) {
        if(input[i].size() != textboxSize) {
          return 2;
        }
      for (int j = 0; j < input[i].size(); j++) {
        if (input[i][j] == '*') {
            countNum++;
        }
        if (input[i][j] = '') {
          if(count != textboxSize) {
            return 2;
          }
          if (countNum = 0) {
            return 3;
          }
          count = 0;
          countNum = 0;
        }
        else if (count == textboxSize && input[i][j] != '') {
          return 2;
        }
        count++;
      }
    }
        break;
    }
    return 0;
}
