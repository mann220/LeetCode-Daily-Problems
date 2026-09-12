class Solution {
public:
    struct Node {
        long long val = -1;
        vector<int> ind; // Changed to vector<int> to match the required return type
    };

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        // Add original indices
        for(int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }
        
        // Sort by start times
        sort(intervals.begin(), intervals.end());
        
        // Precalculate the next valid non-overlapping interval for every interval
        vector<int> next_idx(n, n);
        for(int i = 0; i < n; i++) {
            int lo = i + 1;
            int hi = n - 1;
            int ans = n;
            while(lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                
                if(intervals[mid][0] > intervals[i][1]) {
                    ans = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            next_idx[i] = ans;
        }
        
        // DP Table: initialized to size (n+1) x 5
        vector<vector<Node>> dp(n + 1, vector<Node>(5));
        
        // Base cases (val = 0 for empty states)
        for(int i = 0; i <= n; i++) {
            for(int cnt = 0; cnt <= 4; cnt++) {
                dp[i][cnt].val = 0;
            }
        }
        
        // Fill DP table backwards
        for(int i = n - 1; i >= 0; i--) {
            for(int cnt = 1; cnt <= 4; cnt++) {
                
                // Option 1: Do not take the current interval
                Node nttake = dp[i+1][cnt];
                
                // Option 2: Take the current interval
                int nxt = next_idx[i];
                Node temp = dp[nxt][cnt-1];
                
                Node take;
                take.val = (long long)intervals[i][2] + temp.val;
                take.ind = temp.ind;
                take.ind.push_back(intervals[i][3]);
                sort(take.ind.begin(), take.ind.end());
                
                // Decide which option is better
                if(nttake.val > take.val) {
                    dp[i][cnt] = nttake;
                } else if(nttake.val < take.val) {
                    dp[i][cnt] = take;
                } else {
                    // Tie-breaker: Lexicographically smaller indices
                    dp[i][cnt] = (take.ind < nttake.ind) ? take : nttake;
                }
            }
        }
        
        return dp[0][4].ind;
    }
};