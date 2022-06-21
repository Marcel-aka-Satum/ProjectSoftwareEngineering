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

    /**
     \n ENSURE(this->properlyInitialized(), "De voertuigconstructor is slecht geinitialiseerd");
     */

    Voertuig();
    bool properlyInitialized();

    /**
     \n REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
     */

    Baan *getBaan();

    /**
     \n REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
     */

    double getPositie();

    /**
     \n ENSURE((fPositie >= 0), "Positie is kleiner dan 0");
     \n REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
     */

    void setBaan(Baan *baan);

    /**
     \n ENSURE(baan->properlyInitialized(), "De constructor is slecht geinitialiseerd");
     \n REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
     \n REQUIRE((positie >= 0), "Positie is kleiner dan 0");
     */

    void setPositie(int positie);

    /**
     \n ENSURE((positie >= 0), "Positie is kleiner dan 0");
     \n REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
     \n REQUIRE((fSnelheid >= 0), "Positie is kleiner dan 0");
     */

    double getSnelheid();

    /**
     \n REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
     \n REQUIRE((fAbs_max_snelheid == 16.6), "De absolute max snelheid != 16.6");
     */

    double getAbs_max_snelheid();

    /**
     \n REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
     \n REQUIRE((fSnelheid >= 0), "De snelheid van jouw Voertuig is < 0");
     */

    void change_positie();

    /**
     \n ENSURE((fPositie >= 0 && fPositie <= this->getBaan()->getLengte()),"Positite van jouw voertuig is buiten de baan");
     \n REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
     */

    void change_versnelling(vector<Voertuig*> &vectVoertuigen);

    /**
     \n ENSURE((index >= 0), "De index van jouw voertuig is kleiner dan 0");
     \n ENSURE((fVolgafstand >= 0), "Volgafstand tussen jouw 2 voertuigen is niet correct");
     \n ENSURE((fSnelheidsverschil >= 0), "De snelheidsverschil van jouw voertuig is kleiner dan 0");
     \n REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
     */

    int getFindexVoertuig();

    /**
     \n ENSURE((fIndexVoertuig > 0), "Index van jouw voertuig is niet in de baan");
     \n REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
     */

    void setFindexVoertuig(int findexVoertuig);

    /**
     \n ENSURE((fIndexVoertuig >= 0), "Jouw index van jouw voertuig is niet correct");
     \n REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
     */

    int getFLengte();

    /**
     \n ENSURE(fLengte >= 0, "De lengte van jouw voertuig is niet correct");
     \n REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
     */

    int getFMinVolgafstand();

    /**
     \n ENSURE(fMin_volgafstand == 4, "De minimale volgafstand is niet correct");
     \n REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
     */

    bool checkInBaan(Baan& b1, vector<Voertuig*> vectVoertuigen);

    /**
     \n REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
     */

    void verwijderUitBaan(Baan& b1, vector<Voertuig*> vectVoertuigen);

    /**
     \n REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
     */

    void vertragen();

    /**
     \n ENSURE(fMax_snelheid >= 0, "De Max_snelheid van jouw voertuig is niet correct");
     \n REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
     */

    void versnellen();

    /**
     \n REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
     */

    void stoppen();

    /**
     \n REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
     \n REQUIRE(fMax_remfactor == 4.61,"Max Remfactor is niet correct");
     */

    double getFMaxRemfactor();

    /**
     \n REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
     */

    const string &getType();

    /**
     \n REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
     */

    void setType(const string &type2);

    /**
     \n ENSURE(type2 != "","string mag niet leeg zijn");
     \n REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
     */

    void changeTypeVoertuig();

    /**
     \n REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
     */

    const string &getAfkortingType();

    /**
     \n REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
     */

    void setAfkortingType(const string &afkortingType);

    /**
     \n ENSURE(afkortingType != "", "Een voertuig moet een afkorting hebben");
     */
};



#endif //OEFENINGXML_VOERTUIGEN_H