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
#include "voertuiggenerator.h"

Baan::Baan(){
    _initCheck = this;
    fTijd = 0;
    fLengte = 0;
    fSimulatietijd = 0;
    fSpawnTime = 0;
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
    REQUIRE(!vectVoertuigen2.empty(),"vector van voertuigen mag niet leeg zijn voor sort functie");
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
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer getFVerkeerslichten werd opgeroepen");
    return fVerkeerslichten;
}

void Baan::setTijd(int tijd2) {
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer setTijd werd opgeroepen");
    Baan::fTijd = tijd2;
}

void Baan::addVerkeerslicht(Verkeerslicht* v1){
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer addVerkeerslicht werd opgeroepen");
    fVerkeerslichten.push_back(v1);
}

void Baan::addToKruispunten(Kruispunt *k1) {

    fKruispunten.push_back(k1);
}

vector<Kruispunt *> &Baan::getFKruispunten(){
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer addToKruispunten werd opgeroepen");
    return fKruispunten;
}
/* void Baan:: simpel_uitvoer();
 * Deze functie print in de console huidige staat van elk voertuig op de baan en laat die ook bewegen.
 * */
void Baan:: simpel_uitvoer() {
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer simpel_uitvoer werd opgeroepen");
    REQUIRE(!vectVoertuigen.empty(),"vector van voetuigen mag niet leeg zijn");
    insertionSort(vectVoertuigen);
    while (!vectVoertuigen.empty()) {
        cout << "Tijd: " << fTijd << endl;
        for (long long unsigned int i = 0; i <= vectVoertuigen.size() - 1; i++) {
            cout << "Voertuig " << vectVoertuigen[i]->getFindexVoertuig() << " type: " << vectVoertuigen[i]->getType() << endl;
            cout << "-> baan: " << vectVoertuigen[i]->getBaan()->getNaam() << endl;
            cout << "-> positie: " << vectVoertuigen[i]->getPositie() << endl;
            cout << "-> snelheid: " << vectVoertuigen[i]->getSnelheid() << endl;
            vectVoertuigen[i]->change_positie();
            if(vectVoertuigen.size() == 0){
                return;
            }
            vectVoertuigen[i]->change_versnelling(vectVoertuigen);
            if(fSimulatietijd >= 0.966){
                fSpawnTime += 1;
                fTijd += 1;
                fSimulatietijd = 0;
                if(fVerkeerslichten.size() > 0){
                    for(long long unsigned int k = 0; k <= fVerkeerslichten.size() -1 ;k++){
                        fVerkeerslichten[k]->changeState(fTijd);
                    }
                }
            } else{
                fSimulatietijd += 0.0166;
            }
            if(fVerkeerslichten.size() > 0){
                for(long long unsigned int k = 0; k <= fVerkeerslichten.size() -1 ;k++){
                    cout << "Het is momenteel " << fVerkeerslichten[k]->getFCurrentKleurState() << " voor het verkeerslicht op positie: " << fVerkeerslichten[k]->getPositie() << endl;
                    fVerkeerslichten[k]->actieAuto(vectVoertuigen);
                }
            }
        }
        ENSURE(fSimulatietijd <= 1,"simulatie tijd moet vanaf 1 terug gereset worden.");
    }
}

double Baan::getFSimulatietijd(){
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer getFsimulatietijd werd opgeroepen");
    return fSimulatietijd;
}

void Baan::setFSimulatietijd(double fSimulatietijd2) {
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer setFSimulatietijd werd opgeroepen");
    Baan::fSimulatietijd = fSimulatietijd2;
}

/* void Baan::grafischeImpressie();
 * Functie die een OUTPUTverkeer.txt bestand maakt met huidige posities van voertuigen/verkeerslichten etc.
 * Wiskunde erachter: Deel de lengte van de baan / 10 en zo veel '=' gaan er zijn. Vervolgens kijk of dat er op die positie een voertuig is.
 * */
void Baan::grafischeImpressie() {
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer grafischImpressie werd opgeroepen");
    ofstream new_file("OUTPUTverkeer.txt");
    //BAAN
    new_file << this->getNaam() << "        | ";
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
    if(fVerkeerslichten.size() > 0){
        new_file << " > verkeerslichten    |";
        for(int j = 0; j < this->getLengte() /10; j++){
            int pos = j * 10;
            bool found = false;
            if(fVerkeerslichten.size() > 0){
                for(long long unsigned int i = 0; i <= fVerkeerslichten.size() -1; i++){
                    if(pos == fVerkeerslichten[i]->getPositie()){
                        new_file << "G";
                        found = true;
                        break;
                    }
                }
            }

            if(fBushaltes.size() > 0){
                for(long long unsigned int k = 0; k <= fBushaltes.size()-1; k++){
                    if(pos == fBushaltes[k]->getPositie()){
                        new_file << "|";
                        found = true;
                        break;
                    }
                }
            }

            if(!found){
                new_file << " ";
            }
        }
        new_file << endl;
    }

    // > bushaltes
    if(fBushaltes.size() > 0){
        new_file << " > bushaltes          |";
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
    }

    new_file.close();
}

