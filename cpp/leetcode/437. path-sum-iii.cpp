#include "BinaryTree.h"

//24ms, 94.19%
//DFS, 保存从根节点到当前节点的值数组

class Solution {
public:
	int pathSum(TreeNode* root, int sum) {
		vector<int>data;
		int r = 0;
		recursive(root, sum, data, r);
		return r;
	}
private:
	void recursive(TreeNode* root, int sum, vector<int>& data, int &r) {
		if (!root) return;
		data.emplace_back(root->val);
		int curr = 0;
		for (int index = data.size() - 1; index >= 0; index--)
		{          //检查包含root->val的解的个数, 反向循环的意思是data实际上是从根往下的, 现在是从当前节点往上
			curr += data[index];
			if (curr == sum) r++;
		}
		recursive(root->left, sum, data, r);
		recursive(root->right, sum, data, r);
		data.pop_back();
	}
};

/*
//64ms, 13.66%
//DFS
//先序遍历, 中左右
//此方法有大量重复计算

class Solution {
private:
	int preOrder(TreeNode* root, int target)
	{
		if (!root) return 0;
		int rVal = root->val;
		int res = (rVal == target) ? 1 : 0;
		res += preOrder(root->left, target - rVal);
		res += preOrder(root->right, target - rVal);
		return res;
	}

public:
	int pathSum(TreeNode* root, int sum) {
		if (!root) return 0;
		return preOrder(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
	}
};
*/

/*
int main()
{
	Solution* s = new Solution();
	TreeNode* root = stringToTreeNode("[1,null,2,null,3]");
	prettyPrintTree(root);
	cout << s->pathSum(root, 3);
	return 0;
}
*/
