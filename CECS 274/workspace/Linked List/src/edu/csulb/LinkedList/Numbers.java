package edu.csulb.LinkedList;
import edu.csulb.LinkedList.Stack;

/**
 * Converting and calculating Roman Numerals expression
 * Converting and calculating Arabic numbers expression
 * @author Hieu Tran
 *
 */
public class Numbers {
	/*
	 * Constant Roman Numerals
	 */
	private static final int ROMANI = 1;
	private static final int ROMANX = 10;
	private static final int ROMANV = 5;
	private static final int ROMANL = 50;
	private static final int ROMANC = 100;
	private static final int ROMAND = 500;
	private static final int ROMANM = 1000;
	/*
	 * Instance variables
	 */
	private String roman;		//Total Roman values
	private int arabic;			//Total Arabic values
	private Stack s;			//Create New Stack Object
	
	/**
	 * Initializing instance variables
	 */
	public Numbers()
	{
		roman = "";
		arabic = 0;
		s = new Stack();	//New Stack	
	}
	
	/**
	 * Determine Roman Numerals for Arabic values
	 * @param number - Arabic number
	 */
	public void setRomanNumbers(int number)
	{
		if(number <= ROMANI)
		{
			roman = "I";
		}
		else if(number <= ROMANV)
		{
			roman = "V";
			
		}
		else if(number == ROMANX)
		{
			roman = "X";
		}
		else if(number == ROMANL)
		{
			roman = "L";
		}
		else if(number == ROMANC)
		{
			roman = "C";
		}
		else if(number == ROMAND)
		{
			roman = "D";
		}
		else if(number == ROMANM)
		{
			roman = "M";
		}
	}
	
	/**
	 * Getting total Roman Numeral values
	 * @return	- Total Roman Numeral values
	 */
	public String getRomanNumbers()
	{
		return roman;
	}
	
	/**
	 * Determine Arabic values for Roman Numerals
	 * @param name - Roman Numeral character
	 */
	public void setArabicNumbers(char name)
	{
		if(name == 'I')
		{
			arabic = ROMANI;
		}
		else if(name == 'V')
		{
			arabic = ROMANV;
		}
		else if(name == 'X')
		{
			arabic = ROMANX;
		}
		else if(name == 'L')
		{
			arabic = ROMANL;
		}
		else if(name == 'C')
		{
			arabic = ROMANC;
		}
		else if(name == 'D')
		{
			arabic = ROMAND;
		}
		else if(name == 'M')
		{
			arabic = ROMANM;
		}
	}
	
	/**
	 * Getting total Arabic values
	 * @return - Total Arabic values
	 */
	public int getArabicNumbers()
	{
		return arabic;
	}
	
	/**
	 * Resetting Roman Numerals
	 */
	public void reset()
	{
		roman = "";
		arabic = 0;
	}
	
	/**
	 * Converting Roman Numerals to Arabic numbers
	 * @param input	Roman Numeralsinput
	 * @return	Arabic numbers
	 */
	public int toArabicNumbers(CharList list)
	{
		int current = 0;		//Current Arabic Values
		int previous = 0;		//Previous Arabic Values
		int total = 0;
		boolean exit = false;
		for(int index = 0; index < list.getSize(); index++)
		{
			s.push(list.getChar(index));	//Storing linked list elements into stack
		}
		//Converting into Arabic numbers
		while(!exit)
		{
			if(s.isEmpty())
			{
				exit = true;
			}
			else
			{
				previous = current;
				setArabicNumbers(s.pop());	//Getting top stack element
				current = arabic;
				//Converting into Arabic number
				if(current < previous)
				{
					total -= current;
				}
				else if(current >= previous)
				{
					total += current;
				}
			}
		}
		return total;	//Return Arabic numbers
	}
	
