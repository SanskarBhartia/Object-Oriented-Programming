#include<iostream>
#include"hw4part2_VirtualInheitance.h"
using namespace std;
int main()
{
	Work_Study Obj_WS;
	Work_Study* Obj_WS_ptr = &Obj_WS;

	//cout
	//cout << "Object1 " << &Obj_WS_ptr<< endl;
	//out << "Obj_WS_ptr->E1: " << &Obj_WS_ptr->E1 << endl;

	//cout << "Obj_WS_ptr->S1: " << &Obj_WS_ptr->S1 << endl;

	//cout << "Obj_WS_ptr->A1: " << &Obj_WS_ptr->A1<< endl;



// creating addresses for all classes

	cout << "Obj_WS_ptr->S1: " << &Obj_WS_ptr->S1 << endl; //creates address for STUDENT class
	cout << "Obj_WS_ptr->E1: " << &Obj_WS_ptr->E1 << endl;//creates address for EMPLOYEE class

	cout << "Obj_WS_ptr->W1: " << &Obj_WS_ptr->W1 << endl;//creates address for WORK_STUDY class
	cout << "Obj_WS_ptr->A1: " << &Obj_WS_ptr->A1<< endl;//creates address for ACCOUNT class


	cout << "Obj_WS_ptr :" << Obj_WS_ptr << endl;
	cout << "(Employee*)Obj_WS_ptr :" << (Employee*)Obj_WS_ptr << endl;
	cout << "(Student*)Obj_WS_ptr :" << (Student*)Obj_WS_ptr << endl;
	cout << "(Account*)Obj_WS_ptr :" << (Account*)Obj_WS_ptr << endl;


	return 0;
}
