#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#define maxjobs 3

typedef struct{
        int jobs, nproc, imp;
}PROC;

void printproc(PROC *proc);
void printjob(PROC *vet);
int np, maxjobs;
int t=0;



int main() {
        int i;
        srand(time(NULL));
        printf("Numero de Processos:");
        scanf("%d",&np);

        printf("Maximo de jobs:");
        scanf("%d",&maxjobs);
        PROC proc[np];

        for ( i = 0;i < np;i++ ) {
		    proc[i].jobs = 4+rand()%12;
		    proc[i].nproc = i;
		    t = t + proc[i].jobs;
        }

        printproc(proc);        		//impressao dos processos e quantos jobs tem
        printjob(proc);         		//impressao dos jobs sendo executados, tempo de uso e total da espera da cpu
        return 0;
}

void printproc(PROC *proc) {
        int i;
        for( i = 0;i < np;i++ ){
			printf("\nProcesso %d: %d Jobs\n",proc[i].nproc + 1,proc[i].jobs);
        }
        printf("\n");
}

void printjob(PROC *vet) {

        int i, j, aux;
        bool teste;

        do{
            for (i = 0; i < np; i++ ) {
                    printf("\n\nNumero do Processo %d restam: %d -- Jobs",vet[i].nproc + 1,vet[i].jobs);
                    printf("|");
                    for(j = 0; j < maxjobs; j++ ) {

                        if(vet[i].jobs > 0 ){
                            printf("%d",i+1);
                            t--;
                            vet[i].jobs--;
                            aux--;

                        }

                    }
                    printf("|");

            }
        } while(t > 0);
}
