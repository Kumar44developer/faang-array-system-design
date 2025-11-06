#include <bits/stdc++.h>
using namespace std;
struct AutoComplete {
    vector<string> dict;
    explicit AutoComplete(vector<string> words) {
        dict = move(words);
        sort(dict.begin(), dict.end());
    }
