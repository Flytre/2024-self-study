#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <stack>
#include <fstream>
#include <string>

using namespace std;

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using ii = std::pair<int, int>;
using si = std::set<int>;
using msi = std::map<std::string, int>;

template<typename T>
using vv = vector<vector<T>>;

template<typename T>
using vvv = vector<vector<vector<T>>>;
int main() {
  int n;
  cin >> n;
  vv<long long> grid(n + 1, vll(n+1, 0));
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++) {
      char ch;
      cin >> ch;
      grid[i][j] = (ch == '*') ? 0 : -1;
    }
  if(grid[1][1] == -1) grid[1][1] = 1;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++) {
      if(grid[i][j] == -1)
	grid[i][j] = (grid[i-1][j] + grid[i][j-1]) % 1'000'000'007;
    }
  cout << grid[n][n] << endl;
  
};
