//
// Created by marcel on 21/04/2022.
//

#include "bushalte.h"


Bushalte::Bushalte() {}

int Bushalte::getPositie() const {
    return positie;
}

void Bushalte::setPositie(int positie2) {
    Bushalte::positie = positie2;
}

Baan *Bushalte::getBaan() const {
    return baan;
}

void Bushalte::setBaan(Baan *baan2) {
    Bushalte::baan = baan2;
}

int Bushalte::getWachttijd() const {
    return wachttijd;
}

void Bushalte::setWachttijd(int wachttijd2) {
    Bushalte::wachttijd = wachttijd2;
}
