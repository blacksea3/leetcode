#include "BinaryTree.h"

//DC problem: Divide and Conquer, 20ms, 98.53%
// Binary recursively

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
	//should ensure that right >= left, if not return nullptr
	TreeNode* iter_sortedArrayToBST(vector<int>& nums, int left, int right)
	{
		if (left > right) return nullptr;
		//divide into two tree
		int mid = left + (right - left) / 2;  //don't use mid = (l + r)/2£¬may overflow?!
		TreeNode *root = new TreeNode(nums[mid]);
		root->left = iter_sortedArrayToBST(nums, left, mid - 1);
		root->right = iter_sortedArrayToBST(nums, mid + 1, right);

		return root;
	}

public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.size() == 0) return nullptr;
		else return iter_sortedArrayToBST(nums, 0, nums.size() - 1);
	}
};
