#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

void findPer(vector<vector<char>> vec, vector<string> &bahar, int n=0, string str = "") {

	if (n == vec.size()-1) {
		bahar.push_back(str);
		return;
	}

	for(int i=0;i<vec[n].size();i++) {
		findPer(vec, bahar, n+1, str + vec[n][i]);
    	}


}

int main(int argc, char** argv) {

	ifstream f;

	f.open(argv[1]);

	string str;

	vector<char> data;

	vector<vector<char>> dataVec;

	vector<string> bahar;

	while(f) {

		getline(f, str);

		for(int i = 0;i<str.size();i++) {
			if(str[i] != ',' && str[i] != ' ')
				data.push_back(str[i]);
		}

		dataVec.push_back(data);
		data.clear();

	}

	findPer(dataVec, bahar);

	for(int i = 0;i<bahar.size();i++) {
		cout<<bahar[i]<<" ";
		if(i < bahar.size() - 1) {
	            cout << ", ";
	        }
	}
	
	return 0;

}

