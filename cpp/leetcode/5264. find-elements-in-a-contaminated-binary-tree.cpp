#include "BinaryTree.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
private:
	//±©Á¦,×ª³Éunordered_set
	unordered_set<int> us;
	void recu(TreeNode* root, int prev)
	{
		if (!root) return;
		us.insert(prev);
		recu(root->left, 2 * prev + 1);
		recu(root->right, 2 * prev + 2);
	}

public:
	FindElements(TreeNode* root) {
		recu(root, 0);
	}

	bool find(int target) {
		return (us.find(target) != us.end());
	}
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
