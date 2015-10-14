package edu.csulb.romannumerals;
import java.util.*;

/**
 * Running Roman Numerals Program
 * @author Hieu Tran
 *
 */
public class RomanNumerals {
	private static Scanner scan = new Scanner(System.in);	//New Scanner
	
	/**
	 * Prompt for program menu
	 * @param args - N/A
	 */
	public static void main(String[] args) {
		menu();	
	}
	
	/**
	 * Prompt for menu
	 */
	public static void menu()
	{
		boolean out = false;
		do
		{
			System.out.println("Choose the following options:");
			System.out.println("A: Convert Arabic Numbers Expression: ");
			System.out.println("R: Convert Roman Numberals Expression: ");
			System.out.println("Q: Quit");
			String input = scan.nextLine().trim().toUpperCase();
			switch(input)
			{
			case "A":
				promptArabicInput();	//Prompt for Arabic numbers input
				break;
			case "R":
				promptRomanInput();		//Prompt for Roman Numerals input
				break;
			case "Q":					//End Program
				System.out.println("Thank you for playing.");
				out = true;
				break;
			default:
				System.out.println("Invalid Input");
			}
		}while(!out);
		scan.close();
	}
	
	public static void promptArabicInput()
	{
		boolean exit = false;
		int arabic = 0;	//Arabic numbers
		String input = "";	//User Arabic numbers input
		Numbers num = new Numbers();	//New Numbers
		while(!exit)
		{
			try{
				System.out.println("\nEnter Arabic Numbers Expression (M back to menu): ");
				input = scan.nextLine().trim().toUpperCase();
				String leftRoman = "";	//Arabic left hand side values
				String rightRoman = "";	//Arabic right hand side values
				int leftArabic = 0;
				int rightArabic = 0;
				//Back to Menu
				if(input.equals("M"))
				{
					exit = true;
				}
				else
				{
					//Reading each Arabic number input
					for(int i = 0; i < input.length(); i++)
					{
						//Skipping space character
						if (input.charAt(i) == ' ')
						{
							i++;
						}
						//Skipping string operator expression
						if(input.charAt(i) == '*' || input.charAt(i) == '/' || input.charAt(i) == '+' || input.charAt(i) == '-')
						{
							for(int j = i + 1; j < input.length(); j++)
							{
								//Skipping space character
								if (input.charAt(j) == ' ')
								{
									j++;
								}
								rightRoman += input.charAt(j);	//Retrieving right hand side Arabic values
							}
							break;
						}
						leftRoman += input.charAt(i);		//Retrieving left hand side of Arabic values
					}
					leftArabic = Integer.parseInt(leftRoman);	//Converting left hand side of Arabic numbers into integer
					rightArabic = Integer.parseInt(rightRoman);	//Converting right hand side of Arabic numbers into integer
					num.reset();	//Reset values
					arabic = num.calculate(input, leftArabic, rightArabic);		//Calculate Arabic Numbers
					if(arabic > 3999)
					{
						System.out.println("Arabic Numbers Expression is more than 3999");	//Error if Arabic expression > 3999
						continue;
					}
					
					System.out.println("Arabic Expression: " + input + " = " + arabic);	//Output Arabic calculated values
				
				}

			}
			catch(Exception e)
			{
				System.out.println("Invalid Input");	//Invalid user input
			}
		}
	}

	/**
	 * Prompt for Roman Numerals Input
	 */
	public static void promptRomanInput()
	{
		boolean exit = false;
		int arabic = 0;	//Arabic numbers
		String input = " ";	//User Roman Numerals input
		Numbers num = new Numbers();
		while(!exit)
		{
			try{
				num.reset();		//Clear values
				/*
				 * Local variables
				 */
				String leftSide = "";
				String rightSide = "";
				int leftArabic = 0;
				int rightArabic = 0;
				/*
				 * Prompt for user input
				 */
				System.out.println("\nEnter Roman Numerals Expression (M back to menu): ");
				input = scan.nextLine().trim().toUpperCase();
				//Reading each Roman Numerals input
				for(int i = 0; i < input.length(); i++)
				{
					//Skipping space character of the input
					if (input.charAt(i) == ' ')
					{
						i++;
					}
					//Skipping string operator expression
					if(input.charAt(i) == '*' || input.charAt(i) == '/' || input.charAt(i) == '+' || input.charAt(i) == '-')
					{
						for(int j = i + 1; j < input.length(); j++)
						{
							//Skipping space character
							if (input.charAt(j) == ' ')
							{
								j++;
							}
							rightSide += input.charAt(j);	//Push Roman Numerals right hand side onto stack
						}
						break;
					}
					leftSide += input.charAt(i);	//Push Roman Numerals left hand side onto queue
				}
				//Back to Menu
				if(input.equals("M"))
				{
					exit = true;
				}
				//Check for valid Roman Numerals input
				else if(!num.check(leftSide, rightSide))
				{
					System.out.println("Invalid Roman Numerals");
					continue;
				}
				else{
					leftArabic = num.toArabicNumbers(leftSide);		//Get left Arabic values
					rightArabic = num.toArabicNumbers(rightSide);	//Get right Arabic values
					arabic = num.calculate(input, leftArabic, rightArabic);
					if(arabic > 3999)
					{
						System.out.println("Roman Numerals Expression is more than 3999");	//Error if Roman expression > 3999
						continue;
					}
					String check = num.toRomanNumbers(arabic);	//Check valid Roman Numerals input
					Scanner sc = new Scanner(input);
						if(check.equals("") || sc.hasNextInt())
						{
							System.out.println("Invalid Input");	//Invalid Roman Numerals input
							continue;
						}
					for(int index = 0; index < input.length(); index++)
					{
						if(input.charAt(index) == '/')
						{
							if(rightArabic == 0)
							{
								System.out.println("Invalid Input");	//Invalid Roman Numerals input
								continue;
							}
						}
					}
					if(rightArabic == 0)
					{
						System.out.println("Roman Expression: " + leftSide);	//Output Roman Numerals left hand side
					}
					else
					{
							System.out.println("Roman Expression: " + input + " = " + num.toRomanNumbers(arabic)); //Output Roman Numerals expression
					}
				}
			}
			catch(Exception e)
			{
				System.out.println("Invalid Input");	//Invalid Roman Numerals input
			}
		}
	}
}