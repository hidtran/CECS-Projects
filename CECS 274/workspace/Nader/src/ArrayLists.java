/**
 * 
 */

/**
 * @author tom
 *
 */
import java.util.Scanner;
import java.util.ArrayList;

public class ArrayLists {
	static Scanner in = new Scanner(System.in);
	
	public static void mains(String[] args){
		Lists();
	}

	public static void Lists()
	{
		
		/**
		 * to add an element to an arraylist
		 * one.add("1");
		 * 
		 * This will add an element to a specific place in the arraylist
		 * void add(int index, object obj) method.
		 * 	arrayList.add(1, "insert and element here");
		 * 
		 * This displays the elements of the arraylist
		 * for (int index = 0; index < arrayList.size(); index++)
		 * 		System.out.println(arrayList.get(index));
		 * 
		 * This is to check and see where exactly is the this item in the arraylist
		 * int index;
		 * index = arrayList.indexof(" write something here");
		 * System.out.println("index position" +index); 
		 * 
		 * This is to check if this object in the arraylist exists or not
		 * boolean isExist;
		 * isExist = arrayList.contains("Ram");
		 * System.out.println("is blaaaablaaabla..." +isExist);
		 */
		
	    ArrayList<String> one = new ArrayList<String> (9);
	    for (int i = 0; i < one.size(); i++)
	    {
	    	one.add("X ");
	    }
	    for (int index = 0; index < one.size(); index++){
	    	System.out.print(one.get(index));
	    }

	    twoArray();
	}
	  
	static void twoArray(){
		
	    ArrayList<String> two = new ArrayList<String>(9);
		int choice = 0;
		//Fill 3 cells only and the rest are empty.
		//Have user input what cell they want to go through.
		two.add(0, "X");
		two.add(5, "Y");
		two.add(8, "Z");
		boolean exit = false;
		
		//filling out three cells and the rest are empty;
		for (int index = 0; index < 9; index++)
		{
		   if(index == 0 || index == 5 || index == 8)
		   {
		      two.add("X"); 
		   }
		   else{
		      two.add("");
		   }
		}

		while(!exit){			
			System.out.println("Choose a path to take.\nEnter a number from 0 to 7.\nThe numbers represent cells; if one of the cells are blocked then you won't be able"
					+ "to go on and you must choose again.\n>>");
			choice = in.nextInt();
			if (!two.get(choice).isEmpty())
			{
				System.out.println("You hit a wall.\n Please try again.\n>>");
			}
			else
			{
				System.out.println("You are granted Passage.");
				exit = true;
			}
		}
		
		threeArray(choice);
	}
		
	static void threeArray(int input)
	{
		ArrayList<String> three = new ArrayList<String>(9);
		//Fill 7 cells and leave 2 empty.
		//Have user input what cell they want to go through.
		//If empty. Sys.out.println("you are allowed path");
		//else full Sys.out.println("you hit a wall. Choose another path.");
		//Allow user to select another path.
		//Create a while loop with conditions.
		three.add(0, "X");
		three.add(1, "X");
		three.add(2, "X");
		three.add(3, "X");
		three.add(4, "X");
		three.add(5, "X");
		three.add(8, "X");
		
		if (!three.get(input).isEmpty()){
			System.out.println("You hit a wall.\n Please try again.\n>>");
		}
		else{
			System.out.println("You are granted Passage.");
			fourArray(input);
		}
			

	}
	
	static void fourArray(int input)
	{
		ArrayList<String> four = new ArrayList<String>(9);
		//Fill 4 cells and leave 5 empty.
		//Have user input what cell they want to go through.
		//If empty. Sys.out.println("you are allowed path");
		//else full Sys.out.println("you hit a wall. Choose another path.");
		//Allow user to select another path.
		//Create a while loop with conditions.
		four.add(0, "X");
		four.add(1, "X");
		four.add(3, "X");
		four.add(8, "X");
		   
		if (!four.get(input).isEmpty()){
			System.out.println("You hit a wall.\n Please try again.\n>>");
		}
		else{
			System.out.println("You are granted Passage.");
			fiveArray(input);
		}
	}
		
	static void fiveArray(int input)
	{
		ArrayList<String> five = new ArrayList<String>(9);
		//Fill 6 cells and leave 3 empty.
		//Have user input what cell they want to go through.
		//If empty. Sys.out.println("you are allowed path");
		//else full Sys.out.println("you hit a wall. Choose another path.");
		//Allow user to select another path.
		//Create a while loop with conditions.
		five.add(0, "X");
		five.add(1, "X");
		five.add(2, "X");
		five.add(3, "X");
		five.add(4, "X");
		five.add(7, "X");
	}
	
	static void sixArray()
	{
		ArrayList<String> six = new ArrayList<String>(9);
		//Fill 3 cells and leave 6 empty.
		//Have user input what cell they want to go through.
		//If empty. Sys.out.println("you are allowed path");
		//else full Sys.out.println("you hit a wall. Choose another path.");
		//Allow user to select another path.
		//Create a while loop with conditions.
		six.add(0, "X");
		six.add(2, "X");
		six.add(7, "X");
	}
	
	static void sevenArray()
	{
		ArrayList<String> seven = new ArrayList<String>(9);
		//Fill 6 cells and leave 3 empty.
		//Have user input what cell they want to go through.
		//If empty. Sys.out.println("you are allowed path");
		//else full Sys.out.println("you hit a wall. Choose another path.");
		//Allow user to select another path.
		//Create a while loop with conditions.
		seven.add(0, "X");
		seven.add(1, "X");
		seven.add(2, "X");
		seven.add(3, "X");
		seven.add(4, "X");
		seven.add(8, "X");
	}
		
	static void eightArray()
	{
		ArrayList<String> eight = new ArrayList<String>(9);
		//Fill 3 cells and leave 6 empty.
		//Have user input what cell they want to go through.
		//If empty. Sys.out.println("you are allowed path");
		//else full Sys.out.println("you hit a wall. Choose another path.");
		//Allow user to select another path.
		//Create a while loop with conditions.
		eight.add(0, "X");
		eight.add(5, "X");
		eight.add(8, "X");
	}
		
	static void nineArray()
	{
		ArrayList<String> nine = new ArrayList<String>(9);
		//Fill 9 cells and leave 1 empty.
		//Have user input what cell they want to go through.
		//If empty. Sys.out.println("you are allowed path");
		//else full Sys.out.println("you hit a wall. Choose another path.");
		//Allow user to select another path.
		//Create a while loop with conditions.
		//Create a recursion function with base case. If user goes through the cell then end program. Otherwise choose again.
		nine.add(0, "X");
		nine.add(1, "X");
		nine.add(2, "X");
		nine.add(3, "X");
		nine.add(4, "X");
		nine.add(5, "X");
		nine.add(6, "X");
		nine.add(8, "X");
	}
		
}
