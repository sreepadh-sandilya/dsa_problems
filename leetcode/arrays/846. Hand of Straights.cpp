

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }

        map<int, int> mp;
        for (int card : hand) {
            mp[card]++;
        }

        while (!mp.empty()) {
            int first = mp.begin()->first;  // Get the smallest card value

            for (int i = 0; i < groupSize; ++i) {
                if (mp[first + i] == 0) {  // If the required card is not available
                    return false;
                }
                if (--mp[first + i] == 0) {  // Decrement the count and remove if it reaches zero
                    mp.erase(first + i);
                }
            }
        }

        return true;
    }
};
