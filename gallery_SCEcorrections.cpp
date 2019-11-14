//some standard C++ includes
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <chrono>
#include <cmath>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <numeric>  

//some ROOT includes
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
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBranch.h"

//"art" includes (canvas, and gallery)
#include "canvas/Utilities/InputTag.h"
#include "gallery/Event.h"
#include "gallery/ValidHandle.h"
#include "canvas/Persistency/Common/FindMany.h"
#include "canvas/Persistency/Common/FindOne.h"

//"larsoft" object includes
#include "lardataobj/RecoBase/OpFlash.h"
#include "lardataobj/RecoBase/OpHit.h"
#include "lardataobj/RawData/RawDigit.h"
#include "lardataobj/RecoBase/Hit.h"
#include "lardataobj/RecoBase/Track.h"
#include "lardataobj/AnalysisBase/T0.h"
#include "larcoreobj/SimpleTypesAndConstants/geo_types.h"
#include "larcoreobj/SimpleTypesAndConstants/RawTypes.h"
#include "lardataobj/Simulation/SimEnergyDeposit.h"
#include "nusimdata/SimulationBase/MCTruth.h"
#include "lardataobj/AnalysisBase/Calorimetry.h"

using namespace art;
using namespace std;
using namespace std::chrono;

//TFile* fileHists = new TFile("SCE_hists_E250.root");
TFile* fileHists = new TFile("SCE_hists_E500.root");
//TFile* fileHists = new TFile("SCE_hists_E250.root");

//Physics constants (and detector parameters)
const Double_t E_nominal = 0.5; // MUST MATCH ABOVE FILE USED (in V/mm)
//const Double_t E_nominal = 0.25; // MUST MATCH ABOVE FILE USED
const double ModBoxA = 0.930; // recomb constant A used in LArG4 (DO NOT CHANGE)
const double ModBoxB = 0.212; // recomb constant B used in LArG4 (DO NOT CHANGE)
const double LAr_density = 1.3973; // LAr density (DO NOT CHANGE)
const double drift_v = 160; //drift velocity at 500 V/cm is at 160 cm/ms
const double MIP_dEdx = 2.1; // MIP dE/dx (in MeV/cm)
const double electronlifetime = 3.0; //electron lifetime
//recombination for nominal E-Field
//do recombination correction
double Xi = (ModBoxB * MIP_dEdx) / (LAr_density * E_nominal);
const double recomb_nominal = log(ModBoxA + Xi) / Xi;

//These TH3 objects are loaded in the LoadHists() FUNction
TH3F* TrueFwdX;
TH3F* TrueFwdY;
TH3F* TrueFwdZ;
TH3F* TrueBkwdX;
TH3F* TrueBkwdY;
TH3F* TrueBkwdZ;
TH3F* TrueEFieldMag;
//Load up SCE correction tools
void LoadHists();
double GetFwdOffset(double x_true, double y_true, double z_true, int comp);
double GetBkwdOffset(double x_reco, double y_reco, double z_reco, int comp);
double GetLocalEField(double x_true, double y_true, double z_true);
//other user-defined functions
double anodeDist(double x);
double cathodeDist(double x);
double calcPitch(double x1, double y1, double z1, double x2, double y2, double z2);
double calcMedian(vector<float> values);
double calcMean(vector<float> values);
int getindex(float val, int lim[2], int nbins);

//Module Labels
string fCalorimetrymoduleLabel = "pandoraCalo"; //"pmatrackcalo"; //pandoraCalo

