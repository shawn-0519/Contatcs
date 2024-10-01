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

vector<Contact> contacts; // 用于存储联系人

int language = 0; // 0 表示中文，1 表示英文

// 菜单和提示信息的多语言支持
const string menu[2][8] = {
    { // 中文
        "1、添加联系人",
        "2、显示联系人",
        "3、删除联系人",
        "4、查找联系人",
        "5、修改联系人",
        "6、清空联系人",
        "7、语言切换/change language",
        "0、退出"
    },
    { // 英文
        "1. Add Contact",
        "2. Show Contacts",
        "3. Delete Contact",
        "4. Find Contact",
        "5. Edit Contact",
        "6. Clear Contacts",
        "7、language change/语言切换",
        "0. Exit"
    }
};

const string prompts[2][6] = {
    { // 中文提示
        "请输入姓名: ",
        "请输入电话: ",
        "请输入地址: ",
        "请输入年龄: ",
        "请输入性别 (1: 男, 2: 女): ",
        "联系人添加成功！"
    },
    { // 英文提示
        "Enter name: ",
        "Enter phone: ",
        "Enter address: ",
        "Enter age: ",
        "Enter gender (1: male, 2: female): ",
        "Contact added successfully!"
    }
};

// 验证输入是否为数字
bool validateInput() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << (language == 0 ? "输入无效，请输入数字。" : "Invalid input. Please enter a number.") << endl;
        return false;
    }
    return true;
}

// 显示菜单
void showMenu() {
    cout << "******************************" << endl;
    for (int i = 0; i < 8; ++i) {
        cout << menu[language][i] << endl;
    }
    cout << "******************************" << endl;
}


// 添加联系人
void addContact() {
    Contact newContact;
    cout << prompts[language][0];  // 请输入姓名
    cin >> newContact.name;
    cin.ignore(); // 忽略上一个输入后的换行符

    // 验证电话号码输入
    while (true) {
        cout << prompts[language][1];  // 请输入电话
        getline(cin, newContact.phone); // 使用getline读取电话

        // 检查电话输入是否为纯数字
        bool validPhone = true;
        for (char c : newContact.phone) {
            if (!isdigit(c)) {
                validPhone = false;
                break;
            }
        }

        if (validPhone) {
            break;  // 输入合法，退出循环
        }
        else {
            cout << (language == 0 ? "无效的电话号码，请输入数字。" : "Invalid phone number. Please enter only numbers.") << endl;
        }
    }

    cout << prompts[language][2];  // 请输入地址
    getline(cin, newContact.addr); // 使用getline读取地址

    cout << prompts[language][3];  // 请输入年龄
    while (true) {
        cin >> newContact.age;
        if (!validateInput()) {
            continue;
        }
        break;
    }

    cout << prompts[language][4];  // 请输入性别
    int gender = 0;
    while (true) {
        cin >> gender;
        if (!validateInput()) {
            continue;
        }
        if (gender == 1) {
            newContact.gender = language == 0 ? "男" : "male";
            break;
        }
        else if (gender == 2) {
            newContact.gender = language == 0 ? "女" : "female";
            break;
        }
        cout << (language == 0 ? "无效输入，请输入1或2。" : "Invalid input. Please enter 1 or 2.") << endl;
    }

    contacts.push_back(newContact);
    cout << prompts[language][5] << endl;  // 联系人添加成功
}


// 显示联系人
void showContacts() {
    if (contacts.empty()) {
        cout << (language == 0 ? "没有可显示的联系人。" : "No contacts available.") << endl;
        return;
    }
    cout << (language == 0 ? "联系人列表：" : "Contacts List:") << endl;
    for (const auto& contact : contacts) {
        cout << (language == 0 ? "姓名：" : "name: ") << contact.name
            << (language == 0 ? " 年龄：" : " age: ") << contact.age << endl
            << (language == 0 ? "性别：" : "gender: ") << contact.gender << endl
            << (language == 0 ? "电话：" : "phone: ") << contact.phone << endl
            << (language == 0 ? "地址：" : "addr: ") << contact.addr << endl << endl;
    }
}

// 删除联系人
void deleteContact() {
    if (contacts.empty()) {
        cout << (language == 0 ? "没有可删除的联系人。" : "No contacts available to delete.") << endl;
        return;
    }
    string nameToDelete;
    cout << (language == 0 ? "请输入要删除的联系人姓名: " : "Enter the name of the contact you want to delete: ");
    cin >> nameToDelete;
    auto it = contacts.begin();
    bool found = false;
    while (it != contacts.end()) {
        if (it->name == nameToDelete) {
            found = true;
            it = contacts.erase(it);
            cout << (language == 0 ? "联系人删除成功。" : "Contact deleted successfully.") << endl;
            break;
        }
        else {
            ++it;
        }
    }
    if (!found) {
        cout << (language == 0 ? "未找到联系人。" : "Contact not found.") << endl;
    }
}

