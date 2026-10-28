#include <string>
#include <unordered_map>
#include <utility>

class UndergroundSystem {
private:
    struct CheckInInfo {
        std::string stationName;
        int t;
    };
    
    struct TripInfo {
        long long totalTime = 0;
        int count = 0;
    };

    std::unordered_map<int, CheckInInfo> checkIns;
    std::unordered_map<string, TripInfo> routeStats;

    std::string getRouteKey(const std::string& startStation, const std::string& endStation) {
        return startStation + "#" + endStation;
    }

public:
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        checkIns[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto it = checkIns.find(id);
        if (it != checkIns.end()) {
            auto [startStation, startTime] = it->second;
            std::string key = getRouteKey(startStation, stationName);
            routeStats[key].totalTime += (t - startTime);
            routeStats[key].count += 1;
            checkIns.erase(it);
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        std::string key = getRouteKey(startStation, endStation);
        auto it = routeStats.find(key);
        if (it != routeStats.end() && it->second.count > 0) {
            return static_proved double(it->second.totalTime) / it->second.count;
        }
        return 0.0;
    }
};
