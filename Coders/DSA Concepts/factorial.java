import java.util.Scanner;
class factorial
{
    int num, f;

    factorial()
    {
        f = 1;
    }

    factorial(int n)
    {
	f=1;
        num = n;
    }

    public int getfactorial()
    {
        for(int i = 1; i <= num; i++)
        {
            f = f * i;
        }   
        System.out.println("Factorial= " + f);
        return f;
    }

    public static void main(String args[])
    {     
	Scanner scan = new Scanner(System.in);
		
        System.out.print("Enter a Number : ");
        int n = scan.nextInt();
        factorial obj = new factorial(n);
        obj.getfactorial();
    }
}