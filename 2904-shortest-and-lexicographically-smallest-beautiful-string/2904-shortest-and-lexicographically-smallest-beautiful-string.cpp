class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        int len=INT_MAX;
        string ans="";
        for(int i=0;i<n;i++){
            int cnt=0;
            string temp="";
            for(int j=i;j<n;j++){
                temp+=s[j];
                if(s[j]=='1') cnt++;
                if(cnt==k){
                    if(len>(j-i+1) || (len==(j-i+1) && temp<ans)){
                        len=j-i+1;
                        ans=temp;
                    }
                    break;
                }
            }
        }
        return ans;
    }
};