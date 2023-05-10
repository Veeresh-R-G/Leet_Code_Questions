/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    
    let N = nums.length;
    let ans = init;
    // console.log(fn);
    for(let i = 0 ; i < N ; i++)
    {
        ans = fn(ans , nums[i]);
    }
    
    return ans;
    
};