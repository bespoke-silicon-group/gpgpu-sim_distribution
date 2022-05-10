#!/bin/bash
cd ${RESULTS};
files=$(ls);
printf "Data size\tRegionSize\tTraversals\tTime\n"
for i in ${files}; do
	traversals=$(grep "Traversals" $i | grep -oE "[0-9]+");
	#echo  | grep -oE "[0-9]+"
	time=($(grep "gpu_sim_cycle" $i | grep -oE "[0-9]+"));
	threads=$(grep "RegionSize" $i | grep -oE "[0-9]+");
	Dsize=$(grep "Dsize" $i | grep -oE "[0-9]+");
	printf "%d\t%d\t%d\t%d\n" $Dsize $threads $traversals $(expr ${time[2]} - ${time[1]})
done
