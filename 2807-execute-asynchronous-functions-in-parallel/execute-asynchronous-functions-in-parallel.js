/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function (functions) {
    // return new Promise((res, rej) => {
    //     const result = new Array(functions.length);
    //     let count = 0;
    //     functions.forEach((fn, i) => {
    //         fn()
    //             .then(val => {
    //                 result[i] = val
    //                 count++;
    //                 if (count === functions.length) resolve(result);
    //             })
    //             .catch(err => rej(err));
    //     });
    // });


    return new Promise((resolve, reject) => {
        // We know the resulting array will be the same length as functions
        const results = new Array(functions.length);
        let count = 0;
        functions.forEach((fn, i) => {
            fn()
            .then(val => {
                results[i] = val;
                count++;
                if(count === functions.length) resolve(results);
            })
            .catch(reason => reject(reason));
        });
    });
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */