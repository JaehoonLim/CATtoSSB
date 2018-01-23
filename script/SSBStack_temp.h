#include "TStyle.h"

    string rootpath = "Output/170901/SUSY/";
    string rootpath_sig = "Output/170912/";
    string f_suffix = "_SUSY";
    bool Do_DataDriven = false;
    bool log_y = false;

    // data
    TFile* f_DoubleEG_Run2016 = new TFile(Form("%s/DoubleEG_Run2016%s.root",rootpath.c_str(),f_suffix.c_str()));
    TFile* f_DoubleMuon_Run2016 = new TFile(Form("%s/DoubleMuon_Run2016%s.root",rootpath.c_str(),f_suffix.c_str()));
    TFile* f_MuonEG_Run2016 = new TFile(Form("%s/MuonEG_Run2016%s.root",rootpath.c_str(),f_suffix.c_str()));

    // CrossSection : pb-1
    // TTTT
    TFile* f_TTTT_Signal = new TFile(Form("%s/TTTT%s.root",rootpath_sig.c_str(),f_suffix.c_str())); double x_TTTT = 0.009201; 

    // non Prompt Lepton
    TFile* f_TTTT_Others = new TFile(Form("%s/TTTT_Others%s.root",rootpath_sig.c_str(),f_suffix.c_str()));
    TFile* f_TT = new TFile(Form("%s/TT%s.root",rootpath.c_str(),f_suffix.c_str())); double x_TT = 831.76;
    //TFile* f_SingleTop_s = new TFile(Form("%s/SingleTop_s%s.root",rootpath.c_str(),f_suffix.c_str())); double x_ST_s = 3.36; 
    //TFile* f_SingleTop_t = new TFile(Form("%s/SingleTop_t%s.root",rootpath.c_str(),f_suffix.c_str())); double x_ST_t = 44.3;
    //TFile* f_SingleTbar_t = new TFile(Form("%s/SingleTbar_t%s.root",rootpath.c_str(),f_suffix.c_str())); double x_STbar_t = 26.4;
    TFile* f_SingleTop_tW = new TFile(Form("%s/SingleTop_tW%s.root",rootpath.c_str(),f_suffix.c_str())); double x_ST_tW = 35.85;
    TFile* f_SingleTbar_tW = new TFile(Form("%s/SingleTbar_tW%s.root",rootpath.c_str(),f_suffix.c_str())); double x_STbar_tW = 35.85;
    //TFile* f_DYJets = new TFile(Form("%s/DYJets_MG%s.root",rootpath.c_str(),f_suffix.c_str())); double x_DY = 6025.2;
    TFile* f_DYJets = new TFile(Form("%s/DYJets_MG_ext1%s.root",rootpath.c_str(),f_suffix.c_str())); double x_DY = 6025.2;
    TFile* f_DYJets_10to50 = new TFile(Form("%s/DYJets_MG_10to50%s.root",rootpath.c_str(),f_suffix.c_str())); double x_DY_10to50 = 18610;
    //TFile* f_WJets = new TFile(Form("%s/WJets%s.root",rootpath.c_str(),f_suffix.c_str())); double x_WJ = 61526.7;
    TFile* f_WJets = new TFile(Form("%s/WJets_MG%s.root",rootpath.c_str(),f_suffix.c_str())); double x_WJ = 61526.7;

    //TFile* f_DoubleEG_Run2016_TL;
    //TFile* f_DoubleMuon_Run2016_TL;
    //TFile* f_MuonEG_Run2016_TL;
    //if(Do_DataDriven){
    // non Prompt Lepton - Data Driven
    TFile* f_DoubleEG_Run2016_TL = new TFile(Form("%s/DoubleEG_Run2016_TL%s.root",rootpath.c_str(),f_suffix.c_str()));
    TFile* f_DoubleMuon_Run2016_TL = new TFile(Form("%s/DoubleMuon_Run2016_TL%s.root",rootpath.c_str(),f_suffix.c_str()));
    TFile* f_MuonEG_Run2016_TL = new TFile(Form("%s/MuonEG_Run2016_TL%s.root",rootpath.c_str(),f_suffix.c_str()));
    //}

    // TT + V
    //TFile* f_ttW = new TFile(Form("%s/ttW%s.root",rootpath.c_str(),f_suffix.c_str())); double x_ttW = 0.61; // Inclusive
    TFile* f_ttW = new TFile(Form("%s/ttWToLNu%s.root",rootpath.c_str(),f_suffix.c_str())); double x_ttW = 0.2043;
    //TFile* f_ttZ = new TFile(Form("%s/ttZ%s.root",rootpath.c_str(),f_suffix.c_str())); double x_ttZ = 0.78; // Inclusive
    TFile* f_ttZ_1to10 = new TFile(Form("%s/ttZToLL_M-1to10%s.root",rootpath.c_str(),f_suffix.c_str())); double x_ttZ_1to10 = 0.0493;
    TFile* f_ttZ_10 = new TFile(Form("%s/ttZToLLNuNu_M-10%s.root",rootpath.c_str(),f_suffix.c_str())); double x_ttZ_10 = 0.2529;
    //TFile* f_ttH_bb = new TFile(Form("%s/ttH_bb%s.root",rootpath.c_str(),f_suffix.c_str())); double x_ttH_bb = 0.29;
    TFile* f_ttH_nonbb = new TFile(Form("%s/ttH_nonbb%s.root",rootpath.c_str(),f_suffix.c_str())); double x_ttH_nonbb = 0.22;
    //TFile* f_ttbb = new TFile(Form("%s/ttbb%s.root",rootpath.c_str(),f_suffix.c_str())); double x_ttbb = 13.93;

    // TT + VV
    TFile* f_ttWW = new TFile(Form("%s/ttWW%s.root",rootpath.c_str(),f_suffix.c_str())); double x_ttWW = 0.0115;
    TFile* f_ttWZ = new TFile(Form("%s/ttWZ%s.root",rootpath.c_str(),f_suffix.c_str())); double x_ttWZ = 0.0039;
    TFile* f_ttWH = new TFile(Form("%s/ttWH%s.root",rootpath.c_str(),f_suffix.c_str())); double x_ttWH = 0.0016;
    TFile* f_ttZZ = new TFile(Form("%s/ttZZ%s.root",rootpath.c_str(),f_suffix.c_str())); double x_ttZZ = 0.0020;
    TFile* f_ttZH = new TFile(Form("%s/ttZH%s.root",rootpath.c_str(),f_suffix.c_str())); double x_ttZH = 0.0015;
    TFile* f_ttHH = new TFile(Form("%s/ttHH%s.root",rootpath.c_str(),f_suffix.c_str())); double x_ttHH = 0.0008;

    // X + Gamma
    TFile* f_TG = new TFile(Form("%s/TGJets%s.root",rootpath.c_str(),f_suffix.c_str())); double x_TG = 2.967;
    TFile* f_ttG_slt = new TFile(Form("%s/ttGamma_SingleLeptFromT%s.root",rootpath.c_str(),f_suffix.c_str())); double x_ttG_slt = 0.7700;
    TFile* f_ttG_sltbar = new TFile(Form("%s/ttGamma_SingleLeptFromTbar%s.root",rootpath.c_str(),f_suffix.c_str())); double x_ttG_sltbar = 0.7690;
    TFile* f_ttG_dl = new TFile(Form("%s/ttGamma_Dilept%s.root",rootpath.c_str(),f_suffix.c_str())); double x_ttG_dl = 0.6320;
    TFile* f_WGtoLNuG = new TFile(Form("%s/WGtoLNuG%s.root",rootpath.c_str(),f_suffix.c_str())); double x_WG = 405.3;
    TFile* f_ZGto2LG = new TFile(Form("%s/ZGto2LG%s.root",rootpath.c_str(),f_suffix.c_str())); double x_ZG = 117.7;

    // Rare SM
    TFile* f_tZq = new TFile(Form("%s/tZq_ll_4f%s.root",rootpath.c_str(),f_suffix.c_str())); double x_tZq = 0.0758;
    TFile* f_tttW = new TFile(Form("%s/tttW%s.root",rootpath.c_str(),f_suffix.c_str())); double x_tttW = 0.0008;
    TFile* f_tttJ = new TFile(Form("%s/tttJ%s.root",rootpath.c_str(),f_suffix.c_str())); double x_tttJ = 0.0005;
    //TFile* f_WW = new TFile(Form("%s/WW%s.root",rootpath.c_str(),f_suffix.c_str())); double x_WW = 118.8; // Inclusive
    TFile* f_WW = new TFile(Form("%s/WWTo2L2Nu%s.root",rootpath.c_str(),f_suffix.c_str())); double x_WW = 12.178;
    TFile* f_WWG = new TFile(Form("%s/WWG%s.root",rootpath.c_str(),f_suffix.c_str())); double x_WWG = 0.0412;
    //TFile* f_WZ = new TFile(Form("%s/WZ%s.root",rootpath.c_str(),f_suffix.c_str())); double x_WZ = 47.3; // Inclusive
    TFile* f_WZ = new TFile(Form("%s/WZTo3LNu%s.root",rootpath.c_str(),f_suffix.c_str())); double x_WZ = 4.42965;
    TFile* f_WZG = new TFile(Form("%s/WZG%s.root",rootpath.c_str(),f_suffix.c_str())); double x_WZG = 0.2147;
    //TFile* f_ZZ = new TFile(Form("%s/ZZ%s.root",rootpath.c_str(),f_suffix.c_str())); double x_ZZ = 16.5; // Inclusive
    TFile* f_ZZ = new TFile(Form("%s/ZZTo4L%s.root",rootpath.c_str(),f_suffix.c_str())); double x_ZZ = 1.212;
    TFile* f_WpWpQCD = new TFile(Form("%s/WpWpQCD%s.root",rootpath.c_str(),f_suffix.c_str())); double x_WpWpQCD = 0.01538; 
    TFile* f_WpWpEWK = new TFile(Form("%s/WpWpEWK%s.root",rootpath.c_str(),f_suffix.c_str())); double x_WpWpEWK = 0.02064;
    TFile* f_WWW = new TFile(Form("%s/WWW%s.root",rootpath.c_str(),f_suffix.c_str())); double x_WWW = 0.17;
    TFile* f_WWZ = new TFile(Form("%s/WWZ%s.root",rootpath.c_str(),f_suffix.c_str())); double x_WWZ = 0.17;
    TFile* f_WZZ = new TFile(Form("%s/WZZ%s.root",rootpath.c_str(),f_suffix.c_str())); double x_WZZ = 0.06;
    TFile* f_ZZZ = new TFile(Form("%s/ZZZ%s.root",rootpath.c_str(),f_suffix.c_str())); double x_ZZZ = 0.01;
    TFile* f_GluGluH = new TFile(Form("%s/GluGluHToZZTo4L%s.root",rootpath.c_str(),f_suffix.c_str())); double x_GGH = 0.0118;
    TFile* f_VHToNonbb = new TFile(Form("%s/VHToNonbb%s.root",rootpath.c_str(),f_suffix.c_str())); double x_VH = 0.9561;
    //TFile* f_ = new TFile(Form("%s/.root",rootpath.c_str(),f_suffix.c_str()));

TH1D* GetHist(TFile* f_test, std::string HistName, double CrossSection, double Luminosity, bool isData=false){

    CrossSection *= 1000; //
    TH1D* h_gen = (TH1D*)f_test->Get("SSBAnalyzer/GenInfo");
    double NumEvents = (double)h_gen->GetBinContent(1);
    double EventsWeight = (double)h_gen->GetBinContent(2); 
    cout << fixed << setprecision(0);
    if(HistName =="numPV_ee_0a" || HistName =="numPV_mm_0a" || HistName =="numPV_em_0a" ) cout << HistName << " : " << "NumEvents : " << NumEvents << " / EventsWeight : " << EventsWeight << endl;
    if (isData) {EventsWeight = 1; CrossSection = 1;}
    TH1D* h_test = (TH1D*)f_test->Get(Form("SSBAnalyzer/SSBHist/%s",HistName.c_str()));
    if(h_test->GetNbinsX()>50){
        if(h_test->GetNbinsX()<200){h_test->Rebin(h_test->GetNbinsX()/10);}
        else {h_test->Rebin(h_test->GetNbinsX()/20);}
    }
    h_test->SetDirectory(0);
    h_test->SetLineColor(1);
    h_test->Scale(CrossSection*Luminosity/EventsWeight);
    //cout << FileName << " : " << h_test->Integral() << " +/- " << h_test->Integral() * sqrt(1./h_test->Integral() + 1./EventsWeight) << endl;
    return (TH1D*)h_test->Clone();

}

void setTDRStyle() {
  TStyle *tdrStyle = new TStyle("tdrStyle","Style for P-TDR");

  tdrStyle->SetCanvasBorderMode(0);
  tdrStyle->SetCanvasColor(kWhite);
  tdrStyle->SetCanvasDefX(0);
  tdrStyle->SetCanvasDefY(0);

  tdrStyle->SetPadBorderMode(0);
  tdrStyle->SetPadColor(kWhite);
  tdrStyle->SetPadGridX(false);
  tdrStyle->SetPadGridY(false);
  tdrStyle->SetGridColor(0);
  tdrStyle->SetGridStyle(3);
  tdrStyle->SetGridWidth(1);

  tdrStyle->SetFrameBorderMode(0);
  tdrStyle->SetFrameBorderSize(1);
  tdrStyle->SetFrameFillColor(0);
  tdrStyle->SetFrameFillStyle(0);
  tdrStyle->SetFrameLineColor(1);
  tdrStyle->SetFrameLineStyle(1);
  tdrStyle->SetFrameLineWidth(1);

  tdrStyle->SetHistLineColor(1);
  tdrStyle->SetHistLineStyle(0);
  tdrStyle->SetHistLineWidth(1);

  tdrStyle->SetEndErrorSize(2);
  tdrStyle->SetMarkerStyle(20);

  tdrStyle->SetOptFit(1);
  tdrStyle->SetFitFormat("5.4g");
  tdrStyle->SetFuncColor(2);
  tdrStyle->SetFuncStyle(1);
  tdrStyle->SetFuncWidth(1);

  tdrStyle->SetOptDate(0);
  tdrStyle->SetOptFile(0);
  tdrStyle->SetOptStat(0);
  tdrStyle->SetStatColor(kWhite);
  tdrStyle->SetStatFont(42);
  tdrStyle->SetStatFontSize(0.025);
  tdrStyle->SetStatTextColor(1);
  tdrStyle->SetStatFormat("6.4g");
  tdrStyle->SetStatBorderSize(1);
  tdrStyle->SetStatH(0.1);
  tdrStyle->SetStatW(0.15);

  tdrStyle->SetTitleFont(42);
  tdrStyle->SetTitleColor(1);
  tdrStyle->SetTitleTextColor(1);
  tdrStyle->SetTitleFillColor(10);
  tdrStyle->SetTitleFontSize(0.05);

  tdrStyle->SetTitleColor(1, "XYZ");
  tdrStyle->SetTitleFont(42, "XYZ");

  tdrStyle->SetLabelColor(1, "XYZ");
  tdrStyle->SetLabelFont(42, "XYZ");
  tdrStyle->SetLabelSize(0.05, "XYZ");

  tdrStyle->SetAxisColor(1, "XYZ");
  tdrStyle->SetStripDecimals(kTRUE);
  tdrStyle->SetTickLength(0.03, "XYZ");
  tdrStyle->SetNdivisions(510, "XYZ");
  tdrStyle->SetPadTickX(1);
  tdrStyle->SetPadTickY(1);

  tdrStyle->cd();

}

void MKStack(string HistName, double Luminosity, bool DataDriven = false){

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

    double SigMin,DataMax;
    string HistTitle = HistName;
    TLegend *legend1 = new TLegend(0.0,0.1,0.9,0.95);
    legend1->SetNColumns(2);
    legend1->SetFillColor(0);
    legend1->SetTextSize(0.05);

    THStack* h_stack = new THStack("h_stack","h_stack");

    // data
    TH1D* h_data;
    TH1D* h_DataDriven;
    if(HistName.find("ee") != string::npos){
        h_data = GetHist(f_DoubleEG_Run2016,HistName,1,1,true);
        HistTitle.replace(HistTitle.find("_ee_"),4,"  (ee : CutStep ");
        Luminosity = 36.454;
        if(DataDriven) h_DataDriven = GetHist(f_DoubleEG_Run2016_TL,HistName,1,1,true);
    } else if(HistName.find("mm") != string::npos){
        h_data = GetHist(f_DoubleMuon_Run2016,HistName,1,1,true);
        HistTitle.replace(HistTitle.find("_mm_"),4,"  (#mu#mu : CutStep ");
        if(DataDriven) h_DataDriven = GetHist(f_DoubleMuon_Run2016_TL,HistName,1,1,true);
    } else if(HistName.find("em") != string::npos){
        h_data = GetHist(f_MuonEG_Run2016,HistName,1,1,true);
        HistTitle.replace(HistTitle.find("_em_"),4,"  (e#mu : CutStep ");
        if(DataDriven) h_DataDriven = GetHist(f_MuonEG_Run2016_TL,HistName,1,1,true);
    } else {
        cout << "ERROR" << endl; exit(0);
    }

    HistTitle += ")";
    h_data->SetMarkerStyle(20);
    h_data->SetLineWidth(3);
    DataMax = h_data->GetMaximum();

    // TTTT Signal
    TH1D* h_sig = GetHist(f_TTTT_Signal,HistName,x_TTTT,Luminosity);
    h_sig->SetFillColor(kRed);
    h_stack->Add(h_sig);
    SigMin = h_sig->GetMaximum();

    // TTTT Others
    TH1D* h_ttttbg = GetHist(f_TTTT_Others,HistName,x_TTTT,Luminosity);
    h_ttttbg->SetFillColor(kMagenta);
    h_stack->Add(h_ttttbg);
    legend1->AddEntry(h_ttttbg, "FourTops Others", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttttbg->Integral()),"");

    // TT + V
    TH1D* h_ttW = GetHist(f_ttW,HistName,x_ttW,Luminosity);
    h_ttW->SetFillColor(kBlue);
    h_stack->Add(h_ttW);
    legend1->AddEntry(h_ttW, "TTbar+W (W->l#nu)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttW->Integral()),"");

    TH1D* h_ttZ_1to10 = GetHist(f_ttZ_1to10,HistName,x_ttZ_1to10,Luminosity);
    h_ttZ_1to10->SetFillColor(kAzure-3);
    h_stack->Add(h_ttZ_1to10);
    legend1->AddEntry(h_ttZ_1to10, "TTbar+Z (Z->ll, M1to10)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttZ_1to10->Integral()),"");

    TH1D* h_ttZ_10 = GetHist(f_ttZ_10,HistName,x_ttZ_10,Luminosity);
    h_ttZ_10->SetFillColor(kAzure-3);
    h_stack->Add(h_ttZ_10);
    legend1->AddEntry(h_ttZ_10, "TTbar+Z (Z->ll, M10)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttZ_10->Integral()),"");
/*
    TH1D* h_ttZ = GetHist(f_ttZ,HistName,x_ttZ,Luminosity);
    h_ttZ->SetFillColor(kAzure-3);
    h_stack->Add(h_ttZ);
    legend1->AddEntry(h_ttZ, "TTbar+Z", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttZ->Integral()),"");

    TH1D* h_ttH_bb = GetHist(f_ttH_bb,HistName,x_ttHbb,Luminosity);
    h_ttH_bb->SetFillColor(kAzure+7);
    h_stack->Add(h_ttH_bb);
    legend1->AddEntry(h_ttH_bb, "TTbar+H (H->bb)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttH_bb->Integral()),"");
*/
    TH1D* h_ttH_nonbb = GetHist(f_ttH_nonbb,HistName,x_ttH_nonbb,Luminosity);
    h_ttH_nonbb->SetFillColor(kAzure+7);
    h_stack->Add(h_ttH_nonbb);
    legend1->AddEntry(h_ttH_nonbb, "TTbar+H (H->nonbb)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttH_nonbb->Integral()),"");
/*
    TH1D* h_ttbb = GetHist(f_ttbb,HistName,x_ttbb,Luminosity);
    h_ttbb->SetFillColor(kAzure);
    h_stack->Add(h_ttbb);
    legend1->AddEntry(h_ttbb, "TTbar+bb", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttbb->Integral()),"");
*/
    legend1->AddEntry((TObject*)0,"TopPair + V","");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttW->Integral()+h_ttZ_1to10->Integral()+h_ttZ_10->Integral()+h_ttH_nonbb->Integral()),"");

    // TT + VV
    TH1D* h_ttWW = GetHist(f_ttWW,HistName,x_ttWW,Luminosity);
    h_ttWW->SetFillColor(kCyan);
    h_stack->Add(h_ttWW);
    legend1->AddEntry(h_ttWW, "TTbar+WW", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttWW->Integral()),"");

    TH1D* h_ttWZ = GetHist(f_ttWZ,HistName,x_ttWZ,Luminosity);
    h_ttWZ->SetFillColor(kCyan);
    h_stack->Add(h_ttWZ);
    legend1->AddEntry(h_ttWZ, "TTbar+WZ", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttWZ->Integral()),"");

    TH1D* h_ttWH = GetHist(f_ttWH,HistName,x_ttWH,Luminosity);
    h_ttWH->SetFillColor(kCyan);
    h_stack->Add(h_ttWH);
    legend1->AddEntry(h_ttWH, "TTbar+WH", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttWH->Integral()),"");

    TH1D* h_ttZZ = GetHist(f_ttZZ,HistName,x_ttZZ,Luminosity);
    h_ttZZ->SetFillColor(kCyan);
    h_stack->Add(h_ttZZ);
    legend1->AddEntry(h_ttZZ, "TTbar+ZZ", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttZZ->Integral()),"");

    TH1D* h_ttZH = GetHist(f_ttZH,HistName,x_ttZH,Luminosity);
    h_ttZH->SetFillColor(kCyan);
    h_stack->Add(h_ttZH);
    legend1->AddEntry(h_ttZH, "TTbar+ZH", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttZH->Integral()),"");

    TH1D* h_ttHH = GetHist(f_ttHH,HistName,x_ttHH,Luminosity);
    h_ttHH->SetFillColor(kCyan);
    h_stack->Add(h_ttHH);
    legend1->AddEntry(h_ttHH, "TTbar+HH", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttHH->Integral()),"");

    legend1->AddEntry((TObject*)0,"TopPair + VV","");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttWW->Integral()+h_ttWZ->Integral()+h_ttWH->Integral()+h_ttZZ->Integral()+h_ttZH->Integral()+h_ttHH->Integral()),"");

    // X + Gamma
    TH1D* h_ttG_dl = GetHist(f_ttG_dl,HistName,x_ttG_dl,Luminosity);
    h_ttG_dl->SetFillColor(kGreen);
    h_stack->Add(h_ttG_dl);
    legend1->AddEntry(h_ttG_dl, "TTbar+#gamma (Di-Lepton)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttG_dl->Integral()),"");

    TH1D* h_ttG_slt = GetHist(f_ttG_slt,HistName,x_ttG_slt,Luminosity);
    h_ttG_slt->SetFillColor(kGreen);
    h_stack->Add(h_ttG_slt);
    legend1->AddEntry(h_ttG_slt, "TTbar+#gamma (T->LNu)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttG_slt->Integral()),"");

    TH1D* h_ttG_sltbar = GetHist(f_ttG_sltbar,HistName,x_ttG_sltbar,Luminosity);
    h_ttG_sltbar->SetFillColor(kGreen);
    h_stack->Add(h_ttG_sltbar);
    legend1->AddEntry(h_ttG_sltbar, "TTbar+#gamma (Tbar->LNu)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttG_sltbar->Integral()),"");

    TH1D* h_TG = GetHist(f_TG,HistName,x_TG,Luminosity);
    h_TG->SetFillColor(kGreen);
    h_stack->Add(h_TG);
    legend1->AddEntry(h_TG, "T+#gamma", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_TG->Integral()),"");

    TH1D* h_WGtoLNuG = GetHist(f_WGtoLNuG,HistName,x_WG,Luminosity);
    h_WGtoLNuG->SetFillColor(kGreen);
    h_stack->Add(h_WGtoLNuG);
    legend1->AddEntry(h_WGtoLNuG, "W+#gamma (W->l#nu)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_WGtoLNuG->Integral()),"");

    TH1D* h_ZGto2LG = GetHist(f_ZGto2LG,HistName,x_ZG,Luminosity);
    h_ZGto2LG->SetFillColor(kGreen);
    h_stack->Add(h_ZGto2LG);
    legend1->AddEntry(h_ZGto2LG, "Z+#gamma (Z->ll)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ZGto2LG->Integral()),"");

    legend1->AddEntry((TObject*)0,"X + #gamma","");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttG_dl->Integral()+h_ttG_slt->Integral()+h_ttG_sltbar->Integral()+h_TG->Integral()+h_WGtoLNuG->Integral()+h_ZGto2LG->Integral()),"");

    // Rare SM
    TH1D* h_tZq = GetHist(f_tZq,HistName,x_tZq,Luminosity);
    h_tZq->SetFillColor(kViolet);
    h_stack->Add(h_tZq);
    legend1->AddEntry(h_tZq, "TZq", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_tZq->Integral()),"");

    TH1D* h_tttW = GetHist(f_tttW,HistName,x_tttW,Luminosity);
    h_tttW->SetFillColor(kViolet);
    h_stack->Add(h_tttW);
    legend1->AddEntry(h_tttW, "TTT+W", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_tttW->Integral()),"");

    TH1D* h_tttJ = GetHist(f_tttJ,HistName,x_tttJ,Luminosity);
    h_tttJ->SetFillColor(kViolet);
    h_stack->Add(h_tttJ);
    legend1->AddEntry(h_tttJ, "TTT+jets", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_tttJ->Integral()),"");

    TH1D* h_WW = GetHist(f_WW,HistName,x_WW,Luminosity);
    h_WW->SetFillColor(kViolet);
    h_stack->Add(h_WW);
    legend1->AddEntry(h_WW, "WW (WW->ll#nu#nu)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_WW->Integral()),"");

    TH1D* h_WZ = GetHist(f_WZ,HistName,x_WZ,Luminosity);
    h_WZ->SetFillColor(kViolet);
    h_stack->Add(h_WZ);
    legend1->AddEntry(h_WZ, "WZ (WZ->lll#nu)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_WZ->Integral()),"");

    TH1D* h_ZZ = GetHist(f_ZZ,HistName,x_ZZ,Luminosity);
    h_ZZ->SetFillColor(kViolet);
    h_stack->Add(h_ZZ);
    legend1->AddEntry(h_ZZ, "ZZ (ZZ->llll)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ZZ->Integral()),"");

    TH1D* h_WpWpQCD = GetHist(f_WpWpQCD,HistName,x_WpWpQCD,Luminosity);
    h_WpWpQCD->SetFillColor(kViolet);
    h_stack->Add(h_WpWpQCD);
    legend1->AddEntry(h_WpWpQCD, "W+W+ (QCD)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_WpWpQCD->Integral()),"");

    TH1D* h_WpWpEWK = GetHist(f_WpWpEWK,HistName,x_WpWpEWK,Luminosity);
    h_WpWpEWK->SetFillColor(kViolet);
    h_stack->Add(h_WpWpEWK);
    legend1->AddEntry(h_WpWpEWK, "W+W+ (EWK)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_WpWpEWK->Integral()),"");

    TH1D* h_WWG = GetHist(f_WWG,HistName,x_WWG,Luminosity);
    h_WWG->SetFillColor(kViolet);
    h_stack->Add(h_WWG);
    legend1->AddEntry(h_WWG, "WW+#gamma", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_WWG->Integral()),"");

    TH1D* h_WZG = GetHist(f_WZG,HistName,x_WZG,Luminosity);
    h_WZG->SetFillColor(kViolet);
    h_stack->Add(h_WZG);
    legend1->AddEntry(h_WZG, "WZ+#gamma", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_WZG->Integral()),"");

    TH1D* h_WWW = GetHist(f_WWW,HistName,x_WWW,Luminosity);
    h_WWW->SetFillColor(kViolet);
    h_stack->Add(h_WWW);
    legend1->AddEntry(h_WWW, "WWW", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_WWW->Integral()),"");

    TH1D* h_WWZ = GetHist(f_WWZ,HistName,x_WWZ,Luminosity);
    h_WWZ->SetFillColor(kViolet);
    h_stack->Add(h_WWZ);
    legend1->AddEntry(h_WWZ, "WWZ", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_WWZ->Integral()),"");

    TH1D* h_WZZ = GetHist(f_WZZ,HistName,x_WZZ,Luminosity);
    h_WZZ->SetFillColor(kViolet);
    h_stack->Add(h_WZZ);
    legend1->AddEntry(h_WZZ, "WZZ", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_WZZ->Integral()),"");

    TH1D* h_ZZZ = GetHist(f_ZZZ,HistName,x_ZZZ,Luminosity);
    h_ZZZ->SetFillColor(kViolet);
    h_stack->Add(h_ZZZ);
    legend1->AddEntry(h_ZZZ, "ZZZ", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ZZZ->Integral()),"");

    TH1D* h_GluGluH = GetHist(f_GluGluH,HistName,x_GGH,Luminosity);
    h_GluGluH->SetFillColor(kViolet);
    h_stack->Add(h_GluGluH);
    legend1->AddEntry(h_GluGluH, "gg->H", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_GluGluH->Integral()),"");

    TH1D* h_VHToNonbb = GetHist(f_VHToNonbb,HistName,x_VH,Luminosity);
    h_VHToNonbb->SetFillColor(kViolet);
    h_stack->Add(h_VHToNonbb);
    legend1->AddEntry(h_VHToNonbb, "H+X (H->nonbb)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_VHToNonbb->Integral()),"");

    legend1->AddEntry((TObject*)0,"Rare SM","");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_tZq->Integral()+h_tttW->Integral()+h_tttJ->Integral()+h_WW->Integral()+h_WWG->Integral()+h_WZ->Integral()+h_WZG->Integral()+h_ZZ->Integral()+h_WpWpQCD->Integral()+h_WpWpEWK->Integral()+h_WWW->Integral()+h_WWZ->Integral()+h_WZZ->Integral()+h_ZZZ->Integral()+h_GluGluH->Integral()+h_VHToNonbb->Integral()),"");


    // non Prompt Lepton
    if(DataDriven){
    h_DataDriven->SetFillColor(kGray);
    double temp_weight = (double)(h_data->Integral()) - (double)(((TH1D*)h_stack->GetStack()->Last())->Integral());
    if (temp_weight < 0) temp_weight = 0;
    h_DataDriven->Scale(temp_weight/h_DataDriven->Integral());
    h_stack->Add(h_DataDriven);

    legend1->AddEntry(h_DataDriven,"non Prompt Lepton","f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_DataDriven->Integral()),"");
    } else {
    TH1D* h_ttbg = GetHist(f_TT,HistName,x_TT,Luminosity);
    h_ttbg->SetFillColor(kGray);
    h_stack->Add(h_ttbg);
    legend1->AddEntry(h_ttbg, "TTbar", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttbg->Integral()),"");
/*
    TH1D* h_SingleTop_s = GetHist(f_SingleTop_s,HistName,x_ST_s,Luminosity);
    h_SingleTop_s->SetFillColor(kGray);
    h_stack->Add(h_SingleTop_s);
    legend1->AddEntry(h_SingleTop_s, "s-channel T (leptonic)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_SingleTop_s->Integral()),"");

    TH1D* h_SingleTop_t = GetHist(f_SingleTop_t,HistName,x_ST_t,Luminosity);
    h_SingleTop_t->SetFillColor(kGray);
    h_stack->Add(h_SingleTop_t);
    legend1->AddEntry(h_SingleTop_t, "t-channel T (leptonic)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_SingleTop_t->Integral()),"");

    TH1D* h_SingleTbar_t = GetHist(f_SingleTbar_t,HistName,x_STbar_t,Luminosity);
    h_SingleTbar_t->SetFillColor(kGray);
    h_stack->Add(h_SingleTbar_t);
    legend1->AddEntry(h_SingleTbar_t, "t-channel Tbar (leptonic)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_SingleTbar_t->Integral()),"");
*/
    TH1D* h_SingleTop_tW = GetHist(f_SingleTop_tW,HistName,x_ST_tW,Luminosity);
    h_SingleTop_tW->SetFillColor(kGray);
    h_stack->Add(h_SingleTop_tW);
    legend1->AddEntry(h_SingleTop_tW, "t-channel T+W", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_SingleTop_tW->Integral()),"");

    TH1D* h_SingleTbar_tW = GetHist(f_SingleTbar_tW,HistName,x_STbar_tW,Luminosity);
    h_SingleTbar_tW->SetFillColor(kGray);
    h_stack->Add(h_SingleTbar_tW);
    legend1->AddEntry(h_SingleTbar_tW, "t-channel Tbar+W", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_SingleTbar_tW->Integral()),"");

    TH1D* h_DYJets_10to50 = GetHist(f_DYJets_10to50,HistName,x_DY_10to50,Luminosity);
    h_DYJets_10to50->SetFillColor(kGray);
    h_stack->Add(h_DYJets_10to50);
    legend1->AddEntry(h_DYJets_10to50, "Drell-Yan (Z/#gamma->ll, M10to50)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_DYJets_10to50->Integral()),"");

    TH1D* h_DYJets = GetHist(f_DYJets,HistName,x_DY,Luminosity);
    h_DYJets->SetFillColor(kGray);
    h_stack->Add(h_DYJets);
    legend1->AddEntry(h_DYJets, "Drell-Yan (Z/#gamma->ll, M50)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_DYJets->Integral()),"");

    TH1D* h_WJets = GetHist(f_WJets,HistName,x_WJ,Luminosity);
    h_WJets->SetFillColor(kGray);
    h_stack->Add(h_WJets);
    legend1->AddEntry(h_WJets, "W+jets (W->l#nu)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_WJets->Integral()),"");

    legend1->AddEntry((TObject*)0,"non Prompt Lepton","");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttbg->Integral()+h_SingleTop_tW->Integral()+h_SingleTbar_tW->Integral()+h_DYJets_10to50->Integral()+h_DYJets->Integral()+h_WJets->Integral()),"");
    }

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

    dummy_mc->SetFillStyle(3244);
    dummy_mc->SetFillColor(kBlack);

    dummy_mcE->SetFillStyle(3244);
    dummy_mcE->SetFillColor(kBlack);

    pad1->cd();
    pad1->Clear();

    if(log_y){
    pad1->SetLogy();
    if(DataMax > 0) {h_stack->SetMaximum(DataMax*100);}
    else h_stack->SetMaximum(dummy_mc->GetMaximum()*100);

    SigMin /= 100;
    if(SigMin > 1) h_stack->SetMinimum(1);
    else if(SigMin > 0.1) h_stack->SetMinimum(0.1);
    else if(SigMin > 0.01) h_stack->SetMinimum(0.01);
    else h_stack->SetMinimum(0.001);
    } else {
    if(DataMax > dummy_mc->GetMaximum()) {h_stack->SetMaximum(DataMax*1.3);}
    else h_stack->SetMaximum(dummy_mc->GetMaximum()*1.3);
    }

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

    c_test->SaveAs(Form("%s/ControlPlots/%s.png",rootpath_sig.c_str(),HistName.c_str()));

//    delete h_stack; delete h_data; delete h_sig; delete h_ttttbg;
//    delete h_ttbg; delete h_ttW; /*delete h_ttZ;*/ delete h_ttZ_1to10; delete h_ttZ_10; /*delete h_ttH_bb;*/ delete h_ttH_nonbb; /*delete h_ttbb;*/
//    delete h_ttG_dl; delete h_ttG_slt; delete h_ttG_sltbar;
//    delete h_ttWW; delete h_ttWZ; delete h_ttWH; delete h_ttZZ; delete h_ttZH; delete h_ttHH;
//    /*delete h_SingleTop_s; delete h_SingleTop_t; delete h_SingleTbar_t;*/ delete h_SingleTop_tW; delete h_SingleTbar_tW;
//    delete h_TG; delete h_tZq;
//    delete h_tttW; delete h_tttJ;
//    delete h_DYJets; delete h_DYJets_10to50; delete h_WJets; delete h_WGtoLNuG; delete h_ZGto2LG;
//    delete h_WW; delete h_WWG; delete h_WZ; delete h_WZG; delete h_ZZ; delete h_WpWpEWK; delete h_WpWpQCD;
//    delete h_WWW; delete h_WWZ; delete h_WZZ; delete h_ZZZ;
//    delete h_GluGluH; delete h_VHToNonbb;

    delete c_test;

}

