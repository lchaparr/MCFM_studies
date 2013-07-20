#!/bin/bash
cd workspace
source rootsetup.sh
cd MCFM-6.6/Bin

for i in {1089..1109};
do
  cp background.DAT background"_"$i.DAT
  sed -i s/1089/$i/g background"_"$i.DAT
  sed -i s/zeeg/$i/g background"_"$i.DAT
  ./mcfm background"_"$i.DAT
done
