#include "public.h"
#include "leetcode.h"

#ifdef LEETCODE_81_90

//nums[startloc, endloc]��������������,Ҳ���ܲ��ǵ�,���涼�д���,����������������������
//�ҷ�����Ŀ�涨
int Solution::iter_search_81(vector<int>& nums, int target, int startloc, int endloc)
{
	//���ֲ��
	int nsize = endloc - startloc;
	if (nsize < 0) return -1;
	if (nsize == 0)
	{
		if (nums[startloc] == target) return startloc;
		else return -1;
	}
	else
	{
		int mid = (startloc + endloc) / 2;   //here mid must < endloc
		//��ʽ�ָ����[startloc,mid],  [mid+1,endloc]

		//��һ�����������,����nums[startloc] <= nums[mid],��Ҳ������������
		//����1 3 1 1 1
		//���ʱ��Ӧ�������ж���λ�Ƿ���ͬ,Ȼ�����м���,ֱ�ӱ���������

		bool is_lefthalf_sorted = true;

		if (nums[startloc] != nums[endloc])
		{
			is_lefthalf_sorted = (nums[startloc] <= nums[mid]);
			//��[0,mid]����������������,��[mid+1,endloc]��Ϊ������������
		}
		else
		{
			//���������[startloc,mid]�ǲ�����������
			if (nums[startloc] < nums[mid]) is_lefthalf_sorted = true;
			else
			{
				//�������ֻ��һ��Ԫ��,��ôis_lefthalf_sorted�����Ĭ��ֵtrue
				for (int i = (startloc + 1); i <= mid; i++)
					if (nums[i] != nums[startloc]) is_lefthalf_sorted = false;
			}
		}
		if (is_lefthalf_sorted)
		{
			if (nums[startloc] <= target)
				if (target <= nums[mid])
					return binary_search_81(nums, target, startloc, mid);
				else //�����ں���
				{
					//���β�һ����������������
					bool is_righthalf_sorted = true;  //˼·�����ε�һ��
					if (nums[mid + 1] < nums[endloc]) is_righthalf_sorted = true;
					else
					{
						//����Ұ��ֻ��һ��Ԫ��,��ôis_righthalf_sorted�����Ĭ��ֵtrue
						for (int i = (mid + 2); i <= endloc; i++)
							if (nums[i] != nums[mid + 1]) is_righthalf_sorted = false;
					}

					if (is_righthalf_sorted)     //[mid+1,endloc]Ϊ������������
						return binary_search_81(nums, target, mid + 1, endloc);
					else
						return iter_search_81(nums, target, mid + 1, endloc);
				}
			else
				return iter_search_81(nums, target, mid + 1, endloc);
		}
		else
		{
			if (nums[mid + 1] <= target)
				if (target <= nums[endloc])
					return binary_search_81(nums, target, mid + 1, endloc);
				else
					return iter_search_81(nums, target, startloc, mid);
			else
				return iter_search_81(nums, target, startloc, mid);
		}

	}
}

int Solution::binary_search_81(vector<int>& nums, int target, int startloc, int endloc)
{
	int left = startloc;
	int right = endloc;
	if (right < left) return -1;
	if (right == left)
	{
		if (nums[left] == target) return left;
		else return -1;
	}
	else
	{
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (nums[mid] < target) left = mid + 1;
			else if (nums[mid] > target) right = mid - 1;
			else return mid;
		}
	}
	return -1;
}

bool Solution::search_81(vector<int>& nums, int target)
{
	int nsize = nums.size();
	if (nsize == 0) return false;
	if (nsize == 1)
	{
		if (nums[0] == target) return true;
		else return false;
    }

	//����Ϊnsize >= 2����,�ݹ�
	if (iter_search_81(nums, target, 0, nsize - 1) == -1)
		return false;
	else return true;
}

ListNode * Solution::deleteDuplicates(ListNode * head)
{
	if (head == nullptr) return nullptr;

	//һ�ֱ���
	//˫ָ��
	ListNode* dump = new ListNode(0);
	dump->next = head;
	ListNode* loc = dump;
	ListNode *left, *right;

	//1->1->2->2->3

	while (loc->next)
	{
		left = loc->next;
		right = left;
		while (right->next && right->next->val == left->val)
			right = right->next;
		if (left == right) loc = loc->next;
		else loc->next = right->next;
	}
	return dump->next;
}

ListNode * Solution::deleteDuplicates_83(ListNode * head)
{
	ListNode *dump = new ListNode(0);
	dump->next = head;

	ListNode *left, *right;
	ListNode *loc = head;

	while (loc)
	{
		left = loc;
		right = loc->next;
		while (right && (right->val == left->val)) right = right->next;
		if (left->next == right) loc = loc->next;
		else loc->next = right;
	}
	return dump->next;
}

