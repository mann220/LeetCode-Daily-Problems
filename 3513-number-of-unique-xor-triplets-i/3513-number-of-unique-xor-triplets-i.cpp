class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        if(n<=2) return n;
        int a=1;
        while(a<=maxi) a=a*2;
        return a;
    }
};