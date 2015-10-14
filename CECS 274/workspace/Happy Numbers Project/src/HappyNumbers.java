import java.util.Scanner;
import java.util.ArrayList;
/**
 * This is an exercise of happy number
 * @author tom
 *
 */
public class HappyNumbers {
	
	//Declare instance variable
	private static ArrayList numList = new ArrayList(); //Creating ArrayList
	private static Scanner scan = new Scanner(System.in); //Creating a Scanner object
	
	/**
	 * Run Happy Numbers Program
	 * @param args undefined
	 */
	public static void main(String[] args) {
		promptUser(); //Prompt user for input
	}
	
	/*
	 * Ask user if he/she wants to find a Happy Number
	 */
	public static void promptUser()
	{
		boolean out = false;	//Ending Happy Numbers Program
		char prompt;
		do
		{
			System.out.println("Would you like to find a Happy Number (y/n)?");	//Ask user for an answer
			prompt = scan.next().trim().toLowerCase().charAt(0);	//Take user answer & reduce it to lower case letter
			switch(prompt)
			{
				case 'y':
					inputNumbers(); //Recursively asking input numbers from user
					break;
				case 'n':	
					out = true;	//Exiting the Program
					break;
				default:
					System.out.println("Invalid Input.");	//Display user invalid answer
					break;
			}
		}while(!out);
		System.out.println("Thank you for playing."); //Display End of Program Text
	}
	
	/*
	 * User input any positive integer
	 */
	public static void inputNumbers()
	{
		boolean exit = false;	//Ending Happy Numbers Program
		do
		{
			System.out.println("Enter a positive integer (0 to quit): ");	//Prompt for user input
			int input = scan.nextInt();	//Take user next integer input
			if(input > 0)
			{
				dissect(input); //Dissect user input recursively
				break;
			}
			else if(input == 0)
			{
				exit = true; //Exiting the Program
				break;
			}
			else
			{
				System.out.println("Invalid Input.");	//Display user invalid input
			}
		}while(!exit);
	}
	
	/*
	 * Splitting user input numbers into individual digit
	 * @param num - numbers being dissected
	 */
	public static void dissect(int num)
	{
		int remainder = 0;	//Modulus numbers
		numList.add(num);	//Storing numbers into an array list before being dissected
		while(num > 0)
		{
			remainder += (num % 10) * (num % 10);	//Capturing the remainder number
			num /= 10;	//Reducing numbers by 10
		}
		isHappyNumber(remainder);	//Recursively determine if number is happy
	}
	
	/*
	 * Determine if the number is a Happy Number
	 * @param num - new calculated numbers
	 */
	public static void isHappyNumber(int num)
	{
		if(num == 1)	//Determine if Happy Number exists
		{
			numList.add(num);	//Add Happy Number into ArrayList
			displayNumbers();	//Display all calculated numbers
			System.out.println(numList.get(numList.size()- 1) + " - Happy Number"); //Display Happy Number
		}
		else
		{
			converge(num);	//Recursively converge individual number
		}
		numList.clear();	//Empty ArrayList
	}
	
	/*
	 * Determine if the numbers not Happy Number
	 * @param num - numbers to converge
	 */
	public static void converge(int num)
	{
		if(!numList.contains(num))
		{
			dissect(num);	//Recursively dissect new numbers if the numbers are not repeated in the ArrayList
		}
		else
		{
			numList.add(num);	//Add not Happy Number into Array List
			displayNumbers();	//Display all calculated numbers
			System.out.println(numList.get(numList.size() -1 ) + " - not Happy Number");	//Display not Happy Numbers
			numList.clear();	//Empty ArrayList
		}
	}
	/*
	 * Display all calculated numbers
	 */
	public static void displayNumbers()
	{
		System.out.println("Input: " + numList.get(0));	//Display user input number
		System.out.print("Output: "); //Display Output number(s)
		for(int index = 0; index < numList.size(); index++)
		{
			if(index != numList.size() - 1)
			{
				System.out.print(numList.get(index) + " , ");	//Display all calculated numbers in the ArrayList
			}
		}
	}
}
