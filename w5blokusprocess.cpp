// Copyright 2020 ZHIYUAN RUAN zruan@bu.edu
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using std::cout;
using std::cin;
using std::string;
using std::vector;

bool validLineInput(string test) {
  for (char a : test) {
    if (a != '*' && a !='.') {
      return false;
    }
  }
  return true;
}

bool empty(string test) {
  for (char a : test) {
    if (a == '*') {
      return false;
    }
  }
  return true;
}
int validInput(vector <vector<string>> input, int size, bool emp, int count) {
  for (int i = 0; i < input.size(); i++) {
    if (input.size() < size) {
      return 2;
    }
    for (int j = 0; j < input[i].size(); j++) {
      if (i == input.size()-1 && count != size) {
        return 2;
      }
      if (count == size) {
        if (input[i][j] != "") {
          return 2;
        } else if (emp == true) {
          return 3;
        }
        emp = true;
      }
      if ( input[i][j] == "" ) {
        if (count != size) {
          return 2;
        }
        count = 0;
        continue;
      }
      if (!validLineInput(input[i][j])) {
        return 1;
      }
      if (input[i][j].length() != size) {
        return 2;
      }
      if (!empty(input[i][j])) {
        emp = false;
      }
      count++;
    }
  }
  return 0;
}
int main(int argc, char const *argv[]) {
  int textboxSize, count, countNum, result;
  vector < vector < string >> input;
  string inputName;
  string outputName;
  bool emp = true;
  count = 0;
  countNum = 0;

  if (argc == 1) {
    textboxSize = 5;
    string s;
    while (getline(cin, s)) {
      input.push_back(vector<string> ({s}));
    }
    result = validInput(input, textboxSize, emp, count);
    if (result != 0) {
      return result;
    }
    for (int i = 0; i < input.size(); i++) {
      for (int j = 0; j < input[i].size(); j++) {
        cout << input[i][j] << "\n";
      }
    }
  } else if (argc == 2) {
    textboxSize = std::stoi(argv[1]);
    string s;
    while (getline(cin, s)) {
      input.push_back(vector<string> ({s}));
    }
    result = validInput(input, textboxSize, emp, count);
    if (result != 0) {
      return result;
    }
    for (int i = 0; i < input.size(); i++) {
      for (int j = 0; j < input[i].size(); j++) {
        cout << input[i][j] << "\n";
      }
    }
  } else if (argc == 3) {
    std::ifstream inFile;
    string line;
    textboxSize = std::stoi(argv[1]);
    inputName = argv[2];
    inFile.open(inputName);
    while (getline(inFile, line)) {
      input.push_back(vector<string>({line}));
    }
    inFile.close();
    result = validInput(input, textboxSize, emp, count);
    if (result != 0) {
      return result;
    }
    for (int i = 0; i < input.size(); i++) {
      for (int j = 0; j < input[i].size(); j++) {
        cout << input[i][j] << "\n";
      }
    }
  } else {
    std::ifstream inFile;
    std::ofstream outFile;
    string line;
    textboxSize = std::stoi(argv[1]);
    inputName = argv[2];
    outputName = argv[3];
    inFile.open(inputName);
    outFile.open(outputName);
    while (getline(inFile, line)) {
      input.push_back(vector<string>({line}));
    }
    inFile.close();
    result = validInput(input, textboxSize, emp, count);
    if (result != 0) {
      return result;
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
