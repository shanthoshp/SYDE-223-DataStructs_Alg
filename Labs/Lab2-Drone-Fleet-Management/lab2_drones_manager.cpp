//NAME: SHANTHOSH PUSHPARJAH (20710273) && TANJOT PANESAR(20727567)
//DATE: 02/19/2019

#include "lab2_drones_manager.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

// TODO: Implement all of the listed functions below

DronesManager::DronesManager() {
  size = 0;
  first = NULL;
  last = NULL;
}

DronesManager::~DronesManager() {
  DroneRecord* current = first;
	while (current) {
		current = first->next;
		delete first; 
		first = current;
  }
}

bool operator==(const DronesManager::DroneRecord& lhs, const DronesManager::DroneRecord& rhs) {
	//friend function
  bool sameRecord = true;

  sameRecord = sameRecord && lhs.droneID == rhs.droneID;
  sameRecord = sameRecord && lhs.droneType == rhs.droneType;
  sameRecord = sameRecord && lhs.manufacturer == rhs.manufacturer;
  sameRecord = sameRecord && lhs.description == rhs.description;
  sameRecord = sameRecord && lhs.range == rhs.range;
  sameRecord = sameRecord && lhs.batteryType == rhs.batteryType;
  sameRecord = sameRecord && lhs.yearBought == rhs.yearBought;

  return sameRecord;
}

unsigned int DronesManager::get_size() const {
	return size;
}

bool DronesManager::empty() const {
	if (first == NULL) {
    return true;
  }
  return false;
}

DronesManager::DroneRecord DronesManager::select(unsigned int index) const {
  DroneRecord* temp = first;

  if (first == NULL) {
    return DroneRecord(0);
  } 

  if (index >= size) {
    return *last;
  } 

  for (int i = 0; i < index; i++) {
    temp = temp -> next;
  }

  return *temp;
}

unsigned int DronesManager::search(DroneRecord value) const {
  DroneRecord* temp = first;

  int i = 0;

  if (first == NULL) {
    return 0;
  } 

  while (temp != NULL) {
    if (*temp == value) {
      return i;
    } else {
      temp = temp -> next;
      i++;
    }
  }

  return size;
}

void DronesManager::print() const {
    DroneRecord* temp = first;
    for (int i = 0; i < size; i++) {
      cout << "index " << i << ": " << "id: " << temp -> droneID << " range: " << temp -> range << " yearBought: " << temp -> yearBought << " droneType: " << temp -> droneType << " manufacturer: " << temp -> manufacturer << " description: " << temp -> description << " batteryType: " << temp -> batteryType << endl;

      temp = temp -> next;
    }
}

bool DronesManager::insert(DroneRecord value, unsigned int index) {
	 DroneRecord* node = new DroneRecord(value);
   DroneRecord* temp = first;

  if (index >= size) {
    return false;
  }

  if (first == NULL) {
    first = node;
    last = node;
  } else if (index == 0) {
    insert_front(value);
  } else if (index == size - 1) {
    insert_back(value);
  } else {
    for (int i = 0; i < index - 1; ++i) {
      temp = temp -> next;
    }
    node -> next = temp -> next;
    temp -> next -> prev = node;
    temp -> next = node;
    node -> prev = temp;

    size++;
  }
  return true;
}

bool DronesManager::insert_front(DroneRecord value) {
  DroneRecord* node = new DroneRecord(value);

 if (first == NULL) {
    first = node;
    last = node;
  } else {
    node -> next = first;
    first -> prev = node;
    first = node;
  }


  size++;
	return true;
}

bool DronesManager::insert_back(DroneRecord value) {
  DroneRecord* node = new DroneRecord(value);

if (first == NULL) {
    first = node;
    last = node;
  } else {
    node -> next = NULL;
    last -> next = node;
    node -> prev = last;
    last = node;
  }

  size++;
	return true;
}


bool DronesManager::remove(unsigned int index) {
	DroneRecord* temp = first;

  if (first == NULL || index >= size) {
    return false;
  }

  if (index == 0) {
    remove_front();
  } else if (index == size - 1) {
    remove_back();
  } else {

    for (int i = 0; i < index; i++) {
      temp = temp -> next;
    }

    temp -> prev -> next = temp -> next;
    temp -> next -> prev = temp -> prev;
    size--;
  }

  delete temp;
  temp = NULL;

  return true;
}

bool DronesManager::remove_front() {
	DroneRecord* temp = first;
  
  if (first == NULL) {
    return false;
  } 

  if (temp -> next != NULL) {
    first -> next -> prev = NULL;
    delete first;
    first = first -> next;
  } else {
    first = NULL;
    last = NULL;
  }

  size--;
  return true;
}

bool DronesManager::remove_back() {
	DroneRecord* temp = last;

  if (first == NULL) {
    return false;
  } 

  if (temp -> prev != NULL) {
    last -> prev -> next = last -> next;
    delete last;
    last = temp -> prev;
  } else {
    first = NULL;
    last = NULL;
  }

  size--;
  return true;
}

