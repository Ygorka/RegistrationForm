#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string username, password, pw;

void reg();
void create();

int main() {
	int choice;
	cout << "1.Registration\n2.Loggin\n3.Forgot password\n4.Exit\nYour choice:";
	cin >> choice;
	cout << endl;

	switch (choice) {
	case 1: {//регистрация
		reg();
		break;
	}
	case 2: {//вход

		cout << "Enter your username: ";
		cin >> username;

		ifstream log;
		log.open(username + ".txt");
		if (log.is_open()) {//проверка существует ли аккаунт 			
			cout << "Enter your password: ";
			cin >> password;

			getline(log, pw);//запись пароля из файла в переменную string

			if (pw == password) { //проверка пароля введеного пользователем и пароля из файла
				cout << "Welcome";
			}
			else {
				cout << "Wrong password!";
				cout << endl;
			}

			log.close();
		}
		else {
			create();
		}

		break;
	}
	case 3: {//если забылт пароль

		cout << "Enter your username: ";
		cin >> username;

		ifstream log;

		log.open(username + ".txt");
		if (log.is_open()) {//проверка существует ли аккаунт

			cout << "Enter new password: ";
			cin >> password;

			ofstream fog;
			fog.open(username + ".txt");
			fog << password;//запись нового пароля в файл
			fog.close();
			log.close();
			cout << endl;
			main();
		}
		else {
			create();
		}

	}
	case 4: {//выход
		return 0;
	}
	default: {
		cout << "Wrong answer";
		cout << endl;
		main();
	}
	}
}

void reg() {

	cout << "Enter your username: ";
	cin >> username;

	cout << "Enter your password: ";
	cin >> password;

	cout << endl;

	ofstream reg;
	reg.open(username + ".txt");
	reg << password; // Создание файла с паролем
	reg.close();

	main();
}

void create() {//создание уч.записи, если ее нету
	int create;
	cout << "User does not exist.\nDo you want create?\n1.Yes\n2.No\nYour choice:";
	cin >> create;
	switch (create)
	{
	case 1: {
		reg();
		main();
	}
	case 2: {
		cout << "So sad :(";
		break;
	}
	default:
		cout << "Wrong choice";
		cout << endl<<endl;
		main();
	}
}