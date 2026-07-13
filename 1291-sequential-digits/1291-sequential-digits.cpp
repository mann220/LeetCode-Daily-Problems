class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string s1=to_string(low);
        string s2=to_string(high);
        int n1=s1.size();
        int n2=s2.size();
        for(int i=n1;i<=n2;i++){
            char c='1';
            int num=low;
            while(c<='9' && num<=high){
                string s="";
                char c1=c;
                int j=0;
                while(j<i){
                    if(c1>'9'){
                        s="";
                        break;
                    }
                    s.push_back(c1);
                    c1++;
                    j++;
                }
                if(s.empty()){
                    c++;
                    continue;
                }
                num=stoi(s);
                if(num>=low && num<=high) ans.push_back(num);
                c++;
            }
        }
        return ans;
    }
};