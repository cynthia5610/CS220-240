/**
* NAME: CYNTHIA HA
* WORKED WITH LUKE KRENTZ
* EXTRA CREDIT
**/
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>

using namespace std;

vector <string> lines;
vector <int> data;

void get_data();
int find_unique(vector <int> data);
int find_freq(vector<int> data);
int find_burst(vector <int> data);

int main(int argc, char *argv[]){

	int i;
	string line;

	if(argc != 2){
		cerr << "ERROR: To many/few arguments" << endl;
		exit(EXIT_FAILURE);
		}

	ifstream file(argv[1]);

	while(getline(file, line)){
		if(line[0] != '#' && !line.empty()){
			lines.push_back(line);
		}
	}

	get_data();

 return EXIT_SUCCESS;

}


void get_data(){

	int i;
	int numbers;
	int num_of_ints = 0;
	int num_of_unique = 0;
	int most_freq = 0;
	int bursts = 0;
	string line;

	for(i = 0; i < lines.size(); i++){
		line = lines[i];

		stringstream ss(line);

		while(ss >> numbers){
			data.push_back(numbers);
		}
		num_of_ints = data.size();
		num_of_unique = find_unique(data);
		most_freq = find_freq(data);
		bursts = find_burst(data);


		cout << "integers: " << num_of_ints;
		cout << " unique: " << num_of_unique;
		cout << " most frequent: " << most_freq;
		cout << " bursts: " << bursts;
		cout << endl;

		num_of_ints = 0;
		num_of_unique = 0;
		most_freq = 0;
		bursts = 0;
		data.clear();
	}

	return;
}


int find_unique(vector <int> data)
{
	vector <int> line;

		for(int i = 0; i < data.size(); i++){
			line.push_back(data[i]);
		}

	sort( line.begin(), line.end() );
	line.erase( unique( line.begin(), line.end() ), line.end() );
	return line.size();
}

int find_freq(vector<int> data)
{
	vector <int> line;
		int max_count = 0;
		int num = 0;

		for(int i = 0; i < data.size(); i++){
			line.push_back(data[i]);
		}

		for(int i = 0; i < line.size(); i++){
			int count=1;
   			for (int j = i + 1; j < line.size() ;j++){
   				if (line[i]==line[j])
           			count++;
   			}
   		    if (count>max_count){
      			max_count = count;
      			num = line[i];
   		    }
   		    if (count == max_count){
   		    	if(line[i] < num){
   		    		num = line[i];
   		    	}
   		    }
		}

	return num;

}

int find_burst(vector <int> data){
	vector <int> line;
		int burst = 0;

		for(int i = 0; i < data.size(); i++){
			line.push_back(data[i]);
		}

		for(int i = 0; i < line.size(); i++){
			if(line[i]!=line[i+1])
				burst++;
		}

	return burst;
}
