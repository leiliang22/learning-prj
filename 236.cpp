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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::vector<TreeNode*> lp, lq;
        findx(root, p->val, lp);
        findx(root, q->val, lq);
        TreeNode* res = nullptr;
        
        std::vector<TreeNode*>::iterator pit,qit;
        pit = lp.begin();
        qit = lq.begin();
        while (pit!=lp.end() && qit!=lq.end()) {
            if(*pit == *qit) {
                res = *pit;
                ++pit;
                ++qit;
            } else {
                return res;
            }
        }
        return res;
    }

    bool findx(TreeNode* root, int val, vector<TreeNode*>& l) {
        if (root == nullptr) return false;

        if (root->val == val) {
            l.push_back(root);
            return true;
        }

        l.push_back(root);
        if (findx(root->left, val, l)) return true;
        if (findx(root->right, val, l)) return true;
        l.pop_back();
        return false;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return root;
        if (root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p , q);
        TreeNode* right = lowestCommonAncestor(root->right, p , q);

        if (left == nullptr) return right;
        if (right == nullptr) return left;

        if (left && right) return root;

        return nullptr;
    }
};
