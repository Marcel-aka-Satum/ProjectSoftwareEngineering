//
// Created by marcel on 20/03/2022.
//

#ifndef VERKEERSSIMULATIE_XMLEXPORTER_H
#define VERKEERSSIMULATIE_XMLEXPORTER_H

#include "baan.h"
#include "voertuiggenerator.h"
#include "verkeerslicht.h"
#include "bushalte.h"
#include "tinyxml.h"
#include "voertuig.h"
#include "kruispunt.h"
#include <sstream>


void startParsing2(vector<Baan*>& banen, Verkeerslicht& l1, Voertuiggenerator& g1, Bushalte& bushalte1){

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
        Baan* b1 = new Baan;

        for(TiXmlElement* k = e->FirstChildElement(); k != NULL; k = k->NextSiblingElement()){
            Kruispunt* k1 = new Kruispunt;
            //stap 2.1
            string elemName2 = k->Value();
            if(elemName == "BAAN" && elemName2 == "naam"){
                string a = k->GetText();
                b1->setNaam(a);
            } else if (elemName == "BAAN" && elemName2 == "lengte"){
                int i;
                istringstream(k->GetText()) >> i;
                b1->setLengte(i);
            } else if (elemName == "VERKEERSLICHT" && elemName2 == "baan"){
                string a = k->GetText();
                for(long long unsigned int i = 0; i <= banen.size() -1; i++){
                    if(banen[i]->getNaam() == a){
                        b1 = banen[i];
                    }
                }
                l1.setBaan(b1);
            } else if (elemName == "VERKEERSLICHT" && elemName2 == "positie"){
                int i;
                istringstream(k->GetText()) >> i;
                l1.setPositie(i);
            } else if (elemName == "VERKEERSLICHT" && elemName2 == "cyclus"){
                int i;
                istringstream(k->GetText()) >> i;
                l1.setCyclus(i);
            } else if (elemName == "VOERTUIG" && elemName2 == "baan"){
                string a = k->GetText();
                for(long long unsigned int i = 0; i <= banen.size() -1; i++){
                    if(banen[i]->getNaam() == a){
                        b1 = banen[i];
                    }
                }
                v1->setBaan(b1);
            } else if (elemName == "VOERTUIG" && elemName2 == "positie"){
                int i;
                istringstream(k->GetText()) >> i;
                v1->setPositie(i);
            } else if(elemName == "VOERTUIG" && elemName2 == "type"){
                string a = k->GetText();
                v1->setType(a);
            } else if (elemName == "VOERTUIGGENERATOR" && elemName2 == "baan"){
                g1.setBaan(b1);
            } else if(elemName == "VOERTUIGGENERATOR" && elemName2 == "frequentie"){
                int i;
                istringstream(k->GetText()) >> i;
                g1.setFrequentie(i);
            } else if(elemName == "VOERTUIGGENERATOR" && elemName2 == "type"){
                string a = k->GetText();
                g1.setType(a);
            } else if(elemName == "BUSHALTE" && elemName2 == "baan"){
                bushalte1.setBaan(b1);
            } else if(elemName == "BUSHALTE" && elemName2 == "positie"){
                int i;
                istringstream(k->GetText()) >> i;
                bushalte1.setPositie(i);
            } else if(elemName == "BUSHALTE" && elemName2 == "wachttijd"){
                int i;
                istringstream(k->GetText()) >> i;
                bushalte1.setWachttijd(i);
            } else if(elemName == "KRUISPUNT" && elemName2 == "baan"){
                for(long long unsigned int i = 0; i <= banen.size()-1; i++){
                    if(banen[i]->getNaam() == k->GetText()){
                       k1->setPositie(k->FirstAttribute()->IntValue());
                       banen[i]->addToKruispunten(k1);
                       break;
                    }
                }
            }else{ // 2.1 UITZONDERING!!!
                cout << "Fout bij het inlezen!" << endl;
            }
        }


        if(elemName == "VOERTUIG"){
            v1->changeTypeVoertuig();
            gIndex++;
            v1->setFindexVoertuig(gIndex);
            for(long long unsigned int i = 0; i <= banen.size() - 1; i++){
                if(banen[i]->getNaam() == v1->getBaan()->getNaam()){
                    banen[i]->addVector(v1, banen[i]->getVectVoertuigen());
                }
            }
        } else if(elemName == "VERKEERSLICHT"){
            b1->addVerkeerslicht(&l1, b1->getFVerkeerslichten());
        } else if(elemName == "BAAN"){
            banen.push_back(b1);
        }
    }
    //sluit bestand
    doc.Clear();
}
#endif //VERKEERSSIMULATIE_XMLEXPORTER_H
