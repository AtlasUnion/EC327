#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using std::string;
using std::cout;
using std::cin;
using std::vector;

typedef double numbers;

struct collision {
  numbers time;
  int first, second;
  collision(numbers t, int one, int two) : time(t), first(one), second(two) { }

  bool operator<(const collision& other) const {
    return time < other.time;
  }
};

struct vehicle {
  string id;
  numbers rx, ry, vx, vy;
  bool wallCollisionVertical;
  bool wallCollisionHorizontal;
  bool carCollision;
};

numbers collide_timer(const vehicle& one, const vehicle& two) {
  numbers a = two.rx - one.rx;
  numbers b = two.ry - one.ry;
  numbers c = two.vx - one.vx;
  numbers d = two.vy - one.vy;
  numbers A = c * c + d * d;
  numbers B = 2 * (a * c + b * d);

  numbers C = (a * a + b * b - 100);


  numbers rootarg = B * B - 4 * A * C;

  if (rootarg < 0) return 0;

  numbers root = sqrt(rootarg);

  numbers t1 = (-B  - root) / (2 * A);
  numbers t2 = (-B + root) / (2 * A);

  if (t1 > 0)
    return t1;
  if (t2 > 0)
    return t2;

  return 0;
}

void report(vector<vehicle> &cars) {
  for (int i = 0; i < cars.size(); i++) {
    cout << cars[i].id << " " << cars[i].rx << cars[i].ry << "\n";
  }
}


int main() {
  vector<vehicle> cars;
  vector<collision> hits, real_hits;

  cout.precision(8);

  vehicle z;
  numbers collide_t;
  int i, j;
  double time_interval, time_length, timeCount;
  double lowerX, lowerY, upperX, upperY;

  cin >> time_interval >> time_length;
  cin >> lowerX >> lowerY >> upperX >> upperY;
  timeCount = 0.0;
  while (std::cin >> z.id >> z.rx >> z.ry >> z.vx >> z.vy)
    cars.push_back(z);

  while (timeCount <= time_length) {

    if (timeCount % time_interval == 0) {
      cout << "At " << timeCount << "\n";
      report(cars);
    }
  }
}
