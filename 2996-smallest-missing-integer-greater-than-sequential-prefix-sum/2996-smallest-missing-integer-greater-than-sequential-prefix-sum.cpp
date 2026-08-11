class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        int i=1;
        int sum=nums[0];
        while(i<n && nums[i]==nums[i-1]+1){
            sum+=nums[i];
            i++;
        }
        bool flag=false;
        while(true){
            for(int i=0;i<n;i++){
                if(nums[i]==sum){
                    sum++;
                    flag=true;
                    break;
                }
            }
            if(!flag) break;
            flag=false;
        }
        return sum;
    }
};