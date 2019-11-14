//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Aug 20 10:26:25 2019 by ROOT version 6.14/02
// from TTree anatree/analysis tree
// found on file: reco-a6725708-f2f1-4a11-800c-2e9cac4f5d95_AnaTree-20190802T161208.root
//////////////////////////////////////////////////////////

#ifndef endpoints_h
#define endpoints_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"

class endpoints {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           run;
   Int_t           subrun;
   Int_t           event;
   Double_t        evttime;
   Double_t        beamtime;
   Double_t        pot;
   Char_t          isdata;
   Int_t           no_hits;
   Short_t         hit_tpc[32779];   //[no_hits]
   Short_t         hit_plane[32779];   //[no_hits]
   Short_t         hit_wire[32779];   //[no_hits]
   Short_t         hit_channel[32779];   //[no_hits]
   Float_t         hit_peakT[32779];   //[no_hits]
   Float_t         hit_charge[32779];   //[no_hits]
   Float_t         hit_ph[32779];   //[no_hits]
   Float_t         hit_startT[32779];   //[no_hits]
   Float_t         hit_endT[32779];   //[no_hits]
   Short_t         hit_trkid[32779];   //[no_hits]
   Float_t         hit_nelec[32779];   //[no_hits]
   Float_t         hit_energy[32779];   //[no_hits]
   Char_t          kNTracker;
   Int_t           mcevts_truth;
   Int_t           nuScatterCode_truth[1];   //[mcevts_truth]
   Int_t           nuID_truth[1];   //[mcevts_truth]
   Int_t           nuPDG_truth[1];   //[mcevts_truth]
   Int_t           ccnc_truth[1];   //[mcevts_truth]
   Int_t           mode_truth[1];   //[mcevts_truth]
   Float_t         enu_truth[1];   //[mcevts_truth]
   Float_t         Q2_truth[1];   //[mcevts_truth]
   Float_t         W_truth[1];   //[mcevts_truth]
   Int_t           hitnuc_truth[1];   //[mcevts_truth]
   Float_t         nuvtxx_truth[1];   //[mcevts_truth]
   Float_t         nuvtxy_truth[1];   //[mcevts_truth]
   Float_t         nuvtxz_truth[1];   //[mcevts_truth]
   Float_t         nu_dcosx_truth[1];   //[mcevts_truth]
   Float_t         nu_dcosy_truth[1];   //[mcevts_truth]
   Float_t         nu_dcosz_truth[1];   //[mcevts_truth]
   Float_t         lep_mom_truth[1];   //[mcevts_truth]
   Float_t         lep_dcosx_truth[1];   //[mcevts_truth]
   Float_t         lep_dcosy_truth[1];   //[mcevts_truth]
   Float_t         lep_dcosz_truth[1];   //[mcevts_truth]
   Float_t         tpx_flux[1];   //[mcevts_truth]
   Float_t         tpy_flux[1];   //[mcevts_truth]
   Float_t         tpz_flux[1];   //[mcevts_truth]
   Int_t           tptype_flux[1];   //[mcevts_truth]
   Int_t           genie_no_primaries;
   Int_t           genie_primaries_pdg[1];   //[genie_no_primaries]
   Float_t         genie_Eng[1];   //[genie_no_primaries]
   Float_t         genie_Px[1];   //[genie_no_primaries]
   Float_t         genie_Py[1];   //[genie_no_primaries]
   Float_t         genie_Pz[1];   //[genie_no_primaries]
   Float_t         genie_P[1];   //[genie_no_primaries]
   Int_t           genie_status_code[1];   //[genie_no_primaries]
   Float_t         genie_mass[1];   //[genie_no_primaries]
   Int_t           genie_trackID[1];   //[genie_no_primaries]
   Int_t           genie_ND[1];   //[genie_no_primaries]
   Int_t           genie_mother[1];   //[genie_no_primaries]
   Int_t           mcevts_truthcry;
   Int_t           cry_no_primaries;
   Int_t           cry_primaries_pdg[649];   //[cry_no_primaries]
   Float_t         cry_Eng[649];   //[cry_no_primaries]
   Float_t         cry_Px[649];   //[cry_no_primaries]
   Float_t         cry_Py[649];   //[cry_no_primaries]
   Float_t         cry_Pz[649];   //[cry_no_primaries]
   Float_t         cry_P[649];   //[cry_no_primaries]
   Float_t         cry_StartPointx[649];   //[cry_no_primaries]
   Float_t         cry_StartPointy[649];   //[cry_no_primaries]
   Float_t         cry_StartPointz[649];   //[cry_no_primaries]
   Int_t           cry_status_code[649];   //[cry_no_primaries]
   Float_t         cry_mass[649];   //[cry_no_primaries]
   Int_t           cry_trackID[649];   //[cry_no_primaries]
   Int_t           cry_ND[649];   //[cry_no_primaries]
   Int_t           cry_mother[649];   //[cry_no_primaries]
   Int_t           no_primaries;
   Int_t           geant_list_size;
   Int_t           geant_list_size_in_tpcAV;
   Int_t           pdg[3268];   //[geant_list_size]
   Int_t           status[3268];   //[geant_list_size]
   Float_t         Mass[3268];   //[geant_list_size]
   Float_t         Eng[3268];   //[geant_list_size]
   Float_t         EndE[3268];   //[geant_list_size]
   Float_t         Px[3268];   //[geant_list_size]
   Float_t         Py[3268];   //[geant_list_size]
   Float_t         Pz[3268];   //[geant_list_size]
   Float_t         P[3268];   //[geant_list_size]
   Float_t         StartPointx[3268];   //[geant_list_size]
   Float_t         StartPointy[3268];   //[geant_list_size]
   Float_t         StartPointz[3268];   //[geant_list_size]
   Float_t         StartT[3268];   //[geant_list_size]
   Float_t         EndPointx[3268];   //[geant_list_size]
   Float_t         EndPointy[3268];   //[geant_list_size]
   Float_t         EndPointz[3268];   //[geant_list_size]
   Float_t         EndT[3268];   //[geant_list_size]
   Float_t         theta[3268];   //[geant_list_size]
   Float_t         phi[3268];   //[geant_list_size]
   Float_t         theta_xz[3268];   //[geant_list_size]
   Float_t         theta_yz[3268];   //[geant_list_size]
   Float_t         pathlen[3268];   //[geant_list_size]
   Int_t           inTPCActive[3268];   //[geant_list_size]
   Float_t         StartPointx_tpcAV[3268];   //[geant_list_size]
   Float_t         StartPointy_tpcAV[3268];   //[geant_list_size]
   Float_t         StartPointz_tpcAV[3268];   //[geant_list_size]
   Float_t         EndPointx_tpcAV[3268];   //[geant_list_size]
   Float_t         EndPointy_tpcAV[3268];   //[geant_list_size]
   Float_t         EndPointz_tpcAV[3268];   //[geant_list_size]
   Int_t           NumberDaughters[3268];   //[geant_list_size]
   Int_t           Mother[3268];   //[geant_list_size]
   Int_t           TrackId[3268];   //[geant_list_size]
   Int_t           MergedId[3268];   //[geant_list_size]
   Int_t           MotherNuId[3268];   //[geant_list_size]
   Int_t           process_primary[3268];   //[geant_list_size]
   vector<string>  *processname;
   Short_t         nvtx_pmalgtrackmaker;
   Float_t         vtx_pmalgtrackmaker[108][3];   //[nvtx_pmalgtrackmaker]
   Short_t         nvtx_pandora;
   Int_t           primaryvtx_pandora[183];   //[nvtx_pandora]
   Float_t         vtx_pandora[183][3];   //[nvtx_pandora]
   Short_t         nshowers_pandoraShower;
   Int_t           shwId_pandoraShower[150];   //[nshowers_pandoraShower]
   Int_t           shwbestplane_pandoraShower[150];   //[nshowers_pandoraShower]
   Float_t         shwlength_pandoraShower[150];   //[nshowers_pandoraShower]
   Float_t         shwopenangle_pandoraShower[150];   //[nshowers_pandoraShower]
   Float_t         shwstartx_pandoraShower[150];   //[nshowers_pandoraShower]
   Float_t         shwstarty_pandoraShower[150];   //[nshowers_pandoraShower]
   Float_t         shwstartz_pandoraShower[150];   //[nshowers_pandoraShower]
   Float_t         shwdirx_pandoraShower[150];   //[nshowers_pandoraShower]
   Float_t         shwdiry_pandoraShower[150];   //[nshowers_pandoraShower]
   Float_t         shwdirz_pandoraShower[150];   //[nshowers_pandoraShower]
   Bool_t          shwisprimary_pandoraShower[150];   //[nshowers_pandoraShower]
   Int_t           shwndaughters_pandoraShower[150];   //[nshowers_pandoraShower]
   Int_t           shwpfpid_pandoraShower[150];   //[nshowers_pandoraShower]
   Int_t           shwparentpfpid_pandoraShower[150];   //[nshowers_pandoraShower]
   Short_t         ntracks_pmalgtrackmaker;
   Short_t         trkId_pmalgtrackmaker[128];   //[ntracks_pmalgtrackmaker]
   Short_t         trkncosmictags_tagger_pmalgtrackmaker[128];   //[ntracks_pmalgtrackmaker]
   Float_t         trkcosmicscore_tagger_pmalgtrackmaker[128];   //[ntracks_pmalgtrackmaker]
   Short_t         trkcosmictype_tagger_pmalgtrackmaker[128];   //[ntracks_pmalgtrackmaker]
   Short_t         trkncosmictags_flashmatch_pmalgtrackmaker[128];   //[ntracks_pmalgtrackmaker]
   Float_t         trkcosmicscore_flashmatch_pmalgtrackmaker[128];   //[ntracks_pmalgtrackmaker]
   Short_t         trkcosmictype_flashmatch_pmalgtrackmaker[128];   //[ntracks_pmalgtrackmaker]
   Float_t         trkke_pmalgtrackmaker[128][3];   //[ntracks_pmalgtrackmaker]
   Float_t         trkrange_pmalgtrackmaker[128][3];   //[ntracks_pmalgtrackmaker]
   Int_t           trkidtruth_recoutils_totaltrueenergy_pmalgtrackmaker[128][3];   //[ntracks_pmalgtrackmaker]
   Int_t           trkidtruth_recoutils_totalrecocharge_pmalgtrackmaker[128][3];   //[ntracks_pmalgtrackmaker]
   Int_t           trkidtruth_recoutils_totalrecohits_pmalgtrackmaker[128][3];   //[ntracks_pmalgtrackmaker]
   Int_t           trkidtruth_pmalgtrackmaker[128][3];   //[ntracks_pmalgtrackmaker]
   Short_t         trkorigin_pmalgtrackmaker[128][3];   //[ntracks_pmalgtrackmaker]
   Int_t           trkpdgtruth_pmalgtrackmaker[128][3];   //[ntracks_pmalgtrackmaker]
   Float_t         trkefftruth_pmalgtrackmaker[128][3];   //[ntracks_pmalgtrackmaker]
   Float_t         trksimIDEenergytruth_pmalgtrackmaker[128][3];   //[ntracks_pmalgtrackmaker]
   Float_t         trksimIDExtruth_pmalgtrackmaker[128][3];   //[ntracks_pmalgtrackmaker]
   Float_t         trksimIDEytruth_pmalgtrackmaker[128][3];   //[ntracks_pmalgtrackmaker]
   Float_t         trksimIDEztruth_pmalgtrackmaker[128][3];   //[ntracks_pmalgtrackmaker]
   Float_t         trkpurtruth_pmalgtrackmaker[128][3];   //[ntracks_pmalgtrackmaker]
   Float_t         trkpitchc_pmalgtrackmaker[128][3];   //[ntracks_pmalgtrackmaker]
   Short_t         ntrkhits_pmalgtrackmaker[128][3];   //[ntracks_pmalgtrackmaker]
   Float_t         trkstartx_pmalgtrackmaker[128];   //[ntracks_pmalgtrackmaker]
   Float_t         trkstarty_pmalgtrackmaker[128];   //[ntracks_pmalgtrackmaker]
   Float_t         trkstartz_pmalgtrackmaker[128];   //[ntracks_pmalgtrackmaker]
   Float_t         trkstartd_pmalgtrackmaker[128];   //[ntracks_pmalgtrackmaker]
   Float_t         trkendx_pmalgtrackmaker[128];   //[ntracks_pmalgtrackmaker]
   Float_t         trkendy_pmalgtrackmaker[128];   //[ntracks_pmalgtrackmaker]
   Float_t         trkendz_pmalgtrackmaker[128];   //[ntracks_pmalgtrackmaker]
   Float_t         trkendd_pmalgtrackmaker[128];   //[ntracks_pmalgtrackmaker]
   Float_t         trktheta_pmalgtrackmaker[128];   //[ntracks_pmalgtrackmaker]
   Float_t         trkphi_pmalgtrackmaker[128];   //[ntracks_pmalgtrackmaker]
   Float_t         trkstartdcosx_pmalgtrackmaker[128];   //[ntracks_pmalgtrackmaker]
   Float_t         trkstartdcosy_pmalgtrackmaker[128];   //[ntracks_pmalgtrackmaker]
   Float_t         trkstartdcosz_pmalgtrackmaker[128];   //[ntracks_pmalgtrackmaker]
   Float_t         trkenddcosx_pmalgtrackmaker[128];   //[ntracks_pmalgtrackmaker]
   Float_t         trkenddcosy_pmalgtrackmaker[128];   //[ntracks_pmalgtrackmaker]
   Float_t         trkenddcosz_pmalgtrackmaker[128];   //[ntracks_pmalgtrackmaker]
   Float_t         trkthetaxz_pmalgtrackmaker[128];   //[ntracks_pmalgtrackmaker]
   Float_t         trkthetayz_pmalgtrackmaker[128];   //[ntracks_pmalgtrackmaker]
   Float_t         trkmom_pmalgtrackmaker[128];   //[ntracks_pmalgtrackmaker]
   Float_t         trkmomrange_pmalgtrackmaker[128];   //[ntracks_pmalgtrackmaker]
   Float_t         trkmommschi2_pmalgtrackmaker[128];   //[ntracks_pmalgtrackmaker]
   Float_t         trkmommsllhd_pmalgtrackmaker[128];   //[ntracks_pmalgtrackmaker]
   Float_t         trklen_pmalgtrackmaker[128];   //[ntracks_pmalgtrackmaker]
   Short_t         trksvtxid_pmalgtrackmaker[128];   //[ntracks_pmalgtrackmaker]
   Short_t         trkevtxid_pmalgtrackmaker[128];   //[ntracks_pmalgtrackmaker]
   Int_t           trkpidpdg_pmalgtrackmaker[128][3];   //[ntracks_pmalgtrackmaker]
   Float_t         trkpidchi_pmalgtrackmaker[128][3];   //[ntracks_pmalgtrackmaker]
   Float_t         trkpidchipr_pmalgtrackmaker[128][3];   //[ntracks_pmalgtrackmaker]
   Float_t         trkpidchika_pmalgtrackmaker[128][3];   //[ntracks_pmalgtrackmaker]
   Float_t         trkpidchipi_pmalgtrackmaker[128][3];   //[ntracks_pmalgtrackmaker]
   Float_t         trkpidchimu_pmalgtrackmaker[128][3];   //[ntracks_pmalgtrackmaker]
   Float_t         trkpidpida_pmalgtrackmaker[128][3];   //[ntracks_pmalgtrackmaker]
   Short_t         trkpidbestplane_pmalgtrackmaker[128];   //[ntracks_pmalgtrackmaker]
   Short_t         ntracks_pandoraTrack;
   Short_t         trkId_pandoraTrack[36];   //[ntracks_pandoraTrack]
   Short_t         trkncosmictags_tagger_pandoraTrack[36];   //[ntracks_pandoraTrack]
   Float_t         trkcosmicscore_tagger_pandoraTrack[36];   //[ntracks_pandoraTrack]
   Short_t         trkcosmictype_tagger_pandoraTrack[36];   //[ntracks_pandoraTrack]
   Short_t         trkncosmictags_flashmatch_pandoraTrack[36];   //[ntracks_pandoraTrack]
   Float_t         trkcosmicscore_flashmatch_pandoraTrack[36];   //[ntracks_pandoraTrack]
   Short_t         trkcosmictype_flashmatch_pandoraTrack[36];   //[ntracks_pandoraTrack]
   Float_t         trkke_pandoraTrack[36][3];   //[ntracks_pandoraTrack]
   Float_t         trkrange_pandoraTrack[36][3];   //[ntracks_pandoraTrack]
   Int_t           trkidtruth_recoutils_totaltrueenergy_pandoraTrack[36][3];   //[ntracks_pandoraTrack]
   Int_t           trkidtruth_recoutils_totalrecocharge_pandoraTrack[36][3];   //[ntracks_pandoraTrack]
   Int_t           trkidtruth_recoutils_totalrecohits_pandoraTrack[36][3];   //[ntracks_pandoraTrack]
   Int_t           trkidtruth_pandoraTrack[36][3];   //[ntracks_pandoraTrack]
   Short_t         trkorigin_pandoraTrack[36][3];   //[ntracks_pandoraTrack]
   Int_t           trkpdgtruth_pandoraTrack[36][3];   //[ntracks_pandoraTrack]
   Float_t         trkefftruth_pandoraTrack[36][3];   //[ntracks_pandoraTrack]
   Float_t         trksimIDEenergytruth_pandoraTrack[36][3];   //[ntracks_pandoraTrack]
   Float_t         trksimIDExtruth_pandoraTrack[36][3];   //[ntracks_pandoraTrack]
   Float_t         trksimIDEytruth_pandoraTrack[36][3];   //[ntracks_pandoraTrack]
   Float_t         trksimIDEztruth_pandoraTrack[36][3];   //[ntracks_pandoraTrack]
   Float_t         trkpurtruth_pandoraTrack[36][3];   //[ntracks_pandoraTrack]
   Float_t         trkpitchc_pandoraTrack[36][3];   //[ntracks_pandoraTrack]
   Short_t         ntrkhits_pandoraTrack[36][3];   //[ntracks_pandoraTrack]
   Float_t         trkstartx_pandoraTrack[36];   //[ntracks_pandoraTrack]
   Float_t         trkstarty_pandoraTrack[36];   //[ntracks_pandoraTrack]
   Float_t         trkstartz_pandoraTrack[36];   //[ntracks_pandoraTrack]
   Float_t         trkstartd_pandoraTrack[36];   //[ntracks_pandoraTrack]
   Float_t         trkendx_pandoraTrack[36];   //[ntracks_pandoraTrack]
   Float_t         trkendy_pandoraTrack[36];   //[ntracks_pandoraTrack]
   Float_t         trkendz_pandoraTrack[36];   //[ntracks_pandoraTrack]
   Float_t         trkendd_pandoraTrack[36];   //[ntracks_pandoraTrack]
   Float_t         trktheta_pandoraTrack[36];   //[ntracks_pandoraTrack]
   Float_t         trkphi_pandoraTrack[36];   //[ntracks_pandoraTrack]
   Float_t         trkstartdcosx_pandoraTrack[36];   //[ntracks_pandoraTrack]
   Float_t         trkstartdcosy_pandoraTrack[36];   //[ntracks_pandoraTrack]
   Float_t         trkstartdcosz_pandoraTrack[36];   //[ntracks_pandoraTrack]
   Float_t         trkenddcosx_pandoraTrack[36];   //[ntracks_pandoraTrack]
   Float_t         trkenddcosy_pandoraTrack[36];   //[ntracks_pandoraTrack]
   Float_t         trkenddcosz_pandoraTrack[36];   //[ntracks_pandoraTrack]
   Float_t         trkthetaxz_pandoraTrack[36];   //[ntracks_pandoraTrack]
   Float_t         trkthetayz_pandoraTrack[36];   //[ntracks_pandoraTrack]
   Float_t         trkmom_pandoraTrack[36];   //[ntracks_pandoraTrack]
   Float_t         trkmomrange_pandoraTrack[36];   //[ntracks_pandoraTrack]
   Float_t         trkmommschi2_pandoraTrack[36];   //[ntracks_pandoraTrack]
   Float_t         trkmommsllhd_pandoraTrack[36];   //[ntracks_pandoraTrack]
   Float_t         trklen_pandoraTrack[36];   //[ntracks_pandoraTrack]
   Short_t         trksvtxid_pandoraTrack[36];   //[ntracks_pandoraTrack]
   Short_t         trkevtxid_pandoraTrack[36];   //[ntracks_pandoraTrack]
   Int_t           trkpidpdg_pandoraTrack[36][3];   //[ntracks_pandoraTrack]
   Float_t         trkpidchi_pandoraTrack[36][3];   //[ntracks_pandoraTrack]
   Float_t         trkpidchipr_pandoraTrack[36][3];   //[ntracks_pandoraTrack]
   Float_t         trkpidchika_pandoraTrack[36][3];   //[ntracks_pandoraTrack]
   Float_t         trkpidchipi_pandoraTrack[36][3];   //[ntracks_pandoraTrack]
   Float_t         trkpidchimu_pandoraTrack[36][3];   //[ntracks_pandoraTrack]
   Float_t         trkpidpida_pandoraTrack[36][3];   //[ntracks_pandoraTrack]
   Short_t         trkpidbestplane_pandoraTrack[36];   //[ntracks_pandoraTrack]
   Bool_t          trkisprimary_pandoraTrack[36];   //[ntracks_pandoraTrack]
   Int_t           trkndaughters_pandoraTrack[36];   //[ntracks_pandoraTrack]
   Int_t           trkpfpid_pandoraTrack[36];   //[ntracks_pandoraTrack]
   Int_t           trkparentpfpid_pandoraTrack[36];   //[ntracks_pandoraTrack]

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_subrun;   //!
   TBranch        *b_event;   //!
   TBranch        *b_evttime;   //!
   TBranch        *b_beamtime;   //!
   TBranch        *b_pot;   //!
   TBranch        *b_isdata;   //!
   TBranch        *b_no_hits;   //!
   TBranch        *b_hit_tpc;   //!
   TBranch        *b_hit_plane;   //!
   TBranch        *b_hit_wire;   //!
   TBranch        *b_hit_channel;   //!
   TBranch        *b_hit_peakT;   //!
   TBranch        *b_hit_charge;   //!
   TBranch        *b_hit_ph;   //!
   TBranch        *b_hit_startT;   //!
   TBranch        *b_hit_endT;   //!
   TBranch        *b_hit_trkid;   //!
   TBranch        *b_hit_nelec;   //!
   TBranch        *b_hit_energy;   //!
   TBranch        *b_kNTracker;   //!
   TBranch        *b_mcevts_truth;   //!
   TBranch        *b_nuScatterCode_truth;   //!
   TBranch        *b_nuID_truth;   //!
   TBranch        *b_nuPDG_truth;   //!
   TBranch        *b_ccnc_truth;   //!
   TBranch        *b_mode_truth;   //!
   TBranch        *b_enu_truth;   //!
   TBranch        *b_Q2_truth;   //!
   TBranch        *b_W_truth;   //!
   TBranch        *b_hitnuc_truth;   //!
   TBranch        *b_nuvtxx_truth;   //!
   TBranch        *b_nuvtxy_truth;   //!
   TBranch        *b_nuvtxz_truth;   //!
   TBranch        *b_nu_dcosx_truth;   //!
   TBranch        *b_nu_dcosy_truth;   //!
   TBranch        *b_nu_dcosz_truth;   //!
   TBranch        *b_lep_mom_truth;   //!
   TBranch        *b_lep_dcosx_truth;   //!
   TBranch        *b_lep_dcosy_truth;   //!
   TBranch        *b_lep_dcosz_truth;   //!
   TBranch        *b_tpx_flux;   //!
   TBranch        *b_tpy_flux;   //!
   TBranch        *b_tpz_flux;   //!
   TBranch        *b_tptype_flux;   //!
   TBranch        *b_genie_no_primaries;   //!
   TBranch        *b_genie_primaries_pdg;   //!
   TBranch        *b_genie_Eng;   //!
   TBranch        *b_genie_Px;   //!
   TBranch        *b_genie_Py;   //!
   TBranch        *b_genie_Pz;   //!
   TBranch        *b_genie_P;   //!
   TBranch        *b_genie_status_code;   //!
   TBranch        *b_genie_mass;   //!
   TBranch        *b_genie_trackID;   //!
   TBranch        *b_genie_ND;   //!
   TBranch        *b_genie_mother;   //!
   TBranch        *b_mcevts_truthcry;   //!
   TBranch        *b_cry_no_primaries;   //!
   TBranch        *b_cry_primaries_pdg;   //!
   TBranch        *b_cry_Eng;   //!
   TBranch        *b_cry_Px;   //!
   TBranch        *b_cry_Py;   //!
   TBranch        *b_cry_Pz;   //!
   TBranch        *b_cry_P;   //!
   TBranch        *b_cry_StartPointx;   //!
   TBranch        *b_cry_StartPointy;   //!
   TBranch        *b_cry_StartPointz;   //!
   TBranch        *b_cry_status_code;   //!
   TBranch        *b_cry_mass;   //!
   TBranch        *b_cry_trackID;   //!
   TBranch        *b_cry_ND;   //!
   TBranch        *b_cry_mother;   //!
   TBranch        *b_no_primaries;   //!
   TBranch        *b_geant_list_size;   //!
   TBranch        *b_geant_list_size_in_tpcAV;   //!
   TBranch        *b_pdg;   //!
   TBranch        *b_status;   //!
   TBranch        *b_Mass;   //!
   TBranch        *b_Eng;   //!
   TBranch        *b_EndE;   //!
   TBranch        *b_Px;   //!
   TBranch        *b_Py;   //!
   TBranch        *b_Pz;   //!
   TBranch        *b_P;   //!
   TBranch        *b_StartPointx;   //!
   TBranch        *b_StartPointy;   //!
   TBranch        *b_StartPointz;   //!
   TBranch        *b_StartT;   //!
   TBranch        *b_EndPointx;   //!
   TBranch        *b_EndPointy;   //!
   TBranch        *b_EndPointz;   //!
   TBranch        *b_EndT;   //!
   TBranch        *b_theta;   //!
   TBranch        *b_phi;   //!
   TBranch        *b_theta_xz;   //!
   TBranch        *b_theta_yz;   //!
   TBranch        *b_pathlen;   //!
   TBranch        *b_inTPCActive;   //!
   TBranch        *b_StartPointx_tpcAV;   //!
   TBranch        *b_StartPointy_tpcAV;   //!
   TBranch        *b_StartPointz_tpcAV;   //!
   TBranch        *b_EndPointx_tpcAV;   //!
   TBranch        *b_EndPointy_tpcAV;   //!
   TBranch        *b_EndPointz_tpcAV;   //!
   TBranch        *b_NumberDaughters;   //!
   TBranch        *b_Mother;   //!
   TBranch        *b_TrackId;   //!
   TBranch        *b_MergedId;   //!
   TBranch        *b_MotherNuId;   //!
   TBranch        *b_process_primary;   //!
   TBranch        *b_processname;   //!
   TBranch        *b_nvtx_pmalgtrackmaker;   //!
   TBranch        *b_vtx_pmalgtrackmaker;   //!
   TBranch        *b_nvtx_pandora;   //!
   TBranch        *b_primaryvtx_pandora;   //!
   TBranch        *b_vtx_pandora;   //!
   TBranch        *b_nshowers_pandoraShower;   //!
   TBranch        *b_shwId_pandoraShower;   //!
   TBranch        *b_shwbestplane_pandoraShower;   //!
   TBranch        *b_shwlength_pandoraShower;   //!
   TBranch        *b_shwopenangle_pandoraShower;   //!
   TBranch        *b_shwstartx_pandoraShower;   //!
   TBranch        *b_shwstarty_pandoraShower;   //!
   TBranch        *b_shwstartz_pandoraShower;   //!
   TBranch        *b_shwdirx_pandoraShower;   //!
   TBranch        *b_shwdiry_pandoraShower;   //!
   TBranch        *b_shwdirz_pandoraShower;   //!
   TBranch        *b_shwisprimary_pandoraShower;   //!
   TBranch        *b_shwndaughters_pandoraShower;   //!
   TBranch        *b_shwpfpid_pandoraShower;   //!
   TBranch        *b_shwparentpfpid_pandoraShower;   //!
   TBranch        *b_ntracks_pmalgtrackmaker;   //!
   TBranch        *b_trkId_pmalgtrackmaker;   //!
   TBranch        *b_trkncosmictags_tagger_pmalgtrackmaker;   //!
   TBranch        *b_trkcosmicscore_tagger_pmalgtrackmaker;   //!
   TBranch        *b_trkcosmictype_tagger_pmalgtrackmaker;   //!
   TBranch        *b_trkncosmictags_flashmatch_pmalgtrackmaker;   //!
   TBranch        *b_trkcosmicscore_flashmatch_pmalgtrackmaker;   //!
   TBranch        *b_trkcosmictype_flashmatch_pmalgtrackmaker;   //!
   TBranch        *b_trkke_pmalgtrackmaker;   //!
   TBranch        *b_trkrange_pmalgtrackmaker;   //!
   TBranch        *b_trkidtruth_recoutils_totaltrueenergy_pmalgtrackmaker;   //!
   TBranch        *b_trkidtruth_recoutils_totalrecocharge_pmalgtrackmaker;   //!
   TBranch        *b_trkidtruth_recoutils_totalrecohits_pmalgtrackmaker;   //!
   TBranch        *b_trkidtruth_pmalgtrackmaker;   //!
   TBranch        *b_trkorigin_pmalgtrackmaker;   //!
   TBranch        *b_trkpdgtruth_pmalgtrackmaker;   //!
   TBranch        *b_trkefftruth_pmalgtrackmaker;   //!
   TBranch        *b_trksimIDEenergytruth_pmalgtrackmaker;   //!
   TBranch        *b_trksimIDExtruth_pmalgtrackmaker;   //!
   TBranch        *b_trksimIDEytruth_pmalgtrackmaker;   //!
   TBranch        *b_trksimIDEztruth_pmalgtrackmaker;   //!
   TBranch        *b_trkpurtruth_pmalgtrackmaker;   //!
   TBranch        *b_trkpitchc_pmalgtrackmaker;   //!
   TBranch        *b_ntrkhits_pmalgtrackmaker;   //!
   TBranch        *b_trkstartx_pmalgtrackmaker;   //!
   TBranch        *b_trkstarty_pmalgtrackmaker;   //!
   TBranch        *b_trkstartz_pmalgtrackmaker;   //!
   TBranch        *b_trkstartd_pmalgtrackmaker;   //!
   TBranch        *b_trkendx_pmalgtrackmaker;   //!
   TBranch        *b_trkendy_pmalgtrackmaker;   //!
   TBranch        *b_trkendz_pmalgtrackmaker;   //!
   TBranch        *b_trkendd_pmalgtrackmaker;   //!
   TBranch        *b_trktheta_pmalgtrackmaker;   //!
   TBranch        *b_trkphi_pmalgtrackmaker;   //!
   TBranch        *b_trkstartdcosx_pmalgtrackmaker;   //!
   TBranch        *b_trkstartdcosy_pmalgtrackmaker;   //!
   TBranch        *b_trkstartdcosz_pmalgtrackmaker;   //!
   TBranch        *b_trkenddcosx_pmalgtrackmaker;   //!
   TBranch        *b_trkenddcosy_pmalgtrackmaker;   //!
   TBranch        *b_trkenddcosz_pmalgtrackmaker;   //!
   TBranch        *b_trkthetaxz_pmalgtrackmaker;   //!
   TBranch        *b_trkthetayz_pmalgtrackmaker;   //!
   TBranch        *b_trkmom_pmalgtrackmaker;   //!
   TBranch        *b_trkmomrange_pmalgtrackmaker;   //!
   TBranch        *b_trkmommschi2_pmalgtrackmaker;   //!
   TBranch        *b_trkmommsllhd_pmalgtrackmaker;   //!
   TBranch        *b_trklen_pmalgtrackmaker;   //!
   TBranch        *b_trksvtxid_pmalgtrackmaker;   //!
   TBranch        *b_trkevtxid_pmalgtrackmaker;   //!
   TBranch        *b_trkpidpdg_pmalgtrackmaker;   //!
   TBranch        *b_trkpidchi_pmalgtrackmaker;   //!
   TBranch        *b_trkpidchipr_pmalgtrackmaker;   //!
   TBranch        *b_trkpidchika_pmalgtrackmaker;   //!
   TBranch        *b_trkpidchipi_pmalgtrackmaker;   //!
   TBranch        *b_trkpidchimu_pmalgtrackmaker;   //!
   TBranch        *b_trkpidpida_pmalgtrackmaker;   //!
   TBranch        *b_trkpidbestplane_pmalgtrackmaker;   //!
   TBranch        *b_ntracks_pandoraTrack;   //!
   TBranch        *b_trkId_pandoraTrack;   //!
   TBranch        *b_trkncosmictags_tagger_pandoraTrack;   //!
   TBranch        *b_trkcosmicscore_tagger_pandoraTrack;   //!
   TBranch        *b_trkcosmictype_tagger_pandoraTrack;   //!
   TBranch        *b_trkncosmictags_flashmatch_pandoraTrack;   //!
   TBranch        *b_trkcosmicscore_flashmatch_pandoraTrack;   //!
   TBranch        *b_trkcosmictype_flashmatch_pandoraTrack;   //!
   TBranch        *b_trkke_pandoraTrack;   //!
   TBranch        *b_trkrange_pandoraTrack;   //!
   TBranch        *b_trkidtruth_recoutils_totaltrueenergy_pandoraTrack;   //!
   TBranch        *b_trkidtruth_recoutils_totalrecocharge_pandoraTrack;   //!
   TBranch        *b_trkidtruth_recoutils_totalrecohits_pandoraTrack;   //!
   TBranch        *b_trkidtruth_pandoraTrack;   //!
   TBranch        *b_trkorigin_pandoraTrack;   //!
   TBranch        *b_trkpdgtruth_pandoraTrack;   //!
   TBranch        *b_trkefftruth_pandoraTrack;   //!
   TBranch        *b_trksimIDEenergytruth_pandoraTrack;   //!
   TBranch        *b_trksimIDExtruth_pandoraTrack;   //!
   TBranch        *b_trksimIDEytruth_pandoraTrack;   //!
   TBranch        *b_trksimIDEztruth_pandoraTrack;   //!
   TBranch        *b_trkpurtruth_pandoraTrack;   //!
   TBranch        *b_trkpitchc_pandoraTrack;   //!
   TBranch        *b_ntrkhits_pandoraTrack;   //!
   TBranch        *b_trkstartx_pandoraTrack;   //!
   TBranch        *b_trkstarty_pandoraTrack;   //!
   TBranch        *b_trkstartz_pandoraTrack;   //!
   TBranch        *b_trkstartd_pandoraTrack;   //!
   TBranch        *b_trkendx_pandoraTrack;   //!
   TBranch        *b_trkendy_pandoraTrack;   //!
   TBranch        *b_trkendz_pandoraTrack;   //!
   TBranch        *b_trkendd_pandoraTrack;   //!
   TBranch        *b_trktheta_pandoraTrack;   //!
   TBranch        *b_trkphi_pandoraTrack;   //!
   TBranch        *b_trkstartdcosx_pandoraTrack;   //!
   TBranch        *b_trkstartdcosy_pandoraTrack;   //!
   TBranch        *b_trkstartdcosz_pandoraTrack;   //!
   TBranch        *b_trkenddcosx_pandoraTrack;   //!
   TBranch        *b_trkenddcosy_pandoraTrack;   //!
   TBranch        *b_trkenddcosz_pandoraTrack;   //!
   TBranch        *b_trkthetaxz_pandoraTrack;   //!
   TBranch        *b_trkthetayz_pandoraTrack;   //!
   TBranch        *b_trkmom_pandoraTrack;   //!
   TBranch        *b_trkmomrange_pandoraTrack;   //!
   TBranch        *b_trkmommschi2_pandoraTrack;   //!
   TBranch        *b_trkmommsllhd_pandoraTrack;   //!
   TBranch        *b_trklen_pandoraTrack;   //!
   TBranch        *b_trksvtxid_pandoraTrack;   //!
   TBranch        *b_trkevtxid_pandoraTrack;   //!
   TBranch        *b_trkpidpdg_pandoraTrack;   //!
   TBranch        *b_trkpidchi_pandoraTrack;   //!
   TBranch        *b_trkpidchipr_pandoraTrack;   //!
   TBranch        *b_trkpidchika_pandoraTrack;   //!
   TBranch        *b_trkpidchipi_pandoraTrack;   //!
   TBranch        *b_trkpidchimu_pandoraTrack;   //!
   TBranch        *b_trkpidpida_pandoraTrack;   //!
   TBranch        *b_trkpidbestplane_pandoraTrack;   //!
   TBranch        *b_trkisprimary_pandoraTrack;   //!
   TBranch        *b_trkndaughters_pandoraTrack;   //!
   TBranch        *b_trkpfpid_pandoraTrack;   //!
   TBranch        *b_trkparentpfpid_pandoraTrack;   //!

