
/**
 * DangNghiaA1
 *
 * Comp 2150 Section A02 Assignment: 4
 *
 * @author Nghia Dang( 7863117)
 *
 *
 *        this is the Node class
 */


// ==========================================================
// Node class
//
//
//
//
// PURPOSE: Node data for the linked list
//
// ==========================================================

class Node {
    // ==============================================================
    // basic node class like orther project
    //
    // ==============================================================
    #data; // hashable
    #next;// node

    constructor(data, next) {

        this.#data = data;
        this.#next = next;

    }

    getDatNode() {
        return this.#data;

    }
    setData(data) {
        this.#data = data;
    }

    getNext() {
        return this.#next;
    }




}

module.exports = Node;


