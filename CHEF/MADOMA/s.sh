for((i=0; i<100; i+=1))
do 
	echo $i
	./gen $i > int
	./sol < int > out1
	./brute < int > out2
	diff -w out1 out2 || break 
done 
