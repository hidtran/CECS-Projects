import java.util.Scanner;
import java.util.Random;
import java.awt.KeyEventDispatcher;
import java.awt.event.KeyEvent;					//(awt) abstract window toolkit

public class Operations 
{
	public static void getOperations()
	{
		
		char command = ' ';
		Scanner in = new Scanner(System.in);
			
		System.out.print("Hello =) \n\nWelcome to your personal radio.");
		System.out.println("\n\nHere are the list of controles: \n\tPress 'o' to turn on."
				+"\n\tPress 'f' to turn off.\n\tPress 'w' to turn volume up"
				+ "\n\tPress 's' to turn volume down.\n"
				+ "\n\tPress 'c' to scan.\n\tPress 't' to tune.");
		while(true){	
			System.out.println("\n\nEnter your command.  >>");
			command = in.nextLine().charAt(0);
			
			if (command == 'o' | command == 'O')
			{
				break;
			}
			
			else
			{
				System.out.println("You must turn on the radio first.");
			}			
		}
		Not_On off = new Not_On();
		off.turnOn();
	}
}