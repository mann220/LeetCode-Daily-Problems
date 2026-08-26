class Solution {
public:
    #define ll long long
    ll f(ll first_hlf,bool isEven){
        ll num=first_hlf;
        if(isEven==false) first_hlf/=10;
        while(first_hlf>0){
            int digit=first_hlf%10;
            num=(num*10)+digit;
            first_hlf/=10;
        }
        return num;
    }
    string nearestPalindromic(string n) {
        int sz=n.size();
        int mid=sz/2;
        int hlf=(sz%2==0) ? mid : mid+1; 
        ll first_hlf=stoll(n.substr(0,hlf));
        vector<ll> ans;
        ans.push_back(f(first_hlf,sz%2==0));
        ans.push_back(f(first_hlf+1,sz%2==0));
        ans.push_back(f(first_hlf-1,sz%2==0));
        ans.push_back((ll)pow(10,sz-1)-1);
        ans.push_back((ll)pow(10,sz)+1);
        ll diff=LLONG_MAX;
        ll result=LLONG_MAX;
        ll num=stoll(n);
        for(ll val:ans){
            if(num==val) continue;
            if(abs(val-num)<diff){
                diff=abs(val-num);
                result=val;
            }
            else if(abs(num-val)==diff){
                result=min(result,val);
            }
        }
        return to_string(result);
    }
};