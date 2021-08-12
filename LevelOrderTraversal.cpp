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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL)
            return result;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> curr_vec;
        while(!q.empty())
        {
            TreeNode* current= q.front();
            q.pop();
            if(current==NULL)
            {
                result.push_back(curr_vec);
                curr_vec.resize(0);
                if(q.size()>0)
                    q.push(NULL);
            }
            else{
                curr_vec.push_back(current->val);
                if(current->left!=NULL)
                    q.push(current->left);
                if(current->right!=NULL)
                    q.push(current->right);
            }
        }
        return result;
    }
};
