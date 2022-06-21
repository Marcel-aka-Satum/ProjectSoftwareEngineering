#include <iostream>
#include <string>
#include "xmlImporter.h"

using namespace std;

int main() {

    //maak vector van banen die alle data gaat bevatten
    vector<Baan*> banen;
    ofstream myFile;

    //lees de xml bestand in en voeg banen in de vector en zijn attributen erbij
    xmlImporter importer;
    importer.startParsing2("voorbeeld.xml",banen, myFile);

    //grafische impressie in een OUTPUTverkeer.txt bestand
//    banen[0]->grafischeImpressie();

    //voer simulatie uit tot er geen auto's in de baan zijn
//    banen[0]->simpel_uitvoer();

    return 0;
}