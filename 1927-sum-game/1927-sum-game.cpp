class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();
        double ans=0;
        for(int i=0;i<n;i++){
            if(i<n/2){
                if(num[i]=='?') ans+=4.5;
                else ans+=num[i]-'0';
            } 
            else{
                if(num[i]=='?') ans-=4.5;
                else ans-=num[i]-'0';
            }
        }
        return ans!=0.0;
    }
};