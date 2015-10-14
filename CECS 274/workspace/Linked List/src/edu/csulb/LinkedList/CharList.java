package edu.csulb.LinkedList;

/**
 * @author Hieu Tran
 * This class will instantiate linked list of character
 */

public class CharList {
		/*
		 * Instance variables
		 */
		private Node head = null;	
		private Node tail = null;	
		private int count = 0;		
		/**
		 * create an empty linked list of character
		 */
		public CharList() 
		{
			head = null;
			tail = null;
			count = 0;
		}
		/**
		 * add a node to the end of the list and
		 * node will have a character
		 * @param input the character that will be stored in the node
		 */
		public void add(char input)
		{
			if (head == null)
			{
				head = new Node(input);	//New head node
				tail = head;	//New tail node
			}
			else
			{
				Node newNode = new Node(input);
				tail.setNext(newNode);	//Next tail node
				tail = newNode;	//New tail node
			}
			count++;
		}
		
		/**
		 * remove a node from the list
		 * @param input	character to be removed from the list
		 */
		public void remove(char input)
		{
			Node current = head;	//duplicate the list
			while(current != null)
			{
				if(head.getCharacter() == input)
				{
					head = head.next;	//New first node of the list
					count --;	//reducing list size
					break;
				}
				else
				{
					if(current.next.getCharacter() == input)
					{
						current.next = current.next.next;	//remove a node from the list
						count--;	//reducing list size
						break;
					}
					else
					{
						current = current.next;	//Traverse to next node
					}
				}
			}
		}
		/**
		 * Retrieve the character that stores at index i
		 * @param i is the index of the node in the list
		 * @return the character at the node
		 */
		public char getChar(int i)
		{
			if (i> count-1) return '\0';	//Null node character
			if (i == 0)
				return head.getCharacter();	//Removing head node character
			Node current = head;
			for (int j = 1; j <= i; j++)
				current = current.getNext();	//Removing a node character
			return current.getCharacter();	//Return a node character
		}
		
		/**
		 * show the size of the list
		 * @return the size of the list
		 */
		public int getSize()
		{
			return count;	//Size of the node
		}
		
		/**
		 * Insert a card to the list at position index
		 * @param input character to be inserted
		 * @param index position that the character will be stored
		 *        index must be >=0
		 */
		public void insertAt(char input, int index)
		{
			Node newNode = new Node(input);
			if (index == 0)
			{
				newNode.next = head;	//New next head node
				head = newNode;	//New node
				count++;
			}
			else if (index >= count)
			{
				tail.next = newNode;	//New tail next node
				tail = newNode;		//New tail node
				count++;
			}
			else
			{
				Node current = head;
				for (int i = 1; i<index; i++)
				{
					current = current.next;	//Traversing linked list
				}
				newNode.next = current.next;	//Inserting new node
				current.next = newNode;		//New current node
				count++;
			}
		}
		/**
		* Remove a character at a position index
		* @return the character at that node
		*
		*/
		public char removeAt(int index)
		{
			char currentCharacter = '\0';
			if (index >= count)
				return currentCharacter;	//Remove current node character
			if (index == 0)
			{
				currentCharacter = head.getCharacter();	//Remove head node character
				head = head.next;	//New head node
				count--;
			}
			else
			{
				Node current = head;
				for (int i = 1; i< index; i++)
				{
					current = current.next;	//Traversing linked list
				}
				currentCharacter = current.next.getCharacter();	//Character to be remove
				current.next = current.next.next;	//New current node
				count--;
			}
			
			return currentCharacter;	//Return remove character
		}
		
		/**
		 * Display all characters in the list
		 */
		public void showList()
		{
			Node current = head;
			System.out.print("Link list's data: ");
			while(current != null)
			{
				System.out.print(current.getCharacter()); //Display all characters in the list
				current = current.next;
			}
		}
		
		/**
		 * This class is used be CharList class
		 * @author Hieu Tran
		 *
		 */
		private class Node {
			private char character;
			private Node next;
			
			public Node()
			{
				character = '\0';	//Null character
				next = null;	//Null next node
			}
			public Node(char input)
			{
				character = input;	//New node character
				next = null;	//Null next node
			}
			public char getCharacter()
			{
				return character;	//Return a node character
			}
			public void setCharacter(char input)
			{
				character = input;	//Set new node characterStringString
				next = null;	//Null next node
			}
			public void setNext(Node newNode)
			{
				next = newNode;	//Set next node
			}
			public Node getNext() {
				return next;	//Return next node
			}
		}

}
