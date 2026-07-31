class Solution {
public:
    // this is done in O(nlogn) for O(n) we have to do it with deque
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        deque<int> maxh,minh;
        int i=0;
        int ln=0;
        for(int j=0;j<n;j++){
            while(!maxh.empty() && nums[maxh.back()]<nums[j]) maxh.pop_back();
            maxh.push_back(j);
            while(!minh.empty() && nums[minh.back()]>nums[j]) minh.pop_back();
            minh.push_back(j);
            while(nums[maxh.front()]-nums[minh.front()]>limit){
                if(maxh.front()==i) maxh.pop_front();
                if(minh.front()==i) minh.pop_front();
                i++;
            }
            ln=max(ln,j-i+1);
        }
        return ln;
    }
};