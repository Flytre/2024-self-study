#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

double convertToCustomFp16(double value) {
    uint64_t bits;
    std::memcpy(&bits, &value, sizeof(bits));

    uint64_t sign = bits & 0x8000000000000000;
    uint64_t exponent = bits & 0x7FF0000000000000;
    uint64_t mantissa = bits & 0x000FFFFFFFFFFFFF;
    uint64_t truncatedMantissa = mantissa & 0x000FFC0000000000;
    uint64_t newBits = sign | exponent | (truncatedMantissa);
    double result;
    std::memcpy(&result, &newBits, sizeof(result));
    return result;
}

int main() {
    cout << convertToCustomFp16(33.4267) << endl;
}