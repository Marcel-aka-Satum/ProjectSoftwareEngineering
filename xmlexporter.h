//
// Created by marcel on 20/03/2022.
//

#ifndef VERKEERSSIMULATIE_XMLEXPORTER_H
#define VERKEERSSIMULATIE_XMLEXPORTER_H

#include "baan.h"
#include "voertuiggenerator.h"
#include "verkeerslicht.h"
#include "tinyxml.h"
#include "voertuig.h"
#include <sstream>


void startParsing2(Baan& b1, Verkeerslicht& l1, Voertuiggenerator& g1){

    // stap 1
    //steek input in doc object
    TiXmlDocument doc;
    if(!doc.LoadFile("voorbeeld.xml")) {
        std::cerr << doc.ErrorDesc() << std::endl;
        return;
    }

    // get de root zodat gij dinges mee kan doen
    TiXmlElement* root = doc.FirstChildElement();
    if(root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
        return;
    }


    bool volgorde = false;
    int gIndex = 0;
    // stap 2
    for(TiXmlElement* e = root->FirstChildElement(); e != NULL; e = e->NextSiblingElement()){

        string elemName = e->Value();
        if(elemName == "BAAN"){
            volgorde = true;
        }
        if(!volgorde){
            break;
        }

        Voertuig* v1 = new Voertuig;
        for(TiXmlElement* k = e->FirstChildElement(); k != NULL; k = k->NextSiblingElement()){
            //stap 2.1
            string elemName2 = k->Value();
            if(elemName == "BAAN" && elemName2 == "naam"){
                string a = k->GetText();
                b1.setNaam(a);
            } else if (elemName == "BAAN" && elemName2 == "lengte"){
                int i;
                istringstream(k->GetText()) >> i;
                b1.setLengte(i);
            } else if (elemName == "VERKEERSLICHT" && elemName2 == "baan"){
                l1.setBaan(&b1);
            } else if (elemName == "VERKEERSLICHT" && elemName2 == "positie"){
                int i;
                istringstream(k->GetText()) >> i;
                l1.setPositie(i);
            } else if (elemName == "VERKEERSLICHT" && elemName2 == "cyclus"){
                int i;
                istringstream(k->GetText()) >> i;
                l1.setCyclus(i);
            } else if (elemName == "VOERTUIG" && elemName2 == "baan"){
                v1->setBaan(&b1);
            } else if (elemName == "VOERTUIG" && elemName2 == "positie"){
                int i;
                istringstream(k->GetText()) >> i;
                v1->setPositie(i);
            } else if (elemName == "VOERTUIGGENERATOR" && elemName2 == "baan"){
                g1.setBaan(&b1);
            } else if(elemName == "VOERTUIGGENERATOR" && elemName2 == "frequentie"){
                int i;
                istringstream(k->GetText()) >> i;
                g1.setFrequentie(i);
            } else{ // 2.1 UITZONDERING!!!
                cout << "Fout bij het inlezen!" << endl;
            }
        }

        if(elemName == "VOERTUIG"){
            gIndex++;
            v1->setFindexVoertuig(gIndex);
            b1.addVector(v1);
        } else if(elemName == "VERKEERSLICHT"){
            b1.addVerkeerslicht(&l1);
        }
    }
    //sluit bestand
    doc.Clear();
}
#endif //VERKEERSSIMULATIE_XMLEXPORTER_H
