// leetcode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include "leetcode.h"

#ifdef LEETCODE_01_10
void test1(Solution s)
{
	vector<int> input = vector<int>{ 1, 2, 5, 6 };

	vector<int> res = s.twoSum(input, 6);
	for (vector<int>::const_iterator iter = res.cbegin(); iter != res.cend(); iter++)
	{
		cout << (*iter) << " ";
	}
	cout << endl;
}

void test2(Solution s)
{
	ListNode* l1 = s.initlistnode(vector<int>{2, 4, 3});
	ListNode* l2 = s.initlistnode(vector<int>{5, 6, 4});
	s.printlistnode(l1);
	s.printlistnode(l2);
	s.printlistnode(s.addTwoNumbers(l1, l2));
}

void test3(Solution s)
{
	cout << s.lengthOfLongestSubstring(string{ "1asdas" });
}

void test4(Solution s)
{
	vector<int> v1 = vector<int>{1,2};
	vector<int> v2 = vector<int>{3,4};
	cout << s.findMedianSortedArrays(v1, v2);
}

void test5(Solution s)
{
	string res = s.longestPalindrome(string{ "babad" });

	char* b = (char*)res.c_str();
	cout << b;

	string res2 = s.longestPalindrome(string{ "abbd" });

	char* b2 = (char*)res2.c_str();
	cout << b2;
}

void test6(Solution s)
{
	string res2 = s.convert(string{ "PAYPALISHIRING" }, 3);

	char* b2 = (char*)res2.c_str();
	cout << b2;
}

void test7(Solution s)
{
	cout << s.reverse(-123);   //?日,为什么无法测试-2147483648
}

void test8(Solution s)
{
	cout << s.myAtoi("   -42");
}

void test9(Solution s)
{
	cout << s.isPalindrome(21);
}

void test10(Solution s)
{
	cout << s.isMatch("mississippi", "mis*is*ip*.");
}
#else
#endif

#ifdef LEETCODE_11_20
void test11(Solution s)
{
	vector<int> v2 = vector<int>{ 1,1 };
	cout << s.maxArea(v2);
}

void test12(Solution s)
{
	string res2 = s.intToRoman(2134);

	char* b2 = (char*)res2.c_str();
	cout << b2;
}

void test13(Solution s)
{
	cout << s.romanToInt("III");
}

void test14(Solution s)
{
	vector<string> strs = { "a","b" };

	string res2 = s.longestCommonPrefix(strs);

	char* b2 = (char*)res2.c_str();
	cout << b2;
}

void test15(Solution s)
{
	vector<vector<int>> res;
	vector<int> ints = {-1,0,1,2,-1,-4};
	res = s.threeSum(ints);
	int i = 1;
}

void test16(Solution s)
{
	vector<int> ints = { -1,2,1, - 4 };
	cout << s.threeSumClosest(ints, 1);
}

void test17(Solution s)
{
	vector<string> res;
	res = s.letterCombinations("23");
	int i = 0;
}

void test18(Solution s)
{
	vector<vector<int>> res;
	vector<int> ints = { 0,0,0,0 };
	res = s.fourSum(ints, 0);
	int i = 0;
}

void test19(Solution s)
{
	ListNode* l1 = s.initlistnode(vector<int>{1,2,3,4,5});
	s.printlistnode(l1);
	s.printlistnode(s.removeNthFromEnd(l1, 2));
}

void test20(Solution s)
{
	cout << s.isValid("()");
}
#else
#endif

#ifdef LEETCODE_21_30
void test21(Solution s)
{
	ListNode* l1 = s.initlistnode(vector<int>{1, 2, 4});
	ListNode* l2 = s.initlistnode(vector<int>{1, 3, 4});
	s.printlistnode(l1);
	s.printlistnode(l2);
	s.printlistnode(s.mergeTwoLists(l1, l2));
}

void test22(Solution s)
{
	vector<string> res;
	res = s.generateParenthesis(3);
	int i = 1;
}

void test23(Solution s)
{
	vector<ListNode*> lists;
	ListNode* l1 = s.initlistnode(vector<int>{1, 4, 5});
	ListNode* l2 = s.initlistnode(vector<int>{1, 3, 4});
	ListNode* l3 = s.initlistnode(vector<int>{2, 6});
	lists.push_back(l1);
	lists.push_back(l2);
	lists.push_back(l3);
	s.printlistnode(s.mergeKLists(lists));
}

void test24(Solution s)
{
	ListNode* l1 = s.initlistnode(vector<int>{1, 2, 3, 4});
	s.printlistnode(s.swapPairs(l1));
}

void test25(Solution s)
{
	ListNode* l1 = s.initlistnode(vector<int>{1, 2, 3, 4, 5});
	s.printlistnode(s.reverseKGroup(l1, 3));
}

void test26(Solution s)
{
	vector<int> input = {1,1,2};
	cout << s.removeDuplicates(input);
}

void test28(Solution s)
{
	cout << s.strStr("mississippi", "issip");
}

void test29(Solution s)
{
	cout << s.divide((int)1, 1);
}

void test30(Solution s)
{
	vector<string> strs = { "word","good","best","good" };
	vector<int> res = s.findSubstring("wordgoodgoodgoodbestword", strs);
	int i = 0;
}
#else
#endif

#ifdef LEETCODE_31_40
void test31(Solution s)
{
	vector<int> nums = { 1,5,1 };
	s.nextPermutation(nums);
	int i = 1;
}

void test32(Solution s)
{
	cout << s.longestValidParentheses(")()())");
}

void test33(Solution s)
{
	vector<int> nums = { 5,1,3 };
	cout << s.search(nums, 1);
}

void test34(Solution s)
{
	vector<int> nums = { 2,2 };
	vector<int> res = s.searchRange(nums, 3);
	int i = 1;
}

void test35(Solution s)
{
	vector<int> nums = { 1,3 };
	cout << s.searchInsert(nums, 3);
}

