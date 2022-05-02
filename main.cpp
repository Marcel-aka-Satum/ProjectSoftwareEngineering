#include <iostream>
#include <string>
#include "xmlexporter.h"

using namespace std;

int main() {

//    maak classes van verkeerslicht/baan/voertuigen om data op te slaan
    Verkeerslicht l1;
    Voertuiggenerator g1;
    vector<Baan*> banen;

    //lees de xml bestand in en geef da classes b1, l1, g1 hun juiste waardes
    startParsing2(banen,l1,g1);
    banen[0]->grafischeImpressie();

    return 0;
}