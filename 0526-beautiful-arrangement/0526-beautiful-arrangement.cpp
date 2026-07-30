class Solution {
public:
    vector<int> used;
    int f(int i,int n){
        if(i>n) return 1;
        int ans=0;
        for(int j=1;j<=n;j++){
            if(used[j]) continue;
            if(i%j==0 || j%i==0){
                used[j]=true;
                ans+=f(i+1,n);
                used[j]=false;
            }
        }
        return ans;
    }
    int countArrangement(int n) {
        used.resize(n+1,false);
        return f(1,n);
    }
};