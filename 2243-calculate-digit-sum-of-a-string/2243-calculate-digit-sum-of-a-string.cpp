class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k){
            string p="";
            for(int i=0;i<s.size();i+=k){
                int val=0;
                for(int j=i;j<min((int)s.size(),i+k);j++){
                    val+=(s[j]-'0');
                }
                p+=to_string(val);
            }
            s=p;
        }
        return s;
    }
};