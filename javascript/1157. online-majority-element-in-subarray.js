/*
暴力, O(nm), n:arr大小, m:查询次数
不建议
4128ms, 6.67%
*/

/**
 * @param {number[]} arr
 */
var MajorityChecker = function(arr) {
    this.m_arr = arr;
};

/** 
 * @param {number} left 
 * @param {number} right 
 * @param {number} threshold
 * @return {number}
 */
MajorityChecker.prototype.query = function(left, right, threshold) {
    var ans = this.m_arr[left];
	var flag = 1;
	for (var i = left + 1; i <= right; i++)
	{
		if (flag > 0)
		{
			if (ans == this.m_arr[i])
				flag++;
			else
				flag--;
		}
		else
		{
			flag = 1;
			ans = this.m_arr[i];
		}
	}
	
	var num = 0;
	for (var i = left; i <= right; i++)
	{
		if (ans == this.m_arr[i])
			num++;
	}
	
	if (num >= threshold) return ans;
	else return -1;
};

/** 
 * Your MajorityChecker object will be instantiated and called as such:
 * var obj = new MajorityChecker(arr)
 * var param_1 = obj.query(left,right,threshold)
 */