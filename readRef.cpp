#include <iostream>
#include <fstream>
#include <cstdlib>
#include "readRef.hpp"


void readSeq(string filename, vector<string> &name, vector<long> &seqLength,long &totalLength, long &totalNum){
	string meta, line;
	long length = 0;
	int index = 0;

	ifstream data(filename.c_str());
	if(!data.is_open())
	{
		cerr << "unable open the file !" << endl;
		exit(1);
	}
	while(!data.eof())
	{
		getline(data, line);
		if(line.length() == 0)
			continue;

		if(line[0] == '>')
		{
			meta = line;
			name.push_back(meta);
			if(length > 0)
			{
				seqLength.push_back(length);
				totalLength += length;
				length = 0;
			}
		
		}
		else
		{
			length += line.length();
		}
	}
	if(length > 0)
	{
		seqLength.push_back(length);
		totalLength += length;
		length = 0;
	}
	totalNum = name.size();
	cerr << "finish read the file ! " << endl;
	cerr << "the num of sequence is: " << totalNum << endl;
	cerr << " the total length of content is: " << totalLength << endl;
				
}






void computeType(vector<GenomeSeq> &descr, vector <string> &name, vector<long> &seqLength, vector <long> &typeSeq){
	int type_NZ = 0, type_NC = 0, type_NG = 0, type_NR = 0, type_others = 0;
	for(long i = 0; i < name.size() && i < seqLength.size(); i++)
	{
		GenomeSeq genome;
		genome.name = name[i];
		genome.length = seqLength[i];
//		switch(genome.name.substr(1,2))
//		{
//			case: "NZ"
//				genome.type = "NZ";
//				type_NZ++;
//				break;
//			case: "NC"
//				genome.type = "NC";
//				type_NC++;
//				break;
//			case: "NG"
//				genome.type = "NG";
//				type_NG++;
//				break;
//			case: "NR"
//				genome.type = "NR";
//				type_NR++;
//				break;
//			default:
//				genome.type = "others";
//				type_others++;
//				break;
//		}
		if(genome.name.substr(1,2) == "NZ")
		{
			genome.type = "NZ";
			type_NZ++;
		}
		else if(genome.name.substr(1,2) == "NC")
		{
			genome.type = "NC";
			type_NC++;
		}
		else if(genome.name.substr(1,2) == "NG")
		{
			genome.type = "NG";
			type_NG++;
		}
		else if(genome.name.substr(1,2) == "NR")
		{
			genome.type = "NR";
			type_NR++;
		}
		else
		{
			genome.type = "others";
			type_others++;
		}
		
			
		descr.push_back(genome);
	}
	typeSeq.push_back(type_NZ);
	typeSeq.push_back(type_NC);
	typeSeq.push_back(type_NG);
	typeSeq.push_back(type_NR);
	typeSeq.push_back(type_others);

}			
		

void outputTypeNum(vector<long> typeSeq)
{
	if(typeSeq.size() != 5)
	{
		cerr << "the nums of TYPE is not 5 , exit! " << endl;
		exit(1);
	}
	cout << "the number of type_NZ is: " << typeSeq[0] <<endl;
	cout << "the number of type_NC is: " << typeSeq[1] <<endl;
	cout << "the number of type_NG is: " << typeSeq[2] <<endl;
	cout << "the number of type_NR is: " << typeSeq[3] <<endl;
	cout << "the number of type_others is: " << typeSeq[4] <<endl;
}

void outputSeqName(vector<GenomeSeq> descr)
{
	if(descr.size() == 0){
		cerr << "the descr is NULL, exit! " << endl;
		exit(1);
	}
	for(long i = 0; i < descr.size(); i++)
	{
		cout << "the name is:   " << descr[i].name << "\t" ;
		cout << descr[i].length << "\t";
		cout << descr[i].type << endl;
	}
}



















































