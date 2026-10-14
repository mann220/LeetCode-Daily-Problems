class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans="";
        if(sum>num*9) return ans;
        while(num){
            if(sum>=9){
                ans+='9';
                sum-=9;
            }
            else{
                ans+=to_string(sum);
                sum=0;
            }
            num--;
        }
        return ans;
    }
};