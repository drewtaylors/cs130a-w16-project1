#include <string>
#include "Hashtable.cpp"
#include "Student.h"

class Hashtable {

 public:
  void insert(int key, Student student);
  int lookup(int key);
  void remove(int key);
  void print();

  inthash1(int key);
  inthash2(int key);

  void setMode(int number) {
    if (number == 1) {
      this.method = "linearprobing";
    } 
    else if (number == 2) {
      this.method = "doublehasing";
    } 
  }

 private:
  struct Node {
    int key;
    Student student;
  }
  int TABLE_SIZE = 5;
  Node* table [TABLE_SIZE];
  bool isPrime(int number);
}
