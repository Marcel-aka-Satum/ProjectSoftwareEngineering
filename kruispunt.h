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
public:
    int getPositie() const;

    void setPositie(int positie);
};


#endif //VERKEERSSIMULATIE_KRUISPUNT_H
