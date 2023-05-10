/**
 * @param {Function} fn
 * @return {Array}
 */
Array.prototype.groupBy = function(fn) {
    
    let ans = {};
    
    let N = this.length;
    
    for(let i = 0 ; i < N ; i++)
    {
        let key = fn(this[i]);
        let value = this[i];
        
        if(key in ans)
        {
            ans[key].push(value);
        }
        else
        {
            ans[key] = [value];
        }
        
       
        
    }
    return ans;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */