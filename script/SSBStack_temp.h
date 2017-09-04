#include "TStyle.h"

TH1D* GetHist(TFile* f_test, std::string HistName, double CrossSection, double Luminosity, bool isData=false){

    CrossSection *= 1000; //
    //TFile* f_test = new TFile(FileName.c_str());
    TH1D* h_gen = (TH1D*)f_test->Get("SSBAnalyzer/GenInfo");
    double NumEvents = (double)h_gen->GetBinContent(1);
    double EventsWeight = (double)h_gen->GetBinContent(2); 
    cout << fixed << setprecision(0);
    if(HistName =="numPV_ee_0a" || HistName =="numPV_mm_0a" || HistName =="numPV_em_0a" ) cout << HistName << " : " << "NumEvents : " << NumEvents << " / EventsWeight : " << EventsWeight << endl;
    if (isData) {EventsWeight = 1; CrossSection = 1;}
    TH1D* h_test = (TH1D*)f_test->Get(Form("SSBAnalyzer/SSBHist/%s",HistName.c_str()));
    if(h_test->GetNbinsX()>50) h_test->Rebin(h_test->GetNbinsX()/20);
    h_test->SetDirectory(0);
    //f_test->Close();
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