int Solution::largestRectangleArea(vector<int>& heights)
{
	//����ջ
	//����https://blog.csdn.net/lv1224/article/details/79974175

	//�㷨̫�߶���:)

	vector<int> stack = {};
	int hsize = heights.size();
	int maxArea = 0;
	if (hsize == 0) return 0;

	for (int i = 0; i < hsize; i++)
	{
		if (stack.empty() || heights[stack[stack.size() - 1]] <= heights[i]) stack.push_back(i);
		else
		{
			while (!stack.empty() && heights[stack[stack.size() - 1]] > heights[i])
			{
				int top = stack[stack.size() - 1];
				stack.pop_back();
				if (stack.empty()) maxArea = max(heights[top] * i, maxArea);
				else maxArea = max(heights[top] * (i - stack[stack.size() - 1] - 1), maxArea);
			}
			stack.push_back(i);
		}
	}

	while (!stack.empty())
	{
		int top = stack[stack.size() - 1];
		stack.pop_back();
		if (stack.empty()) maxArea = max(heights[top] * (hsize), maxArea);
		else maxArea = max(heights[top]* (hsize - stack[stack.size() - 1] - 1), maxArea);
	}
	return maxArea;
}

int Solution::maximalRectangle(vector<vector<char>>& matrix)
{
	//���п�,����������������1���������Ǹ߶�,��ô�ͱ��Ѱ��ÿ�е����������(��һ��),
	//Ȼ���m��(m��)�������ҳ�����

	//m��n��
	int m = matrix.size();
	if (m == 0) return 0;
	int n = matrix[0].size();
	if (n == 0) return 0;

	vector<vector<int>> heights(m, vector<int>(n, 0));

	for (int j = 0; j < n; j++)
		heights[0][j] = (matrix[0][j] == '1') ? 1 : 0;

	for (int i = 1; i < m; i++)
		for (int j = 0; j < n; j++)
			heights[i][j] = (matrix[i][j] == '1') ? heights[i - 1][j] + 1 : 0;

	int maxsize = 0;

	for (int i = 0; i < m; i++)
		maxsize = max(maxsize, largestRectangleArea(heights[i]));

	return maxsize;
}

ListNode * Solution::partition(ListNode * head, int x)
{
	//��򵥵İ취,�ϳ������½�������

	ListNode *leftdump = new ListNode(0);
	ListNode *rightdump = new ListNode(0);
	ListNode *left = leftdump;
	ListNode *right = rightdump;

	while (head != nullptr)
	{
		if (head->val < x)
		{
			left->next = new ListNode(head->val);
			left = left->next;
		}
		else
		{
			right->next = new ListNode(head->val);
			right = right->next;
		}
		head = head->next;
	}

	if (leftdump->next)
	{
		left->next = rightdump->next;
		return leftdump->next;
	}
	else return rightdump->next;
}

bool Solution::isScramble(string s1, string s2)
{
	//�ж�s2�Ƿ��ܹ�ͨ��s1���ض����������ַ��������õ�,���������ڽ��������ַ�����������,
	//ÿ����һ��,s1������        

	//�ݹ�̫������,���������ַ���,ֹͣ�����������ַ�����ȫ��ͬ
	//�ݹ�ʱ�����п��ַ������±�ݹ�,�˹�ʵ�ָ���λ�õĽ���!

	//��̬�滮 https://blog.csdn.net/linhuanmars/article/details/24506703

	//��̬�滮dp[i][j][len_m1]��ʾs1.substr(i,len_m1+1)��s2.substr(j,len_m1+1)�Ƿ�
	//Ϊ�����ַ���,len_m1��ʾ���ȼ�һ(���������±��0��ʼ)...
	//i��0~s1.size()-1;  j��0~s2.size()-1

	//len_m1=0ʱ���Լ����
	//len_m1>0ʱ,emmmmm��Ϊ���������
	//����:s1��i��ʼ��ĳ��������s2��j��ʼ��ĳ��������ͬ,����֮����Ƕγ���Ҳ��Ӧ��ͬ
	//����:s1��i��ʼ��ĳ��������s2�ĵ���ĳ��������ͬ,����s2��j��ʼ����һ�γ�����s1�ĵ�����һ�γ�����ͬ

	//ע�ⲻ������dpԪ�ض��Ϸ�,����len_m1������,i��j�����޽���
	int lens = s1.size();
	if (lens == 0) return true;  //���ַ���>.<
	//ע���ⲿȷ�����볤����ͬ
	vector<vector<vector<bool>>> dp(lens, vector<vector<bool>>(lens, vector<bool>(lens, false)));

	for (int i = 0; i < lens; i++)
		for (int j = 0; j < lens; j++)
			dp[i][j][0] = (s1[i] == s2[j]);

	//����dp
	for (int lenm1 = 1; lenm1 < lens; lenm1++)   //ʵ�ʳ��ȼ�1
	{
		for (int i = 0; i < lens - lenm1; i++)
			for (int j = 0; j < lens - lenm1; j++)
			{
				//��Щ�����ֱ����Ծ,����Ҫ�������|=λ��
				//����
				for (int klenm1 = 0; klenm1 < lenm1; klenm1++)  //�󲿷�ʵ�ʳ��ȼ�1
					if (dp[i][j][klenm1] && dp[i + klenm1 + 1][j + klenm1 + 1][lenm1 - klenm1 - 1])
					{
						dp[i][j][lenm1] = true;
						goto end;
					}
				//����
				for (int klenm1 = 0; klenm1 < lenm1; klenm1++)  //�󲿷�ʵ�ʳ��ȼ�1
					if (dp[i][j + lenm1 - klenm1][klenm1] && dp[i + klenm1 + 1][j][lenm1 - klenm1 - 1])
					{
						dp[i][j][lenm1] = true;
						goto end;
					}
			end:;
			}
	}

	return dp[0][0][lens - 1];
}

