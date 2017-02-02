// Copyright 2020 ZHIYUAN RUAN zruan@bu.edu

bool isHappy(int n) {

}

int main() {
    int count = 0;
    bool happyNum = false;
    int testNum = 1;
    while(count <= 888) {
        if (isHappy(testNum)){
            std::cout<< testNum << std::endl;
            count++;
        }
        testNum++;
    }
}
