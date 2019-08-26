
/*
不推荐, 暴力O(n^2*m^2)
9536ms, 11.11%
*/

/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {number}
 */
var numSubmatrixSumTarget = function(matrix, target) {
    var res = 0;
    
    var sumCol = new Array(matrix.length);
    for (var row = 0; row < matrix.length; ++row) {
        sumCol[row] = new Array();
		sumCol[row][0] = 0;
        for (var col = 0; col < matrix[0].length; ++col)
        {
            sumCol[row][col + 1] = sumCol[row][col] + matrix[row][col];
        }
    }	
	
    for(let leftCol = 0; leftCol < matrix[0].length; leftCol++)
    {
        for (let rightCol = leftCol; rightCol < matrix[0].length; rightCol++)
        {
            for (let upRow = 0; upRow < matrix.length; upRow++)
            {
				var presum = sumCol[upRow][rightCol + 1] - sumCol[upRow][leftCol];
                if (presum == target)
                    res++;
                for (let downRow = upRow + 1; downRow < matrix.length; downRow++)
                {
					presum += sumCol[downRow][rightCol + 1] - sumCol[downRow][leftCol];
                if (presum == target)
                    res++;
                }
            }
        }
    }
    return res;
};