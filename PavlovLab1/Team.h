#pragma once

#include <vector>
#include "VolleyPlayer.h"
#include "Attacker.h"
#include <boost/serialization/vector.hpp>
#include <boost/serialization/access.hpp>
#include <boost/serialization/shared_ptr.hpp>


using namespace std;

class Team
{
    vector<shared_ptr<VolleyPlayer>> players;

public:
    void addPlayer(shared_ptr<VolleyPlayer> player);
    void seePlayer() const;

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
        ar& players;
    }
   
    void readFromFile(const string& filename);
    void writeToFile(const string& filename) const;

    void clearPlayers();

    ~Team();
};

