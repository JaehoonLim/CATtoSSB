#include "SSBStack_temp.h"

void SSBStack_temp(){

    string rootpath = "Output/170901/SUSY";
    string f_suffix = "_SUSY";
    double Luminosity = 36.455;
    string HistName = "";
    string HistTitle = "";

    double SigMin,DataMax;
    setTDRStyle();
    gStyle->SetMarkerSize(1.2);
    gStyle->SetPalette(1);
    gStyle->SetPadLeftMargin(0.15);
    gStyle->SetPadRightMargin(0.05);
    gStyle->SetTitleOffset(1.8,"y");

    TCanvas* c_test = new TCanvas("c_test","c_test",1000,800);
    TPad *pad1 = new TPad("pad1","histos",0.0,0.3,0.8,1.0);
    pad1->SetBottomMargin(0.0);
    TPad *pad2 = new TPad("pad2","ratio",0.0,0.0,0.8,0.3);
    pad2->SetTopMargin(0.0);
    pad2->SetBottomMargin(0.35);
    TPad *pad3 = new TPad("pad3","legend",0.8,0.0,1.0,1.0);
    pad1->Draw();
    pad2->Draw();
    pad3->Draw();

    // data
    TFile* f_DoubleEG_Run2016 = new TFile(Form("%s/DoubleEG_Run2016%s.root",rootpath.c_str(),f_suffix.c_str()));
    TFile* f_DoubleMuon_Run2016 = new TFile(Form("%s/DoubleMuon_Run2016%s.root",rootpath.c_str(),f_suffix.c_str()));
    TFile* f_MuonEG_Run2016 = new TFile(Form("%s/MuonEG_Run2016%s.root",rootpath.c_str(),f_suffix.c_str()));

    // TTTT
    TFile* f_TTTT_Signal = new TFile(Form("%s/TTTT%s.root",rootpath.c_str(),f_suffix.c_str()));
    TFile* f_TTTT_Others = new TFile(Form("%s/TTTT_Others%s.root",rootpath.c_str(),f_suffix.c_str()));

    // TT + X
    TFile* f_TT = new TFile(Form("%s/TT%s.root",rootpath.c_str(),f_suffix.c_str()));
    //TFile* f_ttW = new TFile(Form("%s/ttW%s.root",rootpath.c_str(),f_suffix.c_str()));
    TFile* f_ttW = new TFile(Form("%s/ttWToLNu%s.root",rootpath.c_str(),f_suffix.c_str()));
    //TFile* f_ttZ = new TFile(Form("%s/ttZ%s.root",rootpath.c_str(),f_suffix.c_str()));
    TFile* f_ttZ_1to10 = new TFile(Form("%s/ttZToLL_M-1to10%s.root",rootpath.c_str(),f_suffix.c_str()));
    TFile* f_ttZ_10 = new TFile(Form("%s/ttZToLLNuNu_M-10%s.root",rootpath.c_str(),f_suffix.c_str()));
    //TFile* f_ttH_bb = new TFile(Form("%s/ttH_bb%s.root",rootpath.c_str(),f_suffix.c_str()));
    TFile* f_ttH_nonbb = new TFile(Form("%s/ttH_nonbb%s.root",rootpath.c_str(),f_suffix.c_str()));
    //TFile* f_ttbb = new TFile(Form("%s/ttbb%s.root",rootpath.c_str(),f_suffix.c_str()));
    TFile* f_ttG_dl = new TFile(Form("%s/ttGamma_Dilept%s.root",rootpath.c_str(),f_suffix.c_str()));
    TFile* f_ttG_slt = new TFile(Form("%s/ttGamma_SingleLeptFromT%s.root",rootpath.c_str(),f_suffix.c_str()));
    TFile* f_ttG_sltbar = new TFile(Form("%s/ttGamma_SingleLeptFromTbar%s.root",rootpath.c_str(),f_suffix.c_str()));

    // TT + XX
    TFile* f_ttWW = new TFile(Form("%s/ttWW%s.root",rootpath.c_str(),f_suffix.c_str()));
    TFile* f_ttWZ = new TFile(Form("%s/ttWZ%s.root",rootpath.c_str(),f_suffix.c_str()));
    TFile* f_ttWH = new TFile(Form("%s/ttWH%s.root",rootpath.c_str(),f_suffix.c_str()));
    TFile* f_ttZZ = new TFile(Form("%s/ttZZ%s.root",rootpath.c_str(),f_suffix.c_str()));
    TFile* f_ttZH = new TFile(Form("%s/ttZH%s.root",rootpath.c_str(),f_suffix.c_str()));
    TFile* f_ttHH = new TFile(Form("%s/ttHH%s.root",rootpath.c_str(),f_suffix.c_str()));

    // T + X
    //TFile* f_SingleTop_s = new TFile(Form("%s/SingleTop_s%s.root",rootpath.c_str(),f_suffix.c_str()));
    //TFile* f_SingleTop_t = new TFile(Form("%s/SingleTop_t%s.root",rootpath.c_str(),f_suffix.c_str()));
    //TFile* f_SingleTbar_t = new TFile(Form("%s/SingleTbar_t%s.root",rootpath.c_str(),f_suffix.c_str()));
    TFile* f_SingleTop_tW = new TFile(Form("%s/SingleTop_tW%s.root",rootpath.c_str(),f_suffix.c_str()));
    TFile* f_SingleTbar_tW = new TFile(Form("%s/SingleTbar_tW%s.root",rootpath.c_str(),f_suffix.c_str()));
    TFile* f_TG = new TFile(Form("%s/TGJets%s.root",rootpath.c_str(),f_suffix.c_str()));
    TFile* f_tZq = new TFile(Form("%s/tZq_ll_4f%s.root",rootpath.c_str(),f_suffix.c_str()));

    // TTT + X
    TFile* f_tttW = new TFile(Form("%s/tttW%s.root",rootpath.c_str(),f_suffix.c_str()));
    TFile* f_tttJ = new TFile(Form("%s/tttJ%s.root",rootpath.c_str(),f_suffix.c_str()));

    // Boson + X
    TFile* f_DYJets = new TFile(Form("%s/DYJets_MG_ext1%s.root",rootpath.c_str(),f_suffix.c_str()));
    //TFile* f_DYJets = new TFile(Form("%s/DYJets_MG%s.root",rootpath.c_str(),f_suffix.c_str()));
    TFile* f_DYJets_10to50 = new TFile(Form("%s/DYJets_MG_10to50%s.root",rootpath.c_str(),f_suffix.c_str()));
    //TFile* f_WJets = new TFile(Form("%s/WJets%s.root",rootpath.c_str(),f_suffix.c_str()));
    TFile* f_WJets = new TFile(Form("%s/WJets_MG%s.root",rootpath.c_str(),f_suffix.c_str()));
    TFile* f_WGtoLNuG = new TFile(Form("%s/WGtoLNuG%s.root",rootpath.c_str(),f_suffix.c_str()));
    TFile* f_ZGto2LG = new TFile(Form("%s/ZGto2LG%s.root",rootpath.c_str(),f_suffix.c_str()));

    // Di-Boson + X
    //TFile* f_WW = new TFile(Form("%s/WW%s.root",rootpath.c_str(),f_suffix.c_str()));
    TFile* f_WW = new TFile(Form("%s/WWTo2L2Nu%s.root",rootpath.c_str(),f_suffix.c_str()));
    TFile* f_WWG = new TFile(Form("%s/WWG%s.root",rootpath.c_str(),f_suffix.c_str()));
    //TFile* f_WZ = new TFile(Form("%s/WZ%s.root",rootpath.c_str(),f_suffix.c_str()));
    TFile* f_WZ = new TFile(Form("%s/WZTo3LNu%s.root",rootpath.c_str(),f_suffix.c_str()));
    TFile* f_WZG = new TFile(Form("%s/WZG%s.root",rootpath.c_str(),f_suffix.c_str()));
    //TFile* f_ZZ = new TFile(Form("%s/ZZ%s.root",rootpath.c_str(),f_suffix.c_str()));
    TFile* f_ZZ = new TFile(Form("%s/ZZTo4L%s.root",rootpath.c_str(),f_suffix.c_str()));
    TFile* f_WpWpQCD = new TFile(Form("%s/WpWpQCD%s.root",rootpath.c_str(),f_suffix.c_str()));
    TFile* f_WpWpEWK = new TFile(Form("%s/WpWpEWK%s.root",rootpath.c_str(),f_suffix.c_str()));

    // Tri-Boson + X
    TFile* f_WWW = new TFile(Form("%s/WWW%s.root",rootpath.c_str(),f_suffix.c_str()));
    TFile* f_WWZ = new TFile(Form("%s/WWZ%s.root",rootpath.c_str(),f_suffix.c_str()));
    TFile* f_WZZ = new TFile(Form("%s/WZZ%s.root",rootpath.c_str(),f_suffix.c_str()));
    TFile* f_ZZZ = new TFile(Form("%s/ZZZ%s.root",rootpath.c_str(),f_suffix.c_str()));

    // Higgs related
    TFile* f_GluGluH = new TFile(Form("%s/GluGluHToZZTo4L%s.root",rootpath.c_str(),f_suffix.c_str()));
    TFile* f_VHToNonbb = new TFile(Form("%s/VHToNonbb%s.root",rootpath.c_str(),f_suffix.c_str()));
    //TFile* f_ = new TFile(Form("%s/.root",rootpath.c_str(),f_suffix.c_str()));

    TFile* f_test = new TFile(Form("%s/TTTT%s.root",rootpath.c_str(),f_suffix.c_str()));
    f_test->cd("SSBAnalyzer/SSBHist");
    TIter keylist(gDirectory->GetListOfKeys()); 
    TKey *key; 

    while ((key = (TKey*)keylist())) {
        THStack* h_stack = new THStack("h_stack","h_stack");
        HistName = key->GetName();

        if(HistName.find("num") == std::string::npos && HistName.find("HT") == std::string::npos && HistName.find("MET") == std::string::npos) continue;

        HistTitle = HistName;
        TLegend *legend1 = new TLegend(0.0,0.1,0.9,0.95);
        legend1->SetNColumns(2);
        legend1->SetFillColor(0);
        legend1->SetTextSize(0.05);

        TH1D* h_data;
        if(HistName.find("ee") != string::npos){h_data = GetHist(f_DoubleEG_Run2016,HistName,1,1,true); HistTitle.replace(HistTitle.find("_ee_"),4,"  (ee : CutStep "); Luminosity = 36.454;}
        else if(HistName.find("mm") != string::npos){h_data = GetHist(f_DoubleMuon_Run2016,HistName,1,1,true); HistTitle.replace(HistTitle.find("_mm_"),4,"  (#mu#mu : CutStep ");}
        else if(HistName.find("em") != string::npos){h_data = GetHist(f_MuonEG_Run2016,HistName,1,1,true); HistTitle.replace(HistTitle.find("_em_"),4,"  (e#mu : CutStep ");}
        else {cout << "ERROR" << endl; exit(0);}
        HistTitle += ")";
        h_data->SetMarkerStyle(20);
        h_data->SetLineWidth(3);
        DataMax = h_data->GetMaximum();

        TH1D* h_sig = GetHist(f_TTTT_Signal,HistName,0.009201,Luminosity);
        h_sig->SetFillColor(kRed);
        h_stack->Add(h_sig);
        SigMin = h_sig->GetMaximum();

        TH1D* h_ttttbg = GetHist(f_TTTT_Others,HistName,0.009201,Luminosity);
        h_ttttbg->SetFillColor(kRed+2);
        h_stack->Add(h_ttttbg);
        legend1->AddEntry(h_ttttbg, "FourTops Others", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_ttttbg->Integral()),"");

        TH1D* h_ttbg = GetHist(f_TT,HistName,831.76,Luminosity);
        h_ttbg->SetFillColor(kMagenta);
        h_stack->Add(h_ttbg);
        legend1->AddEntry(h_ttbg, "TTbar", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_ttbg->Integral()),"");

        //TH1D* h_ttW = GetHist(f_ttW,HistName,0.61,Luminosity);
        TH1D* h_ttW = GetHist(f_ttW,HistName,0.2043,Luminosity);
        h_ttW->SetFillColor(kMagenta);
        h_stack->Add(h_ttW);
        legend1->AddEntry(h_ttW, "TTbar+W (W->l#nu)", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_ttW->Integral()),"");

        TH1D* h_ttZ_1to10 = GetHist(f_ttZ_1to10,HistName,0.0493,Luminosity);
        h_ttZ_1to10->SetFillColor(kMagenta);
        h_stack->Add(h_ttZ_1to10);
        legend1->AddEntry(h_ttZ_1to10, "TTbar+Z (Z->ll, M1to10)", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_ttZ_1to10->Integral()),"");

        TH1D* h_ttZ_10 = GetHist(f_ttZ_10,HistName,0.2529,Luminosity);
        h_ttZ_10->SetFillColor(kMagenta);
        h_stack->Add(h_ttZ_10);
        legend1->AddEntry(h_ttZ_10, "TTbar+Z (Z->ll, M10)", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_ttZ_10->Integral()),"");
