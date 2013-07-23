#!/bin/bash
cd /afs/cern.ch/user/l/lchaparr/workspace
source rootsetup.sh
cd mcfm_production/zeej/ROOTfiles

for i in {1100..1100};
do
VARIABLE="hadd zeej_$i.root"
for numero in {0..32};
do
VARIABLE="${VARIABLE} z_1jet_tota_cteq6_m_50__50__$i${numero}_*.root"
done
#Para ejecutar
${VARIABLE}

done
