#include "2_4.h"

#pragma GCC optimize("O3")

using namespace std;

int main() {
    // 1 - 2
    lab2::func(2);
    lab2::func(4);
    lab2::func(6);
    #define sm(a, b) a + b
    cout << sm(2,4) << endl;
}