class Solution {
public:
    // imp observation=>
    // 1- we have to make a subseqeusnce having max length=n/k, because we are repeating it k times
    // 2- now we have to calculate frequency of each character and see the character which have frequency>=k because for making a subsequence we can only use them.
    // 3- now if we know the characters which can be made up are subsequence so we try all possible combo's of subsequences and try to find longest one
    // 4- now we have to check that subseqence by repeating it k times that is this present or not in our sequence 
    // <-------------------------------------------------------------------------------------------------->

    // obs 4 checking subsequnce is present
    bool isSubsequence(string curr,string s,int k){
        int i=0,j=0;
        int n=curr.size();
        while(i<s.size() && j<k*n){
            if(s[i]==curr[j%n]) j++;
            i++;
        }
        return j==k*n;
    }
    // obs 3 backtracking
    void f(vector<bool> &canUse,vector<int> &reqFreq,int mxLen,string &s,int k,string &curr,string &result){
        if(curr.size()>mxLen) return;
        if((curr.size()>result.size() || (curr.size()==result.size() && curr>result)) && isSubsequence(curr,s,k)){
            result=curr;
        }
        for(int i=0;i<26;i++){
            if(canUse[i] && reqFreq[i]>0){
                char ch=i+'a';
                // DO
                curr.push_back(ch);
                reqFreq[i]--;

                // Explore
                f(canUse,reqFreq,mxLen,s,k,curr,result);

                // Undo
                curr.pop_back();
                reqFreq[i]++;
            }
        }
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        int n=s.size();
        // doing obs 1
        int mxLen=n/k;
        // doing obs 2
        vector<int> hash(26,0);
        for(int i=0;i<n;i++) hash[s[i]-'a']++;
        vector<bool> canUse(26,0);
        vector<int> reqFreq(26,0);
        for(int i=0;i<26;i++){
            if(hash[i]>=k){
                canUse[i]=true;
                reqFreq[i]=hash[i]/k;
            }
        }
        // doing obs 3 by backtracking means generating all subsequences and obs 4 by making isSubsequence func
        string result="";
        string curr;
        f(canUse,reqFreq,mxLen,s,k,curr,result);
        return result;
    }
};