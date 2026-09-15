#include <bits/stdc++.h>
using namespace std;

struct Leaderboard {
    vector<pair<int,int>> players;

    void addScore(int playerId, int score) {
        for (auto& p : players) {
            if (p.first == playerId) { p.second += score; return; }
        }
        players.push_back({playerId, score});
    }

    long long top(int K) const {
        vector<int> scores;
        scores.reserve(players.size());
        for (const auto& p : players) scores.push_back(p.second);
        sort(scores.begin(), scores.end(), greater<int>());
        long long sum = 0;
        int limit = min((int)scores.size(), K);
        for (int i = 0; i < limit; ++i) sum += scores[i];
        return sum;
    }

    void reset(int playerId) {
        for (size_t i = 0; i < players.size(); ++i) {
            if (players[i].first == playerId) {
                players.erase(players.begin() + i);
                return;
            }
        }
    }
};

int main() {
    Leaderboard lb;
    lb.addScore(1, 73);
    lb.addScore(2, 56);
    lb.addScore(3, 39);
    lb.addScore(4, 51);
    lb.addScore(5, 4);
    cout << lb.top(1) << "\n";
    lb.reset(1);
    lb.reset(2);
    lb.addScore(2, 51);
    cout << lb.top(3) << "\n";
    return 0;
}
