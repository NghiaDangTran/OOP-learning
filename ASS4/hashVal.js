const { type } = require("os");

// this will be abstract class
class Hashable { //  privtare value
    #val;

    constructor(val) {
        let size = arguments[1]
        if (this.constructor.name === "Hashable") {
            throw new Error("Class AbstractShape is abstract and cannot be instantiated.");
        }
        this.#val = val;


    }
    hashVal() {
       
            throw new Error("Class AbstractShape is abstract and cannot be instantiated.");
        

        return this.#val;
        // throw new Error("The hashVal method is abstract and needs an implementation in " + this.constructor.name);

    }
    getData()
    {

        return this.#val;
    }

    equal() {
        throw new Error("The equal method is abstract and needs an implementation in " + this.constructor.name);

    }

    toString() {
        return "This val is " + this.#val + ".";
    }

}

module.exports = Hashable;


// 