/**
 * DangNghiaA1
 *
 * Comp 2150 Section A02 Assignment: 4
 *
 * @author Nghia Dang( 7863117)
 *
 *
 *        this is the Hashable abstact class
 */


// ==========================================================
// Hashable class
//
//
//
//
// PURPOSE: this is the abstract class for the hashable
//
// ==========================================================
class Hashable {
    //  privtare value
    #val;

    // ==============================================================
    // Hashable constructor
    //
    // PURPOSE: this is a constructor for the hashable class
    //
    // parameter: the vale of the hashable
    // return: nonce
    // ==============================================================
    constructor(val) {
        if (this.constructor.name === "Hashable") {
            throw new Error("Class Hashable is abstract and cannot be instantiated.");
        }
        // if the name of the class is not Hashable then throw error
        this.#val = val;


    }
    // ==============================================================
    // hashVal function
    //
    // PURPOSE: none for abstract class
    //
    // parameter: none
    // return: nonce
    // ==============================================================
    hashVal(size) {

        throw new Error("Class Hashable is abstract and cannot be instantiated.");



    }
    // ==============================================================
    // getData function
    //
    // PURPOSE: none for abstract class , but return the value of for inherited class
    //
    // parameter: none
    // return: nonce
    // ==============================================================
    getData() {
        if (this.constructor.name === "Hashable") {
            throw new Error("Class Hashable is abstract and cannot be instantiated.");
        }

        return this.#val;
    }
    // ==============================================================
    // equal function
    //
    // PURPOSE: none for abstract class
    //
    // parameter: orther hashable
    // return: nonce
    // ==============================================================
    equal(orther) {
        throw new Error("Class Hashable is abstract and cannot be instantiated.");
    }

    // ==============================================================
    // toString function
    //
    // PURPOSE: none for abstract class, but return the value of for inherited class
    //
    // parameter: none
    // return: nonce
    // ==============================================================

    toString() {
        if (this.constructor.name === "Hashable") {
            throw new Error("Class Hashable is abstract and cannot be instantiated.");
        }
        return "This val is " + this.#val + ".";
    }

}
// export the class
module.exports = Hashable;


