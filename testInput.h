//
// Created by marcel on 13/05/2022.
//

#ifndef VERKEERSSIMULATIE_TESTINPUT_H
#define VERKEERSSIMULATIE_TESTINPUT_H


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

//used to convert int to string in c++98
#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

class testInput : public ::testing::Test{

};


/*
 * Test happydaygame
 * */
TEST_F(testInput, InputHappyDay){
    ofstream myfile;
    SuccessEnum importResult;
    vector<Baan*> banen;
    xmlImporter in;

    myfile.open("testInput/zzzInput.xml");
    myfile << "<ROOT>" << endl;
    myfile << "<BAAN>" << endl;
    myfile << "<naam>Middelheimlaan</naam>" << endl;
    myfile << "<lengte>500</lengte>" << endl;
    myfile << "</BAAN>" << endl;
    myfile << endl;
    myfile << "<VOERTUIG>" << endl;
    myfile << "<baan>Middelheimlaan</baan>" << endl;
    myfile << "<positie>60</positie>" << endl;
    myfile << "<type>auto</type>" << endl;
    myfile << "</VOERTUIG>" << endl;
    myfile << "</ROOT>" << endl;
    myfile.close();
    myfile.open("testInput/zzzError.txt");
    importResult = in.startParsing2("testInput/happyDayGame.xml", banen, myfile);
    myfile.close();
    EXPECT_TRUE(importResult == Success);
    banen[0]->simpel_uitvoer_happyday();
    EXPECT_TRUE(banen[0]->getVectVoertuigen().empty());
}


/*
 * Test illegalSimulations
 * */
TEST_F(testInput, illegalSimulations){
    ASSERT_TRUE(DirectoryExists("testInput"));

    ofstream myfile;
    SuccessEnum importResult;
    int fileCounter = 1;
    vector<Baan*> banen;
    xmlImporter in;
    //convert int to string in c++98 using #define SSTR
    string s = SSTR(fileCounter);
    string fileName = "testInput/illegalSimulation" + s + ".xml";
    string errorfileName;

    while(FileExists(fileName)){
        myfile.open("testInput/zzzError.txt");
        importResult = in.startParsing2(fileName.c_str(), banen, myfile);
        myfile.close();
        EXPECT_TRUE(importResult == PartialImport);
        errorfileName = "testInput/illegalSimulation" + s + ".txt";
        EXPECT_TRUE(FileCompare("testInput/zzzError.txt", errorfileName));
        fileCounter++;
        s = SSTR(fileCounter);
        fileName = "testInput/illegalSimulation" + s + ".xml";
    }
    EXPECT_TRUE(fileCounter == 5);
}

/*
 * Test illegal xml syntaxes
 * */
TEST_F(testInput, testXmlSyntaxes){
    ASSERT_TRUE(DirectoryExists("testInput"));

    ofstream myfile;
    SuccessEnum importResult;
    int fileCounter = 1;
    vector<Baan*> banen;
    xmlImporter in;
    //convert int to string in c++98 using #define SSTR
    string s = SSTR(fileCounter);
    string fileName = "testInput/xmlsyntaxerror" + s + ".xml";
    string errorfileName;

    while(FileExists(fileName)){
        myfile.open("testInput/zzzError.txt");
        importResult = in.startParsing2(fileName.c_str(), banen, myfile);
        myfile.close();
        EXPECT_TRUE(importResult == ImportAborted);
        errorfileName = "testInput/xmlsyntaxerror" + s + ".txt";
        EXPECT_TRUE(FileCompare("testInput/zzzError.txt", errorfileName));
        fileCounter++;
        s = SSTR(fileCounter);
        fileName = "testInput/xmlsyntaxerror" + s + ".xml";
    }

    EXPECT_TRUE(fileCounter == 11);
}



#endif //VERKEERSSIMULATIE_TESTINPUT_H
