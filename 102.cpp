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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;

        int level = 1;
        queue<Elem*> que; 
        que.push(new Elem(root, level));
        vector<int> v;

        while (!que.empty()) {
            Elem* tmp = que.front();
            if (tmp->level != level) {
                res.push_back(v);
                v.clear();
                ++level;
            }
            v.push_back(tmp->p->val);
            if (tmp->p->left)
                que.push(new Elem(tmp->p->left, tmp->level + 1));
            if (tmp->p->right)
                que.push(new Elem(tmp->p->right, tmp->level + 1));
            que.pop();
        }
        res.push_back(v);
        return res;
    }

private:
    struct Elem {
        TreeNode *p;
        int level;
        Elem(TreeNode* tn, int l) : p(tn), level(l) {}
    };
};
