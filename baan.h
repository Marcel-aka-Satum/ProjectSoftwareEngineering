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
class Bushalte;
class Kruispunt;

class Baan {
protected:
    Baan* _initCheck;

    string fNaam;

    int fLengte;

    Verkeerslicht* verkeerslichtOpBaan;

    vector<Verkeerslicht*> fVerkeerslichten;

    int fTijd;

    Bushalte* bushalte2;

    vector<Kruispunt*> fKruispunten;

    double fSimulatietijd;

public:
    vector<Voertuig*> vectVoertuigen;

    bool properlyInitialized();

    Baan();

    vector<Verkeerslicht *> &getFVerkeerslichten();

    void setTijd(int tijd);

    int getTijd();

    vector<Voertuig *> &getVectVoertuigen();

    void setNaam(string a);

    void setLengte(int lengte);

    const string &getNaam();

    int getLengte();

    Verkeerslicht *getVerkeerslichtOpBaan();

    void addVector(Voertuig* v1, vector<Voertuig*> &vectVoertuigen2);

    void addVerkeerslicht(Verkeerslicht* v1, vector<Verkeerslicht*> &fVerkeerslichten2);

    int searchVoertuig(Voertuig* v, Baan b1, vector<Voertuig*> vectVoertuigen2);

    void insertionSort(vector<Voertuig*> &vectVoertuigen2);

    Bushalte *getBushalte2() const;

    void setBushalte2(Bushalte *bushalte);

    void addToKruispunten(Kruispunt* k1);

    vector<Kruispunt *> &getFKruispunten();

    void simpel_uitvoer();

    double getFSimulatietijd() const;

    void setFSimulatietijd(double fSimulatietijd);

};


#endif //OEFENINGXML_BAAN_H