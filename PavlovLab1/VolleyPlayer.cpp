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
}

void VolleyPlayer::readFromFile(ifstream& in) {
	in >> name >> height >> weight >> age;
}

void VolleyPlayer::writeToFile(ofstream& out) const {
	out << name << " " << height << " " << weight << " " << age << endl;
}

void Attacker::readFromConsole() {
	VolleyPlayer::readFromConsole();  // ����� ������� ����������
	cout << "������� �������� ����� � ��/�: ";
	power = get_correct(120, 70);
	cout << "������� ������ ������ � ��: ";
	jump = get_correct(120, 40);
}

void Attacker::writeToConsole() const {
	VolleyPlayer::writeToConsole();  // ����� ������� ����������
	cout << "�������� ����� � ��/�: " << power << endl;
	cout << "������ ������ � ��: " << jump << endl;
	cout << endl;
}

void Attacker::readFromFile(ifstream& in) {
	VolleyPlayer::readFromFile(in);  // ������ ����� �����
	in >> power >> jump;             // ������ ���������� ����� ��� Attacker
}

void Attacker::writeToFile(ofstream& out) const {
	VolleyPlayer::writeToFile(out);  // ������ ����� �����
	out << power << " " << jump << endl;  // ������ ���������� ����� ��� Attacker
}