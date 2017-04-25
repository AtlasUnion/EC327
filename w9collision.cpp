// Copyright 2020 ZHIYUAN RUAN zruan@bu.edu
#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using std::cin;
using std::cout;
using std::string;
using std::make_tuple;
using std::tuple;
using std::vector;
using std::get;
using std::sqrt;
using std::sort;
bool tupleCompare(tuple<string, string, double> first, tuple<string, string, double> second) {
  return get<2>(first) < get<2>(second);
}

tuple<string, string, double> willCollide(tuple<string, double, double, double, double> car1, tuple<string, double, double, double, double> car2) {
  double posDifX = get<1>(car1) - get<1>(car2);
  double posDifY = get<2>(car1) - get<2>(car2);
  double velDifX = get<3>(car1) - get<3>(car2);
  double velDifY = get<4>(car1) - get<4>(car2);

  double a = velDifX*velDifX + velDifY*velDifY;
  double b = 2*(posDifX*velDifX+posDifY*velDifY);
  double c = posDifX*posDifX + posDifY*posDifY - 100;
  double possibleSol = b*b - 4*a*c;  // b^2-4ac
  double sol1, sol2;
  if ((a == 0) || possibleSol < 0) {    //check for a = 0 or b^2-4ac < 0
    return make_tuple("0", "0", 0);
  } else {
    sol1 = (-b + sqrt(possibleSol))/(2*a);
    sol2 = (-b - sqrt(possibleSol))/(2*a);
    if (sol1 <= sol2 && sol1 > 0){
      return make_tuple(get<0>(car1), get<0>(car2), sol1);
    } else if (sol2 <= sol1 && sol2 > 0) {
      return make_tuple(get<0>(car1), get<0>(car2), sol2);
    } else {
      return make_tuple("0", "0", 0);
    }
  }

}

bool containString(vector<string> colliedCars, string check) {
  for (int i = 0; i < colliedCars.size(); i++) {
    if (check == colliedCars[i]) {
      return true;
    }
  }
  return false;
}

int main() {
  vector< tuple<string, double, double, double, double> > collectionOfCars; //All info of cars
  vector< tuple<string, string, double> > collision;  //all possible collision
  vector< string > hasCollided;   //store ID of cars already collid
  vector < tuple<string, string, double> > collisionResult;     //result of collision
  string ID;
  double xPos, yPos, xVel, yVel;
  while (cin >> ID >> xPos >> yPos >> xVel >> yVel) {   //read in info about cars
    collectionOfCars.push_back(make_tuple(ID, xPos, yPos, xVel, yVel));
  }
  for (int i = 0; i < collectionOfCars.size(); i++) {   //test for time of collision for different pairs of cars
    for (int j = i+1; j < collectionOfCars.size(); j++) {
      tuple<string, string, double> result = willCollide(collectionOfCars[i], collectionOfCars[j]);
      if (get<0>(result) != "0") {
        collision.push_back(result);
      }
    }
  }
  sort(collision.begin(), collision.end(), tupleCompare);
  for (int k = 0; k < collision.size(); k++) {
    if (!containString(hasCollided, get<0>(collision[k])) && !containString(hasCollided, get<1>(collision[k]))) {
      hasCollided.push_back(get<0>(collision[k]));
      hasCollided.push_back(get<1>(collision[k]));
      collisionResult.push_back(collision[k]);
    }
  }
  cout << "there are " << collectionOfCars.size() << " vehicles" << "\n";
  cout << "collision report" << "\n";
  if (collisionResult.size() == 0) {
    cout << "none" << "\n";
  } else {
    for (int i = 0; i < collisionResult.size(); i++) {
        cout << "at " << get<2>(collisionResult[i]) << " " << get<0>(collisionResult[i]) << " collided with " << get<1>(collisionResult[i]) << "\n";
    }
}
  cout << "the remaining vehicles are" << "\n";
  if (hasCollided.size() == collectionOfCars.size()) {
    cout << "none" << "\n";
  } else {
    for (int j = 0; j < collectionOfCars.size(); j++) {
      if (!containString(hasCollided, get<0>(collectionOfCars[j]))) {
        ID = get<0>(collectionOfCars[j]);
        xPos = get<1>(collectionOfCars[j]);
        yPos = get<2>(collectionOfCars[j]);
        xVel = get<3>(collectionOfCars[j]);
        yVel = get<4>(collectionOfCars[j]);
        cout << ID << " " << xPos << " " << yPos << " " << xVel << " " << yVel << "\n";
      }
  }
}
}
