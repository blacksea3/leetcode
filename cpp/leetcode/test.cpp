#include "BinaryTree.h"
#include "ListNode.h"

//����һ�ε�ǰ�����

//������м䷭[i, j], ��ôi , j ����: (abs(nums[i] - nums[j + 1]) + abs(nums[i - 1] - nums[j])) - (abs(nums[i] - nums[i - 1]) + abs(nums[j] - nums[j + 1])) ���
//�ֻ��ߴ�[0, j]��, ��ôj ����: abs(nums[j + 1] - nums[0]) - abs(nums[j + 1] - nums[j])���
//�ֻ��ߴ�[i, nums.size() - 1]��, ��ôi����: abs(nums.back() - nums[i - 1]) - abs(nums[i] - nums[i - 1])���

//�ĸ�����ȡ���ֵ

class Solution {
public:
	int maxValueAfterReverse(vector<int>& nums) {
		if (nums.size() == 1) return 0;
		else {
			int OriRes = 0;

			for (int index = 0; index < (nums.size() - 1); ++index) {
				OriRes += abs(nums[index + 1] - nums[index]);
			}

			vector<int> absDP(nums.size(), INT_MAX);         //means abs(nums[index] - nums[index - 1])
			for (int iter = 1; iter < nums.size(); ++iter) {
				absDP[iter] = abs(nums[iter] - nums[iter - 1]);
			}

			int absMaxRes = INT_MIN;
			for (int i = 1; i < nums.size() - 1; ++i) {
				for (int j = i + 1; j < nums.size() - 1; ++j) {
					absMaxRes = max(absMaxRes, (abs(nums[i] - nums[j + 1]) + abs(nums[i - 1] - nums[j])) - (absDP[i] + absDP[j + 1]));
				}
			}

			int absSideR = INT_MIN;
			for (int j = 1; j < nums.size() - 1; ++j) {
				absSideR = max(absSideR, abs(nums[j + 1] - nums[0]) - abs(nums[j + 1] - nums[j]));
			}

			int absSideL = INT_MIN;
			for (int i = 1; i < nums.size() - 1; ++i) {
				absSideL = max(absSideL, abs(nums.back() - nums[i - 1]) - abs(nums[i] - nums[i - 1]));
			}

			return OriRes + max(max(0, absMaxRes), max(absSideR, absSideL));

		}


	}
};

int main()
{
	Solution* s = new Solution();
	vector<int> nums = { 2,3,1,5,4 };
	cout << s->maxValueAfterReverse(nums) << endl;  //10

	vector<int> nums2 = { 2,4,9,24,2,1,10 }; 
	cout << s->maxValueAfterReverse(nums2) << endl; //68

	return 0; 
}
