#pragma once

#include "public.h"
#include "include.h"

#ifdef LEETCODE_141_150
class LRUCache {
private:
	//放一个字典记录键:pair(值,链表位置)
	unordered_map<int, pair<int, list<int>::iterator>> LRUpair;
	//放一个双向链表记录:链表值(头部的链表是最少使用的)
	list<int> record;
	int prelen = 0;
	int i_capacity = 0;
public:
	LRUCache(int capacity) {
		//要求是O(1)时间
		prelen = 0;
		i_capacity = capacity;
	}

	int get(int key) {
		if (LRUpair.find(key) != LRUpair.end())
		{
			list<int>::iterator loc = LRUpair[key].second;
			int value = LRUpair[key].first;
			record.erase(loc);
			record.push_front(key);
			LRUpair[key] = pair<int, list<int>::iterator>{ value,record.begin() };
			return value;
		}
		else
			return -1;
	}

	void put(int key, int value) {
		//如果存在
		if (get(key) != -1)
		{
			list<int>::iterator loc = LRUpair[key].second;
			record.erase(loc);
			record.push_front(key);
			LRUpair[key] = pair<int, list<int>::iterator>{ value,record.begin() };
		}
		else
		{
			if (prelen < i_capacity)
			{
				prelen++;
				record.push_front(key);
				LRUpair[key] = pair<int, list<int>::iterator>{ value,record.begin() };
			}
			else
			{
				LRUpair.erase(LRUpair.find(record.back()));
				record.pop_back();
				record.push_front(key);
				LRUpair[key] = pair<int, list<int>::iterator>{ value, record.begin() };
			}
		}
	}
};
#else
#endif

class Solution
{
public:
	void printlistnode(ListNode* input);
	ListNode* initlistnode(vector<int> input);
	TreeNode * initTreeNode(vector<int> input);





#ifdef LEETCODE_01_10
	////////////////////////////////////////////////////////////////////////////////////
//01-09
public:
	vector<int> twoSum(vector<int>& nums, int target);
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
	int lengthOfLongestSubstring(string s);
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
	string longestPalindrome(string s);
	string convert(string s, int numRows);
	int reverse(int x);
	int myAtoi(string str);
	bool isPalindrome(int x);
	//10
private:
	bool isMatchBlock(string s, string p);
	string shorter(string p);
	bool isMatchStar(string s, string p);
	bool isMatchSpace(string p);
public:
	bool isMatch(string s, string p);

private:
	bool isMatch_recall(string s, string p);
#else
#endif

#ifdef LEETCODE_11_20
public:
	//11
	int maxArea(vector<int>& height);
	//12
private:
	string stringMultiple(char c, int num);
public:
	string intToRoman(int num);
	//13
	int romanToInt(string s);
	//14
private:
	pair<bool, int> FindCommonPrefix(vector<string>& strs, int start, int end);
public:
	string longestCommonPrefix(vector<string>& strs);
	//15
	vector<vector<int>> threeSum(vector<int>& nums);
	//16
	int threeSumClosest(vector<int>& nums, int target);
	//17
	vector<string> letterCombinations(string digits);
	vector<string> letterCombinations_recall(string digits);
	//18
private:
	vector<vector<int>> three_sum_target(vector<int>& nums, int target, int startloc, int endloc);
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target);
	//19
	ListNode* removeNthFromEnd(ListNode* head, int n);
	//20
	bool isValid(string s);
#else
#endif

#ifdef LEETCODE_21_30
public:
	//21
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
	//22
	vector<string> generateParenthesis(int n);
	vector<string> generateParenthesis_recall(int n);
	//23
private:
	ListNode* iter_mergeKLists(vector<ListNode*>& lists, int startloc1, int startloc2);
public:
	ListNode* mergeKLists(vector<ListNode*>& lists);
	//24
	ListNode* swapPairs(ListNode* head);
	//25
	ListNode* reverseKGroup(ListNode* head, int k);
	//26
	int removeDuplicates(vector<int>& nums);
	//27
	int removeElement(vector<int>& nums, int val);
	//28
private:
	int strStr_next(string needle, int j);
public:
	int strStr(string haystack, string needle);
	//29
	int divide(int dividend, int divisor);
	//30
	vector<int> findSubstring(string s, vector<string>& words);
#else
#endif

#ifdef LEETCODE_31_40
public:
	//31
	void nextPermutation(vector<int>& nums);
	//32
	int longestValidParentheses(string s);
	//33
private:
	int iter_search(vector<int>& nums, int target, int startloc, int endloc);
	int binary_search(vector<int>& nums, int target, int startloc, int endloc);
public:
	int search(vector<int>& nums, int target);
	//34
private:
	int search_fix_right_border(vector<int>& nums, int target, int startloc, int endloc);
	int search_fix_left_border(vector<int>& nums, int target, int startloc, int endloc);
public:
	vector<int> searchRange(vector<int>& nums, int target);
	//35
	int searchInsert(vector<int>& nums, int target);
	//36
	bool isValidSudoku(vector<vector<char>>& board);
	//37
	void solveSudoku(vector<vector<char>>& board);
	//38
	string countAndSay(int n);
	//39
private:
	pair<bool, int> searchInsert_exam39(vector<int>& nums, int max_end_loc, int target);
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target);
	//40
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target);
#else
#endif

#ifdef LEETCODE_41_50
public:
	//41
	int firstMissingPositive(vector<int>& nums);
	//42
	int trap(vector<int>& height);
	//43
	string multiply(string num1, string num2);
	//44
	bool isMatch_44(string s, string p);
	//45
	int jump(vector<int>& nums);
	//46
	vector<vector<int>> permute(vector<int>& nums);
	//47
	vector<vector<int>> permuteUnique(vector<int>& nums);
	//48
	void rotate(vector<vector<int>>& matrix);
	//49
	vector<vector<string>> groupAnagrams(vector<string>& strs);
	//50
	double myPow(double x, int n);
#else
#endif

#ifdef LEETCODE_51_60
	//51
private:
	vector<string> generate_Queens_string(vector<int> input);
	vector<int> generate_Queens_nextlineloc(vector<int> input, int n);
public:
	vector<vector<string>> solveNQueens(int n);
	//52
public:
	int totalNQueens(int n);
	//53
	int maxSubArray(vector<int>& nums);
	//54
	vector<int> spiralOrder(vector<vector<int>>& matrix);
	//55
	bool canJump(vector<int>& nums);
	//56
private:
	bool LessEqSort(vector<int> a, vector<int> b);
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals);
	//57
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval);
	//58
	int lengthOfLastWord(string s);
	//59
	vector<vector<int>> generateMatrix(int n);
	//60
	string getPermutation(int n, int k);
#else
#endif

#ifdef LEETCODE_61_70
    //61
    ListNode* rotateRight(ListNode* head, int k);
	//62
	int uniquePaths(int m, int n);
	//63
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);
	//64
	int minPathSum(vector<vector<int>>& grid);
	//65
	bool isNumber(string s);
	//66
	vector<int> plusOne(vector<int>& digits);
	//67
	string addBinary(string a, string b);
	//68
private:
	string genstring_fullJustify(vector<string> words, int maxlength);
	string genlaststring_fullJustify(vector<string> words, int maxlength);
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth);
	//69
	int mySqrt(int x);
	//70
	int climbStairs(int n);
#else
#endif

#ifdef LEETCODE_71_80
public:
	//71
	string simplifyPath(string path);
	//72
	int minDistance(string word1, string word2);
	//73
	void setZeroes(vector<vector<int>>& matrix);
	//74
	bool searchMatrix(vector<vector<int>>& matrix, int target);
	//75
	void sortColors(vector<int>& nums);
	//76
	string minWindow(string s, string t);
	//77
	vector<vector<int>> combine(int n, int k);
	//78
	vector<vector<int>> subsets(vector<int>& nums);
	//79
private:
	vector<pair<int, int>> get_possible_locations(vector<vector<char>>& board, vector<vector<bool>>& boolboard, int m, int n, int i, int j, char ch);
public:
	bool exist(vector<vector<char>>& board, string word);
	//80
	int removeDuplicates(vector<int>& nums);
#else
#endif

#ifdef LEETCODE_81_90
    //81
private:
	int iter_search_81(vector<int>& nums, int target, int startloc, int endloc);
	int binary_search_81(vector<int>& nums, int target, int startloc, int endloc);
public:
	bool search_81(vector<int>& nums, int target);
	//82
	ListNode* deleteDuplicates(ListNode* head);
	//83
	ListNode* deleteDuplicates_83(ListNode* head);
	//84
	int largestRectangleArea(vector<int>& heights);
	//85
	int maximalRectangle(vector<vector<char>>& matrix);
	//86
	ListNode* partition(ListNode* head, int x);
	//87
	bool isScramble(string s1, string s2);
	//88
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
	//89
	vector<int> grayCode(int n);
	//90
	vector<vector<int>> subsetsWithDup(vector<int>& nums);
#else
#endif

#ifdef LEETCODE_91_100
public:
	//91
	int numDecodings(string s);
	//92
	ListNode* reverseBetween(ListNode* head, int m, int n);
	//93
	vector<string> restoreIpAddresses(string s);
	//94
	vector<int> inorderTraversal(TreeNode* root);
	//95
private:
	vector<TreeNode*> iter_gen_trees(int n, int m);
public:
	vector<TreeNode*> generateTrees(int n);
	//96
public:
	int numTrees(int n);
	//97
	bool isInterleave(string s1, string s2, string s3);
	//98
	bool isValidBST(TreeNode* root);
	//99
	void recoverTree(TreeNode* root);
	//100
	bool isSameTree(TreeNode* p, TreeNode* q);
#else
#endif

