import ROOT as cepc_ana 
import os
cepc_ana.gSystem.Load('../build/lib/libRDAnalysis.so')
load=cepc_ana.f()


cepc_ana.ROOT.EnableImplicitMT(12)#turn on MT


df = cepc_ana.RDataFrame("events","./a1.root")#set input file


df1=df.Define("Muon",cepc_ana.selLep(13))\
.Define("MuonM","ArborPFOs.type==-13")\
.Define("P_MX",cepc_ana.get_lep_px("MuonM"))\
.Define("cutMuon","ArborPFOs.type!=13&&ArborPFOs.type!=-13")\
.Define("Muon_px",cepc_ana.get_lep_px("Muon"))\
.Define("Muon_py",cepc_ana.get_lep_py("Muon"))\
.Define("Muon_pz",cepc_ana.get_lep_pz("Muon"))\
.Define("Muon_e",cepc_ana.get_lep_e("Muon"))\
#select muon and save 4 momentum

df2=df1.Filter("Muon_px.size()==2&&P_MX.size()==1")\
.Define("l1","getLepton(Muon_px,Muon_py,Muon_pz,Muon_e)")\
.Define("higgs_M","Kinfit::fit(j2[0],j2[1],l1[0],l1[1])")\
.Snapshot("events","./a2.root",{"j2","higgs_M","l1"})
#cut 2muon event ,use 2jet2muon in Kinfit

df3 = df2.Histo1D(("HiggsRecoM", "after4cfit", 200,0 ,200 ), "higgs_M")
h = cepc_ana.TCanvas()
df3.Draw()
h.SaveAs("higgs.png")
#make plot

