#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include "Student.h"

class Hashtable {

 public:
  Hashtable();
  void insert(int key, Student student);
  void lookup(int key);
  void remove(int key);
  void print();

  int hash1(int key);
  int hash2(int key);

  void setMode(int number);

 private:
  struct Node {
    int key;
    Student student;
  };
  Node **table;
  int TABLE_SIZE;
  string method;
  bool isPrime(int number);

};

#endif
