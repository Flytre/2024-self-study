//
// Created by Aaron Rahman on 3/31/24.
//
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <initializer_list>
#include <numeric>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        vector<string> words;
        string word;

        while (iss >> word)
            words.push_back(word);

        reverse(words.begin(), words.end());

        string result;

        if (!words.empty()) {
            result = words[0];
            for (size_t i = 1; i < words.size(); ++i) {
                result += " " + words[i];
            }
        }

        return result;
    }
};