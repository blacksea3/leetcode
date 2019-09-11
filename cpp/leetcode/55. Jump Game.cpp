#include "public.h"

/*
//20ms, 38.25%
//̰��1
//�Ӻ���ǰ��, ������ֵ�ǰ������ŵ����, �ж��ܷ��������

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int nSize = nums.size();
		int preLoc = nSize - 1;

		while (preLoc > 0)
		{
			int preStartLoc = preLoc - 1;
			while (preStartLoc >= 0)
			{
				if ((nums[preStartLoc] + preStartLoc) >= preLoc)
				{
					preLoc = preStartLoc;
					break;
				}
				preStartLoc--;
			}
			if (preStartLoc < 0) break;
		}
		return (preLoc == 0);
	}
};
*/

//12ms, 88.10%
//̰��2
//��ǰ������, ÿ�θ�����Զ����, �����ǰ���곬���˵�ǰ��Զ������false, ��������true
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int maxIndex = 0;

		for (int index = 0; index < nums.size(); ++index)
		{
			if (index > maxIndex) return false;
			else maxIndex = max(maxIndex, index + nums[index]);
		}

		return true;
	}
};
