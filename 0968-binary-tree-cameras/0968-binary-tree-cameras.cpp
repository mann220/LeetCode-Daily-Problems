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

// here we just have to take that if the node has camer then lets take it 2, if it is monitored by its other node then its 1, otherwise 0 i.e its not monitored
// now the base case will be when root==> null return 1, you will understand this by urself i am not writing here
class Solution {
public:
    int f(TreeNode* root,int &sum){
        if(root==NULL) return 1;
        int lft=f(root->left,sum);
        int rgt=f(root->right,sum);
        if(lft==0 || rgt==0){
            sum++;
            return 2;
        }
        else if(lft==2 || rgt==2) return 1;
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        int sum=0;
        if(f(root,sum)==0) sum++;   // if root is not monitored we will put one additional camera on the root 
        return sum;
    }
};