#include <iostream>
#include <string>
#include <fstream>
using std::cout;
using std::cin;
using std::string;

bool validInput(string test) {
    for (char a: string test) {
        if (a != '*' && a!='.') {
            return false;
        }
    }
    return true;
}
int main (int argc, char const *argv[]) {
    int textboxSize;
    string inputName;
    string outputName;
    switch (argc)
    {
    case 1:
        textboxSize = 5;
        inputName =
        break;
    case 2:
        textboxSize = argv[1];
        break;
    case 3:
        break;
    case 4:
        break;
    default:
        break;
    }
        ifstream inFile;
        ifstream outFile;
        inFile.open(inputName);
        outFile.open(outputName);
        while(getline(inFile,line)) {
            if (line == "") {
                continue;
            }
            if (!validInput(line)) {
                inFile.close();
                outFile.close();
                return 3;
            }
        }

}
