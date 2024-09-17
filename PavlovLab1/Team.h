#pragma once

#include <vector>
#include "VolleyPlayer.h"

using namespace std;

class Team
{
    vector<VolleyPlayer*> players;

public:
    void addPlayer(VolleyPlayer* player);
    void seePlayer() const;
    void readFromFile(const string& filename);
    void writeToFile(const string& filename) const;
    void clearPlayers();

    ~Team();
};

