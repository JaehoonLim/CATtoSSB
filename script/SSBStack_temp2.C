#include "SSBStack_temp.h"

void SSBStack_temp2(){

    string rootpath = "Output/170602";
    double Luminosity = 36.455;
    string HistName = "";
    string HistTitle = "";

    double SigMax,DataMax;
    setTDRStyle();
    gStyle->SetMarkerSize(1.2);
    gStyle->SetPalette(1);
    gStyle->SetPadLeftMargin(0.15);
    gStyle->SetPadRightMargin(0.05);
    gStyle->SetTitleOffset(1.8,"y");

    TCanvas* c_test = new TCanvas("c_test","c_test",800,800);
    TPad *pad1 = new TPad("pad1","histos",0.,0.3,1.,1.);
    pad1->SetBottomMargin(0.0);
    TPad *pad2 = new TPad("pad2","ratio",0.,0.,1.,0.3);
    pad2->SetTopMargin(0.0);
    pad2->SetBottomMargin(0.35);
    pad1->Draw();
    pad2->Draw();

    // data
    TFile* f_DoubleEG_Run2016 = new TFile(Form("%s/DoubleEG_Run2016.root",rootpath.c_str()));
    TFile* f_DoubleMuon_Run2016 = new TFile(Form("%s/DoubleMuon_Run2016.root",rootpath.c_str()));
    TFile* f_MuonEG_Run2016 = new TFile(Form("%s/MuonEG_Run2016.root",rootpath.c_str()));
    TFile* f_DoubleEG_nonprompt = new TFile(Form("%s/DoubleEG_nonprompt.root",rootpath.c_str()));
    TFile* f_DoubleMuon_nonprompt = new TFile(Form("%s/DoubleMuon_nonprompt.root",rootpath.c_str()));
    TFile* f_MuonEG_nonprompt = new TFile(Form("%s/MuonEG_nonprompt.root",rootpath.c_str()));
    // TTTT
    TFile* f_TTTT_Signal = new TFile(Form("%s/TTTT_Signal.root",rootpath.c_str()));
    TFile* f_TTTT_Others = new TFile(Form("%s/TTTT_Others.root",rootpath.c_str()));
    // TT + X
    TFile* f_TT = new TFile(Form("%s/TT.root",rootpath.c_str()));
    //TFile* f_ttW = new TFile(Form("%s/ttW.root",rootpath.c_str()));
    TFile* f_ttW = new TFile(Form("%s/ttWToLNu.root",rootpath.c_str()));
    TFile* f_ttZ = new TFile(Form("%s/ttZ.root",rootpath.c_str()));
    TFile* f_ttZ_1to10 = new TFile(Form("%s/ttZToLL_M-1to10.root",rootpath.c_str()));
    //TFile* f_ttH_bb = new TFile(Form("%s/ttH_bb.root",rootpath.c_str()));
    TFile* f_ttH_nonbb = new TFile(Form("%s/ttH_nonbb.root",rootpath.c_str()));
    //TFile* f_ttbb = new TFile(Form("%s/ttbb.root",rootpath.c_str()));
    // T + X
    //TFile* f_SingleTop_s = new TFile(Form("%s/SingleTop_s.root",rootpath.c_str()));
    //TFile* f_SingleTop_t = new TFile(Form("%s/SingleTop_t.root",rootpath.c_str()));
    //TFile* f_SingleTbar_t = new TFile(Form("%s/SingleTbar_t.root",rootpath.c_str()));
    TFile* f_SingleTop_tW = new TFile(Form("%s/SingleTop_tW.root",rootpath.c_str()));
    TFile* f_SingleTbar_tW = new TFile(Form("%s/SingleTbar_tW.root",rootpath.c_str()));
    // Boson + X
    TFile* f_DYJets = new TFile(Form("%s/DYJets.root",rootpath.c_str()));
    //TFile* f_DYJets = new TFile(Form("%s/DYJets_MG.root",rootpath.c_str()));
    TFile* f_DYJets_10to50 = new TFile(Form("%s/DYJets_MG_10to50.root",rootpath.c_str()));
    //TFile* f_WJets = new TFile(Form("%s/WJets.root",rootpath.c_str()));
    TFile* f_WJets = new TFile(Form("%s/WJets_MG.root",rootpath.c_str()));
    TFile* f_WGtoLNuG = new TFile(Form("%s/WGtoLNuG.root",rootpath.c_str()));
    TFile* f_ZGto2LG = new TFile(Form("%s/ZGto2LG.root",rootpath.c_str()));
    // Di-Boson + X
    //TFile* f_WW = new TFile(Form("%s/WW.root",rootpath.c_str()));
    TFile* f_WW = new TFile(Form("%s/WWTo2L2Nu.root",rootpath.c_str()));
    //TFile* f_WZ = new TFile(Form("%s/WZ.root",rootpath.c_str()));
    TFile* f_WZ = new TFile(Form("%s/WZTo3LNu.root",rootpath.c_str()));
    //TFile* f_ZZ = new TFile(Form("%s/ZZ.root",rootpath.c_str()));
    TFile* f_ZZ = new TFile(Form("%s/ZZTo4L.root",rootpath.c_str()));
    // Tri-Boson + X
    TFile* f_WWW = new TFile(Form("%s/WWW.root",rootpath.c_str()));
    //TFile* f_WWZ = new TFile(Form("%s/WWZ.root",rootpath.c_str()));
    TFile* f_WZZ = new TFile(Form("%s/WZZ.root",rootpath.c_str()));
    TFile* f_ZZZ = new TFile(Form("%s/ZZZ.root",rootpath.c_str()));
    //TFile* f_ = new TFile(Form("%s/.root",rootpath.c_str()));

    TFile* f_test = new TFile(Form("%s/TTTT_Signal.root",rootpath.c_str()));
    f_test->cd("SSBAnalyzer/SSBHist");
    TIter keylist(gDirectory->GetListOfKeys()); 
    TKey *key; 

    while ((key = (TKey*)keylist())) {
        THStack* h_stack = new THStack("h_stack","h_stack");
        HistName = key->GetName();
        HistTitle = HistName;
        TLegend *legend1 = new TLegend(.65,.85,1.00,0.98);
        legend1->SetNColumns(2);
        legend1->SetFillColor(0);
        legend1->SetTextSize(0.023);

        TH1D* h_data;
        TH1D* h_nonprompt;
        if(HistName.find("ee") != string::npos){h_data = GetHist(f_DoubleEG_Run2016,HistName,1,1,true); HistTitle.replace(HistTitle.find("_ee_"),4,"  (ee : CutStep "); h_nonprompt = GetHist(f_DoubleEG_nonprompt,HistName,1,1,true); Luminosity = 36.454;}
        else if(HistName.find("mm") != string::npos){h_data = GetHist(f_DoubleMuon_Run2016,HistName,1,1,true); HistTitle.replace(HistTitle.find("_mm_"),4,"  (#mu#mu : CutStep "); h_nonprompt = GetHist(f_DoubleMuon_nonprompt,HistName,1,1,true);}
        else if(HistName.find("em") != string::npos){h_data = GetHist(f_MuonEG_Run2016,HistName,1,1,true); HistTitle.replace(HistTitle.find("_em_"),4,"  (e#mu : CutStep "); h_nonprompt = GetHist(f_MuonEG_nonprompt,HistName,1,1,true);}
        else {cout << "ERROR" << endl; exit(0);}
        HistTitle += ")";
        h_data->SetMarkerStyle(20);
        h_data->SetLineWidth(3);
        DataMax = h_data->GetMaximum();

        TH1D* h_sig = GetHist(f_TTTT_Signal,HistName,0.009201,Luminosity);
        h_sig->SetFillColor(kRed);
        h_stack->Add(h_sig);
        SigMax = h_sig->GetMaximum();

        TH1D* h_ttttbg = GetHist(f_TTTT_Others,HistName,0.009201,Luminosity);
        h_ttttbg->SetFillColor(kRed+2);
        h_stack->Add(h_ttttbg);
        //legend1->AddEntry(h_ttttbg, "FourTops Others", "f");
        //legend1->AddEntry((TObject*)0,Form("%.3f",h_ttttbg->Integral()),"");

        TH1D* h_ttbg = GetHist(f_TT,HistName,831.76,Luminosity);
        h_ttbg->SetFillColor(kMagenta);
        h_stack->Add(h_ttbg);
        //legend1->AddEntry(h_ttbg, "TTbar", "f");
        //legend1->AddEntry((TObject*)0,Form("%.3f",h_ttbg->Integral()),"");

        //TH1D* h_ttW = GetHist(f_ttW,HistName,0.61,Luminosity);
        TH1D* h_ttW = GetHist(f_ttW,HistName,0.2043,Luminosity);
        h_ttW->SetFillColor(kMagenta);
        h_stack->Add(h_ttW);
        //legend1->AddEntry(h_ttW, "TTbar+W (W->l#nu)", "f");
        //legend1->AddEntry((TObject*)0,Form("%.3f",h_ttW->Integral()),"");

        TH1D* h_ttZ_1to10 = GetHist(f_ttZ_1to10,HistName,0.0493,Luminosity);
        h_ttZ_1to10->SetFillColor(kMagenta);
        h_stack->Add(h_ttZ_1to10);
        //legend1->AddEntry(h_ttZ_1to10, "TTbar+Z (Z->ll, M1to10)", "f");
        //legend1->AddEntry((TObject*)0,Form("%.3f",h_ttZ_1to10->Integral()),"");

        TH1D* h_ttZ = GetHist(f_ttZ,HistName,0.78,Luminosity);
        h_ttZ->SetFillColor(kMagenta);
        h_stack->Add(h_ttZ);
        //legend1->AddEntry(h_ttZ, "TTbar+Z", "f");
        //legend1->AddEntry((TObject*)0,Form("%.3f",h_ttZ->Integral()),"");
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
        //legend1->AddEntry(h_ttH_nonbb, "TTbar+H (H->nonbb)", "f");
        //legend1->AddEntry((TObject*)0,Form("%.3f",h_ttH_nonbb->Integral()),"");
/*
        TH1D* h_ttbb = GetHist(f_ttbb,HistName,13.93,Luminosity);
        h_ttbb->SetFillColor(kMagenta);
        h_stack->Add(h_ttbb);
        legend1->AddEntry(h_ttbb, "TTbar+bb", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_ttbb->Integral()),"");
*/
        //legend1->AddEntry((TObject*)0,"TopPair + X","");
        //legend1->AddEntry((TObject*)0,Form("%.3f",h_ttbg->Integral()+h_ttW->Integral()+h_ttZ_1to10->Integral()+h_ttZ->Integral()+h_ttH_nonbb->Integral()),"");
/*
        TH1D* h_SingleTop_s = GetHist(f_SingleTop_s,HistName,3.36,Luminosity);
        h_SingleTop_s->SetFillColor(kBlue);
        h_stack->Add(h_SingleTop_s);
        //legend1->AddEntry(h_SingleTop_s, "s-channel T (leptonic)", "f");
        //legend1->AddEntry((TObject*)0,Form("%.3f",h_SingleTop_s->Integral()),"");

        TH1D* h_SingleTop_t = GetHist(f_SingleTop_t,HistName,44.3,Luminosity);
        h_SingleTop_t->SetFillColor(kBlue);
        h_stack->Add(h_SingleTop_t);
        //legend1->AddEntry(h_SingleTop_t, "t-channel T (leptonic)", "f");
        //legend1->AddEntry((TObject*)0,Form("%.3f",h_SingleTop_t->Integral()),"");

        TH1D* h_SingleTbar_t = GetHist(f_SingleTbar_t,HistName,26.4,Luminosity);
        h_SingleTbar_t->SetFillColor(kBlue);
        h_stack->Add(h_SingleTbar_t);
        //legend1->AddEntry(h_SingleTbar_t, "t-channel Tbar (leptonic)", "f");
        //legend1->AddEntry((TObject*)0,Form("%.3f",h_SingleTbar_t->Integral()),"");
*/
        TH1D* h_SingleTop_tW = GetHist(f_SingleTop_tW,HistName,35.85,Luminosity);
        h_SingleTop_tW->SetFillColor(kBlue);
        h_stack->Add(h_SingleTop_tW);
        //legend1->AddEntry(h_SingleTop_tW, "t-channel T+W", "f");
        //legend1->AddEntry((TObject*)0,Form("%.3f",h_SingleTop_tW->Integral()),"");

        TH1D* h_SingleTbar_tW = GetHist(f_SingleTbar_tW,HistName,35.85,Luminosity);
        h_SingleTbar_tW->SetFillColor(kBlue);
        h_stack->Add(h_SingleTbar_tW);
        //legend1->AddEntry(h_SingleTbar_tW, "t-channel Tbar+W", "f");
        //legend1->AddEntry((TObject*)0,Form("%.3f",h_SingleTbar_tW->Integral()),"");

        //legend1->AddEntry((TObject*)0,"SingleTop + X","");
        //legend1->AddEntry((TObject*)0,Form("%.3f",h_SingleTop_tW->Integral()+h_SingleTbar_tW->Integral()),"");

        TH1D* h_DYJets_10to50 = GetHist(f_DYJets_10to50,HistName,18610,Luminosity);
        h_DYJets_10to50->SetFillColor(kGreen);
        h_stack->Add(h_DYJets_10to50);
        //legend1->AddEntry(h_DYJets_10to50, "Drell-Yan (Z/#gamma->ll, M10to50)", "f");
        //legend1->AddEntry((TObject*)0,Form("%.3f",h_DYJets_10to50->Integral()),"");

        TH1D* h_DYJets = GetHist(f_DYJets,HistName,6025.2,Luminosity);
        h_DYJets->SetFillColor(kGreen);
        h_stack->Add(h_DYJets);
        //legend1->AddEntry(h_DYJets, "Drell-Yan (Z/#gamma->ll, M50)", "f");
        //legend1->AddEntry((TObject*)0,Form("%.3f",h_DYJets->Integral()),"");

        TH1D* h_WJets = GetHist(f_WJets,HistName,61526.7,Luminosity);
        h_WJets->SetFillColor(kGreen);
        h_stack->Add(h_WJets);
        //legend1->AddEntry(h_WJets, "W+jets (W->l#nu)", "f");
        //legend1->AddEntry((TObject*)0,Form("%.3f",h_WJets->Integral()),"");

        TH1D* h_WGtoLNuG = GetHist(f_WGtoLNuG,HistName,405.3,Luminosity);
        h_WGtoLNuG->SetFillColor(kGreen);
        h_stack->Add(h_WGtoLNuG);
        //legend1->AddEntry(h_WGtoLNuG, "W+#gamma (W->l#nu)", "f");
        //legend1->AddEntry((TObject*)0,Form("%.3f",h_WGtoLNuG->Integral()),"");

        TH1D* h_ZGto2LG = GetHist(f_ZGto2LG,HistName,117.7,Luminosity);
        h_ZGto2LG->SetFillColor(kGreen);
        h_stack->Add(h_ZGto2LG);
        //legend1->AddEntry(h_ZGto2LG, "Z+#gamma (Z->ll)", "f");
        //legend1->AddEntry((TObject*)0,Form("%.3f",h_ZGto2LG->Integral()),"");

        //legend1->AddEntry((TObject*)0,"SingleBoson + X","");
        //legend1->AddEntry((TObject*)0,Form("%.3f",h_DYJets_10to50->Integral()+h_DYJets->Integral()+h_WJets->Integral()+h_WGtoLNuG->Integral()+h_ZGto2LG->Integral()),"");

        //TH1D* h_WW = GetHist(f_WW,HistName,118.8,Luminosity);
        TH1D* h_WW = GetHist(f_WW,HistName,12.178,Luminosity);
        h_WW->SetFillColor(kAzure+10);
        h_stack->Add(h_WW);
        //legend1->AddEntry(h_WW, "WW (WW->ll#nu#nu)", "f");
        //legend1->AddEntry((TObject*)0,Form("%.3f",h_WW->Integral()),"");

        //TH1D* h_WZ = GetHist(f_WZ,HistName,47.3,Luminosity);
        TH1D* h_WZ = GetHist(f_WZ,HistName,4.42965,Luminosity);
        h_WZ->SetFillColor(kAzure+10);
        h_stack->Add(h_WZ);
        //legend1->AddEntry(h_WZ, "WZ (WZ->lll#nu)", "f");
        //legend1->AddEntry((TObject*)0,Form("%.3f",h_WZ->Integral()),"");

        //TH1D* h_ZZ = GetHist(f_ZZ,HistName,16.5,Luminosity);
        TH1D* h_ZZ = GetHist(f_ZZ,HistName,1.212,Luminosity);
        h_ZZ->SetFillColor(kAzure+10);
        h_stack->Add(h_ZZ);
        //legend1->AddEntry(h_ZZ, "ZZ (ZZ->llll)", "f");
        //legend1->AddEntry((TObject*)0,Form("%.3f",h_ZZ->Integral()),"");

        //legend1->AddEntry((TObject*)0,"Di-Boson + X","");
        //legend1->AddEntry((TObject*)0,Form("%.3f",h_WW->Integral()+h_WZ->Integral()+h_ZZ->Integral()),"");

        TH1D* h_WWW = GetHist(f_WWW,HistName,0.17,Luminosity);
        h_WWW->SetFillColor(kCyan-10);
        h_stack->Add(h_WWW);
        //legend1->AddEntry(h_WWW, "WWW", "f");
        //legend1->AddEntry((TObject*)0,Form("%.3f",h_WWW->Integral()),"");
/*
        TH1D* h_WWZ = GetHist(f_WWZ,HistName,0.17,Luminosity);
        h_WWZ->SetFillColor(kCyan-10);
        h_stack->Add(h_WWZ);
        //legend1->AddEntry(h_WWZ, "WWZ", "f");
        //legend1->AddEntry((TObject*)0,Form("%.3f",h_WWZ->Integral()),"");
*/
        TH1D* h_WZZ = GetHist(f_WZZ,HistName,0.06,Luminosity);
        h_WZZ->SetFillColor(kCyan-10);
        h_stack->Add(h_WZZ);
        //legend1->AddEntry(h_WZZ, "WZZ", "f");
        //legend1->AddEntry((TObject*)0,Form("%.3f",h_WZZ->Integral()),"");

        TH1D* h_ZZZ = GetHist(f_ZZZ,HistName,0.01,Luminosity);
        h_ZZZ->SetFillColor(kCyan-10);
        h_stack->Add(h_ZZZ);
        //legend1->AddEntry(h_ZZZ, "ZZZ", "f");
        //legend1->AddEntry((TObject*)0,Form("%.3f",h_ZZZ->Integral()),"");

        //legend1->AddEntry((TObject*)0,"Tri-Boson + X","");
        //legend1->AddEntry((TObject*)0,Form("%.3f",h_WWW->Integral()+h_WZZ->Integral()+h_ZZZ->Integral()),"");
/*
        TH1D* h_ = GetHist(".root",HistName,,Luminosity);
        h_->SetFillColor();
        h_stack->Add(h_);
        //legend1->AddEntry(h_, "", "f");
        //legend1->AddEntry((TObject*)0,Form("%.3f",h_->Integral()),"");
*/
        TH1D* dummy_back = (TH1D*) h_stack->GetStack()->Last();
        //legend1->AddEntry((TObject*)0, "Total BackGround", "");
        //legend1->AddEntry((TObject*)0,Form("%.3f",dummy_back->Integral()-h_sig->Integral()),"");
        //legend1->AddEntry(h_sig, "FourTops Signal", "f");
        //legend1->AddEntry((TObject*)0,Form("%.3f",h_sig->Integral()),"");
        //legend1->AddEntry(h_data, "Data expected", "lep");
        //legend1->AddEntry((TObject*)0,Form("%.0f",h_data->Integral()),"");

        h_stack->Add(h_sig);
        TH1D* dummy_mc = (TH1D*) h_stack->GetStack()->Last();
        h_data->Add(dummy_mc,-1);
        legend1->AddEntry(h_data, "Data - MC", "lp");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_data->Integral()),"");
        legend1->AddEntry(h_nonprompt, "Tight - Loose", "f");
        legend1->AddEntry((TObject*)0,Form("%.3f",h_nonprompt->GetEntries()),"");
        h_data->Scale(1./h_data->Integral());
        h_nonprompt->Scale(1./h_nonprompt->Integral());
        TH1D* dummy_data = (TH1D*) h_data->Clone("dummy_data");
        dummy_data->SetTitle("");
        dummy_data->GetYaxis()->SetTitle("(Data-MC) / (Tight-Loose)");
        dummy_data->Divide(h_nonprompt);
       
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

        pad1->cd();
        pad1->Clear();
