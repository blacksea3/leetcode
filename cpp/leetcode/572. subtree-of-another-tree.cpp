#include "BinaryTree.h"

//32ms, 91.71%
//µÝ¹éÅÐ¶Ï, ÅÐ¶ÏÏàÍ¬Ê÷ºÍ×ÓÊ÷

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
private:
	TreeNode* root_t;

	bool isSametree(TreeNode* s, TreeNode* t)
	{
		if (!s && !t) return true;
		return  (s && t && s->val == t->val && isSametree(s->left, t->left)
			&& isSametree(s->right, t->right));
	}

public:
	bool isSubtree(TreeNode* s, TreeNode* t) {
		if (!s && !t) return true;
		if (!s || !t) return false;
		return isSametree(s, t)
			|| isSubtree(s->left, t)
			|| isSubtree(s->right, t);
	}
};

int main()
{
	Solution* s = new Solution();
	cout << s->isSubtree(stringToTreeNode("[3, 4, 5, 1, 2]"), stringToTreeNode("[4, 1, 2]"));
	return 0;
}
