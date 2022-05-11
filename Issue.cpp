#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
using namespace std;
	int main(){
		ifstream inFile;
		char inputFileName [  ] = "salin.txt";
		ofstream outFile;
		char outputFileName [  ] = "salout.txt";
		const int MAX_CHAR_TO_READ = 100;
		char completeLineText [ MAX_CHAR_TO_READ ];
		char *tokenPtr;
		int salary = 0 , totalSalary = 0;
		
		inFile.open( inputFileName );
		outFile.open ( outputFileName );
		
		if ( ! inFile ) {
			cout << "Can't Open input File Named " << inputFileName << '\n';
			exit ( 1 );
		}  
		
		if ( ! outFile ) {
			cout << "Can't Open output File Named " << outputFileName << '\n';
			exit( 1 );
		}
		
		while ( ! inFile.eof ( ) ) {
			inFile.getline( completeLineText , MAX_CHAR_TO_READ );
			tokenPtr = strtok ( completeLineText , " " );
			tokenPtr = strtok ( NULL , " " );
			salary = atoi( tokenPtr );
			totalSalary = totalSalary + salary;
		}
		outFile << "The Total Salary = " << totalSalary;
		
		inFile.close();
		outFile.close();
		
		return 0;
		
	}
