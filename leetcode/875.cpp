// v1
// class Solution {
// public:
//     // return eating time
//     long eat_time(long num, vector<int> piles) {
//         if (num == 0) return 1e9+1; // impossible
        
//         long finish_time = 0;
//         for (int loc = 0; loc < piles.size(); loc++) {
//             finish_time += (piles[loc] % num) ? piles[loc] / num + 1 : piles[loc] / num;
//         }
//         return finish_time;
//     }
//     int minEatingSpeed(vector<int>& piles, int h) {
//         long numl = 1, num = 1, numr = 1e9;
//         long time = -1, timel = -1, timer = -1;
        
//         numr = 1;
//         while(eat_time(numr, piles) > h)
//             numr *= 10;
        
//         while (numl <= numr) {
//             num = numl + (numr-numl)/2;
//             time = eat_time(num, piles);
//             timel = eat_time(num-1, piles); // eat less
//             // timer = eat_time(num+1, piles); // eat more
            
//             if (time <= h && timel > h) {
//                 break;
//             } else if (time <= h && timel <= h) {
//                 numr = num-1;
//             } else if (time > h) {
//                 numl = num+1;
//             }
//         }
//         return num;
//     }
// };

// v2
class Solution {
public:
    // return eating time
    long eat_time(long num, vector<int> piles) {
        if (num == 0) return 1e9+1; // impossible
        
        long finish_time = 0;
        for (int loc = 0; loc < piles.size(); loc++) {
            finish_time += (piles[loc] % num) ? piles[loc] / num + 1 : piles[loc] / num;
        }
        return finish_time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long numl = 1, num = 1, numr = 1e9;
        long time = -1, timel = -1, timer = -1;
        
        numr = 1;
        while(eat_time(numr, piles) > h)
            numr *= 10;
        
        while (numl <= numr) {
            num = numl + (numr-numl)/2;
            time = eat_time(num, piles);
            
            if (time <= h) {
                numr = num-1;
            } else if (time > h) {
                numl = num+1;
            }
        }
        return numl;
    }
};