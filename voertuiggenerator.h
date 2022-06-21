// Prototype van classe Voertuiggenerator
// Marceli Wilczynski && Tomas Ghysels
// 18.03.2022
// version 1.0

#ifndef OEFENINGXML_VOERTUIGGENERATOR_H
#define OEFENINGXML_VOERTUIGGENERATOR_H
#include <iostream>

using namespace std;

class Baan;

class Voertuiggenerator {

private:
    Voertuiggenerator* _initCheck;
    int fFrequentie;
    Baan* fBaan;
    string type;


public:

    /**
     \n ENSURE(this->properlyInitialized(), "voertuiggeneratorconstructor moet goed geinitialiseerd worden");
     */

    Voertuiggenerator();
    bool properlyInitialized();

    /**
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer getFrequentie werd opgeroepen");
     */

    int getFrequentie();

    /**
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer setNaam werd opgeroepen");
     */

    void setFrequentie(int frequentie);

    /**
     \n ENSURE(frequentie >= 0,"frequentie moet positief zijn");
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer setNaam werd opgeroepen");
     */

    Baan *getBaan();

    /**
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer setNaam werd opgeroepen");
     */

    void setBaan(Baan *baan);

    /**
     \n ENSURE(baan !=NULL, "het moet een baan zijn");
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer getType werd opgeroepen");
     */

    const string & getType();

    /**
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer setType werd opgeroepen");
     */

    void setType(const string &type2);

};


#endif //OEFENINGXML_VOERTUIGGENERATOR_H