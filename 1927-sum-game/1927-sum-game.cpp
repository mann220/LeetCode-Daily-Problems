class Solution {
public:
    // acc to my observation there are two conditon possible if alice want to maximise the first half and minimise the second half or it maximise the second half and minise the frist half
    bool sumGame(string s) {
        int n=s.size();
        int f1sum=0,f2sum=0;
        int l1sum=0,l2sum=0;
        bool flag=true;
        for(int i=0;i<n;i++){
            if(flag){
                if(i<n/2 && s[i]=='?'){
                    f1sum+=0;
                    f2sum+=9;
                    flag=false;
                    continue;
                }
                else if(i>=n/2 && s[i]=='?'){
                    l1sum+=9;
                    l2sum+=0;
                    flag=false;
                    continue;
                }
            }
            else{
                if(i<n/2 && s[i]=='?'){
                    f1sum+=9;
                    f2sum+=0;
                    flag=true;
                    continue;
                }
                if(i>=n/2 && s[i]=='?'){
                    l1sum+=0;
                    l2sum+=9;
                    flag=true;
                    continue;
                }
            }
            if(i<n/2){
                f1sum+=(s[i]-'0');
                f2sum+=(s[i]-'0');
            }
            else{
                l1sum+=(s[i]-'0');
                l2sum+=(s[i]-'0');
            }
        }
        return (f1sum<l1sum || f2sum>l2sum);
    }
};