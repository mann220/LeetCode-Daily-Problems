class Solution {
public:
    #define ll long long 
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        pair<ll,ll> minNeed,maxNeed;
        if(need1>need2){
            minNeed={need2,cost2};
            maxNeed={need1,cost1};
        }
        else{
            minNeed={need1,cost1};
            maxNeed={need2,cost2};
        }
        ll tot=cost1+cost2;
        ll ans=0;
        if(tot>=costBoth){
            ans+=(minNeed.first*costBoth);
            if(maxNeed.second<=costBoth) ans+=(maxNeed.first-minNeed.first)*maxNeed.second;
            else ans+=(maxNeed.first-minNeed.first)*costBoth;
        }
        else{
            ans+=(minNeed.first*minNeed.second);
            ans+=(maxNeed.first*maxNeed.second);
        }
        return ans;
    }
};