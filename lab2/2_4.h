#include <iostream>

namespace lab2 {

void func(int a) {
    static int VAL = 0;
    std::cout << a + VAL << std::endl;
    VAL = a;

}
}