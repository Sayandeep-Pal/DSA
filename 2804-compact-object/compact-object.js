/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function (obj) {
    var isArray = Array.isArray(obj);
    var res = isArray ? [] : {};

    if (isArray) {
        for(let i = 0; i < obj.length; i++) {
            const el = obj[i];
            if (Array.isArray(el) || (el !== null && typeof el === "object"))
                res.push(compactObject(el));
            else if (el) res.push(el);
        }

    }
    else if (!isArray) {
        for (let key in obj) {
      const el = obj[key];
      if (Array.isArray(el) || (el !== null && typeof el === "object"))
        res[key] = compactObject(el);
      else if (el) res[key] = el;
    }
    }
    return res;
};