#include "VolleyPlayer.h"
#include "Correct.h"
#include <iostream>


VolleyPlayer::VolleyPlayer() : name(""), height(0), weight(0), age(0) {}

VolleyPlayer::VolleyPlayer(const string& name, int height, double weight, int age):
	name(name), height(height), weight(weight), age(age) {}

void VolleyPlayer::readFromConsole() {
	cout << "������� ���: ";
	cin >> ws;
	getline(cin,name);
	cout << "������� ����: ";
	height = get_correct(220, 170);
	cout << "������� ���: ";
	weight = get_correct(110, 60);
	cout << "������� �������: ";
	age = get_correct(50, 15);
}

void VolleyPlayer::writeToConsole() const{
	cout << "���: " << name << endl;
	cout << "����:" << height << endl;
	cout << "���:" << weight << endl;
	cout << "�������:" << age << endl;
	cout << endl;
}