/*
        TH1D* h_ttZ = GetHist(f_ttZ,HistName,0.78,Luminosity);
        h_ttZ->SetFillColor(kMagenta);
        h_stack->Add(h_ttZ);
        legend1->AddEntry(h_ttZ, "TTbar+Z", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_ttZ->Integral()),"");
*/
/*
        TH1D* h_ttH_bb = GetHist(f_ttH_bb,HistName,0.29,Luminosity);
        h_ttH_bb->SetFillColor(kMagenta);
        h_stack->Add(h_ttH_bb);
        legend1->AddEntry(h_ttH_bb, "TTbar+H (H->bb)", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_ttH_bb->Integral()),"");
*/
        TH1D* h_ttH_nonbb = GetHist(f_ttH_nonbb,HistName,0.22,Luminosity);
        h_ttH_nonbb->SetFillColor(kMagenta);
        h_stack->Add(h_ttH_nonbb);
        legend1->AddEntry(h_ttH_nonbb, "TTbar+H (H->nonbb)", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_ttH_nonbb->Integral()),"");
/*
        TH1D* h_ttbb = GetHist(f_ttbb,HistName,13.93,Luminosity);
        h_ttbb->SetFillColor(kMagenta);
        h_stack->Add(h_ttbb);
        legend1->AddEntry(h_ttbb, "TTbar+bb", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_ttbb->Integral()),"");
*/
        TH1D* h_ttG_slt = GetHist(f_ttG_slt,HistName,0.7700,Luminosity);
        h_ttG_slt->SetFillColor(kMagenta);
        h_stack->Add(h_ttG_slt);
        legend1->AddEntry(h_ttG_slt, "TTbar+#gamma (T->LNu)", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_ttG_slt->Integral()),"");

        TH1D* h_ttG_sltbar = GetHist(f_ttG_sltbar,HistName,0.7690,Luminosity);
        h_ttG_sltbar->SetFillColor(kMagenta);
        h_stack->Add(h_ttG_sltbar);
        legend1->AddEntry(h_ttG_sltbar, "TTbar+#gamma (Tbar->LNu)", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_ttG_sltbar->Integral()),"");

        TH1D* h_ttG_dl = GetHist(f_ttG_dl,HistName,0.6320,Luminosity);
        h_ttG_dl->SetFillColor(kMagenta);
        h_stack->Add(h_ttG_dl);
        legend1->AddEntry(h_ttG_dl, "TTbar+#gamma (Di-Lepton)", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_ttG_dl->Integral()),"");

        legend1->AddEntry((TObject*)0,"TopPair + X","");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_ttbg->Integral()+h_ttW->Integral()+h_ttZ_1to10->Integral()+h_ttZ_10->Integral()+h_ttH_nonbb->Integral()+h_ttG_dl->Integral()+h_ttG_slt->Integral()+h_ttG_sltbar->Integral()),"");

        TH1D* h_ttWW = GetHist(f_ttWW,HistName,0.0115,Luminosity);
        h_ttWW->SetFillColor(kMagenta+3);
        h_stack->Add(h_ttWW);
        legend1->AddEntry(h_ttWW, "TTbar+WW", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_ttWW->Integral()),"");

        TH1D* h_ttWZ = GetHist(f_ttWZ,HistName,0.0039,Luminosity);
        h_ttWZ->SetFillColor(kMagenta+3);
        h_stack->Add(h_ttWZ);
        legend1->AddEntry(h_ttWZ, "TTbar+WZ", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_ttWZ->Integral()),"");

        TH1D* h_ttWH = GetHist(f_ttWH,HistName,0.0016,Luminosity);
        h_ttWH->SetFillColor(kMagenta+3);
        h_stack->Add(h_ttWH);
        legend1->AddEntry(h_ttWH, "TTbar+WH", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_ttWH->Integral()),"");

        TH1D* h_ttZZ = GetHist(f_ttZZ,HistName,0.0020,Luminosity);
        h_ttZZ->SetFillColor(kMagenta+3);
        h_stack->Add(h_ttZZ);
        legend1->AddEntry(h_ttZZ, "TTbar+ZZ", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_ttZZ->Integral()),"");

        TH1D* h_ttZH = GetHist(f_ttZH,HistName,0.0015,Luminosity);
        h_ttZH->SetFillColor(kMagenta+3);
        h_stack->Add(h_ttZH);
        legend1->AddEntry(h_ttZH, "TTbar+ZH", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_ttZH->Integral()),"");

        TH1D* h_ttHH = GetHist(f_ttHH,HistName,0.0008,Luminosity);
        h_ttHH->SetFillColor(kMagenta+3);
        h_stack->Add(h_ttHH);
        legend1->AddEntry(h_ttHH, "TTbar+HH", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_ttHH->Integral()),"");

        legend1->AddEntry((TObject*)0,"TopPair + XX","");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_ttWW->Integral()+h_ttWZ->Integral()+h_ttWH->Integral()+h_ttZZ->Integral()+h_ttZH->Integral()+h_ttHH->Integral()),"");

