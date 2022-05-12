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
    char afkortingKleur;

public:

    /**
     \n ENSURE(this->properlyInitialized(),"verkeerslichtconstructor moet geintitialiseerd worden");
     */

    bool properlyInitialized();
    Verkeerslicht();

    /**
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer setBaan werd opgeroepen");
     */

    void setBaan(Baan *baan);

    /**
     \n ENSURE(baan != NULL,"het moet een baan zijn");
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer getBaan werd opgeroepen");
     */

    Baan *getBaan();

    /**
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer getPositie werd opgeroepen");
     */

    int getPositie();

    /**
     \n ENSURE(fPositie >= 0 && fPositie <= this->getBaan()->getLengte(),"positie moet bestaan");
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer setPositie werd opgeroepen");
     */

    void setPositie(int positie2);

    /**
     \n ENSURE(fPositie >= 0 && fPositie <= fBaan->getLengte(),"positie moet bestaan");
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer getCyclus werd opgeroepen");
     */

    int getCyclus();

    /**
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer setCyclus werd opgeroepen");
     */

    void setCyclus(int cyclus);

    /**
     \n ENSURE(cyclus >= 0,"de cyclus kan groter of gelijk zijn aan 0");
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer changeState werd opgeroepen");
     */

    void changeState(double fTijd);

    /**
     \n ENSURE(fTijd >= 0,"tijd kan niet negatief");
     \n ENSURE(fCurrentKleurState != "","het moet groen of rood zijn en niet leeg");
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer whichState werd opgeroepen");
     */

    void actieAuto(vector<Voertuig*> &vectVoertuigen);

    /**
     \n ENSURE(fCurrentKleurState != "", "het moet groen of rood zijn en niet leeg");
     \n ENSURE(vectVoertuigen.size() > 0, "vectVoertuigen mag niet leeg zijn");
     \n ENSURE(fPositie >= 0 && fPositie <= this->getBaan()->getLengte(),"positie moet bestaan");
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer getFCurrentKleurstate werd opgeroepen");
     */

    const string &getFCurrentKleurState();

    /**
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer simulatieverkeer werd opgeroepen");
     */

    void simulatieVerkeer(double fTijd, vector<Voertuig*>& vectVoertuigen);

    /**
     \n ENSURE(fTijd >= 0,"tijd kan niet negatief zijn");
     \n ENSURE(!vectVoertuigen.empty(),"vector mag niet leeg zijn");
     */



};


#endif //OEFENINGXML_VERKEERSLICHT_H
