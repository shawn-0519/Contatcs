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

vector<Contact> contacts; //vector<Contact> contacts; 的意思是声明一个名为 contacts 的动态数组（向量）,用于存储多个 Contact 结构体的实例。

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

bool validateInput() //输入验证函数
{
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
	contacts.push_back(newContact);//将 newContact 对象添加到 contacts 向量的末尾
	cout << "Contact added successfully!" << endl;
}

void showContacts() {
    if (contacts.empty()) {
        cout << "No contacts available." << endl;
    }
    else 
    {
        cout << "Contacts List:" << endl << endl;
        for (const auto& contact : contacts)//一种范围基于的for循环，用于遍历 contacts 向量中的每个元素。
        {
            cout << "Name: " << contact.name << ", Age: " << contact.age << endl
                << "gender: " << contact.gender << endl
                << "Phone: " << contact.phone << endl
                << "Address: " << contact.addr << endl << endl;
        }

    }

}

void deleteContact() {
    if (contacts.empty()) {
        cout << "No contacts available to delete." << endl;
        return;
    }

    string nameToDelete;
    cout << "Enter the name of the contact you want to delete: ";
    cin >> nameToDelete;

    auto it = contacts.begin();  // 使用迭代器遍历联系人列表。contacts.begin()返回的是一个指向 Contact 元素的迭代器。
    bool found = false;

    while (it != contacts.end()) 
    {
        if (it->name == nameToDelete) //it 是一个指向 Contact 对象的迭代器。通过 -> 访问迭代器指向的 Contact 对象的 name 字段
        {
            found = true;
            it = contacts.erase(it);  // 删除联系人并更新迭代器。erase 函数从 contacts 向量中删除由迭代器 it 指向的联系人，并返回一个指向下一个元素的迭代器。这样可以确保删除后继续正确遍历剩余的联系人。
            cout << "Contact deleted successfully." << endl;
            break;
        }
        else {
            ++it;  // 继续查找下一个联系人
        }
    }

    if (!found) {
        cout << "Contact not found." << endl;
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
            deleteContact();
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