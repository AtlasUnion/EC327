// Copyright 2020 ZHIYUAN RUAN zruan@bu.edu

#include <iostream>
using std::cout;
using std::endl;

int numSquareSum(int n) {
    int sum = 0;
    while(n) {
      sum += (n % 10) * (n % 10);
      n /= 10;
    }
}

bool isHappy(int n) {
  int slow, fast;

  //  initialize slow and fast by n
  slow = fast = n;
  do
  {
      slow = numSquareSum(slow);
      fast = numSquareSum(numSquareSum(fast));
  }
  while (slow != fast);

  //  if both number meet at 1, then return true
  return (slow == 1);
}

int main() {
    int count = 0;
    bool happyNum = false;
    int testNum = 1;
    while(count <= 888) {
        if (isHappy(testNum)){
            cout<< testNum << endl;
            count++;
        }
        testNum++;
    }
}
