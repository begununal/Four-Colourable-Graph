/*
Student Name: Begun Unal
Student Number: 2013400021
Project Numbner: 3
Operating System: Virtual Machine
Compile Status: {Compiling/Not Compiling}
Program Status: {Working/Not Working}
Notes: Anything you want to say about your code that will be helpful in the grading process.
*/
/*
Student Name: Begun Unal
Student Number: 2013400021
Project Number: 3
Operating System: Virtual Machine
Compile Status: {Compiling/Not Compiling}
Program Status: {Working/Not Working}
Notes: Anything you want to say about your code that will be helpful in the grading process.
*/
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

struct Node {
	string c;
	int cc=0;
	int id;
	vector<Node*> next;
};
vector<Node> cities;

void importData(char* infilename){
	int x;
	int y;
	ifstream reader(infilename);
	reader>>x;
	int i,j = 0;
	for(i=0; i<x; i++){
		Node n;
		n.id=i;
		cities.push_back(n);
	}

	for(i=0; i<x; i++){
		for(j=0; j<x; j++){
			reader>>y;
			if(y == 1){
				cities[i].next.push_back(&cities[j]);
			}
		}
	}

}
void colouring(int k){
	for(int i=1; i<=4; i++){
		bool ok = true;
		for(int j=0; j<cities[k].next.size();j++){
			if(cities[k].next[j]->cc==i){
				ok = false;
				break;
			}
		}
		if(ok){
			cities[k].cc = i;
			if (k+1<cities.size()){
				colouring(k+1);
			}
			return;
		}
	}

}

void possibilities(vector<Node> &cities){
	string pos[] = {"red", "green", "blue", "orange"};
	for(int i=0; i<cities.size(); i++){
		cities[i].c = pos[cities[i].cc-1];
	}

}

int main(int argc, char *argv[]){
	if(argc!=3){
		printf("Usage: ./project1 infile outfile\n");
		return 0;
	}
	importData(argv[1]);
	ofstream writer(argv[2]);

	colouring(0);

	bool ok = true;
	for(int i=0;i<cities.size();i++){
		if(cities[i].cc == 0){
			ok = false;
			break;
		}
	}
	if(ok){
		possibilities(cities);
	for(int i=0; i<cities.size();i++){
			writer<<cities[i].c<<endl;
	}
	}else{
		writer<<"ups"<<endl;
	}


	return 0;
}
