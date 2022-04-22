


class Node {
    #data; // hashable
    #next;// node

    constructor(data, next) {
        // check data is number or string
        // if (typeof data !== "Str" || typeof data !== "IntHash") {
        //     throw new Error("data must be a string or number");
        // }

        // // check next is Node or null
        // if (next !== null || !(next instanceof Node)) {
        //     throw new Error("next must be a Node or null");
        // }
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


