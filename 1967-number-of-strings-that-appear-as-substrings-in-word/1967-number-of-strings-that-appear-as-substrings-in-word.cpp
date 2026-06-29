class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans=0;
        for(int k=0;k<patterns.size();k++){
            for(int i=0;i<word.size();i++){
                string s;
                bool flag=false;
                for(int j=i;j<word.size();j++){
                    s.push_back(word[j]);
                    if(s==patterns[k]){
                        ans++;
                        flag=true;
                        break;
                    }
                }
                if(flag) break;
            }
        }
        return ans;
    }
};