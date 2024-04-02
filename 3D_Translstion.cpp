#include<iostream>
#include<math.h>
using namespace std;
int size = 4;

int main() {
	float co_mat[size],tx,ty,tz,sum;
	int i,j;
	cout<<"Enter all the points:"<<endl;
	for(i = 0; i<size-1; i++){
		cin>>co_mat[i];
	}
	co_mat[size-1] = 1;
	
	cout<<"Enter Translation Factors:"<<endl;
	cin>>tx>>ty>>tz;
	cout<<"Translation Matrix"<<endl;
	
	float trans_mat[size][size], af_mul[size];
	
	for(i = 0; i<size; i++){
		for(j = 0; j<size; j++){
			if(i == j){
				trans_mat[i][j] = 1;
			}else if(j == size -1){
				if( i == 0){
					trans_mat[i][j] = tx;
				}
				if( i == 1){
					trans_mat[i][j] = ty;
				}
				if( i == 2){
					trans_mat[i][j] = tz;
				}
			}
		}
	}
	
	for(i = 0; i<size; i++){
		for(j = 0; j<size; j++){
			printf("%.2f\t", trans_mat[i][j]);
		}
		printf("\n");
	}
	
	cout<<"After Multiplication"<<endl;
	
	for(i = 0; i<size; i++){
		sum = 0;
		for(j = 0; j<size; j++){
			sum += trans_mat[i][j] * co_mat[j];
		}
		af_mul[i] = sum;
	}
	
	for(i = 0; i<size-1; i++){
		cout<<"x"<<i+1<<" = "<<af_mul[i]<<endl;
	}
}
