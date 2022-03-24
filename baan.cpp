// Implementatie van methodes uit classe Baan
// Marceli Wilczynski && Tomas Ghysels
// 18.03.2022
// version 1.0

//
// Created by student on 10.03.22.
//

#include "baan.h"
#include "voertuig.h"
#include "DesignByContract.h"

Baan::Baan(){
    _initCheck = this;
    fTijd = 0;
    fLengte = 0;
    ENSURE(this->properlyInitialized(), "baanconstructor moet goed geinitialiseerd worden");
}


void Baan::setNaam(string a) {
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer setNaam werd opgeroepen");
    Baan::fNaam = a;
    ENSURE(a != "","mag geen lege string zijn");
}

void Baan::setLengte(int lengte) {
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer setLengte werd opgeroepen");
    Baan::fLengte = lengte;
    ENSURE(lengte >= 0 , "lengte moet groter of gelijk zijn aan 0");
}

const string &Baan::getNaam() {
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer getNaam werd opgeroepen");
    return fNaam;
}

int Baan::getLengte(){
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer getLengte werd opgeroepen");
    return fLengte;
}

Verkeerslicht *Baan::getVerkeerslichtOpBaan(){
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer getVerkeerslischOpBaan werd opgeroepen");
    return verkeerslichtOpBaan;
}

int Baan::getTijd(){
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer getTijd werd opgeroepen");
    return fTijd;
}

const vector<Voertuig *> &Baan::getVectVoertuigen(){
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer getVectVoertuigen werd opgeroepen");
    return vectVoertuigen;
}

void Baan::addVector(Voertuig *v1) {
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer addVector werd opgeroepen");
    vectVoertuigen.push_back(v1);
    ENSURE(v1 != NULL, "het moet een voertuig zijn");
}

int Baan::searchVoertuig(Voertuig* v){
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer searchVoertuig werd opgeroepen");

    for(long long unsigned int i = 0; i < vectVoertuigen.size(); i++){
        if(vectVoertuigen[i] == v){
            return i;
        }
    }
    ENSURE(v != NULL, "het moet een voertuig zijn");
    return -1;
}

void Baan::insertionSort(){
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer insertionSort werd opgeroepen");
    int n = vectVoertuigen.size() - 1;
    int key;
    int j;
    for(int i = 1; i <= n; i++){
        key = vectVoertuigen[i]->getPositie();
        j = i - 1;
        while(j >= 0 && vectVoertuigen[j]->getPositie() > key){
            Voertuig* temp = vectVoertuigen[j+1];
            vectVoertuigen[j + 1] = vectVoertuigen[j];
            vectVoertuigen[j] = temp;
            j = j-1;
        }
    }
}

bool Baan::properlyInitialized() {
    return _initCheck == this;
}

const vector<Verkeerslicht *> &Baan::getFVerkeerslichten() const {
    return fVerkeerslichten;
}

void Baan::setTijd(int tijd2) {
    Baan::fTijd = tijd2;
}

void Baan::addVerkeerslicht(Verkeerslicht* v1){
    fVerkeerslichten.push_back(v1);
}
