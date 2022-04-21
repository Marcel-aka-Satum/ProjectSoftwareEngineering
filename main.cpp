#include <iostream>
#include <string>
#include "xmlexporter.h"

using namespace std;

int main() {

//    maak classes van verkeerslicht/baan/voertuigen om data op te slaan
    Verkeerslicht l1;
    Voertuiggenerator g1;
    Bushalte bus1;
    vector<Baan*> banen;

    //lees de xml bestand in en geef da classes b1, l1, g1 hun juiste waardes
    startParsing2(banen,l1,g1, bus1);

    for(long long unsigned int i = 0; i <= banen.size() - 1; i++){
        for(long long unsigned int j = 0; j <= banen[i]->getFKruispunten().size()-1; j++){
            cout << banen[i]->getNaam() << endl;
            cout << banen[i]->getFKruispunten()[j]->getPositie() << endl;
        }
    }

//    int j = 10;
//    b1.insertionSort();
//    while (j > 5) {
//        j--;
//        for (long long unsigned int i = 0; i < b1.getVectVoertuigen().size(); i++) {
//            b1.vectVoertuigen[i]->vertragen(b1.vectVoertuigen);
//            b1.vectVoertuigen[i]->change_positie();
//            b1.vectVoertuigen[i]->change_versnelling(b1.vectVoertuigen);
//            b1.getVectVoertuigen()[i]->setFSimulatietijd(b1.getVectVoertuigen()[i]->getFSimulatietijd() + 0.0166);
//            cout << "Positie: " << b1.getVectVoertuigen()[i]->getPositie() << endl;
//            cout << "Snelheid: " << b1.getVectVoertuigen()[i]->getSnelheid() << endl;
//        }
//        if(b1.getVectVoertuigen().empty()){
//            break;
//        }
//        werkt momenteel niet (verander vector verkeerslichten naar ptr vector)
//        for(long long unsigned int i = 0; i < b1.getFVerkeerslichten().size(); i++){
//            b1.setTijd(simultijd2);
//            b1.getFVerkeerslichten()[i]->simulatieVerkeerslicht();
//            cout << b1.getFVerkeerslichten()[i]->getFCurrentKleurState() << endl;
//        }
//    }

    return 0;
}