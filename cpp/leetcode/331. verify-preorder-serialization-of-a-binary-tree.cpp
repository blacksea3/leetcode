#include "BinaryTree.h"

//8ms, 87.56%
//在未结束之前, 读取到的节点数量应大于叶子节点数量
//结束时叶子数量应等于节点数量

class Solution {
public:
	bool isValidSerialization(string preorder) {
		//特殊输入
		if ((preorder.size() == 0) || (preorder == "#")) return true;

		int loc = 0;
		while (isdigit(preorder[loc])) loc++;
		loc++;
		int nodes = 1;
		int leaves = 0;

		while (loc < preorder.size())
		{
			if (preorder[loc] == '#')
			{
				leaves++;
				if (leaves > nodes)
					if(loc == preorder.size() - 1) return true;
					else return false;
				loc += 2;
			}
			else 
			{
				while (isdigit(preorder[loc])) loc++;
				loc++;
				nodes++;
			}
		}
		return false;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	//cout << s->isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#");
	//cout << s->isValidSerialization("1,#");
	cout << s->isValidSerialization("#");
	return 0;
}
*/
