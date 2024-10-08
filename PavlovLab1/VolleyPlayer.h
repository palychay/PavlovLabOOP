#pragma once

#include <string>
#include <fstream>
#include <boost/serialization/string.hpp>
#include <boost/serialization/access.hpp>


using namespace std;

class VolleyPlayer
{
protected:
    string name;
    int height;
    double weight;
    int age;

public:
    VolleyPlayer();

    VolleyPlayer(const string& name, int height, double weight, int age);

    virtual void readFromConsole();
    virtual void writeToConsole() const;
    
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
        ar& name;
        ar& height;
        ar& weight;
        ar& age;
    }

    virtual ~VolleyPlayer() = default;
};

