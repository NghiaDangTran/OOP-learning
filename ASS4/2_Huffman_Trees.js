
/**
 * DangNghiaA1
 *
 * Comp 2150 Section A02 Assignment: 4
 *
 * @author Nghia Dang( 7863117)
 *
 *
 *        this is the Huffman_Trees class
 */


const { type } = require("os");
let Tree_node = require("./2_Tree_node");


class Huffman_Trees {
    #root;//Tree_node
    // ==============================================================
    // Huffman_Trees constructor
    //
    // PURPOSE: To create a new Huffman_Trees object
    //
    // parameter: char, freq
    // return: nonce
    // ============= =================================================
    constructor(char, freq) {
        this.#root = new Tree_node(freq, char, null, null);
    }
    // ==============================================================
    // Combine function
    //
    // PURPOSE: To combine two Huffman_Trees
    //
    // parameter: left, right tree
    // return: nonce
    // ==============================================================


    Combine(left, right) {
        // if left and right is not the same 
        if (typeof left != typeof right) {
            throw new Error("The two tree are not the same");

        }
        let freq = left.getRoot().getFreq() + right.getRoot().getFreq();
        let root = new Tree_node(freq, left.getRoot().getdata() + right.getRoot().getdata(), left, right);
        let newTree = new Huffman_Trees(null, null);
        newTree.setRoot(root);
        return newTree;
    }

    // ==============================================================
    // compareTo function
    //
    // PURPOSE: To compareTo two Huffman_Trees
    //
    // parameter: Huffman_Trees
    // return: 1, 0, -1
    // ==============================================================
    compareTo(other) {
        if (this.#root.compare(other.getRoot()) > 0) {
            // if the top node freq is greater than the other tree
            // return 1
            return 1;
        }
        else if (this.#root.compare(other.getRoot()) < 0) {
            // if the top node freq is less than the other tree
            // return -1
            return -1;
        }
        else {
            // go into each node and compare the data
            // inorder traversal

            let current = this.smallestElement(this);
            // find the smallest char in the tree
            let otherCurrent = this.smallestElement(other);
            // find the smallest char in the tree

            if (current.charCodeAt(0) > otherCurrent.charCodeAt(0)) {
                return 1;
            }
            else if (current.charCodeAt(0) < otherCurrent.charCodeAt(0)) {
                return -1;
            }
            else {
                // rare case when the two char are the same
                return 0;
            }


        }
    }
    // ==============================================================
    // smallestElement function
    //
    // PURPOSE: return the smallest char in the tree
    //
    // parameter: Huffman_Trees
    // return: nonce
    // ==============================================================
    smallestElement(root) {
        // inorder traversal to find the smallest char
        if (root == null) {
            return 99999;
        }
        var res = root.getRoot().getdata();
        var lres = this.smallestElement(root.getRoot().getLeft());
        var rres = this.smallestElement(root.getRoot().getRight());

        if (lres != 99999 && lres.charCodeAt(0) < res.charCodeAt(0)) {
            res = lres;
        }
        if (rres != 99999 && rres.charCodeAt(0) < res.charCodeAt(0)) {
            res = rres;
        }
        return res;

    }




    // ==============================================================
    // printInorder function
    //
    // PURPOSE: To print the tree inorder
    //
    // parameter: nonce
    // return: nonce
    // ==============================================================
    printInorder(currroot) {
        if (currroot == null) {
            return;
        }
        this.printInorder(currroot.getRoot().getLeft());
        console.log(currroot.getRoot().getdata() + " freq" + currroot.getRoot().getFreq());
        this.printInorder(currroot.getRoot().getRight());

    }
    // ==============================================================
    // Combine function
    //
    // PURPOSE: To combine two Huffman_Trees
    //
    // parameter: left, right tree
    // return: nonce
    // ==============================================================
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

    // ==============================================================
    // encodingALl function
    //
    // PURPOSE: To encode all the char in the tree
    //
    // parameter: left, right tree
    // return: nonce
    // ==============================================================
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
    // ==============================================================
    // encoding_dict function
    //
    // PURPOSE: To return the encoding dict
    // parameter: nonce
    // return: nonce
    // ==============================================================
    encoding_dict(root, data) {
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


    // ==============================================================
    // Combine function
    //
    // PURPOSE: To combine two Huffman_Trees
    //
    // parameter: left, right tree
    // return: nonce
    // ==============================================================


    printEncoding(root, data) {
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
    // ==============================================================
    // Combine function
    //
    // PURPOSE: To combine two Huffman_Trees
    //
    // parameter: left, right tree
    // return: nonce
    // ==============================================================

    getRoot() {
        return this.#root;
    }
    // ==============================================================
    // Combine function
    //
    // PURPOSE: To combine two Huffman_Trees
    //
    // parameter: left, right tree
    // return: nonce
    // ==============================================================
    setRoot(root) {
        this.#root = root;
    }




}

module.exports = Huffman_Trees;
