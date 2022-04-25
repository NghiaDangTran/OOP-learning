/**
 * DangNghiaA1
 *
 * Comp 2150 Section A02 Assignment: 4
 *
 * @author Nghia Dang( 7863117)
 *
 *
 *        this is the linked_list class
 */


// ==========================================================
// linked_list class
//
//
//
//
// PURPOSE: this is the class for the linked_list
//
// ==========================================================

let Node = require("./Node");

class linked_list {

    #top;// node
    #size;// int
    // ==============================================================
    // linked_list constructor
    //
    // PURPOSE: this is a constructor for the linked_list
    //
    // parameter:none
    // return: nonce
    // ==============================================================

    constructor() {
        this.#top = null;
        this.#size = 0;
    }
    // ==============================================================
    // getSize function
    //
    // PURPOSE: return the size of the linked list
    //
    // parameter: none
    // return: nonce
    // ==============================================================

    getSize() {
        return this.#size;
    }

    // ==============================================================
    // insertL function
    //
    // PURPOSE: insert the data to the linked list
    //
    // parameter: anoher hashable
    // return: nonce
    // ==============================================================
    insertL(data) {

        // console.log(data);

        this.#top = new Node(data, this.#top);
        this.#size++;
    }
    // ==============================================================
    // printList function
    //
    // PURPOSE: print the linked list
    //
    // parameter: none
    // return: nonce
    // ==============================================================
    printList() {
        let Str = "";
        let current = this.#top;
        while (current != null) {
            Str += "\'" + current.getDatNode() + "\' ";

            current = current.getNext();
        }

        console.log(Str);


    }
    // ==============================================================
    // getTop function
    //
    // PURPOSE: return the top of the linked list
    //
    // parameter: none
    // return: nonce
    // ==============================================================
    getTop() {
        return this.#top;
    }
    // ==============================================================
    // inside function
    //
    // PURPOSE: check if the data is inside the linked list
    //
    // parameter: data
    // return: nonce
    // ==============================================================
    inside(data) {
        let current = this.#top;
        while (current != null) {
            // console.log((current.getDatNode()).equal(data));
            if ((current.getDatNode()) == (data)) {
                return true;
            }
            current = current.getNext();
        }
        return false;
    }

}


module.exports = linked_list;