//NAME: SHANTHOSH PUSHPARJAH (20710273) && TANJOT PANESAR(20727567)
//DATE: 02/19/2019

#ifndef DRONES_MANAGER_TEST
#define DRONES_MANAGER_TEST
#include <string>


#include "lab2_drones_manager.hpp"

#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

class DronesManagerTest {
public:
	// PURPOSE: New empty list is valid
	bool test1() {
		DronesManager manager;
		ASSERT_TRUE(manager.get_size() == 0)
		ASSERT_TRUE(manager.empty() == true)
		ASSERT_TRUE(manager.first == NULL)
		ASSERT_TRUE(manager.last == NULL)
	    return true;
	}
	
	// PURPOSE: insert_front() and insert_back() on zero-element list
	bool test2() {
		DronesManager manager1, manager2;
		manager1.insert_front(DronesManager::DroneRecord(100));
		manager2.insert_back(DronesManager::DroneRecord(100));
	    
		ASSERT_TRUE(manager1.get_size() == manager2.get_size() && manager1.get_size() == 1)
		ASSERT_TRUE(manager1.first != NULL && manager1.first == manager1.last)
		ASSERT_TRUE(manager2.first != NULL && manager2.first == manager2.last)
		ASSERT_TRUE(manager1.first->prev == NULL && manager1.last->next == NULL)
		ASSERT_TRUE(manager2.first->prev == NULL && manager2.last->next == NULL)
		ASSERT_TRUE(manager1.select(0) == manager2.select(0) && manager1.select(0) == DronesManager::DroneRecord(100))		
	    return true;
	}
	
	// TODO: Implement all of the test cases below
	
	// PURPOSE: select() and search() work properly
  bool test3() {
		DronesManager manager1;
		
		const int num_elems = 5;
		for (int i = 0; i < num_elems; i++) {
			ASSERT_TRUE(manager1.insert_back(DronesManager::DroneRecord(i*100)))
		}

		unsigned int idx = 3;
		ASSERT_TRUE(manager1.search(manager1.select(idx)) == idx)
		ASSERT_TRUE(manager1.select(num_elems + 1) == DronesManager::DroneRecord(400))
		ASSERT_TRUE(manager1.search(1000) == manager1.get_size())
		
		for (int i = 0; i < num_elems; i++) {
			ASSERT_TRUE(manager1.select(i) == DronesManager::DroneRecord(i*100))
		}
		ASSERT_TRUE(manager1.first->prev == NULL && manager1.last->next == NULL)
	  
    //OWN TEST CASES
    ASSERT_TRUE(manager1.get_size() == 5)

    DronesManager manager2;
    DronesManager manager3;

    const int num = 10;
		for (int i = 0; i < num; i++) {
			ASSERT_TRUE(manager2.insert_back(DronesManager::DroneRecord(i)))
		}
    ASSERT_TRUE(manager2.select(2) == DronesManager::DroneRecord(2))
    ASSERT_TRUE(manager2.search(manager2.select(2)) == 2)
    ASSERT_TRUE(manager2.search(manager3.select(2)) == 0)
   	ASSERT_TRUE(manager2.search(1000) == 10)

    return true;
  }
	
  // PURPOSE: remove_front() and remove_back() on one-element list
  bool test4() {
		DronesManager manager1, manager2;
		ASSERT_TRUE(manager1.insert_front(DronesManager::DroneRecord(100)))
		ASSERT_TRUE(manager2.insert_front(DronesManager::DroneRecord(100)))
		ASSERT_TRUE(manager1.remove_front())
		ASSERT_TRUE(manager2.remove_back())
		
		ASSERT_TRUE(manager1.first == NULL && manager1.last == NULL)
		ASSERT_TRUE(manager2.first == NULL && manager2.last == NULL)
		ASSERT_TRUE(manager1.get_size() == manager2.get_size() && manager1.get_size() == 0)
		ASSERT_TRUE(manager1.empty() == true && manager2.empty() == true)

    //OWN TEST CASES
    ASSERT_TRUE(manager1.get_size() == 0)
    ASSERT_TRUE(manager1.insert_front(DronesManager::DroneRecord(100)))
    ASSERT_TRUE(manager1.insert_front(DronesManager::DroneRecord(99)))
    ASSERT_TRUE(manager1.insert(DronesManager::DroneRecord(100), 1))
    ASSERT_TRUE(!manager1.insert(DronesManager::DroneRecord(100), 5))
    ASSERT_TRUE(manager1.get_size() == 3)
    ASSERT_TRUE(manager1.remove_front())
    ASSERT_TRUE(manager1.remove_front())
    ASSERT_TRUE(manager1.get_size() == 1)

	  return true;
  }
	
