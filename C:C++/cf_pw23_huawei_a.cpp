#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <cmath>
#include <cstring>

#define _CRT_SECURE_NO_DEPRECATE


using namespace std;


const double max_fp16 = (2 - pow(2, -10)) * pow(2, 16);
const double max_fp32 = std::numeric_limits<float>::max();

struct node {
    double sum;
    string rep;
};

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

char stype(double a, double b) {
    double sum = a + b;
    float half_sum = (float) a + (float) b;
    char ret = 'd';
    if (abs(sum) <= max_fp32 && (sum == half_sum)) {
        if (abs(sum) <= max_fp16 && (sum == convertToCustomFp16(sum))) {
            ret = 's';
        } else {
            ret = 'h';
        }
    }
    return ret;
}

int main() {

    int n;
    cin >> n;

    auto ls = list<node>();
    double d;
    for (int i = 0; i < n; i++) {
        cin >> d;
        ls.push_back({d, to_string(i + 1)});
    }

    while (ls.size() > 1) {
        for (auto it = ls.begin(); it != ls.end();) {
            auto nextIt = std::next(it);
            if (nextIt != ls.end()) {
                char type = stype(it->sum, nextIt->sum);
                it->sum = it->sum + nextIt->sum;
                std::ostringstream oss;
                oss << "{" << type << ":" << it->rep << "," << nextIt->rep << "}";
                it->rep = oss.str();
                it = ls.erase(nextIt);
            }
            ++it;
        }

    }

    cout << ls.begin()->rep;

}