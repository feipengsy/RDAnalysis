#include "ReconstructedParticle.h"
#include <iostream>
#include <cmath>
#include "TLorentzVector.h"
#include <Math/GenVector/LorentzVector.h>
#include <TMath.h>
#include <Math/Vector4Dfwd.h>
#include <Math/GenVector/LorentzVector.h>
#include <Math/GenVector/PtEtaPhiM4D.h>

using namespace std;
//using namespace ROOT::VecOps;
//#include "TLorentzVector.h"
//#include "ROOT/RVec.hxx"
//#include "edm4hep/ReconstructedParticleData.h"
//#include "edm4hep/ParticleIDData.h"
//#include "edm4hep/MCParticleData.h"
//using namespace  edm4hep;

std::string selLep(int i){
//std::string a;
if(i==11){string a="ArborPFOs.type==11||ArborPFOs.type==-11";return a;}
if(i==13){string a="ArborPFOs.type==13||ArborPFOs.type==-13";return a;}
if(i==15){string a="ArborPFOs.type==15||ArborPFOs.type==-15";return a;}
//return a;
}

std::string getMuon(){
string a="ArborPFOs.type==13||ArborPFOs.type==-13";
return a;
}

std::string get_jet_e(){
string a="Jet.energy";
return a;
}

std::string get_jet_px(){
string a="Jet.momentum.x";
return a;
}

std::string get_jet_py(){
string a="Jet.momentum.y";
return a;
}

std::string get_jet_pz(){
string a="Jet.momentum.z";
return a;
}

std::string get_lep_e(string p_name){
string a="ArborPFOs.energy";
string b=a+"["+p_name+"]";
//string a="ArborPFOs.energy[MuonP]";
return b;
}

std::string get_lep_px(string p_name){
string a="ArborPFOs.momentum.x";
string b=a+"["+p_name+"]";
//string a="ArborPFOs.energy[MuonP]";
return b;
}

std::string get_lep_py(string p_name){
string a="ArborPFOs.momentum.y";
string b=a+"["+p_name+"]";
//string a="ArborPFOs.energy[MuonP]";
return b;
}

std::string get_lep_pz(string p_name){
string a="ArborPFOs.momentum.z";
string b=a+"["+p_name+"]";
//string a="ArborPFOs.energy[MuonP]";
return b;
}

std::vector<JetFitObject> getJet(ROOT::VecOps::RVec<float> px,ROOT::VecOps::RVec<float> py,ROOT::VecOps::RVec<float> pz,ROOT::VecOps::RVec<float> energy){
std::vector<ROOT::Math::PxPyPzEVector> vv1;
for(int i=0;i<2;i++){
ROOT::Math::PxPyPzEVector v1(px[i],py[i],pz[i],energy[i]);
vv1.push_back(v1);
}
std::vector<JetFitObject> l2;
for(int i=0;i<2;i++){
JetFitObject l3(vv1[i].E(),vv1[i].Theta(),vv1[i].Phi(),1,1,1);
l2.push_back(l3);
}
return l2;
}

std::vector<LeptonFitObject> getLepton(ROOT::VecOps::RVec<float> px,ROOT::VecOps::RVec<float> py,ROOT::VecOps::RVec<float> pz,ROOT::VecOps::RVec<float> energy){
std::vector<ROOT::Math::PxPyPzMVector> vv1;
for(int i=0;i<2;i++){
ROOT::Math::PxPyPzMVector v1(px[i],py[i],pz[i],0.105);
vv1.push_back(v1);
}
std::vector<LeptonFitObject> l2;
for(int i=0;i<2;i++){
LeptonFitObject l3(1/vv1[i].Pt(),vv1[i].Theta(),vv1[i].Phi(),0.00001,0.1,0.1,0.105);
l2.push_back(l3);
}
return l2;

}




//ROOT::VecOps::RVec<float> get_e(ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> in);
