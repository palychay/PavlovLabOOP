#include "Team.h"
#include <fstream>
#include <iostream>

void Team::addPlayer(VolleyPlayer* player) {
	players.push_back(player);
}

void Team::seePlayer() const {
	for (const VolleyPlayer* player: players){
        player->writeToConsole();
	}
}

void Team::readFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Файл пуст." << endl;
        return;
    }

    VolleyPlayer* player = nullptr;
    while (inFile) {
        player = new VolleyPlayer();
        player->readFromFile(inFile);
        if (inFile) {
            addPlayer(player);
        }
        else {
            delete player;
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

    for (const VolleyPlayer* player : players) {
        player->writeToFile(outFile);
    }

    outFile.close();
}

void Team::clearPlayers() {
    for (VolleyPlayer* player : players) {
        delete player;
    }
    players.clear();
}

Team::~Team() {
	clearPlayers();
}