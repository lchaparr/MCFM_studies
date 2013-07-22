#!/bin/bash
cd workspace
source rootsetup.sh
cd MCFM-6.6/Bin

for i in {1089..1109};
do
  for j in {0..13};
  do
  h2root zgamma_tota_cteq6_m_50__50__$i$j*.rz

  done
done