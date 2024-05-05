#include <iostream>

using namespace std;

template<int n>
struct fact {
    static constexpr int f = n * fact<n - 1>::f;
};

template<>
struct fact<0> {
    static constexpr int f = 1;
};

int main() {
    cout << fact<4>::f << endl;
}