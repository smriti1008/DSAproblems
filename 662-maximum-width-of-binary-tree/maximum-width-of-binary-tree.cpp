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
    int widthOfBinaryTree(TreeNode* root) {

        if (root == NULL) return 0;

        queue<pair<TreeNode* , unsigned long long>>q;
        q.push({root, 0});
        unsigned long long maxWidth = 0;
        while(q.size()>0){
            int currLevelsize = q.size();
            unsigned long long stIdx = q.front().second;
            unsigned long long endIdx = q.back().second;

            maxWidth = max(maxWidth, endIdx-stIdx+1);

            for(int i=0; i<currLevelsize; i++)
            {
            auto curr = q.front();
            q.pop();

            TreeNode* node = curr.first;
                unsigned long long idx = curr.second;
            
            if(curr.first->left){
                q.push({curr.first->left, curr.second*2+1});
            }
            if(curr.first->right){
                q.push({curr.first->right, curr.second*2+2});
            }
        }
        }
        return (int)maxWidth;
    }
};