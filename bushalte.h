//
// Created by marcel on 21/04/2022.
//

#ifndef VERKEERSSIMULATIE_BUSHALTE_H
#define VERKEERSSIMULATIE_BUSHALTE_H

#include "iostream"

using namespace std;

class Baan;

class Bushalte {
private:
    Bushalte* _initCheck;

    int positie;

    Baan* baan;

    int wachttijd;

public:
    bool properlyInitialized();

    Bushalte();

    int getPositie();

    void setPositie(int positie2);

    Baan * getBaan();

    void setBaan(Baan *baan);

    int getWachttijd();

    void setWachttijd(int wachttijd);

};


#endif //VERKEERSSIMULATIE_BUSHALTE_H
