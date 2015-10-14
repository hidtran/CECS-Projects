package Heap;

/**
 * Randomizing integers from 10-99 into tree and array
 * Convert tree to heap
 * @author tom
 *
 */
public class Tree {
	private Node root = null;	//Null root node
	
	/**
	 * Empty tree
	 */
	public Tree()
	{
		root = null;	//Empty root node
	}
	
	/**
	 * Non-empty tree
	 * @param number
	 */
	public Tree(int number)
	{
		root = new Node(number);	//Non-empty root node
	}
	
	/**
	 * Recursive help to insert item into tree
	 * @param number - user input integer
	 */
	public void insert(int number)
	{
		root = add(root, number);
	}
	
	/**
	 * Insert new item into tree list
	 * @param parent - parent node pointer
	 * @param number - integer to be insert
	 * @return	- update tree list
	 */
	private Node add(Node parent, int number)
	{
		if(parent == null)
		{
			parent = new Node(number);	//Insert into root pointer node
		}
		else
		{
			if(number == parent.data)
			{
				System.out.println("Duplicate item on tree list");	//Error message for duplicate item
			}
			else if(number < parent.data)
			{
				parent.left = add(parent.left, number);	//Insert into left pointer node
			}
			else if(number > parent.data)
			{
				parent.right = add(parent.right, number);	//Insert into right pointer node
			}
		}
		return parent;
	}
	
	/**
	 * Remove an item from tree list
	 * @param number - item to be remove
	 * @return - update tree list
	 */
	public Node remove(int number)
	{
		Node current = root;	//Current pointer node
		Node parent = root;		//Parent pointer node
		Node grandparent = null;
		boolean foundLeftChild = false;	
		
		while(current.data != number)
		{
			parent = current;
			if(number < current.data)
			{
				foundLeftChild = true;	//Left child exist
				current = current.left;
			}
			else
			{
				foundLeftChild = false;	//Right child exist
				current = current.right;
			}
			if(current == null)
			{
				System.out.println("Item not found");	//Unable to find item in the tree list
				return root;
			}
		}
		
		//parent with no children
		if(current.left == null && current.right == null)
		{
			if(current == root)
			{
				root = null;	//No children
			}
			else if(foundLeftChild)
			{
				parent.left = null;		//No parent left child
			}
			else
			{
				parent.right = null;	//No parent right child
			}
		}
		//parent with left children
		else if(current.right == null)
		{
			if(current == root)
			{
				root = current.left;	//No right child
			}
			else if(foundLeftChild)
			{
				parent.left = current.left;		//No right child
			}
			else
			{
				parent.right = current.left;	//No left child
			}
		}
		//parent with right children
		else if(current.left == null)
		{
			if(current == root)
			{
				root = current.right;	//No left child
			}
			else if(foundLeftChild)
			{
				parent.left = current.right;	//No right child
			}
			else
			{
				parent.right = current.left;	//No left child
			}
		}
		//parent with 2 children
		else
		{
			Node child = delete(current);	//replace node pointer
			if(current == root)
			{
				root = child;	//No children
			}
			else if(foundLeftChild)
			{
				parent.left = child;	//No right child
			}
			else
			{
				parent.right = child;	//No left child
			}
			child.left = current.left;
			grandparent = child;	//updated tree list
		}
		System.out.println(number + " removes from the tree list");
		return grandparent;
	}
	
	/**
	 * Recursive helper to remove item from tree list
	 * @param child	- tree list
	 * @return - update tree list
	 */
	private Node delete(Node child)
	{
		Node parent = child;	//parent node pointer
		Node replaceNode = child;	//replace node pointer
		
		Node current = child.right;		//current node pointer
		
		while(current != null)
		{
			parent = child;		//updated parent pointer
			replaceNode = current;	
			current = current.left;		//updated current node pointer
		}
		return replaceNode;
	}
	
