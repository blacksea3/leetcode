#pragma once

#include <iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include <string>
#include <strstream>
#include<stack>
#include <unordered_set>

using namespace std;

/**
 * Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//37
struct SudokuInfo
{
	int row;
	int column;
	vector<char> remaining_numbers;
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}	
};

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() {}

	Node(int _val, Node* _left, Node* _right, Node* _next) {
		val = _val;
		left = _left;
		right = _right;
		next = _next;
	}
};
