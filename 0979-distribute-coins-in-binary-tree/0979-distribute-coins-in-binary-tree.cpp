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

// i think i have to find distance from node which has coin then minimise them all i think bfs is best choice
// the idea is wrong i am doing wrong way it is purely recusrion based question
class Solution {
public:
    int ans;
    int f(TreeNode* root){
        if(root==nullptr) return 0;
        int l=f(root->left);
        int r=f(root->right);
        ans+=(abs(r)+abs(l));
        return (r+l+root->val-1);
    }
    int distributeCoins(TreeNode* root) {
        ans=0;
        f(root);
        return ans;
    }
};