	/**
	 * Search for an item in tree list
	 * @param number - item to be search
	 */
	public void search(int number)
	{
		Node current = root;	//Current node pointer
		int count = 0;	//tree level counter
		boolean found = false;
		while(!found && current != null)
		{
			if(current.data == number)
			{
				System.out.println("Item is on level " + count++);	//Current tree level item is in
				found = true;
			}
			else if(current.data > number)
			{
				current = current.left;		//item on left side of tree list
				count++;
			}
			else if(current.data < number)
			{
				current = current.right;	//item on right side of tree list
				count++;
			}
		}
		if(current == null)
		{
			if(!found)
			{
				System.out.println("Item is not found.");	//Unable to find item
			}
		}
	}
		
	/**
	 * Determine depth of tree list
	 * @return - depth of tree
	 */
	public int depth()
	{
		int length = depth(root);
		return length;
	}
	
	/**
	 * Recursive helper to determine depth of tree list
	 * @param current - current tree list
	 * @return - update tree list
	 */
	private int depth(Node current)
	{
		if(current == null)
		{
			return 0;
		}
		else
		{
			int left = depth(current.left);	//Count tree left side
			int right = depth(current.right);	///Count tree right side
			if(left > right)
			{
				return left+1;
			}
			else
			{
				return right+1;
			}
		}
	}
	
	/**
	 * Determine total number of items in the tree
	 * @return - total number of items
	 */
	public int size()
	{
		int length = size(root);
		return length;
		
	}
	
	/**
	 * Recursive helper to determine total number of items in the tree
	 * @param current - current tree list
	 * @return - total number of items
	 */
	private int size(Node current)
	{
		int length = 0;
		if(current == null)
		{
			return length;
		}
		else
		{
			length = 1 + size(current.left) + size(current.right); //Recursive call for tree size
		}
		return length;
	}
	
	/**
	 * Convert tree to array
	 * @return	- array
	 */
	public int[] toArray()
	{
		Node current = root;
		int[] array = new int[32];
		int index = 0;
		toArray(current, array, index);	// Recursively convert tree to array
		return array;
	}
	
	/**
	 * Recursive helper to convert tree to array
	 * @param parent - parent node
	 * @param array	- array input
	 * @param index - index of array
	 * @return
	 */
	private static int toArray(Node parent, int[] array, int index)
	{
		if(parent == null)
		{
			return 0;
		}
		else
		{
			array[index++] = parent.data;
			if(parent.left != null)
			{
				index = toArray(parent.left, array, index);
			}
			if(parent.right != null)
			{
				index = toArray(parent.right, array, index);
			}
		}
		return index;
	}
	
	/**
	 * Convert to Heap
	 * @param data - array input
	 */
	public void displayHeap(int[] data)
	{
		try{
			System.out.println("                                      " + data[0]);
			System.out.println("                                      |");
			System.out.println("                  "+data[1]+ "------------------^------------------"+data[2]);
			System.out.println("                  |                                      |");
			System.out.println("        "+data[3]+ "--------^--------"+data[4]+"                  "+ data[5]+"--------^--------"+data[6]);
			System.out.println("        |                  |                   |                  |");
			System.out.println("   "+data[7]+"---^---"+data[8]+"        "+data[9]+"---^---"+data[10]+"         "+data[11]+"---^---"+data[12]+"         "+data[13]+"---^---"+data[14]);
			System.out.println("   |        |         |        |          |        |          |        |");
			System.out.println(""+data[15]+"-^-"+data[16]+"  "+data[17]+"-^-"+data[18]+"   "+data[19]+"-^-"+data[20]+"  "+data[21]+"-^-"+
					data[22]+"    "+data[23]+"-^-"+data[24]+"  "+data[25]+"-^-"+data[26]+"    "+data[27]+"-^-"+data[28]+"  "+data[29]+"-^-"+data[30]);
			System.out.println("-------------------------------------------------------------------------------");
			System.out.println("-------------------------------------------------------------------------------");
		}catch(Exception e){
			System.out.println("Tree is Empty!");
		}
	}
	
