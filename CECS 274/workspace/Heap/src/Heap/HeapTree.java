package Heap;

public class HeapTree {
	private static final int childrenPerParent = 2;
	private int[] heap;
	private int size;
	
	public HeapTree(int[] data)
	{
		heap = data;
		size = 0;
	}
	public HeapTree(int[] data, int number)
	{
		heap = data;
		size = data.length;
	}
	
	public int getLeftChild(int index)
	{
		return (2 * index) + 1;
	}
	
	public int getRightChild(int index)
	{
		return (2 * index) + 2;
	}
	
	public int getParent(int index)
	{
		return (index - 1) / 2;
	}
	
	public int[] getHeap()
	{
		return heap;
	}
	
	public int size()
	{
		return size;
	}
	
	public void insert(int number)
	{
		if(size == heap.length)
		{
			System.out.println ("Heap is overflow");
		}
		size++;
		int current = size - 1;
		heap[current] = number;
		shiftUp(current);
	}
	
	public void remove(int number)
	{
		int value = heap[number];
		int temp = value;
		int child = 0;
		int position = 0;
		if(size == 0)
		{
			System.out.println("Heap is empty");
		}
		
		heap[number] = heap[size - 1];
		size--;
		int index = 2;
		position = (childrenPerParent * number) + index;
		while(((childrenPerParent * number) + 1) < size)
		{
			child = (childrenPerParent * number) + 1;
			
			while((index <= childrenPerParent) && (position < size))
			{
				if(heap[position] < heap[child])
				{
					child = position;
				}
				index++;
				position = (childrenPerParent * number) + index;
			}
			
			if(heap[child] < temp)
			{
				heap[number] = heap[child];
			}
			else
			{
				break;
			}
			number = child;
		}
		heap[number] = temp;
	}
	
	public void shiftUp(int index)
	{
		int parent = getParent(index);
		if(index == 0)
		{
			return;
		}
		
		while(heap[parent] > heap[index] && parent >= 0)
		{
			swap(heap, index, parent);
			index = parent;
			parent = getParent(index);
		}
	}
	
	public void heapify(int[] data)
	{
		for(int index = (size / 2) - 1; index >= 0; index--)
		{
			maxHeap(data, index);
		}
	}
	
	public void maxHeap(int[] data, int index)
	{
		int biggest = index;
		int leftChild = getLeftChild(index);
		int rightChild = getRightChild(index);
		
		if(leftChild < size && data[leftChild] < data[biggest])
		{
			biggest = leftChild;
		}
		
		if(rightChild < size && data[rightChild] < data[biggest])
		{
			biggest = rightChild;
		}
		
		if(biggest != index)
		{
			swap(data, biggest, index);
			maxHeap(data, biggest);
		}
	}
	
	public void minHeap(int[] data, int index)
	{
		int biggest = index;
		int leftChild = (2 * index) + 1;
		int rightChild = (2 * index) + 2;
		
		if(leftChild < size && data[leftChild] > data[biggest])
		{
			biggest = leftChild;
		}
		
		if(rightChild < size && data[rightChild] > data[biggest])
		{
			biggest = rightChild;
		}
		
		if(biggest != index)
		{
			swap(data, biggest, index);
			minHeap(data, biggest);
		}
	}
	
	public int removeMax()
	{
		if(size == 0)
		{
			System.out.println("No Such Element");
		}
		int next = heap[0];
		heap[0] = heap[--size];
		maxHeap(heap, 0);
		return next;
		
	}
	
	public int removeMin()
	{
		if(size == 0)
		{
			System.out.println("No Such Element");
		}
		int next = heap[0];
		heap[0] = heap[--size];
		minHeap(heap, 0);
		return next;
		
	}
	
	private void swap(int[] array, int big, int index)
	{
		int temp = array[index];
		array[index] = array[big];
		array[big] = temp;
	}
		
	public int[] sortMax(int[] data)
	{
		for(int index = size -1 ; index >= 0; index--)
		{
			int next = removeMax();
			data[index] = next;
		}
		return data;
	}
	
	public int[] sortMin(int[] data)
	{
		for(int index = size -1 ; index >= 0; index--)
		{
			int next = removeMin();
			data[index] = next;
		}
		return data;
	}
	
	public void showHeap()
	{
		System.out.print("Sorted Heap: ");
		for (int index = 0; index < heap.length; index++)
		{
			System.out.print(heap[index]);
		}
	}
}