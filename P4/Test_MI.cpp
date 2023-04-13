#include<iostream>
#include"hw4part2_MultipleInheritance.h"
using namespace std;
int main()
{
	Work_Study Obj_WS;  //initializing
	Work_Study* Obj_WS_ptr = &Obj_WS;

	cout << &Obj_WS_ptr->W1 << endl;//printing different objects
	cout << &Obj_WS_ptr->E1 << endl;
	cout << &Obj_WS_ptr->S1 << endl;
	cout << &Obj_WS_ptr->Employee::A1 << endl;
	cout << &Obj_WS_ptr->Student::A1 << endl;
	cout << Obj_WS_ptr << endl;
	cout << (Employee*)Obj_WS_ptr << endl;
	cout << (Student*)Obj_WS_ptr << endl;
	cout << (Account*)((Employee*)Obj_WS_ptr) << endl;
	cout << (Account*)((Student*)Obj_WS_ptr)<< endl;

	return 0;
}