void Solution::merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	//���߶���һ�ֱ���

	int pre_loc = m + n - 1;
	int m_loc = m - 1;
	int n_loc = n - 1;

	while ((m_loc > -1) && (n_loc > -1))
	{
		if (nums1[m_loc] >= nums2[n_loc]) nums1[pre_loc--] = nums1[m_loc--];
		else nums1[pre_loc--] = nums2[n_loc--];
	}

	if (m_loc == -1)
		while (n_loc > -1) nums1[pre_loc--] = nums2[n_loc--];

}

vector<int> Solution::grayCode(int n)
{
	//������ø��ױ���

	//���n֮ǰҪ���n-1��
	//n=1ֱ�Ӹ���,n=0Ϊ�������

	//�����������ز���

	if (n == 0) return vector<int> {0};
	if (n == 1) return vector<int> {0, 1};

	vector<int> left = { 0,1 };
	vector<int> right;
	bool is_left_useful = true;

	for (int i = 2; i <= n; i++)
	{
		if (is_left_useful)
		{
			right.clear();
			right.resize(left.size() * 2);
			for (int j = 0; j < left.size(); j++)
				right[j] = left[j];
			int abs = 1 << (i - 1);
			for (int j = left.size(); j < 2 * left.size(); j++)
				right[j] = left[2 * left.size() - j - 1] + abs;
			is_left_useful = false;
		}
		else
		{
			left.clear();
			left.resize(right.size() * 2);
			for (int j = 0; j < right.size(); j++)
				left[j] = right[j];
			int abs = 1 << (i - 1);
			for (int j = right.size(); j < 2 * right.size(); j++)
				left[j] = right[2 * right.size() - j - 1] + abs;
			is_left_useful = true;
		}
	}
	return (is_left_useful) ? left : right;
}

vector<vector<int>> Solution::subsetsWithDup(vector<int>& nums)
{
	//����
	//��ʼ��:numdict:nums�ֵ����
	//length:nums����
	//uniquenums:ȥ��nums

	//ά��:stack:δ�������õ�������
	//prelength:��ǰ����
	//predict:��ǰ�����ֵ�
	//prenums:��ǰ����vector
	//res:����ֵ

	//��ʼ������
	int length = nums.size();
	if (length == 0) return vector<vector<int>>{ {}};
	if (length == 1) return vector<vector<int>>{ {}, nums};

	unordered_map<int, int> numdict;
	for (auto num : nums) numdict[num]++;

	unordered_map<int, int>::iterator it;
	vector<int> uniquenums;
	for (it = numdict.begin(); it != numdict.end(); it++) {
		if (find(uniquenums.begin(), uniquenums.end(), it->first) == uniquenums.end())
			uniquenums.push_back(it->first);
	}
	sort(uniquenums.begin(), uniquenums.end());

	vector<vector<int>> stack = { uniquenums };
	int prelength = 0;
	unordered_map<int, int> predict;
	vector<int> prenums;
	vector<vector<int>> res = { {} };

	//���ݹ���
	while ((stack.size() > 1) || (stack[0].size() >= 1))
	{
		if (stack[stack.size() - 1].size() > 0)
		{
			int pre_num = stack[stack.size() - 1][0];
			stack[stack.size() - 1].erase(stack[stack.size() - 1].begin());
			prenums.push_back(pre_num);
			predict[pre_num]++;
			prelength++;
			res.push_back(prenums);

			if (prelength == length) continue; //�������,��������

			//���������ܵ�����
			vector<int> temp = {};
			for (auto tempnum : uniquenums)
				if (tempnum < pre_num)
					temp.push_back(tempnum);
			//�����ظ�����,�ر���
			if (predict[pre_num] < numdict[pre_num]) temp.push_back(pre_num);
			stack.push_back(temp);
		}
		else
		{
			int last_num = prenums[prenums.size() - 1];
			predict[last_num]--;
			prenums.pop_back();
			prelength--;
			stack.pop_back();
		}
	}
	return res;
}



#else
#endif
