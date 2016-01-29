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
  double getGPA();
  Student(string name, double gpa);
  Student();

};

#endif
