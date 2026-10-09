class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        int i=0;
        int cnt=0,ans=0;
        while(i<n){
            if(s[i]=='('){
                cnt++;
                i++;
            }
            else {
                if(cnt>0){
                    if(i+1<n && s[i+1]==')'){
                        i+=2;
                        cnt--;
                    }
                    else{
                        ans++;
                        cnt--;
                        i++;
                    }
                }
                else{
                    if(i+1<n && s[i+1]==')'){
                        i+=2;
                        ans++;
                    }
                    else{
                        i++;
                        ans+=2;
                    }
                }
            }
        }
        if(cnt>0) ans+=(2*cnt);
        return ans;
    }
};