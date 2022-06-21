//
// Created by marcel on 20/03/2022.
//

#ifndef VERKEERSSIMULATIE_XMLIMPORTER_H
#define VERKEERSSIMULATIE_XMLIMPORTER_H

#include "baan.h"
#include "voertuiggenerator.h"
#include "verkeerslicht.h"
#include "bushalte.h"
#include "tinyxml.h"
#include "voertuig.h"
#include "kruispunt.h"
#include <sstream>

enum SuccessEnum {ImportAborted, PartialImport, Success};

class xmlImporter{
private:

public:
    /*
     * Read an XML description of traffic simulation from inStream and add it to the vector with Baan objects
     * if error occur, report them on errStream
     * Return whether succesful in the errorcode:
     *  - ImportAborted = simulationTraffic is unchanged; reason for abortion is reported on errStream
     *  - PartialImport = Some semantic errors reported on errStream; state is partially imported and board might have changed
     *  - Succes = No importer errors; no errors reported
     *
     * */
    static SuccessEnum startParsing2(const char* inputfilename, vector<Baan*>& banen, ostream& errStream);
};


#endif //VERKEERSSIMULATIE_XMLIMPORTER_H
