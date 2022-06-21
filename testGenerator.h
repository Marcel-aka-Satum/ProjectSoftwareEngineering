//
// Created by s0212792 on 21/03/2022.
//

#ifndef VERKEERSSIMULATIE_TESTGENERATOR_H
#define VERKEERSSIMULATIE_TESTGENERATOR_H


#include <gtest/gtest.h>
#include "voertuiggenerator.h"
#include "baan.h"

class testGenerator : public ::testing::Test{

};

TEST_F(testGenerator, checkFrequentie){
    Voertuiggenerator* v1 = new Voertuiggenerator;
    ASSERT_EQ(0, v1->getFrequentie());
}

TEST_F(testGenerator, checkBaan){
    Voertuiggenerator* v1 = new Voertuiggenerator;
    Baan* b1 = new Baan;
    v1->setBaan(b1);
    ASSERT_EQ(0, v1->getBaan()->getLengte());
}



#endif //VERKEERSSIMULATIE_TESTGENERATOR_H
