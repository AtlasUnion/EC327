#include <iostream>
#include <tuple>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::string;
using std::make_tuple;
using std::tuple;
using std::vector;
using std::get;

int main() {
  vector< tuple<string, int, int, int, int> > collectionOfCars;
  string ID;
  int xPos, yPos, xVel, yVel;
  while(cin >> ID >> xPos >> yPos >> xVel >> yVel) {
    collectionOfCars.push_back(make_tuple(ID, xPos, yPos, xVel, yVel));
  }
}
