#include "LinkedQueue.h"
#include <iostream>
#include <stdexcept>
<<<<<<< HEAD
=======


using std::cout;
using std::endl;
>>>>>>> fe7b745c7d6660c025dd5da914234ef1d22d8a35

// Default construct a LinkedQueue with no elements.
LinkedQueue::LinkedQueue()
   : mHead(nullptr), mTail(nullptr), mSize(0) { // "nullptr" instead of "null"

   // Before continuing, draw a picture of a LinkedQueue variable on the stack.
<<<<<<< HEAD
	// See lecture notes

=======
   cout << "Constructing LinkedQueue" << endl;
>>>>>>> fe7b745c7d6660c025dd5da914234ef1d22d8a35
}


LinkedQueue::LinkedQueue(const LinkedQueue &other)
   : mSize(other.mSize) {
   // This initializer list is the "shallow copy" behavior of the 
   // copy constructor. Is it correct? We'll answer this later.
<<<<<<< HEAD
	
	mHead = nullptr;
	Node *o = other.mHead;
	Node *mine = nullptr;

	for (int index = 0; index < mSize; index++){
		Node *newNode = new Node(o->mData, nullptr);

		if (index == 0){
			mine = mHead = newNode;
		}

		else {
			mine->mNext = newNode;
			mine = newNode;
		}

		o = o->mNext;
	}
		mTail = mine;
=======

   mHead = nullptr;
   Node *o = other.mHead;
   Node *mine = nullptr;

   for (int i = 0; i < other.mSize; i++) {
      Node *n = new Node(o->mData, nullptr);

      if (i == 0) { // this is the first Node I created as a copy
         mHead = n;
      }
      else {
         mine->mNext = n;
      }
      o = o->mNext;
      mine = n;
   }
   mTail = mine;

   cout << "Copy construct, head at " << mHead << endl;

>>>>>>> fe7b745c7d6660c025dd5da914234ef1d22d8a35
}

void LinkedQueue::Add(int data) {
   // Add the new data to the tail of the queue. 
   // Create a Node to hold the data, then link the current "tail" of the queue
   // to the new Node.


   // First case: the queue is empty, so there is no tail.
   if (mSize == 0) {
      // DRAW THIS OUT.
<<<<<<< HEAD
      Node *newNode = new Node(data, nullptr); //Putting new node onto the heap. *Right hand side always evaluated first*
      mHead = mTail = newNode;	//Setting head and tail to the new node

=======
      Node *newNode = new Node(data, nullptr);
      mHead = mTail = newNode;
      cout << "Head at " << mHead << endl;
>>>>>>> fe7b745c7d6660c025dd5da914234ef1d22d8a35


   }
   else {
      Node *newNode = new Node(data, nullptr);
      mTail->mNext = newNode; // *-> - follow the pointer arrow points to*
      mTail = newNode;
   }
   mSize++;
}

int LinkedQueue::Remove() {
   if (mSize == 0) {
      // what do we do?
<<<<<<< HEAD
		throw std::out of range("Queue was empty");
		//Can't return null from primitive types
		//mtail = mHead;
   
=======
      throw std::out_of_range("Queue was empty");
>>>>>>> fe7b745c7d6660c025dd5da914234ef1d22d8a35
   }

   // mHead points to the next item we want to remove. 
   // Make a copy of the data at the head, then redirect the head.
   int data = mHead->mData;
<<<<<<< HEAD
	Node *temp = mHead;
   mHead = mHead->mNext;
	delete temp;
=======
   Node *temp = mHead;
   mHead = mHead->mNext;
   delete temp;


   if (mSize == 1) {
      mTail = nullptr;
   }

>>>>>>> fe7b745c7d6660c025dd5da914234ef1d22d8a35
   // What happens to the old head Node? There is a bug in this code...

	if(mSize == 1)
		mTail = nullptr;

   mSize--;
   return data;
}

<<<<<<< HEAD
LinkedQueue::~LinkedQueue() {

	Node *newNode = mHead;
	while (newNode != nullptr){
		Node *temp = newNode;
		newNode = newNode -> mNext;
		delete temp;
	}
	mHead = nullptr;
	mTail = nullptr;

}

=======

LinkedQueue::~LinkedQueue() {

   cout << "Destruct head " << mHead << endl;
   Node *n = mHead;

   while (n != nullptr) {
      Node *temp = n;
      n = n->mNext;
      delete temp;
   }
}

LinkedQueue& LinkedQueue::operator=(const LinkedQueue &rhs) {
   if (this == &rhs) {
      // this happens when you do something like "x=x";
      // in this case, we don't want to do anything.
      return *this;
   }

   // first, we must clear our existing list of nodes
   if (mHead != nullptr) {
      Node *n = mHead;
      while (n != nullptr) {
         Node *temp = n;
         n = n->mNext;
         delete temp;
      }
   }

   // Now, run our "copy" routine.
   mSize = rhs.mSize;
   mHead = nullptr;
   Node *o = rhs.mHead;
   Node *mine = nullptr;

   for (int i = 0; i < rhs.mSize; i++) {
      Node *n = new Node(o->mData, nullptr);

      if (i == 0) { // this is the first Node I created as a copy
         mHead = n;
      }
      else {
         mine->mNext = n;
      }
      o = o->mNext;
      mine = n;
   }
   mTail = mine;

   return *this;
}


/*

LinkedQueue::~LinkedQueue() {

}



Node *o = other.mHead;
Node *mine = nullptr;
for (int i = 0; i < mSize; i++) {
Node *n = new Node(o->mData, nullptr);
if (i == 0) {
mine = mHead = n;
}
else {
mine->mNext = n;
mine = n;
}

o = o->mNext;
}

mTail = mine;
*/


>>>>>>> fe7b745c7d6660c025dd5da914234ef1d22d8a35
