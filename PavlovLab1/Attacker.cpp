#include "Attacker.h"
#include "Correct.h"
#include <iostream>


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
