// Albert Coba 1727
// Shawn Nematbakhsh 8551
//
// cs161 as3: This program is a cache simulator. It takes data from an input file specified
// on the command line and then simulates the data in the file with each value corresponding to
// an address. 40 different caches are simulated of varying size/associativity/replacement
// policies.

// number of caches to use for debugging, set lower to get a quick test result


#define NUM_CACHES 40

#include <math.h>
#include <fstream.h>
#include <stdio.h>
#include "block.h"


int main(int argc,char **argv)
{
	// if fine name isn't passed in
	if(argc != 2)
	{
		// print error and quit
		cout << "Usage: as3 input_file\n";
		return 0;
	}
	
	cout << "Execution will take about 20 seconds, please wait...\n";


	// for loop counter
	int i;

	// the input file
	ifstream infile(argv[1]);
	
	// data from input file, read one at a time
	int read;

	// caches
	block caches[NUM_CACHES];	
	
	// initialize the caches to have varying sizes and replacement policies
	for(i=0;i<NUM_CACHES;++i)
		caches[i].init(64*(int)pow(2,i%5),(i>19));

	// while there is data to be read
	while(infile >> read)
	{
		// put the data in each cache, and set the "way" assiciativity different
		// for each
		for(i=0;i<NUM_CACHES;++i)
			caches[i].access(read,(int)pow(2,(i/5))%16+(int)pow(2,(i/5))/16);
	}
	
	// print title nicely
	printf("%25s\n\n%14d%10d%10d%10d%11d\n","LRU",1024,2048,4096,8192,16384);
	
	// print a the first half of the table, one line at a time
	for(i=0;i<4;++i)
	{
		printf("%-10d%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f\n",(int)pow(2,i),caches[5*i].rate(),caches[5*i+1].rate(),
		caches[5*i+2].rate(),caches[5*i+3].rate(),caches[5*i+4].rate());
	}

	// FIFO title
	printf("\n%26s\n\n%14d%10d%10d%10d%11d\n","FIFO",1024,2048,4096,8192,16384);
	
	// print second half, one line at a time
	for(i=4;i<8;++i)
	{
		printf("%-10d%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f\n",(int)pow(2,i%4),caches[5*i].rate(),caches[5*i+1].rate(),
		caches[5*i+2].rate(),caches[5*i+3].rate(),caches[5*i+4].rate());
	}

	// close input file
	infile.close();

	return 0;

