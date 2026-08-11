class Solution {
public:
    int n;
    int f(int curr,int clip){
        if(curr==n) return 0;
        if(curr>n) return 1e9;
        // option 1 is copy all
        int copy=1e9;
        if(curr!=clip) copy=1+f(curr,curr);
        // option 2 is paste them
        int paste=1e9;
        if(clip>0){
            paste=1+f(curr+clip,clip);
        }
        return min(copy,paste);
    }
    int minSteps(int p) {
        n=p;
        if(n==1) return 0;
        return f(1,0);
    }
};