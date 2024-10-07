#include "VolleyPlayer.h"
#include "Correct.h"
#include <iostream>

VolleyPlayer::VolleyPlayer() : name(""), height(0), weight(0), age(0) {}

VolleyPlayer::VolleyPlayer(const string& name, int height, double weight, int age):
	name(name), height(height), weight(weight), age(age) {}

void VolleyPlayer::readFromConsole() {
	cout << "Введите имя: ";
	cin >> ws;
	getline(cin,name);
	cout << "Введите рост: ";
	height = get_correct(220, 170);
	cout << "Введите вес: ";
	weight = get_correct(110, 60);
	cout << "Введите возраст: ";
	age = get_correct(50, 15);
}

void VolleyPlayer::writeToConsole() const{
	cout << "Имя: " << name << endl;
	cout << "Рост:" << height << endl;
	cout << "Вес:" << weight << endl;
	cout << "Возраст:" << age << endl;
}

void VolleyPlayer::readFromFile(ifstream& in) {
	in >> name >> height >> weight >> age;
}

void VolleyPlayer::writeToFile(ofstream& out) const {
	out << name << " " << height << " " << weight << " " << age << endl;
}

void Attacker::readFromConsole() {
	VolleyPlayer::readFromConsole();  // Вызов базовой реализации
	cout << "Введите мощность удара в км/ч: ";
	power = get_correct(120, 70);
	cout << "Введите высоту прыжка в см: ";
	jump = get_correct(120, 40);
}

void Attacker::writeToConsole() const {
	VolleyPlayer::writeToConsole();  // Вызов базовой реализации
	cout << "Мощность удара в км/ч: " << power << endl;
	cout << "Высота прыжка в см: " << jump << endl;
	cout << endl;
}

void Attacker::readFromFile(ifstream& in) {
	VolleyPlayer::readFromFile(in);  // Чтение общих полей
	in >> power >> jump;             // Чтение уникальных полей для Attacker
}

void Attacker::writeToFile(ofstream& out) const {
	VolleyPlayer::writeToFile(out);  // Запись общих полей
	out << power << " " << jump << endl;  // Запись уникальных полей для Attacker
}