/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, Tr5eeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> arr;
    void f(TreeNode* root){
        if(root==nullptr) return;
        f(root->left);
        arr.push_back(root->val);
        f(root->right);
    }
    int mx(int i,int j,vector<int> &arr){
        int ind=-1;
        int maxi=-1;
        for(int k=i;k<=j;k++){
            if(maxi<arr[k]){
                maxi=arr[k];
                ind=k;
            }
        }
        return ind;
    }
    TreeNode* f1(int i,int j,vector<int>& arr){
        if(i>j) return nullptr;
        if(i==j) return new TreeNode(arr[i]);
        int ind=mx(i,j,arr);
        TreeNode* root=new TreeNode(arr[ind]);
        root->left=f1(i,ind-1,arr);
        root->right=f1(ind+1,j,arr);
        return root;
    }
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        f(root);
        arr.push_back(val);
        return f1(0,arr.size()-1,arr);
    }
};