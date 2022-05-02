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


class Verkeerslicht{
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

    void setPositie(int positie2);

    void setCyclus(int cyclus);

    void changeState(double fTijd);

    void actieAuto(vector<Voertuig*> &vectVoertuigen);

    const string &getFCurrentKleurState();


};


#endif //OEFENINGXML_VERKEERSLICHT_H