/*
        TH1D* h_SingleTop_s = GetHist(f_SingleTop_s,HistName,3.36,Luminosity);
        h_SingleTop_s->SetFillColor(kBlue);
        h_stack->Add(h_SingleTop_s);
        legend1->AddEntry(h_SingleTop_s, "s-channel T (leptonic)", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_SingleTop_s->Integral()),"");

        TH1D* h_SingleTop_t = GetHist(f_SingleTop_t,HistName,44.3,Luminosity);
        h_SingleTop_t->SetFillColor(kBlue);
        h_stack->Add(h_SingleTop_t);
        legend1->AddEntry(h_SingleTop_t, "t-channel T (leptonic)", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_SingleTop_t->Integral()),"");

        TH1D* h_SingleTbar_t = GetHist(f_SingleTbar_t,HistName,26.4,Luminosity);
        h_SingleTbar_t->SetFillColor(kBlue);
        h_stack->Add(h_SingleTbar_t);
        legend1->AddEntry(h_SingleTbar_t, "t-channel Tbar (leptonic)", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_SingleTbar_t->Integral()),"");
*/
        TH1D* h_SingleTop_tW = GetHist(f_SingleTop_tW,HistName,35.85,Luminosity);
        h_SingleTop_tW->SetFillColor(kBlue);
        h_stack->Add(h_SingleTop_tW);
        legend1->AddEntry(h_SingleTop_tW, "t-channel T+W", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_SingleTop_tW->Integral()),"");

        TH1D* h_SingleTbar_tW = GetHist(f_SingleTbar_tW,HistName,35.85,Luminosity);
        h_SingleTbar_tW->SetFillColor(kBlue);
        h_stack->Add(h_SingleTbar_tW);
        legend1->AddEntry(h_SingleTbar_tW, "t-channel Tbar+W", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_SingleTbar_tW->Integral()),"");

        TH1D* h_TG = GetHist(f_TG,HistName,2.967,Luminosity);
        h_TG->SetFillColor(kBlue);
        h_stack->Add(h_TG);
        legend1->AddEntry(h_TG, "T+#gamma", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_TG->Integral()),"");

        TH1D* h_tZq = GetHist(f_tZq,HistName,0.0758,Luminosity);
        h_tZq->SetFillColor(kBlue);
        h_stack->Add(h_tZq);
        legend1->AddEntry(h_tZq, "TZq", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_tZq->Integral()),"");

        legend1->AddEntry((TObject*)0,"SingleTop related","");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_SingleTop_tW->Integral()+h_SingleTbar_tW->Integral()+h_TG->Integral()+h_tZq->Integral()),"");

        TH1D* h_tttW = GetHist(f_tttW,HistName,0.0008,Luminosity);
        h_tttW->SetFillColor(kBlue+2);
        h_stack->Add(h_tttW);
        legend1->AddEntry(h_tttW, "TTT+W", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_tttW->Integral()),"");

        TH1D* h_tttJ = GetHist(f_tttJ,HistName,0.0005,Luminosity);
        h_tttJ->SetFillColor(kBlue+2);
        h_stack->Add(h_tttJ);
        legend1->AddEntry(h_tttJ, "TTT+jets", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_tttJ->Integral()),"");

        legend1->AddEntry((TObject*)0,"Tri-Top + X","");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_tttW->Integral()+h_tttJ->Integral()),"");

        TH1D* h_DYJets_10to50 = GetHist(f_DYJets_10to50,HistName,18610,Luminosity);
        h_DYJets_10to50->SetFillColor(kGreen);
        h_stack->Add(h_DYJets_10to50);
        legend1->AddEntry(h_DYJets_10to50, "Drell-Yan (Z/#gamma->ll, M10to50)", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_DYJets_10to50->Integral()),"");

        TH1D* h_DYJets = GetHist(f_DYJets,HistName,6025.2,Luminosity);
        h_DYJets->SetFillColor(kGreen);
        h_stack->Add(h_DYJets);
        legend1->AddEntry(h_DYJets, "Drell-Yan (Z/#gamma->ll, M50)", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_DYJets->Integral()),"");

        TH1D* h_WJets = GetHist(f_WJets,HistName,61526.7,Luminosity);
        h_WJets->SetFillColor(kGreen);
        h_stack->Add(h_WJets);
        legend1->AddEntry(h_WJets, "W+jets (W->l#nu)", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_WJets->Integral()),"");

        TH1D* h_WGtoLNuG = GetHist(f_WGtoLNuG,HistName,405.3,Luminosity);
        h_WGtoLNuG->SetFillColor(kGreen);
        h_stack->Add(h_WGtoLNuG);
        legend1->AddEntry(h_WGtoLNuG, "W+#gamma (W->l#nu)", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_WGtoLNuG->Integral()),"");

        TH1D* h_ZGto2LG = GetHist(f_ZGto2LG,HistName,117.7,Luminosity);
        h_ZGto2LG->SetFillColor(kGreen);
        h_stack->Add(h_ZGto2LG);
        legend1->AddEntry(h_ZGto2LG, "Z+#gamma (Z->ll)", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_ZGto2LG->Integral()),"");

        legend1->AddEntry((TObject*)0,"SingleBoson + X","");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_DYJets_10to50->Integral()+h_DYJets->Integral()+h_WJets->Integral()+h_WGtoLNuG->Integral()+h_ZGto2LG->Integral()),"");

        //TH1D* h_WW = GetHist(f_WW,HistName,118.8,Luminosity);
        TH1D* h_WW = GetHist(f_WW,HistName,12.178,Luminosity);
        h_WW->SetFillColor(kAzure+10);
        h_stack->Add(h_WW);
        legend1->AddEntry(h_WW, "WW (WW->ll#nu#nu)", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_WW->Integral()),"");

        TH1D* h_WWG = GetHist(f_WWG,HistName,0.0412,Luminosity);
        h_WWG->SetFillColor(kAzure+10);
        h_stack->Add(h_WWG);
        legend1->AddEntry(h_WWG, "WW+#gamma", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_WWG->Integral()),"");

        //TH1D* h_WZ = GetHist(f_WZ,HistName,47.3,Luminosity);
        TH1D* h_WZ = GetHist(f_WZ,HistName,4.42965,Luminosity);
        h_WZ->SetFillColor(kAzure+10);
        h_stack->Add(h_WZ);
        legend1->AddEntry(h_WZ, "WZ (WZ->lll#nu)", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_WZ->Integral()),"");

        TH1D* h_WZG = GetHist(f_WZG,HistName,0.2147,Luminosity);
        h_WZG->SetFillColor(kAzure+10);
        h_stack->Add(h_WZG);
        legend1->AddEntry(h_WZG, "WZ+#gamma", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_WZG->Integral()),"");

        //TH1D* h_ZZ = GetHist(f_ZZ,HistName,16.5,Luminosity);
        TH1D* h_ZZ = GetHist(f_ZZ,HistName,1.212,Luminosity);
        h_ZZ->SetFillColor(kAzure+10);
        h_stack->Add(h_ZZ);
        legend1->AddEntry(h_ZZ, "ZZ (ZZ->llll)", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_ZZ->Integral()),"");

        TH1D* h_WpWpQCD = GetHist(f_WpWpQCD,HistName,0.01538,Luminosity);
        h_WpWpQCD->SetFillColor(kAzure+10);
        h_stack->Add(h_WpWpQCD);
        legend1->AddEntry(h_WpWpQCD, "W+W+ (QCD)", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_WpWpQCD->Integral()),"");

        TH1D* h_WpWpEWK = GetHist(f_WpWpEWK,HistName,0.02064,Luminosity);
        h_WpWpEWK->SetFillColor(kAzure+10);
        h_stack->Add(h_WpWpEWK);
        legend1->AddEntry(h_WpWpEWK, "W+W+ (EWK)", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_WpWpEWK->Integral()),"");

        legend1->AddEntry((TObject*)0,"Di-Boson + X","");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_WW->Integral()+h_WWG->Integral()+h_WZ->Integral()+h_WZG->Integral()+h_ZZ->Integral()+h_WpWpQCD->Integral()+h_WpWpEWK->Integral()),"");

        TH1D* h_WWW = GetHist(f_WWW,HistName,0.17,Luminosity);
        h_WWW->SetFillColor(kCyan-10);
        h_stack->Add(h_WWW);
        legend1->AddEntry(h_WWW, "WWW", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_WWW->Integral()),"");

        TH1D* h_WWZ = GetHist(f_WWZ,HistName,0.17,Luminosity);
        h_WWZ->SetFillColor(kCyan-10);
        h_stack->Add(h_WWZ);
        legend1->AddEntry(h_WWZ, "WWZ", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_WWZ->Integral()),"");

        TH1D* h_WZZ = GetHist(f_WZZ,HistName,0.06,Luminosity);
        h_WZZ->SetFillColor(kCyan-10);
        h_stack->Add(h_WZZ);
        legend1->AddEntry(h_WZZ, "WZZ", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_WZZ->Integral()),"");

        TH1D* h_ZZZ = GetHist(f_ZZZ,HistName,0.01,Luminosity);
        h_ZZZ->SetFillColor(kCyan-10);
        h_stack->Add(h_ZZZ);
        legend1->AddEntry(h_ZZZ, "ZZZ", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_ZZZ->Integral()),"");

        legend1->AddEntry((TObject*)0,"Tri-Boson + X","");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_WWW->Integral()+h_WWZ->Integral()+h_WZZ->Integral()+h_ZZZ->Integral()),"");

        TH1D* h_GluGluH = GetHist(f_GluGluH,HistName,0.0118,Luminosity);
        h_GluGluH->SetFillColor(kCyan);
        h_stack->Add(h_GluGluH);
        legend1->AddEntry(h_GluGluH, "gg->H", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_GluGluH->Integral()),"");

        TH1D* h_VHToNonbb = GetHist(f_VHToNonbb,HistName,0.9561,Luminosity);
        h_VHToNonbb->SetFillColor(kCyan);
        h_stack->Add(h_VHToNonbb);
        legend1->AddEntry(h_VHToNonbb, "H+X (H->nonbb)", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_VHToNonbb->Integral()),"");

        legend1->AddEntry((TObject*)0,"Higgs related","");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_GluGluH->Integral()+h_VHToNonbb->Integral()),"");

