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

    int sumLevel(TreeNode* root, int k){
        if(root==NULL)
        {
            return 0;
        }

        if(k==1)
        {
            return root->val;

        }
        return sumLevel(root->left, k-1)+sumLevel(root->right, k-1);

    }

    bool exists(TreeNode* root, int k)
    {
        if(root == NULL)
            return false;

        if(k == 1)
            return true;

        return exists(root->left, k-1) ||
               exists(root->right, k-1);
    }


    int maxLevelSum(TreeNode* root) {
        int level = 1;
        int ans = 1;
        int maxVal = root->val;

        while(exists(root, level)){
            int sum = sumLevel(root, level);
            
            if(sum>maxVal)
            {
                maxVal = sum;
                ans = level;
            }
            level++;
        }
        return ans;
    }
};