package edu.csulb.LinkedList;
import java.util.*;

/**
 * Creating & Running Linked List
 * Running Roman Numerals Expression
 * @param args
 */
public class LinkedList {
	
	public static void main(String[] args) {
		menu(); //Prompting menu

	}
	
	/**
	 * Running Linked List Menu
	 */
	public static void menu()
	{
		CharList newList = new CharList();	//New empty linked list
		int input = 0;	//User input
		boolean exit = false;
		do{
			String character = "";
			boolean out = false;
			Scanner scan = new Scanner(System.in);
			System.out.println("\nChoose from the following options: ");
			System.out.println("1: Create an empty linked list");
			System.out.println("2: Insert a node to the linked list");
			System.out.println("3: Remove a node to a linked list");
			System.out.println("4: Display a size of a linked list");
			System.out.println("5: Display the information store at a particular node");
			System.out.println("6: Show linked list's data");
			System.out.println("7: Process Roman Number expression");
			System.out.println("8: Quit");
			try{
				input = scan.nextInt();		//Prompting user input
			}
			catch(Exception e)
			{
				System.out.println("Invalid Input");
				scan.next();
			}
			switch(input)
			{
			case 1:
				newList = new CharList();	//Creating empty linked list
				break;
			case 2:
				int in = 0;	//User input
				if(newList.getSize() == 0)
				{
					while(!out)
					{
						System.out.println("\nEnter the first node character to insert to the linked list: ");
						character = scan.next();
						if(character.length() > 1)
						{
							System.out.println("Invalid Character");
						}
						else
						{
							out = true;
						}
					}
					newList.add(character.charAt(0));
				}
				else
				{
					while(!out)
					{
						System.out.println("\nWhich node position would you like to insert? ");
						try{
							in = scan.nextInt();	//Prompting user to insert a character
							out = true;
						}
						catch(Exception e)
						{
							System.out.println("Invalid Input");
							scan.next();
						}
					}
					out = false;
					while(!out)
					{
						System.out.println("\nEnter a node character to insert to the linked list: ");
						character = scan.next();
						if(character.length() > 1)
						{
							System.out.println("Invalid Character");
						}
						else
						{
							out = true;
						}
					}
					newList.insertAt(character.charAt(0), in);	//Add new character to linked list
				}
				break;
			case 3:
				char temp = ' ';
				while(!out)
				{
					System.out.println("\nWhich node position would you like to remove: ");
					input = scan.nextInt();		//Prompting user to remove a character
					temp = newList.removeAt(input);		//Remove a character from linked list
					if(temp == '\0')
					{
						System.out.println("Invalid Removal Character");
					}
					else
					{
						//Display remove character
						System.out.println("Removal character: " + temp);
						out = true;
					}
				}
				break;
			case 4:
				System.out.println("\nCurrent linked list size: " + newList.getSize());		//Display current linked list size
				break;
			case 5:
				while(!out)
				{
					System.out.println("\nEnter a particular node position to see the store information: ");
					int position = 0;
					try
					{
						position = scan.nextInt();	//Prompting user input to take a look at particular linked list position
						if(position > newList.getSize() || position < 0)
						{
							System.out.println("Linked List is out of bound");
						}
						else
						{
							System.out.println("\nCurrent node information: " + newList.getChar(position));		//Display current linked list position data
							out = true;
						}
					}
					catch(Exception e)
					{
						System.out.println("Invalid Input");
						scan.next();
					}
				}
				break;
			case 6:
				newList.showList();		//Display all linked list's data
				System.out.println();
				break;
			case 7:
				promptRomanInput();		//Running Roman Numerals expression
				break;
			case 8:
				System.out.println("Thank you for playing");
				exit = true;
				break;
			default: 
				System.out.println("Invalid Input");
				break;
			}	
	
		}while(!exit);
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
			num.reset();		//Clear values
			/*
			 * Local variables
			 */
			CharList leftSide = new CharList();
			CharList rightSide = new CharList();
			int leftArabic = 0;
			int rightArabic = 0;
			/*
			 * Prompt for user input
			 */
			Scanner scan = new Scanner(System.in);
			System.out.println("\nEnter Roman Numerals Expression (M back to menu): ");
			try{
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
							rightSide.add(input.charAt(j));	//Push Roman Numerals right hand side onto stack
						}
						break;
					}
					leftSide.add(input.charAt(i));	//Push Roman Numerals left hand side onto queue
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
