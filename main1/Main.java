package main1;
public class Main {

    public static void main(String[] args) {

        GrandParent gpObject;
        gpObject = new GrandParent();

        //static type - compile time type of gpObject : GrandParent
        //dynamic type - run time type of gpObject : GrandParent

        //we only care about the dynamic type of our object - polymorphic methods
        gpObject.methodX();   //output "Grand Parent"

        gpObject = new Parent();  // error?
        //static: GrandParent       dynamic: Parent

        gpObject.methodX();    //Parent



        //Child chObject = new Parent(); //[Error]
//        chObject.methodX();     output/error?




        gpObject = new Child();  //error?
        //s:GP      d:Ch
        gpObject.methodX();     //Child


        gpObject = new Child();
        gpObject.onlyGP();     //Only GP




        gpObject = new GrandParent();
        // gpObject.onlyCH();     //error? we always check the higher classes in the hierarchy
        // method from top can not traversal from top to bot
        // but method from bottom can tranversal to top

        gpObject = new Child();
        gpObject.methodZ();     //output?error?


    }
}



//class subClass extends superClass



class GrandParent
{
    //polymorphic method
    public void methodX(){
        System.out.println("Grand Parent");
    }

    public void onlyGP()
    {
        System.out.println("Only GP");
    }

    public void methodZ()
    {
        System.out.println("method Z - GP");
    }
}

class Parent extends GrandParent{
    public void methodX(){
        System.out.println("Parent");
    }

    public void methodZ()
    {
        System.out.println("method Z - P");
    }
    public void onlyGP()
    {
        System.out.println("Only GP but at parent");
    }

    public void methodz()
    {
    

    }

}

class Child extends Parent {
    public void methodX() {System.out.println("Child");}

    public void onlyCH() { System.out.println("Only CH");}
}
