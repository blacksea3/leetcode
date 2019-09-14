#include "BinaryTree.h"
#include "listnode.h"

/*
//64ms, 33.69%
//先把链表转成数组然后用108题
class Solution {
private:
	//should ensure that right >= left, if not return nullptr
	TreeNode* iter_sortedArrayToBST(vector<int>& nums, int left, int right)
	{
		if (left > right) return nullptr;
		//divide into two tree
		int mid = left + (right - left) / 2;  //don't use mid = (l + r)/2，may overflow?!
		TreeNode *root = new TreeNode(nums[mid]);
		root->left = iter_sortedArrayToBST(nums, left, mid - 1);
		root->right = iter_sortedArrayToBST(nums, mid + 1, right);

		return root;
	}

	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.size() == 0) return nullptr;
		else return iter_sortedArrayToBST(nums, 0, nums.size() - 1);
	}

public:
	TreeNode* sortedListToBST(ListNode* head) {
		vector<int> nums = {};
		ListNode* pre = head;
		while (pre != nullptr)
		{
			nums.emplace_back(pre->val);
			pre = pre->next;
		}
		return sortedArrayToBST(nums);
	}
};
*/

//36ms, 92.19%
//直接把链表转成二叉搜索树
//用快慢指针定位链表中间
class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		if (!head) return nullptr;
		else if (!head->next) return new TreeNode(head->val);
		else
		{
			ListNode* fast = head;
			ListNode* slow = head;
			ListNode* oldslow;     //注意到head==nullptr和head->next==nullptr已经被排除, 下面的while至少会循环一次
			while (fast && fast->next)
			{
				oldslow = slow;
				fast = fast->next->next;
				slow = slow->next;
			}
			//切断list
			TreeNode *root = new TreeNode(slow->val);
			oldslow->next = nullptr;
			root->left = sortedListToBST(head);
			root->right = sortedListToBST(slow->next);
			return root;
		}
	}
};
