#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using std::cout;
using std::cin;
using std::string;
using std::vector;

bool validLineInput(string test) {
    for (char a: test) {
        if (a != '*' && a!='.') {
            return false;
        }
    }
    return true;
}

bool empty(string test) {
  for (char a: test) {
      if (a == '*') {
          return false;
      }
  }
  return true;
}
int main (int argc, char const *argv[]) {
    int textboxSize, count, countNum;
    string inputName;
    string outputName;
    bool emp = true;
    count = 0;
    countNum = 0;

    if (argc == 1){
        textboxSize = 5;
        string s;
        vector < vector < string >> input;
        while (getline(cin, s)) {
          input.push_back(vector<string> ({s}));
         }
       }
    else if (argc == 2){
        textboxSize = std::stoi(argv[1]);
      }

    else if (argc == 3){
    }
    else {
        std::ifstream inFile;
        std::ofstream outFile;
        string line;
        vector < vector < string >> input;
        textboxSize = std::stoi(argv[1]);
        inputName = argv[2];
        outputName = argv[3];
        inFile.open(inputName);
        outFile.open(outputName);
        while(getline(inFile,line)) { //read the file into 2D vector
          input.push_back(vector<string>({line}));
        }
        inFile.close();
        for (int i = 0; i < input.size(); i++) {
            if (input.size() < textboxSize) { //if incorrect input size
              cout << "I am 1" << "\n";
              return 2;
            }
          for (int j = 0; j < input[i].size(); j++) {
            if (count == textboxSize && input[i][j] != "") { //no empty line
              cout << count << "\n";
              cout << i << "\n";
              cout << "I am 2" << "\n";
                return 2;
            }
            else if (input[i][j] == "" ) { //incorrect size
              if(count != textboxSize) {
                cout << count << "\n";
                cout << i << "\n";
                cout << input[i][j] << "\n";
                cout << "I am 3" << "\n";
                return 2;
            }
              count = 0; //if correct size
              continue;
            }
            else if (!validLineInput(input[i][j])) { //contain other char
              cout << "I am 4" << "\n";
                return 1;
            }
            else if (input[i][j].length() != textboxSize) { //incorrect size
              cout << "I am 5" << "\n";
                return 2;
            }
            else if (count == textboxSize && emp == true) {
              cout << "I am 6" << "\n";
              return 3;
            }
            else if (!empty(input[i][j])) {
              emp = false;
            }
            count++;
          }
        }
        for (int i = 0; i < input.size(); i++) {
          for (int j = 0; j < input[i].size(); j++) {
            outFile << input[i][j] << "\n";
          }
        }
        outFile.close();
      }

    return 0;
}
