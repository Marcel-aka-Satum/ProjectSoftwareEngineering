// Prototype van classe Verkeerslicht
// Marceli Wilczynski && Tomas Ghysels
// 18.03.2022
// version 1.0

#ifndef OEFENINGXML_VERKEERSLICHT_H
#define OEFENINGXML_VERKEERSLICHT_H

#include <vector>
#include <string>
#include "baan.h"

using namespace std;


class Verkeerslicht : protected Baan {
private:
    Verkeerslicht* _initCheck;
    Baan* fBaan;
    int fPositie;
    int fCyclus;
    string fCurrentKleurState;

public:
    bool properlyInitialized();

    Verkeerslicht();

    void setBaan(Baan *baan);

    Baan *getBaan();

    int getPositie();

    int getCyclus();

    void setPositie(int positie);

    void setCyclus(int cyclus);

    void changeState();

    void actieAuto();

    const string &getFCurrentKleurState();

    void simulatieVerkeerslicht();

};


#endif //OEFENINGXML_VERKEERSLICHT_H
