#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>

#include <TMath.h>
#include <TH1.h>
#include <TH2.h>
#include <TH3.h>
#include <TF1.h>
#include <TFile.h>
#include <TTree.h>
#include <TCanvas.h>
#include <TGraph.h>
#include <TView.h>
#include <TView3D.h>
#include <TPolyLine3D.h>
#include <TPolyMarker3D.h>
#include <TRandom3.h>
#include <TStyle.h>
#include <TAxis.h>
#include <TGaxis.h>
#include <TLegend.h>
#include <TStopwatch.h>
#include <TVector3.h>
#include <TPrincipal.h>
#include <TTreeReader.h>
#include <TTreeReaderArray.h>
#include <TProfile.h>
#include <TProfile2D.h>
#include <TVirtualFFT.h>
#include <TSystem.h>
#include <TGraph2D.h>

using namespace std;

//TFile* fileHists = new TFile("SCE_hists_E250.root");
TFile* fileHists = new TFile("SCE_hists_E500.root");

//const Double_t E_nominal = 0.25; // MUST MATCH ABOVE FILE USED
const Double_t E_nominal = 0.5; // MUST MATCH ABOVE FILE USED

const double ModBoxA = 0.930; // recomb constant A used in LArG4 (DO NOT CHANGE)
const double ModBoxB = 0.212; // recomb constant B used in LArG4 (DO NOT CHANGE)
const double LAr_density = 1.3973; // LAr density (DO NOT CHANGE)

TH3F* TrueFwdX;
TH3F* TrueFwdY;
TH3F* TrueFwdZ;

TH3F* TrueBkwdX;
TH3F* TrueBkwdY;
TH3F* TrueBkwdZ;

TH3F* TrueEFieldMag;

void LoadHists();
double GetFwdOffset(double x_true, double y_true, double z_true, int comp);
double GetBkwdOffset(double x_reco, double y_reco, double z_reco, int comp);
double GetLocalEField(double x_true, double y_true, double z_true);

