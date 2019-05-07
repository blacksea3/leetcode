#include "public.h"
#include "leetcode.h"

#ifdef LEETCODE_101_110

bool Solution::isSymmetric(TreeNode * root)
{
	//�õ���,�ݹ�̫��

	//�����>1�����
	//ά������vector<TreeNode*>��ʾ���ҵĽڵ���,Ȼ��ɨ����
	//ֻ�е�ǰ�ڵ�Ķ����ǶԳ���,�Ż����stack

	//�������
	if (root == nullptr) return true;
	vector<TreeNode*> left1;
	vector<TreeNode*> right1;
	vector<TreeNode*> left2;
	vector<TreeNode*> right2;
	bool isvalid1 = true;

	//init left/right
	if ((root->right) && (root->left))
	{
		if ((root->right->val) == (root->left->val))
		{
			left1.push_back(root->left);
			right1.push_back(root->right);
		}
		else return false;
	}
	else if (!(root->right) && !(root->left)) return true;
	else return false;

	int count = 0;
	int countmax = (isvalid1) ? left1.size() : left2.size();
	while (true)  //�������
	{
		if (isvalid1)
		{
			TreeNode *tl = left1[0];
			TreeNode *tr = right1[0];
			left1.erase(left1.begin());
			right1.erase(right1.begin());
			if ((tr->right) && (tl->left))
			{
				if ((tr->right->val) == (tl->left->val))
				{
					left2.push_back(tl->left);
					right2.push_back(tr->right);
				}
				else return false;
			}
			else if (!(tr->right) && !(tl->left));
			else return false;

			if ((tr->left) && (tl->right))
			{
				if ((tr->left->val) == (tl->right->val))
				{
					left2.push_back(tl->right);
					right2.push_back(tr->left);
				}
				else return false;
			}
			else if (!(tr->left) && !(tl->right));
			else return false;
			count++;
		}
		else
		{
			TreeNode *tl = left2[0];
			TreeNode *tr = right2[0];
			left2.erase(left2.begin());
			right2.erase(right2.begin());
			if ((tr->right) && (tl->left))
			{
				if ((tr->right->val) == (tl->left->val))
				{
					left1.push_back(tl->left);
					right1.push_back(tr->right);
				}
				else return false;
			}
			else if (!(tr->right) && !(tl->left));
			else return false;

			if ((tr->left) && (tl->right))
			{
				if ((tr->left->val) == (tl->right->val))
				{
					left1.push_back(tl->right);
					right1.push_back(tr->left);
				}
				else return false;
			}
			else if (!(tr->left) && !(tl->right));
			else return false;
			count++;
		}


		if (count == countmax)
		{
			if (isvalid1)
			{
				left1.clear();
				right1.clear();
				countmax = left2.size();
				count = 0;
				isvalid1 = false;
				if (countmax == 0) break;
			}
			else
			{
				left2.clear();
				right2.clear();
				countmax = left1.size();
				count = 0;
				isvalid1 = true;
				if (countmax == 0) break;
			}
		}
	}
	return true;
}

vector<vector<int>> Solution::levelOrder(TreeNode * root)
{
	//û��ʲô�������

	//ά������vector<TreeNode*> pre_t1,pre_t2;
	//ά��һ��vector<vector<int>> total_res
	//ά��һ��vector<int> pre_res

	if (root == nullptr) return vector<vector<int>> {};

	vector<TreeNode*> pre_t1, pre_t2;

	vector<vector<int>> total_res;
	vector<int> pre_res;

	bool ist1valid = true;

	pre_t1.push_back(root);

	while (true)
	{
		if (ist1valid)
		{
			pre_t2.clear();
			pre_res.clear();
			for (auto tn : pre_t1)
			{
				pre_res.push_back(tn->val);
				if (tn->left) pre_t2.push_back(tn->left);
				if (tn->right) pre_t2.push_back(tn->right);
			}
			ist1valid = false;
			total_res.push_back(pre_res);
			if (pre_t2.empty()) break;
		}
		else
		{
			pre_t1.clear();
			pre_res.clear();
			for (auto tn : pre_t2)
			{
				pre_res.push_back(tn->val);
				if (tn->left) pre_t1.push_back(tn->left);
				if (tn->right) pre_t1.push_back(tn->right);
			}
			ist1valid = true;
			total_res.push_back(pre_res);
			if (pre_t1.empty()) break;
		}
	}
	return total_res;
}

