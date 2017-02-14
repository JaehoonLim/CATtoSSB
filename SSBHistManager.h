// SSBHMMaker v1.10

#ifndef SSBHistManager_h
#define SSBHistManager_h 

#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include <vector>
#include <map>
#include <iostream>
#include <TROOT.h>
#include "TFile.h"
#include "TDirectory.h"
#include "TMath.h"
#include "TH1D.h"


class SSBHistManager
{

    typedef std::map<std::string, TH1D*>                 map_hist;
    typedef std::map<std::string, TH1D*>::iterator       map_hist_it;

    map_hist    HistBox;
    map_hist_it it_HistBox;

public:

    SSBHistManager(std::vector<std::string>,std::vector<std::string>);
    ~SSBHistManager();

    void Book(TFileDirectory);
    void InitializeHist();

    void FillHist();

    void Fill(std::string, bool, double Weight=1.0);
    void Fill(std::string, int, double Weight=1.0);
    void Fill(std::string, unsigned int, double Weight=1.0);
    void Fill(std::string, float, double Weight=1.0);
    void Fill(std::string, double, double Weight=1.0);

    void GetCutStep(std::string,std::map<std::string,bool>);

private:

    TFileDirectory ssbhist;
    std::vector<std::string> ChannelName;
    std::vector<std::string> CutStepName;
    std::vector<std::string> AllCutName;
    std::map<std::string,bool> AllCut;
    std::string HistName;

};

#endif
