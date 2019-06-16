#include "public.h"

//DC problem: divide and conquer, 204ms, 84.36%

// Definition for a QuadTree node.
class Node {
public:
	bool val;
	bool isLeaf;
	Node* topLeft;
	Node* topRight;
	Node* bottomLeft;
	Node* bottomRight;

	Node() {}

	Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
		val = _val;
		isLeaf = _isLeaf;
		topLeft = _topLeft;
		topRight = _topRight;
		bottomLeft = _bottomLeft;
		bottomRight = _bottomRight;
	}
};

class Solution {
private:
	Node* recu_construct(vector<vector<int>>& grid, int startrow, int startcolumn, int linelen)
	{
		bool isAllconstant = true;
		bool firstval;
		int firstvali = grid[startrow][startcolumn];
		if (grid[startrow][startcolumn]) firstval = true;
		else firstval = false;
		for (int row = startrow; row < startrow + linelen; ++row)
		{
			for (int column = startcolumn; column < startcolumn + linelen; ++column)
			{
				if (firstvali != grid[row][column])
				{
					isAllconstant = false;
					goto end;
				}
			}
		}
	end:
		if (isAllconstant)
		{
			Node* newn = new Node(firstval, true, nullptr, nullptr, nullptr, nullptr);
			return newn;
		}
		else
		{
			Node* topLeft = recu_construct(grid, startrow, startcolumn, linelen / 2);
			Node* topRight = recu_construct(grid, startrow, startcolumn + linelen / 2, linelen / 2);
			Node* bottomLeft = recu_construct(grid, startrow + linelen / 2, startcolumn, linelen / 2);
			Node* bottomRight = recu_construct(grid, startrow + linelen / 2, startcolumn + linelen / 2, linelen / 2);
			Node* newn = new Node(firstval, false, topLeft, topRight, bottomLeft, bottomRight);
			return newn;
		}
	}

public:
	Node* construct(vector<vector<int>>& grid) {
		return recu_construct(grid, 0, 0, grid.size());
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<vector<int>> grid = {{1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}};
	Node* res = s->construct(grid);
	return 0;
}
*/