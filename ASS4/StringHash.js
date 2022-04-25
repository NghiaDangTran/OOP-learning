/**
 * DangNghiaA1
 *
 * Comp 2150 Section A02 Assignment: 4
 *
 * @author Nghia Dang( 7863117)
 *
 *
 *        this is the StringHash class
 */


// ==========================================================
// StringHash class
//
//
//
//
// PURPOSE: this is the class for the StringHash hash
//
// ==========================================================
let Hashable = require("./hashVal");


class StringHash extends Hashable {
    #prime= 53;// set a prive prime number
     // ==============================================================
    // StringHash constructor
    //
    // PURPOSE: this is a constructor for the StringHash class
    //
    // parameter: the vale of the hashable
    // return: nonce
    // ==============================================================
    constructor(data) {
        // if the data is not a string then throw error
        if (typeof data !== "string") {
            throw new Error("data must be a string");
        }
       
      
        super(data);
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
        let data=super.getData();
        
        let result = 0;
        for (let i = 0; i < data.length; i++) {
            let char = data.charCodeAt(i);
            result += (char * Math.pow(this.#prime, data.length-i))%size;

        }   





        return result%size;
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
        // check the type of the orther


        return this.getData() === orther.getData();

    }

}

module.exports = StringHash;

// function test() {
//     let objectA = new StringHash("anh va em");
//     console.log(objectA.getData());
//     console.log(objectA.hashVal(10));



  

// }

// test();