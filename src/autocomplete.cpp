#include <bits/stdc++.h>
using namespace std;
struct AutoComplete {
    vector<string> dict;
    explicit AutoComplete(vector<string> words) {
        dict = move(words);
        sort(dict.begin(), dict.end());
    }
   vector<string> suggest(const string& prefix, int limit) const {
        string lo = prefix;
        string hi = prefix; hi.push_back(char(127)); // upper bound sentinel
        auto it1 = lower_bound(dict.begin(), dict.end(), lo);
        auto it2 = lower_bound(dict.begin(), dict.end(), hi);
        vector<string> out;
        for (; it1 != it2 && (int)out.size() < limit; ++it1) out.push_back(*it1);
        return out;
    }
};
int main() {
    AutoComplete ac({"apple","app","ape","bat","band","banner","ban"});
    auto res = ac.suggest("ban", 4);
    for (auto &s : res) cout << s << " ";
    cout << "\n";
    return 0;
}
