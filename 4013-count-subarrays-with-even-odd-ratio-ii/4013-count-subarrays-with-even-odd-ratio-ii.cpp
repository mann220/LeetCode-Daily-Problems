#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;
class Solution {
public:
    #define ll long long
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        ordered_set<pair<ll,int>> st;
        ll sum=0,ans=0;
        int val=0;
        st.insert({0,val++});
        for(auto it:nums){
            sum+=(it%2==0 ? b:-a);
            ans+=st.size()-st.order_of_key({sum,INT_MIN});
            st.insert({sum,val++});
        }
        return ans;
    }
};