#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main()
{
	unsigned int i, check, num;
	unsigned int max= 1000000000;

	for(i=1; i<max; i++)
	{
		check=true;
		while(num<=sqrt(i))
		{
			if((i%num)==0)
			{
				check=false;
				break;
			}
			num++;
		}
		if(check==true)
			printf("%d\n", i);
		num=2;
	}

	return 0;
}