///////////////////////////////////////////////////////////////////////////////////////////////////
// MAIN FUNCTION
///////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[]){

  //Look at terminal input
  for (int i = 0; i < argc; ++i){
    cout << argv[i] << endl;
  }
  //Load SCE Maps
  LoadHists();
  //Control Variables
  const int maxEvents = 1000; //how many events to look at
  const int maxEventsPerRun = 1000; //how many events from each run
  const unsigned int maxHits = 5000000; //want to plot same number of hits for SCE/NON
  //be careful with the hit limit, especially with protons
  int totalEventCount = 0;
  int prevRun = -9999;
  int runEventCount = 0;
  int chanNum;
  unsigned int hitCount_sce = 0;
  unsigned int hitCount = 0;
  int trackCount_sce = 0;
  int trackCount = 0;

  //Read in input files from filelist.txt
  cout << "Reading files " << endl;
  vector<string> filenames;
  vector<string> filenames_sce;
  ifstream myfile("isotropicmuons_filelist.txt");
  ifstream myfile_sce("isotropicmuons_sce_filelist.txt");
  copy(istream_iterator<string>(myfile),istream_iterator<string>(),back_inserter(filenames));
  copy(istream_iterator<string>(myfile_sce),istream_iterator<string>(),back_inserter(filenames_sce));

  //setting boundaries for picky histograms
  int xlim[2] = {-200,200};
  int ylim[2] = {-200,200};
  int zlim[2] = {0,500};
  int cmperbin = 10;
  int nxbins = int((xlim[1]-xlim[0])/cmperbin);
  int nybins = int((ylim[1]-ylim[0])/cmperbin);
  int nzbins = int((zlim[1]-zlim[0])/cmperbin);

  //Instantiate output stuff
  TFile f_output("output.root","RECREATE");

  ////////////////////////////////////////////////////////////////
  ////DECLARE HISTOGRAMS
  ///////////////////////////////////////////////////////////////
  //TH2* hTracksxy = new TH2F("hTracksxy","tracks",nxbins,xlim[0],xlim[1],nybins,ylim[0],ylim[1]);
  //TH2* hTrackszy = new TH2F("hTrackszy","tracks",nzbins,zlim[0],zlim[1],nybins,ylim[0],ylim[1]);
  //TH2* hTrackszx = new TH2F("hTrackszx","tracks",nzbins,zlim[0],zlim[1],nxbins,xlim[0],xlim[1]);
  //TH3* h3points = new TH3F("h3points","space points", 50, xlim[0], xlim[1], 50, ylim[0], ylim[1], 60, zlim[0], zlim[1]);
  //TH3* h3points_sce = new TH3F("h3points_sce","space points sce", 50, xlim[0], xlim[1], 50, ylim[0], ylim[1], 60, zlim[0], zlim[1]);
  //dEdx isn't truthful here, but it's the corrections applied to dqdx in various ways
  //TH1* h1dEdx = new TH1F("h1dEdx","dEdx, No SCE, nominal corrections", 500,0,12000);
  //TH1* h1dEdx_noel = new TH1F("h1dEdx_noel","dEdx, No SCE, no el corrections", 500,0,12000);
  TH2* h2dEdx_rrange = new TH2F("h2dEdx_rrange", "dEdx vs residual range", 100,0,50,400,0,10000);
  //TH1* h1dEdx_sce = new TH1F("h1dEdx_sce","dEdx, SCE, nominal Corrections", 500,0,12000);
  //TH1* h1dEdx_sce_noel = new TH1F("h1dEdx_sce_noel","dEdx, SCE, no e-lifetime corr (or any)", 500,0,12000);
  //TH1* h1dEdx_sce_corrspat = new TH1F("h1dEdx_sce_corrspat","dEdx, SCE, SCE Spatial Corrections", 500,0,12000);
  //TH1* h1dEdx_sce_corrE = new TH1F("h1dEdx_sce_corrE","dEdx, SCE, SCE Energy Corrections", 500,0,12000);
  //TH1* h1dEdx_sce_corr = new TH1F("h1dEdx_sce_corr","dEdx, SCE, SCE Spatial and Energy Corrections", 500,0,12000);
  //TH1* h1dEdx_sce_corr_noel = new TH1F("h1dEdx_sce_corr_noel","dEdx, SCE, SCE Spatial and Energy Corrections (no e-lifetime)", 500,0,12000);
  //calodEdx means I am applying corrections to the native dedx values in anab::calorimetry
  TH1* h1calodEdx = new TH1F("h1calodEdx","native dEdx, no-sce",500,0,15);
  TH1* h1calodEdx_invel = new TH1F("h1calodEdx_invel","native dEdx, no-sce, inverse e-lifetime",500,0,15);
  TH1* h1calodEdx_noel = new TH1F("h1calodEdx_noel","native dEdx, no-sce, no e-lifetime",500,0,15);
  TH1* h1calodEdx_inverel = new TH1F("h1calodEdx_inverel","native dEdx, no-sce, inverted e-lifetime",500,0,15);
  TH1* h1calodEdx_sce = new TH1F("h1calodEdx_sce","native SCE dEdx values",500,0,15);
  TH1* h1calodEdx_sce_corr = new TH1F("h1calodEdx_sce_corr","correction to native dEdx, standard",500,0,15);
  TH1* h1calodEdx_sce_invel = new TH1F("h1calodEdx_sce_invel","SCE, inverted e-life, no SCE corr",500,0,15);
  TH1* h1calodEdx_sce_corr_invel = new TH1F("h1calodEdx_sce_corr_invel","correction to native SCE dEdx, inverse e-lifetime",500,0,15);
  TH1* h1calodEdx_sce_corr_noel = new TH1F("h1calodEdx_sce_corr_noel","correction to native SCE dEdx, no e-lifetime recomb)",500,0,15);
  //just to study variables of interest
  TH1* h1pitchratio = new TH1F("h1pitchratio","ratio of calc_pitch to inherent pitch",50,0,2);
  TH1* h1pitchratio_sce = new TH1F("h1pitchratio_sce","ratio of calc_pitch to inherent pitch with SCE on",50,0,2);
  TH1* h1calopitches = new TH1F("h1calopitches","what calo says the pitches are",100,0,1);

  TH1* h1recomb = new TH1F("h1recomb","recombination correction factors",100,0.9,1.1);
  TH1* h1recomb_prime = new TH1F("h1recomb_prime","recombination correction factors prime",100,0.9,1.1);
  //dedx as function of some spatial dimension
  int nbins = 100;
  TH1* h1dEdx_x = new TH1F("h1dEdx_x","dEdx(x), no-SCE",nbins,xlim[0],xlim[1]);
  TH1* h1dEdx_noel_x = new TH1F("h1dEdx_noel_x","dEdx(x), no-SCE, no e-lifetime",nbins,xlim[0],xlim[1]);
  TH1* h1dEdx_corr_x = new TH1F("h1dEdx_corr_x","dEdx(x), no-SCE, e-lifetime corr",nbins,xlim[0],xlim[1]);
  TH1* h1dEdx_invel_x = new TH1F("h1dEdx_invel_x","dEdx(x), no-SCE, inverted e-lifetime corr",nbins,xlim[0],xlim[1]);
  TH1* h1dEdx_inverel_x = new TH1F("h1dEdx_inverel_x","dEdx(x), no-SCE, cathode e-lifetime corr",nbins,xlim[0],xlim[1]);
  TH1* h1dEdx_sce_x = new TH1F("h1dEdx_sce_x","dEdx(x), SCE no corr",nbins,xlim[0],xlim[1]);
  TH1* h1dEdx_sce_corr_x = new TH1F("h1dEdx_sce_corr_x","dEdx(x), SCE full corr",nbins,xlim[0],xlim[1]);
  TH1* h1dEdx_sce_noel_x = new TH1F("h1dEdx_sce_noel_x","dEdx(x), SCE corr no e-lifetime",nbins,xlim[0],xlim[1]);
  
  TH1* h1dEdx_corr_y = new TH1F("h1dEdx_corr_y","dEdx(y), no-SCE",nbins,ylim[0],ylim[1]);
  TH1* h1dEdx_invel_y = new TH1F("h1dEdx_invel_y","dEdx(y), no-SCE, e-lifetime corr",nbins,ylim[0],ylim[1]);
  TH1* h1dEdx_y = new TH1F("h1dEdx_y","dEdx(y), no-SCE, inv e-lifetime corr",nbins,ylim[0],ylim[1]);
  TH1* h1dEdx_noel_y = new TH1F("h1dEdx_noel_y","dEdx(y), no-SCE, no e-lifetime corr",nbins,ylim[0],ylim[1]);
  TH1* h1dEdx_sce_y = new TH1F("h1dEdx_sce_y","dEdx(y), SCE no corr",nbins,ylim[0],ylim[1]);
  TH1* h1dEdx_sce_corr_y = new TH1F("h1dEdx_sce_corr_y","dEdx(y), SCE full corr",nbins,ylim[0],ylim[1]);
  TH1* h1dEdx_sce_noel_y = new TH1F("h1dEdx_sce_noel_y","dEdx(y), SCE corr no e-lifetime",nbins,ylim[0],ylim[1]);
  TH1* h1dEdx_z = new TH1F("h1dEdx_z","dEdx(z), no-SCE",nbins,zlim[0],zlim[1]);
  TH1* h1dEdx_noel_z = new TH1F("h1dEdx_noel_z","dEdx(z), no-SCE, no e-lifetime",nbins,zlim[0],zlim[1]);
  TH1* h1dEdx_corr_z = new TH1F("h1dEdx_corr_z","dEdx(z), no-SCE, e-lifetime corr",nbins,zlim[0],zlim[1]);
  TH1* h1dEdx_invel_z = new TH1F("h1dEdx_invel_z","dEdx(z), no-SCE, inv e-lifetime corr",nbins,zlim[0],zlim[1]);
  TH1* h1dEdx_sce_z = new TH1F("h1dEdx_sce_z","dEdx(z), SCE no corr",nbins,zlim[0],zlim[1]);
  TH1* h1dEdx_sce_corr_z = new TH1F("h1dEdx_sce_corr_z","dEdx(z), SCE full corr",nbins,zlim[0],zlim[1]);
  TH1* h1dEdx_sce_noel_z = new TH1F("h1dEdx_sce_noel_z","dEdx(z), SCE corr no e-lifetime",nbins,zlim[0],zlim[1]);
  //TH1* h1dQdx_x = new TH1F("h1dQdx_x","dQdx(x), no-SCE",nbins,xlim[0],xlim[1]);
  //TH1* h1dQdx_y = new TH1F("h1dQdx_y","dQdx(y), no-SCE",nbins,ylim[0],ylim[1]);
  //TH1* h1dQdx_z = new TH1F("h1dQdx_z","dQdx(z), no-SCE",nbins,zlim[0],zlim[1]);
  //TH1* h1dQdx_sce_x = new TH1F("h1dQdx_sce_x","dQdx(x), SCE",nbins,xlim[0],xlim[1]);
  //TH1* h1dQdx_sce_y = new TH1F("h1dQdx_sce_y","dQdx(y), SCE",nbins,ylim[0],ylim[1]);
  //TH1* h1dQdx_sce_z = new TH1F("h1dQdx_sce_z","dQdx(z), SCE",nbins,zlim[0],zlim[1]);

  TH1* h1xvals = new TH1F("h1xvals", "x values", 100,xlim[0],xlim[1]);

  //need these to fill the spatially dependent hists
  //so the dimensions need to match the number of bins in the histograms
  vector<vector<float> > dedx_x(nbins);
  vector<vector<float> > dedx_noel_x(nbins);
  vector<vector<float> > dedx_corr_x(nbins);
  vector<vector<float> > dedx_invel_x(nbins);
  vector<vector<float> > dedx_inverel_x(nbins);
  vector<vector<float> > dedx_sce_x(nbins);
  vector<vector<float> > dedx_sce_corr_x(nbins);
  vector<vector<float> > dedx_sce_noel_x(nbins);
  vector<vector<float> > dedx_y(nbins);
  vector<vector<float> > dedx_noel_y(nbins);
  vector<vector<float> > dedx_corr_y(nbins);
  vector<vector<float> > dedx_invel_y(nbins);
  vector<vector<float> > dedx_sce_y(nbins);
  vector<vector<float> > dedx_sce_corr_y(nbins);
  vector<vector<float> > dedx_sce_noel_y(nbins);
  vector<vector<float> > dedx_z(nbins);
  vector<vector<float> > dedx_noel_z(nbins);
  vector<vector<float> > dedx_corr_z(nbins);
  vector<vector<float> > dedx_invel_z(nbins);
  vector<vector<float> > dedx_sce_z(nbins);
  vector<vector<float> > dedx_sce_corr_z(nbins);
  vector<vector<float> > dedx_sce_noel_z(nbins);
  
  vector<vector<float> > dqdx_x(nbins);
  vector<vector<float> > dqdx_y(nbins);
  vector<vector<float> > dqdx_z(nbins);
  vector<vector<float> > dqdx_sce_x(nbins);
  vector<vector<float> > dqdx_sce_y(nbins);
  vector<vector<float> > dqdx_sce_z(nbins);

  /////////////////////////////////////////////////////////////////////////////////////
  // Starting SCE Event Loop
  /////////////////////////////////////////////////////////////////////////////////////
  for (gallery::Event ev(filenames_sce) ; !ev.atEnd(); ev.next()){
    auto t_begin = high_resolution_clock::now();
    int thisRunNum = ev.eventAuxiliary().run();
    int thisSubrunNum = ev.eventAuxiliary().subRun();
    int thisEventNum = ev.eventAuxiliary().event();
    //have we seen enough events?
    if (thisRunNum != prevRun){//new runs
      prevRun = thisRunNum;
      runEventCount = 1;
    }
    if (runEventCount++ > maxEventsPerRun) {break;}//we've seen enough of this run..
    if (totalEventCount++ > maxEvents) {break;}//we've seen enough events...
    if (hitCount_sce > maxHits) {break;}//hits updated in the track loop
    cout << "Processing SCE Event:" << "Run " << thisRunNum << ", " << "Subrun " << thisSubrunNum << ", " << "Event " << thisEventNum << endl;
   
    //////////////////////////////////////////////////////////////////////////////////
    // Calorimetry Loop
    //////////////////////////////////////////////////////////////////////////////////
    try{
      auto const& calo = *ev.getValidHandle< vector <anab::Calorimetry > > (fCalorimetrymoduleLabel);
      for (auto const& c : calo) {//loop through object in event
	const vector<recob::Track::Point_t> xyz = c.XYZ();
	const vector<float> dqdx = c.dQdx();      
	const vector<float> rrange = c.ResidualRange();
	const vector<float> dedx = c.dEdx();
	bool iscrazy = false;
	for (unsigned int i=1; i<dedx.size()-1; i++){
	  if (dedx.at(i)>1000){iscrazy=true;}
	}
	if (iscrazy){continue;}
	//I don't think I trust the given wire pitch
	const vector<float> tpitch = c.TrkPitchVec();
	//just quick check that there are same number of hits in each vector
	if (xyz.size() != dqdx.size()||
	    xyz.size() != rrange.size()){
	  cout << "vector size mismatch in calorimetry data products" << endl;
	  cout << "breaking..." << endl;
	  break;
	}else if (xyz.size() < 10){
	  cout << "only " << xyz.size() << " hits in this track" << endl;
	  cout << "...skipping" << endl;
	  break;
	}
	trackCount_sce++;

	for (unsigned i=1; i<xyz.size()-1; i++){//loop through hits	  
	  if (hitCount_sce++ > maxHits) {break;}
	  //hit space points
	  float x = xyz[i].X();
	  float y = xyz[i].Y();
	  float z = xyz[i].Z();
	  //previous space points
	  float xb = xyz[i-1].X();
	  float yb = xyz[i-1].Y();
	  float zb = xyz[i-1].Z();
	  //the next hit space points
	  float xf = xyz[i+1].X();
	  float yf = xyz[i+1].Y();
	  float zf = xyz[i+1].Z();
	  //corrected space points for SCE
	  float x_corr = x + GetBkwdOffset(x,y,z,1);
	  float y_corr = y + GetBkwdOffset(x,y,z,2);
	  float z_corr = z + GetBkwdOffset(x,y,z,3);
	  float xb_corr = xb + GetBkwdOffset(xb,yb,zb,1);
	  float yb_corr = yb + GetBkwdOffset(xb,yb,zb,2);
	  float zb_corr = zb + GetBkwdOffset(xb,yb,zb,3);
	  float xf_corr = xf + GetBkwdOffset(xf,yf,zf,1);
	  float yf_corr = yf + GetBkwdOffset(xf,yf,zf,2);
	  float zf_corr = zf + GetBkwdOffset(xf,yf,zf,3);
	  //pitch correction
	  float corr_pitch = calcPitch(xf,yf,zf,xb,yb,zb)/calcPitch(xf_corr,yf_corr,zf_corr,xb_corr,yb_corr,zb_corr);
	  //do e-lifetime correction
	  float el_corr_prime = exp((anodeDist(x_corr)/drift_v)/electronlifetime);
	  float el_corr = exp((anodeDist(x)/drift_v)/electronlifetime);
	  float el_corr_invel = exp(-1.*(anodeDist(x)/drift_v)/electronlifetime);
	  //do recombination correction
	  Xi = (ModBoxB * MIP_dEdx) / (LAr_density * GetLocalEField(x,y,z));
	  float Xi_prime = (ModBoxB * MIP_dEdx) / (LAr_density * GetLocalEField(x_corr,y_corr,z_corr));
	  float recomb = log(ModBoxA + Xi) / Xi;
	  float recomb_prime = log(ModBoxA + Xi_prime) / Xi_prime;
	  float corr_recomb = recomb_nominal/recomb;
	  float corr_recomb_prime = recomb_nominal/recomb_prime;
	  //calculate vals for histograms
	  //float dqdx_corrE = dqdx[i]*el_corr_prime*corr_recomb/recomb_nominal;
	  //float dqdx_corrnominal = dqdx[i]*el_corr_prime/recomb_nominal;
	  //float dqdx_corrspat = dqdx[i]*el_corr_prime*corr_pitch/recomb_nominal;
	  //float dqdx_corr = dqdx[i]*el_corr_prime*corr_pitch*corr_recomb/recomb_nominal;
	  //float dqdx_noel = dqdx[i]/recomb_nominal;
	  //float dqdx_corr_noel = dqdx[i]*corr_recomb*corr_pitch/recomb_nominal;
	  float dedx_corr = dedx[i]*corr_pitch*corr_recomb*el_corr_prime;
	  float dedx_invel = dedx[i]*el_corr_invel;
	  float dedx_corr_prime = dedx[i]*corr_pitch*corr_recomb_prime/el_corr_prime;
	  float dedx_corr_noel = dedx[i]*corr_pitch*corr_recomb;
	  float dedx_corr_invel = dedx[i]*corr_pitch*corr_recomb*el_corr_invel;

	  int x_bin = getindex(x,xlim,nbins);
	  int x_corr_bin = getindex(x_corr,xlim,nbins);
	  int y_bin = getindex(y,ylim,nbins);
	  int y_corr_bin = getindex(y_corr,ylim,nbins);
	  int z_bin = getindex(z,zlim,nbins);
	  int z_corr_bin = getindex(z_corr,zlim,nbins);
	  dedx_sce_x[x_bin].push_back(dedx[i]);
	  dedx_sce_corr_x[x_corr_bin].push_back(dedx_corr);
	  dedx_sce_noel_x[x_corr_bin].push_back(dedx_corr_noel);
	  dedx_sce_y[y_bin].push_back(dedx[i]);
	  dedx_sce_corr_y[y_corr_bin].push_back(dedx_corr);
	  dedx_sce_noel_y[y_corr_bin].push_back(dedx_corr_noel);
	  dedx_sce_z[z_bin].push_back(dedx[i]);
	  dedx_sce_corr_z[z_corr_bin].push_back(dedx_corr);
	  dedx_sce_noel_z[z_corr_bin].push_back(dedx_corr_noel);
	  
	  //dqdx_sce_x[x_bin].push_back(dqdx[i]);
	  //dqdx_sce_y[y_bin].push_back(dqdx[i]);
	  //dqdx_sce_z[z_bin].push_back(dqdx[i]);
	  ////////////////////////////////////////////////
	  ///FILL HISTOGRAMS
	  ////////////////////////////////////////////////
	  //h1dEdx_sce->Fill(dqdx_corrnominal);
	  //h1dEdx_sce_noel->Fill(dqdx_noel);
	  //h1dEdx_sce_corrE->Fill(dqdx_corrE);
	  //h1dEdx_sce_corrspat->Fill(dqdx_corrspat);
	  //h1dEdx_sce_corr->Fill(dqdx_corr);
	  //h1dEdx_sce_corr_noel->Fill(dqdx_corr_noel);
	  h1calodEdx_sce_invel->Fill(dedx_invel);
	  h1calodEdx_sce_corr->Fill(dedx_corr);
	  h1calodEdx_sce_corr_invel->Fill(dedx_corr_invel);
	  h1calodEdx_sce_corr_noel->Fill(dedx_corr_noel);
	  h1calodEdx_sce->Fill(dedx[i]);
	  //h3points_sce->Fill(x,y,z);
	  h1recomb->Fill(corr_recomb);
	  h1recomb_prime->Fill(corr_recomb_prime);
	}//end track loop	
      }//end loop over calo           
    } catch (const exception& e) {
      cout << "couldn't load calorimetry product"  << endl;
    }
  }//end loop over events
  //get values for the dedx_spat histograms
  for (int i=1; i<=nbins; i++){
    h1dEdx_sce_x->SetBinContent(i,calcMedian(dedx_sce_x[i-1]));
    h1dEdx_sce_corr_x->SetBinContent(i,calcMedian(dedx_sce_corr_x[i-1]));
    h1dEdx_sce_noel_x->SetBinContent(i,calcMedian(dedx_sce_noel_x[i-1]));
    h1dEdx_sce_y->SetBinContent(i,calcMedian(dedx_sce_y[i-1]));
    h1dEdx_sce_corr_y->SetBinContent(i,calcMedian(dedx_sce_corr_y[i-1]));
    h1dEdx_sce_noel_y->SetBinContent(i,calcMedian(dedx_sce_noel_y[i-1]));
    h1dEdx_sce_z->SetBinContent(i,calcMedian(dedx_sce_z[i-1]));
    h1dEdx_sce_corr_z->SetBinContent(i,calcMedian(dedx_sce_corr_z[i-1]));
    h1dEdx_sce_noel_z->SetBinContent(i,calcMedian(dedx_sce_noel_z[i-1]));
    
    //h1dQdx_sce_x->SetBinContent(i,calcMedian(dqdx_sce_x[i-1]));
    //h1dQdx_sce_y->SetBinContent(i,calcMedian(dqdx_sce_y[i-1]));
    //h1dQdx_sce_z->SetBinContent(i,calcMedian(dqdx_sce_z[i-1]));
  }
  //Write to output file
  f_output.cd();
  //h1dEdx_sce->Write();
  //h1dEdx_sce_noel->Write();
  //h1dEdx_sce_corrE->Write();
  //h1dEdx_sce_corrspat->Write();
  //h1dEdx_sce_corr->Write();
  //h1dEdx_sce_corr_noel->Write();
  h1calodEdx_sce->Write();
  h1calodEdx_sce_corr->Write();  
  h1calodEdx_sce_corr_invel->Write();
  h1calodEdx_sce_corr_noel->Write();
  h1calodEdx_sce_invel->Write();
  h1recomb->Write();
  //h3points_sce->Write();
  h1dEdx_sce_x->Write();
  h1dEdx_sce_corr_x->Write();
  h1dEdx_sce_noel_x->Write();
  h1dEdx_sce_y->Write();
  h1dEdx_sce_corr_y->Write();
  h1dEdx_sce_noel_y->Write();
  h1dEdx_sce_z->Write();
  h1dEdx_sce_corr_z->Write();
  h1dEdx_sce_noel_z->Write();

  //reset loop variables
  totalEventCount = 0;
  prevRun = -9999;
  runEventCount = 0;

  /////////////////////////////////////////////////////////////////////////////////////
  // Starting NON-SCE Event Loop
  /////////////////////////////////////////////////////////////////////////////////////
  for (gallery::Event ev(filenames) ; !ev.atEnd(); ev.next()){
    auto t_begin = high_resolution_clock::now();
    int thisRunNum = ev.eventAuxiliary().run();
    int thisSubrunNum = ev.eventAuxiliary().subRun();
    int thisEventNum = ev.eventAuxiliary().event();
    //have we seen enough events?
    if (thisRunNum != prevRun){//new runs
      prevRun = thisRunNum;
      runEventCount = 1;
    }
    runEventCount++;
    totalEventCount++;
    if (runEventCount > maxEventsPerRun) {break;}//we've seen enough of this run..
    if (totalEventCount > maxEvents) {break;}//we've seen enough events...
    if (hitCount > maxHits) {break;}//hits updated in track loop below
    cout << "Processing non-SCE Event: " << "Run " << thisRunNum << ", " << "Subrun " << thisSubrunNum << ", " << "Event " << thisEventNum << endl;
   
    //////////////////////////////////////////////////////////////////////////////////
    // Calorimetry Loop
    //////////////////////////////////////////////////////////////////////////////////
    try{
      auto const& calo = *ev.getValidHandle< vector <anab::Calorimetry > > (fCalorimetrymoduleLabel);
      for (auto const& c : calo) {//loop through object in event
	const vector<recob::Track::Point_t> xyz = c.XYZ();
	const vector<float> dqdx = c.dQdx();      
	const vector<float> rrange = c.ResidualRange();
	const vector<float> tpitch = c.TrkPitchVec();
	const vector<float> dedx = c.dEdx();
	bool iscrazy = false;
	for (unsigned int i=1; i<xyz.size()-1; i++){
	  if (dedx.at(i)>1000){iscrazy=true;}
	}
	if (iscrazy){continue;}
	//just quick check that there are same number of hits in each vector
	if (xyz.size() != dqdx.size()||
	    xyz.size() != rrange.size()){
	  cout << "vector size mismatch in calorimetry data products" << endl;
	  cout << "breaking..." << endl;
	  break;
	}else if (xyz.size() < 10){
	  cout << "only " << xyz.size() << " hits in this track" << endl;
	  cout << "...skipping" << endl;
	  break;
	}
	trackCount++;

	//correction factors
	float corr_el;
	for (unsigned i=0; i<xyz.size()-1; i++){//loop through hits	  
	  if (hitCount++ > maxHits) {break;}
	  //hit space points
	  float x = xyz[i].X();	
	  float y = xyz[i].Y();
	  float z = xyz[i].Z();
	  //fill pitch ratio histogram (testing)
	  h1pitchratio->Fill(calcPitch(x,xyz[i].Y(),xyz[i].Z(),xyz[i+1].X(),xyz[i+1].Y(),xyz[i+1].Z())/tpitch[i]);
	  //do e-lifetime correction
	  float el_corr = exp((anodeDist(x)/drift_v)/electronlifetime);
	  float el_corr_invel = exp(-1.*(anodeDist(x)/drift_v)/electronlifetime);
	  float el_corr_inverel = exp((cathodeDist(x)/drift_v)/electronlifetime);
	  //corrected dqdx
	  //float dqdx_corr = dqdx[i]*corr_el/recomb_nominal;
	  //float dqdx_corr_noel = dqdx[i]/recomb_nominal;
	  
	  float dedx_corr = dedx[i]*el_corr;
	  float dedx_invel = dedx[i]*el_corr_invel;
	  float dedx_inverel = dedx[i]*el_corr_inverel;
	  int x_bin = getindex(x,xlim,nbins);
	  int y_bin = getindex(y,ylim,nbins);
	  int z_bin = getindex(z,zlim,nbins);
	  dedx_x[x_bin].push_back(dedx_corr);
	  dedx_y[y_bin].push_back(dedx_corr);
	  dedx_z[z_bin].push_back(dedx_corr);
	  //dqdx_x[x_bin].push_back(dqdx[i]);
	  //dqdx_y[y_bin].push_back(dqdx[i]);
	  //dqdx_z[z_bin].push_back(dqdx[i]);
	  dedx_invel_x[x_bin].push_back(dedx_invel);
	  dedx_invel_y[y_bin].push_back(dedx_invel);
	  dedx_invel_z[z_bin].push_back(dedx_invel);
	  dedx_corr_x[x_bin].push_back(dedx_corr);
	  dedx_corr_y[y_bin].push_back(dedx_corr);
	  dedx_corr_z[z_bin].push_back(dedx_corr);
	  dedx_inverel_x[x_bin].push_back(dedx_inverel);
	  dedx_noel_x[x_bin].push_back(dedx[i]);
	  dedx_noel_y[y_bin].push_back(dedx[i]);
	  dedx_noel_z[z_bin].push_back(dedx[i]);
	  //fill no-sce histogram
	  //h1dEdx->Fill(dqdx_corr);	 
	  //h1dEdx_noel->Fill(dqdx_corr_noel);	 
	  h2dEdx_rrange->Fill(rrange[i],dedx[i]);	  
	  h1calodEdx->Fill(dedx_corr);
	  h1calodEdx_noel->Fill(dedx[i]);
	  h1calodEdx_invel->Fill(dedx_invel);
	  h1calodEdx_inverel->Fill(dedx_inverel);
	  h1calopitches->Fill(tpitch[i]);
	  h1xvals->Fill(x);
	  //h3points->Fill(x,y,z);
	}//end track loop	
      }//end loop over calo           
    } catch (const exception& e) {
      cout << "couldn't load calorimetry product"  << endl;
    }
  }//end loop over events
  //get values for the dedx_spat histograms
  for (int i=1; i<=nbins; i++){
    h1dEdx_x->SetBinContent(i,calcMedian(dedx_x[i-1]));
    h1dEdx_noel_x->SetBinContent(i,calcMedian(dedx_noel_x[i-1]));
    h1dEdx_corr_x->SetBinContent(i,calcMedian(dedx_corr_x[i-1]));
    h1dEdx_invel_x->SetBinContent(i,calcMedian(dedx_invel_x[i-1]));
    h1dEdx_inverel_x->SetBinContent(i,calcMedian(dedx_inverel_x[i-1]));
    h1dEdx_y->SetBinContent(i,calcMedian(dedx_y[i-1]));
    h1dEdx_noel_y->SetBinContent(i,calcMedian(dedx_noel_y[i-1]));
    h1dEdx_corr_y->SetBinContent(i,calcMedian(dedx_corr_y[i-1]));
    h1dEdx_invel_y->SetBinContent(i,calcMedian(dedx_invel_y[i-1]));
    h1dEdx_z->SetBinContent(i,calcMedian(dedx_z[i-1]));
    h1dEdx_noel_z->SetBinContent(i,calcMedian(dedx_noel_z[i-1]));
    h1dEdx_corr_z->SetBinContent(i,calcMedian(dedx_corr_z[i-1]));
    h1dEdx_invel_z->SetBinContent(i,calcMedian(dedx_invel_z[i-1]));

    //h1dQdx_x->SetBinContent(i,calcMedian(dqdx_x[i-1]));
    //h1dQdx_y->SetBinContent(i,calcMedian(dqdx_y[i-1]));
    //h1dQdx_z->SetBinContent(i,calcMedian(dqdx_z[i-1]));
  }
  f_output.cd();
  //h1dEdx->Write();
  //h1dEdx_noel->Write();
  h2dEdx_rrange->Write();
  h1pitchratio->Write();
  h1calodEdx->Write();
  h1calodEdx_noel->Write();
  h1calodEdx_invel->Write();
  h1calodEdx_inverel->Write();
  h1calopitches->Write();
  //h3points->Write();
  h1dEdx_x->Write();
  h1dEdx_inverel_x->Write();
  h1dEdx_noel_x->Write();
  h1dEdx_noel_y->Write();
  h1dEdx_noel_z->Write();
  h1dEdx_y->Write();
  h1dEdx_z->Write();
  h1dEdx_corr_x->Write();
  h1dEdx_invel_x->Write();
  h1dEdx_corr_y->Write();
  h1dEdx_corr_z->Write();
  h1dEdx_invel_y->Write();
  h1dEdx_invel_z->Write();
  //h1dQdx_x->Write();
  //h1dQdx_y->Write();
  //h1dQdx_z->Write();
  h1xvals->Write();

  f_output.Write();
  f_output.Close();
  cout << "num tracks with at least 10 hits: " << trackCount << endl;
  cout << "num sce tracks with at least 10 hits: " << trackCount_sce << endl;
  cout << "num hits recorded for non-sce: " << hitCount << endl;
  cout << "num hits recorded for sce: " << hitCount_sce << endl;

  return 0;
}//end main