	/**
	 * Display Heap from largest to smallest
	 * @param data - array input
	 */
	public void displayLargestToSmallest(int[] data)
	{
		try{
			System.out.println("                                      " + data[30]);
			System.out.println("                                      |");
			System.out.println("                  "+data[29]+ "------------------^------------------"+data[28]);
			System.out.println("                  |                                      |");
			System.out.println("        "+data[27]+ "--------^--------"+data[26]+"                  "+ data[25]+"--------^--------"+data[24]);
			System.out.println("        |                  |                   |                  |");
			System.out.println("   "+data[23]+"---^---"+data[22]+"        "+data[21]+"---^---"+data[20]+"         "+data[19]+"---^---"+data[18]+"         "+data[17]+"---^---"+data[16]);
			System.out.println("   |        |         |        |          |        |          |        |");
			System.out.println(""+data[15]+"-^-"+data[14]+"  "+data[13]+"-^-"+data[12]+"   "+data[11]+"-^-"+data[10]+"  "+data[9]+"-^-"+
					data[8]+"    "+data[7]+"-^-"+data[6]+"  "+data[5]+"-^-"+data[4]+"    "+data[3]+"-^-"+data[2]+"  "+data[1]+"-^-"+data[0]);
			System.out.println("-------------------------------------------------------------------------------");
			System.out.println("-------------------------------------------------------------------------------");
		}catch(Exception e){
			System.out.println("Tree is empty");
		}
	}
	
	/**
	 * Print current tree list
	 */
	public void inOrderDisplay()
	{
		inOrderSearch(root);
		System.out.println();
	}
	
	/**
	 * Recursive helper to print current tree list
	 * @param parent - current tree list
	 */
	private static void inOrderSearch(Node parent)
	{
		if(parent == null)
		{
			return;
		}
		inOrderSearch(parent.left);
		System.out.print(parent.data + " ");
		inOrderSearch(parent.right);
	}
	
	/**
	 * Recursively printing tree in pre-order search
	 * @param parent
	 */
	private static void preOrderSearch(Node parent)
	{
		if(parent == null)
		{
			return;
		}
		System.out.println("Tree Pre-Order List: " + parent.data + " " );
		preOrderSearch(parent.left);
		preOrderSearch(parent.right);
	}
	
	/**
	 * Recursively printing tree in post-order search
	 * @param parent
	 */
	private static void postOrderSearch(Node parent)
	{
		if (parent == null)
		{
			return;
		}
		preOrderSearch(parent.left);
		preOrderSearch(parent.right);
		System.out.println("Tree Post-Order List: " + parent.data + " " );
	}
	
	/**
	 * Print current root value
	 */
	public void rootValue()
	{
		System.out.println("Root value: " + root.data);
	}

	/**
	 * Stores reference to next item in the tree
	 * @author tom
	 *
	 */
	private class Node {
		private int data; 	////Node can store data as integer but code can be tweaked to store ArrayList or any other java object.
		private Node left;	//stores reference to next left item in the tree
		private Node right;	//stores reference to next right item in the tree
		
		/**
		 * Empty node constructor
		 */
		public Node()
		{
			data = 0;	//Null character
			left = null;	//Null next node
			right = null;
		}
		
		/**
		 * Non-empty node constructor
		 * @param input
		 */
		public Node(int input)
		{
			data = input;	//New node character
			left = null;	//Null left node
			right = null;	//Null right Node
		}
		
		/**
		 * Get current node store data
		 * @return
		 */
		public int getData()
		{
			return data;	//Return a node character
		}
		
		/**
		 * Set current node store data
		 * @param input
		 */
		public void setData(int input)
		{
			data = input;	//Set new node characterStringString
			left = null;	//Null left node
			right = null;	//Null right node
		}
		
		/**
		 * Set current tree children node
		 * @param leftSide	- left node of the tree
		 * @param rightSide	- right node of the tree
		 */
		public void setChildren(Node leftSide, Node rightSide)
		{
			left = leftSide;	//Set left node
			right = rightSide; //Set right node
		}
		
		/**
		 * Get left node of the tree
		 * @return - left node of the tree
		 */
		public Node getLeftChildren() {
			return left;	//Return left node
		}
		
		/**
		 * Get right node of the tree
		 * @return - right node of the tree
		 */
		public Node getRightChildren()
		{
			return right;	//Return right node
		}
	}
}	