#include <string>
#include <unordered_map>

class ExamTracker {
private:
    std::unordered_map<int, int> studentScores;

public:
    ExamTracker() {}
    
    void recordScore(int studentId, int score) {
        studentScores[studentId] = score;
    }
    
    int getScore(int studentId) {
        auto it = studentScores.find(studentId);
        if (it != studentScores.end()) {
            return it->second;
        }
        return -1;
    }
    
    void removeScore(int studentId) {
        studentScores.erase(studentId);
    }
};
