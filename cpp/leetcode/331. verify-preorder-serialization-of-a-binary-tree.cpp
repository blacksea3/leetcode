#include "BinaryTree.h"

//8ms, 87.56%
//��δ����֮ǰ, ��ȡ���Ľڵ�����Ӧ����Ҷ�ӽڵ�����
//����ʱҶ������Ӧ���ڽڵ�����

class Solution {
public:
	bool isValidSerialization(string preorder) {
		//��������
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
