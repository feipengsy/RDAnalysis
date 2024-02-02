import ROOT as cepc_ana 
import os
cepc_ana.gSystem.Load('../lib/libMarlinKinfit.so')
load=cepc_ana.f()
cepc_ana.ROOT.EnableImplicitMT(12)

#df = cepc_ana.RDataFrame("events","/afs/ihep.ac.cn/users/w/wangshengyi/scratchfs/CEPCSW/0524_eebbMarlin_test.root")
df = cepc_ana.RDataFrame("events","data/2muon2jet.root")

#set input file

d1=df.Define("cutMuon","ArborPFOs.type!=13&&ArborPFOs.type!=-13")\
.Define("PX1",cepc_ana.get_lep_px("cutMuon"))\
.Define("PY1",cepc_ana.get_lep_py("cutMuon"))\
.Define("PZ1",cepc_ana.get_lep_pz("cutMuon"))\
.Define("E1",cepc_ana.get_lep_e("cutMuon"))\
#remove muon and define 4 momentum of these particles

d2=d1.Define("pseudo_jets","CEPCAnalyses::JetClusteringUtils::set_pseudoJets(PX1,PY1,PZ1,E1)")\
.Define("CEPCAnalysesJets_ee_genkt", "JetClustering::clustering_ee_kt(2, 2, 0, 0 )(pseudo_jets)")\
.Define("jets_ee_genkt", "CEPCAnalyses::JetClusteringUtils::get_pseudoJets(CEPCAnalysesJets_ee_genkt)")\
#enter 4 momentum about these particles into jetclustering program
#Set clustering parameters and make jetclustering
#create a column to store the jets

d3=d2.Define("jets_ee_genkt_px","CEPCAnalyses::JetClusteringUtils::get_px(jets_ee_genkt)")\
.Define("jets_ee_genkt_py","CEPCAnalyses::JetClusteringUtils::get_py(jets_ee_genkt)")\
.Define("jets_ee_genkt_pz","CEPCAnalyses::JetClusteringUtils::get_pz(jets_ee_genkt)")\
.Define("jets_ee_genkt_e","CEPCAnalyses::JetClusteringUtils::get_e(jets_ee_genkt)")\
.Filter("jets_ee_genkt_px.size()==2")\
.Define("j2","getJet(jets_ee_genkt_px,jets_ee_genkt_py,jets_ee_genkt_pz,jets_ee_genkt_e)")\
.Snapshot("events","./a1.root",{"j2","ArborPFOs"})
#define 4 momentum of jets
#cut 2jet event
#get jet mass
#save rootfile
