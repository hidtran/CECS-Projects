package Heap;
import java.util.*;

/**
 * Test run heap and tree program
 * @author tom
 *
 */
public class HeapTest {

	/** Main program to run
	 * @param args
	 */
	public static void main(String[] args) {
		menu();	//Prompt menu

	}
	
	/**
	 * Menu of the program
	 */
	public static void menu()
	{
		Scanner scan = new Scanner(System.in);	//Create new Scanner
		Random random = new Random();	//Create new random generator
		Tree heap = new Tree();	//Create new heap
		int[] array;	//Create new array
		int number = 0;
		int input = 0;
		boolean exit = false;
		do
		{
			System.out.println("Choose one of the following options: ");
			System.out.println("1. Generate random numbers into Binary Tree of array");
			System.out.println("2. Display Binary Tree");
			System.out.println("3. Display Heap from largest to smallest");
			System.out.println("4. Display Heap from smallest to largest");
			System.out.println("5. Display heap in-order");
			System.out.println("6. Quit");
			input = scan.nextInt();
			switch(input)
			{
				case 1:
					boolean out = false;
					while(heap.size() <= 31)
					{
						number = random.nextInt(89) + 10;	//Random numbers between 10 & 99
						heap.insert(number);
					}
					array = heap.toArray();	//Convert to array
					System.out.print("Array list: ");
					for(int index = 0; index < array.length; index++)
					{
						System.out.print(array[index]);
					}
					System.out.println();
					break;
				case 2:
					array = heap.toArray();	//Convert to array
					heap.displayHeap(array);	//Convert to heap
					break;
				case 3:
					heap.inOrderDisplay();
					array = heap.toArray();	//Convert to array
					heap.displayLargestToSmallest(array);	//Display largest to smallest
					System.out.println();
					break;
				case 4:
					heap.inOrderDisplay();	
					array = heap.toArray();	//Convert to array
					heap.displayHeap(array);	//Convert to heap
					System.out.println();
					break;
				case 5: 
					heap.inOrderDisplay();	//Display in order tree
					break;
				case 6:
					System.out.println("Thank you for playing");
					exit = true;
					break;
				default:
					System.out.println("Invalid input");
					break;		
			}
		}while(!exit);
	}
}
