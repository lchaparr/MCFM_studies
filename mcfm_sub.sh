#!/bin/bash

for i in {1089..1289};
do
  cp mcfm_run.sh mcfm_run"_"$i.sh
  sed -i s/1089/$i/g mcfm_run"_"$i.sh
  bsub -q 1nw mcfm_run"_"$i.sh
done
