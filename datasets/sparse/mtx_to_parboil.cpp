#include <vector>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <map>
using namespace std;
#define ll long long

int main(int argc, char *argv[])
{
	if(argc < 3) {
		printf("Usage: ./mtx_to_parboil file_name.mtx source_node\n");
		return 1;
    }
	string file_mm = argv[1];
	ll source_num = atoi(argv[2]);
	
	ll nodes, edges;
	map<ll, vector<ll> > edgelist;
	//%%MatrixMarket matrix coordinate pattern symmetric or general
	
	
	ll line_num = 0;
	ifstream in(file_mm);
	
	string mm, mat, coord, patt, type;
	in >> mm >> mat >> coord >> patt >> type;
	cout << type << "\n";
	printf("%d\n", type == "symmetric");
	
	
	for (std::string line; std::getline(in, line); ) 
	{
		if(line.length() == 0 || line[0] == '%')
			continue;
		if(line_num == 0) {
			ll i = 0, j = 0;
			std::string delimiter = " ";
			i = j;
			std::string token = line.substr(i, (j = line.find(delimiter, i)) - i);
			cout << i << " " << j << " " << token << "\n";
			nodes = stoi(token);
			i = (j += 1);
			token = line.substr(i, (j = line.find(delimiter, i)) - i);
			cout << i << " " << j << " " << token << "\n";
			i = (j += 1);
			token = line.substr(i, (j = line.length()) - i);
			cout << i << " " << j << " " << token << "\n";
			edges = stoi(token);
			++line_num;
		}
		else {
			ll i = 0, j = 0;
			std::string delimiter = " ";
			i = j;
			std::string token = line.substr(i, (j = line.find(delimiter, i)) - i);
			//cout << token << "\n";
			//fflush(stdout);
			ll u = stoi(token);
			i = (j += 1);
			token = line.substr(i, (line.length()) - i);
			//cout << token << "\n";
			//fflush(stdout);
			ll v = stoi(token);
			edgelist[u - 1].push_back(v - 1);
			if(type == "symmetric")
				edgelist[v - 1].push_back(u - 1);
				
		}
	}
	
	long long tot_edges = 0;
	for(auto i = 0; i < nodes; ++i) {
		tot_edges += edgelist[i].size();
	}
	
	std::string file_parboil = file_mm.substr(0, file_mm.find(".")) + ".parboil.gr";
	ofstream out(file_parboil);
	out << nodes << " " << tot_edges << " " << source_num << "\n";
	
	long long start = 0;
	for(auto i = 0; i < nodes; ++i) {
		out << start << " " << edgelist[i].size() << "\n";
		start += edgelist[i].size();
	}
	
	for(auto i = 0; i < nodes; ++i) {
		for(auto j = edgelist[i].begin(); j != edgelist[i].end(); ++j)
			out << *j << " " << 1 << "\n";
	}
}
