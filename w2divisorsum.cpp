// Copyright 2020 ZHIYUAN RUAN zruan@bu.edu

#include <iostream>

int divisorsum(int n) {
    int i, factor, sum = 0;
    int count = 0;

    for (i = 1; i <= n; i++) {
        if (!(n % i) && i != n) {
            count++;
            factor1 = i;
            sum = sum + factor;
            if (count == 1) {
            std::cout << n << ":" << i;
        } else {
            std::cout << " + " << i;
        }
        }
    }
    return sum;
}

int main() {
    for (int i = 2; i <= 888; i++) {
        int sum = divisorsum(i);
        std::cout << " = " << sum << std::endl;
    }
}
