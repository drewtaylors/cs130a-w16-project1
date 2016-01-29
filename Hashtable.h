#include <string>
#include "Student.h"

class Hashtable {

 public:
  void insert(int key, Student student);
  void lookup(int key);
  void remove(int key);
  void print();

  inthash1(int key);
  inthash2(int key);

  void setMode(int number);

 private:
  struct Node {
    int key;
    Student student;
  };
  int TABLE_SIZE = 5;
  Node* table [TABLE_SIZE];
  bool isPrime(int number);
  string method = "linearprobing";
};
