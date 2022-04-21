// Implementatie van methodes uit classe Voertuiggenerator
// Marceli Wilczynski && Tomas Ghysels
// 18.03.2022
// version 1.0

#include "voertuiggenerator.h"
#include "baan.h"
#include "DesignByContract.h"

Voertuiggenerator::Voertuiggenerator() {
    _initCheck = this;
    fFrequentie = 0;
    ENSURE(this->properlyInitialized(), "voertuiggeneratorconstructor moet goed geinitialiseerd worden");
}

int Voertuiggenerator::getFrequentie(){
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer getFrequentie werd opgeroepen");
    return fFrequentie;
}

void Voertuiggenerator::setFrequentie(int frequentie) {
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer setNaam werd opgeroepen");
    Voertuiggenerator::fFrequentie = frequentie;
    ENSURE(frequentie >= 0,"frequentie moet positief zijn");
}

Baan *Voertuiggenerator::getBaan(){
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer setNaam werd opgeroepen");
    return fBaan;
}

void Voertuiggenerator::setBaan(Baan *baan) {
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer setNaam werd opgeroepen");
    Voertuiggenerator::fBaan = baan;
    ENSURE(baan !=NULL, "het moet een baan zijn");
}

bool Voertuiggenerator::properlyInitialized() {
    return _initCheck == this;
}

const string &Voertuiggenerator::getType() const {
    return type;
}

void Voertuiggenerator::setType(const string &type) {
    Voertuiggenerator::type = type;
}




