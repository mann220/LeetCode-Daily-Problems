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
    int maxi;
    int mini;
    void f(TreeNode* root){
        if(root==NULL) return;
        int maxi1=maxi;
        int mini1=mini;
        maxi=max(maxi,root->val);
        mini=min(mini,root->val);
        ans=max(ans,maxi-mini);
        f(root->left);
        f(root->right);
        maxi=maxi1;
        mini=mini1;
        return;
    }
    int maxAncestorDiff(TreeNode* root) {
        ans=0;
        maxi=0;
        mini=1e9;
        f(root);
        return ans;
    }
};