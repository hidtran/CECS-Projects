import java.util.Random;
import java.util.Scanner;

public class Not_On 
{
	double station = 90;
	
	public static void turnOn()
	{
		int volume = 0;
		char choice;
		boolean on = true;
		Not_On sc = new Not_On();		//create an object
		Scanner in = new Scanner(System.in);
		
		System.out.println("Radio is on.");
		
		while (on)
		{
			System.out.println("please choose a commmand:\n  >>");
			choice = in.nextLine().charAt(0);
		
			if (choice == 'w' | choice == 'W')
			{					
				volumeUp(volume);
			}
			else if (choice == 'd' | choice == 'D')
			{				
				volumeDown(volume);
			}
			else if (choice == 'c' | choice == 'C')
			{				
				sc.Scanning();
			}
			else if (choice == 't' | choice == 'T')
			{
				tunning(sc.station);
			}
			else if (choice == 'f' | choice == 'F' )
			{
				on = false;
				System.out.println("Good bye");
			}
			else
			{
				System.out.println("Please enter a valid command! \n ");
			}

		}
	}
	
	public static void volumeUp(int volume)
	{
		volume = volume +1;
		System.out.println("Volume down");
	}
	
	public static void volumeDown(int volume)
	{
		volume = volume -1;
		System.out.println("Volume down");
	}
	
	public static void tunning(double num)
	{
		char tune;
		Not_On update = new Not_On();
		double temp = num;
		
		while (true)
		{
			System.out.println("A to tune up, D to tune down, X for ending command ");
			Scanner in = new Scanner(System.in);
			tune = in.next().charAt(0);
			
				//pass in the station from the method below and increment or decrement it. Keep program running 
				//till the user hits 'f'.
				
			if (tune == 'd' || tune == 'D')
			{
				temp = temp - 1;
				System.out.println("Station: " + temp);
			}
			
			else if (tune == 'a' || tune == 'A')
			{
				temp += 1;
				System.out.println("Station: " + temp);
			}
			
			else if (tune == 'x' || tune == 'X')
			{
				update.station = temp;
				break;
			}
		}
		
		turnOn();
			
	}
	
	
	public double Scanning()
	{
		//Scan. Random number generator
		//Random number generator from 90.0 to 107.0
		
		double num;
		System.out.println("Scanning. . . .");
		
		Random scan = new Random();
		
		num = scan.nextInt(107-90)+90;
		System.out.print("Station: " +num);
		
		Not_On.tunning(num);
		return num;
	}
	
}