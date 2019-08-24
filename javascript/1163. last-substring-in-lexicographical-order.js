/*
不推荐, 暴力O(n^2)
1212ms, 23.33%
*/

/**
 * @param {string} s
 * @return {string}
 */
var lastSubstring = function(s) {
    var sSize = s.length;
    var res = s;
    
    for(var index = 1; index < sSize; index++)
        {
            var next = s.slice(index);
            if (next > res)
                res = next;
        }
    return res;
};