void LoadHists()
{
  TrueFwdX = (TH3F*) fileHists->Get("TrueFwd_Displacement_X");
  TrueFwdY = (TH3F*) fileHists->Get("TrueFwd_Displacement_Y");
  TrueFwdZ = (TH3F*) fileHists->Get("TrueFwd_Displacement_Z");

  TrueBkwdX = (TH3F*) fileHists->Get("TrueBkwd_Displacement_X");
  TrueBkwdY = (TH3F*) fileHists->Get("TrueBkwd_Displacement_Y");
  TrueBkwdZ = (TH3F*) fileHists->Get("TrueBkwd_Displacement_Z");

  TrueEFieldMag = (TH3F*) fileHists->Get("True_ElecField_Mag");
}//end main loop

/////////////////////////////////////////////////////////////////////////////
//User-Defined Functions
/////////////////////////////////////////////////////////////////////////////
double anodeDist(double x){
  double d = 200 - abs(x);
  if (d < 0){d = 0;}
  return d;
}
double cathodeDist(double x){
  return abs(x);
}
double calcPitch(double x1, double y1, double z1, double x2, double y2, double z2){
  return sqrt(pow(x2-x1,2)+pow(y2-y1,2)+pow(z2-z1,2));
}

double calcMedian(vector<float> values){
  size_t size = values.size();
  if (size == 0){
    return 0;  // Undefined, really.
  }
  else{
    sort(values.begin(), values.end());
    if (size % 2 == 0){
      return (values[size / 2 - 1] + values[size / 2]) / 2;
    }
    else{
      return values[size / 2];
    }
  }
}

double calcMean(vector<float> values){
  if (values.size() == 0){return 0;}
  float mean =  accumulate( values.begin(), values.end(), 0.0)/values.size();
  return mean;
}
int getindex(float val, int lims[2], int nbins){
  int index = int(round((val-lims[0])/abs(lims[1]-lims[0])*nbins));
  if (index < 0){index=0;}
  if (index >= nbins){index = nbins - 1;}
  return index;
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
