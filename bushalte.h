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
    int positie;

    Baan* baan;

    int wachttijd;

public:
    Bushalte();

    int getPositie() const;

    void setPositie(int positie2);

    Baan *getBaan() const;

    void setBaan(Baan *baan);

    int getWachttijd() const;

    void setWachttijd(int wachttijd);

};


#endif //VERKEERSSIMULATIE_BUSHALTE_H
