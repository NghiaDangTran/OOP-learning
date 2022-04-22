let Node = require("./Node");
let StringHash = require("./StringHash");
let IntHash = require("./IntHash");
let Hashable = require("./hashVal");
class linked_list {

    #top;// node
    #size;// int

    constructor() {
        this.#top = null;
        this.#size = 0;
    }

    getSize() {
        return this.#size;
    }


    insertL(data) {
   
        // console.log(data);

        this.#top = new Node(data, this.#top);
        this.#size++;
    }

    printList() {
        let Str="";
        let current = this.#top;
        while (current != null) {
            Str+="\'"+current.getDatNode()+"\' ";
           
            current = current.getNext();
        }

        console.log(Str);


    }

    getTop() {
        return this.#top;
    }
    inside(data) {
        let current = this.#top;
        while (current != null) {
            // console.log((current.getDatNode()).equal(data));
            if ((current.getDatNode())==(data)) {
                return true;
            }
            current = current.getNext();
        }
        return false;
    }

}


module.exports = linked_list;