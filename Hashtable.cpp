#include <iostream>
#include <iomanip>
#include "Hashtable.h"

using namespace std;

Hashtable::Hashtable() {
  method = "linearprobing";
  size = 0;
  TABLE_SIZE = 5;
  table = new Node*[TABLE_SIZE];
  for (int i = 0; i < TABLE_SIZE; i++) {
    table[i] = NULL;
  }
}


void Hashtable::insert(int key, Student student) {
  int index = hash1(key);
  if (method == "linearprobing") {
    while (table[index] != NULL && table[index]->key != key && table[index]->key != -10) {
      index++;
      if (index == TABLE_SIZE) {
	index = 0;
      }
    }
  }
  if (method == "doublehashing") {
    int i = 0;
    while (table[index] != NULL && table[index]->key != key && table[index]->key != -10) {
      i++;
      index = (hash1(key) + i*hash2(key)) % TABLE_SIZE;
    }
  }
  if (table[index] != NULL && table[index]->key != -10) {
    cout << "item already present" << endl;
  }
  else {
    table[index] = new Node;
    table[index]->key = key;
    table[index]->student.setName(student.getName());
    table[index]->student.setGPA(student.getGPA());
    size++;
    if (size > 0.7*TABLE_SIZE) {
      rehash();
    }
    cout << "item successfully inserted" << endl;
  }
}

void Hashtable::lookup(int key) {
  int index = hash1(key);
  if (method == "linearprobing") {
    while (table[index] != NULL && table[index]->key != key) {
      index++;
      if (index == TABLE_SIZE) {
        index = 0;
      }
    }
  }
  if (method == "doublehashing") {
    int i = 0;
    while (table[index] != NULL && table[index]->key != key) {
      i++;
      index = (hash1(key) + i*hash2(key)) % TABLE_SIZE;
    }
  }
  if (table[index] == NULL) {
    cout << "item not found" << endl;
  }
  else {
    cout << "item found; " 
	 << table[index]->student.getName() 
	 << " "
	 << index << endl;
  }
}

void Hashtable::remove(int key) {
  int index = hash1(key);
  if (method == "linearprobing") {
    while (table[index] != NULL && table[index]->key != key) {
      index++;
      if (index == TABLE_SIZE) {
        index = 0;
      }
    }
  }
  if (method == "doublehashing") {
    int i = 0;
    while (table[index] != NULL && table[index]->key != key) {
      i++;
      index = (hash1(key) + i*hash2(key)) % TABLE_SIZE;
    }
  }
  if (table[index] == NULL) {
    cout << "item not present in the table" << endl;
  }
  else {
    table[index]->key = -10;
    size--;
    cout << "item successfully deleted" << endl;
  }
}

void Hashtable::print() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    if (table[i] != NULL && table[i]->key != -10) {
      cout << "(" << table[i]->key 
	   << "," << table[i]->student.getName()
	   << "," << fixed << setprecision(1) << table[i]->student.getGPA()
	   << ")";
    } 
  }
  cout << endl;
}

void Hashtable::rehash() {
  int OG_TABLE_SIZE = TABLE_SIZE;
  TABLE_SIZE = TABLE_SIZE * 2 + 1;
  while (isPrime(TABLE_SIZE) != true) {
    TABLE_SIZE = TABLE_SIZE + 2;
  }
  Node **ogTable = table;
  table = new Node*[TABLE_SIZE];
  for (int i = 0; i < TABLE_SIZE; i++) {
    table[i] = NULL;
  }
  size = 0;
  for (int j = 0; j < OG_TABLE_SIZE; j++) {
    if (ogTable[j] != NULL) {
      int index = hash1(ogTable[j]->key);
      if (method == "linearprobing") {
	while (table[index] != NULL && table[index]->key != ogTable[j]->key && table[index]->key != -10) {
	  index++;
	  if (index == TABLE_SIZE) {
	    index = 0;
	  }
	}
      }
      if (method == "doublehashing") {
	int k = 0;
	// issue is this while loop for double hashing
	while (table[index] != NULL && table[index]->key != ogTable[j]->key && table[index]->key != -10) {
	  k++;
	  index = (hash1(ogTable[j]->key) + k*hash2(ogTable[j]->key)) % TABLE_SIZE;
	}
      }
      if (table[index] != NULL && table[index]->key != -10) {
	cout << "item already present" << endl;
      }
      else {
	table[index] = new Node;
	table[index]->key = ogTable[j]->key;
	table[index]->student.setName(ogTable[j]->student.getName());
	table[index]->student.setGPA(ogTable[j]->student.getGPA());
	size++;
      }
    }
  }
  delete [] ogTable;
  cout << "table doubled" << endl;
}

int Hashtable::hash1(int key) {
  return (key % 492113) % TABLE_SIZE;
}

int Hashtable::hash2(int key) {
  int hasher = (key % 392113) % TABLE_SIZE;
  if (hasher == 0) {
    return 1;
  }
  return hasher;
}

void Hashtable::setMode(int number) {
  if (number == 1) {
    method = "linearprobing";
  }
  else if (number == 2) {
    method = "doublehashing";
  }
}

bool Hashtable::isPrime(int number) {
  for (int i = 2; i < number; i++) {
    if (number % i == 0) {
      return false;
    }
  }
  return true;
}

Hashtable::~Hashtable() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    if (table[i] != NULL) {
      delete table[i];
    }
  }
}
