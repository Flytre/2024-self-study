//
// Created by Aaron Rahman on 4/7/24.
//
#include <iostream>
#include <set>
#include <map>

#define _CRT_SECURE_NO_DEPRECATE


using namespace std;
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef set<int> si;
typedef map<string, int> msi;

template<typename T> // declaration only for TD;
class TD; // TD == "Type Displayer"

template<typename T> // template function to
void f(const T& param); // be called
class Widget {

};
std::vector<Widget> createVec();
int main() {
    const auto vw = createVec(); // init vw w/factory return
    if (!vw.empty()) {
        f(&vw[0]); // call f
    }
}