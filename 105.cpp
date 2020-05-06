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
        size_t l1 = preorder.size();
        size_t l2 = inorder.size();
        if (l1 != l2 || l1 == 0) return nullptr;

        return handle(preorder, 0, l1 -1, inorder, 0, l2 - 1);
    }

    // recursive
    TreeNode* handle(vector<int>& pre_v, int s1, int e1,
                vector<int>& in_v, int s2, int e2) {
        if (e1 == s1) return new TreeNode(pre_v[s1]);

        TreeNode* n = new TreeNode(pre_v[s1]);

        int idx = s2;
        while (in_v[idx] != pre_v[s1]) ++idx;

        // left
        int ls1, le1, ls2, le2;
        ls1 = s1 + 1;
        le1 = idx;
        ls2 = s2;
        le2 = idx - 1;
        n->left = handle(pre_v, ls1, le1, in_v, ls2, le2);

        // right
        int rs1, re1, rs2, re2;
        rs1 = idx + 1;
        re1 = e1;
        rs2 = idx + 1;
        re2 = e2;
        n->right = handle(pre_v, rs1, re1, in_v, rs2, re2);

        return n;
    }
};
