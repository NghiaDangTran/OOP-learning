/**
 * DangNghiaA1
 *
 * Comp 2150 Section A02 Assignment: 4
 *
 * @author Nghia Dang( 7863117)
 *
 *
 *        this is the Hash_table class
 */




let linked_list = require("./linked_list");

class Hash_table {
    #table;// the array in side
    #size;// the size of the table
    #currSize;// current size of the table

    // ==============================================================
    // Hash_table constructor
    //
    // PURPOSE: this is a constructor for the Hash_table class
    //
    // parameter: the size of the table
    // return: nonce
    // ==============================================================
    constructor(size) {
        this.#table = new Array(size);// make the array
        this.#currSize = 0;
        this.#size = size;
    }
    // ==============================================================
    // hash function
    //
    // PURPOSE: this will get get the hash from data then return the position
    //
    // parameter: hashablle
    // return: nonce
    // ===============================================================

    hash(data) {
        let hash_val = data.hashVal();
        return hash_val % this.#size;
    }
    // ==============================================================
    // print function
    //
    // PURPOSE: this will print the table
    //
    // parameter: none
    // return: nonce
    // ===============================================================
    print() {
        for (let i = 0; i < this.#size; i++) {
            if (this.#table[i] != null) {
                for (let j = 0; j < this.#table[i].length; j += 2) {
                    console.log(this.#table[i][j] + " " + this.#table[i][j + 1].getTop().getDatNode());
                }
            }


        }
    }
    // ==============================================================
    // toDict function
    //
    // PURPOSE: this will convert the table to a dictionary 
    //
    // parameter: none
    // return: nonce
    // ===============================================================
    toDict() {
        let dict = {};
        for (let i = 0; i < this.#size; i++) {
            if (this.#table[i] != null) {
                for (let j = 0; j < this.#table[i].length; j += 2) {
                    dict[this.#table[i][j]] = this.#table[i][j + 1].getTop().getDatNode();
                }
            }


        }
        return dict;
    }
    // ==============================================================
    // put function
    //
    // PURPOSE: this will put the data into the table 
    //
    // parameter: key with the value
    // return: nonce
    // ===============================================================

    put(k, v) {

        let index = k.hashVal(this.#size);
        // get the index
        if (this.#table[index] == null) {
            this.#table[index] = [];
            this.#table[index].push(k.getData());


            this.#table[index][1] = new linked_list();


            this.#table[index][1].insertL(v);

        } else {
            // check the this.#table[index][ this.#table[index].length] is the same as k.getData()
            let at = -1;
            for (let i = 0; i < this.#table[index].length; i += 2) {
                if (this.#table[index][i] == k.getData()) {
                    at = i;
                }
            }
            // if it is the same then add new v to the linked list
            if (at != -1) {
                this.#table[index][at + 1].insertL(v);
            }
            else {
                // orther wise add new k and v to the table
                this.#table[index].push(k.getData());
                this.#table[index].push(new linked_list());
                this.#table[index][this.#table[index].length - 1].insertL(v);

            }




        }





    }
    // ==============================================================
    // updatePercentage function
    //
    // PURPOSE: this will update the percentage of the table
    //
    // parameter: length of the data
    // return: nonce
    // ==============================================================
    updatePercentage(lenData) {
        for (let i = 0; i < this.#size; i++) {
            if (this.#table[i] != null) {

                for (let j = 0; j < this.#table[i].length; j += 2) {

                    let a = this.#table[i][j + 1].getTop().getDatNode()
                    this.#table[i][j + 1].insertL(a / lenData);
                    // the top will contain the percentage of the data
                }
            }


        }

    }
    // ==============================================================
    // get function
    //
    // PURPOSE: return the value of the key
    //
    // parameter: key
    // return: nonce or undefined if not found
    // ==============================================================
    get(k) {
        let index = k.hashVal(this.#size);
        if (this.#table[index] == null) {
            return undefined;
        }
        else {
            let at = -1;
            for (let i = 0; i < this.#table[index].length; i += 2) {
                if (this.#table[index][i] == k.getData()) {
                    at = i;
                }
            }
            if (at != -1) {
                return this.#table[index][at + 1].getTop().getDatNode();
            }
            else {
                return undefined;
            }

        }

    }
    // ==============================================================
    // contains function
    //
    // PURPOSE: return true if the key is in the table
    // parameter: key
    // return: true or false
    // ==============================================================
    contains(k) {
        return this.get(k) != null;
    }
    // ==============================================================
    // isEmpty function
    //
    // PURPOSE: return true if the table is empty
    // parameter: none
    // return: true or false
    // ==============================================================
    isEmpty() {
        return this.#currSize == 0;
    }
}
module.exports = Hash_table;
