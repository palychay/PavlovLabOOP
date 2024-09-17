#include <iostream>
#include "Team.h"
#include "Correct.h"
#include <Windows.h>

using namespace std;

void showMenu() {
    cout << "\nМеню:" << endl;
    cout << "1. Добавить нового игрока" << endl;
    cout << "2. Показать всех игроков" << endl;
    cout << "3. Загрузить игроков из файла" << endl;
    cout << "4. Сохранить игроков в файл" << endl;
    cout << "5. Очистить список игроков" << endl;
    cout << "6. Выйти" << endl;
    cout << "Выберите действие (1-6): ";
}

void handleAddPlayer(Team& team) {
    VolleyPlayer* player = new VolleyPlayer();
    player->readFromConsole();
    team.addPlayer(player);
}

void handleDisplayPlayers(const Team& team) {
    team.seePlayer();
}

void handleLoadFromFile(Team& team) {
    string filename;
    cout << "Введите имя файла для загрузки: ";
    cin >> ws;
    getline(cin, filename);
    team.readFromFile(filename);
}

void handleSaveToFile(const Team& team) {
    string filename;
    cout << "Введите имя файла для сохранения: ";
    cin >> ws;
    getline(cin, filename);
    team.writeToFile(filename);
}

void handleClearPlayers(Team& team) {
    team.clearPlayers();
    cout << "Список игроков очищен." << endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Team team;
    bool running = true;

    while (running) {
        showMenu();
        int choice = get_correct(6, 1);

        switch (choice) {
        case 1:
            handleAddPlayer(team);
            break;
        case 2:
            handleDisplayPlayers(team);
            break;
        case 3:
            handleClearPlayers(team);
            handleLoadFromFile(team);
            break;
        case 4:
            handleSaveToFile(team);
            break;
        case 5:
            handleClearPlayers(team);
            break;
        case 6:
            running = false;
            break;
        default:
            break;
        }
        
    }
    
    return 0;
}

