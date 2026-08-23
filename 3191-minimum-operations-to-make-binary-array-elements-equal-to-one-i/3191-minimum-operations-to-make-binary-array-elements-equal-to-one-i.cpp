class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int cnt=0;
        int k=3;
        for(int i=0;i<n;i++){
            if(nums[i]==1) continue;
            int j=i;
            if(i+k-1>=n) break;
            cnt++;
            while(j<=i+k-1 && i+k-1<n){
                nums[j]=!nums[j];
                j++;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]==0) return -1;
        }
        return cnt;
    }
};