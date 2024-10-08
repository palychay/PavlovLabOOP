#include "Attacker.h"
#include "Correct.h"
#include <iostream>


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
