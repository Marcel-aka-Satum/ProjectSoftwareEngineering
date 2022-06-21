//
// Created by marcel on 13/05/2022.
//

#ifndef VERKEERSSIMULATIE_TESTOUTPUT_H
#define VERKEERSSIMULATIE_TESTOUTPUT_H

#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <gtest/gtest.h>
#include <sstream>

using namespace std;

#include "baan.h"
#include "kruispunt.h"
#include "voertuig.h"
#include "verkeerslicht.h"
#include "bushalte.h"
#include "simulationUtils.h"
#include "xmlImporter.h"


class testOutput : public ::testing::Test{

};

/*
 * Tests the output of the "happy day" scenario
 * */
TEST_F(testOutput, OutputHappyDay){
    ASSERT_TRUE(DirectoryExists("testOutput"));
    xmlImporter importer;
    vector<Baan*> banen;
    ofstream myFile;
    importer.startParsing2("testInput/happyDayGame.xml", banen, myFile);
    banen[0]->grafischeImpressie();
    EXPECT_TRUE(FileCompare("testOutput/happyDayExpectedOut.txt", "outputVerkeer.txt"));
}

/*
 * Test the compare files
 * */
TEST_F(testOutput, FileCompare){
    ASSERT_TRUE(DirectoryExists("testOutput"));

    ofstream myfile;
    myfile.open("testOutput/file1.txt");
    myfile.close();
    myfile.open("testOutput/file2.txt");
    myfile.close();

    EXPECT_TRUE(FileExists("testOutput/file1.txt"));
    EXPECT_TRUE(FileExists("testOutput/file2.txt"));
    EXPECT_TRUE(FileIsEmpty("testOutput/file1.txt"));
    EXPECT_TRUE(FileIsEmpty("testOutput/file2.txt"));

    //compare 2 empty files
// *** Beware: the following does not work with older versions of libstdc++
// *** It doesn't work with gcc version 4.0.1 (Apple Inc. build 5465)
// *** It does work with gcc version 4.2.1
    EXPECT_TRUE(FileCompare("testOutput/file1.txt", "testOutput/file2.txt"));
    EXPECT_TRUE(FileCompare("testOutput/file2.txt", "testOutput/file1.txt"));

    //compare an empty and a non-empty files
    myfile.open("testOutput/file1.txt");
    myfile << "xxx" << endl << "yyy";
    myfile.close();
    EXPECT_TRUE(FileExists("testOutput/file1.txt"));
    EXPECT_FALSE(FileIsEmpty("testOutput/file1.txt"));
    EXPECT_FALSE(FileCompare("testOutput/file1.txt", "testOutput/file2.txt"));
    EXPECT_FALSE(FileCompare("testOutput/file2.txt", "testOutput/file1.txt"));

    //compare two equal files
    myfile.open("testOutput/file2.txt");
    myfile << "xxx" << endl << "yyy";
    myfile.close();
    EXPECT_TRUE(FileExists("testOutput/file2.txt"));
    EXPECT_FALSE(FileIsEmpty("testOutput/file2.txt"));
    EXPECT_TRUE(FileCompare("testOutput/file1.txt", "testOutput/file2.txt"));
    EXPECT_TRUE(FileCompare("testOutput/file2.txt", "testOutput/file1.txt"));

    //compare 2 non-empty files which are off by a character in the middle
    myfile.open("testOutput/file2.txt");
    myfile << "xxx" << endl << "xyy";
    myfile.close();
    EXPECT_FALSE(FileCompare("testOutput/file1.txt", "testOutput/file2.txt"));
    EXPECT_FALSE(FileCompare("testOutput/file2.txt", "testOutput/file1.txt"));

    //compare 2 non-empty files where one is one character shorter than the other
    myfile.open("testOutput/file2.txt");
    myfile << "xxx" << endl << "yy";
    myfile.close();
    EXPECT_FALSE(FileCompare("testOutput/file1.txt", "testOutput/file2.txt"));
    EXPECT_FALSE(FileCompare("testOutput/file2.txt", "testOutput/file1.txt"));
    //compare existing against non existing file
    EXPECT_FALSE(FileCompare("testOutput/file1.txt", "testOutput/nonexisting.txt"));
    EXPECT_FALSE(FileCompare("testOutput/nonexisting.txt", "testOutput/file1.txt"));

}




#endif //VERKEERSSIMULATIE_TESTOUTPUT_H
