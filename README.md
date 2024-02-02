# RDAnalysis


## Getting started
```shell
source /cvmfs/sw.hsf.org/key4hep/releases/2023-06-05-fcchh/x86_64-centos7-gcc12.2.0-opt/key4hep-stack/2023-08-28-hsn6vj/setup.sh
cd build
cmake ..
make install
mv libRDAnalysis_rdict.pcm ./lib
cd ..
```
## Example
To better understand the workflow, we provide a example in CEPC here. It's a Electron-positron collision at 240GeV with final state two jet two muon.
Firstly,
```shell
cd example
```
run the example.
Secondly,run
```shell
python jetcluster.py
```
to get a rootfile(a1.root) after JetClustering, which have two jet two muon data.
Finally, run a1.root in
```shell
python Kinfit.py
```
to do kinematic fit to two jet and two muon, output file is a2.root. To check the effectiveness of the 2 analysis tools, higgs mass reconstructed by two jet is output as higgs.png
