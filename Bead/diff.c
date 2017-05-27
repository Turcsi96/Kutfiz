#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


void dy(double* vector, double* deltavec, double mf, double G, double h){
	
	deltavec[0]=vector[2];
	deltavec[1]=vector[3];
	deltavec[2]=(G*mf*(-vector[0]))/(pow(vector[0]*vector[0]+vector[1]*vector[1],1.5));
	deltavec[3]=(G*mf*(-vector[1]))/(pow(vector[0]*vector[0]+vector[1]*vector[1],1.5));
}


void euler_step(double* vector, double* deltavec, double h, int N, double mf, double G, FILE* p){
	for(double k=0; k<100000000; k+=h){
		dy(vector,deltavec, mf, G, h);
		for(int i=0; i<N; i++){
			//printf("dy:%d %lf \n",i,deltavec[i]);
			vector[i] +=h * deltavec[i];
			//printf("vec:%d %lf \n",i, vector[i]);
		}
		fprintf(p, "%lf %lf %lf %lf \n", vector[0], vector[1], vector[2], vector[3]);

	}
}

int main(){

double mf = 5.9736e24;
double mh = 7.359e22;
double dA = 405500e3;
double dP = 363300e3;
double vA = 964;
double vP = 1076;
double G = 6.67384e-11;
double h=1000;
int N=4;

double* vector;
double* deltavec;

vector=(double*)calloc(4,sizeof(double));
deltavec=(double*)calloc(4,sizeof(double));


vector[0]=0;
vector[1]=-dP;
vector[2]=vP;
vector[3]=0;

FILE* p=fopen("adat.dat","w");
euler_step(vector,deltavec,h,N,mf,G,p);
fclose(p);

return 0;
}
