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

vector<Contact> contacts; //vector<Contact> contacts; ����˼������һ����Ϊ contacts �Ķ�̬���飨������,���ڴ洢��� Contact �ṹ���ʵ����

void showMenu() 
{
	cout << "******************************" << endl;
	cout << "***** 1��Add	Contact  *****" << endl;
	cout << "***** 2��Show	Contacts *****" << endl;
	cout << "***** 3��Delete	Contact  *****" << endl;
	cout << "***** 4��Find	Contact  *****" << endl;
	cout << "***** 5��Edit	Contact  *****" << endl;
	cout << "***** 6��Clear	Contacts *****" << endl;
	cout << "***** 0��Exti	Contacts *****" << endl;
	cout << "******************************" << endl;
}

bool validateInput() //������֤����
{
    if (cin.fail()) {
        cin.clear(); // ��������־
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // �������뻺�����е�����
        cout << "Invalid input. Please enter a number." << endl;
        return false; // ������Ч
    }
    return true; // ������Ч
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
            continue; // ������һ��ѭ��
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
            continue; // ������һ��ѭ��
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
	contacts.push_back(newContact);//�� newContact ������ӵ� contacts ������ĩβ
	cout << "Contact added successfully!" << endl;
}

void showContacts() {
    if (contacts.empty()) {
        cout << "No contacts available." << endl;
    }
    else 
    {
        cout << "Contacts List:" << endl << endl;
        for (const auto& contact : contacts)//һ�ַ�Χ���ڵ�forѭ�������ڱ��� contacts �����е�ÿ��Ԫ�ء�
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

    auto it = contacts.begin();  // ʹ�õ�����������ϵ���б�contacts.begin()���ص���һ��ָ�� Contact Ԫ�صĵ�������
    bool found = false;

    while (it != contacts.end()) 
    {
        if (it->name == nameToDelete) //it ��һ��ָ�� Contact ����ĵ�������ͨ�� -> ���ʵ�����ָ��� Contact ����� name �ֶ�
        {
            found = true;
            it = contacts.erase(it);  // ɾ����ϵ�˲����µ�������erase ������ contacts ������ɾ���ɵ����� it ָ�����ϵ�ˣ�������һ��ָ����һ��Ԫ�صĵ���������������ȷ��ɾ���������ȷ����ʣ�����ϵ�ˡ�
            cout << "Contact deleted successfully." << endl;
            break;
        }
        else {
            ++it;  // ����������һ����ϵ��
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

        if (!validateInput()) //�����Ƿ�������
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
            // ������ϵ�˹��ܴ�ʵ��
            cout << "Find Contact functionality not implemented." << endl;
            break;
        case 5:
            // �༭��ϵ�˹��ܴ�ʵ��
            cout << "Edit Contact functionality not implemented." << endl;
            break;
        case 6:
            // �����ϵ�˹��ܴ�ʵ��
            cout << "Clear Contacts functionality not implemented." << endl;
            break;
        case 0:
            cout << "Exiting Contacts System." << endl;
            return 0;  // �˳�����
        default:
            cout << "Invalid selection, please try again." << endl;
            break;
        }
    }
	return 0;
}