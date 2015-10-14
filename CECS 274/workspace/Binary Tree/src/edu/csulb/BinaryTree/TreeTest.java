package edu.csulb.BinaryTree;
import java.util.*;

/**
 * Running tree program
 * @author tom
 *
 */
public class TreeTest {
	
	private static Tree newTree = new Tree();
	
	/**
	 * Main program
	 * @param args
	 */
	public static void main(String[] args) {
		menu(); //Prompt for menu

	}
	
	/**
	 * Menu of tree list
	 */
	public static void menu()
	{
		Scanner scan = new Scanner(System.in);
		int input = 0;
		boolean exit = false;
		while(!exit)
		{
			System.out.println("Choose one of the following options: ");
			System.out.println("1. Add item to tree");
			System.out.println("2. Delete item from tree (if item is not found, return an error message.)");
			System.out.println("3. Find item (Tell what level item is on)");
			System.out.println("4. Balance Tree");
			System.out.println("5. List content of tree (in order)");
			System.out.println("6. Display Statistics");
			System.out.println("7. Quit");
			try
			{
				input = scan.nextInt();
			
				switch(input)
				{
					case 1:
						boolean out = false;
						int number = 0;
						while(!out)
						{
							System.out.println("Enter an integer to insert to the tree: ");
							try
							{
								number = scan.nextInt();
								out = true;
							}
							catch(Exception e)
							{
								System.out.println("Invalid Input");
								scan.next();
								out = false;
							}
							if(out)
							{
								newTree.insert(number);
							}
						}
						break;
					case 2:
						out = false;
						number= 0;
						while(!out)
						{
							System.out.println("Enter an integer to remove from the tree: ");
							try
							{
								number = scan.nextInt();
								out = true;
							}
							catch(Exception e)
							{
								System.out.println("Invalid Input");
								scan.next();
								out = false;
							}
							if(out)
							{
								newTree.remove(number);
							}
						}
						break;
					case 3:
						out = false;
						number= 0;
						while(!out)
						{
							System.out.println("Enter an integer to find from the tree: ");
							try
							{
								number = scan.nextInt();
								out = true;
							}
							catch(Exception e)
							{
								System.out.println("Invalid Input");
								scan.next();
								out = false;
							}
							if(out)
							{
								newTree.search(number);
							}
						}
						break;
					case 4:
						break;
					case 5:
						newTree.display();
						break;
					case 6:
						getStats();
						break;
					case 7:
						System.out.println("Thank you for playing");
						exit = true;
						break;
					default:
						System.out.println("Invalid Input");
						break;
				}
			}
			catch(Exception e)
			{
				System.out.println("Invalid Input");
				scan.next();
			}
		}
		
	}
	
	/**
	 * Get statistic of the tree
	 */
	public static void getStats()
	{
		Scanner scan = new Scanner(System.in);
		char input = ' ';
		boolean exit = false;
		do
		{
			System.out.println("Which statistics would you like to see? ");
			System.out.println("A. Root value");
			System.out.println("B. Depth of tree");
			System.out.println("C. Number of items in tree");
			System.out.println("Q. Back to menu");
			try
			{
				input = scan.next().trim().toUpperCase().charAt(0);
				switch(input)
				{
					case 'A':
						newTree.rootValue();	//Root value
						break;
					case 'B':
						System.out.println("Depth of tree: " + newTree.depth());	//Depth of tree
						break;
					case 'C':
						System.out.println("Number of items in tree: " + newTree.size());	//Number of items in tree
						break;
					case 'Q':
						exit = true;
						break;
					default:
						System.out.println("Invalid Input");
						break;
				}
			}
			catch(Exception e)
			{
				System.out.println("Invalid Input");
				scan.next();
			}
		}while(!exit);
	}

}
