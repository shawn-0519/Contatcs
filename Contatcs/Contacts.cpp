#include<iostream>
#include<string>
#include<vector>
#include<limits>
using namespace std;

struct Contact {
	string name;
	string phone;
	string addr;
    string gender;
    int age;
};

vector<Contact> contacts;

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

bool validateInput() {
    if (cin.fail()) {
        cin.clear(); // 清除错误标志
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略输入缓冲区中的内容
        cout << "Invalid input. Please enter a number." << endl;
        return false; // 输入无效
    }
    return true; // 输入有效
}

void addContact() {
	Contact newContact;
	cout << "Enter name: ";
	cin >> newContact.name;
	cout << "Enter phone: ";
	cin >> newContact.phone;
    cout << "Enter addr: ";
	cin >> newContact.addr;
    cout << "Enter age: ";
    while (true)
    {
        cin >> newContact.age;
        if (!validateInput()) {
            continue; // 继续下一轮循环
        }break;
    }
	cout << "Enter gender: " << endl;
    cout << "1:---male " << endl;
    cout << "2:---female " <<endl;
    int gender = 0;
    while (true)
    {
        cin >> gender;
        if (!validateInput()) {
            continue; // 继续下一轮循环
        }
        if (gender == 1)
        {
            newContact.gender = "male";
            break;
        }
        else if(gender == 2)
        {
            newContact.gender = "female";
            break;
        }
        cout << "Invalid input. Please enter 1 or 2" << endl;
    }
	contacts.push_back(newContact);
	cout << "Contact added successfully!" << endl;
}

void showContacts() {
	cout << "Contacts List:" << endl;
	for (const auto& contact : contacts) {
		cout << "Name: " << contact.name << ", Age: " << contact.age << endl
            << "gender: " << contact.gender << endl 
            << "Phone: " << contact.phone  << endl
			<< "Address: " << contact.addr << endl;
	}
}


int main()
{
	int select = 0;

    while (true)
    {
        showMenu();
        cin >> select;

        if (!validateInput()) //输入是否是数字
        {
            continue;
        }

        switch (select) {
        case 1:
            addContact();
            break;
        case 2:
            showContacts();
            break;
        case 3:
            // 删除联系人功能待实现
            cout << "Delete Contact functionality not implemented." << endl;
            break;
        case 4:
            // 查找联系人功能待实现
            cout << "Find Contact functionality not implemented." << endl;
            break;
        case 5:
            // 编辑联系人功能待实现
            cout << "Edit Contact functionality not implemented." << endl;
            break;
        case 6:
            // 清空联系人功能待实现
            cout << "Clear Contacts functionality not implemented." << endl;
            break;
        case 0:
            cout << "Exiting Contacts System." << endl;
            return 0;  // 退出程序
        default:
            cout << "Invalid selection, please try again." << endl;
            break;
        }
    }
	return 0;
}