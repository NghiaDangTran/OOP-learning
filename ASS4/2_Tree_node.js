/**
 * DangNghiaA1
 *
 * Comp 2150 Section A02 Assignment: 4
 *
 * @author Nghia Dang( 7863117)
 *
 *
 *        this is the Tree_node class
 */



class Tree_node {
    #freq;//int
    #data;//char
    #encoding;//str
    #left;//Tree_node
    #right;//Tree_node


    // ==============================================================
    // Tree_node constructor
    //
    // PURPOSE: this is a constructor for the Tree_node class
    //
    // parameter: frquency, data, left, right
    // return: nonce
    // ============= =================================================
    constructor(freq, data, left, right) {
        this.#freq = freq;
        this.#data = data;
        this.#left = left;
        this.#right = right;
        this.#encoding = null;//set the encoding to null
    }
    // ==============================================================
    // getEncoding function
    //
    // PURPOSE: return the encoding of the node
    //
    // parameter: none
    // return: nonce
    // ==============================================================

    getEncoding() {
        return this.#encoding;
    }
    // ==============================================================
    // setEncoding function
    //
    // PURPOSE: set the encoding of the node
    //
    // parameter: the encoding
    // return: nonce
    // ==============================================================
    setEncoding(encoding) {

        this.#encoding = encoding;
    }
    // ==============================================================
    // compare function
    //
    // PURPOSE: compare the data of the node by the frequency
    //
    // parameter: the node to compare
    // return: nonce
    // ==============================================================
    compare(other) {
        if (this.#freq > other.getFreq()) {
            return 1;
        }
        else if (this.#freq < other.getFreq()) {
            return -1;
        }
        else {
            return 0;
        }
    }
    // ==============================================================
    // getFreq function
    //
    // PURPOSE: return the frequency of the node
    //
    // parameter: none
    // return: nonce
    // ==============================================================
    getFreq() {
        return this.#freq;
    }
    // ==============================================================
    // getdata function
    //
    // PURPOSE: return the data of the node
    //
    // parameter: none
    // return: nonce
    // ==============================================================
    getdata() {
        return this.#data;

    }

    // ==============================================================
    // getLeft function
    //
    // PURPOSE: return the left node of the node
    //
    // parameter: none
    // return: nonce
    // ==============================================================
    getLeft() {
        return this.#left;
    }
    // ==============================================================
    // getRight function
    //
    // PURPOSE: return the right node of the node
    //
    // parameter: =none
    // return: nonce
    // ==============================================================
    getRight() {
        return this.#right;
    }
    // ==============================================================
    // setL function
    //
    // PURPOSE: set the left node of the node
    // parameter: the left node
    // return: nonce
    // ==============================================================
    setL(left) {
        this.#left = left;
    }
    // ==============================================================
    // setR function
    //
    // PURPOSE: set the right node of the node
    //
    // parameter: the right node
    // return: nonce
    // ==============================================================
    setR(right) {
        this.#right = right;
    }

}

module.exports = Tree_node;