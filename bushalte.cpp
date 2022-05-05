//
// Created by marcel on 21/04/2022.
//

#include "bushalte.h"
#include "DesignByContract.h"


Bushalte::Bushalte() {
    _initCheck = this;
    ENSURE(this->properlyInitialized(), "Bushalte constructor moet goed geinitialiseerd worden");
}

int Bushalte::getPositie() {
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer getPositie werd opgeroepen");
    return positie;
}

void Bushalte::setPositie(int positie2) {
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer setPositie werd opgeroepen");
    Bushalte::positie = positie2;
    ENSURE(positie2 >= 0,"de positiekan niet negatief zijn");
}

Baan * Bushalte::getBaan() {
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer getBaan werd opgeroepen");
    return baan;
}

void Bushalte::setBaan(Baan *baan2) {
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer setBaan werd opgeroepen");
    Bushalte::baan = baan2;
    ENSURE(baan2 != NULL,"De baan moet bestaan");
}

int Bushalte::getWachttijd() {
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer getWachttijd werd opgeroepen");
    return wachttijd;
}

void Bushalte::setWachttijd(int wachttijd2) {
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer setWachttijd werd opgeroepen");
    Bushalte::wachttijd = wachttijd2;
    ENSURE(wachttijd2 >= 0, "wachttijd kan niet negatief zijn");
}

bool Bushalte::properlyInitialized() {
    return _initCheck == this;
}
