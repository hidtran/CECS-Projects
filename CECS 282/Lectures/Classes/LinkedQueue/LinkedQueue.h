#ifndef __LINKEDQUEUE_H
#define __LINKEDQUEUE_H

// Demonstrate using dynamic memory management to create a queue of integers.

// Implement the Queue data type using a singly linked list.
class LinkedQueue {
private:
   // A class to store a piece of data, and a link to the next data in the queue
   class Node {
   private:
      int mData;
      // How to store a link to the next Node in the list?
      Node *mNext; // Why a pointer? *To only allocate a specified amount of memory onto the stack.*




      friend class LinkedQueue; //*LinkedQueue has accessed to Node class only*.

   public:
      // Initialize a Node with the given data, and a pointer for the next Node.
      Node(int data, Node *next) : mData(data), mNext(next) {
      }
   };


   // *A linked list is just a pointer to a head node, a pointer to a tail node,
   // and a count of how many nodes there are.*
   Node *mHead;
   Node *mTail;
   int mSize;

public:
   // Default construct an empty queue.
   LinkedQueue();
   // Copy construct a queue with a duplicate of other's data.
   LinkedQueue(const LinkedQueue &other);

<<<<<<< HEAD
	//Destructor
	~LinkedQueue();
=======
   // Destructor
   ~LinkedQueue();

   // Assignment=
   LinkedQueue& operator=(const LinkedQueue &rhs);
>>>>>>> fe7b745c7d6660c025dd5da914234ef1d22d8a35

   // Add an element to the end of the queue.
   void Add(int data);
   // Remove and return the front element from the queue.
   int Remove();
   
   // Give the size of the queue. What does inline mean? Telling the following function really smalls. 
	// Instead of calling, copying the codes inside instead of function jumping.
   inline int Size() const { //Can't change member variable
      return mSize;
   }
};

#endif
