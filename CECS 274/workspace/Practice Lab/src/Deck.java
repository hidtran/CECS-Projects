import java.util.Random;

public class Deck {
	
	//instance variables
	int top;
	Card[] myDeck;
	
	public Deck()
	{
		top = 52;
		myDeck = new Card[top];
	
		int index = 0;
		
		for(int i = 1; i <= 4; i++)
		{
			for(int j = 1; j <= 13; j++)
			{
				myDeck[index] = new Card(j, i);
				index++;
			}
		}
	}
	
	public void shuffle()
	{
		Random rand = new Random();
		for(int i = top - 1 ; i > 0; i--)
		{
				int index = rand.nextInt(i + 1);
				Card temp = myDeck[i];
				myDeck[i] = myDeck[index];
				myDeck[index] = temp;
		}
	}
	
	public Card draw()
	{
		top = top - 1;
		return myDeck[top];
	}
	
	public Card removeCard(Card newCard)
	{
		for (int first = 0; first < top; first++)
		{
			int last = top;
			if(newCard == myDeck[first])
			{
				myDeck[first] = myDeck[last - 1];
			}
		}
		return myDeck[top];
	}
	
	public void remainingDeck()
	{
		for(int index = 0 ; index < top; index++)
		{
			System.out.println(myDeck[index].toString());
		}
	}
	
	public void showDeck()
	{
		for(int index = 0 ; index < myDeck.length; index++)
		{
			System.out.println(myDeck[index].toString());
		}
	}
}
