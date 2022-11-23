#include <stdio.h>

int main()

{   long int x,y,z=9;
	int sum =0;
	printf( "User Input :" );
	scanf( "%ld", &x );
	for ( y = 1 ; y <= x ; y++ )
	{ sum +=z;
	  printf( "\n Series = " );
	  printf( "%ld ", z );
	  z=z*10+9;
	}
	printf( "\n Sum = %d \n", sum );
}  
