#include <iostream>
#include <string>
#include "xmlexporter.h"

using namespace std;

int main() {


//    maak classes van verkeerslicht/baan/voertuigen om data op te slaan
    Baan b1;
    Verkeerslicht l1;
    Voertuiggenerator g1;

    //lees de xml bestand in en geef da classes b1, l1, g1 hun juiste waardes
    startParsing2(b1,l1,g1);
    int j = 10;
    double simultijd2 = 0;
    b1.insertionSort();
    while (j > 5) {
        j--;

        for (long long unsigned int i = 0; i < b1.getVectVoertuigen().size(); i++) {
            b1.getVectVoertuigen()[i]->change_versnelling();
            b1.getVectVoertuigen()[i]->change_positie();
            b1.getVectVoertuigen()[i]->setFSimulatietijd(b1.getVectVoertuigen()[i]->getFSimulatietijd() + 0.0166);
            simultijd2 = b1.getVectVoertuigen()[i]->getFSimulatietijd();
            cout << "Positie: " << b1.getVectVoertuigen()[i]->getPositie() << endl;
            cout << "Snelheid: " << b1.getVectVoertuigen()[i]->getSnelheid() << endl;
        }

        if(b1.getVectVoertuigen().empty()){
            break;
        }

        //werkt momenteel niet (verander vector verkeerslichten naar ptr vector)
//        for(long long unsigned int i = 0; i < b1.getFVerkeerslichten().size(); i++){
//            b1.setTijd(simultijd2);
//            b1.getFVerkeerslichten()[i]->simulatieVerkeerslicht();
//            cout << b1.getFVerkeerslichten()[i]->getFCurrentKleurState() << endl;
//        }

    }
    return 0;
}