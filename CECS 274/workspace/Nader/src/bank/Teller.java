package bank;
import java.util.*;

public class Teller 
{
	static char choice;
	static boolean exit = false;
	static int index = 0;
	static char ans;
	static String name;
	static String[] business = new String[1];
	static String[] personal = new String[2];
	static Queue que = new Queue();
			
	
	public static void greeting()
	{
		Scanner in = new Scanner(System.in);
		
		while(!exit){
			System.out.println("\nPlease enter your name: ");
			name = in.next();
			System.out.println("Hello welcome to Chase.\nAre you here for business transaction or personal transaction?"
					+"\nType in 'B' for business, type in 'P' for personal, or type in 'Q to quit.");
			choice = in.next().charAt(0);
			
			if (choice == 'b' || choice == 'B')
			{
				business();
			}
			else if (choice == 'p' || choice == 'P')
			{
				personal();
			}
			else if(choice == 'q' || choice == 'Q')
			{
				System.out.println("Have a nice day =).");
				exit = true;
			}
			else 
			{
				System.out.println("Enter a valid command");
			}
		}
		
	}
	
	public static void business()
	{
		que.enQ(name);
		business[0] = que.deQ(0);
		que.line();
		System.out.println("Business Teller has customer " + business[0]);
		
		System.out.println("Would you like to wait?");
		Scanner in = new Scanner(System.in);
		ans = in.next().charAt(0);
		if (ans == 'y' || ans == 'Y')
		{	
			if(que.getSize() != 0){
				System.out.println("Customers infront of you " + que.peek(que.getSize() - 2));
			}
			else{
				System.out.println("You are next in line");
			}
		}
		else if (ans == 'n' || ans == 'N')
		{
			que.deQ(que.getSize() - 1);
			System.out.println("Have a nice day =)");
		}
		else
		{
			System.out.println("please enter a valid command");
		}
	}
	
	public static void personal()
	{	
		que.enQ(name);
		if(index < 2){
			personal[index++] = que.deQ(0);
			que.line();
			System.out.println("\nTeller #" + index + " has customer " + personal[index-1]);
		}
		else
		{
			que.line();
			System.out.println("Would you like to wait?");
			Scanner in = new Scanner(System.in);
			ans = in.next().charAt(0);
			if (ans == 'y' || ans == 'Y')
			{
				if(que.getSize() != 0){
					System.out.println("Customers infront of you " + que.peek(que.getSize() - 2));
				}
				else{
					System.out.println("You are next in line");
				}
				index = 0;
			}
			else if (ans == 'n' || ans == 'N')
			{
				que.deQ(que.getSize() - 1);
				System.out.println("Have a nice day =)");
			}
			else
			{
				System.out.println("please enter a valid command");
			}
		}
	}
	
}
