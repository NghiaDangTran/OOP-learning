
let Hashable = require("./hashVal");


class StringHash extends Hashable {
    #prime= 53;

    constructor(data) {
        // if val is number throw error
        if (typeof data !== "string") {
            throw new Error("data must be a string");
        }
       
      
        super(data);
    }

    hashVal(size) {
        let data=super.getData();
        
        let result = 0;
        for (let i = 0; i < data.length; i++) {
            let char = data.charCodeAt(i);
            result += (char * Math.pow(this.#prime, data.length-i))%size;

        }   





        return result%size;
    }

    equal(orther) {
        // check the type of the orther


        if (this.getData() === orther.getData()) {
            return true;
        }
        return false;

    }

}

module.exports = StringHash;

// function test() {
//     let objectA = new StringHash("anh va em");
//     console.log(objectA.getData());
//     console.log(objectA.hashVal(10));



  

// }

// test();