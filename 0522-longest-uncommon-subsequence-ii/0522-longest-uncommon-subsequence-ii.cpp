class Solution {
public:
    static bool comparator(string &s1,string &s2){
        return s1.size()>s2.size();
    }
    bool f(string x,string y){
        int i=0,j=0;
        while(i<x.size() && j<y.size()){
            if(x[i]==y[j]) i++;
            j++;
        }
        return i==x.size();
    }
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(),strs.end(),comparator);
        for(int i=0;i<strs.size(); i++){
            bool flag=true;
            for(int j=0;j<strs.size();j++){
                if(i==j) continue;
                if(f(strs[i],strs[j])){
                    flag=false;
                    break;
                }
            }
            if(flag) return strs[i].size();
        }
        return -1;
    }
};