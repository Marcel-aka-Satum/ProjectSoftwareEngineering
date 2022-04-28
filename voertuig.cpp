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

    fSnelheid = fAbs_max_snelheid;
    fVersnelling = 0;     // hoe weten we dit

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


void Voertuig::print() {

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

//Bereken nieuwe snelheid en positie van voertuig
void Voertuig::change_positie(double fSimulatietijd) {
    REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
    REQUIRE((fSnelheid >= 0), "De snelheid van jouw Voertuig is < 0");
    REQUIRE((fVersnelling >= 0 && fVersnelling <= 1.44), "De versnelling van jouw Voertuig is < 0 of > 1.44");

    if(fSnelheid + (fVersnelling * fSimulatietijd) < 0 ){
        fPositie = fPositie - ((fVersnelling * fVersnelling) / 2 * fVersnelling);
        fSnelheid = 0;

    } else {
        fSnelheid = fSnelheid + (fVersnelling * fSimulatietijd);
        fPositie = fPositie + (fSnelheid * fSimulatietijd) + (fVersnelling * ((fSimulatietijd * fSimulatietijd) / 2));
    }

    if(fSnelheid >= fAbs_max_snelheid){
        fSnelheid = fAbs_max_snelheid;
    }
    if(checkInBaan(*this->getBaan(), this->getBaan()->getVectVoertuigen())){
        verwijderUitBaan(*this->getBaan(), this->getBaan()->getVectVoertuigen());
        return;
    }
    ENSURE((fPositie >= 0 && fPositie <= this->getBaan()->getLengte()),"Positite van jouw voertuig is buiten de baan");
    ENSURE((fSnelheid >= 0 && fSnelheid <= fAbs_max_snelheid),"Snelheid van jouw voertuig is ongeldig");
    ENSURE((fVersnelling >= 0 && fVersnelling <= fMax_versnelling), "Versnelling van jouw voertuig is ongeldig");
}


void Voertuig::change_versnelling(vector<Voertuig*> vectVoertuigen){
    REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
    REQUIRE((vectVoertuigen.size() >= 1), "Voertuigen zijn niet op de baan");

    unsigned int index = this->fIndexVoertuig;
    ENSURE((index >= 0), "De index van jouw voertuig is kleiner dan 0");
    if(this->getPositie() == 1){
        return;
    }

    if(index+1 == vectVoertuigen.size()){
        fDelta = 0;
    } else{
        fVolgafstand = vectVoertuigen[index+1]->getPositie() - vectVoertuigen[index]->getPositie() - vectVoertuigen[index + 1]->getFLengte();
        fSnelheidsverschil = vectVoertuigen[index]->getSnelheid() - vectVoertuigen[index + 1]->getSnelheid();
        fDelta = vectVoertuigen[index]->getFMinVolgafstand() + max(0.0, fSnelheid + (fSnelheid * fSnelheidsverschil) / (2 * (sqrt((fMax_versnelling * fMax_remfactor)))));
    }

    fVersnelling = fMax_versnelling * (1 - pow((fSnelheid / fMax_snelheid), 4) - (pow(fDelta, 2)));
    ENSURE((fVolgafstand >= 0), "Volgafstand tussen jouw 2 voertuigen is niet correct");
    ENSURE((fSnelheidsverschil >= 0), "De snelheidsverschil van jouw voertuig is kleiner dan 0");
    ENSURE((fVersnelling >= 0), "De versnelling van jouw voertuig is niet correct");
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

void Voertuig::vertragen(vector<Voertuig*> &vectVoertuigen) {
    REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd"); //TODO:GAAT NIET WERKEN MET VERKEERSLICHTEN FIX LATER
    ENSURE(fMax_snelheid >= 0, "De Max_snelheid van jouw voertuig is niet correct");
    this->fMax_versnelling = fVertraagfactor * fAbs_max_snelheid;
    for(long long unsigned int i = this->getPositie()-1; i > 0; i--){
        vectVoertuigen[i]->fMax_versnelling = fVertraagfactor * fAbs_max_snelheid;
    }
}

void Voertuig::versnellen(vector<Voertuig*> &vectVoertuigen) {
    REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
    ENSURE(this->getBaan()->getVerkeerslichtOpBaan()->getFCurrentKleurState() == "groen", "Het is rood jouw auto mag niet versnellen");
    if(this->getBaan()->getVerkeerslichtOpBaan()->getFCurrentKleurState() == "groen"){
        this->fMax_snelheid = this->fAbs_max_snelheid;
        for(long long unsigned int i = this->getPositie()-1; i > 0; i--){
            vectVoertuigen[i]->fMax_snelheid = vectVoertuigen[i]->fAbs_max_snelheid;
        }
    }
}

void Voertuig::stoppen() {
    REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
    this->fVersnelling = - ((this->fMax_remfactor * this->fSnelheid) / this->fMax_snelheid);
    ENSURE(this->fVersnelling >= 0, "Versnelling van jouw auto is niet correct");
}

double Voertuig::getFMaxRemfactor() {
    REQUIRE(this->properlyInitialized(), "De constructor is slecht geinitialiseerd");
    REQUIRE(fMax_remfactor == 4.61,"Max Remfactor is niet correct");
    return fMax_remfactor;
}

const string &Voertuig::getType() const {
    return type;
}

void Voertuig::setType(const string &type2) {
    Voertuig::type = type2;
}

void Voertuig::changeTypeVoertuig() {
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

        fSnelheid = fAbs_max_snelheid;
        fVersnelling = 0;     // hoe weten we dit

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

        fSnelheid = fAbs_max_snelheid;
        fVersnelling = 0;     // hoe weten we dit

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

        fSnelheid = fAbs_max_snelheid;
        fVersnelling = 0;     // hoe weten we dit

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

        fSnelheid = fAbs_max_snelheid;
        fVersnelling = 0;     // hoe weten we dit

    }
}
