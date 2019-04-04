ls *.fna >filelist
exec 0<filelist
count=1
while read line
do
	./main $line >result/result_$line
#	echo "line $count is: $line"
	count=$[$count+1]

done



