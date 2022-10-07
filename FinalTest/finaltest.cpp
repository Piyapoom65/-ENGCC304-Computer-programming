#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ageman {
	int number ; // person's number
	char name[ 100 ] ; //person's name 
	char date[ 100 ] ; //Birthday date
} typedef age ; //keyword

int takedata ( age [] ) ; //take data to structure
void showdata ( age [], int ) ; // show data and the oldest/youngest 

int main(){
	age human[ 100 ] ; //announce array structure
	int number ; // number to count people
	number = takedata( human ) ;
	printf("-------------------------------\n") ; //segmented input and output
	showdata( human, number ) ;
	return 0 ;
}

int takedata ( age human[] ) {
	FILE *fp ; //file reader
	int count ;//count people
	
	fp = fopen( "a.txt", "r" ) ;//read file
	if ( fp == NULL ) {
		printf( "Unknowable file location, fix file name pls " ) ;
		exit( 0 ) ;
	}//end if
	fscanf(fp,  "%s\t%s\t\t%s\n", human[ 0 ].name, human[ 0 ].name, human[ 0 ].name ) ;
	printf("%s\t%s\t\t%s\n", "No", "Name", "Birthday") ;
	strcpy(human[0].name, "\0") ;
	for (int i = 0 ; i < 100 ; i++){
		if (fscanf( fp, "%d\t%s\t\t%s\n", &human[ i ].number, human[ i ].name, human[ i ].date) != EOF) {
			count++ ;
			printf("%d\t%s\t\t%s\n", human[ i ].number, human[ i ].name, human[ i ].date) ;
		}
		else {
			break ;
		}//end if	
	}//end for
	fclose( fp ) ;//end
	return count ; //return number of people
}

void showdata ( age human[], int count) {
	int oldest = -99999999 ; //oldest values movement
	int youngest = 999999999 ; //oldest values movement
	char holderall[ 100 ], holder[ 100 ] ;// holder string and pre string date to integer date
	int year, month, day ;// date per person 
	char *pointname ; // point name
	int alltoday[ 100 ] ;//all day age
	for (int i = 0 ; i < count ; i++) {
		strcpy(holderall, human[i].date) ;
		for(int j = 0 ; j < 4 ; j++ ) {
			holder[ j ] = holderall[ j ] ;
		}//end for
		holder[ 4 ] = '\0' ;
		year = atoi( holder ) ;
		for(int j = 0 ; j < 2 ; j++ ) {
			holder[ j ] = holderall[ j + 5 ] ;
		}//end for
		holder[ 2 ] = '\0' ;
		month = atoi( holder ) ;
		
		for(int j = 0 ; j < 2 ; j++ ) {
			holder[ j ] = holderall[ j + 8 ] ;
		}//end for
		holder[ 2 ] = '\0' ;
		day = atoi( holder ) ;
		alltoday[ i ] =  ( 2018 - year ) * 365 + ( 6 - month ) * 30 + ( 21 - day ) ;// 
		printf("%s %d Years, %d Months\n", human[ i ].name, alltoday[ i ]/ 365, ( alltoday[ i ] % 365) / 30 ) ;
	}//end for
	
	for (int k = 0; k < count ; k++) {
		if ( alltoday[ k ] > oldest ) {
			oldest = alltoday[ k ] ;
			pointname = human[ k ].name ;
		}//end if
	}//end for
	printf( "\nMax : %s [%d Years, %d months]\n", pointname, oldest/365, (oldest%365)/30) ;

	for (int k = 0; k < count ; k++) {
		if ( alltoday[ k ] < youngest) {
			youngest = alltoday[ k ] ;
			pointname = human[ k ].name ;
		}//end if
	}//end for
	printf( "Min : %s [%d Years, %d months]", pointname, youngest/365, (youngest%365)/30) ;
}