vector<vector<int>> Solution::zigzagLevelOrder(TreeNode * root)
{
	//û��ʲô�������

	//ά������vector<TreeNode*> pre_t1,pre_t2;
	//ά��һ��vector<vector<int>> total_res
	//ά��һ��vector<int> pre_res

	if (root == nullptr) return vector<vector<int>> {};

	vector<TreeNode*> pre_t1, pre_t2;

	vector<vector<int>> total_res;
	vector<int> pre_res;

	bool ist1valid = true;  //���ͬʱҲ��ӳ�˱������ҷ���

	pre_t1.push_back(root);

	while (true)
	{
		if (ist1valid)
		{
			pre_t2.clear();
			pre_res.clear();
			for (auto tn : pre_t1)
			{
				pre_res.push_back(tn->val);
				if (tn->left) pre_t2.push_back(tn->left);
				if (tn->right) pre_t2.push_back(tn->right);
			}
			ist1valid = false;
			total_res.push_back(pre_res);
			if (pre_t2.empty()) break;
		}
		else
		{
			pre_t1.clear();
			pre_res.clear();
			for (int i = pre_t2.size() - 1; i >= 0; i--)
			{
				TreeNode *tn = pre_t2[i];
				pre_res.push_back(tn->val);
				if (tn->right) pre_t1.insert(pre_t1.begin(), tn->right);
				if (tn->left) pre_t1.insert(pre_t1.begin(), tn->left);
			}
			ist1valid = true;
			total_res.push_back(pre_res);
			if (pre_t1.empty()) break;
		}
	}
	return total_res;
}

int Solution::maxDepth(TreeNode * root)
{
	//û��ʲô�������

	//ά������vector<TreeNode*> pre_t1,pre_t2;
	//ά��һ��vector<vector<int>> total_res
	//ά��һ��vector<int> pre_res

	if (root == nullptr) return 0;

	vector<TreeNode*> pre_t1, pre_t2;

	int count = 0;
	vector<int> pre_res;

	bool ist1valid = true;

	pre_t1.push_back(root);

	while (true)
	{
		count++;
		if (ist1valid)
		{
			pre_t2.clear();
			pre_res.clear();
			for (auto tn : pre_t1)
			{
				pre_res.push_back(tn->val);
				if (tn->left) pre_t2.push_back(tn->left);
				if (tn->right) pre_t2.push_back(tn->right);
			}
			ist1valid = false;
			if (pre_t2.empty()) break;
		}
		else
		{
			pre_t1.clear();
			pre_res.clear();
			for (auto tn : pre_t2)
			{
				pre_res.push_back(tn->val);
				if (tn->left) pre_t1.push_back(tn->left);
				if (tn->right) pre_t1.push_back(tn->right);
			}
			ist1valid = true;
			if (pre_t1.empty()) break;
		}
	}
	return count;
}

TreeNode * Solution::buildTree(vector<int>& preorder, vector<int>& inorder)
{
	//�ݹ�������,fuck

	//����,ͨ��ǰ��ĵ�һ���ڵ��жϸ��ڵ�,���������Դ�Ϊ���ݲ��������������,��Ϊ��������������
	//Ȼ���������������Ȼ�ȡ��Ӧ��ǰ�����,������ȥ����

	if (preorder.size() == 0) return nullptr;

	stack<TreeNode*> st;
	TreeNode* root = new TreeNode(preorder[0]);
	st.push(root);
	int index = 0;

	//��preorder������ɨ,�����ǰ�ڵ�!=inorderδ�����ڵ�,���¼�������
	//Ȼ�����ջ,ע������ɨ��ʱ��,��ɨ�Ľڵ��ڵ�ǰ�ڵ��һ��
	//����,ջ�˳�,��ǰ�ڵ�����
	//inorder�ڵ�����������,����ֹͣʱ��ǰ�ڵ���ҽڵ�ǡ�õ���preorder
	//�ı�ɨ��Ľڵ�

	for (int i = 1; i <= preorder.size(); ++i)
	{
		TreeNode *cur = st.top();
		if (cur->val != inorder[index])
		{
			cur->left = new TreeNode(preorder[i]);
			st.push(cur->left);
		}
		else
		{
			while (!st.empty() && st.top()->val == inorder[index])
			{
				cur = st.top();
				st.pop();
				++index;
			}
			if (index < inorder.size())  //���൱���˳�ѭ����־
			{
				cur->right = new TreeNode(preorder[i]);
				st.push(cur->right);
			}
		}
	}
	return root;
}

