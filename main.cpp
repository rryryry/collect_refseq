#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "readRef.hpp"

using namespace std;

int main(int argc, char* argv[]){

	if(argc != 2){
		cerr << "the parameter's number is wrong! " << endl;
		cerr << "you should run as : ./read filename " << endl;
		exit(1);
	}

	string filename = argv[1];
	
	vector<string> name;
	vector <long> seqLength;
	long totalLength;
	long totalNum;
	vector <long> typeSeq;
	vector <GenomeSeq> genome;

	readSeq(filename, name, seqLength, totalLength, totalNum);

	computeType(genome, name, seqLength, typeSeq);

	outputTypeNum(typeSeq);
	
	outputSeqName(genome);


	return 0;
}
	