bool DronesManager::replace(unsigned int index, DroneRecord value) {
  DroneRecord* node = new DroneRecord(value);
  DroneRecord* temp = first;

 if (index >= size || first == NULL) {
    return false;
  }

if (index == 0) {
  node -> prev = NULL;
  first -> next -> prev = node;
  node -> next = first -> next;
  
  delete first;
  first = node;
} else if (index == size - 1) {
  node -> next = NULL;
  last -> prev -> next = node;
  node -> prev = last -> prev;

  delete last;
  last = node;
} else {

  for (int i = 0; i < index; i++) {
      temp = temp -> next;
  }
    
  temp -> prev -> next = node;
  node -> prev = temp -> prev;
  node -> next = temp -> next;
  temp -> next -> prev = node;

  delete temp;
  temp = NULL;
}

  return true;
}


bool DronesManager::reverse_list() {
  
  if (first == NULL || first -> next == NULL) {
    return true;
  }

  DroneRecord* mover = first;
  DroneRecord* current = first;
  DroneRecord* pervious = first -> prev;

  while (current != NULL) {
    mover = mover -> next;
    current -> next = pervious;
    current -> prev = mover;
    pervious = current;
    current = mover;
  }
  last = first;
  first = pervious;

  return true;
}

bool DronesManagerSorted::is_sorted_asc() const {
	DroneRecord* current = first;

  while (current -> next != NULL) {
    if (current -> droneID > current -> next -> droneID) {
      return false;
    }
    current = current -> next;

  }

  return true;
}

bool DronesManagerSorted::is_sorted_desc() const {
	DroneRecord* current = first;

  while (current -> next != NULL) {
    if (current -> droneID < current -> next -> droneID) {
      return false;
    }
    current = current -> next;
  }
  
  return true;
}

bool DronesManagerSorted::insert_sorted_asc(DroneRecord val) {
  DroneRecord* temp = first;
  unsigned int index = 0;

  if (!is_sorted_asc() || first == NULL) {
    return false;
  } 

  if (first -> next == NULL && first != NULL) {
    if (temp -> droneID < val.droneID) {
      insert_back(val);
    } else {
      insert_front(val);
    }
  }

  while(temp -> next != NULL && (temp -> droneID < val.droneID)) {
    temp = temp -> next;
    index++;
  }     

  insert(val, index);
 
  return true;
}

bool DronesManagerSorted::insert_sorted_desc(DroneRecord val) {
	DroneRecord* temp = first;
  unsigned int index = 0;

  if (!is_sorted_desc() || first == NULL) {
    return false;
  } 

  if (first -> next == NULL && first != NULL) {
    if (temp -> droneID > val.droneID) {
      insert_back(val);
    } else {
      insert_front(val);
    }
  }

  while(temp -> next != NULL && (temp -> droneID > val.droneID)) {
    temp = temp -> next;
    index++;
  }     

  insert(val, index);

  return true;
}

void DronesManagerSorted::sort_asc() {
    if (first == NULL) {
        return;
    }
    bool swapped = false;
    do {
        swapped = false;
        DroneRecord* curr = first;
        while (curr->next != NULL) {
            if (curr->droneID > curr->next->droneID) {
                swap(curr, curr->next);
                swapped = true;
            }
            else {
                curr = curr->next;
            }
        }
    } while (swapped);
}
    
void DronesManagerSorted::sort_desc() {
     if (first == NULL) {
        return;
    }
    bool swapped = false;
    do {
        swapped = false;
        DroneRecord* curr = first;
        while (curr->next != NULL) {
            if (curr->droneID < curr->next->droneID) {
                swap(curr, curr->next);
                swapped = true;
            }
            else {
                curr = curr->next;
            }
        }

    } while (swapped);

}


void DronesManagerSorted::swap(DronesManager::DroneRecord *head, DronesManager::DroneRecord *tail) {
if (head == first && tail == last) {
        first = tail;
        last = head;
        tail->next = head;
        tail->prev = NULL;
        head->prev = tail ;
        head->next = NULL;
    }
    else if (head == first) {
        DroneRecord* temp = tail->next;

        tail->next->prev = head;
        first = tail;
        tail->prev = NULL;
        tail->next = head;
        head->prev = tail;
        head->next = temp;

    }
    else if (tail == last) {
        DroneRecord* temp = head->prev;

        head->prev->next = tail;
        last = head;
        head->prev = tail;
        head->next = NULL;
        tail->prev = temp;
        tail->next = head;
    }
    else {
        DroneRecord* temp = tail->next;

        head->prev->next = tail;
        tail->next->prev = head;
        tail->next = head;
        tail->prev = head->prev;
        head->next = temp;
        head->prev = tail;
    }
}