int main(int argc, char **argv)
{
  // Formatting Options for Plotting
  gErrorIgnoreLevel = kError;
  TGaxis::SetMaxDigits(2);
  Double_t stops[5] = {0.00,0.34,0.61,0.84,1.00};
  Double_t red[5] = {0.00,0.00,0.87,1.00,0.51};
  Double_t green[5] = {0.00,0.81,1.00,0.20,0.00};
  Double_t blue[5] = {0.51,1.00,0.12,0.00,0.00};
  TColor::CreateGradientColorTable(5,stops,red,green,blue,255);
  gStyle->SetNumberContours(255);
  gStyle->SetOptStat(0);

  // Load SCE Map Histograms
  LoadHists();

  //////////////////////////////////////////////////////////////////////////////////////
  // Example 1: Make Forward (Simulation) Spatial Offset 2D Plots at Central Z Slice
  //////////////////////////////////////////////////////////////////////////////////////

  TH2F* dX_YvsX_Fwd = new TH2F("dX_YvsX_Fwd","",101,-202.0,202.0,101,-202.0,202.0);
  TH2F* dY_YvsX_Fwd = new TH2F("dY_YvsX_Fwd","",101,-202.0,202.0,101,-202.0,202.0);

  for(int i = 1; i <= dX_YvsX_Fwd->GetNbinsX(); i++)
  {
    for(int j = 1; j <= dX_YvsX_Fwd->GetNbinsX(); j++)
    {
      dX_YvsX_Fwd->SetBinContent(i,j,GetFwdOffset(dX_YvsX_Fwd->GetXaxis()->GetBinCenter(i),dX_YvsX_Fwd->GetYaxis()->GetBinCenter(j),250.0,1));
    }
  }

  for(int i = 1; i <= dY_YvsX_Fwd->GetNbinsX(); i++)
  {
    for(int j = 1; j <= dY_YvsX_Fwd->GetNbinsX(); j++)
    {
      dY_YvsX_Fwd->SetBinContent(i,j,GetFwdOffset(dY_YvsX_Fwd->GetXaxis()->GetBinCenter(i),dY_YvsX_Fwd->GetYaxis()->GetBinCenter(j),250.0,2));
    }
  }

  TCanvas canv_Fwd_XY_DX("canv_Fwd_XY_DX","",600,550);
  canv_Fwd_XY_DX.cd();
  dX_YvsX_Fwd->SetTitle("Sim. #DeltaX [cm]:  ^{}Z_{true} = 250 cm");
  dX_YvsX_Fwd->GetXaxis()->SetTitle("X_{true} [cm]");
  dX_YvsX_Fwd->GetXaxis()->SetTitleOffset(1.1);
  dX_YvsX_Fwd->GetXaxis()->SetTitleSize(0.04);
  dX_YvsX_Fwd->GetXaxis()->SetNoExponent(kTRUE);
  dX_YvsX_Fwd->GetYaxis()->SetTitle("Y_{true} [cm]");
  dX_YvsX_Fwd->GetYaxis()->SetTitleOffset(1.4);
  dX_YvsX_Fwd->GetYaxis()->SetTitleSize(0.04);
  dX_YvsX_Fwd->GetYaxis()->SetNoExponent(kTRUE);
  dX_YvsX_Fwd->GetZaxis()->SetLabelSize(0.035);
  dX_YvsX_Fwd->GetZaxis()->SetNoExponent(kTRUE);
  dX_YvsX_Fwd->SetStats(0);
  dX_YvsX_Fwd->Draw("COLZ");
  gPad->SetLeftMargin(0.12);
  gPad->SetRightMargin(0.12);
  canv_Fwd_XY_DX.SaveAs("dX_YvsX_Fwd.png");

  TCanvas canv_Fwd_XY_DY("canv_Fwd_XY_DY","",600,550);
  canv_Fwd_XY_DY.cd();
  dY_YvsX_Fwd->SetTitle("Sim. #DeltaY [cm]:  ^{}Z_{true} = 250 cm");
  dY_YvsX_Fwd->GetXaxis()->SetTitle("X_{true} [cm]");
  dY_YvsX_Fwd->GetXaxis()->SetTitleOffset(1.1);
  dY_YvsX_Fwd->GetXaxis()->SetTitleSize(0.04);
  dY_YvsX_Fwd->GetXaxis()->SetNoExponent(kTRUE);
  dY_YvsX_Fwd->GetYaxis()->SetTitle("Y_{true} [cm]");
  dY_YvsX_Fwd->GetYaxis()->SetTitleOffset(1.4);
  dY_YvsX_Fwd->GetYaxis()->SetTitleSize(0.04);
  dY_YvsX_Fwd->GetYaxis()->SetNoExponent(kTRUE);
  dY_YvsX_Fwd->GetZaxis()->SetLabelSize(0.035);
  dY_YvsX_Fwd->GetZaxis()->SetNoExponent(kTRUE);
  dY_YvsX_Fwd->SetStats(0);
  dY_YvsX_Fwd->Draw("COLZ");
  gPad->SetLeftMargin(0.12);
  gPad->SetRightMargin(0.12);
  canv_Fwd_XY_DY.SaveAs("dY_YvsX_Fwd.png");

  //////////////////////////////////////////////////////////////////////////////////////
  // Example 2: Make Backward (Calibration) Spatial Offset 2D Plots at Central Z Slice
  //////////////////////////////////////////////////////////////////////////////////////

  TH2F* dX_YvsX_Bkwd = new TH2F("dX_YvsX_Bkwd","",101,-202.0,202.0,101,-202.0,202.0);
  TH2F* dY_YvsX_Bkwd = new TH2F("dY_YvsX_Bkwd","",101,-202.0,202.0,101,-202.0,202.0);

  for(int i = 1; i <= dX_YvsX_Bkwd->GetNbinsX(); i++)
  {
    for(int j = 1; j <= dX_YvsX_Bkwd->GetNbinsX(); j++)
    {
      dX_YvsX_Bkwd->SetBinContent(i,j,GetBkwdOffset(dX_YvsX_Bkwd->GetXaxis()->GetBinCenter(i),dX_YvsX_Bkwd->GetYaxis()->GetBinCenter(j),250.0,1));
    }
  }

  for(int i = 1; i <= dY_YvsX_Bkwd->GetNbinsX(); i++)
  {
    for(int j = 1; j <= dY_YvsX_Bkwd->GetNbinsX(); j++)
    {
      dY_YvsX_Bkwd->SetBinContent(i,j,GetBkwdOffset(dY_YvsX_Bkwd->GetXaxis()->GetBinCenter(i),dY_YvsX_Bkwd->GetYaxis()->GetBinCenter(j),250.0,2));
    }
  }

  TCanvas canv_Bkwd_XY_DX("canv_Bkwd_XY_DX","",600,550);
  canv_Bkwd_XY_DX.cd();
  dX_YvsX_Bkwd->SetTitle("Calib. #DeltaX [cm]:  ^{}Z_{reco} = 250 cm");
  dX_YvsX_Bkwd->GetXaxis()->SetTitle("X_{reco} [cm]");
  dX_YvsX_Bkwd->GetXaxis()->SetTitleOffset(1.1);
  dX_YvsX_Bkwd->GetXaxis()->SetTitleSize(0.04);
  dX_YvsX_Bkwd->GetXaxis()->SetNoExponent(kTRUE);
  dX_YvsX_Bkwd->GetYaxis()->SetTitle("Y_{reco} [cm]");
  dX_YvsX_Bkwd->GetYaxis()->SetTitleOffset(1.4);
  dX_YvsX_Bkwd->GetYaxis()->SetTitleSize(0.04);
  dX_YvsX_Bkwd->GetYaxis()->SetNoExponent(kTRUE);
  dX_YvsX_Bkwd->GetZaxis()->SetLabelSize(0.035);
  dX_YvsX_Bkwd->GetZaxis()->SetNoExponent(kTRUE);
  dX_YvsX_Bkwd->SetStats(0);
  dX_YvsX_Bkwd->Draw("COLZ");
  gPad->SetLeftMargin(0.12);
  gPad->SetRightMargin(0.12);
  canv_Bkwd_XY_DX.SaveAs("dX_YvsX_Bkwd.png");

  TCanvas canv_Bkwd_XY_DY("canv_Bkwd_XY_DY","",600,550);
  canv_Bkwd_XY_DY.cd();
  dY_YvsX_Bkwd->SetTitle("Calib. #DeltaY [cm]:  ^{}Z_{reco} = 250 cm");
  dY_YvsX_Bkwd->GetXaxis()->SetTitle("X_{reco} [cm]");
  dY_YvsX_Bkwd->GetXaxis()->SetTitleOffset(1.1);
  dY_YvsX_Bkwd->GetXaxis()->SetTitleSize(0.04);
  dY_YvsX_Bkwd->GetXaxis()->SetNoExponent(kTRUE);
  dY_YvsX_Bkwd->GetYaxis()->SetTitle("Y_{reco} [cm]");
  dY_YvsX_Bkwd->GetYaxis()->SetTitleOffset(1.4);
  dY_YvsX_Bkwd->GetYaxis()->SetTitleSize(0.04);
  dY_YvsX_Bkwd->GetYaxis()->SetNoExponent(kTRUE);
  dY_YvsX_Bkwd->GetZaxis()->SetLabelSize(0.035);
  dY_YvsX_Bkwd->GetZaxis()->SetNoExponent(kTRUE);
  dY_YvsX_Bkwd->SetStats(0);
  dY_YvsX_Bkwd->Draw("COLZ");
  gPad->SetLeftMargin(0.12);
  gPad->SetRightMargin(0.12);
  canv_Bkwd_XY_DY.SaveAs("dY_YvsX_Bkwd.png");
  
  //////////////////////////////////////////////////////////////////////////////////////
  // Example 3: Plot Recombination Factor (for MIPs) in 2D at Central Z Slice
  //////////////////////////////////////////////////////////////////////////////////////

  TH2F* recomb_YvsX = new TH2F("recomb_YvsX","",101,-202.0,202.0,101,-202.0,202.0);
    
  const double dEdx = 2.1; // MIP dE/dx (in MeV/cm)

  for(int i = 1; i <= dX_YvsX_Fwd->GetNbinsX(); i++)
  {
    for(int j = 1; j <= dX_YvsX_Fwd->GetNbinsX(); j++)
    {
      double Xi = (ModBoxB * dEdx) / (LAr_density * GetLocalEField(recomb_YvsX->GetXaxis()->GetBinCenter(i),recomb_YvsX->GetYaxis()->GetBinCenter(j),250.0));
      double recomb = log(ModBoxA + Xi) / Xi;

      recomb_YvsX->SetBinContent(i,j,recomb);
    }
  }
    
  TCanvas canv_recomb("canv_recomb","",600,550);
  canv_recomb.cd();
  recomb_YvsX->SetTitle("Recomb. Factor:  ^{}Z_{true} = 250 cm");
  recomb_YvsX->GetXaxis()->SetTitle("X_{true} [cm]");
  recomb_YvsX->GetXaxis()->SetTitleOffset(1.1);
  recomb_YvsX->GetXaxis()->SetTitleSize(0.04);
  recomb_YvsX->GetXaxis()->SetNoExponent(kTRUE);
  recomb_YvsX->GetYaxis()->SetTitle("Y_{true} [cm]");
  recomb_YvsX->GetYaxis()->SetTitleOffset(1.4);
  recomb_YvsX->GetYaxis()->SetTitleSize(0.04);
  recomb_YvsX->GetYaxis()->SetNoExponent(kTRUE);
  recomb_YvsX->GetZaxis()->SetLabelSize(0.035);
  recomb_YvsX->GetZaxis()->SetNoExponent(kTRUE);
  recomb_YvsX->SetStats(0);
  recomb_YvsX->Draw("COLZ");
  gPad->SetLeftMargin(0.12);
  gPad->SetRightMargin(0.15);
  canv_recomb.SaveAs("recomb_YvsX.png");

  return 0;
}

