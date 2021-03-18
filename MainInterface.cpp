#include <iostream>
#include <string>
#include <fstream>

#define MAX 100

using namespace std;

class Contact
{
public:
	
	string get_name() {
		return name;
	}
	string get_addr() {
		return addr;
	}
	string get_number() {
		return number;
	}
	string get_gender() {
		return gender ? "男" : "女";
	}


	void set_name(string n) {
		name = n;
	}
	void set_addr(string a) {
		addr = a;
	}
	void set_number(string n) {
		number = n;
	}
	void set_gender(int g) {
		gender = g;
	}


private:
	string name;
	int gender=0;
	string addr;
	string number;
};

class AddressBook {
public:
	class Contact contactArray[MAX];
	int m_size=0;
};

void addContact(AddressBook * abs) {
	if (abs->m_size >= MAX) {
		cout << "通讯录已满" << endl; 
		return;
	}
	string name;
	string addr;
	string number;
	int gender;
	cout << "姓名：";
	cin >> name;
	abs->contactArray[abs->m_size].set_name(name);

	cout << "电话：";
	cin >> number;
	abs->contactArray[abs->m_size].set_number(number);

	cout << "性别：";
	while (true) {
		cin >> gender;
		if(gender == 1 || gender == 0){
			abs->contactArray[abs->m_size].set_gender(gender);
			break;
		}
		cout << "男--1  女--0" << endl;
		cout << "请重新输入:";
		
	}


	cout << "地址：";
	cin >> addr;
	abs->contactArray[abs->m_size].set_addr(addr);
	abs->m_size++;
	cout << "保存成功!" << endl;
	system("pause");
}

void listContact(AddressBook * abs) {
	if (abs->m_size == 0) {
		cout << "联系人为空！" << endl;
		return;
	}
	for (int i = 0; i < abs->m_size; ++i) {
		cout << "姓名：" << abs->contactArray[i].get_name() << endl;
		cout << "性别：" << abs->contactArray[i].get_gender() << endl;
		cout << "号码：" << abs->contactArray[i].get_number() << endl;
		cout << "地址：" << abs->contactArray[i].get_addr() << endl;
		cout << endl;
	}
	system("pause");
}

void editContact(AddressBook * abs) {
	cout << "请输入要修改的联系人姓名：";
	string name;
	cin >> name;
	bool flag = true;
	for (int i = 0; i <= abs->m_size; ++i) {
		if (abs->contactArray[i].get_name() == name) {
			string name;
			string addr;
			string number;
			bool gender;
			cout << "姓名：";
			cin >> name;
			abs->contactArray[i].set_name(name);

			cout << "电话：";
			cin >> number;
			abs->contactArray[i].set_number(number);

			cout << "性别：";
			cin >> gender;
			abs->contactArray[i].set_gender(gender);

			cout << "地址：";
			cin >> addr;
			abs->contactArray[i].set_addr(addr);
			cout << "保存成功!" << endl;
			flag = !flag;
		}
	}
	if (flag) {
		cout << "查无此人！" << endl;
	}
	system("pause");
}

void delContact(AddressBook * abs) {
	cout << "请输入要删除的联系人姓名：";
	string name;
	cin >> name;
	bool flag = true;
	for (int i = 0; i <= abs->m_size; ++i) {
		if (abs->contactArray[i].get_name() == name) {
			for (int j = i; j < abs->m_size; ++j) {
				abs->contactArray[j] = abs->contactArray[j + 1];
			}
			abs->m_size -= 1;
			flag = !flag;
		}
	}
	if (flag) {
		cout << "查无此人！" << endl;
	}
	else {
		cout << "删除成功！" << endl;
	}
	system("pause");
}

void writeFile(AddressBook* abs) {
	if (abs->m_size == 0) {
		cout << "联系人为空！" << endl;
		return;
	}
	string fileName;
	cout << "请输入文件名：";
	cin >> fileName;
	ofstream file;
	file.open(fileName);
	for (int i = 0; i < abs->m_size; ++i) {
		file << "姓名：" << abs->contactArray[i].get_name() << "\n";
		file << "性别：" << abs->contactArray[i].get_gender() << "\n";
		file << "号码：" << abs->contactArray[i].get_number() << "\n";
		file << "地址：" << abs->contactArray[i].get_addr() << "\n";
		file << "\n";
	}
	file.close();
	cout << "导出成功" << endl;
	system("pause");
}

void clearContact(AddressBook * abs) {
	abs->m_size=0;
	cout << "联系人已清空！" << endl;
	system("pause");
}

void showMenu() {
	cout << "*************************" << endl;
	cout << "***** 1、添加联系人 *****" << endl;
	cout << "***** 2、查看联系人 *****" << endl;
	cout << "***** 3、修改联系人 *****" << endl;
	cout << "***** 4、删除联系人 *****" << endl;
	cout << "***** 5、清空联系人 *****" << endl;
	cout << "***** 6、导出联系人 *****" << endl;
	cout << "***** 0、退出通讯录 *****" << endl;
	cout << "*************************" << endl;
}

int main() {
	AddressBook abs;
	int select;
	while (true) {
		system("cls");
		showMenu();
		cin >> select;
		switch (select) {
		case 1:
			addContact(&abs);
			break;
		case 2:
			listContact(&abs);
			break;
		case 3:
			editContact(&abs);
			break;
		case 4:
			delContact(&abs);
			break;
		case 5:
			clearContact(&abs);
			break;
		case 6:
			writeFile(&abs);
			break;
		case 0:
			cout << "通讯录已关闭" << endl;
			system("pause");
			return 0;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}