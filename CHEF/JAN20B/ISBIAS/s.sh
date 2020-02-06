for((i=0; i<=100; i++)) 
do
	echo $i
	./gen $i > int
	./brute < int > out1
	./a < int > out2
	diff -w out1 out2 || break
	# diff -w <(./a < int)< (./brute < int) || break
done
