         //Arranging coins

class Solution {
public:
    int arrangeCoins(int n) {
        long left = 0, right = n;
        
        while (left <= right) {
            long mid = left + (right - left) / 2;
            long total_coins = mid * (mid + 1) / 2; // Coins needed for 'mid' rows
            
            if (total_coins == n) {
                return static_cast<int>(mid); // Found exact number of rows
            } else if (total_coins < n) {
                left = mid + 1; // Increase the number of rows
            } else {
                right = mid - 1; // Decrease the number of rows
            }
        }
        
        // 'right' will be the maximum number of complete rows
        return static_cast<int>(right);
    }
};

