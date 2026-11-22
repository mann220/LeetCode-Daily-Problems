class Solution {
public:
    bool checkString(string s) {
        int n=s.size();
        bool flg=false;
        for(int i=0;i<n;i++){
            if(s[i]=='b' && !flg) flg=true;
            else if(s[i]=='a' && flg){
                return false;
            }
        }
        return true;
    }
};