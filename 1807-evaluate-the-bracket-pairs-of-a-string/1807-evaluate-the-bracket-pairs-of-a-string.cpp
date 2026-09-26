class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mpp;
        for(int i=0;i<knowledge.size();i++) mpp[knowledge[i][0]]=knowledge[i][1];
        int i=0;
        int n=s.size();
        bool flg=false;
        string ans="";
        while(i<n){
            if(s[i]=='('){

                int j=i+1;
                string p="";
                while(s[j]!=')'){
                    p+=s[j];
                    j++;
                }
                if(mpp.find(p)!=mpp.end()) ans+=mpp[p];
                else ans+="?";
                i=j+1;
                flg=true;
            }
            if(flg){
                flg=false;
                continue; 
            }
            ans+=s[i];
            i++;
        }
        return ans;
    }
};