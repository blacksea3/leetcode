#include "public.h"

//
//找规律:
//首先把矩形按照边长sideLength分掉, 看看还剩下多少
//分掉的每个正方形使用maxOnes的1
//剩下的能用就用
//注意使用的1相对位置是一样的

class Solution {
public:
	int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
		int lineNum = height / sideLength;
		int lineRem = height % sideLength;
		int colNum = width / sideLength;
		int colRem = width % sideLength;

		int res = lineNum * colNum*maxOnes;

		//对于剩余图形: 右边: colRem*sideLength, 下面:lineRem*sideLength, 右下角:colRem*lineRem
		//寻找一个最大的公共图形

		if (maxOnes <= colRem * lineRem)
		{
			res += (lineNum + colNum + 1)*maxOnes;
		}
		else
		{
			//选择
			res += colRem * lineRem;
			if (lineNum > colNum)
			{
				//先放右面
				if (maxOnes <= colRem * sideLength)
				{
					res += lineNum * (maxOnes);
					res += colNum * colRem * lineRem;
				}
				else
				{
					//下面也能放但不满
					if (maxOnes <= lineRem * sideLength + colRem * sideLength - colRem * lineRem)
					{
						res += lineNum * colRem * sideLength;
						res += colNum * (maxOnes - colRem * sideLength + colRem * lineRem);
					}
					//都能放满
					else
					{
						res += lineNum * colRem * sideLength;
						res += colNum * lineRem* sideLength;
					}
				}
			}
			else
			{
				//先放下面
				if (maxOnes <= lineRem * sideLength)
				{
					res += colNum * (maxOnes);
					res += lineNum * colRem * lineRem;
				}
				else
				{
					//下面也能放但不满
					if (maxOnes <= lineRem * sideLength + colRem * sideLength - colRem * lineRem)
					{
						res += colNum * lineRem * sideLength;
						res += lineNum * (maxOnes - lineRem * sideLength + colRem * lineRem);
					}
					//都能放满
					else
					{
						res += colNum * lineRem * sideLength;
						res += lineNum * colRem * sideLength;
					}
				}
			}
		}
		return res;
	}
};

int main()
{
	Solution* s = new Solution();
	cout << s->maximumNumberOfOnes(74, 52, 10, 77) << endl;
	cout << s->maximumNumberOfOnes(10, 10, 4, 5) << endl;
	cout << s->maximumNumberOfOnes(3,3,2,2) << endl;
	return 0;
}
