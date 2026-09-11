class Solution {
public:
    set<int> st;
    void f(int i,string s,int mask,vector<int> &digits){
        if(i==3){
            int val=stoi(s);
            if(val>=100 && val%2==0) st.insert(val);
            return;
        }
        for(int j=0;j<digits.size();j++){
            if(mask & (1<<j)) continue;
            char ch=digits[j]+'0';
            f(i+1,s+ch,mask | (1<<j),digits); 
        }
        return;
    }
    int totalNumbers(vector<int>& digits) {
        f(0,"",0,digits);
        return st.size();
    }
};