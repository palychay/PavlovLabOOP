#pragma once
#include <string>;
#include <fstream>

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
    virtual void readFromFile(ifstream& in);
    virtual void writeToFile(ofstream& out) const;

    virtual ~VolleyPlayer() = default;  // ����������� ����������
};

class Attacker : public VolleyPlayer
{
    int power;
    double jump;

public:
    void readFromConsole() override;
    void writeToConsole() const override;
    void readFromFile(ifstream& in) override;  // ��������������� ������ �� �����
    void writeToFile(ofstream& out) const override;  // ��������������� ������ � ����
};