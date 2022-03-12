public class TestShadow
{
	public static void main (String[] args)
	{
		A var1 = new B();
		var1.number = 10;
		System.out.println(var1);
		
		A var2 = new A();
		var2.number = 10;
		System.out.println(var2);
		
		
		B var3 = new B();
		var3.number = 10;
		System.out.println(var3);
		
		B var4 = (B)var1;
		var4.number = 10;
		System.out.println(var4);
	}
}