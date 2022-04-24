class Solution {
public:
    const int MAX_TRIPS = 1001;
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> seats(MAX_TRIPS, 0);
        for (auto &trip : trips) {
            seats[trip[1]] += trip[0];
            seats[trip[2]] -= trip[0];
        }
        int left_seat = capacity;
        for (auto seat : seats) {
            left_seat -= seat;
            if (left_seat < 0) return false;
        }
        
        return true;
    }
};