#include<stdio.h>
int main(){
    int i, x, y, z;
    printf( "Input yourline: " ) ;
    scanf( "%d", &x) ;    
    for ( i = 1; i <= x; i++)
    {
        if ( x % 2 == 0 ){
            for ( y = x-i ; y > 0 ; y--)
            {
                
                printf( " " ) ;
            } 
            for ( z = 0 ; z < i; z++)
            {
                {
                    printf( "*" ) ;
                    printf( " " ) ;
                }
            }        
                   
            printf( "\n" ) ;
        }
        else{
            for ( z = 1; z < i; z++)
            {
                {
                    printf( " " ) ;
                }
            }        
            for ( y = x-i ; y >= 0 ; y--)
            {
                printf( "*" ) ;
                printf( " " ) ;
            }        
            printf( "\n" ) ;
        }
    }
    
    return 0 ;
}