void MKStack_ALL(string HistName, double Luminosity, bool DataDriven = false){

    if(HistName.find("ee") != string::npos){

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

    double SigMin,DataMax;
    string HistTitle = HistName;
    HistTitle.replace(HistTitle.find("_ee_"),4,"  (ALL Channel : CutStep ");
    HistTitle += ")";
    double Luminosity_ee = 36.454;

    TLegend *legend1 = new TLegend(0.0,0.1,0.9,0.95);
    legend1->SetNColumns(2);
    legend1->SetFillColor(0);
    legend1->SetTextSize(0.05);

    THStack* h_stack = new THStack("h_stack","h_stack");

    // data
    TH1D* h_data = GetHist(f_DoubleEG_Run2016,HistName,1,1,true);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_data->Add(GetHist(f_DoubleMuon_Run2016,HistName,1,1,true));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_data->Add(GetHist(f_MuonEG_Run2016,HistName,1,1,true));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_data->SetMarkerStyle(20);
    h_data->SetLineWidth(3);
    DataMax = h_data->GetMaximum();

    // TTTT Signal
    TH1D* h_sig = GetHist(f_TTTT_Signal,HistName,x_TTTT,Luminosity_ee);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_sig->Add(GetHist(f_TTTT_Signal,HistName,x_TTTT,Luminosity));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_sig->Add(GetHist(f_TTTT_Signal,HistName,x_TTTT,Luminosity));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_sig->SetFillColor(kRed);
    h_stack->Add(h_sig);
    SigMin = h_sig->GetMaximum();

    // TTTT Others
    TH1D* h_ttttbg = GetHist(f_TTTT_Others,HistName,x_TTTT,Luminosity_ee);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_ttttbg->Add(GetHist(f_TTTT_Others,HistName,x_TTTT,Luminosity));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_ttttbg->Add(GetHist(f_TTTT_Others,HistName,x_TTTT,Luminosity));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_ttttbg->SetFillColor(kMagenta);
    h_stack->Add(h_ttttbg);
    legend1->AddEntry(h_ttttbg, "FourTops Others", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttttbg->Integral()),"");

    // TT + V
    TH1D* h_ttW = GetHist(f_ttW,HistName,x_ttW,Luminosity_ee);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_ttW->Add(GetHist(f_ttW,HistName,x_ttW,Luminosity));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_ttW->Add(GetHist(f_ttW,HistName,x_ttW,Luminosity));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_ttW->SetFillColor(kBlue);
    h_stack->Add(h_ttW);
    legend1->AddEntry(h_ttW, "TTbar+W (W->l#nu)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttW->Integral()),"");

    TH1D* h_ttZ_1to10 = GetHist(f_ttZ_1to10,HistName,x_ttZ_1to10,Luminosity_ee);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_ttZ_1to10->Add(GetHist(f_ttZ_1to10,HistName,x_ttZ_1to10,Luminosity));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_ttZ_1to10->Add(GetHist(f_ttZ_1to10,HistName,x_ttZ_1to10,Luminosity));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_ttZ_1to10->SetFillColor(kAzure-3);
    h_stack->Add(h_ttZ_1to10);
    legend1->AddEntry(h_ttZ_1to10, "TTbar+Z (Z->ll, M1to10)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttZ_1to10->Integral()),"");

    TH1D* h_ttZ_10 = GetHist(f_ttZ_10,HistName,x_ttZ_10,Luminosity_ee);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_ttZ_10->Add(GetHist(f_ttZ_10,HistName,x_ttZ_10,Luminosity));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_ttZ_10->Add(GetHist(f_ttZ_10,HistName,x_ttZ_10,Luminosity));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_ttZ_10->SetFillColor(kAzure-3);
    h_stack->Add(h_ttZ_10);
    legend1->AddEntry(h_ttZ_10, "TTbar+Z (Z->ll, M10)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttZ_10->Integral()),"");
/*
    TH1D* h_ttZ = GetHist(f_ttZ,HistName,x_ttZ,Luminosity);
    h_ttZ->SetFillColor(kAzure-3);
    h_stack->Add(h_ttZ);
    legend1->AddEntry(h_ttZ, "TTbar+Z", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttZ->Integral()),"");

    TH1D* h_ttH_bb = GetHist(f_ttH_bb,HistName,x_ttHbb,Luminosity);
    h_ttH_bb->SetFillColor(kAzure+7);
    h_stack->Add(h_ttH_bb);
    legend1->AddEntry(h_ttH_bb, "TTbar+H (H->bb)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttH_bb->Integral()),"");
*/
    TH1D* h_ttH_nonbb = GetHist(f_ttH_nonbb,HistName,x_ttH_nonbb,Luminosity_ee);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_ttH_nonbb->Add(GetHist(f_ttH_nonbb,HistName,x_ttH_nonbb,Luminosity));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_ttH_nonbb->Add(GetHist(f_ttH_nonbb,HistName,x_ttH_nonbb,Luminosity));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_ttH_nonbb->SetFillColor(kAzure+7);
    h_stack->Add(h_ttH_nonbb);
    legend1->AddEntry(h_ttH_nonbb, "TTbar+H (H->nonbb)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttH_nonbb->Integral()),"");
/*
    TH1D* h_ttbb = GetHist(f_ttbb,HistName,x_ttbb,Luminosity);
    h_ttbb->SetFillColor(kAzure);
    h_stack->Add(h_ttbb);
    legend1->AddEntry(h_ttbb, "TTbar+bb", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttbb->Integral()),"");
*/
    legend1->AddEntry((TObject*)0,"TopPair + V","");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttW->Integral()+h_ttZ_1to10->Integral()+h_ttZ_10->Integral()+h_ttH_nonbb->Integral()),"");

    // TT + VV
    TH1D* h_ttWW = GetHist(f_ttWW,HistName,x_ttWW,Luminosity_ee);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_ttWW->Add(GetHist(f_ttWW,HistName,x_ttWW,Luminosity));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_ttWW->Add(GetHist(f_ttWW,HistName,x_ttWW,Luminosity));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_ttWW->SetFillColor(kCyan);
    h_stack->Add(h_ttWW);
    legend1->AddEntry(h_ttWW, "TTbar+WW", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttWW->Integral()),"");

    TH1D* h_ttWZ = GetHist(f_ttWZ,HistName,x_ttWZ,Luminosity_ee);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_ttWZ->Add(GetHist(f_ttWZ,HistName,x_ttWZ,Luminosity));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_ttWZ->Add(GetHist(f_ttWZ,HistName,x_ttWZ,Luminosity));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_ttWZ->SetFillColor(kCyan);
    h_stack->Add(h_ttWZ);
    legend1->AddEntry(h_ttWZ, "TTbar+WZ", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttWZ->Integral()),"");

    TH1D* h_ttWH = GetHist(f_ttWH,HistName,x_ttWH,Luminosity_ee);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_ttWH->Add(GetHist(f_ttWH,HistName,x_ttWH,Luminosity));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_ttWH->Add(GetHist(f_ttWH,HistName,x_ttWH,Luminosity));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_ttWH->SetFillColor(kCyan);
    h_stack->Add(h_ttWH);
    legend1->AddEntry(h_ttWH, "TTbar+WH", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttWH->Integral()),"");

    TH1D* h_ttZZ = GetHist(f_ttZZ,HistName,x_ttZZ,Luminosity_ee);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_ttZZ->Add(GetHist(f_ttZZ,HistName,x_ttZZ,Luminosity));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_ttZZ->Add(GetHist(f_ttZZ,HistName,x_ttZZ,Luminosity));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_ttZZ->SetFillColor(kCyan);
    h_stack->Add(h_ttZZ);
    legend1->AddEntry(h_ttZZ, "TTbar+ZZ", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttZZ->Integral()),"");

    TH1D* h_ttZH = GetHist(f_ttZH,HistName,x_ttZH,Luminosity_ee);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_ttZH->Add(GetHist(f_ttZH,HistName,x_ttZH,Luminosity));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_ttZH->Add(GetHist(f_ttZH,HistName,x_ttZH,Luminosity));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_ttZH->SetFillColor(kCyan);
    h_stack->Add(h_ttZH);
    legend1->AddEntry(h_ttZH, "TTbar+ZH", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttZH->Integral()),"");

    TH1D* h_ttHH = GetHist(f_ttHH,HistName,x_ttHH,Luminosity_ee);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_ttHH->Add(GetHist(f_ttHH,HistName,x_ttHH,Luminosity));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_ttHH->Add(GetHist(f_ttHH,HistName,x_ttHH,Luminosity));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_ttHH->SetFillColor(kCyan);
    h_stack->Add(h_ttHH);
    legend1->AddEntry(h_ttHH, "TTbar+HH", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttHH->Integral()),"");

    legend1->AddEntry((TObject*)0,"TopPair + VV","");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttWW->Integral()+h_ttWZ->Integral()+h_ttWH->Integral()+h_ttZZ->Integral()+h_ttZH->Integral()+h_ttHH->Integral()),"");

    // X + Gamma
    TH1D* h_ttG_dl = GetHist(f_ttG_dl,HistName,x_ttG_dl,Luminosity_ee);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_ttG_dl->Add(GetHist(f_ttG_dl,HistName,x_ttG_dl,Luminosity));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_ttG_dl->Add(GetHist(f_ttG_dl,HistName,x_ttG_dl,Luminosity));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_ttG_dl->SetFillColor(kGreen);
    h_stack->Add(h_ttG_dl);
    legend1->AddEntry(h_ttG_dl, "TTbar+#gamma (Di-Lepton)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttG_dl->Integral()),"");

    TH1D* h_ttG_slt = GetHist(f_ttG_slt,HistName,x_ttG_slt,Luminosity_ee);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_ttG_slt->Add(GetHist(f_ttG_slt,HistName,x_ttG_slt,Luminosity));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_ttG_slt->Add(GetHist(f_ttG_slt,HistName,x_ttG_slt,Luminosity));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_ttG_slt->SetFillColor(kGreen);
    h_stack->Add(h_ttG_slt);
    legend1->AddEntry(h_ttG_slt, "TTbar+#gamma (T->LNu)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttG_slt->Integral()),"");

    TH1D* h_ttG_sltbar = GetHist(f_ttG_sltbar,HistName,x_ttG_sltbar,Luminosity_ee);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_ttG_sltbar->Add(GetHist(f_ttG_sltbar,HistName,x_ttG_sltbar,Luminosity));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_ttG_sltbar->Add(GetHist(f_ttG_sltbar,HistName,x_ttG_sltbar,Luminosity));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_ttG_sltbar->SetFillColor(kGreen);
    h_stack->Add(h_ttG_sltbar);
    legend1->AddEntry(h_ttG_sltbar, "TTbar+#gamma (Tbar->LNu)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttG_sltbar->Integral()),"");

    TH1D* h_TG = GetHist(f_TG,HistName,x_TG,Luminosity_ee);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_TG->Add(GetHist(f_TG,HistName,x_TG,Luminosity));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_TG->Add(GetHist(f_TG,HistName,x_TG,Luminosity));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_TG->SetFillColor(kGreen);
    h_stack->Add(h_TG);
    legend1->AddEntry(h_TG, "T+#gamma", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_TG->Integral()),"");

    TH1D* h_WGtoLNuG = GetHist(f_WGtoLNuG,HistName,x_WG,Luminosity_ee);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_WGtoLNuG->Add(GetHist(f_WGtoLNuG,HistName,x_WG,Luminosity));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_WGtoLNuG->Add(GetHist(f_WGtoLNuG,HistName,x_WG,Luminosity));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_WGtoLNuG->SetFillColor(kGreen);
    h_stack->Add(h_WGtoLNuG);
    legend1->AddEntry(h_WGtoLNuG, "W+#gamma (W->l#nu)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_WGtoLNuG->Integral()),"");

    TH1D* h_ZGto2LG = GetHist(f_ZGto2LG,HistName,x_ZG,Luminosity_ee);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_ZGto2LG->Add(GetHist(f_ZGto2LG,HistName,x_ZG,Luminosity));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_ZGto2LG->Add(GetHist(f_ZGto2LG,HistName,x_ZG,Luminosity));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_ZGto2LG->SetFillColor(kGreen);
    h_stack->Add(h_ZGto2LG);
    legend1->AddEntry(h_ZGto2LG, "Z+#gamma (Z->ll)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ZGto2LG->Integral()),"");

    legend1->AddEntry((TObject*)0,"X + #gamma","");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttG_dl->Integral()+h_ttG_slt->Integral()+h_ttG_sltbar->Integral()+h_TG->Integral()+h_WGtoLNuG->Integral()+h_ZGto2LG->Integral()),"");

    // Rare SM
    TH1D* h_tZq = GetHist(f_tZq,HistName,x_tZq,Luminosity_ee);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_tZq->Add(GetHist(f_tZq,HistName,x_tZq,Luminosity));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_tZq->Add(GetHist(f_tZq,HistName,x_tZq,Luminosity));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_tZq->SetFillColor(kViolet);
    h_stack->Add(h_tZq);
    legend1->AddEntry(h_tZq, "TZq", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_tZq->Integral()),"");

    TH1D* h_tttW = GetHist(f_tttW,HistName,x_tttW,Luminosity_ee);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_tttW->Add(GetHist(f_tttW,HistName,x_tttW,Luminosity));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_tttW->Add(GetHist(f_tttW,HistName,x_tttW,Luminosity));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_tttW->SetFillColor(kViolet);
    h_stack->Add(h_tttW);
    legend1->AddEntry(h_tttW, "TTT+W", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_tttW->Integral()),"");

    TH1D* h_tttJ = GetHist(f_tttJ,HistName,x_tttJ,Luminosity_ee);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_tttJ->Add(GetHist(f_tttJ,HistName,x_tttJ,Luminosity));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_tttJ->Add(GetHist(f_tttJ,HistName,x_tttJ,Luminosity));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_tttJ->SetFillColor(kViolet);
    h_stack->Add(h_tttJ);
    legend1->AddEntry(h_tttJ, "TTT+jets", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_tttJ->Integral()),"");

    TH1D* h_WW = GetHist(f_WW,HistName,x_WW,Luminosity_ee);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_WW->Add(GetHist(f_WW,HistName,x_WW,Luminosity));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_WW->Add(GetHist(f_WW,HistName,x_WW,Luminosity));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_WW->SetFillColor(kViolet);
    h_stack->Add(h_WW);
    legend1->AddEntry(h_WW, "WW (WW->ll#nu#nu)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_WW->Integral()),"");

    TH1D* h_WZ = GetHist(f_WZ,HistName,x_WZ,Luminosity_ee);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_WZ->Add(GetHist(f_WZ,HistName,x_WZ,Luminosity));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_WZ->Add(GetHist(f_WZ,HistName,x_WZ,Luminosity));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_WZ->SetFillColor(kViolet);
    h_stack->Add(h_WZ);
    legend1->AddEntry(h_WZ, "WZ (WZ->lll#nu)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_WZ->Integral()),"");

    TH1D* h_ZZ = GetHist(f_ZZ,HistName,x_ZZ,Luminosity_ee);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_ZZ->Add(GetHist(f_ZZ,HistName,x_ZZ,Luminosity));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_ZZ->Add(GetHist(f_ZZ,HistName,x_ZZ,Luminosity));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_ZZ->SetFillColor(kViolet);
    h_stack->Add(h_ZZ);
    legend1->AddEntry(h_ZZ, "ZZ (ZZ->llll)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ZZ->Integral()),"");

    TH1D* h_WpWpQCD = GetHist(f_WpWpQCD,HistName,x_WpWpQCD,Luminosity_ee);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_WpWpQCD->Add(GetHist(f_WpWpQCD,HistName,x_WpWpQCD,Luminosity));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_WpWpQCD->Add(GetHist(f_WpWpQCD,HistName,x_WpWpQCD,Luminosity));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_WpWpQCD->SetFillColor(kViolet);
    h_stack->Add(h_WpWpQCD);
    legend1->AddEntry(h_WpWpQCD, "W+W+ (QCD)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_WpWpQCD->Integral()),"");

    TH1D* h_WpWpEWK = GetHist(f_WpWpEWK,HistName,x_WpWpEWK,Luminosity_ee);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_WpWpEWK->Add(GetHist(f_WpWpEWK,HistName,x_WpWpEWK,Luminosity));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_WpWpEWK->Add(GetHist(f_WpWpEWK,HistName,x_WpWpEWK,Luminosity));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_WpWpEWK->SetFillColor(kViolet);
    h_stack->Add(h_WpWpEWK);
    legend1->AddEntry(h_WpWpEWK, "W+W+ (EWK)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_WpWpEWK->Integral()),"");

    TH1D* h_WWG = GetHist(f_WWG,HistName,x_WWG,Luminosity_ee);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_WWG->Add(GetHist(f_WWG,HistName,x_WWG,Luminosity));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_WWG->Add(GetHist(f_WWG,HistName,x_WWG,Luminosity));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_WWG->SetFillColor(kViolet);
    h_stack->Add(h_WWG);
    legend1->AddEntry(h_WWG, "WW+#gamma", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_WWG->Integral()),"");

    TH1D* h_WZG = GetHist(f_WZG,HistName,x_WZG,Luminosity_ee);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_WZG->Add(GetHist(f_WZG,HistName,x_WZG,Luminosity));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_WZG->Add(GetHist(f_WZG,HistName,x_WZG,Luminosity));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_WZG->SetFillColor(kViolet);
    h_stack->Add(h_WZG);
    legend1->AddEntry(h_WZG, "WZ+#gamma", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_WZG->Integral()),"");

    TH1D* h_WWW = GetHist(f_WWW,HistName,x_WWW,Luminosity_ee);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_WWW->Add(GetHist(f_WWW,HistName,x_WWW,Luminosity));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_WWW->Add(GetHist(f_WWW,HistName,x_WWW,Luminosity));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_WWW->SetFillColor(kViolet);
    h_stack->Add(h_WWW);
    legend1->AddEntry(h_WWW, "WWW", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_WWW->Integral()),"");

    TH1D* h_WWZ = GetHist(f_WWZ,HistName,x_WWZ,Luminosity_ee);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_WWZ->Add(GetHist(f_WWZ,HistName,x_WWZ,Luminosity));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_WWZ->Add(GetHist(f_WWZ,HistName,x_WWZ,Luminosity));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_WWZ->SetFillColor(kViolet);
    h_stack->Add(h_WWZ);
    legend1->AddEntry(h_WWZ, "WWZ", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_WWZ->Integral()),"");

    TH1D* h_WZZ = GetHist(f_WZZ,HistName,x_WZZ,Luminosity_ee);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_WZZ->Add(GetHist(f_WZZ,HistName,x_WZZ,Luminosity));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_WZZ->Add(GetHist(f_WZZ,HistName,x_WZZ,Luminosity));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_WZZ->SetFillColor(kViolet);
    h_stack->Add(h_WZZ);
    legend1->AddEntry(h_WZZ, "WZZ", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_WZZ->Integral()),"");

    TH1D* h_ZZZ = GetHist(f_ZZZ,HistName,x_ZZZ,Luminosity_ee);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_ZZZ->Add(GetHist(f_ZZZ,HistName,x_ZZZ,Luminosity));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_ZZZ->Add(GetHist(f_ZZZ,HistName,x_ZZZ,Luminosity));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_ZZZ->SetFillColor(kViolet);
    h_stack->Add(h_ZZZ);
    legend1->AddEntry(h_ZZZ, "ZZZ", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ZZZ->Integral()),"");

    TH1D* h_GluGluH = GetHist(f_GluGluH,HistName,x_GGH,Luminosity_ee);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_GluGluH->Add(GetHist(f_GluGluH,HistName,x_GGH,Luminosity));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_GluGluH->Add(GetHist(f_GluGluH,HistName,x_GGH,Luminosity));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_GluGluH->SetFillColor(kViolet);
    h_stack->Add(h_GluGluH);
    legend1->AddEntry(h_GluGluH, "gg->H", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_GluGluH->Integral()),"");

    TH1D* h_VHToNonbb = GetHist(f_VHToNonbb,HistName,x_VH,Luminosity_ee);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_VHToNonbb->Add(GetHist(f_VHToNonbb,HistName,x_VH,Luminosity));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_VHToNonbb->Add(GetHist(f_VHToNonbb,HistName,x_VH,Luminosity));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_VHToNonbb->SetFillColor(kViolet);
    h_stack->Add(h_VHToNonbb);
    legend1->AddEntry(h_VHToNonbb, "H+X (H->nonbb)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_VHToNonbb->Integral()),"");

    legend1->AddEntry((TObject*)0,"Rare SM","");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_tZq->Integral()+h_tttW->Integral()+h_tttJ->Integral()+h_WW->Integral()+h_WWG->Integral()+h_WZ->Integral()+h_WZG->Integral()+h_ZZ->Integral()+h_WpWpQCD->Integral()+h_WpWpEWK->Integral()+h_WWW->Integral()+h_WWZ->Integral()+h_WZZ->Integral()+h_ZZZ->Integral()+h_GluGluH->Integral()+h_VHToNonbb->Integral()),"");

    // non Prompt Lepton
    if(DataDriven){
    TH1D* h_DataDriven = GetHist(f_DoubleEG_Run2016_TL,HistName,1,1,true);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_DataDriven->Add(GetHist(f_DoubleMuon_Run2016_TL,HistName,1,1,true));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_DataDriven->Add(GetHist(f_MuonEG_Run2016_TL,HistName,1,1,true));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_DataDriven->SetFillColor(kGray);
    double temp_weight = (double)(h_data->Integral()) - (double)(((TH1D*)h_stack->GetStack()->Last())->Integral());
    if(temp_weight < 0) temp_weight = 0;
    h_DataDriven->Scale(temp_weight/h_DataDriven->Integral());
    
    legend1->AddEntry(h_DataDriven,"non Prompt Lepton","f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_DataDriven->Integral()),"");
    } else {
    TH1D* h_ttbg = GetHist(f_TT,HistName,x_TT,Luminosity_ee);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_ttbg->Add(GetHist(f_TT,HistName,x_TT,Luminosity));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_ttbg->Add(GetHist(f_TT,HistName,x_TT,Luminosity));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_ttbg->SetFillColor(kGray);
    h_stack->Add(h_ttbg);
    legend1->AddEntry(h_ttbg, "TTbar", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttbg->Integral()),"");
/*
    TH1D* h_SingleTop_s = GetHist(f_SingleTop_s,HistName,x_ST_s,Luminosity);
    h_SingleTop_s->SetFillColor(kGray);
    h_stack->Add(h_SingleTop_s);
    legend1->AddEntry(h_SingleTop_s, "s-channel T (leptonic)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_SingleTop_s->Integral()),"");

    TH1D* h_SingleTop_t = GetHist(f_SingleTop_t,HistName,x_ST_t,Luminosity);
    h_SingleTop_t->SetFillColor(kGray);
    h_stack->Add(h_SingleTop_t);
    legend1->AddEntry(h_SingleTop_t, "t-channel T (leptonic)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_SingleTop_t->Integral()),"");

    TH1D* h_SingleTbar_t = GetHist(f_SingleTbar_t,HistName,x_STbar_t,Luminosity);
    h_SingleTbar_t->SetFillColor(kGray);
    h_stack->Add(h_SingleTbar_t);
    legend1->AddEntry(h_SingleTbar_t, "t-channel Tbar (leptonic)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_SingleTbar_t->Integral()),"");
*/
    TH1D* h_SingleTop_tW = GetHist(f_SingleTop_tW,HistName,x_ST_tW,Luminosity_ee);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_SingleTop_tW->Add(GetHist(f_SingleTop_tW,HistName,x_ST_tW,Luminosity));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_SingleTop_tW->Add(GetHist(f_SingleTop_tW,HistName,x_ST_tW,Luminosity));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_SingleTop_tW->SetFillColor(kGray);
    h_stack->Add(h_SingleTop_tW);
    legend1->AddEntry(h_SingleTop_tW, "t-channel T+W", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_SingleTop_tW->Integral()),"");

    TH1D* h_SingleTbar_tW = GetHist(f_SingleTbar_tW,HistName,x_STbar_tW,Luminosity_ee);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_SingleTbar_tW->Add(GetHist(f_SingleTbar_tW,HistName,x_STbar_tW,Luminosity));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_SingleTbar_tW->Add(GetHist(f_SingleTbar_tW,HistName,x_STbar_tW,Luminosity));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_SingleTbar_tW->SetFillColor(kGray);
    h_stack->Add(h_SingleTbar_tW);
    legend1->AddEntry(h_SingleTbar_tW, "t-channel Tbar+W", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_SingleTbar_tW->Integral()),"");

    TH1D* h_DYJets_10to50 = GetHist(f_DYJets_10to50,HistName,x_DY_10to50,Luminosity_ee);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_DYJets_10to50->Add(GetHist(f_DYJets_10to50,HistName,x_DY_10to50,Luminosity));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_DYJets_10to50->Add(GetHist(f_DYJets_10to50,HistName,x_DY_10to50,Luminosity));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_DYJets_10to50->SetFillColor(kGray);
    h_stack->Add(h_DYJets_10to50);
    legend1->AddEntry(h_DYJets_10to50, "Drell-Yan (Z/#gamma->ll, M10to50)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_DYJets_10to50->Integral()),"");

    TH1D* h_DYJets = GetHist(f_DYJets,HistName,x_DY,Luminosity_ee);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_DYJets->Add(GetHist(f_DYJets,HistName,x_DY,Luminosity));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_DYJets->Add(GetHist(f_DYJets,HistName,x_DY,Luminosity));
    HistName.replace(HistName.find("_em_"),4,"_ee_");
    h_DYJets->SetFillColor(kGray);
    h_stack->Add(h_DYJets);
    legend1->AddEntry(h_DYJets, "Drell-Yan (Z/#gamma->ll, M50)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_DYJets->Integral()),"");

    TH1D* h_WJets = GetHist(f_WJets,HistName,x_WJ,Luminosity_ee);
    HistName.replace(HistName.find("_ee_"),4,"_mm_");
    h_WJets->Add(GetHist(f_WJets,HistName,x_WJ,Luminosity));
    HistName.replace(HistName.find("_mm_"),4,"_em_");
    h_WJets->Add(GetHist(f_WJets,HistName,x_WJ,Luminosity));
    h_WJets->SetFillColor(kGray);
    h_stack->Add(h_WJets);
    legend1->AddEntry(h_WJets, "W+jets (W->l#nu)", "f");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_WJets->Integral()),"");

    legend1->AddEntry((TObject*)0,"non Prompt Lepton","");
    legend1->AddEntry((TObject*)0,Form("%.3f",h_ttbg->Integral()+h_SingleTop_tW->Integral()+h_SingleTbar_tW->Integral()+h_DYJets_10to50->Integral()+h_DYJets->Integral()+h_WJets->Integral()),"");
    }

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

    dummy_mc->SetFillStyle(3244);
    dummy_mc->SetFillColor(kBlack);

    dummy_mcE->SetFillStyle(3244);
    dummy_mcE->SetFillColor(kBlack);

    pad1->cd();
    pad1->Clear();

    if(log_y){
    pad1->SetLogy();
    if(DataMax > 0) {h_stack->SetMaximum(DataMax*100);}
    else h_stack->SetMaximum(dummy_mc->GetMaximum()*100);

    SigMin /= 100;
    if(SigMin > 1) h_stack->SetMinimum(1);
    else if(SigMin > 0.1) h_stack->SetMinimum(0.1);
    else if(SigMin > 0.01) h_stack->SetMinimum(0.01);
    else h_stack->SetMinimum(0.001);
    } else{
    if(DataMax > dummy_mc->GetMaximum()) {h_stack->SetMaximum(DataMax*1.3);}
    else h_stack->SetMaximum(dummy_mc->GetMaximum()*1.3);
    }

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

    HistName.replace(HistName.find("_em_"),4,"_ALL_");
    c_test->SaveAs(Form("%s/ControlPlots/%s.png",rootpath_sig.c_str(),HistName.c_str()));