void test36(Solution s)
{
	vector<vector<char>> board = { {'5', '3', '5', '.', '7', '.', '.', '.', '.'},
	{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
	{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
	{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
	{'.', '.', '.', '.', '.', '5', '.', '.', '.'},
	{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
	{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
	{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
	{'.', '.', '.', '.', '8', '.', '.', '7', '9'} };
	cout << s.isValidSudoku(board);
}

void test37(Solution s)
{
	vector<vector<char>> board = { {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
	{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
	{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
	{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
	{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
	{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
	{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
	{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
	{'.', '.', '.', '.', '8', '.', '.', '7', '9'} };
	s.solveSudoku(board);
	int i = 1;
}

void test39(Solution s)
{
	vector<int> nums = { 6, 9, 7, 4, 5, 3, 10, 12 };
	vector<vector<int>> res = s.combinationSum(nums, 21);
	int i = 1;
}

void test40(Solution s)
{
	vector<int> nums = { 3, 5 };
	vector<vector<int>> res = s.combinationSum2(nums, 2);
	int i = 1;
}
#else
#endif

#ifdef LEETCODE_41_50
void test41(Solution s)
{
	vector<int> nums = { 3, 4, -1, 1 };
	cout << s.firstMissingPositive(nums);
}

void test42(Solution s)
{
	vector<int> nums = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	cout << s.trap(nums);
}

void test43(Solution s)
{
	string res = s.multiply("123456789", "987654321");
	char* b2 = (char*)res.c_str();
	cout << b2;
}

void test44(Solution s)
{
	cout << s.isMatch_44("aa", "a*a");
}

void test45(Solution s)
{
	vector<int> nums = { 2,1,1,1,1 };
	cout << s.jump(nums);
}

void test46(Solution s)
{
	vector<int> nums = { 1,2,3 };
	vector<vector<int>> res = s.permute(nums);
	int i = 1;
}

void test47(Solution s)
{
	vector<int> nums = { 1,1,2 };
	vector<vector<int>> res = s.permuteUnique(nums);
	int i = 1;
}

void test48(Solution s)
{
	vector<vector<int>> board = { {5, 1, 9,11},
  {2, 4, 8,10},
  {13, 3, 6, 7},
	{15,14,12,16} };
	s.rotate(board);
	int i = 1;
}

void test49(Solution s)
{
	vector<string> strs = { "eat","tea","tan","ate","nat","bat" };
	vector<vector<string>> res = s.groupAnagrams(strs);
	int i = 1;
}

void test50(Solution s)
{
	cout << s.myPow(1.0, -32323);
}
#else
#endif

#ifdef LEETCODE_51_60
void test51(Solution s)
{
	vector<vector<string>> res = s.solveNQueens(4);
	int i = 0;
}

void test52(Solution s)
{
	cout << s.totalNQueens(4);
}

void test53(Solution s)
{
	vector<int> nums = { 1,2 };
	cout << s.maxSubArray(nums);
}

void test54(Solution s)
{
	vector<vector<int>> matrix = {{ 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }};
	vector<int> res = s.spiralOrder(matrix);
	int i = 1;
}

void test55(Solution s)
{
	vector<int> nums = { 2,3,1,1,4 };
	cout << s.canJump(nums);
}

void test56(Solution s)
{
	vector<vector<int>> intervals = { { 1,3},{2,6},{8,10},{15,18} };
	vector<vector<int>> res = s.merge(intervals);
	int i = 1;
}

void test57(Solution s)
{
	vector<vector<int>> intervals = { { 1,2},{3,6},{8,10},{15,18} };
	vector<int> newInterval = { 4,9 };
	vector<vector<int>> res = s.insert(intervals, newInterval);
	int i = 1;
}

void test60(Solution s)
{
	cout << s.getPermutation(3, 3);
}

#else
#endif

#ifdef LEETCODE_61_70

void test61(Solution s)
{
	ListNode* head = s.initlistnode(vector<int> {1});
	s.printlistnode(s.rotateRight(head, 99));
}

void test62(Solution s)
{
	vector<vector<int>> obs = {
	{0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0},
{1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,1},
{0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0},
{0,0,0,1,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,0},
{1,0,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0},
{0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0},
{0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
{1,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1},
{0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,0},
{0,1,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0},
{0,1,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,1},
{1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,1,0,0,1,0,0,0,0,0,0},
{0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,1,1,0,1,0,0,0,0,1,1},
{0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,0,1},
{1,1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1},
{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0}
	
	};

	cout << s.uniquePathsWithObstacles(obs);
}

void test65(Solution s)
{
	cout << s.isNumber("2e+0");
}

void test67(Solution s)
{
	string res = s.addBinary("1010", "1011");
	int i = 1;
}

void test68(Solution s)
{
	vector<string> words = { "This", "is", "an", "example", "of", "text", "justification." };
	vector<string> res = s.fullJustify(words, 16);
	int i = 1;
}

#else
#endif

#ifdef LEETCODE_71_80
void test71(Solution s)
{
	string res = s.simplifyPath("/...");
	int i = 1;
}

void test73(Solution s)
{
	vector<vector<int>> matrix = { {0},{1} };
	s.setZeroes(matrix);
	int i = 1;
}

void test75(Solution s)
{
	vector<int> nums = { 2,0,1 };
	s.sortColors(nums);
	int i = 1;
}

void test76(Solution s)
{
	string res = s.minWindow("aaaaaaaaaaaabbbbbcdd", "abcdd");
	int i = 1;
}

void test77(Solution s)
{
	vector<vector<int>> res = s.combine(3,3);
	int i = 1;
}

void test78(Solution s)
{
	vector<int> nums = { 1,2,3 };
	vector<vector<int>> res = s.subsets(nums);
	int i = 1;
}

void test79(Solution s)
{
	vector<vector<char>> board = { {'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'} };
	bool res = s.exist(board, "SEE");
	int i = 1;
}

#else
#endif



int main()
{
	Solution s = Solution();
	test79(s);
}