	// PURPOSE: replace() and reverse_list() work properly
  bool test5() {
    DronesManager manager;
    DronesManager manager2;

		const int num_elems = 8;
		for (int i = 0; i < num_elems; i++) {
			ASSERT_TRUE(manager.insert_back(DronesManager::DroneRecord(i)))
		}
	
		ASSERT_TRUE(manager.replace(0, DronesManager::DroneRecord(8)))
		ASSERT_TRUE(manager.replace(3, DronesManager::DroneRecord(9)))
		ASSERT_TRUE(manager.replace(7, DronesManager::DroneRecord(10)))
	
		ASSERT_TRUE(*manager.first == DronesManager::DroneRecord(8))
		ASSERT_TRUE(*manager.last == DronesManager::DroneRecord(10))
		ASSERT_TRUE(*(manager.first->next->next->next) == DronesManager::DroneRecord(9))
	
		int test_values[8] = {10, 6, 5, 4, 9, 2, 1, 8};
		ASSERT_TRUE(manager.reverse_list());
		for (int i = 0; i < num_elems; i++) {
			ASSERT_TRUE(manager.select(i) == DronesManager::DroneRecord(test_values[i]))
		}
	
		ASSERT_TRUE(manager.first->prev == NULL && manager.last->next == NULL)

     //OWN TEST CASES
		for (int i = 0; i < num_elems; i++) {
		  ASSERT_TRUE(manager2.insert_back(DronesManager::DroneRecord(i)))
		}

		ASSERT_TRUE(manager2.insert_back(DronesManager::DroneRecord(10)))
		ASSERT_TRUE(manager2.replace(0, DronesManager::DroneRecord(3)))
		ASSERT_TRUE(manager2.replace(4, DronesManager::DroneRecord(2)))
    ASSERT_TRUE(*manager2.first == DronesManager::DroneRecord(3))
		ASSERT_TRUE(*manager2.last == DronesManager::DroneRecord(10))
    ASSERT_TRUE(*(manager2.first -> next) == DronesManager::DroneRecord(1))
    ASSERT_TRUE(*(manager2.last -> prev -> prev) == DronesManager::DroneRecord(6))
		ASSERT_TRUE(manager2.replace(6, DronesManager::DroneRecord(2)))
    ASSERT_TRUE(*(manager2.last -> prev -> prev) == DronesManager::DroneRecord(2))
    
    ASSERT_TRUE(manager2.replace(3, DronesManager::DroneRecord(3)))
    ASSERT_TRUE(*manager2.first == DronesManager::DroneRecord(3))

	   return true;
    }
	
    
  // PURPOSE: insert_front() keeps moving elements forward
  bool test6() {
    DronesManager manager;
		const int num_elems = 5;
    
		for (int i = 0; i < num_elems; i++) {
			ASSERT_TRUE(manager.insert_front(DronesManager::DroneRecord(i)))
			ASSERT_TRUE(manager.get_size() == (i + 1))
			ASSERT_TRUE(*manager.first == DronesManager::DroneRecord(i))
	        
			DronesManager::DroneRecord* n = manager.first;
			for (int j = 0; j <= i; j++) {
				DronesManager::DroneRecord expected_value = DronesManager::DroneRecord(i - j);
				ASSERT_TRUE(n != NULL && *n == expected_value)
				n = n->next;
			}
		}	
		ASSERT_TRUE(manager.first->prev == NULL && manager.last->next == NULL)

    //OWN TEST CASES
    DronesManager manager1;

    for (int i = 0; i < num_elems; i++) {
			ASSERT_TRUE(manager1.insert_front(DronesManager::DroneRecord(i)))
    }
    ASSERT_TRUE(manager1.get_size() == 5)
    ASSERT_TRUE(manager1.insert_back(DronesManager::DroneRecord(20)))
    ASSERT_TRUE(*manager1.last == DronesManager::DroneRecord(20))
    ASSERT_TRUE(*manager1.first == DronesManager::DroneRecord(4))
    ASSERT_TRUE(*manager1.last -> prev == DronesManager::DroneRecord(0))


	  return true;
    }
	
