/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans;
    pair<int,int> f(TreeNode* node){
        if(!node) return {0,0};
        auto l=f(node->left);
        auto r=f(node->right);
        int sum=(l.first+r.first+node->val);
        int count=(l.second+r.second+1);
        if((sum/count)==node->val) ans++;
        return {sum,count};
    }
    int averageOfSubtree(TreeNode* root) {
        ans=0;
        f(root);
        return ans;
    }
};