let Hashable = require("./hashVal");
class IntHash extends Hashable {
    constructor(val) {
        // if val is not a number throw error
        
        if (typeof val !== "number") {
            throw new Error("val must be a number");
        }
        super(val);
    }
    hashVal(size) {
       
        return super.getData()%size;
    }
    equal(orther) {
        // check the type of the orther


        if (this.getData() === orther.getData()) {
            return true;
        }
        return false;

    }
}

module.exports = IntHash;