#ifdef LEETCODE_101_110
public:
	//101
	bool isSymmetric(TreeNode* root);
	//102
	vector<vector<int>> levelOrder(TreeNode* root);
	//103
	vector<vector<int>> zigzagLevelOrder(TreeNode* root);
	//104
	int maxDepth(TreeNode* root);
	//105
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
	//106
	TreeNode* buildTree_106(vector<int>& inorder, vector<int>& postorder);
	//107
	vector<vector<int>> levelOrderBottom(TreeNode* root);
	//108
private:
	TreeNode* iter_sortedArrayToBST(vector<int>& nums, int left, int right);
public:
	TreeNode* sortedArrayToBST(vector<int>& nums);
	//109
	TreeNode* sortedListToBST(ListNode* head);
	//110
private:
	int treeDepth(TreeNode* root);
public:
	bool isBalanced(TreeNode* root);
#else
#endif

#ifdef LEETCODE_111_120
public:
	//111
    int minDepth(TreeNode* root);
	//112
	bool hasPathSum(TreeNode* root, int sum);
	//113
	vector<vector<int>> pathSum(TreeNode* root, int sum);
	//114
	void flatten(TreeNode* root);
	//115
	int numDistinct(string s, string t);
	//116与117
	Node* connect(Node* root);
	//118
	vector<vector<int>> generate(int numRows);
	//119
	vector<int> getRow(int rowIndex);
	//120
	int minimumTotal(vector<vector<int>>& triangle);
#else
#endif

#ifdef LEETCODE_121_130
public:
	//121
	int maxProfit(vector<int>& prices);
	//122
	int maxProfit_122(vector<int>& prices);
	//123
	int maxProfit_123(vector<int>& prices);
	//124
private:
	static int res;
	int iter_maxPathSum(TreeNode* root);
public:
	int maxPathSum(TreeNode* root);
	//125
	bool isPalindrome(string s);
	//127
private:
	struct Node_127 { string id; vector<string> links; int level; };
	//之后再操作

private:
	vector<string> adjacent_string(string word, unordered_set<string>& wordList);
	bool onechar_different(string note, unordered_set<string>& wordList);
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList);
	//126,难度过高,跳过去

	//128
	int longestConsecutive(vector<int>& nums);
	//129
private:
	int sum;
	void iter_sumNumbres(TreeNode* root, int pre);
public:
	int sumNumbers(TreeNode* root);
	//130
	void solve(vector<vector<char>>& board);
#else
#endif

#ifdef LEETCODE_131_140
	//131
private:
	vector<vector<string>> res_131;
	vector<string> temp_131;
	bool is_partition(string s);
	void iter_partition(string s);
public:
	vector<vector<string>> partition(string s);
	//132
	int minCut(string s);
	//133
	Node_133 * cloneGraph(Node_133 * node);
	//134
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost);
	//135
	int candy(vector<int>& ratings);
	//136
	int singleNumber(vector<int>& nums);
	//137
	int singleNumber_137(vector<int>& nums);
	//138
	Node* copyRandomList(Node* head);
	//139
	bool wordBreak_139(string s, vector<string>& wordDict);
	//140
private:
	string generate_space_sentense(const vector<string>& input);
public:
	vector<string> wordBreak_140(string s, vector<string>& wordDict);
#else
#endif

#ifdef LEETCODE_141_150
public:
	//141
	bool hasCycle(ListNode *head);
	//142
	ListNode *detectCycle(ListNode *head);
	//143
	void reorderList(ListNode* head);
	//144
	vector<int> preorderTraversal(TreeNode* root);
	//145
	vector<int> postorderTraversal(TreeNode* root);
	//146是一个单独的class LRUCache
	//147
	ListNode* insertionSortList(ListNode* head);
	//148
private:
	ListNode* iter_sortList(ListNode* head);
public:
	ListNode* sortList(ListNode* head);
	//149
private:
	pair<int, int> iter_gcd(pair<int, int> input);
public:
	int maxPoints(vector<vector<int>>& points);
	//150
	int evalRPN(vector<string>& tokens);
#else
#endif

#ifdef LEETCODE_WC
public:
	//week 134
	//problem 2
	vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color);
	//week 135
	//problem 2
public:
	TreeNode* bstToGst(TreeNode* root);
	//problem 3
private:
	//int iter_minScoreTriangulation(vector<int>& A);
	int noborder(int num, int size);
public:
	int minScoreTriangulation(vector<int>& A);

	//week 136
	//problem 2
public:
	vector<int> gardenNoAdj(int N, vector<vector<int>>& paths);

#else
#endif

#ifdef LEETCODE_151_160
public:
	//151
	string reverseWords(string s);
	//152
	int maxProduct(vector<int>& nums);
	//153
private:
	int iter_findMin(vector<int>& nums, int start, int end);
public:
	int findMin(vector<int>& nums);
	//154
private:
	int iter_findMin_154(vector<int>& nums, int start, int end);
public:
	int findMin_154(vector<int>& nums);
	//160
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);


#else
#endif

};


