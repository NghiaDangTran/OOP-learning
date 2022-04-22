let Tree_node = require("./2_Tree_node");


class Huffman_Trees {
    #root;//Tree_node
    #COUNT = 10;
    constructor(char, freq) {
        this.#root = new Tree_node(freq, char, null, null);
    }


    Combine(left, right) {
        let freq = left.getRoot().getFreq() + right.getRoot().getFreq();
        let root = new Tree_node(freq, left.getRoot().getdata() + right.getRoot().getdata(), left, right);
        let newTree = new Huffman_Trees(null, null);
        newTree.setRoot(root);
        return newTree;
    }

    compareTo(other) {
        if (this.#root.compare(other.getRoot()) > 0) {
            return 1;
        }
        else if (this.#root.compare(other.getRoot()) < 0) {
            return -1;
        }
        else {
            // go into each node and compare the data
            // inorder traversal

            let current = this.smallestElement(this);
            let otherCurrent = this.smallestElement(other);
          
            if (current.charCodeAt(0) > otherCurrent.charCodeAt(0)) {
                return 1;
            }
            else if (current.charCodeAt(0) < otherCurrent.charCodeAt(0)) {
                return -1;
            }
            else {
                return 0;
            }
            return this.inorderCOmpare(this.getRoot(), other.getRoot());


        }
        return 0;
    }

    smallestElement(root) {

        if (root == null) {
            return 99999;
        }
        var res = root.getRoot().getdata();
        var lres = this.smallestElement(root.getRoot().getLeft());
        var rres = this.smallestElement(root.getRoot().getRight());
        
        if (lres!=99999 && lres.charCodeAt(0) < res.charCodeAt(0)) {
            res = lres;
        }
        if (rres!=99999 && rres.charCodeAt(0) < res.charCodeAt(0)) {
            res = rres;
        }
        return res;

    }



  

    printInorder(currroot) {
        if (currroot == null) {
            return;
        }
        this.printInorder(currroot.getRoot().getLeft());
        console.log(currroot.getRoot().getdata() + " freq" + currroot.getRoot().getFreq());
        this.printInorder(currroot.getRoot().getRight());

    }
    printGivenLevel(root, level) {
        if (root == null)
            return;
        if (level == 1)
            console.log(" " + root.getRoot().getdata() + " " + root.getRoot().getFreq());
        else if (level > 1) {
            this.printGivenLevel(root.getRoot().getLeft(), level - 1);
            this.printGivenLevel(root.getRoot().getRight(), level - 1);
        }
    }


    encodingALl(root, encoding) {
        if (root == null) {
            return;
        }
        if (root.getRoot().getdata() != null) {
            if (root.getRoot().getdata().length == 1) {
                root.getRoot().setEncoding(encoding);

            }
        }
        this.encodingALl(root.getRoot().getLeft(), encoding + "0");
        this.encodingALl(root.getRoot().getRight(), encoding + "1");
    }

    encoding_dict(root,data) {
        if (root == null) {
            return;
        }
        if (root.getRoot().getdata() != null) {
            if (root.getRoot().getdata().length == 1) {
                data[root.getRoot().getdata()] = root.getRoot().getEncoding();
            }
        }
        this.encoding_dict(root.getRoot().getLeft(), data);
        this.encoding_dict(root.getRoot().getRight(), data);
    }


    


    printEncoding(root,data) {
        if (root == null) {
            return;
        }
        if (root.getRoot().getdata() != null) {
            if (root.getRoot().getdata().length == 1) {
                console.log(root.getRoot().getdata() + " " + root.getRoot().getEncoding());
            }
        }

        this.printEncoding(root.getRoot().getLeft());
        this.printEncoding(root.getRoot().getRight());


    }


    getRoot() {
        return this.#root;
    }
    setRoot(root) {
        this.#root = root;
    }




}

module.exports = Huffman_Trees;

function test() {
    let huffman = new Huffman_Trees("a", 1);


}