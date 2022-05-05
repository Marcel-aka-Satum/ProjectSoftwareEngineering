//
// Created by marcel on 21/04/2022.
//

#include "kruispunt.h"

int Kruispunt::getPositie() const {
    return positie;
}

void Kruispunt::setPositie(int positie2) {
    Kruispunt::positie = positie2;
}

bool Kruispunt::properlyInitialized() {
    return _initCheck == this;
}
