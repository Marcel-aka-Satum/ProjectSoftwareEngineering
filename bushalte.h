//
// Created by marcel on 21/04/2022.
//

#ifndef VERKEERSSIMULATIE_BUSHALTE_H
#define VERKEERSSIMULATIE_BUSHALTE_H

#include "iostream"

using namespace std;

class Baan;

class Bushalte {
private:
    Bushalte* _initCheck;

    int positie;

    Baan* baan;

    int wachttijd;

public:

    /**
     \n ENSURE(this->properlyInitialized(), "Bushalte constructor moet goed geinitialiseerd worden");
     */

    Bushalte();
    bool properlyInitialized();

    /**
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer getPositie werd opgeroepen");
     */

    int getPositie();

    /**
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer setPositie werd opgeroepen");
     */

    void setPositie(int positie2);

    /**
     \n ENSURE(positie2 >= 0,"de positie kan niet negatief zijn");
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer getBaan werd opgeroepen");
     */

    Baan *getBaan();

    /**
     * REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer setBaan werd opgeroepen");
     */

    void setBaan(Baan *baan2);

    /**
     \n ENSURE(baan2 != NULL,"De baan moet bestaan");
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer getWachttijd werd opgeroepen");
     */

    int getWachttijd();

    /**
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer setWachttijd werd opgeroepen");
     */

    void setWachttijd(int wachttijd);

    /**
     \n ENSURE(wachttijd2 >= 0, "wachttijd kan niet negatief zijn");
     */

};


#endif //VERKEERSSIMULATIE_BUSHALTE_H