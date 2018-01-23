#include "SSBStack_temp.h"

void SSBStack_temp(){

    double Luminosity = 36.455;
    string HistName = "";

    setTDRStyle();
    gStyle->SetMarkerSize(1.2);
    gStyle->SetPalette(1);
    gStyle->SetPadLeftMargin(0.15);
    gStyle->SetPadRightMargin(0.05);
    gStyle->SetTitleOffset(1.8,"y");

    TFile* f_test = new TFile(Form("%s/TTTT%s.root",rootpath_sig.c_str(),f_suffix.c_str()));
    f_test->cd("SSBAnalyzer/SSBHist");
    TIter keylist(gDirectory->GetListOfKeys()); 
    TKey *key; 

    while ((key = (TKey*)keylist())) {
        HistName = key->GetName();

        if(HistName.find("num") == std::string::npos && HistName.find("HT") == std::string::npos && HistName.find("MET") == std::string::npos) continue;
        //if(HistName.find("ee") == std::string::npos) continue;
        //if(HistName.find("em") == std::string::npos) continue;
        //if(HistName.find("mm") == std::string::npos) continue;

        MKStack(HistName, Luminosity, false);
        MKStack_ALL(HistName, Luminosity, false);

    }

}