// 查找联系人
void findContact() {
    if (contacts.empty()) {
        cout << (language == 0 ? "没有联系人可以查找。" : "No contacts available to find.") << endl;
        return;
    }
    string nameToFind;
    cout << (language == 0 ? "请输入要查找的联系人姓名: " : "Enter the name of the contact you want to find: ");
    cin >> nameToFind;
    bool found = false;
    for (const auto& contact : contacts) {
        if (contact.name == nameToFind) {
            found = true;
            cout << (language == 0 ? "姓名：" : "name: ") << contact.name 
                << (language == 0 ? " 年龄：" : "age: ") << contact.age << endl
                << (language == 0 ? "性别：" : "gender: ") << contact.gender << endl
                << (language == 0 ? "电话：" : "phone: ") << contact.phone << endl
                << (language == 0 ? "地址：" : "address: ") << contact.addr << endl;
            break;
        }
    }
    if (!found) {
        cout << (language == 0 ? "未找到联系人。" : "Contact not found.") << endl;
    }
}

// 修改联系人
void editContact() {
    if (contacts.empty()) {
        cout << (language == 0 ? "没有可修改的联系人。" : "No contacts available to edit.") << endl;
        return;
    }

    string nameToEdit;
    cout << (language == 0 ? "请输入要修改的联系人姓名: " : "Enter the name of the contact you want to edit: ");
    cin >> nameToEdit;

    bool found = false;

    for (auto& contact : contacts) {
        if (contact.name == nameToEdit) {
            found = true;
            cout << (language == 0 ? "正在修改联系人: " : "Editing contact: ") << contact.name << endl;

            // 修改姓名
            cout << (language == 0 ? "请输入新姓名（按Enter键保持不变）: " : "Enter new name (or press Enter to keep current): ");
            cin.ignore();
            string newName;
            getline(cin, newName);
            if (!newName.empty()) contact.name = newName;

            // 修改电话，循环验证输入是否为数字
            while (true) {
                cout << (language == 0 ? "请输入新电话（按Enter键保持不变）: " : "Enter new phone (or press Enter to keep current): ");
                string newPhone;
                getline(cin, newPhone);

                if (newPhone.empty()) {
                    break;  // 按 Enter，保持当前电话
                }

                // 检查电话输入是否为纯数字
                bool validPhone = true;
                for (char c : newPhone) {
                    if (!isdigit(c)) {
                        validPhone = false;
                        break;
                    }
                }

                if (validPhone) {
                    contact.phone = newPhone;
                    break;  // 输入合法，退出循环
                }
                else {
                    cout << (language == 0 ? "无效的电话号码，请输入数字。" : "Invalid phone number. Please enter only numbers.") << endl;
                }
            }

            // 修改地址
            cout << (language == 0 ? "请输入新地址（按Enter键保持不变）: " : "Enter new address (or press Enter to keep current): ");
            string newAddr;
            getline(cin, newAddr);
            if (!newAddr.empty()) contact.addr = newAddr;

            // 修改性别，循环直到输入正确
            while (true) {
                cout << (language == 0 ? "请输入新性别 (1: 男, 2: 女) 或按Enter键保持不变: "
                    : "Enter new gender (1 for male, 2 for female, or press Enter to keep current): ");
                string genderInput;
                getline(cin, genderInput);
                if (genderInput.empty()) {
                    break;  // 按 Enter，保持当前性别
                }
                if (genderInput == "1") {
                    contact.gender = language == 0 ? "男" : "male";
                    break;
                }
                else if (genderInput == "2") {
                    contact.gender = language == 0 ? "女" : "female";
                    break;
                }
                else {
                    cout << (language == 0 ? "无效输入，请输入1或2。" : "Invalid input. Please enter 1 or 2.") << endl;
                }
            }

            // 修改年龄
            cout << (language == 0 ? "请输入新年龄（按Enter键保持不变）: " : "Enter new age (or press Enter to keep current): ");
            string ageInput;
            getline(cin, ageInput);
            if (!ageInput.empty()) {
                contact.age = stoi(ageInput);
            }

            cout << (language == 0 ? "联系人修改成功！" : "Contact edited successfully!") << endl;
            break;
        }
    }

    if (!found) {
        cout << (language == 0 ? "未找到联系人。" : "Contact not found.") << endl;
    }
}

// 清空联系人
void clearContacts() {
    contacts.clear();
    cout << (language == 0 ? "所有联系人已清空。" : "All contacts cleared.") << endl;
}

// 选择语言
void chooseLanguage() {
    cout << "请选择语言 / Choose your language: " << endl;
    cout << "1: 中文" << endl;
    cout << "2: English" << endl;
    int choice;
    cin >> choice;
    language = (choice == 2) ? 1 : 0;  // 选择英文则设置 language 为 1，默认中文为 0
}

// 主程序入口
int main() {
    chooseLanguage();  // 用户选择语言

    int select = 0;
    while (true) {
        showMenu();  // 显示菜单
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
            cout << (language == 0 ? "退出通讯录系统。" : "Exiting Contacts System.") << endl;
            return 0;
        default:
            cout << (language == 0 ? "无效选择，请重试。" : "Invalid selection, please try again.") << endl;
            break;
        }
    }
    return 0;
}