TreeNode * Solution::buildTree_106(vector<int>& inorder, vector<int>& postorder)
{
	if (inorder.size() == 0) return nullptr;

	stack<TreeNode*> st;
	TreeNode* root = new TreeNode(postorder[postorder.size() - 1]);
	st.push(root);
	int index = inorder.size() - 1;

	//��һ��������
	//��preorder������ɨ,�����ǰ�ڵ�!=inorderδ�����ڵ�,���¼�������
	//Ȼ�����ջ,ע������ɨ��ʱ��,��ɨ�Ľڵ��ڵ�ǰ�ڵ��һ��
	//����,ջ�˳�,��ǰ�ڵ�����
	//inorder�ڵ�����������,����ֹͣʱ��ǰ�ڵ���ҽڵ�ǡ�õ���preorder
	//�ı�ɨ��Ľڵ�

	//��һ��������
	//�Ѻ���������������Ǹ�->��->��
	//���������������������->��->��
	//��������һ�ⲻ�ǲ����!

	for (int i = postorder.size() - 2; i >= 0; --i)
	{
		TreeNode *cur = st.top();
		if (cur->val != inorder[index])
		{
			cur->right = new TreeNode(postorder[i]);
			st.push(cur->right);
		}
		else
		{
			while (!st.empty() && st.top()->val == inorder[index])
			{
				cur = st.top();
				st.pop();
				--index;
			}
			if (index >= 0)  //���൱���˳�ѭ����־
			{
				cur->left = new TreeNode(postorder[i]);
				st.push(cur->left);
			}
		}
	}
	return root;
}

vector<vector<int>> Solution::levelOrderBottom(TreeNode * root)
{
	vector<vector<int>> res = levelOrder(root);

	//��resתһ��
	for (int i = 0; i < res.size(); i++)
	{
		vector<int> temp = res[res.size() - 1];
		res.pop_back();
		res.insert(res.begin() + i, temp);
	}
	return res;
}

TreeNode * Solution::iter_sortedArrayToBST(vector<int>& nums, int left, int right)
{
	//�������,Ȼ��ݹ�
	int nsize = right - left + 1;
	if (nsize == 1)
	{
		TreeNode *root = new TreeNode(nums[left]);
		return root;
	}
	else if (nsize == 2)
	{
		TreeNode *root = new TreeNode(nums[right]);
		root->left = new TreeNode(nums[left]);
		return root;
	}
	else
	{
		int mid = left + (right - left) / 2;  //���е㲻Ҫ�� int mid = (l + r)/2�����������
		TreeNode *root = new TreeNode(nums[mid]);
		root->left = iter_sortedArrayToBST(nums, left, mid - 1);
		root->right = iter_sortedArrayToBST(nums, mid + 1, right);

		return root;
	}
}

TreeNode * Solution::sortedArrayToBST(vector<int>& nums)
{
	if (nums.size() == 0) return nullptr;
	else return iter_sortedArrayToBST(nums, 0, nums.size() - 1);
}

TreeNode * Solution::sortedListToBST(ListNode * head)
{
	//ת����������,Ȼ��͸�������һ��Ĵ���

	vector<int> nums = {};
	ListNode* pre = head;
	while (pre != nullptr)
	{
		nums.push_back(pre->val);
		pre = pre->next;
	}
	return sortedArrayToBST(nums);
}

int Solution::treeDepth(TreeNode * root)
{
	if (root == nullptr) return 0;
	else return max(treeDepth(root->left), treeDepth(root->right)) + 1;
}

bool Solution::isBalanced(TreeNode * root)
{
	//�ݹ�,��ȡ�����������Ȼ���ж�
	//���費��ջ���

	if (root == nullptr) return true;
	if (abs(treeDepth(root->left) - treeDepth(root->right) ) > 1) return false;
	else
		return isBalanced(root->left) && isBalanced(root->right);
}

#else
#endif
