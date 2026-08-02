class Solution {
public:
    #define ll long long
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n1=shifts.size();
        int n2=tasks.size();
        vector<ll> pre(n2,0);
        ll sum=0;
        for(int i=0;i<n2;i++){
            sum+=tasks[i];
            pre[i]=sum;
        }
        vector<int> ans(n1);
        int ub=-1;
        ll val=0;
        for(int i=0;i<n1;i++){
            if(ub==-1) val=shifts[i];
            else val+=shifts[i];
            ub=upper_bound(pre.begin(),pre.end(),val)-pre.begin();
            if(ub==n2) {
                val=0;
                ub=-1;
                ans[i]=0;
            } else {
                ans[i]=n2-ub;
            }
        }
        return ans;
    }
};