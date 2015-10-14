package bank;
import java.util.*;

public class Queue 
{
	//public LinkedList list;
	LinkedList<String> list = new LinkedList<String>();
	private int size = 0;
	//Initialize the variable
	public Queue()
	{
		list = new LinkedList();
		list.add("Phuong");
		list.add("Charles");
		list.add("Andrew");
		size = 3;
	}
	
	public int getSize(){
		return size;
	}
	
	//Checks if queue is empty
	public boolean isEmpty()
	{
		return (list.size() == 0);
	}
	
	//For inserting at the end
	public void enQ(String o)
	{
		list.add(o);
		size++;
	}
	
	//for removing from the front
	public String deQ(int position)
	{
		String o = (String) list.get(position);
		list.remove(position);
		size--;
		return o;
	}
	
	//For peaking at the top element
	public Object peek(int position)
	{
		return list.get(position);
	}
	
	public void line()
	{
		System.out.println("\nCustomers in line "+list);
		//System.out.println("\nCustomer 1: " +list.get(0));
		//System.out.println("\nCustomer 2: " +list.get(1));
		//System.out.println("\nCustomer 3: " +list.get(2));
	}
}
	