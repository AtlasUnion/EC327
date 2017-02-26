#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> 
#include <vector>
using std::string;

bool isValid(string check) {
    countX = 0;
    countO = 0;
    if (check.length() > 6 || (xWon(check) && oWon(check))) {
        return false;
    }
    for (int i = 0; i < check.length(); i++) {
        if (check[i] == 'x') {
            countX++;
        }
        else if (check[i] == 'o') {
            countO++;
        }
    }
    if (abs(countX-countO) > 1) {
        return false;
    }
    return true;
}

bool xWon (string check) {
    
}

bool oWon(string check) {
    
}

bool BoardFull(string check) {
    for (int i = 0; i < check.length(); i++) {
        if (check[i] == '#') 
            return false;
    }
    return true;
}
void checkFile(vector test) {
    for (int i = 0; i < test.end(); i++) {
        string check = test.at(i);
        if (!isValid(check) {
            test.at(i) += "i";
        }
        else if (BoardFull(check)) {
            test.at(i) += "t";
        }
        else if (xWom(check)) {
            test.at(i) += "x";
        }
        else if (yWon(check)) {
            test.at(i) += "o";
        }
    }
}

int main() {
    ifstream outfile;
    vetor<string> inFile;
    outfile.open("tictactoeboards.txt", ios::in || ios::out);
    if(outfile.isopen()) {
        while (getline(outfile, line)) {
            inFile.push_back(line);
        }
    }
    checkFile(inFile);
    
    outfile.close();
    return 0;
}
