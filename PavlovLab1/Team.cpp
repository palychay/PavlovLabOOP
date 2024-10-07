#include "Team.h"
#include <fstream>
#include <iostream>

void Team::addPlayer(shared_ptr<VolleyPlayer> player) {
	players.push_back(player);
}

void Team::seePlayer() const {
	for (const auto& player: players){
        player->writeToConsole();
	}
}

void Team::readFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Файл пуст." << endl;
        return;
    }

    string playerType;
    while (inFile >> playerType) {
        shared_ptr<VolleyPlayer> player;

        if (playerType == "VolleyPlayer") {
            player = make_shared<VolleyPlayer>();
        }
        else if (playerType == "Attacker") {
            player = make_shared<Attacker>();
        }

        if (player) {
            player->readFromFile(inFile);  // Виртуальный вызов
            addPlayer(player);
        }
    }
    inFile.close();
}

void Team::writeToFile(const string& filename) const {
    ofstream outFile(filename, ios::app);
    if (!outFile) {
        cerr << "Файл пуст." << endl;
        return;
    }

    for (const auto& player : players) {
        if (dynamic_pointer_cast<Attacker>(player)) {
            outFile << "Attacker" << endl;
        }
        else {
            outFile << "VolleyPlayer" << endl;
        }

        player->writeToFile(outFile);  // Виртуальный вызов
    }

    outFile.close();
}

void Team::clearPlayers() {
    players.clear();
}

Team::~Team() {
    clearPlayers();
}