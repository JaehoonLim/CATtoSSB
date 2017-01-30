// SSBHMMaker v1.00

#ifndef SSBHistManager_h
#define SSBHistManager_h 

#include <vector>
#include <iostream>
#include <TROOT.h>
#include "TFile.h"
#include "TTree.h"
#include "TLorentzVector.h"
#include "TMath.h"
#include "TClonesArray.h"
#include "TH1D.h"


class SSBHistManager
{

    typedef std::map<std::string, TClonesArray*>                 map_hist;
    typedef std::map<std::string, TClonesArray*>::iterator       map_hist_it;

    map_hist    HistBox;
    map_hist_it it_HistBox;

public:

    SSBHistManager(std::vector<std::string>);
    ~SSBHistManager();

    void Book(TTree* tree);
    void InitializeHist();

    void FillHist();

    void Fill(std::string, bool);
    void Fill(std::string, int);
    void Fill(std::string, unsigned int);
    void Fill(std::string, float);
    void Fill(std::string, double);

    void GetCutStep(std::map<std::string,bool>,std::map<std::string,bool>,std::map<std::string,bool>);

private:

    TTree* ssbhist;
    std::vector<std::string> ChannelName = {"ee","mm","em"};
    std::vector<std::string> CutStepName;
    std::vector<bool> AllCut;

};

#endif
