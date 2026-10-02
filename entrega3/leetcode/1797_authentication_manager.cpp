#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class AuthenticationManager {
private:
    int ttl;
    unordered_map<string, int> tokens;

public:
    AuthenticationManager(int timeToLive) : ttl(timeToLive) {}
    
    void generate(string tokenId, int currentTime) {
        tokens[tokenId] = currentTime + ttl;
    }
    
    void renew(string tokenId, int currentTime) {
        if (tokens.count(tokenId) && tokens[tokenId] > currentTime) {
            tokens[tokenId] = currentTime + ttl;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for (const auto& pair : tokens) {
            if (pair.second > currentTime) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    AuthenticationManager am(5);
    am.generate("token1", 1);
    am.renew("token1", 2);
    cout << "Tokens no expirados a tiempo 6: " << am.countUnexpiredTokens(6) << endl;
    return 0;
}