void Baan::addBushalteToVector(Bushalte *b1) {
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer addBushalteToVector werd opgeroepen");
    fBushaltes.push_back(b1);
}

void Baan::addToGeneratoren(Voertuiggenerator *generator1) {
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer addToGeneratore werd opgeroepen");
    fGeneratoren.push_back(generator1);
}
/* void Baan::simulatieVoertuiggenerator(double &generatorTijd);
 * Voeg autos toe op positie 0 indien er geen autos zijn tussen positie 0 en 2* de lengte van een voertuig
 * 3. FOR elke voertuiggenerator
 * 3.1 IF tijd sinds laatste voertuig > frequentie
 * 3.1.1 IF geen voertuig op baan tussen posities 0 en 2l
 * 3.1.1.1 THEN voeg voertuig toe aan baan op positie 0
 * */
void Baan::simulatieVoertuiggenerator(double &generatorTijd, vector<Voertuig*> &vectVoertuigen2) {
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer addToGeneratore werd opgeroepen");
    REQUIRE(fGeneratoren.size() > 0,"Er moet tenminstens 1 generator zijn zodat simulatie met voertuiggenerator wordt aangeroepen");
    for(long long unsigned int k = 0; k <= fGeneratoren.size() -1; k++){
        if(generatorTijd - fGeneratoren[k]->getFrequentie() == 0){
            generatorTijd = 0;
            string typeGenerator = fGeneratoren[k]->getType();
            Voertuig* v = new Voertuig;
            v->setPositie(0);
            v->setType(typeGenerator);
            v->setFindexVoertuig(vectVoertuigen2.size()+1);
            v->setBaan(this);
            v->changeTypeVoertuig();
            bool found = false; // TRUE indien voertuig tussen positie 0 en 2l
            for(long long unsigned int i = 0; i <= vectVoertuigen2.size()-1; i++){
                if(vectVoertuigen2[i]->getPositie() >= 0 && vectVoertuigen2[i]->getPositie() <= v->getFLengte()){
                    found = true;
                    break;
                }
            }
            if(!found){
                vectVoertuigen2.push_back(v);
            }
        }
    }
}

double Baan::getFSpawnTime(){
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer addToGeneratore werd opgeroepen");
    return fSpawnTime;
}

void Baan::setFSpawnTime(double fSpawnTime2) {
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer addToGeneratore werd opgeroepen");
    Baan::fSpawnTime = fSpawnTime2;
    ENSURE(fSpawnTime >= 0, "De tijd kan niet negatief zijn");
}
/*
 * deze functie wordt gebruikt bij het testen van happyday xml test
 * deze functie voert simulatie uit op alles wat er op de baan zit en laat niks zien in de console zodat de testen duidelijk blijven
 * */
void Baan::simpel_uitvoer_happyday() {
    REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer simpel_uitvoer werd opgeroepen");
    REQUIRE(!vectVoertuigen.empty(),"vector van voetuigen mag niet leeg zijn");
    insertionSort(vectVoertuigen);
    while (!vectVoertuigen.empty()) {
        for (long long unsigned int i = 0; i <= vectVoertuigen.size() - 1; i++) {
            vectVoertuigen[i]->change_positie();
            if(vectVoertuigen.size() == 0){
                return;
            }
            vectVoertuigen[i]->change_versnelling(vectVoertuigen);
            if(fSimulatietijd >= 0.966){
                fSpawnTime += 1;
                fTijd += 1;
                fSimulatietijd = 0;
                if(fVerkeerslichten.size() > 0){
                    for(long long unsigned int k = 0; k <= fVerkeerslichten.size() -1 ;k++){
                        fVerkeerslichten[k]->changeState(fTijd);
                    }
                }
            } else{
                fSimulatietijd += 0.0166;
            }
            if(fVerkeerslichten.size() > 0){
                for(long long unsigned int k = 0; k <= fVerkeerslichten.size() -1 ;k++){
                    fVerkeerslichten[k]->actieAuto(vectVoertuigen);
                }
            }
        }
        ENSURE(fSimulatietijd <= 1,"simulatie tijd moet vanaf 1 terug gereset worden.");
    }
}
