
#include<iostream>
#include<cstdlib> 
using namespace std;

int operations =0;
const int N=1000;

int n=N;
int A[N];
void generate_data(){
	for(int i=0;i<N;i++){
		A[i]=rand()%2000;
	}
}

void print_data(){
	for(int i=0;i<N;i++){
		cout<<"\t"<<A[i];
	}
}

int findmax(int A[],int n){		
	int max;			//First we will Find The Max Number Then we will Create New Array;
	
	for(int i=0;i<n;i++){
		
		if (A[i]>max){
			max=A[i];
		}
	}
	return max;
}

void CS(int A[],int n){		//CS= Counter Sort 
	
	int j,*C,max;		//C Means Counter Array(New Array ) 
	max=findmax(A,n);
	C=new int [max+1];		//In C= We will create New Array Size of Max+1
	
	for(int i=0;i<max+1;i++){
		
		C[i]=0;			//We Initialize the whole Array as 0; it is just like Flags
	}
	for(int i=0;i<n;i++){
		
		C[A[i]]++;			//we are copying Agian into Actual Array
	}
	int i=0;
	j=0;
	while(j<max+1){
		
		if(C[j]>0){	
			A[i++]=j;		//chy kala Number active ve no Assign ka mean copy ka
			C[j]--;			// aw chy kala more than one  ve yaw Number  no decrement kawa 
		operations++;
		}
		else 
			j++;		// ka na ye no index increment kawa
		operations++;
	}
cout << "\nNumber of operations in Counting Sort : " << operations <<endl;	
}

int main(){
	
	//cout<<"\n\n-----------****   UNIVERSITY OF ENGINEERING & TECHNOLOGY MARDAN   ****------------\n\n**************Welcome TO Program for Counting Sort ***************\n\n"<<endl;
	generate_data();
	print_data();
	CS(A,N);		//Function Calling For Counting Sorting
	
	cout<<"\nAfter Sorting :";
	print_data();
	cout << "\nNumber of operations For ="<<N<<" counting  Sort : " << operations <<endl;
	char ch;
	cout<<"\n\nAre you want to Call Again(y/n):";
	cin>>ch;
	if(ch=='y'||ch=='Y'){
		main();
	}
	else 
		exit(0);
		

system("pause");	
	return 0;
}
