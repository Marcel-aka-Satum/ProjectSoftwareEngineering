// Implementatie van methodes voor Voertuig classe
// Marceli Wilczynski && Tomas Ghysels
// 18.03.2022
// version 1.0


#include "voertuig.h"
#include "baan.h"
#include <algorithm>
#include <math.h>
#include "DesignByContract.h"


Voertuig::Voertuig() {
    _initCheck = this;
    fLengte = 4;
    fAbs_max_snelheid = 16.6;
    fMax_versnelling = 1.44;
    fMax_remfactor = 4.61;
    fMin_volgafstand = 4;
    fVertraagafstand = 50;
    fStopafstand = 15;
    fVertraagfactor = 0.4;
    afkortingType = "A";
    fSnelheid = fAbs_max_snelheid;
    fVersnelling = 0;
    fVolgafstand = 0;
    fSnelheidsverschil = 0;
    fMax_snelheid = fAbs_max_snelheid;
    fDelta = 0;
    fBaan = new Baan;
    ENSURE(this->properlyInitialized(), "De voertuigconstructor is slecht geinitialiseerd");
}

bool Voertuig::properlyInitialized() {
    return _initCheck == this;
}

Baan *Voertuig::getBaan() {
    REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
    return fBaan;
}

double Voertuig::getPositie(){
    REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
    ENSURE((fPositie >= 0), "Positie is kleiner dan 0");
    return fPositie;
}


void Voertuig::setBaan(Baan *baan) {
    REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
    Voertuig::fBaan = baan;
    ENSURE(baan->properlyInitialized(), "De constructor is slecht geinitialiseerd");
}

void Voertuig::setPositie(int positie) {
    REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
    REQUIRE((positie >= 0), "Positie is kleiner dan 0");
    Voertuig::fPositie = positie;
    ENSURE((positie >= 0), "Positie is kleiner dan 0");
}

double Voertuig::getSnelheid(){
    REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
    REQUIRE((fSnelheid >= 0), "Positie is kleiner dan 0");
    return fSnelheid;
}

double Voertuig::getAbs_max_snelheid(){
    REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
    REQUIRE((fAbs_max_snelheid == 16.6), "De absolute max snelheid != 16.6");
    return fAbs_max_snelheid;
}

//Bereken nieuwe snelheid en positie van voertuig en verwijder uit baan indien nodig
void Voertuig::change_positie() {
    REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
    REQUIRE((fSnelheid >= 0), "De snelheid van jouw Voertuig is < 0");

    double fSimulatietijd = 0.0166;
    if(fSnelheid + (fVersnelling * fSimulatietijd) < 0 ){
        fPositie = fPositie - ((fVersnelling * fVersnelling) / 2 * fVersnelling);
        fSnelheid = 0;

    } else {
        fSnelheid = fSnelheid + (fVersnelling * fSimulatietijd);
        fPositie = fPositie + (fSnelheid * fSimulatietijd) + (fVersnelling * ((fSimulatietijd * fSimulatietijd) / 2));
    }

    if(checkInBaan(*this->getBaan(), this->getBaan()->getVectVoertuigen())){
        verwijderUitBaan(*this->getBaan(), this->getBaan()->getVectVoertuigen());
        return;
    }
    ENSURE((fPositie >= 0 && fPositie <= this->getBaan()->getLengte()),"Positite van jouw voertuig is buiten de baan");
}


void Voertuig::change_versnelling(vector<Voertuig*> &vectVoertuigen){
    REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");

    unsigned int index = this->fIndexVoertuig;
    ENSURE((index >= 0), "De index van jouw voertuig is kleiner dan 0");

    if(index == vectVoertuigen.size()){
        fDelta = 0;
    } else{
        fVolgafstand = vectVoertuigen[index]->getPositie() - vectVoertuigen[index-1]->getPositie() - vectVoertuigen[index]->getFLengte();
        fSnelheidsverschil = vectVoertuigen[index-1]->getSnelheid() - vectVoertuigen[index]->getSnelheid();
        fDelta = vectVoertuigen[index-1]->getFMinVolgafstand() + max(0.0, fSnelheid + (fSnelheid * fSnelheidsverschil) / (2 * (sqrt((fMax_versnelling * fMax_remfactor)))));
        fDelta = fDelta / fVolgafstand;
    }

    fVersnelling = fMax_versnelling * (1 - pow((fSnelheid / fMax_snelheid), 4) - (pow(fDelta, 2)));
    ENSURE((fVolgafstand >= 0), "Volgafstand tussen jouw 2 voertuigen is niet correct");
//    ENSURE((fSnelheidsverschil >= 0), "De snelheidsverschil van jouw voertuig is kleiner dan 0");
}

