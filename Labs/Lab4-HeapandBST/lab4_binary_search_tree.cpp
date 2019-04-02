#include <iostream>
#include "lab4_binary_search_tree.hpp"

using namespace std;

// PURPOSE: Default/empty constructor
BinarySearchTree::BinarySearchTree() {
  size = 0;
  root = NULL;
}

// PURPOSE: Explicit destructor of the class BinarySearchTree
BinarySearchTree::~BinarySearchTree() {
  deleteAllNodes(root);
}

// PURPOSE: HELPER FUNCTION 
void BinarySearchTree:: deleteAllNodes(TaskItem* node) {
  if (node != NULL) {
    deleteAllNodes(node -> left);
    deleteAllNodes(node -> right);
    delete node;
    node = NULL;
  } 
  return;
}

// PURPOSE: Returns the number of nodes in the tree
unsigned int BinarySearchTree::get_size() const {
  return size;
}

// PURPOSE: Returns the maximum value of a node in the tree
// if the tree is empty, it returns (-1, "N/A")
BinarySearchTree::TaskItem BinarySearchTree::max() const {
  if(size == 0) return BinarySearchTree::TaskItem(-1, "N/A");
  else{
    TaskItem* current = root; 
    while (current-> right != NULL) current = current -> right;
    return *current; 
  }

}

// PURPOSE: Returns the minimum value of a node in the tree
// if the tree is empty, it returns (-1, "N/A")
BinarySearchTree::TaskItem BinarySearchTree::min() const {
  if(size == 0) return BinarySearchTree::TaskItem(-1, "N/A");
  else {
    TaskItem* current = root; 
    while (current-> left != NULL) current = current -> left;
    return *current; 
  }
}

// PURPOSE: Returns the tree height
unsigned int BinarySearchTree::height() const {
  int height;
  if (size == 0) return 0;
  height = getHeight(root);
  return height - 1;
}

// PURPOSE: HELPER FUNCTION
unsigned int BinarySearchTree:: getHeight(TaskItem *node) const{
  if (node == NULL) return 0;
  int right = getHeight(node -> right);
  int left = getHeight(node -> left);
  return 1 + std::max(left, right);
}

// PURPOSE: Prints the contents of the tree; format not specified
void BinarySearchTree::print() const {
  PreOrder(root);
}

// PURPOSE: HELPER FUNCTION
void BinarySearchTree:: PreOrder(TaskItem* node) const{
  if (node != NULL) {
    cout << "Priority: " << node -> priority << " Description: " << node -> description << endl;
    PreOrder(node -> left);
    PreOrder(node -> right);
  }
}

// PURPOSE: Returns true if a node with the value val exists in the tree	
// otherwise, returns false
bool BinarySearchTree::exists(BinarySearchTree::TaskItem val) const {
  if (size == 0 || root == NULL) return false;
  return (existsCheck(root, val.priority));
}

bool BinarySearchTree:: existsCheck(TaskItem *node, int val) const{
  if (node == NULL) return false;
  if (node -> priority == val) return true;
  else if (node -> priority < val) return existsCheck(node -> right, val);
  return existsCheck(node -> left, val);
}

// PURPOSE: Optional helper function that returns a pointer to the root node
BinarySearchTree::TaskItem* BinarySearchTree::get_root_node() {
    return NULL;
}

// PURPOSE: Optional helper function that returns the root node pointer address
BinarySearchTree::TaskItem** BinarySearchTree::get_root_node_address() {
    return NULL;
}

// PURPOSE: Optional helper function that gets the maximum depth for a given node
int BinarySearchTree::get_node_depth(BinarySearchTree::TaskItem* n ) const {
	return 0;
}

// PURPOSE: Inserts the value val into the tree if it is unique
// returns true if successful; returns false if val already exists
bool BinarySearchTree::insert(BinarySearchTree::TaskItem val) {
    if (exists(val))return false;
    TaskItem *temp = new TaskItem(val.priority, val.description);
    if (root == NULL || size == 0) root = temp;
    else insertVal(root, temp);
    size++;
    return true;
}

// PURPOSE: HELPER FUNCTION
void BinarySearchTree:: insertVal(TaskItem *node, TaskItem *val){
  if (node -> priority > val -> priority) {
    if (node -> left == NULL) node -> left = val;
    else insertVal(node -> left, val);
  } else {
    if (node -> right == NULL) node -> right = val;
    else insertVal(node -> right, val);
  }
}

// PURPOSE: Removes the node with the value val from the tree
// returns true if successful; returns false otherwise
bool BinarySearchTree::remove(BinarySearchTree::TaskItem val) {
TaskItem* current = root;
  TaskItem* item;
  TaskItem* itemParent;
	TaskItem* parent = NULL;

    if (root == NULL) {
        return false;
    }
		
	while(current != NULL) {
		if (val.priority == current -> priority) {
			item = current -> right;
			itemParent = current;

			if (item != NULL) {
				while (item -> left != NULL) {
					itemParent = item;
					item = item -> left; //min val;
				}	
				item -> left = current->left;

				if (itemParent -> left && item -> priority == itemParent -> left -> priority) itemParent -> left = NULL;
        else itemParent -> right = NULL;        
			} else item = current -> left;
          
      if (parent != NULL) {
        if (current == parent -> left) parent -> left = item;
        else parent -> right = item;
      } else root = item;
    
      if (current -> right && item != current -> right) {
				while (item -> right != NULL) item = item -> right;			
				item -> right = current -> right;
			}
			delete current;
			--size;
			return true;
		}

		parent = current;
		if (val.priority < current -> priority) current = current -> left;
    else current = current -> right;	
	}
	return false;
}