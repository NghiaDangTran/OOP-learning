/*
 * CovarianceInJava.java
 * COMP 2150 Object Orientation
 *
 * Illustrates covariant return types in Java
 *
*/

class Parent
{
	public Parent cloneIt() 
	{
		System.out.println("### Inside cloneIt of Parent");
		return new Parent();
	}
	public void print(){
		System.out.println("This is a Parent object!");
	}
}// class Parent

class Child extends Parent
{
	public Child cloneIt() //Covariant return type
	{
		System.out.println("### Inside cloneIt of Child");
		return new Child();
	}
	// public Object cloneIt() //Contra-variant return type --> not allowed!
	// {
		// return new Child();
	// }
	public void print()
	{
		System.out.println("This is a Child object!");
	}
}// class Child

public class CovarianceInJava
{
    public static void main(String[] args)
    {
		Parent aParent = new Parent();
		aParent.print();
		Parent otherParent = aParent.cloneIt();
		otherParent.print();
		
		System.out.println();
		
		Child aChild = new Child();
		aChild.print();
		Child otherChild = aChild.cloneIt();
		otherChild.print();
    }
}


