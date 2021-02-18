#include <iostream>
#include <vector>
#include <string>

#include "MyNumber.h"

using namespace std;

int main(int argc, char **argv) {
    std::cerr << "Before a(10)" << std::endl;
    MyNumber < double > a(10);
    std::cerr << "Before b" << std::endl;
    MyNumber < double > b;
    std::cerr << "Before c = b" << std::endl;
    MyNumber < double > c = b;
    std::cerr << "Before d = std::move(c)" << std::endl;
    MyNumber < double > d = std::move(c);
    std::cerr << "Before e(a)" << std::endl;
    MyNumber < double > e(a);
    std::cerr << "Before e = b" << std::endl;
    e = b;
    std::cerr << "Before e = std::move(c)" << std::endl;
    e = std::move(c);

    return 0;
}
