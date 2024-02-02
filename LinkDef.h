#ifdef __CINT__

//Globals
#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;
#pragma link C++ nestedclasses;

//Dictionaries for output objects
#pragma link C++ class std::vector<TLorentzVector>+;
#pragma link C++ class std::vector<std::string>+;

#pragma link C++ class ROOT::VecOps::RVec<TLorentzVector>+;
#pragma link C++ class std::vector<std::vector<int>>+;
#pragma link C++ class ROOT::VecOps::RVec<edm4hep::TrackState>+;
#pragma link C++ class ROOT::VecOps::RVec<edm4hep::VertexData>+;
#pragma link C++ class ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>+;
#pragma link C++ class ROOT::VecOps::RVec<edm4hep::CalorimeterHitData>+;
#pragma link C++ class ROOT::VecOps::RVec<edm4hep::ClusterData>+;
#pragma link C++ class ROOT::VecOps::RVec<podio::ObjectID>+;
#pragma link C++ class ROOT::VecOps::RVec<edm4hep::Vector3d>+;
#pragma link C++ class ROOT::VecOps::RVec<edm4hep::MCParticleData>+;
#pragma link C++ class ROOT::VecOps::RVec<TVector3>+;
#pragma link C++ class ROOT::VecOps::RVec<ROOT::VecOps::RVec<float>>+;
#pragma link C++ class ROOT::VecOps::RVec<ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>>+;
#pragma link C++ class ROOT::VecOps::RVec<std::vector<float>>+;
#pragma link C++ class std::vector<LeptonFitObject>+;
#pragma link C++ class ROOT::VecOps::RVec<LeptonFitObject>+;
#pragma link C++ class std::vector<JetFitObject>+;
#pragma link C++ class ROOT::VecOps::RVec<JetFitObject>+;
#pragma link C++ class BaseConstraint;
#pragma link C++ class ROOT::VecOps::RVec<ISRPhotonFitObject>+;
#pragma link C++ class std::vector<ISRPhotonFitObject>+;
#pragma link C++ class wsy;
#pragma link C++ function f; 

#pragma link C++ class ISRPhotonFitObject;
#pragma link C++ class JetFitObject;
#pragma link C++ class MomentumConstraint;
#pragma link C++ class BaseFitter;
#pragma link C++ class OPALFitterGSL;
#pragma link C++ class NewtonFitterGSL;
#pragma link C++ class NewFitterGSL;
#pragma link C++ class LeptonFitObject;
#pragma link C++ class BaseFitObject;
#pragma link C++ class FourVector;
#pragma link C++ class ParticleFitObject;
#pragma link C++ class ThreeVector;

#pragma link C++ function getJet;
//to load all other functions
#pragma link C++ function dummyLoader;

#endif
