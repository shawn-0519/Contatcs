#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

struct Contact {
    string name;
    string phone;
    string addr;
    string gender;
    int age;
};

vector<Contact> contacts; // ���ڴ洢��ϵ��

int language = 0; // 0 ��ʾ���ģ�1 ��ʾӢ��

// �˵�����ʾ��Ϣ�Ķ�����֧��
const string menu[2][8] = {
    { // ����
        "1�������ϵ��",
        "2����ʾ��ϵ��",
        "3��ɾ����ϵ��",
        "4��������ϵ��",
        "5���޸���ϵ��",
        "6�������ϵ��",
        "7�������л�/change language",
        "0���˳�"
    },
    { // Ӣ��
        "1. Add Contact",
        "2. Show Contacts",
        "3. Delete Contact",
        "4. Find Contact",
        "5. Edit Contact",
        "6. Clear Contacts",
        "7��language change/�����л�",
        "0. Exit"
    }
};

const string prompts[2][6] = {
    { // ������ʾ
        "����������: ",
        "������绰: ",
        "�������ַ: ",
        "����������: ",
        "�������Ա� (1: ��, 2: Ů): ",
        "��ϵ����ӳɹ���"
    },
    { // Ӣ����ʾ
        "Enter name: ",
        "Enter phone: ",
        "Enter address: ",
        "Enter age: ",
        "Enter gender (1: male, 2: female): ",
        "Contact added successfully!"
    }
};

// ��֤�����Ƿ�Ϊ����
bool validateInput() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << (language == 0 ? "������Ч�����������֡�" : "Invalid input. Please enter a number.") << endl;
        return false;
    }
    return true;
}

// ��ʾ�˵�
void showMenu() {
    cout << "******************************" << endl;
    for (int i = 0; i < 8; ++i) {
        cout << menu[language][i] << endl;
    }
    cout << "******************************" << endl;
}


// �����ϵ��
void addContact() {
    Contact newContact;
    cout << prompts[language][0];  // ����������
    cin >> newContact.name;
    cin.ignore(); // ������һ�������Ļ��з�

    // ��֤�绰��������
    while (true) {
        cout << prompts[language][1];  // ������绰
        getline(cin, newContact.phone); // ʹ��getline��ȡ�绰

        // ���绰�����Ƿ�Ϊ������
        bool validPhone = true;
        for (char c : newContact.phone) {
            if (!isdigit(c)) {
                validPhone = false;
                break;
            }
        }

        if (validPhone) {
            break;  // ����Ϸ����˳�ѭ��
        }
        else {
            cout << (language == 0 ? "��Ч�ĵ绰���룬���������֡�" : "Invalid phone number. Please enter only numbers.") << endl;
        }
    }

    cout << prompts[language][2];  // �������ַ
    getline(cin, newContact.addr); // ʹ��getline��ȡ��ַ

    cout << prompts[language][3];  // ����������
    while (true) {
        cin >> newContact.age;
        if (!validateInput()) {
            continue;
        }
        break;
    }

    cout << prompts[language][4];  // �������Ա�
    int gender = 0;
    while (true) {
        cin >> gender;
        if (!validateInput()) {
            continue;
        }
        if (gender == 1) {
            newContact.gender = language == 0 ? "��" : "male";
            break;
        }
        else if (gender == 2) {
            newContact.gender = language == 0 ? "Ů" : "female";
            break;
        }
        cout << (language == 0 ? "��Ч���룬������1��2��" : "Invalid input. Please enter 1 or 2.") << endl;
    }

    contacts.push_back(newContact);
    cout << prompts[language][5] << endl;  // ��ϵ����ӳɹ�
}


// ��ʾ��ϵ��
void showContacts() {
    if (contacts.empty()) {
        cout << (language == 0 ? "û�п���ʾ����ϵ�ˡ�" : "No contacts available.") << endl;
        return;
    }
    cout << (language == 0 ? "��ϵ���б�" : "Contacts List:") << endl;
    for (const auto& contact : contacts) {
        cout << (language == 0 ? "������" : "name: ") << contact.name
            << (language == 0 ? " ���䣺" : " age: ") << contact.age << endl
            << (language == 0 ? "�Ա�" : "gender: ") << contact.gender << endl
            << (language == 0 ? "�绰��" : "phone: ") << contact.phone << endl
            << (language == 0 ? "��ַ��" : "addr: ") << contact.addr << endl << endl;
    }
}

// ɾ����ϵ��
void deleteContact() {
    if (contacts.empty()) {
        cout << (language == 0 ? "û�п�ɾ������ϵ�ˡ�" : "No contacts available to delete.") << endl;
        return;
    }
    string nameToDelete;
    cout << (language == 0 ? "������Ҫɾ������ϵ������: " : "Enter the name of the contact you want to delete: ");
    cin >> nameToDelete;
    auto it = contacts.begin();
    bool found = false;
    while (it != contacts.end()) {
        if (it->name == nameToDelete) {
            found = true;
            it = contacts.erase(it);
            cout << (language == 0 ? "��ϵ��ɾ���ɹ���" : "Contact deleted successfully.") << endl;
            break;
        }
        else {
            ++it;
        }
    }
    if (!found) {
        cout << (language == 0 ? "δ�ҵ���ϵ�ˡ�" : "Contact not found.") << endl;
    }
}

