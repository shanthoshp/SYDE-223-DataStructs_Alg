#include "lab4_priority_queue.hpp"
#include <string>
#include <iostream>
using namespace std;

// PURPOSE: Parametric constructor 
// initializes heap to an array of (n_capacity + 1) elements
PriorityQueue::PriorityQueue(unsigned int n_capacity) {
  size = 0;
  capacity = n_capacity;
  heap = new TaskItem*[n_capacity + 1]();
}

// PURPOSE: Explicit destructor of the class PriorityQueue
PriorityQueue::~PriorityQueue() {
  
  for (int i = 0; i <= size; i++) {
    delete heap[i];
    heap[i] = NULL;
  }

  delete[] heap; 
  heap = NULL;
}

// PURPOSE: Returns the number of elements in the priority queue
unsigned int PriorityQueue::get_size() const {
	return size;
}

// PURPOSE: Returns true if the priority queue is empty; false, otherwise
bool PriorityQueue::empty() const { 
  if (size == 0) return true;
  return false;
}

// PURPOSE: Returns true if the priority queue is full; false, otherwise
bool PriorityQueue::full() const {
	if (size == capacity) return true;
  return false;
}

// PURPOSE: Prints the contents of the priority queue; format not specified
void PriorityQueue::print() const {
  for (int i = 0; i < size; i++) {
    cout << "Priority: " << heap[i] -> priority << " " << "Description: " << " " << heap[i] -> description << endl;
  }
}

// PURPOSE: Returns the max element of the priority queue without removing it
// if the priority queue is empty, it returns (-1, "N/A")
PriorityQueue::TaskItem PriorityQueue::max() const {
  if (empty()) return TaskItem(-1, "NULL");
  else return *heap[1];
}

// PURPOSE: Inserts the given value into the priority queue
// re-arranges the elements back into a heap
// returns true if successful and false otherwise
// priority queue does not change in capacity
bool PriorityQueue::enqueue( TaskItem val ) {
  if (full()) return false;
  if (size == 0) heap[1] = new TaskItem(val.priority, val.description);
  else {
    int mover = size + 1;
    heap[mover] = new TaskItem(val.priority, val.description);

    while (mover > 1 && heap[mover/2] -> priority < heap[mover] -> priority) {
      TaskItem *temp = heap[mover];
      heap[mover] = heap[mover/2];
      heap[mover/2] = temp;
      mover /= 2;
    }
  }

  size++;
  return true;
}

// PURPOSE: Removes the top element with the maximum priority
// re-arranges the remaining elements back into a heap
// returns true if successful and false otherwise
// priority queue does not change in capacity
bool PriorityQueue::dequeue() {
	if (empty()) return false;
  
  if (size == 1) {
    delete heap[1];
    heap[1] = NULL;
  } else {
    TaskItem *temp = heap[size];
    heap[size] = heap[1];
    heap[1] = temp;
    delete heap[size];
    heap[size] = NULL;
  }
  
  size--;
  return true;
}
