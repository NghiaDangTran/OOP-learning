public class Main {

    public static void main(String[] args) {

        Furniture f1=new Furniture("this is student", null, null);
        System.out.print(f1);

        // Furniture f1, f2;
        // f1 = new Furniture(); // f2 static type? dynamic type?
        // f1 = new Chair();

        // // static type = compile-time type - cannot be changed
        // // dynamic type = run-time type - we change this dynamically

        // Chair c1, c2;
        // c1 = new Chair();

        // // static type = compile time type
        // // dynamic type = run-time type

        // f2 = c1; // [dynamic : chair] - this is happening at run time -

        // // c1 = f2; //error

        // //
        // c1.store(); // "storing chair"

        // //
        // f1.store(); // "storing furniture"

        // // we care about the dynamic type of our object - polymorphic method
        // f2.store(); // ***** storing chair

        // c1.sit(); // "sitting on a chair."

        // // f1.sit(); //error - Compile time error - there is no sit method in Furniture
        // // class

        // // f2.sit(); //***** error - Compile time error - there is no sit method in
        // // Furniture class
        // // we know f2 is dynamically point to a chair but at compile time compiler
        // // cannot find sit method int the furniture class

        // if (f2 instanceof Chair) {
        //     Chair newChair = (Chair) f2;

        //     ((Chair) f2).sit(); // possible

        //     newChair.sit();
        // }

        // Chair newChair2 = (Chair) f1;
        // newChair2.sit(); // error - run time error - f1 is not pointing to a chair object dynamically -
        //                  // so we cannot cast it to chair

        // // int x = get the value from the user = user enters "text . . . ."
        // // int x = "asdasd"; // compile time error

    }
}

class Furniture {
    private String name;
    private String name1;
    private String name2;
    private int unsing;

    public Furniture(String name, String name1, String name2) {

        if (name != null) {
            unsing = 1;
            this.name = name;
        } else if (name1 != null) {
            unsing = 2;
            this.name1 = name1;
        } else if (name2 != null) {
            unsing = 3;
            this.name2 = name2;
        }

    }

    public String toString() {
        if (name != "") {
            return "this is type " + unsing + " and it has name: " + name;
        } else if (name1 != "") {
            return "this is type " + unsing + " and it has name: " + name1;
        } else if (name2 != "") {
            return "this is type " + unsing + " and it has name: " + name2;
        }
        return "";

    }

    // polymorphic method
    public void store() {
        System.out.println("storing furniture");
    }
}

class Chair extends Furniture {
    public Chair(String name1, String name2, String name3) {
        super("1","","");
    }

    public void store() {
        System.out.println("storing chair");
    }

    public void sit() {
        System.out.println("sitting on a chair.");
    }
}

class NewParent {
    private String name;

    public NewParent(String val) {
        // super - constructor of GP
        name = val;
    }

}

class ChildA extends NewParent {
    public ChildA(String val) {
        super(val);
        // super("ali", 2); // ?
    }

}

class ChildB extends NewParent {
    public ChildB(String val) {
        super(val);
    }
}

// ChildB obj = new ChiChildB("x");

class NewParentX {
    public void methodX() {
        // code 1
        // code 2
        // code 3
    }
}

class ChildAX extends NewParentX {
    public void methodX() {
        super.methodX();
        // new code in ChildA
    }
}

class ChildBX extends NewParentX {
    public void methodX() {
        super.methodX();
        // new code in ChildB
    }
}
