#include <string>
#include "Student.h"

using namespace std;

void Student::setName(string name) {
  this->name = name;
}

void Student::setGPA(double gpa) {
  this->gpa = gpa;
}

string Student::getName() {
  return name;
}

int Student::getGPA() {
  return gpa;
}

Student::Student(string name, int gpa) {
  setName(name);
  setGPA(gpa);
}

Student::Student() {
  setName("null");
  setGPA(0);
}
