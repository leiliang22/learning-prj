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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        queue<int> q;
        handle(root, q);
        int val = q.front();
        q.pop();
        while(!q.empty()) {
            if (q.front() <= val) return false;
            val = q.front();
            q.pop();
        }
        return true;
    }

    void handle(TreeNode* root, queue<int>& q) {
        if (root == nullptr) return;

        handle(root->left, q);
        q.push(root->val);
        handle(root->right, q);
    }
};
