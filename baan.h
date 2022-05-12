// Prototype van classe Baan
// Marceli Wilczynski && Tomas Ghysels
// 18.03.2022
// version 1.0

#ifndef OEFENINGXML_BAAN_H
#define OEFENINGXML_BAAN_H
#include <iostream>
#include <string>
#include <vector>
#include "fstream"
using namespace std;

class Verkeerslicht;
class Voertuig;
class Bushalte;
class Kruispunt;
class Voertuiggenerator;

class Baan {
private:
    Baan* _initCheck;

    string fNaam;

    int fLengte;

    vector<Verkeerslicht*> fVerkeerslichten;

    int fTijd;

    vector<Kruispunt*> fKruispunten;

    double fSimulatietijd;

    vector<Voertuig*> vectVoertuigen;

    vector <Bushalte*> fBushaltes;

    vector <Voertuiggenerator*> fGeneratoren;

    double fSpawnTime;

public:

    /**
     \n ENSURE(this->properlyInitialized(), "baanconstructor moet goed geinitialiseerd worden");
     */

    bool properlyInitialized();
    Baan();

    /**
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer setNaam werd opgeroepen");
     */

    void setNaam(string a);

    /**
     \n ENSURE(a != "","mag geen lege string zijn");
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer setLengte werd opgeroepen");
     */

    void setLengte(int lengte);

    /**
     \n ENSURE(lengte >= 0 , "lengte moet groter of gelijk zijn aan 0");
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer getNaam werd opgeroepen");
     */

    const string &getNaam();

    /**
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer getLengte werd opgeroepen");
     */

    int getLengte();

    /**
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer getTijd werd opgeroepen");
     */

    int getTijd();

    /**
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer getVectVoertuigen werd opgeroepen");
     */

    vector<Voertuig *> &getVectVoertuigen();

    /**
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer addVector werd opgeroepen");
     */

    void addVector(Voertuig* v1, vector<Voertuig*> &vectVoertuigen2);

    /**
     \n ENSURE(v1 != NULL, "het moet een voertuig zijn");
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer searchVoertuig werd opgeroepen");
     */

    int searchVoertuig(Voertuig* v, Baan b1, vector<Voertuig*> vectVoertuigen2);

    /**
     \n ENSURE(v != NULL, "het moet een voertuig zijn");
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer insertionSort werd opgeroepen");
     \n REQUIRE(!vectVoertuigen2.empty(),"vector van voertuigen mag niet leeg zijn voor sort functie");
     */

    void insertionSort(vector<Voertuig*> &vectVoertuigen2);

    /**
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer getFVerkeerslichten werd opgeroepen");
     */

    vector<Verkeerslicht *> &getFVerkeerslichten();

    /**
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer setTijd werd opgeroepen");
     */

    void setTijd(int tijd);

    /**
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer addVerkeerslicht werd opgeroepen");
     */

    void addVerkeerslicht(Verkeerslicht* v1);

    /**
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer addToKruispunten werd opgeroepen");
     */

    void addToKruispunten(Kruispunt* k1);

    /**
     \n ENSURE(k1 != NULL, "het moet een kruipunt zijn");
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer addToKruispunten werd opgeroepen");
     */

    vector<Kruispunt *> &getFKruispunten();

    /**
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer simpel_uitvoer werd opgeroepen");
     \n REQUIRE(!vectVoertuigen.empty(),"vector van voetuigen mag niet leeg zijn");
     */

    void simpel_uitvoer();

    /**
     \n ENSURE(fSimulatietijd <= 1,"simulatie tijd moet vanaf 1 terug gereset worden.");
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer getFsimulatietijd werd opgeroepen");
     */

    double getFSimulatietijd();

    /**
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer setFSimulatietijd werd opgeroepen");
     */

    void setFSimulatietijd(double fSimulatietijd2);

    /**
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer grafischImpressie werd opgeroepen");
     */

    void grafischeImpressie();

    /**
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer addBushalteToVector werd opgeroepen");
     */

    void addBushalteToVector(Bushalte* b1);

    /**
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer addToGeneratore werd opgeroepen");
     */

    void addToGeneratoren(Voertuiggenerator* generator1);

    /**
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer addToGeneratore werd opgeroepen");
     \n REQUIRE(fGeneratoren.size() > 0,"Er moet tenminstens 1 generator zijn zodat simulatie met voertuiggenerator wordt aangeroepen");
     */

    void simulatieVoertuiggenerator(double &generatorTijd, vector<Voertuig*> &vectVoertuigen2);

    /**
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer addToGeneratore werd opgeroepen");
     */

    double getFSpawnTime();

    /**
     \n REQUIRE(this->properlyInitialized(),"was niet geinitialiseerd wanneer addToGeneratore werd opgeroepen");
     */

    void setFSpawnTime(double fSpawnTime2);

    /**
     \n ENSURE(fSpawnTime >= 0, "De tijd kan niet negatief zijn");
     */



};


#endif //OEFENINGXML_BAAN_H