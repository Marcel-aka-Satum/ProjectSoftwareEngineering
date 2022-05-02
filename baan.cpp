// Implementatie van methodes uit classe Baan
// Marceli Wilczynski && Tomas Ghysels
// 18.03.2022
// version 1.0

//
// Created by student on 10.03.22.
//

#include "baan.h"
#include "voertuig.h"
#include "bushalte.h"
#include "DesignByContract.h"

Baan::Baan(){
    _initCheck = this;
    fTijd = 0;
    fLengte = 0;
    fSimulatietijd = 0;
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

vector<Voertuig *> &Baan::getVectVoertuigen(){
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer getVectVoertuigen werd opgeroepen");
    return vectVoertuigen;
}

void Baan::addVector(Voertuig *v1, vector<Voertuig*> &vectVoertuigen2) {
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer addVector werd opgeroepen");
    vectVoertuigen2.push_back(v1);
    ENSURE(v1 != NULL, "het moet een voertuig zijn");
}

int Baan::searchVoertuig(Voertuig* v, Baan b1, vector<Voertuig*> vectVoertuigen2){
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer searchVoertuig werd opgeroepen");

    for(long long unsigned int i = 0; i < vectVoertuigen2.size(); i++){
        if(vectVoertuigen2[i] == v){
            return i;
        }
    }
    ENSURE(v != NULL, "het moet een voertuig zijn");
    return -1;
}

void Baan::insertionSort(vector<Voertuig*> &vectVoertuigen2){
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer insertionSort werd opgeroepen");
    int n = vectVoertuigen2.size() - 1;
    int key;
    int j;
    for(int i = 1; i <= n; i++){
        key = vectVoertuigen2[i]->getPositie();
        j = i - 1;
        while(j >= 0 && vectVoertuigen2[j]->getPositie() > key){
            Voertuig* temp = vectVoertuigen2[j+1];
            vectVoertuigen2[j + 1] = vectVoertuigen2[j];
            vectVoertuigen2[j] = temp;
            j = j-1;
        }
    }
}

bool Baan::properlyInitialized() {
    return _initCheck == this;
}

vector<Verkeerslicht *> &Baan::getFVerkeerslichten(){
    return fVerkeerslichten;
}

void Baan::setTijd(int tijd2) {
    Baan::fTijd = tijd2;
}

void Baan::addVerkeerslicht(Verkeerslicht* v1, vector<Verkeerslicht*> &fVerkeerslichten2){
    fVerkeerslichten2.push_back(v1);
}

void Baan::addToKruispunten(Kruispunt *k1) {
    fKruispunten.push_back(k1);
}

vector<Kruispunt *> &Baan::getFKruispunten(){
    return fKruispunten;
}

void Baan::simpel_uitvoer() {
    insertionSort(vectVoertuigen);
    while (!vectVoertuigen.empty()) {
        cout << "Tijd: " << fTijd << endl;
        for (long long unsigned int i = 0; i <= vectVoertuigen.size() - 1; i++) {
            cout << "Voertuig " << vectVoertuigen[i]->getFindexVoertuig() << " type: " << vectVoertuigen[i]->getType() << endl;
            cout << "-> baan: " << vectVoertuigen[i]->getBaan()->getNaam() << endl;
            cout << "-> positie: " << vectVoertuigen[i]->getPositie() << endl;
            cout << "-> snelheid: " << vectVoertuigen[i]->getSnelheid() << endl;
            vectVoertuigen[i]->change_positie(fSimulatietijd);
            if(vectVoertuigen.size() == 0){
                break;
            }
            if(fSimulatietijd >= 0.966){
                fTijd += 1;
                fSimulatietijd = 0;
            } else{
                fSimulatietijd += 0.0166;
            }
        }
        this->simulatieVerkeerslicht();
    }
}

double Baan::getFSimulatietijd() const {
    return fSimulatietijd;
}

void Baan::setFSimulatietijd(double fSimulatietijd2) {
    Baan::fSimulatietijd = fSimulatietijd2;
}

void Baan::simulatieVerkeerslicht(){
    for(long long unsigned int i = 0; i <= fVerkeerslichten.size() -1 ;i++){
        fVerkeerslichten[i]->changeState(fTijd);
        cout << "kleur: " << fVerkeerslichten[i]->getFCurrentKleurState() << endl;
    }
}

/* void Baan::grafischeImpressie();
 * Wiskunde erachter: Deel de lengte van de baan / 10 en zo veel '=' gaan er zijn. Vervolgens kijk of dat er po die positie een voertuig is.
 * */

void Baan::grafischeImpressie() {
    ofstream new_file("OUTPUTverkeer.txt");
    //BAAN
    new_file << this->getNaam() << "         | ";
    for(int i = 0; i < this->getLengte() / 10; i++){
        int pos = i * 10;
        bool found = false;
        for(long long unsigned int j = 0; j <= vectVoertuigen.size()-1; j++){
            if(pos == vectVoertuigen[j]->getPositie()){
                new_file << vectVoertuigen[j]->getAfkortingType();
                found = true;
                break;
            }
        }
        if(!found){
            new_file << "=";
        }
    }
    new_file << endl;
    // > verkeerslichten
    new_file << " > verkeerslichten     |";
    for(int j = 0; j < this->getLengte() /10; j++){
        int pos = j * 10;
        bool found = false;
        for(long long unsigned int i = 0; i <= fVerkeerslichten.size() -1; i++){
            if(pos == fVerkeerslichten[i]->getPositie()){
                new_file << "G";
                found = true;
                break;
            }
        }

        for(long long unsigned int k = 0; k <= fBushaltes.size()-1; k++){
            if(pos == fBushaltes[k]->getPositie()){
                new_file << "|";
                found = true;
                break;
            }
        }

        if(!found){
            new_file << " ";
        }
    }
    new_file << endl;
    // > bushaltes
    new_file << " > bushaltes           |";
    for(int j = 0; j < this->getLengte() /10; j++){
        int pos = j * 10;
        bool found = false;
        for(long long unsigned int k = 0; k <= fBushaltes.size()-1; k++){
            if(pos == fBushaltes[k]->getPositie()){
                new_file << "B";
                found = true;
                break;
            }
        }
        if(!found){
            new_file << " ";
        }
    }
    new_file.close();
}

void Baan::addBushalteToVector(Bushalte *b1) {
    fBushaltes.push_back(b1);
}
