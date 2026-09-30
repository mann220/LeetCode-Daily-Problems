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
    int mx(int i,int j,vector<int> &nums){
        int ind=nums.size();
        int maxi=-1;
        for(int k=i;k<=j;k++){
            if(maxi<nums[k]){
                maxi=nums[k];
                ind=k;
            }
        }
        return ind;
    }
    TreeNode* f(int i,int j,vector<int> &nums){
        if(i>j) return nullptr;
        if(i==j) return new TreeNode(nums[i]);
        int ind=mx(i,j,nums);
        TreeNode* root=new TreeNode(nums[ind]);
        root->left=f(i,ind-1,nums);
        root->right=f(ind+1,j,nums);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n=nums.size();
        return f(0,n-1,nums);
    }
};