int Voertuig::getFindexVoertuig(){
    REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
    ENSURE((fIndexVoertuig > 0), "Index van jouw voertuig is niet in de baan");
    return fIndexVoertuig;
}

void Voertuig::setFindexVoertuig(int f) {
    REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
    Voertuig::fIndexVoertuig = f;
    ENSURE((fIndexVoertuig >= 0), "Jouw index van jouw voertuig is niet correct");
}

int Voertuig::getFLengte(){
    REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
    ENSURE(fLengte >= 0, "De lengte van jouw voertuig is niet correct");
    return fLengte;
}

int Voertuig::getFMinVolgafstand(){
    REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
    ENSURE(fMin_volgafstand == 4, "De minimale volgafstand is niet correct");
    return fMin_volgafstand;
}

bool Voertuig::checkInBaan(Baan& b1, vector<Voertuig*> vectVoertuigen){
    REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
    if(this->getPositie() > this->getBaan()->getLengte() || this->getPositie() < 0){
        return true;
    }
    return false;
}

void Voertuig::verwijderUitBaan(Baan& b1, vector<Voertuig*> vectVoertuigen){
    b1.getVectVoertuigen().pop_back();
}

void Voertuig::vertragen() {
    REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
    ENSURE(fMax_snelheid >= 0, "De Max_snelheid van jouw voertuig is niet correct");
    fMax_snelheid = fVertraagfactor * fAbs_max_snelheid;
}

void Voertuig::versnellen() {
    REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
    fMax_snelheid = fAbs_max_snelheid;
}

void Voertuig::stoppen() {
    REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
    fVersnelling = - ((fMax_remfactor * fSnelheid) / fMax_snelheid);
}

double Voertuig::getFMaxRemfactor() {
    REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
    REQUIRE(fMax_remfactor == 4.61,"Max Remfactor is niet correct");
    return fMax_remfactor;
}

const string &Voertuig::getType() {
    REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
    return type;
}

void Voertuig::setType(const string &type2) {
    REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
    Voertuig::type = type2;
    ENSURE(type2 != "","string mag niet leeg zijn");
}

void Voertuig::changeTypeVoertuig() {
    REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
    if(type == "bus"){
        _initCheck = this;
        fLengte = 12;
        fAbs_max_snelheid = 11.4;
        fMax_versnelling = 1.22;
        fMax_remfactor = 4.29;
        fMin_volgafstand = 12;
        fVertraagafstand = 50;
        fStopafstand = 15;
        fVertraagfactor = 0.4;
        afkortingType = "B";
        fSnelheid = fAbs_max_snelheid;
        fVersnelling = 0;
        afkortingType = "B";

    } else if(type == "brandweerwagen"){
        _initCheck = this;
        fLengte = 10;
        fAbs_max_snelheid = 14.6;
        fMax_versnelling = 1.33;
        fMax_remfactor = 4.56;
        fMin_volgafstand = 10;
        fVertraagafstand = 50;
        fStopafstand = 15;
        fVertraagfactor = 0.4;
        afkortingType = "BW";
        fSnelheid = fAbs_max_snelheid;
        fVersnelling = 0;

    } else if(type == "ziekenwagen"){
        _initCheck = this;
        fLengte = 8;
        fAbs_max_snelheid = 15.5;
        fMax_versnelling = 1.44;
        fMax_remfactor = 4.47;
        fMin_volgafstand = 8;
        fVertraagafstand = 50;
        fStopafstand = 15;
        fVertraagfactor = 0.4;
        afkortingType = "Z";
        fSnelheid = fAbs_max_snelheid;
        fVersnelling = 0;

    } else if(type == "politiecombi"){
        _initCheck = this;
        fLengte = 6;
        fAbs_max_snelheid = 17.2;
        fMax_versnelling = 1.55;
        fMax_remfactor = 4.92;
        fMin_volgafstand = 6;
        fVertraagafstand = 50;
        fStopafstand = 15;
        fVertraagfactor = 0.4;
        afkortingType = "P";
        fSnelheid = fAbs_max_snelheid;
        fVersnelling = 0;

    }
}

const string &Voertuig::getAfkortingType(){
    REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
    return afkortingType;
}

void Voertuig::setAfkortingType(const string &afkortingType2) {
    REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
    Voertuig::afkortingType = afkortingType2;
    ENSURE(afkortingType != "", "Een voertuig moet een afkorting hebben");
}
