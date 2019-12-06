#include <cstdio>

int main()
{
	//look for 124th number
	unsigned int index = 124;
	scanf("%ud");

	//22710 steps until 1577 is a divisor
	//(worst number I observed until the result is found)
	const unsigned int MaxSteps = 22710;

	//current divisor
	unsigned int current =1;

	//found non-divisors
	unsigned int numFound=0;

	while(numFound < index)
	{
		//check next divisor
		current += 2;

		//first three numbers of the sequence
		unsigned int tri1 = 1;
		unsigned int tri2 = 1;
		unsigned int tri3 = 1;

		bool isDivisor = false;

		for(unsigned int step=0; step <= MaxSteps; step++)
		{
			unsigned int triNext = tri1 + tri2 + tri3;
			triNext %= current;

			if(triNext==0)
			{
				isDivisor=true;
				break;
			}

			//update last three elements fo the sequence
			tri1= tri2;
			tri2= tri3;
			tri3= triNext;

			//returned to original state? must be a loop
			if(tri1==1 && tri2==1 && tri3==1)
				break;
		}

		if(isDivisor == true)
			numFound++;
	}

	printf("%u\n", current);
	return 0;

}
