/**
 * DangNghiaA1
 *
 * Comp 2150 Section A02 Assignment: 4
 *
 * @author Nghia Dang( 7863117)
 *
 *
 *        this is the IntHash class
 */


// ==========================================================
// IntHash class
//
//
//
//
// PURPOSE: this is the class for the int hash
//
// ==========================================================
let Hashable = require("./hashVal");
class IntHash extends Hashable {

    // ==============================================================
    // IntHash constructor
    //
    // PURPOSE: this is a constructor for the IntHash class
    //
    // parameter: the vale of the hashable
    // return: nonce
    // ============= =================================================
    constructor(val) {

        // if the name of the class is not IntHash then throw error
        if (typeof val !== "number") {
            throw new Error("val must be a number");
        }
        super(val);
        // call the super class constructor
    }
    // ==============================================================
    // hashVal function
    //
    // PURPOSE: return the hash value of the hashable
    //
    // parameter: size of the container
    // return: nonce
    // ==============================================================
    hashVal(size) {
        // return the hash value of the hashable
        return super.getData() % size;
    }
    // ==============================================================
    // equal function
    //
    // PURPOSE: return true if the hashable is equal to the other hashable
    //
    // parameter: orther hashable
    // return: nonce
    // ==============================================================
    equal(orther) {



        return this.getData() === orther.getData();

    }
}
// export the class
module.exports = IntHash;



