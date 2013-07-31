#define mcfm_cxx
#include "mcfm.h"
#include <TH2.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TLorentzVector.h>
#include <TMath.h>
#include <TVector3.h>
#include <TStyle.h>
#include <TCanvas.h>

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>


void mcfm::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L mcfm.C
//      Root > mcfm t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch

  TH1F *h_m_dilep =new TH1F("h_m_dilep",";Mass Dilep(GeV); Events",120,0,60);
  TH1F *h_m_dilep_cut =new TH1F("h_m_dilep_cut",";Mass Dilep(GeV); Events",80,0,40);

  TH1F *h_DeltaR_three =new TH1F("h_DeltaR_three",";#Delta R (dilepton-#gamma); Events",100,0,6);
  TH1F *h_DeltaR_dilep =new TH1F("h_DeltaR_dilep",";#Delta R (l1-l2); Events",100,0,6);

  TH1F *h_m_three =new TH1F("h_m_three",";Mass Three Body(GeV); Events",75,40,190);
  TH1F *h_m_three_cut =new TH1F("h_m_three_cut",";Mass Three Body(GeV); Events",75,40,190);

  TH1F *h_DeltaR_three_cut =new TH1F("h_DeltaR_three_cut",";#Delta R (dilepton-#gamma); Events",100,0,6);
  TH1F *h_DeltaR_dilep_cut =new TH1F("h_DeltaR_dilep_cut",";#Delta R (l1-l2); Events",100,0,6);

  TH2F *h2_Deltar3_2mass = new TH2F("h2_Deltar3_2mass",";#Delta R (dilepton-#gamma); M(ll)(GeV)",100,0,6,100,0,20);
  TH2F *h2_Deltar3_3mass = new TH2F("h2_Deltar3_3mass",";#Delta R (dilepton-#gamma);3 Body Mass (GeV)",100,0,6,130,50,180);
  TH2F *h2_Deltar2_2mass = new TH2F("h2_Deltar2_2mass",";#Delta R (l1-l2);M(ll)(GeV)",100,0,1,100,0,20);
  TH2F *h2_Deltar2_3mass = new TH2F("h2_Deltar2_3mass",";#Delta R (l1-l2);3 Body Mass (GeV)",100,0,1,130,50,180);
  TH2F *h2_2mass_3mass = new TH2F("h2_2mass_3mass",";M(ll)(GeV);3 Body Mass (GeV)",20,0,20,130,50,180);
  TH2F *h2_ptlow_pthigh = new TH2F("h2_ptlow_pthigh",";pt low(GeV); pt high(GeV)",100,0,100,100,0,100);
  TH2F *h2_etgamma_3mass = new TH2F("h2_etgamma_3mass",";Et(#gamma)(GeV); 3 Body Mass (GeV)",100,0,100,130,50,180);
  TH2F *h2_ptbalance = new TH2F("h2_ptbalance",";pt balance (GeV); 3 Body Mass(GeV)",200,-100,100,130,50,180);



   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      //---------------------------- TLorentz vector declaration ------------------------------------                                                                                                        
      
      
      TLorentzVector p3((Double_t) px3,(Double_t) py3,(Double_t) pz3,(Double_t) E3);
      TLorentzVector p4((Double_t) px4,(Double_t) py4,(Double_t) pz4,(Double_t) E4);
      TLorentzVector p5((Double_t) px5,(Double_t) py5,(Double_t) pz5,(Double_t) E5);
      
      
      TLorentzVector pdi; 
      pdi = p3+p4;
      TLorentzVector pthree; 
      pthree = pdi+p5;
      Float_t high;
      Float_t low;
      

      //----------------------------------- Filling Histograms ----------------------------------                                                                                                            


      //------------------------------------- Declaration of cuts -------------------------------                                                                                                            
      Float_t Delta_pt;
      Delta_pt = pdi.Pt()-p5.Pt();
      h_m_dilep->Fill(pdi.Mag());
      h_m_three->Fill(pthree.Mag());
      h_DeltaR_three->Fill(pdi.DeltaR(p5));
      h_DeltaR_dilep->Fill(p3.DeltaR(p4));
      

      if(p3.Pt()>p4.Pt()){
        high=p3.Pt();
        low = p4.Pt();
      }
      else{
        high=p4.Pt();
        low = p3.Pt();
      }
      
      
      if(low>7){
        if(high>25){
          if(p5.Et()>15.0){
            if(pdi.Mag()<20.0){
              if(fabs(Delta_pt)<10.0){
		if(p3.DeltaR(p4)<1.0) {
                  if(pdi.DeltaR(p5)>0.4){

                    h_m_three_cut->Fill(pthree.Mag());
                    h_m_dilep_cut->Fill(pdi.Mag());
                    h_DeltaR_three_cut->Fill(pdi.DeltaR(p5));
                    h_DeltaR_dilep_cut->Fill(p3.DeltaR(p4));



                    h2_Deltar3_3mass->Fill(pdi.DeltaR(p5),pthree.Mag());
                    h2_Deltar3_2mass->Fill(pdi.DeltaR(p5),pdi.Mag());
                    h2_Deltar2_3mass->Fill(p3.DeltaR(p4),pthree.Mag());
                    h2_Deltar2_2mass->Fill(p3.DeltaR(p4),pdi.Mag());
                    h2_2mass_3mass->Fill(pdi.Mag(),pthree.Mag());
                    h2_etgamma_3mass->Fill(p5.Et(),pthree.Mag());


                    h2_ptlow_pthigh->Fill(low,high);
                    h2_ptbalance->Fill(Delta_pt,pthree.Mag());

                  }
                }
              }
            }
          }
        }
      }
      
   }
   
   TFile *Output_file_1 = new TFile("Output_z_back.root", "RECREATE");
      
   h_m_dilep->Write();
   h_m_dilep_cut->Write();
   h_m_three->Write();
   h_m_three_cut->Write();   
   
   h_DeltaR_three->Write();
   h_DeltaR_dilep->Write();   
   h_DeltaR_three_cut->Write();
   h_DeltaR_dilep_cut->Write();
  

   h2_Deltar3_3mass->Write() ;
   h2_Deltar3_2mass->Write() ;
   h2_Deltar2_3mass->Write() ;
   h2_Deltar2_2mass->Write() ;
   h2_2mass_3mass->Write();
   h2_etgamma_3mass->Write();
   h2_ptlow_pthigh->Write();
   h2_ptbalance->Write();
  
   Output_file_1->Close();
}
