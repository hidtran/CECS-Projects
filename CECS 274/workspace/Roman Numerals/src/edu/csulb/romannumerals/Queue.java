package edu.csulb.romannumerals;
/**
 * Partial implement of a queue for characters
 * @author Hieu Tran
 *
 */
public class Queue {
	Node head= null;
	Node tail= null;
	int length;
	
	public Queue()
	{
		head=null;
		tail=null;
		length=0;
	}
	/**
	 * add a character to the front of the queue
	 * @param item - the character to be added to the queue
	 */
	public void enqueue(char item)
	{
		Node node = new Node(item);
		if (head == null) {
			head = node;
			tail = head;
		} 
		else {
			tail.next = node;
			tail = node;
		}

		length++;
	}
	
	/**
	 * remove and return the character in front of the queue
	 * @return a character at from of the queue
	 */
	public char dequeue()
	{
		Node temp= head;
		head= head.next;
		length--;
		return temp.data;
		
	}
	
	/**
	 * Reverse the queue
	 * @param item - The character to be added the queue
	 */
	public void requeue(char item)
	{
		Node node = new Node(item);
		if (head == null) {
			head = node;
			tail = head;
		} 
		else {
			node.next = head;
			head = node;
			
		}

		length++;
	}
	
	/**
	 * look at the character at the front of the queue
	 * @return
	 */
	public char peek()
	{
		return head.data;
	}
	/**
	 * check to see whether the queue is empty
	 * @return true or false
	 */
	public boolean isEmpty()
	{
		return (length==0);
	}
	
	/**
	 * find out the size of the queue
	 * @return size of the queue
	 */
	public int getSize()
	{
		return length;
	}
	
	/**
	 * override the toString method
	 */
	@Override
	public String toString()
	{
		StringBuilder result = new StringBuilder();
		Node tempNode = null;
		result.append("[");

		if (head != null) {
			for(tempNode = head; tempNode != null; tempNode = tempNode.next) {
				result.append(tempNode.data + " ");
			}
		}

		result.append("]");

		return result.toString();
	}
	/**
	 * it stores reference to next item in the queue
	 * @author Hieu Tran
	 *
	 */
	private class Node {
		//it stores reference to next item in the queue
		public Node next = null;

		//Node can store data as integer but code can be tweaked to store ArrayList or any other java object.
		public char data = 0;

		public Node(char value) {
			this.data = value;
			next = null;
		}
	}
}