void LoadHists()
{
  TrueFwdX = (TH3F*) fileHists->Get("TrueFwd_Displacement_X");
  TrueFwdY = (TH3F*) fileHists->Get("TrueFwd_Displacement_Y");
  TrueFwdZ = (TH3F*) fileHists->Get("TrueFwd_Displacement_Z");

  TrueBkwdX = (TH3F*) fileHists->Get("TrueBkwd_Displacement_X");
  TrueBkwdY = (TH3F*) fileHists->Get("TrueBkwd_Displacement_Y");
  TrueBkwdZ = (TH3F*) fileHists->Get("TrueBkwd_Displacement_Z");

  TrueEFieldMag = (TH3F*) fileHists->Get("True_ElecField_Mag");
}

double GetFwdOffset(double x_true, double y_true, double z_true, int comp)
{
  if(x_true < -199.999)
  {
    x_true = -199.999;
  }
  else if(x_true > 199.999)
  {
    x_true = 199.999;
  }

  if(y_true < -199.999)
  {
    y_true = -199.999;
  }
  else if(y_true > 199.999)
  {
    y_true = 199.999;
  }

  if(z_true < 0.001)
  {
    z_true = 0.001;
  }
  else if(z_true > 499.999)
  {
    z_true = 499.999;
  }

  double offset = 0.0;
  if(comp == 1)
  {
    offset = TrueFwdX->Interpolate(x_true,y_true,z_true);
  }
  else if(comp == 2)
  {
    offset = TrueFwdY->Interpolate(x_true,y_true,z_true);
  }
  else if(comp == 3)
  {
    offset = TrueFwdZ->Interpolate(x_true,y_true,z_true);
  }

  return offset;
}

