
#include <iostream>
#include <iomanip>

class Account
{
public:
  Account() {}
  unsigned long * A1;
  virtual ~Account() {}
};

class Employee : public Account
{
public:
  Employee() {}
  unsigned long E1;
};

class Student : public Account
{
public:
  Student() {}
  unsigned long S1;
};

class Work_Study : public Employee, public Student
{
public:
  Work_Study() {}
  unsigned long W1;
};
