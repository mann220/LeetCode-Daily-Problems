class Solution {
public:
    #define ll long long
    struct Node{
        ll val=-1;
        vector<int> ind;
    };
    vector<vector<Node>> dp;
    int search(int i,vector<vector<int>> &intervals){
        int lo=i+1;
        int hi=intervals.size()-1;
        int ans=intervals.size();
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(intervals[mid][0]>intervals[i][1]){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
    Node f(int i,int cnt,vector<vector<int>> &intervals){
        if(i==intervals.size() || cnt==0) return Node();
        if(dp[i][cnt].val!=-1) return dp[i][cnt];
        Node nttake=f(i+1,cnt,intervals);
        int nextIndex=search(i,intervals);
        Node temp=f(nextIndex,cnt-1,intervals);
        Node take;
        take.val=1LL*intervals[i][2]+temp.val;
        take.ind=temp.ind;
        take.ind.push_back(intervals[i][3]);
        sort(take.ind.begin(),take.ind.end());
        Node result;
        if(nttake.val>take.val) result=nttake;
        else if(nttake.val<take.val) result=take;
        else result=(take.ind<nttake.ind) ? take:nttake;
        return dp[i][cnt]=result;
    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n=intervals.size();
        for(int i=0;i<n;i++) intervals[i].push_back(i);
        sort(intervals.begin(),intervals.end());
        dp=vector<vector<Node>> (n,vector<Node> (5));
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=4;j++){

            }
        }
        return f(0,4,intervals).ind;
    }
};