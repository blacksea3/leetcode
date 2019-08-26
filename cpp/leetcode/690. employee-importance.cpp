#include "public.h"

//64ms, 38.50%
//BFS
//此图不会有环, 因为一个员工最多有一个直系领导

// Employee info
class Employee {
public:
	// It's the unique ID of each node.
	// unique id of this employee
	int id;
	// the importance value of this employee
	int importance;
	// the id of direct subordinates
	vector<int> subordinates;
};

class Solution {
public:
	int getImportance(vector<Employee*> employees, int id) {
		unordered_map<int, Employee*> um_employees;
		for (auto& employee : employees)
			um_employees[employee->id] = employee;

		vector<int> current;
		int sum = 0;
		current.push_back(id);

		while (!current.empty())
		{
			vector<int> next;
			for (auto& employeeid : current)
			{
				sum += um_employees[employeeid]->importance;
				for (auto& sub : um_employees[employeeid]->subordinates)
				{
					next.push_back(sub);
				}
			}
			current = next;
		}
		return sum;
	}
};
