#pragma once
#include <string>;
#include <fstream>

using namespace std;

class VolleyPlayer
{
    string name;
    int height;
    double weight;
    int age;

public:
    VolleyPlayer();

    VolleyPlayer(const string& name, int height, double weight, int age);

    void readFromConsole();
    void writeToConsole() const;
    void readFromFile(ifstream& in);
    void writeToFile(ofstream& out) const;
};

