/**
 * DangNghiaA1
 *
 * Comp 2150 Section A02 Assignment: 1
 *
 * @author Nghia Dang( 7863117)
 * 
 * 
 *         this will make a student and tutor application
 */



// ==========================================================
// appointment class
//
//
//
//
// PURPOSE: this is where I store the information of the appointment
// and also
// ==========================================================
public class appointment extends item {


    // private String Id_of_user;// this will be store in the item class parent class
    private int Total_Hour_spent;// this is the total hour spent by the person
    private int Total_Price;// this is the total price of the person
    private String Topic_name;// this is the topic name

    // ==============================================================
    // appointment
    //
    // PURPOSE: this is a constructor of the appointment
    //
    // parameter: name of the user, the topic name, the hour spent and the price
    // return: nonce
    // ==============================================================
    public appointment(String user, String topic_name, int total_Hour_spent, int total_Price) {
        super(user);
        Total_Hour_spent = total_Hour_spent;
        Total_Price = total_Price;
        Topic_name = topic_name;
    }

  
    // public String getName() {
    //     return super.getName();
    // }
    // ==============================================================
    // toString
    //
    // PURPOSE: this print out the information of the appointment
    //
    // parameter: none
    // return: the information of the appointment
    // ==============================================================
    public String toString() {
        String str = "";
        str += "person: " + super.getName();
        str += " Topic: " + this.Topic_name;
        str += " Hour: " + this.Total_Hour_spent;
        str += " Price: " + this.Total_Price + "\n";
        return str;
    }

    // ==============================================================
    // Total_Price
    //
    // PURPOSE: this will get the price of the appointment
    //
    // parameter: none
    // return: the price of the user
    // ==============================================================
    public int Total_Price() {
        return this.Total_Price;
    }
    // ==============================================================
    // Total_Hour_spent
    //
    // PURPOSE: this will get the hour of the appointment
    //
    // parameter: none
    // return: the hour of the user
    // ==============================================================
    public int Total_Hour_spent() {
        return this.Total_Hour_spent;
    }
    // ==============================================================
    // Topic_name
    //
    // PURPOSE: this will get the name of the appointment
    //
    // parameter: none
    // return: the name of the user
    // ==============================================================
    public String Topic_name() {
        return this.Topic_name;
    }
}