// ������ϵ��
void findContact() {
    if (contacts.empty()) {
        cout << (language == 0 ? "û����ϵ�˿��Բ��ҡ�" : "No contacts available to find.") << endl;
        return;
    }
    string nameToFind;
    cout << (language == 0 ? "������Ҫ���ҵ���ϵ������: " : "Enter the name of the contact you want to find: ");
    cin >> nameToFind;
    bool found = false;
    for (const auto& contact : contacts) {
        if (contact.name == nameToFind) {
            found = true;
            cout << (language == 0 ? "������" : "name: ") << contact.name 
                << (language == 0 ? " ���䣺" : "age: ") << contact.age << endl
                << (language == 0 ? "�Ա�" : "gender: ") << contact.gender << endl
                << (language == 0 ? "�绰��" : "phone: ") << contact.phone << endl
                << (language == 0 ? "��ַ��" : "address: ") << contact.addr << endl;
            break;
        }
    }
    if (!found) {
        cout << (language == 0 ? "δ�ҵ���ϵ�ˡ�" : "Contact not found.") << endl;
    }
}

// �޸���ϵ��
void editContact() {
    if (contacts.empty()) {
        cout << (language == 0 ? "û�п��޸ĵ���ϵ�ˡ�" : "No contacts available to edit.") << endl;
        return;
    }

    string nameToEdit;
    cout << (language == 0 ? "������Ҫ�޸ĵ���ϵ������: " : "Enter the name of the contact you want to edit: ");
    cin >> nameToEdit;

    bool found = false;

    for (auto& contact : contacts) {
        if (contact.name == nameToEdit) {
            found = true;
            cout << (language == 0 ? "�����޸���ϵ��: " : "Editing contact: ") << contact.name << endl;

            // �޸�����
            cout << (language == 0 ? "����������������Enter�����ֲ��䣩: " : "Enter new name (or press Enter to keep current): ");
            cin.ignore();
            string newName;
            getline(cin, newName);
            if (!newName.empty()) contact.name = newName;

            // �޸ĵ绰��ѭ����֤�����Ƿ�Ϊ����
            while (true) {
                cout << (language == 0 ? "�������µ绰����Enter�����ֲ��䣩: " : "Enter new phone (or press Enter to keep current): ");
                string newPhone;
                getline(cin, newPhone);

                if (newPhone.empty()) {
                    break;  // �� Enter�����ֵ�ǰ�绰
                }

                // ���绰�����Ƿ�Ϊ������
                bool validPhone = true;
                for (char c : newPhone) {
                    if (!isdigit(c)) {
                        validPhone = false;
                        break;
                    }
                }

                if (validPhone) {
                    contact.phone = newPhone;
                    break;  // ����Ϸ����˳�ѭ��
                }
                else {
                    cout << (language == 0 ? "��Ч�ĵ绰���룬���������֡�" : "Invalid phone number. Please enter only numbers.") << endl;
                }
            }

            // �޸ĵ�ַ
            cout << (language == 0 ? "�������µ�ַ����Enter�����ֲ��䣩: " : "Enter new address (or press Enter to keep current): ");
            string newAddr;
            getline(cin, newAddr);
            if (!newAddr.empty()) contact.addr = newAddr;

            // �޸��Ա�ѭ��ֱ��������ȷ
            while (true) {
                cout << (language == 0 ? "���������Ա� (1: ��, 2: Ů) ��Enter�����ֲ���: "
                    : "Enter new gender (1 for male, 2 for female, or press Enter to keep current): ");
                string genderInput;
                getline(cin, genderInput);
                if (genderInput.empty()) {
                    break;  // �� Enter�����ֵ�ǰ�Ա�
                }
                if (genderInput == "1") {
                    contact.gender = language == 0 ? "��" : "male";
                    break;
                }
                else if (genderInput == "2") {
                    contact.gender = language == 0 ? "Ů" : "female";
                    break;
                }
                else {
                    cout << (language == 0 ? "��Ч���룬������1��2��" : "Invalid input. Please enter 1 or 2.") << endl;
                }
            }

            // �޸�����
            cout << (language == 0 ? "�����������䣨��Enter�����ֲ��䣩: " : "Enter new age (or press Enter to keep current): ");
            string ageInput;
            getline(cin, ageInput);
            if (!ageInput.empty()) {
                contact.age = stoi(ageInput);
            }

            cout << (language == 0 ? "��ϵ���޸ĳɹ���" : "Contact edited successfully!") << endl;
            break;
        }
    }

    if (!found) {
        cout << (language == 0 ? "δ�ҵ���ϵ�ˡ�" : "Contact not found.") << endl;
    }
}

// �����ϵ��
void clearContacts() {
    contacts.clear();
    cout << (language == 0 ? "������ϵ������ա�" : "All contacts cleared.") << endl;
}

// ѡ������
void chooseLanguage() {
    cout << "��ѡ������ / Choose your language: " << endl;
    cout << "1: ����" << endl;
    cout << "2: English" << endl;
    int choice;
    cin >> choice;
    language = (choice == 2) ? 1 : 0;  // ѡ��Ӣ�������� language Ϊ 1��Ĭ������Ϊ 0
}

// ���������
int main() {
    chooseLanguage();  // �û�ѡ������

    int select = 0;
    while (true) {
        showMenu();  // ��ʾ�˵�
        cin >> select;
        if (!validateInput()) {
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
            findContact();
            break;
        case 5:
            editContact();
            break;
        case 6:
            clearContacts();
            break;
        case 7:
            chooseLanguage();
            break;
        case 0:
            cout << (language == 0 ? "�˳�ͨѶ¼ϵͳ��" : "Exiting Contacts System.") << endl;
            return 0;
        default:
            cout << (language == 0 ? "��Чѡ�������ԡ�" : "Invalid selection, please try again.") << endl;
            break;
        }
    }
    return 0;
}
