#include<stdio.h>
int main() {
    int shownum[100] ;//Array int to keep answer
    int number ;//Number of output and control loop
    int i, j ;//loop controler

    shownum[ 0 ] = 1 ;//assign value
    shownum[ 1 ] = 1 ;//assign value

    printf( "INPUT: " ) ;
    scanf( "%d", &number) ;//assign input to parameter

    for ( i = 2 ; i < number ; i++) {
        shownum[ i ] = shownum[ i - 1 ] + shownum[ i - 2] ;
        printf( "%d", shownum[i - 2] ) ;

    }//end for

    printf( "OUTPUT: " ) ;
    if ( number % 2 == 0) {
        for ( j = 0 ; j < number ; j++) {
            printf( "%d", shownum[ j ] ) ;
            printf( " " ) ;

        }//end for

    }//end if

    else {
        for ( j = number - 1 ; j >= 0 ; j--) {
            printf( "%d", shownum[ j ] ) ;
            printf( " " ) ;

        }//end for

    }//end else
    
    return( 0 ) ;//return ERROR

}//end main