	// PURPOSE: inserting at different positions in the list
	bool test7() {
    DronesManager manager;
		const int num_elems = 8;
		for (int i = 0; i < num_elems; i++) {
			ASSERT_TRUE(manager.insert_back(DronesManager::DroneRecord(i)))
		}

    ASSERT_TRUE(manager.get_size() == 8);
    ASSERT_TRUE(manager.insert(DronesManager::DroneRecord(45), 0))
    ASSERT_TRUE(manager.insert(DronesManager::DroneRecord(50), 1))
    ASSERT_TRUE(manager.insert(DronesManager::DroneRecord(55), 2))
    ASSERT_TRUE(manager.insert(DronesManager::DroneRecord(99), 3))

    ASSERT_TRUE(manager.get_size() == 12)

    ASSERT_TRUE(*manager.first == DronesManager::DroneRecord(45))
    ASSERT_TRUE(*manager.first -> next == DronesManager::DroneRecord(50))
    ASSERT_TRUE(*manager.first -> next -> next == DronesManager::DroneRecord(55))
    ASSERT_TRUE(*manager.first -> next -> next -> next == DronesManager::DroneRecord(99))
    ASSERT_TRUE(*manager.first -> next -> next -> next -> next == DronesManager::DroneRecord(0))

    ASSERT_TRUE(manager.insert(DronesManager::DroneRecord(77), 3))
    ASSERT_TRUE(*manager.first -> next -> next -> next == DronesManager::DroneRecord(77))
    ASSERT_TRUE(*manager.first -> next -> next -> next -> next == DronesManager::DroneRecord(99))
    ASSERT_TRUE(*manager.first -> next -> next -> next -> next -> next == DronesManager::DroneRecord(0))
    ASSERT_TRUE(*manager.first -> next -> next -> next -> next -> next -> next == DronesManager::DroneRecord(1))

    ASSERT_TRUE(*manager.last  == DronesManager::DroneRecord(7))
    ASSERT_TRUE(manager.get_size() == 13)

    ASSERT_TRUE(manager.insert(DronesManager::DroneRecord(100), 12))
    ASSERT_TRUE(*manager.last  == DronesManager::DroneRecord(100))
    ASSERT_TRUE(*manager.last -> prev  == DronesManager::DroneRecord(7))

	  return true;
	}
	
	// PURPOSE: try to remove too many elements, then add a few elements
	bool test8() {
    DronesManager manager;
		const int num_elems = 8;
		for (int i = 0; i < num_elems; i++) {
			ASSERT_TRUE(manager.insert_back(DronesManager::DroneRecord(i)))
		}

    ASSERT_TRUE(manager.get_size() == 8);

    ASSERT_TRUE(manager.remove_front())
    ASSERT_TRUE(manager.get_size() == 7)

    ASSERT_TRUE(manager.remove_back())
    ASSERT_TRUE(manager.get_size() == 6)

    ASSERT_TRUE(*manager.last  == DronesManager::DroneRecord(6))
    ASSERT_TRUE(*manager.first  == DronesManager::DroneRecord(1))

    ASSERT_TRUE(manager.remove_front())
    ASSERT_TRUE(manager.get_size() == 5)

    ASSERT_TRUE(manager.remove_back())
    ASSERT_TRUE(manager.get_size() == 4)

    ASSERT_TRUE(*manager.last  == DronesManager::DroneRecord(5))
    ASSERT_TRUE(*manager.first  == DronesManager::DroneRecord(2))

    ASSERT_TRUE(manager.remove(1));
    ASSERT_TRUE(*manager.first -> next  == DronesManager::DroneRecord(4))
    ASSERT_TRUE(manager.get_size() == 3)

    ASSERT_TRUE(manager.remove_front())
    ASSERT_TRUE(manager.remove_front())
    ASSERT_TRUE(manager.remove_front())
    ASSERT_TRUE(manager.remove_front() == false)
    ASSERT_TRUE(manager.get_size() == 0)
    ASSERT_TRUE(!manager.remove_front())

    ASSERT_TRUE(manager.insert_front(45))
    ASSERT_TRUE(*manager.first == DronesManager::DroneRecord(45))
    ASSERT_TRUE(*manager.last == DronesManager::DroneRecord(45))
    
	  return true;
	}
	
	// PURPOSE: lots of inserts and deletes, some of them invalid
	bool test9() {
    DronesManager manager;
		const int num_elems = 8;
		for (int i = 0; i < num_elems; i++) {
			ASSERT_TRUE(manager.insert_back(DronesManager::DroneRecord(i)))
		}

    ASSERT_TRUE(!manager.insert(DronesManager::DroneRecord(50), 1000))
    ASSERT_TRUE(manager.insert(DronesManager::DroneRecord(50), 2))
    ASSERT_TRUE(manager.remove(2))
    ASSERT_TRUE(!manager.remove(-2))
    ASSERT_TRUE(manager.get_size() == 8)

    ASSERT_TRUE(manager.replace(0,DronesManager::DroneRecord(42)))
    ASSERT_TRUE(manager.get_size() == 8)
  
    ASSERT_TRUE(*manager.first  == DronesManager::DroneRecord(42))
    ASSERT_TRUE(manager.replace(4,DronesManager::DroneRecord(21)))
    ASSERT_TRUE(manager.remove(4))
    ASSERT_TRUE(manager.remove_front())
    ASSERT_TRUE(manager.remove_front())
    ASSERT_TRUE((manager.insert_back(DronesManager::DroneRecord(-1000000))))
    ASSERT_TRUE(manager.remove_front())
    ASSERT_TRUE(manager.get_size() == 5)
    
    ASSERT_TRUE(manager.remove_front())
    ASSERT_TRUE(manager.remove_front())
    ASSERT_TRUE(manager.remove_front())
    ASSERT_TRUE(manager.remove_front())
    ASSERT_TRUE(manager.remove_front())
    ASSERT_TRUE(manager.get_size() == 0)

    ASSERT_TRUE(!manager.remove_front())
    ASSERT_TRUE(!manager.insert(DronesManager::DroneRecord(50), 2))

		return true;
	}    
	    	
	// PURPOSE: inserts into an unsorted list, then sort the list
	bool test10() {
    
    DronesManagerSorted manager;

    DronesManagerSorted::DroneRecord a(1);
    DronesManagerSorted::DroneRecord b(2);
    DronesManagerSorted::DroneRecord c(3);
    DronesManagerSorted::DroneRecord d(4);
    DronesManagerSorted::DroneRecord e(9);
    DronesManagerSorted::DroneRecord f(23);
  
    ASSERT_TRUE(manager.insert_back(DronesManagerSorted::DroneRecord(a)))
    ASSERT_TRUE(manager.insert_back(DronesManagerSorted::DroneRecord(b)))
    ASSERT_TRUE(manager.insert_back(DronesManagerSorted::DroneRecord(c)))
    ASSERT_TRUE(manager.insert_back(DronesManagerSorted::DroneRecord(d)))

    ASSERT_TRUE(manager.first -> droneID == 1)
    ASSERT_TRUE(manager.first -> next -> droneID == 2)
    ASSERT_TRUE(manager.first -> next -> next -> droneID == 3)
    ASSERT_TRUE(manager.first -> next -> next -> next -> droneID == 4)


    manager.sort_desc();
    ASSERT_TRUE(manager.first -> droneID == 4)
    ASSERT_TRUE(manager.first -> next -> droneID == 3)
    ASSERT_TRUE(manager.first -> next -> next -> droneID == 2)
    ASSERT_TRUE(manager.last -> droneID == 1)
    ASSERT_TRUE(manager.last -> prev -> droneID == 2)

    ASSERT_TRUE(manager.is_sorted_desc())

    manager.sort_asc();
    ASSERT_TRUE(manager.first -> droneID == 1)
    ASSERT_TRUE(manager.first -> next -> droneID == 2)
    ASSERT_TRUE(manager.first -> next -> next -> droneID == 3)
    ASSERT_TRUE(manager.last -> droneID == 4)

    ASSERT_TRUE(manager.remove_front())
    ASSERT_TRUE(manager.get_size() == 3)

    ASSERT_TRUE(manager.insert_back(DronesManagerSorted::DroneRecord(e)))
    ASSERT_TRUE(manager.insert_front(DronesManagerSorted::DroneRecord(f)))

    ASSERT_TRUE(manager.get_size() == 5)

    manager.sort_asc();

    ASSERT_TRUE(!manager.is_sorted_desc())
    ASSERT_TRUE(manager.last -> droneID == 23)

    return true;
	}  
	
