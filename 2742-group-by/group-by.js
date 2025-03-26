/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
    var res={};
    this.forEach(ele =>{
        var key = fn(ele);
        res[key] ? res[key].push(ele) : res[key] =[ele];
    })
    return res;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */