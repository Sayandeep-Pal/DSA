/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function (arr1, arr2) {
    var items = arr1.concat(arr2);

    var res = {};

    for (var obj of items)
        {
            if(!res[obj.id])
            {
            res[obj.id] = obj;
        }
        
        res[obj.id] = { ...res[obj.id], ...obj };
}

return Object.values(res)
};