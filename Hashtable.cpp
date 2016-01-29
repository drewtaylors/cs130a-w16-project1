#include <iostream>
#include <iomanip>
#include "Hashtable.h"

using namespace std;

Hashtable::Hashtable() {
  method = "linearprobing";
  TABLE_SIZE = 5;
  table = new Node*[TABLE_SIZE];
  for (int i = 0; i < TABLE_SIZE; i++) {
    table[i] = NULL;
  }
}


void Hashtable::insert(int key, Student student) {
  int index = hash1(key);
  if (method == "linearprobing") {
    while (table[index] != NULL && table[index]->key != key) {
      index = hash1(key+1);
    }
  }
  if (method == "doublehashing") {
    int i = 0;
    while (table[index] != NULL && table[index]->key != key) {
      i++;
      index = (hash1(key) + i*hash2(key)) % TABLE_SIZE;
    }
  }
  if (table[index] != NULL) {
    cout << "item already present" << endl;
  }
  else {
    table[index] = new Node;
    table[index]->key = key;
    table[index]->student.setName(student.getName());
    table[index]->student.setGPA(student.getGPA());
    cout << "item successfully inserted" << endl;
  }
}

void Hashtable::lookup(int key) {
  int index = hash1(key);
  if (method == "linearprobing") {
    while (table[index] != NULL && table[index]->key != key) {
      index = hash1(key+1);
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
      index = hash1(key+1);
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
    cout << "item not present in table" << endl;
  }
  else {
    table[index]->key = -10;
    cout << "item successfully deleted" << endl;
  }
}

void Hashtable::print() {

}

int Hashtable::hash1(int key) {
  return (key % 492113) % TABLE_SIZE;
}

int Hashtable::hash2(int key) {
  return (key % 392113) % TABLE_SIZE;
}

void Hashtable::setMode(int number) {
  if (number == 1) {
    method = "linearprobing";
  }
  else if (number == 2) {
    method = "doublehashing";
  }
}
