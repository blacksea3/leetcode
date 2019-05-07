#include "public.h"
#include "leetcode.h"

#ifdef LEETCODE_111_120

int Solution::minDepth(TreeNode * root)
{
	//维护两个vector<TreeNode*> pre_t1,pre_t2;
    //维护一个vector<vector<int>> total_res
    //维护一个vector<int> pre_res

	if (root == nullptr) return 0;

	vector<TreeNode*> pre_t1, pre_t2;

	vector<int> pre_res;

	bool ist1valid = true;
	int depth = 0;
	bool isleftson_null = false;

	pre_t1.push_back(root);

	while (true)
	{
		depth++;
		if (ist1valid)
		{
			pre_t2.clear();
			for (auto tn : pre_t1)
			{
				isleftson_null = false;
				if (tn->left)
				{
					pre_t2.push_back(tn->left);
				}
				else
				{
					isleftson_null = true;
				}
				if (tn->right)
				{
					pre_t2.push_back(tn->right);
				}
				else if (isleftson_null)
				{
					goto end;
				}
				else;
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
				isleftson_null = false;
				if (tn->left) 
				{
					pre_t1.push_back(tn->left);
				}
				else
				{
					isleftson_null = true;
				}
				if (tn->right)
				{
					pre_t1.push_back(tn->right);
				}
				else if (isleftson_null)
				{
					goto end;
				}
				else;
			}
			ist1valid = true;
			if (pre_t1.empty()) break;
		}
	}
	end:
	return depth;
}

#else
#endif
