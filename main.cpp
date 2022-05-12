#include <iostream>
#include <string>
#include "xmlexporter.h"

using namespace std;

int main() {

    //maak vector van banen die alle data gaat bevatten
    vector<Baan*> banen;
    //lees de xml bestand in en voeg banen in de vector en zijn attributen erbij
    startParsing2(banen);

    //grafische impressie in een OUTPUTverkeer.txt bestand
//    banen[0]->grafischeImpressie();

    //voer simulatie uit tot er geen auto's in de baan zijn
    banen[0]->simpel_uitvoer();

    return 0;
}