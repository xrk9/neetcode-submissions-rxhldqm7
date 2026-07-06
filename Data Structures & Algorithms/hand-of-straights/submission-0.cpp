#include <vector>
#include <map>

class Solution {
public:
    bool isNStraightHand(std::vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;
        
        std::map<int, int> countMap;
        for (int card : hand) {
            countMap[card]++;
        }
        
        for (auto const& [card, count] : countMap) {
            if (count > 0) {
                for (int i = 1; i < groupSize; i++) {
                    if (countMap[card + i] < count) {
                        return false;
                    }
                    countMap[card + i] -= count;
                }
            }
        }
        
        return true;
    }
};