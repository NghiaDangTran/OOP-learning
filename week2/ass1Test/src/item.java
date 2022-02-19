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
// abstract class item
//
//
//
//
// PURPOSE: this is the main (parent) class of the program and
// i dont want the user to able to create this class

// ==========================================================

abstract class item {

  private String id; // 2 main attributes of the item id and the past apointment
  private customLinkedList past_apointment;

  // ==============================================================
  // item
  //
  // PURPOSE: this is a constructor of the item class
  //
  // parameter: name of that item
  // return: nonce
  // ==============================================================

  public item(String id) {
    if (id == null || id=="") {
      return;
    }
    this.id = id;

    past_apointment = new customLinkedList();
  }

  // ==============================================================
  // addPastApointmetn
  //
  // PURPOSE: this will add the past apointment to every child object
  //
  // parameter: name of that item, the topic , hour taken and the price
  // return: nonce
  // ==============================================================
  public void addPastApointmetn(String person, String Topic_taught, int hour, int revuenue) {
    appointment temp = new appointment(person, Topic_taught, hour, revuenue);
    past_apointment.add(temp);
  }
  // ==============================================================
  // getName
  //
  // PURPOSE: get the name of the item
  //
  // parameter: noce
  // return: nonce
  // ==============================================================
  public String getName() {
    return this.id;
  }

  // ==============================================================
  // get_Apointment
  //
  // PURPOSE: get the past apointment of the item
  //
  // parameter: noce
  // return: nonce
  // ==============================================================
  public customLinkedList get_Apointment() {
    return past_apointment;
  }
  // ==============================================================
  // reportappointment
  //
  // PURPOSE: this will print the conclusion of the item
  //
  // parameter: noce
  // return: nonce
  // ==============================================================
  public String reportappointment() {
    int total_Price = 0;
    int total_Hour_spent = 0;
    MyNode currentNode = past_apointment.getRoot();
    while (currentNode != null) {
      appointment temp = (appointment) currentNode.getData();
      total_Price += temp.Total_Price();
      total_Hour_spent += temp.Total_Hour_spent();

      currentNode = currentNode.getNext();
    }

    return ("Total number of hours spent: " + total_Hour_spent + "\n" + " Total price for tutoring " + total_Price);
  }
}
