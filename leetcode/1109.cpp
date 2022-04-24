class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n+1, 0); // diff[i] = init[i] - init[i-1];
        int start_idx, end_idx, booking;
        for (auto iter = bookings.begin(); iter != bookings.end(); ++iter) {
            start_idx = (*iter)[0]-1; end_idx = (*iter)[1]-1; booking = (*iter)[2];
            diff[start_idx] += booking;
            diff[end_idx+1] -= booking;
        }

        for (auto iter = diff.begin()+1; iter != diff.end(); ++iter) {
            *iter += *(iter-1);
        }
        diff.pop_back(); // delete last 0
        return diff;
    }
};