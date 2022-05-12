//
// Created by marcel on 21/04/2022.
//

#ifndef VERKEERSSIMULATIE_KRUISPUNT_H
#define VERKEERSSIMULATIE_KRUISPUNT_H

#include "iostream"
using namespace std;

class Baan;

class Kruispunt {
private:
    int positie;

    Kruispunt* _initCheck;
public:
    Kruispunt();

    int getPositie();

    void setPositie(int positie);

    bool properlyInitialized();
};


#endif //VERKEERSSIMULATIE_KRUISPUNT_H
