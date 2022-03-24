//
// Created by s0212792 on 21/03/2022.
//

#ifndef VERKEERSSIMULATIE_TESTBAAN_H
#define VERKEERSSIMULATIE_TESTBAAN_H

#include <gtest/gtest.h>
#include "baan.h"


class testBaan : public ::testing::Test{

};


TEST_F(testBaan, checkNaam){
    Baan* b1 = new Baan;
    ASSERT_EQ("", b1->getNaam());
}

TEST_F(testBaan, checkLengte){
    Baan* b1 = new Baan;
    ASSERT_EQ(0, b1->getLengte());
}

TEST_F(testBaan, checkTijd){
    Baan* b1 = new Baan;
    ASSERT_EQ(0, b1->getTijd());
}

TEST_F(testBaan, checkSizeVectVoertuigen){
    Baan* b1 = new Baan;
    unsigned int a = 0;
    ASSERT_EQ(a, b1->getVectVoertuigen().size());
}


#endif //VERKEERSSIMULATIE_TESTBAAN_H
