//
// Created by marcel on 21/04/2022.
//

#include "kruispunt.h"
#include "DesignByContract.h"

Kruispunt::Kruispunt() {
    _initCheck = this;
    positie = 0;
    ENSURE(this->properlyInitialized(), "Kruispunt constructor moet goed geinitialiseerd worden");
}

int Kruispunt::getPositie() {
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer getPositie werd opgeroepen");
    return positie;
}

void Kruispunt::setPositie(int positie2) {
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer setPositie werd opgeroepen");
    Kruispunt::positie = positie2;
    ENSURE(positie2 >= 0,"de positie kan niet negatief zijn");
}

bool Kruispunt::properlyInitialized() {
    return _initCheck == this;
}
