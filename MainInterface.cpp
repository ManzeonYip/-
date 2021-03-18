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
		return gender ? "��" : "Ů";
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
		cout << "ͨѶ¼����" << endl; 
		return;
	}
	string name;
	string addr;
	string number;
	int gender;
	cout << "������";
	cin >> name;
	abs->contactArray[abs->m_size].set_name(name);

	cout << "�绰��";
	cin >> number;
	abs->contactArray[abs->m_size].set_number(number);

	cout << "�Ա�";
	while (true) {
		cin >> gender;
		if(gender == 1 || gender == 0){
			abs->contactArray[abs->m_size].set_gender(gender);
			break;
		}
		cout << "��--1  Ů--0" << endl;
		cout << "����������:";
		
	}


	cout << "��ַ��";
	cin >> addr;
	abs->contactArray[abs->m_size].set_addr(addr);
	abs->m_size++;
	cout << "����ɹ�!" << endl;
	system("pause");
}

void listContact(AddressBook * abs) {
	if (abs->m_size == 0) {
		cout << "��ϵ��Ϊ�գ�" << endl;
		return;
	}
	for (int i = 0; i < abs->m_size; ++i) {
		cout << "������" << abs->contactArray[i].get_name() << endl;
		cout << "�Ա�" << abs->contactArray[i].get_gender() << endl;
		cout << "���룺" << abs->contactArray[i].get_number() << endl;
		cout << "��ַ��" << abs->contactArray[i].get_addr() << endl;
		cout << endl;
	}
	system("pause");
}

void editContact(AddressBook * abs) {
	cout << "������Ҫ�޸ĵ���ϵ��������";
	string name;
	cin >> name;
	bool flag = true;
	for (int i = 0; i <= abs->m_size; ++i) {
		if (abs->contactArray[i].get_name() == name) {
			string name;
			string addr;
			string number;
			bool gender;
			cout << "������";
			cin >> name;
			abs->contactArray[i].set_name(name);

			cout << "�绰��";
			cin >> number;
			abs->contactArray[i].set_number(number);

			cout << "�Ա�";
			cin >> gender;
			abs->contactArray[i].set_gender(gender);

			cout << "��ַ��";
			cin >> addr;
			abs->contactArray[i].set_addr(addr);
			cout << "����ɹ�!" << endl;
			flag = !flag;
		}
	}
	if (flag) {
		cout << "���޴��ˣ�" << endl;
	}
	system("pause");
}

void delContact(AddressBook * abs) {
	cout << "������Ҫɾ������ϵ��������";
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
		cout << "���޴��ˣ�" << endl;
	}
	else {
		cout << "ɾ���ɹ���" << endl;
	}
	system("pause");
}

void writeFile(AddressBook* abs) {
	if (abs->m_size == 0) {
		cout << "��ϵ��Ϊ�գ�" << endl;
		return;
	}
	string fileName;
	cout << "�������ļ�����";
	cin >> fileName;
	ofstream file;
	file.open(fileName);
	for (int i = 0; i < abs->m_size; ++i) {
		file << "������" << abs->contactArray[i].get_name() << "\n";
		file << "�Ա�" << abs->contactArray[i].get_gender() << "\n";
		file << "���룺" << abs->contactArray[i].get_number() << "\n";
		file << "��ַ��" << abs->contactArray[i].get_addr() << "\n";
		file << "\n";
	}
	file.close();
	cout << "�����ɹ�" << endl;
	system("pause");
}

void clearContact(AddressBook * abs) {
	abs->m_size=0;
	cout << "��ϵ������գ�" << endl;
	system("pause");
}

void showMenu() {
	cout << "*************************" << endl;
	cout << "***** 1�������ϵ�� *****" << endl;
	cout << "***** 2���鿴��ϵ�� *****" << endl;
	cout << "***** 3���޸���ϵ�� *****" << endl;
	cout << "***** 4��ɾ����ϵ�� *****" << endl;
	cout << "***** 5�������ϵ�� *****" << endl;
	cout << "***** 6��������ϵ�� *****" << endl;
	cout << "***** 0���˳�ͨѶ¼ *****" << endl;
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
			cout << "ͨѶ¼�ѹر�" << endl;
			system("pause");
			return 0;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}