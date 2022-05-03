#include <iostream>
#include <string>
#include "xmlexporter.h"

using namespace std;

int main() {

    //maak vector van banen die alle data gaat bevatten
    vector<Baan*> banen;

    //lees de xml bestand in en voeg banen in de vector en zijn attributen erbij
    startParsing2(banen);
    banen[0]->simpel_uitvoer();


    return 0;
}