#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n,nf;
int in[31];
int p[50];
int hit=0;
int i,j,k;
int pgfaultcnt=0;

void initialize() {
    pgfaultcnt=0;
    for(i=0; i<nf; i++)
        p[i]=9999;
}
int getPos(int data) {
    int hitind;
    for(k=0; k<nf; k++) {
        if(p[k]==data) {
            hitind=k;
            break;
        }
    }
    return hitind;
}

int got(int data) {
    hit=0;
    for(j=0; j<nf; j++) {
        if(p[j]==data) {
            hit = 1;
            break;
        }
    }
    return hit;
}

void fifo() {
    initialize();
    for(i = 0; i < n; i++) {
        printf("\n--- %d: ", in[i]); 
        if(got(in[i])==0) {
            for(k = 0; k < nf - 1; k++)
                p[k] = p[k+1];
            p[k] = in[i];
            pgfaultcnt++;
            printf("%.2d\n", pgfaultcnt);
        } else {
           printf("Sem quebra de pagina");
	}
    }
    printf("\n%.2d\n", pgfaultcnt);
}

int main() {
    char * inTemp = (char*)malloc(sizeof(char*));
    
    //printf("\nComprimento da referencia: ");
    //scanf("%d",&n);
    
    printf("\nReferencia:");
    //for(i=0; i<n; i++)
    //    scanf("%d", &in[i]);
    scanf(" %[^\n]", inTemp);
    n = strlen(inTemp);
    for(int i = 0; i < n; i++) {
	if(inTemp[i] > 47 && inTemp[i] < 58) {
		in[i] = inTemp[i] - 48;
	}
    }
    printf("\nQtd frames: ");
    scanf("%d", &nf);

    fifo();
 return 0;
}
