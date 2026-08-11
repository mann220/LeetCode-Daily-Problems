class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int tg=0;
        int tc=0;
        vector<int> diff(n);
        int ind=-1;
        int sum=0;
        for(int i=0;i<n;i++){
            tg+=gas[i];
            tc+=cost[i];
            diff[i]=gas[i]-cost[i];
            sum+=diff[i];
            if(sum<0){
                sum=0;
                ind=-1;
            }
            else if(ind==-1 && sum>=0) ind=i;
        }
        return (tc>tg)?-1:ind;
    }
};