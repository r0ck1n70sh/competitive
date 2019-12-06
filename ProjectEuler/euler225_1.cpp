#include <cstdio>

int main()
{
	//look for 124th number
	unsigned int index, t1, t2, t3;
	scanf("%u%u%u%u", &t1, &t2, &t3, &index);

	//22710 steps until 1577 is a divisor
	//(worst number I observed until the result is found)
	const unsigned int MaxSteps = 100000;

	//current divisor
	unsigned int current =1;

	//found non-divisors
	unsigned int numFound=0;

	while(numFound < index)
	{
		//check next divisor
		current += 2;

		//first three numbers of the sequence
		unsigned int tri1 = t1;
		unsigned int tri2 = t2;
		unsigned int tri3 = t3;

		bool isDivisor = false;

		for(unsigned int step=0; step <= MaxSteps; step++)
		{
			unsigned int triNext = tri1 + tri2 + tri3;
			triNext %= current;

			if(triNext==0)
			{
				printf("%d %d %d\n", tri1, tri2, tri3);
				isDivisor=true;
				break;
			}

			//update last three elements fo the sequence
			tri1= tri2;
			tri2= tri3;
			tri3= triNext;

			//returned to original state? must be a loop
			if(tri1==t1 && tri2==t2 && tri3==t3)
				break;
		}

		if(isDivisor == true)
			numFound++;
	}

	printf("%u\n", current);
	return 0;

}

