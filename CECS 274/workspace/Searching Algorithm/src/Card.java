public class Card 
{
	//Constant variables
	public static final String SUIT_SPADE = "Spade";
	public static final String SUIT_CLUB = "Club";
	public static final String SUIT_DIAMOND = "Diamond";
	public static final String SUIT_HEART = "Heart";
	public static final String CARD_ACE = "A";
	public static final String CARD_JACK = "J";
	public static final String CARD_QUEEN = "Q";
	public static final String CARD_KING = "K";
	
	//Instance variables
	int suit = 0;
	int value = 0;
	
	public Card(int initialValue, int initialSuit)
	{
		value = initialValue;
		suit = initialSuit; 
	}
	
	//Return card value
	
	public int getValue()
	{
		
		return value;
	}
	
	//Input card value
	public void setValue(int amount)
	{
			value = amount;		
	}
	
	//Return a card suite
	public int getSuit()
	{
		return suit;
	}
	
	//Set a card suite
	public void setSuit(int amount)
	{
		suit = amount;
	}	
	
	public String toString()
	{
		String stringValue = "";
		String stringSuit = "";

		if(suit == 1)
		{
			stringSuit = SUIT_SPADE;
		}
		else if(suit == 2)
		{
			stringSuit = SUIT_CLUB;
		}
		else if(suit == 3)
		{
			stringSuit = SUIT_DIAMOND;
		}
		else if(suit == 4)
		{
			stringSuit = SUIT_HEART;
		}
		
		if(value == 1)
		{
			stringValue = CARD_ACE;
		}
		else if(value == 11)
		{
			stringValue = CARD_JACK;
		}
		else if(value == 12)
		{
			stringValue = CARD_QUEEN;
		}
		else if(value == 13)
		{
			stringValue = CARD_KING;
		}
				
		else
		{
			stringValue = String.valueOf(value);
		}
		
		return (stringValue + " of " + stringSuit);
	}
}