/*
        TH1D* h_ = GetHist(".root",HistName,,Luminosity);
        h_->SetFillColor();
        h_stack->Add(h_);
        legend1->AddEntry(h_, "", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_->Integral()),"");
*/
        TH1D* dummy_back = (TH1D*) h_stack->GetStack()->Last();
        legend1->AddEntry((TObject*)0, "Total BackGround", "");
        legend1->AddEntry((TObject*)0,Form("%.3f",dummy_back->Integral()-h_sig->Integral()),"");
        legend1->AddEntry(h_sig, "FourTops Signal", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_sig->Integral()),"");
        legend1->AddEntry(h_data, "Data expected", "lep");
        legend1->AddEntry((TObject*)0,Form("%.0f",h_data->Integral()),"");

        h_stack->Add(h_sig);
        TH1D* dummy_mc = (TH1D*) h_stack->GetStack()->Last();
        TH1D* dummy_data = (TH1D*) h_data->Clone("dummy_data");
        dummy_data->SetTitle("");
        dummy_data->GetYaxis()->SetTitle("Observed / Predicted");
        dummy_data->Divide(dummy_mc);
        TH1D* dummy_mcE = (TH1D*) dummy_mc->Clone("dummy_mcE");
        dummy_mcE->Divide(dummy_mc);
        
        dummy_data->SetMarkerSize(0.8);
        dummy_data->SetLineWidth(2);
        dummy_data->SetLineColor(kBlack);

        dummy_data->GetXaxis()->SetTitleSize(0.12);
        dummy_data->GetXaxis()->SetLabelSize(0.1);

        dummy_data->GetYaxis()->SetTitleOffset(0.4);
        dummy_data->GetYaxis()->SetTitleSize(0.09);
        dummy_data->GetYaxis()->SetLabelSize(0.1);
        dummy_data->GetYaxis()->SetNdivisions(205);

        dummy_mc->SetFillStyle(3144);
        dummy_mc->SetFillColor(kBlack);

        dummy_mcE->SetFillStyle(3144);
        dummy_mcE->SetFillColor(kBlack);

        pad1->cd();
        pad1->Clear();

        pad1->SetLogy();
        if(DataMax > 0) {h_stack->SetMaximum(DataMax*100);}
        else h_stack->SetMaximum(dummy_mc->GetMaximum()*100);

        SigMin /= 100;
        if(SigMin > 1) h_stack->SetMinimum(1);
        else if(SigMin > 0.1) h_stack->SetMinimum(0.1);
        else if(SigMin > 0.01) h_stack->SetMinimum(0.01);
        else h_stack->SetMinimum(0.001);


        h_stack->SetTitle(HistTitle.c_str());
        h_stack->Draw("HIST");
        dummy_mc->Draw("E2SAME");
        h_data->Draw("PESAME");

        h_stack->GetXaxis()->SetLabelOffset(99); // remove x-axis label
        c_test->Update();

        pad2->cd();
        pad2->Clear();

        dummy_data->SetMaximum(2.0);
        dummy_data->SetMinimum(0.0);
        dummy_data->Draw("PE1X0");
        dummy_mcE->Draw("E2SAME");
        TLine* line = new TLine();
        line->DrawLine(dummy_data->GetXaxis()->GetXmin(),1,dummy_data->GetXaxis()->GetXmax(),1);

        pad3->cd();
        pad3->Clear();
        legend1->Draw();

        c_test->SaveAs(Form("%s/ControlPlots/%s.png",rootpath.c_str(),HistName.c_str()));

        delete h_stack; delete h_data; delete h_sig; delete h_ttttbg;
        delete h_ttbg; delete h_ttW; /*delete h_ttZ;*/ delete h_ttZ_1to10; delete h_ttZ_10; /*delete h_ttH_bb;*/ delete h_ttH_nonbb; /*delete h_ttbb;*/
        delete h_ttG_dl; delete h_ttG_slt; delete h_ttG_sltbar;
        delete h_ttWW; delete h_ttWZ; delete h_ttWH; delete h_ttZZ; delete h_ttZH; delete h_ttHH;
        /*delete h_SingleTop_s; delete h_SingleTop_t; delete h_SingleTbar_t;*/ delete h_SingleTop_tW; delete h_SingleTbar_tW;
        delete h_TG; delete h_tZq;
        delete h_tttW; delete h_tttJ;
        delete h_DYJets; delete h_DYJets_10to50; delete h_WJets; delete h_WGtoLNuG; delete h_ZGto2LG;
        delete h_WW; delete h_WWG; delete h_WZ; delete h_WZG; delete h_ZZ; delete h_WpWpEWK; delete h_WpWpQCD;
        delete h_WWW; delete h_WWZ; delete h_WZZ; delete h_ZZZ;
        delete h_GluGluH; delete h_VHToNonbb;

    }

}
