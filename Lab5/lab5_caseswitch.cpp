#include<stdio.h>
int main(){
    int years, modY ;
    printf( "Input years: " );
    scanf( "%d", &years ) ;
    modY = years % 2 ;
    switch ( modY )
    {
    case 0 :
        printf( "Feb = 29 days" ) ;
        break;
    
    default:
        printf( "Feb = 28 days" ) ;
        break;
    }
    return 0 ;
}