	/**
	 * Converting Arabic numbers into Roman Numerals
	 * @param number - Arabic numbers
	 */
	public String toRomanNumbers(int number)
	{
		String temp = ""; //temporary variable for reversing stack 
		String rome = "";	//Capture reverse stack into a string
		int value = number;
		//Converting into Roman Numerals
		while(value > 0)
		{
			if (value >= ROMANM)
			{
				setRomanNumbers(ROMANM);
				s.push(roman.charAt(0));
				value -= ROMANM;
			}
			else if(value >= ROMANM - ROMANC)
			{
				setRomanNumbers(ROMANC);
				s.push(roman.charAt(0));
				setRomanNumbers(ROMANM);
				s.push(roman.charAt(0));
				value -= ROMANM - ROMANC;
			}
			else if(value >= ROMAND)
			{
				setRomanNumbers(ROMAND);
				s.push(roman.charAt(0));
				value -= ROMAND;
			}
			else if(value >= ROMAND - ROMANC)
			{
				setRomanNumbers(ROMANC);
				s.push(roman.charAt(0));
				setRomanNumbers(ROMAND);
				s.push(roman.charAt(0));
				value -= ROMAND - ROMANC;
			}
			else if(value >= ROMANC)
			{
				setRomanNumbers(ROMANC);
				s.push(roman.charAt(0));
				value -= ROMANC;
			}
			else if(value >= ROMANC - ROMANX)
			{
				setRomanNumbers(ROMANX);
				s.push(roman.charAt(0));
				setRomanNumbers(ROMANC);
				s.push(roman.charAt(0));
				value -= ROMANC - ROMANX;
			}
			else if(value >= ROMANL)
			{
				setRomanNumbers(ROMANL);
				s.push(roman.charAt(0));
				value -= ROMANL;
			}
			else if(value >= ROMANL - ROMANX)
			{
				setRomanNumbers(ROMANX);
				s.push(roman.charAt(0));
				setRomanNumbers(ROMANL);
				s.push(roman.charAt(0));
				value -= ROMANL - ROMANX;
			}
			else if(value >= ROMANX)
			{
				setRomanNumbers(ROMANX);
				s.push(roman.charAt(0));
				value -= ROMANX;
			}
			else if(value >= ROMANX - ROMANI)
			{
				setRomanNumbers(ROMANI);
				s.push(roman.charAt(0));
				setRomanNumbers(ROMANX);
				s.push(roman.charAt(0));
				value -= ROMANX;
			}
			else if(value >= ROMANV)
			{
				setRomanNumbers(ROMANV);
				s.push(roman.charAt(0));
				value -= ROMANV;
			}
			else if(value >= ROMANV - ROMANI)
			{
				setRomanNumbers(ROMANI);
				s.push(roman.charAt(0));
				setRomanNumbers(ROMANV);
				s.push(roman.charAt(0));
				value -= ROMANV - ROMANI;
			}
			else
			{
				setRomanNumbers(ROMANI);
				s.push(roman.charAt(0));
				value -= ROMANI;
			}
		}
		while(!s.isEmpty())
		{
			temp += s.pop();	//Removing elements from stack
		}
		for(int index = temp.length() - 1 ; index >= 0; index--)
		{
			rome += temp.charAt(index);	////Reversing stack
		}
		return rome;	//Return Roman Numerals
	}
	
	/**
	 * Calculating Arabic numbers
	 * @param input	- Roman Numerals input
	 * @return - Total Arabic values
	 */
	public int calculate(String input, int left, int right)
	{
		int total = 0;
		//Calculate total of Roman Numerals expression into Arabic numbers
		for(int index = 0; index < input.length(); index++)
		{
			if(input.charAt(index) == '*')
			{
				total = left * right;
			}
			else if(input.charAt(index) == '/')
			{
				total = left / right;
			}
			else if(input.charAt(index) == '+')
			{
				total = left + right;
			}
			else if(input.charAt(index) == '-')
			{
				total = left - right;
			}
		}
		return total;	//Return total of Arabic numbers
	}
	
	/**
	 * Testing valid Roman Numerals input
	 * @param input - Roman Numerals
	 * @return - true if valid
	 */
	
	public boolean check(CharList left, CharList right)
	{
		/*
		 * Local variables
		 */
		String leftSide = "";
		String rightSide = "";
		for(int index = 0; index < left.getSize(); index++)
		{
			leftSide += left.getChar(index);
		}
		for(int index = 0; index < right.getSize(); index++)
		{
			rightSide += right.getChar(index);
		}
		String leftRoman = "";
		String rightRoman = "";
		int leftArabic = 0;
		int rightArabic = 0;
		boolean isRoman = true;
		leftArabic = toArabicNumbers(left);			//Get left Arabic values
		rightArabic = toArabicNumbers(right);		//Get right Arabic values
		leftRoman = toRomanNumbers(leftArabic);		//Get left Roman Values
		rightRoman = toRomanNumbers(rightArabic);	//Get right Roman Values
		if(!(leftRoman.equals(leftSide) || !(rightRoman.equals(rightSide))))
		{
			isRoman = false;	//Invalid Roman Numerals input
		}
		return isRoman;	//Return if it's valid Roman Numerals
	
	}
}
