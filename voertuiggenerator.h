// Prototype van classe Voertuiggenerator
// Marceli Wilczynski && Tomas Ghysels
// 18.03.2022
// version 1.0

#ifndef OEFENINGXML_VOERTUIGGENERATOR_H
#define OEFENINGXML_VOERTUIGGENERATOR_H
#include <iostream>

using namespace std;

class Baan;

class Voertuiggenerator {

private:
    Voertuiggenerator* _initCheck;
    int fFrequentie;
    Baan* fBaan;


public:
    Voertuiggenerator();

    bool properlyInitialized();

    int getFrequentie();

    void setFrequentie(int frequentie);

    Baan *getBaan();

    void setBaan(Baan *baan);


};


#endif //OEFENINGXML_VOERTUIGGENERATOR_H