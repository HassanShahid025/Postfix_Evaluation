#include <iostream>
#include <stack>
#include <math.h>
#include<sstream>
using namespace std;

bool isOperator(string c){
	if(c=="+"||c=="-"||c=="*"||c=="/"||c=="^"){
		return true;
	}
	else{
		false;
	}
}

int postfixEvaluation(string arr[], int totalElements){
	stack<int> st;
	int operand1, operand2;
	int number;
	for(int i=0; i<totalElements; i++){
		if(!isOperator(arr[i])){
			istringstream(arr[i]) >> number;
			st.push(number);
		}
		else{
			operand1=st.top();
			st.pop();
			operand2=st.top();
			st.pop();
			
			if(arr[i]=="+"){
				st.push(operand1+operand2);
			}
			else if(arr[i]=="-"){
				st.push(operand2-operand1);
			}
			else if(arr[i]=="*"){
				st.push(operand1*operand2);
			}
			else if(arr[i]=="/"){
				st.push(operand2/operand1);
			}
			else if(arr[i]=="^"){
				st.push(pow(operand2,operand1));
			}
		}
		
	}
	return st.top();
}

int main(){
	int totalElements;
	cout<<"Enter Total Elements in the Postfix Expression: "<<endl;
	cin>>totalElements;
	string arr[totalElements];
	cout<<"Enter Postfix Expression"<<endl;
	for(int i=0; i<totalElements; i++){
		cin>>arr[i];
	}
	cout<<endl<<endl<<"Postfix Epression: "<<endl;
	for(int i=0; i<totalElements; i++){
		cout<<arr[i]<<",";
	}
	cout<<endl<<"Postfix Epression Evaluation: ";
	cout<<endl<<postfixEvaluation(arr, totalElements);
	return 0;
}
