#include<iostream>
#include<string>
using namespace std;

void showMenu() 
{
	cout << "******************************" << endl;
	cout << "***** 1、Add	Contact  *****" << endl;
	cout << "***** 2、Show	Contacts *****" << endl;
	cout << "***** 3、Delete	Contact  *****" << endl;
	cout << "***** 4、Find	Contact  *****" << endl;
	cout << "***** 5、Edit	Contact  *****" << endl;
	cout << "***** 6、Clear	Contacts *****" << endl;
	cout << "***** 0、Exti	Contacts *****" << endl;
	cout << "******************************" << endl;
}

int main()
{
	showMenu();

	system("pause"); 

	return 0;
}