
public class CardSearch {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Card newCard = new Card(3, 2);
		CardSearch Card = new CardSearch();
		System.out.println("The Count: " + Card.linearSearch(newCard));

	}
	
	public int linearSearch(Card tempCard)
	{
		Deck newDeck = new Deck();
		Card searchCard;
		int count = 0;
		boolean search = false;
		newDeck.shuffle();
		while(!search)
		{
			for(int index = 0; index < 52; index++)
			{
				searchCard = newDeck.deal();
				if(searchCard == tempCard)
				{
					search = true;
					count = index;
				}
			}
		}
		return count;
	}

}
