#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm> //std::sort
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
	long totalLength = 0;
	long totalNum = 0;
	vector <long> typeSeqNum;
	typeSeqNum.push_back(0);
	typeSeqNum.push_back(0);
	typeSeqNum.push_back(0);
	typeSeqNum.push_back(0);
	vector <string> typeName;
	typeName.push_back("NZ");
	typeName.push_back("NC");
	typeName.push_back("NG");
	typeName.push_back("NR");
	
	vector <GenomeSeq> genome;

	readSeq(filename, name, seqLength, totalLength, totalNum);

	computeType(genome, name, seqLength, typeSeqNum, typeName);

	std::sort(genome.begin(),genome.end(),myfunction);

	outputTypeNum(typeSeqNum, typeName);
	
	outputSeqName(genome);


	return 0;
}
	


