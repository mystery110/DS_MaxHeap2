#include<iostream>
#include<cstdlib>
#include<vector>
#include<sstream>
using namespace std;

vector<int>element;
int Heap[101],number_of_Ele=0,Index;
const char SplitChar=' ';

void Show();
void AddEle(int );
void DeleteEle(int);
void Find(int);
void strSplit(string);

int main (){
	cout<<"Please enter the element of max heap"<<endl;
	string s;
	getline(cin,s);
	strSplit(s);
	for(unsigned int i=element.size();i>0;i--){
		AddEle(element.at(0));
		element.erase(element.begin());
	}
	cout<<"Which element to be deleted?"<<endl;
	getline(cin,s);
	strSplit(s);
	DeleteEle(element.at(0));
	Show();
}

void strSplit(string s){
	istringstream ss(s);
	string temp;
	int x;
	while(getline(ss,temp,SplitChar)){
		x=stoi(temp);
		element.push_back(x);
	}
}

void AddEle(int x){
	int i=++number_of_Ele;
	while((i!=1)&&(Heap[i/2]<x)){
		Heap[i]=Heap[i/2];
		i/=2;
	}
	Heap[i]=x;
}

void Find(int x){
	Index=1;
	while(Heap[Index]!=x){
		Index++;
	}
}

void DeleteEle(int x){
	Find(x);
	int temp=Heap[number_of_Ele--];
	int parent =Index;
	int child =2*parent;
	while(child<=number_of_Ele){
		if((child<=number_of_Ele)&&(Heap[child+1]>Heap[child])){
			child++;
		}
		if(Heap[child]<temp){
			break;
		}
		Heap[parent]=Heap[child];
		parent=child;
		child*=2;
	}
	Heap[parent]=temp;
}

void Show(){
	for(int i=1;i<=number_of_Ele;i++){
		cout<<Heap[i]<<" ";
	}
	cout<<endl;
}



