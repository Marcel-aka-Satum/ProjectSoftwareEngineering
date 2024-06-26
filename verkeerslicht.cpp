// Implementatie van methodes uit classe Verkeerslicht
// Marceli Wilczynski && Tomas Ghysels
// 18.03.2022
// version 1.0

#include "verkeerslicht.h"
#include "voertuig.h"
#include "DesignByContract.h"


Verkeerslicht::Verkeerslicht(){
    _initCheck = this;
    fCurrentKleurState = "groen";
    fCyclus = 0;
    fPositie = 0;
    ENSURE(this->properlyInitialized(),"verkeerslichtconstructor moet geintitialiseerd worden");
}


void Verkeerslicht::setBaan(Baan *baan) {
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer setBaan werd opgeroepen");
    Verkeerslicht::fBaan = baan;
    ENSURE(baan != NULL,"het moet een baan zijn");
}

void Verkeerslicht::setPositie(int positie2) {
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer setPositie werd opgeroepen");
    Verkeerslicht::fPositie = positie2;
    ENSURE(fPositie >= 0 && fPositie <= fBaan->getLengte(),"positie moet bestaan");
}

void Verkeerslicht::setCyclus(int cyclus) {
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer setCyclus werd opgeroepen");
    Verkeerslicht::fCyclus = cyclus;
    ENSURE(cyclus >= 0,"de cyclus kan groter of gelijk zijn aan 0");
}

Baan *Verkeerslicht::getBaan(){
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer getBaan werd opgeroepen");
    return fBaan;
}

int Verkeerslicht::getPositie(){
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer getPositie werd opgeroepen");
    ENSURE(fPositie >= 0 && fPositie <= this->getBaan()->getLengte(),"positie moet bestaan");
    return fPositie;

}

int Verkeerslicht::getCyclus(){
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer getCyclus werd opgeroepen");
    return fCyclus;
}

void Verkeerslicht::changeState(double fTijd){
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer changeState werd opgeroepen");
    ENSURE(fTijd >= 0,"tijd kan niet negatief");
    if(fTijd > fCyclus){
        if(fCurrentKleurState == "groen"){
            fCurrentKleurState = "rood";
        } else{
            fCurrentKleurState = "groen";
        }
        ENSURE(fCurrentKleurState != "","het moet groen of rood zijn en niet leeg");
    }
}

void Verkeerslicht::actieAuto(vector<Voertuig*>& vectVoertuigen) {
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer whichState werd opgeroepen");
    ENSURE(fCurrentKleurState != "", "het moet groen of rood zijn en niet leeg");
    ENSURE(vectVoertuigen.size() > 0, "vectVoertuigen mag niet leeg zijn");
    if(fCurrentKleurState == "groen"){
        for(long long unsigned int i = 0; i <= vectVoertuigen.size() - 1; i++){
            if(vectVoertuigen[i]->getPositie() < this->fPositie){
                vectVoertuigen[i]->versnellen();
            }
        }
    } else if(fCurrentKleurState == "rood"){
        for(long long unsigned int i = 0; i < vectVoertuigen.size(); i++){
            if(vectVoertuigen[i]->getPositie() < this->fPositie){
                ENSURE(fPositie >= 0 && fPositie <= this->getBaan()->getLengte(),"positie moet bestaan");
                int afstandPaalVoertuig = this->fPositie - vectVoertuigen[i]->getPositie();
                if(vectVoertuigen[i]->getType() == "politiecombi" || vectVoertuigen[i]->getType() == "ziekenwagen" || vectVoertuigen[i]->getType() == "brandweerwagen"){
                    break;
                }
                if(afstandPaalVoertuig > 0){
                    if(afstandPaalVoertuig < 50 && afstandPaalVoertuig > 15){
                        vectVoertuigen[i]->vertragen();
                    } else if(afstandPaalVoertuig < 15 && afstandPaalVoertuig > 0){
                        vectVoertuigen[i]->stoppen();
                    }
                }
            }
        }
    }

}

const string &Verkeerslicht::getFCurrentKleurState(){
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer getFCurrentKleurstate werd opgeroepen");
    return fCurrentKleurState;
}

bool Verkeerslicht::properlyInitialized() {
    return _initCheck == this;
}

void Verkeerslicht::simulatieVerkeer(double fTijd, vector<Voertuig*>& vectVoertuigen) {
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer simulatieverkeer werd opgeroepen");
    this->changeState(fTijd);
    ENSURE(fTijd >= 0,"tijd kan niet negatief zijn");
    ENSURE(!vectVoertuigen.empty(),"vector mag niet leeg zijn");
}


