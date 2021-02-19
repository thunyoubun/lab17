#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string filename,vector <string> &names,vector <int> &scores, vector <char> &grades){
	ifstream source;
	source.open(filename.c_str());
	string textline;
	char format[] = "%[^:]: %d %d %d";
	char n[50];
	int g,m,s;
	while(getline(source,textline)){
		sscanf(textline.c_str(),format,n,&g,&m,&s);
		names.push_back(n);
		scores.push_back(s+m+g);
		grades.push_back(score2grade(s+m+g));
	}
	
}

void getCommand(string &command,string &key){
	

	cout << "Please input your command: ";
	string c;
	getline(cin,c);	
	int a;
	
	
	a = c.find_first_of(" ");
	command = c.substr(0,a);
	key = c.substr(a+1);

	
}

void searchName(vector <string> &names, vector <int> &scores,vector <char> &grades, string key){
	bool checker=false;
	
	for(unsigned int i =0 ; i < names.size(); i++){
		if(toUpperStr(names[i]) == key){
			checker=true;
			cout<<"---------------------------------"<<endl;
			cout << names[i] << "'s " << "score = " << scores[i] << endl;
			cout << names[i] << "'s " << "grade = " << grades[i] << endl;
			cout<<"---------------------------------"<<endl;
			
	}
	}
	  if(checker==false){
        cout<<"---------------------------------"<<endl;
        cout<<"Cannot found."<<endl;
        cout<<"---------------------------------"<<endl;
    }
	
}

void searchGrade(vector <string> &names, vector <int> &scores,vector <char> &grades, string key){
	cout<<"---------------------------------"<<endl;
    for(unsigned int i=0;i<grades.size();i++){
        if(key[0]==grades[i]){
            cout<<names[i]<<" "<<"("<<scores[i]<<")"<<endl;
        }
    }
    cout<<"---------------------------------"<<endl;

	
	
}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}