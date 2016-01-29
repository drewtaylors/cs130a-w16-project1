#include "Hashtable.h"

using namespace std;

void Hashtable::insert(int key, Student student) {

}

void Hashtable::lookup(int key) {
  int index = hash1(key);
  if (table[index] == key) {
    cout << " " << endl;
  }
  else {  
    if(method == "linearprobing"){
      
    }
    else if(method == "doublehashing"){
    }
  }
}

void Hashtable::remove(int key) {

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
    this->method = "linearprobing";
  }
  else if (number == 2) {
    this->method = "doublehashing";
  }
}
