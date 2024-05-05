#include <iostream>
#include <set>
#include <map>

#define _CRT_SECURE_NO_DEPRECATED


using namespace std;
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef set<int> si;
typedef map<string, int> msi;

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet) {
        vector<int> answer(quiet.size(), -1);
        vector<vector<int>> graph(quiet.size(), vector<int>{});
        for (int i = 0; i < richer.size(); i++) graph[richer[i][1]].push_back(richer[i][0]);

        for (int i = 0; i < quiet.size(); i++) loudest(graph, quiet, answer, i);


        return answer;
    }

    int loudest(vector<vector<int>>& graph, vector<int> &quiet, vector<int>& answer, int i) {
        if (answer[i] != -1) return answer[i];

        int quietest_value = quiet[i];
        int quietest_person = i;

        for(int j = 0; j < graph[i].size(); j++) {
            int child_quietest = loudest(graph, quiet, answer, graph[i][j]);
            quietest_value = min(quietest_value, quiet[child_quietest]);
            if(quietest_value == quiet[child_quietest])
                quietest_person = child_quietest;
        }

        return answer[i] = quietest_person;
    }
};

int main() {

    Solution sol;
    vector<vector<int>> richer = {{1,0},{2,1},{3,1},{3,7},{4,3},{5,3},{6,3}};
    vector<int> quiet = {3,2,5,4,6,1,7,0};
    vector<int> ans = sol.loudAndRich(richer, quiet);
}