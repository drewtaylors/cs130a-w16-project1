#include <string>
#include "Student.cpp"

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
}
