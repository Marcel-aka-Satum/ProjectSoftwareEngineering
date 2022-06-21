//
// Created by marcel on 13/05/2022.
//

#include "xmlImporter.h"

SuccessEnum xmlImporter::startParsing2(const char* inputfilename, vector<Baan*>& banen, ostream& errStream){

    SuccessEnum endResult = Success;

    // stap 1
    //steek input in doc object
    TiXmlDocument doc;
    if(!doc.LoadFile(inputfilename)) {
        errStream << "XML IMPORT ABORTED: " << doc.ErrorDesc() << endl;
        return ImportAborted;
    }

    // get de root zodat gij dinges mee kan doen
    TiXmlElement* root = doc.FirstChildElement();
    string rootname = root->Value();
    if(root == NULL || rootname != "ROOT") {
        errStream << "XML PARTIAL IMPORT: EXPECTED <ROOT> ... </ROOT> and got <" << rootname << "> ... </" << rootname << ">." << endl;
        return PartialImport;
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
        Bushalte* bushalte1 = new Bushalte;
        Voertuiggenerator* generator1 = new Voertuiggenerator;
        Verkeerslicht* l1 = new Verkeerslicht;

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
                if(i < 0){
                    errStream << "XML PARTIAL IMPORT: Illegal lengte value" << endl;
                    endResult = PartialImport;
                } else{
                    b1->setLengte(i);
                }
            } else if (elemName == "VERKEERSLICHT" && elemName2 == "baan"){
                string a = k->GetText();
                for(long long unsigned int i = 0; i <= banen.size() -1; i++){
                    if(banen[i]->getNaam() == a){
                        b1 = banen[i];
                        l1->setBaan(b1);
                        break;
                    }
                }
            } else if (elemName == "VERKEERSLICHT" && elemName2 == "positie"){
                int i;
                istringstream(k->GetText()) >> i;
                if(i < 0){
                    errStream << "XML PARTIAL IMPORT: Illegal positie value" << endl;
                    endResult = PartialImport;
                } else{
                    l1->setPositie(i);
                }
            } else if (elemName == "VERKEERSLICHT" && elemName2 == "cyclus"){
                int i;
                istringstream(k->GetText()) >> i;
                if(i < 0){
                    errStream << "XML PARTIAL IMPORT: Illegal cyclus value" << endl;
                    endResult = PartialImport;
                } else{
                    l1->setCyclus(i);
                }
            } else if (elemName == "VOERTUIG" && elemName2 == "baan"){
                string a = k->GetText();
                bool f = false; //bools that checks if VOERTUIG has a baan
                for(long long unsigned int i = 0; i <= banen.size() -1; i++){
                    if(banen[i]->getNaam() == a){
                        b1 = banen[i];
                        f = true;
                    }
                }
                if(f){
                    v1->setBaan(b1);
                } else{
                    errStream << "XML PARTIAL IMPORT: Illegal value of VOERTUIG" << endl;
                }
            } else if (elemName == "VOERTUIG" && elemName2 == "positie"){
                int i;
                istringstream(k->GetText()) >> i;
                if(i < 0 || i > v1->getBaan()->getLengte()){
                    errStream << "XML PARTIAL IMPORT: Illegal positie value"<< endl;
                    endResult = PartialImport;
                } else{
                    v1->setPositie(i);
                }
            } else if(elemName == "VOERTUIG" && elemName2 == "type"){
                string a = k->GetText();
                v1->setType(a);
            } else if (elemName == "VOERTUIGGENERATOR" && elemName2 == "baan"){
                string a = k->GetText();
                for(long long unsigned int i = 0; i <= banen.size() -1; i++){
                    if(banen[i]->getNaam() == a){
                        generator1->setBaan(banen[i]);
                    }
                }
            } else if(elemName == "VOERTUIGGENERATOR" && elemName2 == "frequentie"){
                int i;
                istringstream(k->GetText()) >> i;
                if(i < 0){
                    errStream << "XML PARTIAL IMPORT: Illegal frequentie value" << endl;
                    endResult = PartialImport;
                } else{
                    generator1->setFrequentie(i);
                }
            } else if(elemName == "VOERTUIGGENERATOR" && elemName2 == "type"){
                string a = k->GetText();
                generator1->setType(a);
            } else if(elemName == "BUSHALTE" && elemName2 == "baan"){
                string a = k->GetText();
                for(long long unsigned int i = 0; i <= banen.size() -1; i++){
                    if(banen[i]->getNaam() == a){
                        bushalte1->setBaan(banen[i]);
                    }
                }
            } else if(elemName == "BUSHALTE" && elemName2 == "positie"){
                int i;
                istringstream(k->GetText()) >> i;
                if(i < 0){
                    errStream << "XML PARTIAL IMPORT: Illegal positie value" << endl;
                    endResult = PartialImport;
                } else{
                    bushalte1->setPositie(i);
                }
            } else if(elemName == "BUSHALTE" && elemName2 == "wachttijd"){
                int i;
                istringstream(k->GetText()) >> i;
                if(i < 0){
                    errStream << "XML PARTIAL IMPORT: Illegal wachttijd value" << endl;
                    endResult = PartialImport;
                } else{
                    bushalte1->setWachttijd(i);
                }
            } else if(elemName == "KRUISPUNT" && elemName2 == "baan"){
                for(long long unsigned int i = 0; i <= banen.size()-1; i++){
                    if(banen[i]->getNaam() == k->GetText()){
                        k1->setPositie(k->FirstAttribute()->IntValue());
                        banen[i]->addToKruispunten(k1);
                        break;
                    }
                }
            }else{ // 2.1 UITZONDERING!!!
                errStream << "XML IMPORT ABORTED: Error reading opening tag." << endl;
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
            for(long long unsigned int i = 0; i <= banen.size() - 1; i++){
                if(banen[i]->getNaam() == l1->getBaan()->getNaam()){
                    banen[i]->addVerkeerslicht(l1);
                }
            }
        } else if(elemName == "BAAN"){
            banen.push_back(b1);
        } else if(elemName == "BUSHALTE"){
            for(long long unsigned int i = 0; i <= banen.size() -1 ;i++){
                if(banen[i]->getNaam() == bushalte1->getBaan()->getNaam()){
                    banen[i]->addBushalteToVector(bushalte1);
                }
            }
        } else if(elemName == "VOERTUIGGENERATOR"){
            for(long long unsigned int i = 0; i <= banen.size() -1 ;i++){
                if(banen[i]->getNaam() == generator1->getBaan()->getNaam()){
                    banen[i]->addToGeneratoren(generator1);
                }
            }
        }
    }
    //sluit bestand
    doc.Clear();
    return endResult;
}