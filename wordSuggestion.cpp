#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int main() {

	ifstream file;

	file.open("content.csv");

	string str;

	vector<string> data;

	vector<vector<string>> dataArr;
	int splitIndex;

	while(file) {

		getline(file, str);

		for(int i = 0;i<str.size();i++) {
			if(str[i] == ',') {
				splitIndex = i;	
				break;
			}
		}

		if(str.size() == 0)
			break;

		data.push_back(str.substr(0, splitIndex));
		data.push_back(str.substr(splitIndex, str.size() - splitIndex));

		dataArr.push_back(data);
		data.clear();

	}

	for(int i = 0;i<dataArr.size();i++) {

		cout<<(dataArr[i])[0]<<" "<<(dataArr[i])[1];
		cout<<endl;

	}
	
	return 0;

}

