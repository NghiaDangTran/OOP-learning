
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
// MyNode
//
//
//
//
// PURPOSE: this is the node of the list and the reson i want 
// it to be public is i want to be able to access it from anywhere
// 
//
// ==========================================================

public class MyNode {

    private final item data;// this is the data of the node
  
    private MyNode next;// this is the next node of the list
  
    // ==============================================================
    // MyNode
    //
    //
    //
    // PURPOSE: this is a constructor of the MyNode class
    //
    // parameter: the data of the node
    // return: nonce
    // ==============================================================

    public MyNode(item data) {
      this.data = data;
      this.next = null;
    }

   
  
    public MyNode getNext() {
      return next;
    }
  

    // ==============================================================
    // setNext
    // PURPOSE: this will set the next node of the list
    //
    // parameter: tge next node
    // return: nonce
    // ==============================================================
    public void setNext(MyNode next) {
      this.next = next;
    }
   // ==============================================================
    // getData
    //
    //
    //
    //
    // PURPOSE: this will get the data of the node
    //
    // parameter: noce
    // return: the data of the node
    // ==============================================================
    public item getData() {
      return this.data;
    }
  }
  
  