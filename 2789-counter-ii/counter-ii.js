/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    var num = init;
    return{
        increment: () =>{
            num++;
            return num;
        },
        decrement: ()=>{
            num--;
            return num;
        },
        reset: ()=>{
            num = init;
            return num;
        }
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */