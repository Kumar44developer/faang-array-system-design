#include <bits/stdc++.h>
using namespace std;
struct RLEFrame {
    static vector<pair<int,int>> encodeRow(const vector<int>& row) { 
        vector<pair<int,int>> out; if (row.empty()) return out;
        int cur = row[0], cnt = 1;
        for (size_t i = 1; i < row.size(); ++i) {
            if (row[i] == cur) ++cnt;
            else { out.push_back({cur, cnt}); cur = row[i]; cnt = 1; }
        }
        out.push_back({cur, cnt});
        return out;
    }

