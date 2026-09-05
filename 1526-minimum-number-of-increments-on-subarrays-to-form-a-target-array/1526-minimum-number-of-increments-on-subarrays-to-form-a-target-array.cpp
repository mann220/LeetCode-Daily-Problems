class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int curr=0;
        int prev=target[0];
        int ans=target[0];
        int n=target.size();
        for(int i=1;i<n;i++){
            curr=target[i];
            if(curr>prev) ans+=(curr-prev); 
            prev=curr;
        }
        return ans;
    }
};