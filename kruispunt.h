//
// Created by marcel on 21/04/2022.
//

#ifndef VERKEERSSIMULATIE_KRUISPUNT_H
#define VERKEERSSIMULATIE_KRUISPUNT_H

#include "iostream"
using namespace std;

class Baan;

class Kruispunt {
private:
    int positie;

    Kruispunt* _initCheck;
public:

    /**
     \n ENSURE(this->properlyInitialized(), "Kruispunt constructor moet goed geinitialiseerd worden");
     */
    Kruispunt();
    bool properlyInitialized();

    /**
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer getPositie werd opgeroepen");
     */

    int getPositie();

    /**
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer setPositie werd opgeroepen");
     */

    void setPositie(int positie);

    /**
     \n ENSURE(positie2 >= 0,"de positie kan niet negatief zijn");
     */

};


#endif //VERKEERSSIMULATIE_KRUISPUNT_H