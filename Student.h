#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using namespace std;

class Student {

 private:
  string name;
  double gpa;

 public:
  void setName(string name);
  void setGPA(double gpa);
  string getName();
  int getGPA();
  Student(string name, int gpa);
  Student();

};

#endif