double GetBkwdOffset(double x_reco, double y_reco, double z_reco, int comp)
{
  if(x_reco < -199.999)
  {
    x_reco = -199.999;
  }
  else if(x_reco > 199.999)
  {
    x_reco = 199.999;
  }

  if(y_reco < -199.999)
  {
    y_reco = -199.999;
  }
  else if(y_reco > 199.999)
  {
    y_reco = 199.999;
  }

  if(z_reco < 0.001)
  {
    z_reco = 0.001;
  }
  else if(z_reco > 499.999)
  {
    z_reco = 499.999;
  }

  double offset = 0.0;
  if(comp == 1)
  {
    offset = TrueBkwdX->Interpolate(x_reco,y_reco,z_reco);
  }
  else if(comp == 2)
  {
    offset = TrueBkwdY->Interpolate(x_reco,y_reco,z_reco);
  }
  else if(comp == 3)
  {
    offset = TrueBkwdZ->Interpolate(x_reco,y_reco,z_reco);
  }

  return offset;
}

double GetLocalEField(double x_true, double y_true, double z_true)
{
  if(x_true < -199.999)
  {
    x_true = -199.999;
  }
  else if(x_true > 199.999)
  {
    x_true = 199.999;
  }

  if(y_true < -199.999)
  {
    y_true = -199.999;
  }
  else if(y_true > 199.999)
  {
    y_true = 199.999;
  }

  if(z_true < 0.001)
  {
    z_true = 0.001;
  }
  else if(z_true > 499.999)
  {
    z_true = 499.999;
  }

  double Emag = E_nominal*(1.0+TrueEFieldMag->Interpolate(x_true,y_true,z_true));

  return Emag;
}
