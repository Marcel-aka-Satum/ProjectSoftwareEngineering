//
// Created by marcel on 09/05/2022.
//

#ifndef VERKEERSSIMULATIE_TESTKRUISPUNT_H
#define VERKEERSSIMULATIE_TESTKRUISPUNT_H

#include "kruispunt.h"
#include "gtest/gtest.h"

class testKruispunt : public ::testing::Test{

};

TEST_F(testKruispunt, checkPositie){
    Kruispunt* k1 = new Kruispunt;

    ASSERT_EQ(0, k1->getPositie());
}


#endif //VERKEERSSIMULATIE_TESTKRUISPUNT_H
