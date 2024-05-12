#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <queue>

#define _CRT_SECURE_NO_DEPRECATE


using namespace std;
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef set<int> si;
typedef map<string, int> msi;

class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        vector<int> dp(s.size(), -1);
        dp[0] = 1;
        int ret = min_subst(dp, s, s.size() - 1);
        return ret;
    }

    int min_subst(vector<int> &dp, const string &s, int idx) {
        if (dp[idx] != -1)
            return dp[idx];
        int m = idx + 1;

        vector<int> char_ct(26, 0);
        for (int i = 0; i <= idx; i++)
            char_ct[s[i] - 'a']++;

        if (balanced(char_ct)) {
            return dp[idx] = 1;
        }
        char_ct[s[0] - 'a']--;
        for (int b = 0; b < idx; b++) {
            if (balanced(char_ct)) {
                m = min(m, min_subst(dp, s, b) + 1);
            }
            char_ct[s[b + 1] - 'a']--;
        }
        dp[idx] = m;
        return m;
    }

    bool balanced(vector<int>& char_ct) {
        int target = -1;
        for (int i: char_ct) {
            if (i == 0)
                continue;
            if (target == -1)
                target = i;
            else if (i != target)
                return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    cout << sol.minimumSubstringsInPartition(
            "bccbaaeiuoyryuieworyoiutreruewopruoiewriuopewqruopiewqopiurewpoiurqweopiurqwoepiuroipuwqeroipuweqrouipweqropiuwqroiupwerouipweroiupeqwroiupqweiuorqewiuorpqwiuorwuiorqweipuorqweuoirpweuoiprwequioprwoeuipqroweuipruiopqwruiopwqeriuopewqiuporweqiuoprewqiouprqpiwouriowpequrpiouwquioprewruiyoewruiyoewryiuoewyurioewuiroyweuiyorewiyuorweyiuorweiuyoriuyoweruiyoweriuyoewruyoiweqruiyoweqriyuoweqiuoyrewiuyorweiuyorewiuyorewiuyorewuiyoruewiyoruioyewriuoyweruiyoweriuyoweriuyoweriuyoweiuyroewiuyorweiuyorweuiyorweuiyorewoiuyrweiuoyrweoiuyqriuoyewriyuowqeroiuywqruoyiewqyurioqweruyoicabc");
}