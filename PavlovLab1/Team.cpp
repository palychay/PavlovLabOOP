#include "Team.h"
#include <fstream>
#include <iostream>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/export.hpp>

BOOST_CLASS_EXPORT(Attacker)
BOOST_CLASS_EXPORT(VolleyPlayer)

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
        cerr << "error." << endl;
        return;
    }

    boost::archive::text_iarchive ia(inFile);
    ia >> players;

    inFile.close();
}

void Team::writeToFile(const string& filename) const {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "error." << endl;
        return;
    }

    boost::archive::text_oarchive oa(outFile);
    oa << players;

    outFile.close();
}


void Team::clearPlayers() {
    players.clear();
}

Team::~Team() {
    clearPlayers();
}