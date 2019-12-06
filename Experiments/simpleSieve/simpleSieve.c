#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void simpleSieve(int limit);


int main() {
	int limit;
	scanf("%d", &limit);

	simpleSieve(limit);
	return 0;
}

void simpleSieve(int limit) {
	int i, p;
	int mark[limit];
	memset(mark, 1, limit*sizeof(int));
	
	for(p=2; p*p<limit; p++)
		if(mark[p])
			for(i=p*2; i<limit; i+=p)
				mark[i]=0;
	
	for(i=0; i<limit; i++)
		if(mark[i])
			printf("%d ", i);
}
