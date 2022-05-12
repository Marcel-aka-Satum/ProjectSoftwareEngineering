//
// Created by s0212792 on 21/03/2022.
//

#ifndef VERKEERSSIMULATIE_TESTVOERTUIG_H
#define VERKEERSSIMULATIE_TESTVOERTUIG_H

#include <gtest/gtest.h>
#include "voertuig.h"

class testVoertuig : public ::testing::Test{
private:

public:

};


TEST_F(testVoertuig, testSnelheid){
    Voertuig* v1 = new Voertuig;
    ASSERT_EQ(16.6, v1->getSnelheid());
}

TEST_F(testVoertuig, testMaxSnelheid){
    Voertuig* v1 = new Voertuig;
    ASSERT_EQ(16.6, v1->getAbs_max_snelheid());
}

TEST_F(testVoertuig, testMaxRemfactor){
    Voertuig* v1 = new Voertuig;
    ASSERT_EQ(4.61, v1->getFMaxRemfactor());
}

#endif //VERKEERSSIMULATIE_TESTVOERTUIG_H
