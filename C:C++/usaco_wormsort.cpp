#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <stack>
#include <fstream>

using namespace std;

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using ii = std::pair<int, int>;
using si = std::set<int>;
using msi = std::map<std::string, int>;

template<typename T>
using vv = vector<vector<T>>;


vi dsu;
vi dsu_size;

struct Wormhole {
    int a;
    int b;
    int sz;

    bool operator<(const Wormhole &other) const {
        return this->sz > other.sz;
    }
};

int lead(int idx) {
    if (dsu[idx] == idx)
        return idx;

    return dsu[idx] = lead(dsu[idx]);
}

void combine(int idx1, int idx2) {
    int l1 = lead(idx1);
    int l2 = lead(idx2);
    if (l1 != l2) {
        if (dsu_size[l1] < dsu_size[l2]) {
            dsu[l1] = l2;
            dsu_size[l2] += dsu_size[l1];
        } else {
            dsu[l2] = l1;
            dsu_size[l1] += dsu_size[l2];
        }
    }
}

int main() {

    ifstream fin("wormsort.in");
    ofstream fout("wormsort.out");

    int N, M;
    fin >> N >> M;
    vi cows(N, 0);
    vector<Wormhole> wormholes(M, Wormhole());
    for (int &cow: cows) {
        fin >> cow;
        cow--;
    }
    dsu = vi(N, 0);
    dsu_size = vi(N, 1);
    for (int i = 0; i < N; i++) dsu[i] = i;

    for (Wormhole &wh: wormholes) {
        fin >> wh.a >> wh.b >> wh.sz;
        wh.a--;
        wh.b--;
    }
    sort(wormholes.begin(), wormholes.end());

    int w = 0;
    for (int i = 0; i < N; i++) {
        while (lead(cows[i]) != lead(i)) {
            combine(wormholes[w].a, wormholes[w].b);
            w++;
        }
    }
    fout << (w == 0 ? -1 : wormholes[w-1].sz) << endl;

}