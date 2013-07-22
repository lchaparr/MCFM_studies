#!/bin/bash 
cd $HOME/workspace
source rootsetup.sh
cd MCFM-6.6/Bin
./mcfm ../../mcfm_production/zeej/DATfiles/backgroundj_1089.DAT
mv Z_1jet_tota_cteq6_m_50__50__1089*.rz ../../mcfm_production/zeej/ROOTfiles
cd $HOME/workspace/mcfm_production/zeej/ROOTfiles


