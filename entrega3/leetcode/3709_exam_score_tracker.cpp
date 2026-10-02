#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class ExamTracker {
private:
    vector<pair<int, long long>> prefix_scores;

public:
    ExamTracker() {}
    
    void record(int time, int score) {
        long long current_total = 0;
        if (!prefix_scores.empty()) {
            current_total = prefix_scores.back().second;
        }
        prefix_scores.push_back({time, current_total + score});
    }
    
    long long totalScore(int startTime, int endTime) {
        if (prefix_scores.empty()) return 0;

        long long sum_end = 0;
        long long sum_start = 0;

        auto it_end = upper_bound(prefix_scores.begin(), prefix_scores.end(), endTime, 
            [](int val, const pair<int, long long>& p) {
                return val < p.first;
            });
        
        if (it_end != prefix_scores.begin()) {
            sum_end = prev(it_end)->second;
        } else {
            return 0; 
        }

        auto it_start = lower_bound(prefix_scores.begin(), prefix_scores.end(), startTime, 
            [](const pair<int, long long>& p, int val) {
                return p.first < val;
            });

        if (it_start != prefix_scores.begin()) {
            sum_start = prev(it_start)->second;
        }

        return sum_end - sum_start;
    }
};

int main() {
    ExamTracker tracker;
    tracker.record(1, 98);
    cout << "Puntaje en rango [1, 1]: " << tracker.totalScore(1, 1) << endl;
    tracker.record(5, 99);
    cout << "Puntaje en rango [1, 5]: " << tracker.totalScore(1, 5) << endl;
    return 0;
}
