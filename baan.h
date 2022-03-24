// Prototype van classe Baan
// Marceli Wilczynski && Tomas Ghysels
// 18.03.2022
// version 1.0

#ifndef OEFENINGXML_BAAN_H
#define OEFENINGXML_BAAN_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Verkeerslicht;
class Voertuig;

class Baan {
protected:
    Baan* _initCheck;

    string fNaam;

    int fLengte;

    vector<Voertuig*> vectVoertuigen;

    Verkeerslicht* verkeerslichtOpBaan;

    vector<Verkeerslicht*> fVerkeerslichten;

    int fTijd;

public:
    bool properlyInitialized();

    Baan();

    const vector<Verkeerslicht *> &getFVerkeerslichten() const;

    void setTijd(int tijd);

    int getTijd();

    const vector<Voertuig *> &getVectVoertuigen();

    void setNaam(string a);

    void setLengte(int lengte);

    const string &getNaam();

    int getLengte();

    Verkeerslicht *getVerkeerslichtOpBaan();

    void addVector(Voertuig* v1);

    void addVerkeerslicht(Verkeerslicht* v1);

    int searchVoertuig(Voertuig* v);

    void insertionSort();
};


#endif //OEFENINGXML_BAAN_H