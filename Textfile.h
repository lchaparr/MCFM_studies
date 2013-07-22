//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Jul  3 15:54:50 2013 by ROOT version 5.34/06
// from TTree h300/MCFM
// found on file: zgamma_back_less50.root
//////////////////////////////////////////////////////////

#ifndef Textfile_h
#define Textfile_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class Textfile {
 public :
  TTree          *fChain;   //!pointer to the analyzed TTree or TChain
  Int_t           fCurrent; //!current Tree number in a TChain

  // Declaration of leaf types
  Float_t         px3;
  Float_t         py3;
  Float_t         pz3;
  Float_t         E3;
  Float_t         px4;
  Float_t         py4;
  Float_t         pz4;
  Float_t         E4;
  Float_t         px5;
  Float_t         py5;
  Float_t         pz5;
  Float_t         E5;
  Float_t         px6;
  Float_t         py6;
  Float_t         pz6;
  Float_t         E6;
  Float_t         wt;
  Float_t         gg;
  Float_t         gq;
  Float_t         qq;
  Float_t         qqb;

  // List of branches
  TBranch        *b_px3;   //!
  TBranch        *b_py3;   //!
  TBranch        *b_pz3;   //!
  TBranch        *b_E3;   //!
  TBranch        *b_px4;   //!
  TBranch        *b_py4;   //!
  TBranch        *b_pz4;   //!
  TBranch        *b_E4;   //!
  TBranch        *b_px5;   //!
  TBranch        *b_py5;   //!
  TBranch        *b_pz5;   //!
  TBranch        *b_E5;   //!
  TBranch        *b_px6;   //!
  TBranch        *b_py6;   //!
  TBranch        *b_pz6;   //!
  TBranch        *b_E6;   //!
  TBranch        *b_wt;   //!
  TBranch        *b_gg;   //!
  TBranch        *b_gq;   //!
  TBranch        *b_qq;   //!
  TBranch        *b_qqb;   //!

  Textfile(TTree *tree=0);
  virtual ~Textfile();
  virtual Int_t    Cut(Long64_t entry);
  virtual Int_t    GetEntry(Long64_t entry);
  virtual Long64_t LoadTree(Long64_t entry);
  virtual void     Init(TTree *tree);
  virtual void     Loop();
  virtual Bool_t   Notify();
  virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef Textfile_cxx
Textfile::Textfile(TTree *tree) : fChain(0) 
{
  // if parameter tree is not specified (or zero), connect the file
  // used to generate this class and read the Tree.
  if (tree == 0) {
    TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("signal.root");
    if (!f || !f->IsOpen())
      {
	f = new TFile("signal.root");
      }
    f->GetObject("h300",tree);

  }
  Init(tree);
}

Textfile::~Textfile()
{
  if (!fChain) return;
  delete fChain->GetCurrentFile();
}

Int_t Textfile::GetEntry(Long64_t entry)
{
  // Read contents of entry.
  if (!fChain) return 0;
  return fChain->GetEntry(entry);
}
Long64_t Textfile::LoadTree(Long64_t entry)
{
  // Set the environment to read one entry
  if (!fChain) return -5;
  Long64_t centry = fChain->LoadTree(entry);
  if (centry < 0) return centry;
  if (fChain->GetTreeNumber() != fCurrent)
    {
      fCurrent = fChain->GetTreeNumber();
      Notify();
    }
  return centry;
}

void Textfile::Init(TTree *tree)
{
  // The Init() function is called when the selector needs to initialize
  // a new tree or chain. Typically here the branch addresses and branch
  // pointers of the tree will be set.
  // It is normally not necessary to make changes to the generated
  // code, but the routine can be extended by the user if needed.
  // Init() will be called many times when running on PROOF
  // (once per file to be processed).

  // Set branch addresses and branch pointers
  if (!tree) return;
  fChain = tree;
  fCurrent = -1;
  fChain->SetMakeClass(1);

  fChain->SetBranchAddress("px3", &px3, &b_px3);
  fChain->SetBranchAddress("py3", &py3, &b_py3);
  fChain->SetBranchAddress("pz3", &pz3, &b_pz3);
  fChain->SetBranchAddress("E3", &E3, &b_E3);
  fChain->SetBranchAddress("px4", &px4, &b_px4);
  fChain->SetBranchAddress("py4", &py4, &b_py4);
  fChain->SetBranchAddress("pz4", &pz4, &b_pz4);
  fChain->SetBranchAddress("E4", &E4, &b_E4);
  fChain->SetBranchAddress("px5", &px5, &b_px5);
  fChain->SetBranchAddress("py5", &py5, &b_py5);
  fChain->SetBranchAddress("pz5", &pz5, &b_pz5);
  fChain->SetBranchAddress("E5", &E5, &b_E5);
  fChain->SetBranchAddress("px6", &px6, &b_px6);
  fChain->SetBranchAddress("py6", &py6, &b_py6);
  fChain->SetBranchAddress("pz6", &pz6, &b_pz6);
  fChain->SetBranchAddress("E6", &E6, &b_E6);
  fChain->SetBranchAddress("wt", &wt, &b_wt);
  fChain->SetBranchAddress("gg", &gg, &b_gg);
  fChain->SetBranchAddress("gq", &gq, &b_gq);
  fChain->SetBranchAddress("qq", &qq, &b_qq);
  fChain->SetBranchAddress("qqb", &qqb, &b_qqb);
  Notify();
}

Bool_t Textfile::Notify()
{
  // The Notify() function is called when a new file is opened. This
  // can be either for a new TTree in a TChain or when when a new TTree
  // is started when using PROOF. It is normally not necessary to make changes
  // to the generated code, but the routine can be extended by the
  // user if needed. The return value is currently not used.

  return kTRUE;
}

void Textfile::Show(Long64_t entry)
{
  // Print contents of entry.
  // If entry is not specified, print current entry
  if (!fChain) return;
  fChain->Show(entry);
}
Int_t Textfile::Cut(Long64_t entry)
{
  // This function may be called from Loop.
  // returns  1 if entry is accepted.
  // returns -1 otherwise.
  return 1;
}
#endif // #ifdef Textfile_cxx