//    delete h_stack; delete h_data; delete h_sig; delete h_ttttbg;
//    delete h_ttbg; delete h_ttW; /*delete h_ttZ;*/ delete h_ttZ_1to10; delete h_ttZ_10; /*delete h_ttH_bb;*/ delete h_ttH_nonbb; /*delete h_ttbb;*/
//    delete h_ttG_dl; delete h_ttG_slt; delete h_ttG_sltbar;
//    delete h_ttWW; delete h_ttWZ; delete h_ttWH; delete h_ttZZ; delete h_ttZH; delete h_ttHH;
//    /*delete h_SingleTop_s; delete h_SingleTop_t; delete h_SingleTbar_t;*/ delete h_SingleTop_tW; delete h_SingleTbar_tW;
//    delete h_TG; delete h_tZq;
//    delete h_tttW; delete h_tttJ;
//    delete h_DYJets; delete h_DYJets_10to50; delete h_WJets; delete h_WGtoLNuG; delete h_ZGto2LG;
//    delete h_WW; delete h_WWG; delete h_WZ; delete h_WZG; delete h_ZZ; delete h_WpWpEWK; delete h_WpWpQCD;
//    delete h_WWW; delete h_WWZ; delete h_WZZ; delete h_ZZZ;
//    delete h_GluGluH; delete h_VHToNonbb;

    delete c_test;

    }
}

