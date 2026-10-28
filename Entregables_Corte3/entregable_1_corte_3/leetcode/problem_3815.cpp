#include <unordered_map>
#include <map>

class AuctionSystem {
private:
    std::unordered_map<int, std::unordered_map<int, int>> itemBids;
    std::unordered_map<int, std::map<int, std::map<int, bool>>> itemLeaderboard;

public:
    AuctionSystem() {}
    
    void addBid(int userId, int itemId, int bidAmount) {
        if (itemBids[itemId].find(userId) != itemBids[itemId].end()) {
            int oldAmount = itemBids[itemId][userId];
            itemLeaderboard[itemId][oldAmount].erase(userId);
            if (itemLeaderboard[itemId][oldAmount].empty()) {
                itemLeaderboard[itemId].erase(oldAmount);
            }
        }
        itemBids[itemId][userId] = bidAmount;
        itemLeaderboard[itemId][bidAmount][userId] = true;
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        int oldAmount = itemBids[itemId][userId];
        itemLeaderboard[itemId][oldAmount].erase(userId);
        if (itemLeaderboard[itemId][oldAmount].empty()) {
            itemLeaderboard[itemId].erase(oldAmount);
        }
        itemBids[itemId][userId] = newAmount;
        itemLeaderboard[itemId][newAmount][userId] = true;
    }
    
    void removeBid(int userId, int itemId) {
        int oldAmount = itemBids[itemId][userId];
        itemBids[itemId].erase(userId);
        itemLeaderboard[itemId][oldAmount].erase(userId);
        if (itemLeaderboard[itemId][oldAmount].empty()) {
            itemLeaderboard[itemId].erase(oldAmount);
        }
    }
    
    int getHighestBidder(int itemId) {
        if (itemLeaderboard.find(itemId) == itemLeaderboard.end() || itemLeaderboard[itemId].empty()) {
            return -1;
        }
        auto highestBidIt = itemLeaderboard[itemId].rbegin();
        const auto& usersWithHighestBid = highestBidIt->second;
        return usersWithHighestBid.rbegin()->first;
    }
};
