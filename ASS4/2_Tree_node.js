class Tree_node {
    #freq;//int
    #data;//char
    #encoding;
    #left;//Tree_node
    #right;//Tree_node

    constructor(freq, data, left, right) {
        this.#freq = freq;
        this.#data = data;
        this.#left = left;
        this.#right = right;
        this.#encoding =null;
    }
    getEncoding() {
        return this.#encoding;
    }

    setEncoding(encoding) {

        this.#encoding = encoding;
    }

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

    getFreq() {
        return this.#freq;
    }
    getdata() {
        return this.#data;

    }


    getLeft() {
        return this.#left;
    }
    getRight() {
        return this.#right;
    }

    setL(left) {
        this.#left = left;
    }
    setR(right) {
        this.#right = right;
    }

}

module.exports = Tree_node;