	// PURPOSE: insert and remove into sorted manager in ascending order
  bool test11() {
  DronesManagerSorted manager;

  DronesManagerSorted::DroneRecord a(2);
  DronesManagerSorted::DroneRecord b(1);
  DronesManagerSorted::DroneRecord c(3);
  DronesManagerSorted::DroneRecord d(4);
  DronesManagerSorted::DroneRecord e(9);
  DronesManagerSorted::DroneRecord f(23);
  DronesManagerSorted::DroneRecord g(7);

  
  ASSERT_TRUE(manager.insert_back(DronesManagerSorted::DroneRecord(a)))
  ASSERT_TRUE(manager.insert_back(DronesManagerSorted::DroneRecord(b)))
  ASSERT_TRUE(manager.insert_back(DronesManagerSorted::DroneRecord(c)))
  ASSERT_TRUE(manager.insert_back(DronesManagerSorted::DroneRecord(d)))
  ASSERT_TRUE(manager.insert_back(DronesManagerSorted::DroneRecord(e)))
  ASSERT_TRUE(manager.insert_back(DronesManagerSorted::DroneRecord(f)))

   manager.sort_asc();
  ASSERT_TRUE(manager.is_sorted_asc())

  ASSERT_TRUE(manager.insert_sorted_asc(DronesManagerSorted::DroneRecord(g)))

  ASSERT_TRUE(manager.last -> droneID == 23)
  ASSERT_TRUE(manager.last -> prev -> droneID == 9)
  ASSERT_TRUE(manager.last -> prev -> prev -> droneID == 7)

  ASSERT_TRUE(manager.first -> droneID == 1)
  ASSERT_TRUE(manager.get_size() == 7)

  ASSERT_TRUE(manager.remove(5)) 
  ASSERT_TRUE(manager.remove_front())
  ASSERT_TRUE(manager.get_size() == 5)
  
  ASSERT_TRUE(manager.last -> droneID == 23) 
  ASSERT_TRUE(manager.last -> prev -> droneID == 7)
  ASSERT_TRUE(manager.last -> prev -> prev -> droneID == 4)
  ASSERT_TRUE(manager.first -> droneID == 2)
  ASSERT_TRUE(manager.first -> next -> droneID == 3)
  ASSERT_TRUE(manager.first -> next -> next -> droneID == 4)
	ASSERT_TRUE(manager.select(5) == DronesManager::DroneRecord(23))

  return true;
	}
	
	// PURPOSE: insert and remove into sorted manager in descending order
	bool test12() {
  DronesManagerSorted manager;

  DronesManagerSorted::DroneRecord a(2);
  DronesManagerSorted::DroneRecord b(1);
  DronesManagerSorted::DroneRecord c(3);
  DronesManagerSorted::DroneRecord d(4);
  DronesManagerSorted::DroneRecord e(9);
  DronesManagerSorted::DroneRecord f(23);
  DronesManagerSorted::DroneRecord g(7);
  DronesManagerSorted::DroneRecord s(42);


  ASSERT_TRUE(manager.insert_back(DronesManagerSorted::DroneRecord(a)))
  ASSERT_TRUE(manager.insert_back(DronesManagerSorted::DroneRecord(b)))
  ASSERT_TRUE(manager.insert_back(DronesManagerSorted::DroneRecord(c)))
  ASSERT_TRUE(manager.insert_back(DronesManagerSorted::DroneRecord(d)))
  ASSERT_TRUE(manager.insert_back(DronesManagerSorted::DroneRecord(e)))
  ASSERT_TRUE(manager.insert_back(DronesManagerSorted::DroneRecord(f)))

  manager.sort_desc();
  ASSERT_TRUE(manager.is_sorted_desc())

  ASSERT_TRUE(manager.insert_sorted_desc(DronesManagerSorted::DroneRecord(g)))

  ASSERT_TRUE(manager.last -> droneID == 1)
  ASSERT_TRUE(manager.last -> prev -> droneID == 2)
  ASSERT_TRUE(manager.last -> prev -> prev -> droneID == 3)
  ASSERT_TRUE(manager.first -> droneID == 23)
  ASSERT_TRUE(manager.first -> next -> droneID == 9)
  ASSERT_TRUE(manager.first -> next -> next -> droneID == 7)

  ASSERT_TRUE(manager.get_size() == 7)

  ASSERT_TRUE(manager.remove(5)) 
  ASSERT_TRUE(manager.remove_front())
  ASSERT_TRUE(manager.get_size() == 5)
  
  ASSERT_TRUE(manager.last -> droneID == 1) 
  ASSERT_TRUE(manager.last -> prev -> droneID == 3)
  ASSERT_TRUE(manager.last -> prev -> prev -> droneID == 4)
  ASSERT_TRUE(manager.first -> droneID == 9)
  ASSERT_TRUE(manager.first -> next -> droneID == 7)
  ASSERT_TRUE(manager.first -> next -> next -> droneID == 4)
  ASSERT_TRUE(manager.select(0) == DronesManager::DroneRecord(9)) 
  
  manager.sort_asc();
  ASSERT_TRUE(manager.is_sorted_asc())
  ASSERT_TRUE(manager.insert_sorted_asc(DronesManagerSorted::DroneRecord(s)))
  ASSERT_TRUE(manager.get_size() == 6)
  ASSERT_TRUE(manager.last -> droneID == 42)

  //TESTING PRINT
  manager.print();

	return true;
	}  
};

#endif
