// Copyright 2020 ZHIYUAN RUAN zruan@bu.edu
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
// #include "timer.h"
using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::sqrt;
using std::sort;

class Car{
 public:
    string ID;
    double x, y, xVel, yVel;
    bool collided;
    Car(string ID, double x, double y, double xVel, double yVel, bool collided){
      this->ID = ID;
      this->x = x;
      this->y = y;
      this->xVel = xVel;
      this->yVel = yVel;
      this->collided = collided;
    }
};
struct collisionOfCars{
  Car *firstCar;
  Car *secondCar;
  double time;
};

bool tupleCompare(const collisionOfCars &first, const collisionOfCars &second) {
  return first.time < second.time;
}

double willCollide(Car *car1, Car *car2) {
  // Timer one("Diff");
  // Timer two("mult");
  // one.start();
  double posDifX = car1->x - car2->x;
  double posDifY = car1->y - car2->y;
  double velDifX = car1->xVel - car2->xVel;
  double velDifY = car1->yVel - car2->yVel;
  // one.stop();
  // two.start();
  double a = velDifX*velDifX + velDifY*velDifY;
  double b = posDifX*velDifX+posDifY*velDifY;
  double c = posDifX*posDifX + posDifY*posDifY - 100;
  double possibleSol = b*b - a*c;     // b^2-4ac
  // one.stop();
  // two.stop();
  if ((a == 0) || possibleSol < 0) {     // check for a = 0 or b^2-4ac < 0
    return -1;
  } else {
    double sol1, sol2;
    sol1 = (-b + sqrt(possibleSol))/(a);
    sol2 = (-b - sqrt(possibleSol))/(a);
    if (sol1 <= sol2 && sol1 >= 0) {
      return sol1;
    } else if (sol2 <= sol1 && sol2 >= 0) {
      return sol2;
    } else {
      return -1;
    }
  }
}

int main() {
  vector< Car > collection;     // All info of cars
  vector< collisionOfCars > collision;      // all possible collision
  vector < collisionOfCars > collisionResult;     // result of collision
  string ID;
  double x, y, xVel, yVel;
  while (cin >> ID >> x >> y >> xVel >> yVel) {
    collection.push_back(Car(ID, x, y, xVel, yVel, false));
  }
  // Timer one("Read");
  // one.start();
  for (int i = 0; i < collection.size(); i++) {
    for (int j = i+1; j < collection.size(); j++) {
      // one.start();
      double result = willCollide(&collection[i], &collection[j]);
      // one.stop();
      if (result != -1) {
        collisionOfCars in{&collection[i], &collection[j], result};
        collision.push_back(in);
      }
    }
  }
  // one.stop();
  sort(collision.begin(), collision.end(), tupleCompare);
  for (int k = 0; k < collision.size(); k++) {
    bool a = collision[k].firstCar->collided;
    bool b = collision[k].secondCar->collided;
    if (!a && !b) {
      collision[k].firstCar->collided = true;
      collision[k].secondCar->collided = true;
      collisionResult.push_back(collision[k]);
    }
  }
  cout << "there are " << collection.size() << " vehicles" << "\n";
  cout << "collision report" << "\n";
  if (collisionResult.size() == 0) {
    cout << "none" << "\n";
  } else {
    for (int i = 0; i < collisionResult.size(); i++) {
        cout << "at " << collisionResult[i].time << " ";
        cout << collisionResult[i].firstCar->ID;
        cout << " collided with " << collisionResult[i].secondCar->ID << "\n";
    }
}
  cout << "the remaining vehicles are" << "\n";
  if (2*collisionResult.size() == collection.size()) {
    cout << "none" << "\n";
  } else {
    for (int j = 0; j < collection.size(); j++) {
      if (!collection[j].collided) {
        ID = collection[j].ID;
        x = collection[j].x;
        y = collection[j].y;
        xVel = collection[j].xVel;
        yVel = collection[j].yVel;
        cout << ID << " " << x;
        cout << " " << y << " " << xVel;
        cout << " " << yVel << "\n";
      }
  }
}
}