   endpoints(TTree *tree=0);
   virtual ~endpoints();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef endpoints_cxx
endpoints::endpoints(TTree *tree) : fChain(0)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("reco-a6725708-f2f1-4a11-800c-2e9cac4f5d95_AnaTree-20190802T161208.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("reco-a6725708-f2f1-4a11-800c-2e9cac4f5d95_AnaTree-20190802T161208.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("reco-a6725708-f2f1-4a11-800c-2e9cac4f5d95_AnaTree-20190802T161208.root:/analysistree");
      dir->GetObject("anatree",tree);

   }
   Init(tree);
}

endpoints::~endpoints()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t endpoints::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t endpoints::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void endpoints::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   processname = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("subrun", &subrun, &b_subrun);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("evttime", &evttime, &b_evttime);
   fChain->SetBranchAddress("beamtime", &beamtime, &b_beamtime);
   fChain->SetBranchAddress("pot", &pot, &b_pot);
   fChain->SetBranchAddress("isdata", &isdata, &b_isdata);
   fChain->SetBranchAddress("no_hits", &no_hits, &b_no_hits);
   fChain->SetBranchAddress("hit_tpc", hit_tpc, &b_hit_tpc);
   fChain->SetBranchAddress("hit_plane", hit_plane, &b_hit_plane);
   fChain->SetBranchAddress("hit_wire", hit_wire, &b_hit_wire);
   fChain->SetBranchAddress("hit_channel", hit_channel, &b_hit_channel);
   fChain->SetBranchAddress("hit_peakT", hit_peakT, &b_hit_peakT);
   fChain->SetBranchAddress("hit_charge", hit_charge, &b_hit_charge);
   fChain->SetBranchAddress("hit_ph", hit_ph, &b_hit_ph);
   fChain->SetBranchAddress("hit_startT", hit_startT, &b_hit_startT);
   fChain->SetBranchAddress("hit_endT", hit_endT, &b_hit_endT);
   fChain->SetBranchAddress("hit_trkid", hit_trkid, &b_hit_trkid);
   fChain->SetBranchAddress("hit_nelec", hit_nelec, &b_hit_nelec);
   fChain->SetBranchAddress("hit_energy", hit_energy, &b_hit_energy);
   fChain->SetBranchAddress("kNTracker", &kNTracker, &b_kNTracker);
   fChain->SetBranchAddress("mcevts_truth", &mcevts_truth, &b_mcevts_truth);
   fChain->SetBranchAddress("nuScatterCode_truth", &nuScatterCode_truth, &b_nuScatterCode_truth);
   fChain->SetBranchAddress("nuID_truth", &nuID_truth, &b_nuID_truth);
   fChain->SetBranchAddress("nuPDG_truth", &nuPDG_truth, &b_nuPDG_truth);
   fChain->SetBranchAddress("ccnc_truth", &ccnc_truth, &b_ccnc_truth);
   fChain->SetBranchAddress("mode_truth", &mode_truth, &b_mode_truth);
   fChain->SetBranchAddress("enu_truth", &enu_truth, &b_enu_truth);
   fChain->SetBranchAddress("Q2_truth", &Q2_truth, &b_Q2_truth);
   fChain->SetBranchAddress("W_truth", &W_truth, &b_W_truth);
   fChain->SetBranchAddress("hitnuc_truth", &hitnuc_truth, &b_hitnuc_truth);
   fChain->SetBranchAddress("nuvtxx_truth", &nuvtxx_truth, &b_nuvtxx_truth);
   fChain->SetBranchAddress("nuvtxy_truth", &nuvtxy_truth, &b_nuvtxy_truth);
   fChain->SetBranchAddress("nuvtxz_truth", &nuvtxz_truth, &b_nuvtxz_truth);
   fChain->SetBranchAddress("nu_dcosx_truth", &nu_dcosx_truth, &b_nu_dcosx_truth);
   fChain->SetBranchAddress("nu_dcosy_truth", &nu_dcosy_truth, &b_nu_dcosy_truth);
   fChain->SetBranchAddress("nu_dcosz_truth", &nu_dcosz_truth, &b_nu_dcosz_truth);
   fChain->SetBranchAddress("lep_mom_truth", &lep_mom_truth, &b_lep_mom_truth);
   fChain->SetBranchAddress("lep_dcosx_truth", &lep_dcosx_truth, &b_lep_dcosx_truth);
   fChain->SetBranchAddress("lep_dcosy_truth", &lep_dcosy_truth, &b_lep_dcosy_truth);
   fChain->SetBranchAddress("lep_dcosz_truth", &lep_dcosz_truth, &b_lep_dcosz_truth);
   fChain->SetBranchAddress("tpx_flux", &tpx_flux, &b_tpx_flux);
   fChain->SetBranchAddress("tpy_flux", &tpy_flux, &b_tpy_flux);
   fChain->SetBranchAddress("tpz_flux", &tpz_flux, &b_tpz_flux);
   fChain->SetBranchAddress("tptype_flux", &tptype_flux, &b_tptype_flux);
   fChain->SetBranchAddress("genie_no_primaries", &genie_no_primaries, &b_genie_no_primaries);
   fChain->SetBranchAddress("genie_primaries_pdg", &genie_primaries_pdg, &b_genie_primaries_pdg);
   fChain->SetBranchAddress("genie_Eng", &genie_Eng, &b_genie_Eng);
   fChain->SetBranchAddress("genie_Px", &genie_Px, &b_genie_Px);
   fChain->SetBranchAddress("genie_Py", &genie_Py, &b_genie_Py);
   fChain->SetBranchAddress("genie_Pz", &genie_Pz, &b_genie_Pz);
   fChain->SetBranchAddress("genie_P", &genie_P, &b_genie_P);
   fChain->SetBranchAddress("genie_status_code", &genie_status_code, &b_genie_status_code);
   fChain->SetBranchAddress("genie_mass", &genie_mass, &b_genie_mass);
   fChain->SetBranchAddress("genie_trackID", &genie_trackID, &b_genie_trackID);
   fChain->SetBranchAddress("genie_ND", &genie_ND, &b_genie_ND);
   fChain->SetBranchAddress("genie_mother", &genie_mother, &b_genie_mother);
   fChain->SetBranchAddress("mcevts_truthcry", &mcevts_truthcry, &b_mcevts_truthcry);
   fChain->SetBranchAddress("cry_no_primaries", &cry_no_primaries, &b_cry_no_primaries);
   fChain->SetBranchAddress("cry_primaries_pdg", cry_primaries_pdg, &b_cry_primaries_pdg);
   fChain->SetBranchAddress("cry_Eng", cry_Eng, &b_cry_Eng);
   fChain->SetBranchAddress("cry_Px", cry_Px, &b_cry_Px);
   fChain->SetBranchAddress("cry_Py", cry_Py, &b_cry_Py);
   fChain->SetBranchAddress("cry_Pz", cry_Pz, &b_cry_Pz);
   fChain->SetBranchAddress("cry_P", cry_P, &b_cry_P);
   fChain->SetBranchAddress("cry_StartPointx", cry_StartPointx, &b_cry_StartPointx);
   fChain->SetBranchAddress("cry_StartPointy", cry_StartPointy, &b_cry_StartPointy);
   fChain->SetBranchAddress("cry_StartPointz", cry_StartPointz, &b_cry_StartPointz);
   fChain->SetBranchAddress("cry_status_code", cry_status_code, &b_cry_status_code);
   fChain->SetBranchAddress("cry_mass", cry_mass, &b_cry_mass);
   fChain->SetBranchAddress("cry_trackID", cry_trackID, &b_cry_trackID);
   fChain->SetBranchAddress("cry_ND", cry_ND, &b_cry_ND);
   fChain->SetBranchAddress("cry_mother", cry_mother, &b_cry_mother);
   fChain->SetBranchAddress("no_primaries", &no_primaries, &b_no_primaries);
   fChain->SetBranchAddress("geant_list_size", &geant_list_size, &b_geant_list_size);
   fChain->SetBranchAddress("geant_list_size_in_tpcAV", &geant_list_size_in_tpcAV, &b_geant_list_size_in_tpcAV);
   fChain->SetBranchAddress("pdg", pdg, &b_pdg);
   fChain->SetBranchAddress("status", status, &b_status);
   fChain->SetBranchAddress("Mass", Mass, &b_Mass);
   fChain->SetBranchAddress("Eng", Eng, &b_Eng);
   fChain->SetBranchAddress("EndE", EndE, &b_EndE);
   fChain->SetBranchAddress("Px", Px, &b_Px);
   fChain->SetBranchAddress("Py", Py, &b_Py);
   fChain->SetBranchAddress("Pz", Pz, &b_Pz);
   fChain->SetBranchAddress("P", P, &b_P);
   fChain->SetBranchAddress("StartPointx", StartPointx, &b_StartPointx);
   fChain->SetBranchAddress("StartPointy", StartPointy, &b_StartPointy);
   fChain->SetBranchAddress("StartPointz", StartPointz, &b_StartPointz);
   fChain->SetBranchAddress("StartT", StartT, &b_StartT);
   fChain->SetBranchAddress("EndPointx", EndPointx, &b_EndPointx);
   fChain->SetBranchAddress("EndPointy", EndPointy, &b_EndPointy);
   fChain->SetBranchAddress("EndPointz", EndPointz, &b_EndPointz);
   fChain->SetBranchAddress("EndT", EndT, &b_EndT);
   fChain->SetBranchAddress("theta", theta, &b_theta);
   fChain->SetBranchAddress("phi", phi, &b_phi);
   fChain->SetBranchAddress("theta_xz", theta_xz, &b_theta_xz);
   fChain->SetBranchAddress("theta_yz", theta_yz, &b_theta_yz);
   fChain->SetBranchAddress("pathlen", pathlen, &b_pathlen);
   fChain->SetBranchAddress("inTPCActive", inTPCActive, &b_inTPCActive);
   fChain->SetBranchAddress("StartPointx_tpcAV", StartPointx_tpcAV, &b_StartPointx_tpcAV);
   fChain->SetBranchAddress("StartPointy_tpcAV", StartPointy_tpcAV, &b_StartPointy_tpcAV);
   fChain->SetBranchAddress("StartPointz_tpcAV", StartPointz_tpcAV, &b_StartPointz_tpcAV);
   fChain->SetBranchAddress("EndPointx_tpcAV", EndPointx_tpcAV, &b_EndPointx_tpcAV);
   fChain->SetBranchAddress("EndPointy_tpcAV", EndPointy_tpcAV, &b_EndPointy_tpcAV);
   fChain->SetBranchAddress("EndPointz_tpcAV", EndPointz_tpcAV, &b_EndPointz_tpcAV);
   fChain->SetBranchAddress("NumberDaughters", NumberDaughters, &b_NumberDaughters);
   fChain->SetBranchAddress("Mother", Mother, &b_Mother);
   fChain->SetBranchAddress("TrackId", TrackId, &b_TrackId);
   fChain->SetBranchAddress("MergedId", MergedId, &b_MergedId);
   fChain->SetBranchAddress("MotherNuId", MotherNuId, &b_MotherNuId);
   fChain->SetBranchAddress("process_primary", process_primary, &b_process_primary);
   fChain->SetBranchAddress("processname", &processname, &b_processname);
   fChain->SetBranchAddress("nvtx_pmalgtrackmaker", &nvtx_pmalgtrackmaker, &b_nvtx_pmalgtrackmaker);
   fChain->SetBranchAddress("vtx_pmalgtrackmaker", vtx_pmalgtrackmaker, &b_vtx_pmalgtrackmaker);
   fChain->SetBranchAddress("nvtx_pandora", &nvtx_pandora, &b_nvtx_pandora);
   fChain->SetBranchAddress("primaryvtx_pandora", primaryvtx_pandora, &b_primaryvtx_pandora);
   fChain->SetBranchAddress("vtx_pandora", vtx_pandora, &b_vtx_pandora);
   fChain->SetBranchAddress("nshowers_pandoraShower", &nshowers_pandoraShower, &b_nshowers_pandoraShower);
   fChain->SetBranchAddress("shwId_pandoraShower", shwId_pandoraShower, &b_shwId_pandoraShower);
   fChain->SetBranchAddress("shwbestplane_pandoraShower", shwbestplane_pandoraShower, &b_shwbestplane_pandoraShower);
   fChain->SetBranchAddress("shwlength_pandoraShower", shwlength_pandoraShower, &b_shwlength_pandoraShower);
   fChain->SetBranchAddress("shwopenangle_pandoraShower", shwopenangle_pandoraShower, &b_shwopenangle_pandoraShower);
   fChain->SetBranchAddress("shwstartx_pandoraShower", shwstartx_pandoraShower, &b_shwstartx_pandoraShower);
   fChain->SetBranchAddress("shwstarty_pandoraShower", shwstarty_pandoraShower, &b_shwstarty_pandoraShower);
   fChain->SetBranchAddress("shwstartz_pandoraShower", shwstartz_pandoraShower, &b_shwstartz_pandoraShower);
   fChain->SetBranchAddress("shwdirx_pandoraShower", shwdirx_pandoraShower, &b_shwdirx_pandoraShower);
   fChain->SetBranchAddress("shwdiry_pandoraShower", shwdiry_pandoraShower, &b_shwdiry_pandoraShower);
   fChain->SetBranchAddress("shwdirz_pandoraShower", shwdirz_pandoraShower, &b_shwdirz_pandoraShower);
   fChain->SetBranchAddress("shwisprimary_pandoraShower", shwisprimary_pandoraShower, &b_shwisprimary_pandoraShower);
   fChain->SetBranchAddress("shwndaughters_pandoraShower", shwndaughters_pandoraShower, &b_shwndaughters_pandoraShower);
   fChain->SetBranchAddress("shwpfpid_pandoraShower", shwpfpid_pandoraShower, &b_shwpfpid_pandoraShower);
   fChain->SetBranchAddress("shwparentpfpid_pandoraShower", shwparentpfpid_pandoraShower, &b_shwparentpfpid_pandoraShower);
   fChain->SetBranchAddress("ntracks_pmalgtrackmaker", &ntracks_pmalgtrackmaker, &b_ntracks_pmalgtrackmaker);
   fChain->SetBranchAddress("trkId_pmalgtrackmaker", trkId_pmalgtrackmaker, &b_trkId_pmalgtrackmaker);
   fChain->SetBranchAddress("trkncosmictags_tagger_pmalgtrackmaker", trkncosmictags_tagger_pmalgtrackmaker, &b_trkncosmictags_tagger_pmalgtrackmaker);
   fChain->SetBranchAddress("trkcosmicscore_tagger_pmalgtrackmaker", trkcosmicscore_tagger_pmalgtrackmaker, &b_trkcosmicscore_tagger_pmalgtrackmaker);
   fChain->SetBranchAddress("trkcosmictype_tagger_pmalgtrackmaker", trkcosmictype_tagger_pmalgtrackmaker, &b_trkcosmictype_tagger_pmalgtrackmaker);
   fChain->SetBranchAddress("trkncosmictags_flashmatch_pmalgtrackmaker", trkncosmictags_flashmatch_pmalgtrackmaker, &b_trkncosmictags_flashmatch_pmalgtrackmaker);
   fChain->SetBranchAddress("trkcosmicscore_flashmatch_pmalgtrackmaker", trkcosmicscore_flashmatch_pmalgtrackmaker, &b_trkcosmicscore_flashmatch_pmalgtrackmaker);
   fChain->SetBranchAddress("trkcosmictype_flashmatch_pmalgtrackmaker", trkcosmictype_flashmatch_pmalgtrackmaker, &b_trkcosmictype_flashmatch_pmalgtrackmaker);
   fChain->SetBranchAddress("trkke_pmalgtrackmaker", trkke_pmalgtrackmaker, &b_trkke_pmalgtrackmaker);
   fChain->SetBranchAddress("trkrange_pmalgtrackmaker", trkrange_pmalgtrackmaker, &b_trkrange_pmalgtrackmaker);
   fChain->SetBranchAddress("trkidtruth_recoutils_totaltrueenergy_pmalgtrackmaker", trkidtruth_recoutils_totaltrueenergy_pmalgtrackmaker, &b_trkidtruth_recoutils_totaltrueenergy_pmalgtrackmaker);
   fChain->SetBranchAddress("trkidtruth_recoutils_totalrecocharge_pmalgtrackmaker", trkidtruth_recoutils_totalrecocharge_pmalgtrackmaker, &b_trkidtruth_recoutils_totalrecocharge_pmalgtrackmaker);
   fChain->SetBranchAddress("trkidtruth_recoutils_totalrecohits_pmalgtrackmaker", trkidtruth_recoutils_totalrecohits_pmalgtrackmaker, &b_trkidtruth_recoutils_totalrecohits_pmalgtrackmaker);
   fChain->SetBranchAddress("trkidtruth_pmalgtrackmaker", trkidtruth_pmalgtrackmaker, &b_trkidtruth_pmalgtrackmaker);
   fChain->SetBranchAddress("trkorigin_pmalgtrackmaker", trkorigin_pmalgtrackmaker, &b_trkorigin_pmalgtrackmaker);
   fChain->SetBranchAddress("trkpdgtruth_pmalgtrackmaker", trkpdgtruth_pmalgtrackmaker, &b_trkpdgtruth_pmalgtrackmaker);
   fChain->SetBranchAddress("trkefftruth_pmalgtrackmaker", trkefftruth_pmalgtrackmaker, &b_trkefftruth_pmalgtrackmaker);
   fChain->SetBranchAddress("trksimIDEenergytruth_pmalgtrackmaker", trksimIDEenergytruth_pmalgtrackmaker, &b_trksimIDEenergytruth_pmalgtrackmaker);
   fChain->SetBranchAddress("trksimIDExtruth_pmalgtrackmaker", trksimIDExtruth_pmalgtrackmaker, &b_trksimIDExtruth_pmalgtrackmaker);
   fChain->SetBranchAddress("trksimIDEytruth_pmalgtrackmaker", trksimIDEytruth_pmalgtrackmaker, &b_trksimIDEytruth_pmalgtrackmaker);
   fChain->SetBranchAddress("trksimIDEztruth_pmalgtrackmaker", trksimIDEztruth_pmalgtrackmaker, &b_trksimIDEztruth_pmalgtrackmaker);
   fChain->SetBranchAddress("trkpurtruth_pmalgtrackmaker", trkpurtruth_pmalgtrackmaker, &b_trkpurtruth_pmalgtrackmaker);
   fChain->SetBranchAddress("trkpitchc_pmalgtrackmaker", trkpitchc_pmalgtrackmaker, &b_trkpitchc_pmalgtrackmaker);
   fChain->SetBranchAddress("ntrkhits_pmalgtrackmaker", ntrkhits_pmalgtrackmaker, &b_ntrkhits_pmalgtrackmaker);
   fChain->SetBranchAddress("trkstartx_pmalgtrackmaker", trkstartx_pmalgtrackmaker, &b_trkstartx_pmalgtrackmaker);
   fChain->SetBranchAddress("trkstarty_pmalgtrackmaker", trkstarty_pmalgtrackmaker, &b_trkstarty_pmalgtrackmaker);
   fChain->SetBranchAddress("trkstartz_pmalgtrackmaker", trkstartz_pmalgtrackmaker, &b_trkstartz_pmalgtrackmaker);
   fChain->SetBranchAddress("trkstartd_pmalgtrackmaker", trkstartd_pmalgtrackmaker, &b_trkstartd_pmalgtrackmaker);
   fChain->SetBranchAddress("trkendx_pmalgtrackmaker", trkendx_pmalgtrackmaker, &b_trkendx_pmalgtrackmaker);
   fChain->SetBranchAddress("trkendy_pmalgtrackmaker", trkendy_pmalgtrackmaker, &b_trkendy_pmalgtrackmaker);
   fChain->SetBranchAddress("trkendz_pmalgtrackmaker", trkendz_pmalgtrackmaker, &b_trkendz_pmalgtrackmaker);
   fChain->SetBranchAddress("trkendd_pmalgtrackmaker", trkendd_pmalgtrackmaker, &b_trkendd_pmalgtrackmaker);
   fChain->SetBranchAddress("trktheta_pmalgtrackmaker", trktheta_pmalgtrackmaker, &b_trktheta_pmalgtrackmaker);
   fChain->SetBranchAddress("trkphi_pmalgtrackmaker", trkphi_pmalgtrackmaker, &b_trkphi_pmalgtrackmaker);
   fChain->SetBranchAddress("trkstartdcosx_pmalgtrackmaker", trkstartdcosx_pmalgtrackmaker, &b_trkstartdcosx_pmalgtrackmaker);
   fChain->SetBranchAddress("trkstartdcosy_pmalgtrackmaker", trkstartdcosy_pmalgtrackmaker, &b_trkstartdcosy_pmalgtrackmaker);
   fChain->SetBranchAddress("trkstartdcosz_pmalgtrackmaker", trkstartdcosz_pmalgtrackmaker, &b_trkstartdcosz_pmalgtrackmaker);
   fChain->SetBranchAddress("trkenddcosx_pmalgtrackmaker", trkenddcosx_pmalgtrackmaker, &b_trkenddcosx_pmalgtrackmaker);
   fChain->SetBranchAddress("trkenddcosy_pmalgtrackmaker", trkenddcosy_pmalgtrackmaker, &b_trkenddcosy_pmalgtrackmaker);
   fChain->SetBranchAddress("trkenddcosz_pmalgtrackmaker", trkenddcosz_pmalgtrackmaker, &b_trkenddcosz_pmalgtrackmaker);
   fChain->SetBranchAddress("trkthetaxz_pmalgtrackmaker", trkthetaxz_pmalgtrackmaker, &b_trkthetaxz_pmalgtrackmaker);
   fChain->SetBranchAddress("trkthetayz_pmalgtrackmaker", trkthetayz_pmalgtrackmaker, &b_trkthetayz_pmalgtrackmaker);
   fChain->SetBranchAddress("trkmom_pmalgtrackmaker", trkmom_pmalgtrackmaker, &b_trkmom_pmalgtrackmaker);
   fChain->SetBranchAddress("trkmomrange_pmalgtrackmaker", trkmomrange_pmalgtrackmaker, &b_trkmomrange_pmalgtrackmaker);
   fChain->SetBranchAddress("trkmommschi2_pmalgtrackmaker", trkmommschi2_pmalgtrackmaker, &b_trkmommschi2_pmalgtrackmaker);
   fChain->SetBranchAddress("trkmommsllhd_pmalgtrackmaker", trkmommsllhd_pmalgtrackmaker, &b_trkmommsllhd_pmalgtrackmaker);
   fChain->SetBranchAddress("trklen_pmalgtrackmaker", trklen_pmalgtrackmaker, &b_trklen_pmalgtrackmaker);
   fChain->SetBranchAddress("trksvtxid_pmalgtrackmaker", trksvtxid_pmalgtrackmaker, &b_trksvtxid_pmalgtrackmaker);
   fChain->SetBranchAddress("trkevtxid_pmalgtrackmaker", trkevtxid_pmalgtrackmaker, &b_trkevtxid_pmalgtrackmaker);
   fChain->SetBranchAddress("trkpidpdg_pmalgtrackmaker", trkpidpdg_pmalgtrackmaker, &b_trkpidpdg_pmalgtrackmaker);
   fChain->SetBranchAddress("trkpidchi_pmalgtrackmaker", trkpidchi_pmalgtrackmaker, &b_trkpidchi_pmalgtrackmaker);
   fChain->SetBranchAddress("trkpidchipr_pmalgtrackmaker", trkpidchipr_pmalgtrackmaker, &b_trkpidchipr_pmalgtrackmaker);
   fChain->SetBranchAddress("trkpidchika_pmalgtrackmaker", trkpidchika_pmalgtrackmaker, &b_trkpidchika_pmalgtrackmaker);
   fChain->SetBranchAddress("trkpidchipi_pmalgtrackmaker", trkpidchipi_pmalgtrackmaker, &b_trkpidchipi_pmalgtrackmaker);
   fChain->SetBranchAddress("trkpidchimu_pmalgtrackmaker", trkpidchimu_pmalgtrackmaker, &b_trkpidchimu_pmalgtrackmaker);
   fChain->SetBranchAddress("trkpidpida_pmalgtrackmaker", trkpidpida_pmalgtrackmaker, &b_trkpidpida_pmalgtrackmaker);
   fChain->SetBranchAddress("trkpidbestplane_pmalgtrackmaker", trkpidbestplane_pmalgtrackmaker, &b_trkpidbestplane_pmalgtrackmaker);
   fChain->SetBranchAddress("ntracks_pandoraTrack", &ntracks_pandoraTrack, &b_ntracks_pandoraTrack);
   fChain->SetBranchAddress("trkId_pandoraTrack", trkId_pandoraTrack, &b_trkId_pandoraTrack);
   fChain->SetBranchAddress("trkncosmictags_tagger_pandoraTrack", trkncosmictags_tagger_pandoraTrack, &b_trkncosmictags_tagger_pandoraTrack);
   fChain->SetBranchAddress("trkcosmicscore_tagger_pandoraTrack", trkcosmicscore_tagger_pandoraTrack, &b_trkcosmicscore_tagger_pandoraTrack);
   fChain->SetBranchAddress("trkcosmictype_tagger_pandoraTrack", trkcosmictype_tagger_pandoraTrack, &b_trkcosmictype_tagger_pandoraTrack);
   fChain->SetBranchAddress("trkncosmictags_flashmatch_pandoraTrack", trkncosmictags_flashmatch_pandoraTrack, &b_trkncosmictags_flashmatch_pandoraTrack);
   fChain->SetBranchAddress("trkcosmicscore_flashmatch_pandoraTrack", trkcosmicscore_flashmatch_pandoraTrack, &b_trkcosmicscore_flashmatch_pandoraTrack);
   fChain->SetBranchAddress("trkcosmictype_flashmatch_pandoraTrack", trkcosmictype_flashmatch_pandoraTrack, &b_trkcosmictype_flashmatch_pandoraTrack);
   fChain->SetBranchAddress("trkke_pandoraTrack", trkke_pandoraTrack, &b_trkke_pandoraTrack);
   fChain->SetBranchAddress("trkrange_pandoraTrack", trkrange_pandoraTrack, &b_trkrange_pandoraTrack);
   fChain->SetBranchAddress("trkidtruth_recoutils_totaltrueenergy_pandoraTrack", trkidtruth_recoutils_totaltrueenergy_pandoraTrack, &b_trkidtruth_recoutils_totaltrueenergy_pandoraTrack);
   fChain->SetBranchAddress("trkidtruth_recoutils_totalrecocharge_pandoraTrack", trkidtruth_recoutils_totalrecocharge_pandoraTrack, &b_trkidtruth_recoutils_totalrecocharge_pandoraTrack);
   fChain->SetBranchAddress("trkidtruth_recoutils_totalrecohits_pandoraTrack", trkidtruth_recoutils_totalrecohits_pandoraTrack, &b_trkidtruth_recoutils_totalrecohits_pandoraTrack);
   fChain->SetBranchAddress("trkidtruth_pandoraTrack", trkidtruth_pandoraTrack, &b_trkidtruth_pandoraTrack);
   fChain->SetBranchAddress("trkorigin_pandoraTrack", trkorigin_pandoraTrack, &b_trkorigin_pandoraTrack);
   fChain->SetBranchAddress("trkpdgtruth_pandoraTrack", trkpdgtruth_pandoraTrack, &b_trkpdgtruth_pandoraTrack);
   fChain->SetBranchAddress("trkefftruth_pandoraTrack", trkefftruth_pandoraTrack, &b_trkefftruth_pandoraTrack);
   fChain->SetBranchAddress("trksimIDEenergytruth_pandoraTrack", trksimIDEenergytruth_pandoraTrack, &b_trksimIDEenergytruth_pandoraTrack);
   fChain->SetBranchAddress("trksimIDExtruth_pandoraTrack", trksimIDExtruth_pandoraTrack, &b_trksimIDExtruth_pandoraTrack);
   fChain->SetBranchAddress("trksimIDEytruth_pandoraTrack", trksimIDEytruth_pandoraTrack, &b_trksimIDEytruth_pandoraTrack);
   fChain->SetBranchAddress("trksimIDEztruth_pandoraTrack", trksimIDEztruth_pandoraTrack, &b_trksimIDEztruth_pandoraTrack);
   fChain->SetBranchAddress("trkpurtruth_pandoraTrack", trkpurtruth_pandoraTrack, &b_trkpurtruth_pandoraTrack);
   fChain->SetBranchAddress("trkpitchc_pandoraTrack", trkpitchc_pandoraTrack, &b_trkpitchc_pandoraTrack);
   fChain->SetBranchAddress("ntrkhits_pandoraTrack", ntrkhits_pandoraTrack, &b_ntrkhits_pandoraTrack);
   fChain->SetBranchAddress("trkstartx_pandoraTrack", trkstartx_pandoraTrack, &b_trkstartx_pandoraTrack);
   fChain->SetBranchAddress("trkstarty_pandoraTrack", trkstarty_pandoraTrack, &b_trkstarty_pandoraTrack);
   fChain->SetBranchAddress("trkstartz_pandoraTrack", trkstartz_pandoraTrack, &b_trkstartz_pandoraTrack);
   fChain->SetBranchAddress("trkstartd_pandoraTrack", trkstartd_pandoraTrack, &b_trkstartd_pandoraTrack);
   fChain->SetBranchAddress("trkendx_pandoraTrack", trkendx_pandoraTrack, &b_trkendx_pandoraTrack);
   fChain->SetBranchAddress("trkendy_pandoraTrack", trkendy_pandoraTrack, &b_trkendy_pandoraTrack);
   fChain->SetBranchAddress("trkendz_pandoraTrack", trkendz_pandoraTrack, &b_trkendz_pandoraTrack);
   fChain->SetBranchAddress("trkendd_pandoraTrack", trkendd_pandoraTrack, &b_trkendd_pandoraTrack);
   fChain->SetBranchAddress("trktheta_pandoraTrack", trktheta_pandoraTrack, &b_trktheta_pandoraTrack);
   fChain->SetBranchAddress("trkphi_pandoraTrack", trkphi_pandoraTrack, &b_trkphi_pandoraTrack);
   fChain->SetBranchAddress("trkstartdcosx_pandoraTrack", trkstartdcosx_pandoraTrack, &b_trkstartdcosx_pandoraTrack);
   fChain->SetBranchAddress("trkstartdcosy_pandoraTrack", trkstartdcosy_pandoraTrack, &b_trkstartdcosy_pandoraTrack);
   fChain->SetBranchAddress("trkstartdcosz_pandoraTrack", trkstartdcosz_pandoraTrack, &b_trkstartdcosz_pandoraTrack);
   fChain->SetBranchAddress("trkenddcosx_pandoraTrack", trkenddcosx_pandoraTrack, &b_trkenddcosx_pandoraTrack);
   fChain->SetBranchAddress("trkenddcosy_pandoraTrack", trkenddcosy_pandoraTrack, &b_trkenddcosy_pandoraTrack);
   fChain->SetBranchAddress("trkenddcosz_pandoraTrack", trkenddcosz_pandoraTrack, &b_trkenddcosz_pandoraTrack);
   fChain->SetBranchAddress("trkthetaxz_pandoraTrack", trkthetaxz_pandoraTrack, &b_trkthetaxz_pandoraTrack);
   fChain->SetBranchAddress("trkthetayz_pandoraTrack", trkthetayz_pandoraTrack, &b_trkthetayz_pandoraTrack);
   fChain->SetBranchAddress("trkmom_pandoraTrack", trkmom_pandoraTrack, &b_trkmom_pandoraTrack);
   fChain->SetBranchAddress("trkmomrange_pandoraTrack", trkmomrange_pandoraTrack, &b_trkmomrange_pandoraTrack);
   fChain->SetBranchAddress("trkmommschi2_pandoraTrack", trkmommschi2_pandoraTrack, &b_trkmommschi2_pandoraTrack);
   fChain->SetBranchAddress("trkmommsllhd_pandoraTrack", trkmommsllhd_pandoraTrack, &b_trkmommsllhd_pandoraTrack);
   fChain->SetBranchAddress("trklen_pandoraTrack", trklen_pandoraTrack, &b_trklen_pandoraTrack);
   fChain->SetBranchAddress("trksvtxid_pandoraTrack", trksvtxid_pandoraTrack, &b_trksvtxid_pandoraTrack);
   fChain->SetBranchAddress("trkevtxid_pandoraTrack", trkevtxid_pandoraTrack, &b_trkevtxid_pandoraTrack);
   fChain->SetBranchAddress("trkpidpdg_pandoraTrack", trkpidpdg_pandoraTrack, &b_trkpidpdg_pandoraTrack);
   fChain->SetBranchAddress("trkpidchi_pandoraTrack", trkpidchi_pandoraTrack, &b_trkpidchi_pandoraTrack);
   fChain->SetBranchAddress("trkpidchipr_pandoraTrack", trkpidchipr_pandoraTrack, &b_trkpidchipr_pandoraTrack);
   fChain->SetBranchAddress("trkpidchika_pandoraTrack", trkpidchika_pandoraTrack, &b_trkpidchika_pandoraTrack);
   fChain->SetBranchAddress("trkpidchipi_pandoraTrack", trkpidchipi_pandoraTrack, &b_trkpidchipi_pandoraTrack);
   fChain->SetBranchAddress("trkpidchimu_pandoraTrack", trkpidchimu_pandoraTrack, &b_trkpidchimu_pandoraTrack);
   fChain->SetBranchAddress("trkpidpida_pandoraTrack", trkpidpida_pandoraTrack, &b_trkpidpida_pandoraTrack);
   fChain->SetBranchAddress("trkpidbestplane_pandoraTrack", trkpidbestplane_pandoraTrack, &b_trkpidbestplane_pandoraTrack);
   fChain->SetBranchAddress("trkisprimary_pandoraTrack", trkisprimary_pandoraTrack, &b_trkisprimary_pandoraTrack);
   fChain->SetBranchAddress("trkndaughters_pandoraTrack", trkndaughters_pandoraTrack, &b_trkndaughters_pandoraTrack);
   fChain->SetBranchAddress("trkpfpid_pandoraTrack", trkpfpid_pandoraTrack, &b_trkpfpid_pandoraTrack);
   fChain->SetBranchAddress("trkparentpfpid_pandoraTrack", trkparentpfpid_pandoraTrack, &b_trkparentpfpid_pandoraTrack);
   Notify();
}

Bool_t endpoints::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void endpoints::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t endpoints::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef endpoints_cxx
