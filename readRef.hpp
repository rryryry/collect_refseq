#ifndef _READSEQ_HPP_
#define _READSEQ_HPP_

#include <string>
#include <vector>

using namespace std;

struct GenomeSeq{
	string name;
	long length;
	string type;
//	GenomeSeq(string s, long l, string t) : name(s), length(l), type(t) {}

};
bool myfunction(GenomeSeq gs1, GenomeSeq gs2);


void readSeq(string filename, vector<string> &name, vector<long> &seqLength,long &totalLength, long &totalNum);

void computeType(vector<GenomeSeq> &descr, vector <string> &name, vector<long> &seqLength, vector <long> &typeSeqNum, vector<string> &typeName);

void outputTypeNum(vector<long> typeSeqNum, vector<string> typeName);

void outputSeqName(vector<GenomeSeq> descr);


#endif
