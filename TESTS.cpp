//
// Created by thomg on 3/03/2022.
//

#include "testVoertuig.h"
#include "testBaan.h"
#include "testGenerator.h"
#include "testBushalte.h"
#include "testKruispunt.h"
#include "testInput.h"
#include "testOutput.h"

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