/*
        pad1->SetLogy();
        SigMax /= 100;
        if(SigMax > 1) h_stack->SetMinimum(1);
        else if(SigMax > 0.1) h_stack->SetMinimum(0.1);
        else if(SigMax > 0.01) h_stack->SetMinimum(0.01);
        else h_stack->SetMinimum(0.001);
        h_stack->SetMaximum(DataMax*100);

        h_stack->SetTitle(HistTitle.c_str());
        h_stack->Draw("HIST");
        dummy_mc->Draw("E2SAME");*/
        DataMax = h_data->GetMaximum();
        if(DataMax < h_nonprompt->GetMaximum()) DataMax = h_nonprompt->GetMaximum();
        h_nonprompt->SetMaximum(DataMax*1.2);
        h_nonprompt->SetTitle(HistTitle.c_str());
        h_nonprompt->Draw("HIST");
        h_data->Draw("PESAME");
        legend1->Draw();

//        h_stack->GetXaxis()->SetLabelOffset(99); // remove x-axis label
        h_nonprompt->GetXaxis()->SetLabelOffset(99); // remove x-axis label
        c_test->Update();

        pad2->cd();

        dummy_data->SetMaximum(2.0);
        dummy_data->SetMinimum(0.0);
        dummy_data->Draw("PE1X0");
        TLine* line = new TLine();
        line->DrawLine(dummy_data->GetXaxis()->GetXmin(),1,dummy_data->GetXaxis()->GetXmax(),1);

        c_test->SaveAs(Form("%s/../170610/ControlPlots/%s.png",rootpath.c_str(),HistName.c_str()));

        delete h_nonprompt;
        delete h_stack; delete h_data; delete h_sig; delete h_ttttbg;
        delete h_ttbg; delete h_ttW; delete h_ttZ; delete h_ttZ_1to10; /*delete h_ttH_bb;*/ delete h_ttH_nonbb; /*delete h_ttbb;*/
        /*delete h_SingleTop_s; delete h_SingleTop_t; delete h_SingleTbar_t;*/ delete h_SingleTop_tW; delete h_SingleTbar_tW;
        delete h_DYJets; delete h_DYJets_10to50; delete h_WJets; delete h_WGtoLNuG; delete h_ZGto2LG;
        delete h_WW; delete h_WZ; delete h_ZZ;
        delete h_WWW; /*delete h_WWZ;*/ delete h_WZZ; delete h_ZZZ;

    }

}
