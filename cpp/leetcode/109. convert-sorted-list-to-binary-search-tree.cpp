#include "BinaryTree.h"
#include "listnode.h"

/*
//64ms, 33.69%
//�Ȱ�����ת������Ȼ����108��
class Solution {
private:
	//should ensure that right >= left, if not return nullptr
	TreeNode* iter_sortedArrayToBST(vector<int>& nums, int left, int right)
	{
		if (left > right) return nullptr;
		//divide into two tree
		int mid = left + (right - left) / 2;  //don't use mid = (l + r)/2��may overflow?!
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
//ֱ�Ӱ�����ת�ɶ���������
//�ÿ���ָ�붨λ�����м�
class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		if (!head) return nullptr;
		else if (!head->next) return new TreeNode(head->val);
		else
		{
			ListNode* fast = head;
			ListNode* slow = head;
			ListNode* oldslow;     //ע�⵽head==nullptr��head->next==nullptr�Ѿ����ų�, �����while���ٻ�ѭ��һ��
			while (fast && fast->next)
			{
				oldslow = slow;
				fast = fast->next->next;
				slow = slow->next;
			}
			//�ж�list
			TreeNode *root = new TreeNode(slow->val);
			oldslow->next = nullptr;
			root->left = sortedListToBST(head);
			root->right = sortedListToBST(slow->next);
			return root;
		}
	}
};
