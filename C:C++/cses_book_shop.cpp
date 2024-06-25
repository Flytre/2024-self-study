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
  int n, x;
  cin >> n >> x;
  vi prices(n, 0);
  for(int i = 0; i < n; i++)
    cin >> prices[i];
  vi pages(n, 0);
  for(int i = 0; i < n; i++)
    cin >> pages[i];
  vv<int> max_pages(n+1, vi(x+2, 0)); // max_pages[max index][min budget left]
  for(int i = 1; i <= n; i++) {
    for(int budget_left = x; budget_left >= 0; budget_left--) {
      if(x - budget_left >= prices[i-1]) {
	max_pages[i][budget_left] = max_pages[i - 1][budget_left + prices[i-1]] + pages[i-1 ];
      }
      max_pages[i][budget_left] = max({max_pages[i][budget_left], max_pages[i][budget_left+1], max_pages[i-1][budget_left]});
    }
  }
  cout <<  max_pages[n][0] << endl;
  return 0;
}
