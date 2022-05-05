// Prototype van classe Voertuig
// Marceli Wilczynski && Tomas Ghysels
// 18.03.2022
// version 1.0

#ifndef OEFENINGXML_VOERTUIGEN_H
#define OEFENINGXML_VOERTUIGEN_H

#include "verkeerslicht.h"
#include "baan.h"
using namespace std;

class Voertuig{
protected:
    Voertuig* _initCheck;
    Baan* fBaan;
    double fPositie;
    double fSnelheid;
    int fLengte;
    double fAbs_max_snelheid;
    double fMax_snelheid;
    double fVersnelling;
    double fMax_versnelling;
    double fMax_remfactor;
    int fMin_volgafstand;
    int fVertraagafstand;
    int fStopafstand;
    double fVertraagfactor;
    int fIndexVoertuig;
    double fVolgafstand;
    double fSnelheidsverschil;
    double fDelta;
    string type;
    string afkortingType;

public:
    Voertuig();

    bool properlyInitialized();

    Baan *getBaan();

    double getFMaxRemfactor();

    double getPositie();

    void setBaan(Baan *baan);

    void setPositie(int positie);

    double getSnelheid();

    double getAbs_max_snelheid();

    void print();

    void change_positie(double fSimulatietijd);

    void change_versnelling(vector<Voertuig*> vectVoertuigen);

    int getFindexVoertuig();

    void setFindexVoertuig(int findexVoertuig);

    int getFLengte();

    int getFMinVolgafstand();

    bool checkInBaan(Baan& b1, vector<Voertuig*> vectVoertuigen);

    void verwijderUitBaan(Baan& b1, vector<Voertuig*> vectVoertuigen);

    void vertragen();

    void versnellen();

    void stoppen();

    const string & getType();

    void setType(const string &type);

    void changeTypeVoertuig();

    const string & getAfkortingType();
};



#endif //OEFENINGXML_VOERTUIGEN_H
