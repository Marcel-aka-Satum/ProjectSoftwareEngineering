// Prototype van classe Baan
// Marceli Wilczynski && Tomas Ghysels
// 18.03.2022
// version 1.0

#ifndef OEFENINGXML_BAAN_H
#define OEFENINGXML_BAAN_H
#include <iostream>
#include <string>
#include <vector>
#include "fstream"
using namespace std;

class Verkeerslicht;
class Voertuig;
class Bushalte;
class Kruispunt;
class Voertuiggenerator;

class Baan {
private:
    Baan* _initCheck;

    string fNaam;

    int fLengte;

    vector<Verkeerslicht*> fVerkeerslichten;

    int fTijd;

    vector<Kruispunt*> fKruispunten;

    double fSimulatietijd;

    vector<Voertuig*> vectVoertuigen;

    vector <Bushalte*> fBushaltes;

    vector <Voertuiggenerator*> fGeneratoren;

public:

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

    void addVector(Voertuig* v1, vector<Voertuig*> &vectVoertuigen2);

    void addVerkeerslicht(Verkeerslicht* v1);

    int searchVoertuig(Voertuig* v, Baan b1, vector<Voertuig*> vectVoertuigen2);

    void insertionSort(vector<Voertuig*> &vectVoertuigen2);

    void addToKruispunten(Kruispunt* k1);

    vector<Kruispunt *> &getFKruispunten();

    void simpel_uitvoer();

    double getFSimulatietijd();

    void setFSimulatietijd(double fSimulatietijd2);

    void grafischeImpressie();

    void addBushalteToVector(Bushalte* b1);

    char getAfkortingKleur() const;

    void addToGeneratoren(Voertuiggenerator* generator1);

};


#endif //OEFENINGXML_BAAN_H