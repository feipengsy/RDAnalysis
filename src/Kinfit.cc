#include "Kinfit.h"
#include <iostream>
#include <cmath>
#include "TLorentzVector.h"
#include <Math/GenVector/LorentzVector.h>
#include <TMath.h>
#include <Math/Vector4Dfwd.h>
#include <Math/GenVector/LorentzVector.h>
#include <Math/GenVector/PtEtaPhiM4D.h>
#include "ROOT/RVec.hxx"

namespace Kinfit{

float fit(JetFitObject j1,JetFitObject j2,LeptonFitObject l1,LeptonFitObject l2)
{
MomentumConstraint pxc(0, 1, 0, 0, 0.0);
MomentumConstraint pyc(0, 0, 1, 0, 0.0);
MomentumConstraint pzc(0, 0, 0, 1, 0.0);
MomentumConstraint ec(1, 0, 0, 0, 240);

MassConstraint h(0);
h.addToFOList(j1,1);
h.addToFOList(j2,1);
//MassConstraint z(91.2);
SoftGaussMassConstraint z(91.2,2.4952/2);
//z.addToFOList(l1,1);
//z.addToFOList(l2,1);

pxc.addToFOList(l1);
pxc.addToFOList(l2);
pxc.addToFOList(j1);
pxc.addToFOList(j2);
pyc.addToFOList(l1);
pyc.addToFOList(l2);
pyc.addToFOList(j1);
pyc.addToFOList(j2);
pzc.addToFOList(l1);
pzc.addToFOList(l2);
pzc.addToFOList(j1);
pzc.addToFOList(j2);
ec.addToFOList(l1);
ec.addToFOList(l2);
ec.addToFOList(j1);
ec.addToFOList(j2);

//std::cout <<"start mass of z :"<<z.getMass(1)<<std::endl;
//std::cout <<"start mass of h :"<<h.getMass(1)<<std::endl;
float higgsm1=h.getMass();
float zm1=z.getMass(1);

//OPALFitterGSL fitter;
NewtonFitterGSL fitter;
//NewFitterGSL fitter;


//fitter.addFitObject(l1);
//fitter.addFitObject(l2);
fitter.addFitObject(j1);
fitter.addFitObject(j2);
//fitter.addFitObject(l1);
//fitter.addFitObject(l2);


fitter.addConstraint(pxc);
fitter.addConstraint(pyc);
fitter.addConstraint(pzc);
fitter.addConstraint(ec);
//fitter.addConstraint(h);
//fitter.addConstraint(z);

float prob=fitter.fit();

//float nchi2=fitter.calcChi2();
//std::cout<<"newton chi2 ="<<nchi2<<std::endl;
float chi2=fitter.getChi2();
//std::cout<<"fit chi2 ="<<chi2<<std::endl;
/*
std::cout  << "Value of pxc after fit: " << pxc.getValue() << std::endl;
std::cout  << "Value of pyc after fit: " << pyc.getValue() << std::endl ;

std::cout  << "Value of pzc after fit: " << pzc.getValue() << std::endl ;

std::cout << "Value of ec after fit: " << ec.getValue() << std::endl ;

std::cout<<"final mass of z:"<<z.getMass(1)<<std::endl;
*/
//float zm2=z.getMass(1);
float recoil_h=h.getMass(1);
//float chi2=fitter.getChi2();
//std::cout<<"final mass of h:"<<h.getMass(1)<<std::endl;

//int ierr=fitter.getError();
//std::cout<<"fitter error"<<ierr<<std::endl;
//return higgsm1;
return recoil_h;
//return zm2;
//return zm1;
//return chi2;
}

float BeforeFit(JetFitObject j1,JetFitObject j2,LeptonFitObject l1,LeptonFitObject l2)
{
MomentumConstraint pxc(0, 1, 0, 0, 0.0);
MomentumConstraint pyc(0, 0, 1, 0, 0.0);
MomentumConstraint pzc(0, 0, 0, 1, 0.0);
MomentumConstraint ec(1, 0, 0, 0, 240);

MassConstraint h(0);
h.addToFOList(j1,1);
h.addToFOList(j2,1);
//MassConstraint z(91.2);
SoftGaussMassConstraint z(2,2.4952/2);
z.addToFOList(l1,1);
z.addToFOList(l2,1);

pxc.addToFOList(l1);
pxc.addToFOList(l2);
pxc.addToFOList(j1);
pxc.addToFOList(j2);
pyc.addToFOList(l1);
pyc.addToFOList(l2);
pyc.addToFOList(j1);
pyc.addToFOList(j2);
pzc.addToFOList(l1);
pzc.addToFOList(l2);
pzc.addToFOList(j1);
pzc.addToFOList(j2);
ec.addToFOList(l1);
ec.addToFOList(l2);
ec.addToFOList(j1);
ec.addToFOList(j2);

//std::cout <<"start mass of z :"<<z.getMass(1)<<std::endl;
//std::cout <<"start mass of h :"<<h.getMass(1)<<std::endl;
float higgsm1=h.getMass(1);
float zm1=z.getMass(1);

//OPALFitterGSL fitter;
NewtonFitterGSL fitter;
//NewFitterGSL fitter;


//fitter.addFitObject(l1);
//fitter.addFitObject(l2);
fitter.addFitObject(j1);
fitter.addFitObject(j2);
//fitter.addFitObject(l1);
//fitter.addFitObject(l2);


fitter.addConstraint(pxc);
fitter.addConstraint(pyc);
fitter.addConstraint(pzc);
fitter.addConstraint(ec);
//fitter.addConstraint(h);
//fitter.addConstraint(z);

float prob=fitter.fit();

//float nchi2=fitter.calcChi2();
//std::cout<<"newton chi2 ="<<nchi2<<std::endl;
float chi2=fitter.getChi2();
//std::cout<<"fit chi2 ="<<chi2<<std::endl;
/*
std::cout  << "Value of pxc after fit: " << pxc.getValue() << std::endl;
std::cout  << "Value of pyc after fit: " << pyc.getValue() << std::endl ;

std::cout  << "Value of pzc after fit: " << pzc.getValue() << std::endl ;

std::cout << "Value of ec after fit: " << ec.getValue() << std::endl ;

std::cout<<"final mass of z:"<<z.getMass(1)<<std::endl;
*/
//float zm2=z.getMass(1);
float recoil_h=h.getMass(1);
//float chi2=fitter.getChi2();
//std::cout<<"final mass of h:"<<h.getMass(1)<<std::endl;

//int ierr=fitter.getError();
//std::cout<<"fitter error"<<ierr<<std::endl;
return higgsm1;
//return recoil_h;
//return zm2;
//return zm1;
//return chi2;
}



float fourlep(LeptonFitObject l1,LeptonFitObject l2,LeptonFitObject l3,LeptonFitObject l4)
{
MomentumConstraint pxc(0, 1, 0, 0, 0.0);
MomentumConstraint pyc(0, 0, 1, 0, 0.0);
MomentumConstraint pzc(0, 0, 0, 1, 0.0);
MomentumConstraint ec(1, 0, 0, 0, 240);

MassConstraint h(0);
h.addToFOList(l1,1);
h.addToFOList(l2,1);
//MassConstraint z(91.2);
SoftGaussMassConstraint z(2,2.4952/2);
z.addToFOList(l3,1);
z.addToFOList(l4,1);

pxc.addToFOList(l1);
pxc.addToFOList(l2);
pxc.addToFOList(l3);
pxc.addToFOList(l4);
pyc.addToFOList(l1);
pyc.addToFOList(l2);
pyc.addToFOList(l3);
pyc.addToFOList(l4);
pzc.addToFOList(l1);
pzc.addToFOList(l2);
pzc.addToFOList(l3);
pzc.addToFOList(l4);
ec.addToFOList(l1);
ec.addToFOList(l2);
ec.addToFOList(l3);
ec.addToFOList(l4);

//std::cout <<"start mass of z :"<<z.getMass(1)<<std::endl;
//std::cout <<"start mass of h :"<<h.getMass(1)<<std::endl;
float higgsm1=h.getMass(1);
float zm1=z.getMass(1);

//OPALFitterGSL fitter;
NewtonFitterGSL fitter;
//NewFitterGSL fitter;


//fitter.addFitObject(l1);
//fitter.addFitObject(l2);
fitter.addFitObject(l1);
fitter.addFitObject(l2);
//fitter.addFitObject(l1);
//fitter.addFitObject(l2);


fitter.addConstraint(pxc);
fitter.addConstraint(pyc);
fitter.addConstraint(pzc);
fitter.addConstraint(ec);
//fitter.addConstraint(h);
//fitter.addConstraint(z);

float prob=fitter.fit();

//float nchi2=fitter.calcChi2();
//std::cout<<"newton chi2 ="<<nchi2<<std::endl;
float chi2=fitter.getChi2();
//std::cout<<"fit chi2 ="<<chi2<<std::endl;
/*
std::cout  << "Value of pxc after fit: " << pxc.getValue() << std::endl;
std::cout  << "Value of pyc after fit: " << pyc.getValue() << std::endl ;

std::cout  << "Value of pzc after fit: " << pzc.getValue() << std::endl ;

std::cout << "Value of ec after fit: " << ec.getValue() << std::endl ;

std::cout<<"final mass of z:"<<z.getMass(1)<<std::endl;
*/
//float zm2=z.getMass(1);
float recoil_h=h.getMass(1);
//float chi2=fitter.getChi2();
//std::cout<<"final mass of h:"<<h.getMass(1)<<std::endl;

//int ierr=fitter.getError();
//std::cout<<"fitter error"<<ierr<<std::endl;
//return higgsm1;
return recoil_h;
//return zm2;
//return zm1;
//return chi2;
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


}

