


/**
 * DangNghiaA1
 *
 * Comp 2150 Section A02 Assignment: 1
 *
 * @author Nghia Dang( 7863117)
 *
 *         <p>
 *         this will make a student and tutor application
 */

// ==========================================================
// customLinkedList
//
//
//
//
// PURPOSE: this is the main data structure of the program
// ==========================================================



public class customLinkedList {

  private MyNode root;// this is the root of the list

  private int size;// this is the size of the list

  // ==============================================================
  // customLinkedList
  //
  // PURPOSE: this is a constructor of the customLinkedList class
  //
  // parameter: none
  // return: nonce
  // ==============================================================
  public customLinkedList() {
    this.root = null;
    this.size = 0;
  }

  // ==============================================================
  // add
  //
  // PURPOSE: this will add the item to the list
  //
  // parameter: the item that will be added
  // return: nonce
  // ==============================================================


  public void add(item data) {
 

    MyNode node = new MyNode(data);
    if (this.root == null) {
      this.root = node;
    }
    else {
      /// chgeck the root is incstenet of data
      if (!check_same_instace(data)) {
        System.out.println("The data you enter is different from the data in the list");
        return;
      }
      MyNode temp = this.root;
      while (temp.getNext() != null) {
        temp = temp.getNext();
      }
      temp.setNext(node);
    }
    this.size++;
  }


  // ==============================================================
  // check_same_instace
  //
  // PURPOSE: this will check the instance of the item
  //
  // parameter: the item that will be checked
  // return: nonce
  // ==============================================================

  public boolean check_same_instace(item data) {
    MyNode temp = this.root;
    int type = -1;
    int type2 = -1;
    if (temp.getData() instanceof Student) {
      type = 0;
    }
    else if (temp.getData() instanceof Tutor) {
      type = 1;
    }
    else if (temp.getData() instanceof appointment) {
      type = 2;
    }
    else {
      type = 3;
    }

    if (data instanceof Student) {
      type2 = 0;
    }
    else if (data instanceof Tutor) {
      type2 = 1;
    }
    else if (data instanceof appointment) {
      type2 = 2;
    }
    else {
      type2 = 3;
    }
    
    return type == type2;

  }

  // ==============================================================
  // size
  //
  // PURPOSE: get the size of the list
  //
  // parameter: none
  // return: the size of the list
  // ==============================================================

  public int size() {
    return this.size;
  }



  // ==============================================================
  // getRoot
  //
  // PURPOSE: this will get the root of the list
  //
  // parameter: none
  // return: the root of the list
  // ==============================================================

  public MyNode getRoot() {
    return this.root;
  }

  // ==============================================================
  // find
  //
  // PURPOSE: get the node that has the same data, also this can be used as away to find the node
  //
  // parameter: none
  // return: the size of the list
  // ==============================================================

  public MyNode find(String id) {
    MyNode currentNode = root;
    while (currentNode != null) {
      if (currentNode.getData().getName().equals(id)) {
        return currentNode;
      }
      currentNode = currentNode.getNext();
    }
    return null;
  }

  // ==============================================================
  // printData
  //
  // PURPOSE: thnis will print the data of the list
  //
  // parameter: nonce
  // return: nonce
  // ==============================================================
  public void printData() {

    // method used to print the content of the linked list
    MyNode currentNode = root;
    while (currentNode != null) {
      System.out.println(currentNode.getData());

      currentNode = currentNode.getNext();
    }
  }
}


