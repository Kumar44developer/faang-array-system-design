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
static vector<vector<pair<int,int>>> encode(const vector<vector<int>>& frame) {
        vector<vector<pair<int,int>>> enc; enc.reserve(frame.size());
        for (const auto& row : frame) enc.push_back(encodeRow(row));
        return enc;
    }
    static vector<vector<int>> decode(const vector<vector<pair<int,int>>>& enc, int cols) {
        vector<vector<int>> frame; frame.reserve(enc.size());
        for (const auto& row : enc) {
            vector<int> out;
            for (auto [val, cnt] : row) out.insert(out.end(), cnt, val);
            if ((int)out.size() != cols) out.resize(cols, 0); 
            frame.push_back(move(out));
        }
        return frame;
    }
};
int main() {
    vector<vector<int>> frame = {{1,1,1,2,2},{3,3,4,4,4}};
    auto enc = RLEFrame::encode(frame);
    auto dec = RLEFrame::decode(enc, 5);
    for (auto &row : dec) {
        for (int v : row) cout << v << " ";
        cout << "\n";
    }
    return 0;
}
