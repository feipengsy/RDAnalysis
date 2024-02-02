#include <cmath>
#include <vector>
#include <iostream>

#include <ROOT/RLogger.hxx>
#include "TLorentzVector.h"
//#include "ROOT/RConfig.hxx"
#include "ROOT/RVec.hxx"
#include "JetFitObject.h"
#include "LeptonFitObject.h"
#include <Math/GenVector/PtEtaPhiM4D.h>
#include <Math/GenVector/PxPyPzM4D.h>
//#include "edm4hep/ReconstructedParticleData.h"
//#include "edm4hep/ParticleIDData.h"
//#include "edm4hep/MCParticleData.h"
using namespace std;
//using namespace ROOT::VecOps;
std::string selLep(int i);
std::string getMuon();
std::string get_jet_e();
std::string get_jet_px();
std::string get_jet_py();
std::string get_jet_pz();
std::string get_lep_e(string p_name);
std::string get_lep_px(string p_name);
std::string get_lep_py(string p_name);
std::string get_lep_pz(string p_name);

std::vector<LeptonFitObject> getLepton(ROOT::VecOps::RVec<float> px,ROOT::VecOps::RVec<float> py,ROOT::VecOps::RVec<float> pz,ROOT::VecOps::RVec<float> energy);

std::vector<JetFitObject> getJet(ROOT::VecOps::RVec<float> px,ROOT::VecOps::RVec<float> py,ROOT::VecOps::RVec<float> pz,ROOT::VecOps::RVec<float> energy);





//ROOT::VecOps::RVec<float> get_e(ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> in);

