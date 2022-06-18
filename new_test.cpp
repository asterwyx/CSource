#include <iostream>

class A {
    int B[100];
    int C;
};

int main() {
    A test;
    std::cout << sizeof(A) << std::endl;
    std::cout << sizeof(test) << std::endl;
    system("pause");
    return 0; 
}
