#pragma once

#include <iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include <string>
#include <strstream>
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
