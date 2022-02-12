package Main2;

public class Main2 {

    public static void main(String[] args) {


        Furniture f1, f2;
        f1 = new Furniture(); //f2 static type? dynamic type?
        Chair c1, c2;
        c1 = new Chair();

        //static type = compile tiem type
        //dynamic type = run-time type

        f2 = c1; // [dynamic : chair] - this is happening at run time -

        //c1 = f2; //error

        //
        c1.store(); //"storing chair"

        //
        f1.store(); //"storing furniture"

        //
        f2.store(); //storing chair


        c1.sit(); //"sitting on a chair."

        //f1.sit(); //error - Compile time error - there is no sit method in Furniture class

        //        f2.sit(); //error - Compile time error - there is no sit method in Furniture class
        // we know f2 is dynamically point to a chair but at compile time compiler cannot find sit method int the furniture class


        if (f2 instanceof Chair) {
            Chair newChair = (Chair) f2;
            newChair.sit();
        }

        // Chair newChair2 = (Chair) f1;
        // newChair2.sit();  //error - run time error - f1 is not pointing to a chair object dynamically - so we cannot cast it to chair







    }
}









class Furniture {
    public Furniture() {}
        //polymorphic method
    public void store() { System.out.println("storing furniture"); }
}

class Chair extends Furniture {
    public Chair() {}
    public void store() { System.out.println("storing chair"); }
    public void sit() { System.out.println("sitting on a chair."); }
}