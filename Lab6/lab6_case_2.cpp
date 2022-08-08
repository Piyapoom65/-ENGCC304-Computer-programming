#include<stdio.h>
int main(){
    int i, x, y, z;
    printf( "Input yourline: " ) ;
    scanf( "%d", &x) ;
    for ( i = 0; i < x; i++)
    {
        for ( z = 0; z < i; z++)
        {
                printf( " " ) ;
        }        
        for ( y = x-i ; y > 0 ; y--)
        {
            printf( "*" ) ;
        }        
        printf( "\n" ) ;
    }
    return 0 ;
}