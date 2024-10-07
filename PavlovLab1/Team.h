#pragma once

#include <vector>
#include "VolleyPlayer.h"
#include <memory>

using namespace std;

class Team
{
    vector<shared_ptr<VolleyPlayer>> players;

public:
    void addPlayer(shared_ptr<VolleyPlayer> player);
    void seePlayer() const;
    void readFromFile(const string& filename);
    void writeToFile(const string& filename) const;
    void clearPlayers();

    ~Team();
};

