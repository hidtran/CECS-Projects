import java.util.Scanner;

public class BlackJack {
	
	public static final int HANDSIZE = 12;
	public static Hand dealer = new Hand(HANDSIZE);
	public static Hand player = new Hand(HANDSIZE);
	public static Deck newDeck = new Deck();
	public static Card newCard;
	public static String unknownCard = "???? of ????";
	public static Scanner input = new Scanner(System.in);

	public static void main(String[] args) 
	{	
		menu();//Initial blackjack menu
	}
	
	public static void menu()
	{
		int userChoice = 0;
		Deck playerDeck = new Deck();
		Hand playerHand = new Hand(HANDSIZE);
		Card playerCard;
		boolean exit = false;
		//creating a menu
		do{
			System.out.println("Choose one of the following options: ");
			System.out.println("1: Create New Deck");
			System.out.println("2: Deal 4 Cards & Show The Remaining Cards");
			System.out.println("3: Shuffle The Cards & Show The Cards");
			System.out.println("4: Play The Black Jack Game");
			System.out.println("5: Quit");
			userChoice = input.nextInt();
			
			switch(userChoice){
			case 1: // Create new deck
				System.out.println("New Deck: \n");
				playerDeck = new Deck();
				playerDeck.showDeck();
				playerHand.resetHand();
				break;
			case 2: //Deal 4 cards & Show The Remaining cards
				int total = 4;
				for(int index = 0; index < total; index++)
				{
					playerCard = playerDeck.deal();
					playerHand.addCard(playerCard);
					playerDeck.removeCard(playerCard);
				}
				System.out.println("Your Current Hand:\n");
				playerHand.showHand();
				System.out.println("\nYour Remaining Deck:\n");
				playerDeck.remainingDeck();
				break;
			case 3: //Shuffle the deck & Show the deck
				playerDeck.shuffle();
				playerDeck.showDeck();
				break;
			case 4: //Play BlackJack
				playBlackJack();
				break;
			case 5:
				exit = true;
				break;
			default:
				System.out.println("Invalid input");
				break;
			}
		}while(!exit);
	}

	//Update Player's playing money
	public int updateAmount(int total, int bet)
	{
		int betAmount = bet;
		int totalAmount = total;
		if(player.handValue() > 21)
		{
			System.out.println("Dealer Wins!");
			totalAmount = totalAmount - betAmount;
		}
		else if(dealer.handValue() > 21)
		{
			System.out.println("Player Wins!");
			totalAmount = totalAmount + betAmount;
		}
		else if(player.handValue() == dealer.handValue())
		{
			System.out.println("Dealer Wins!");
			totalAmount = totalAmount - betAmount;
		}
		else if(player.handValue() < 21 && dealer.handValue() < 21)
		{
			if(player.handValue() > dealer.handValue())
			{
				System.out.println("Player Wins!");
				totalAmount = totalAmount + betAmount;
			}
			else
			{
				System.out.println("Dealer Wins!");
				totalAmount = totalAmount - betAmount;
			}
		}
		else if(player.handValue() == 21 || dealer.handValue() == 21)
		{
			if(dealer.handValue() < player.handValue())
			{
				System.out.println("Player Wins!");
				totalAmount = totalAmount + betAmount;
			}
			else if(dealer.handValue() == player.handValue())
			{
				System.out.println("Dealer Wins!");
				totalAmount = totalAmount - betAmount;
			}
			else if(dealer.handValue() > player.handValue())
			{
				System.out.println("Dealer Wins!");
				totalAmount = totalAmount - betAmount;
			}
		}
		return totalAmount;
	}
	
