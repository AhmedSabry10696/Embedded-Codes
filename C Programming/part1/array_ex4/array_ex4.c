/* Program displays number of * according to the value in each array element */
#include <stdio.h>

int main( void )
{
    int n[ 5 ] = { 19, 3, 15, 7, 11};
    int i;
    int j;

    /* loop on array elements */
    for ( i = 0; i < 5; i++ ) 
    {
        printf("%d\t",n[i]);
        for ( j = 0; j < n[ i ]; j++ ) 
        {
            printf( "%c", '*' );
        } 
        printf( "\n" );
    }
    
    return 0; 
}

