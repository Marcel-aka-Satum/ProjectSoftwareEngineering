//
// Created by marcel on 09/05/2022.
//

#ifndef VERKEERSSIMULATIE_TESTBUSHALTE_H
#define VERKEERSSIMULATIE_TESTBUSHALTE_H

#include "bushalte.h"
#include "gtest/gtest.h"
#include "baan.h"

class testBushalte : public ::testing::Test{

};

TEST_F(testBushalte, checkPositie){
    Bushalte* b1 = new Bushalte;
    ASSERT_EQ(0, b1->getPositie());
}

TEST_F(testBushalte, checkWachttijd){
    Bushalte* b1 = new Bushalte;
    ASSERT_EQ(0, b1->getWachttijd());
}

TEST_F(testBushalte, checkBaan){
    Bushalte* b1 = new Bushalte;
    Baan* newBaan = new Baan;
    b1->setBaan(newBaan);

    ASSERT_EQ(newBaan, b1->getBaan());
}

#endif //VERKEERSSIMULATIE_TESTBUSHALTE_H
