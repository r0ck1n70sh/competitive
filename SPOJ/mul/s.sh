for((i=0; i<100; i++))
do
	echo $i
	./gen i > int
	./brute < int > out1
	python a.py < int > out2
	diff -w out1 out2 || break
done 
