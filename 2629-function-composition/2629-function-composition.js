/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    
	return function(x) {
        
        if(functions.length === 0)
        {
            return x;
        }
        
        let N = functions.length;
        let ans = x;
        
        for(let i = N - 1 ; i >= 0 ; i--)
        {
            ans = functions[i](ans);
        }
        
        return ans;
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */