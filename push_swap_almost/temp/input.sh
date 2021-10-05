#!/bin/bash

over700=0
under700=0


for ((var=0; var<1000; var++));
do	
	ARG=`python3 gen_num.py 100`
	var=`./push_swap $ARG | grep count | cut -f2 -d ' '`
	#argc=$#
	#argv=$1
	#echo "argc:$argc"
	echo "var:$var"
	num=${var}
	if [($num -gt 700];then
		over700=$((over700+1))
	else
		under700=$((under700+1))
	fi
done
echo "over700:$over700"
echo "under700:$under700"
