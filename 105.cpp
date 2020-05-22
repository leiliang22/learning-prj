/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int m = preorder.size();
        if(m == 0) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        vector<int> preorder_left, inorder_left, preorder_right, inorder_right;
        //在inorder里面寻找根节点，划分左子树和右子树
        int i;
        //构造左子树的中序遍历
        for(i = 0; i < m; i ++){
            if(inorder[i] == preorder[0]) break;
            inorder_left.push_back(inorder[i]);
        }
        //构造右子树的中序遍历
        for(i = i + 1; i < m; i ++){
            inorder_right.push_back(inorder[i]);
        }
        for(int j = 1; j < m; j ++){
            //构造左子树的前序遍历
            if(j <= inorder_left.size())
                preorder_left.push_back(preorder[j]);
            //构造右子树的前序遍历
            else preorder_right.push_back(preorder[j]);
        }
        root->left = buildTree(preorder_left, inorder_left);
        root->right = buildTree(preorder_right, inorder_right);
        return root;
    }
};
