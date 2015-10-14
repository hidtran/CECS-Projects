import java.util.Scanner;

public class Hand {
	Card[] myHand; // Create a hand of card
	int handSize; //Card size of hand
	Scanner input = new Scanner(System.in);
	
	public Hand(int amount)
	{
		myHand = new Card[amount];
		handSize = 0;
	}
	
	public int handValue()
	{
		int cardValue = 0;
		int total = 0;
		int ace = 0;
		
		//Calculate hand values
		for(int index = 0; index < handSize; index++)
		{	
			if (total < 21)
			{
				cardValue = myHand[index].getValue(); 
				if(cardValue == 1)
				{
					ace++;
					total += 11;
					if(total > 21)
					{
						total -= 10;
						ace--;
					}
				}
				else if(cardValue >= 11 && cardValue <= 13)
				{
					total += 10;
					if(ace > 0)
					{
						if(total > 21)
						{
							total -= 10;
							ace --;
						}
					}
				}
				else if(cardValue >= 2 && cardValue <= 10)
				{
					total += cardValue;
					if(ace > 0)
					{	
						if(total > 21)
						{
							total -= 10;
							ace --;
						}
					}
				}
			}
		}
		return total;
	}

	
	public void addCard(Card newHand)
	{
		myHand[handSize++] = newHand; //Add a card to a hand
	}
	
	public int getHandSize()
	{
		return handSize; //Return current hand size
	}
	public int resetHand()
	{
		handSize = 0; //Reset hand size
		return handSize;
	}
	
	public void showHand()
	{
		//Show current hand
		for (int index = 0; index < handSize; index++)
		{
			System.out.println(myHand[index].toString());
		}
	}
	
}