	public static void draw()
	{
		boolean playerStay = false;
		boolean dealerStay = false;
		//Draw card for player
		if(player.handValue() < 21)
		{
			do
			{
				System.out.println("Would you like to hit (Y or N)?");
				String choose = input.next().toLowerCase();
				switch(choose.charAt(0))
				{
				case 'n':
					playerStay= true;
					break;
				case 'y':
					//deal new card to player's hand
					newCard = newDeck.deal();
					player.addCard(newCard);
					System.out.println("Player gets a " + newCard.toString());
					System.out.println("Player Hand Value: " + player.handValue());
					player.showHand();
					break;
				default:
					System.out.println("Invalid Selection.");
					break;
				}
			}while(!playerStay && player.handValue() < 21);
		}
		if(dealer.handValue() < 21 && player.handValue() <= 21)
		{
			do
			{
				if(player.handValue() > dealer.handValue())
				{
					if(!(player.handValue() > 21))
					{
						newCard = newDeck.deal();
						dealer.addCard(newCard);
						System.out.println("Dealer draws a " + newCard.toString());
						newDeck.removeCard(newCard);
						dealer.showHand();
					}
					else
					{
						dealerStay = true;
						break;
					}
				}
				else
				{
					System.out.println("Dealer Hand Value: " + dealer.handValue());
					dealer.showHand();
					dealerStay = true;
				}
			}while(!dealerStay);
		}
		else if(player.handValue() > 21 && dealer.handValue() <= 21)
		{
			//Show Dealer's current hand
			System.out.println("Dealer Hand Value: " + dealer.handValue());
			dealer.showHand();
			//Draw card for dealer
		}
	}


	public static void playBlackJack()
	{
		int amount = 100;
		int bet = 0;
		boolean out = false;
		String showCard = "";
		BlackJack bj = new BlackJack();
		do
		{
			//Player making bet
			System.out.println("You have $" + amount + ". How much would like to bet (0 to quit)?");
			bet = input.nextInt();
			//Check for valid input
			
			if(bet > amount || bet < 0)
			{
				System.out.println("Insufficent Amount To Bet."); //Display invalid input
				continue;
			}
			else if(bet == 0)
			{
				out = true;
				break;
			}
			//Create new deck if deck < 20 cards
			if(newDeck.top < 20)
			{
				newDeck = new Deck(); //Create new deck
				newDeck.shuffle(); //Shuffle the new deck
			}
			newDeck.shuffle(); //Shuffle the deck
			//Draw 2 card for player's hand
			for(int i = 0; i < 2; i++)
			{
				//add cards to player's hand
				newCard = newDeck.deal();
				player.addCard(newCard);
				newDeck.removeCard(newCard);
				
			}
			//Draw 2 cards for Dealer's hand
			for(int j = 0; j < player.getHandSize(); j++)
			{
				//add cards to dealer's hand
				newCard = newDeck.deal();
				dealer.addCard(newCard);
				newDeck.removeCard(newCard);
				if(j == 1)
				{
					showCard = newCard.toString();
				}
			}
			//Display player hands & hands value on player side
			System.out.println("Your Hand Value: " + player.handValue());
			player.showHand();
			//Show dealer second card to the player
			System.out.println("\nDealer Hand:\n");
			System.out.println(unknownCard);
			System.out.println(showCard);
			draw();
			//Display new player's playing money
			if(player.handValue() < 21 && dealer.handValue() < 21)
			{
				amount = bj.updateAmount(amount, bet);
				System.out.println("Total: " + amount);
				player.resetHand(); //Reset player's hand
				dealer.resetHand(); //Reset dealer's hand
			}
			else if(player.handValue() > 21 && dealer.handValue() < 21)
			{
				amount = bj.updateAmount(amount,bet);
				System.out.println("Total: " + amount);
				player.resetHand(); //Reset player's hand
				dealer.resetHand(); //Reset dealer's hand
			}
			else if(player.handValue() < 21 && dealer.handValue() > 21)
			{
				amount = bj.updateAmount (amount, bet);
				System.out.println("Total: " + amount);
				player.resetHand(); //Reset player's hand
				dealer.resetHand(); //Reset dealer's hand
			}
			else if(player.handValue() >= 21 || dealer.handValue() >= 21)
			{
				amount = bj.updateAmount(amount, bet);
				System.out.println("Total: " + amount);
				player.resetHand(); //Reset player's hand
				dealer.resetHand(); //Reset dealer's hand
			}
			else if(player.handValue() == dealer.handValue())
			{
				amount = bj.updateAmount(amount, bet);
				System.out.println("Total: " + amount);
				player.resetHand(); //Reset player's hand
				dealer.resetHand(); //Reset dealer's hand
			}
		}while(amount >0 && !out);
		System.out.println("Thank you for playing.");
	}
}
