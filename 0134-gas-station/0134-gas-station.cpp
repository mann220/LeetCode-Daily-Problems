class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int tg=accumulate(gas.begin(),gas.end(),0);
        int tc=accumulate(cost.begin(),cost.end(),0);
        vector<int> diff(n);
        if(tg<tc) return -1;
        int ind=-1;
        int maxi=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++){
            diff[i]=gas[i]-cost[i];
            sum+=diff[i];
            if(sum<0){
                sum=0;
                ind=-1;
            }
            else if(ind==-1 && sum>=0) ind=i;
        }
        return ind;
    }
};