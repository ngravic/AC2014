#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TESTS   20
#define DIFF    100000
long N = 100000;
float *a;
float *b;
long t[TESTS][3];

void sum(float *a, float *b, int len);
void sum_sse(float *a, float *b, int len);

int main() {
    int j;
    long promsum, promsumsse, perc;
    for(j = 0; j < TESTS; j++, N+=DIFF)
    {        
        int i;
        a = malloc(sizeof(int) * N);    
        b = malloc(sizeof(int) * N);
        for(i = 0; i < N; i++){
            a[i] = i*0.1;
            b[i] = i*0.2;
        }
        struct timespec ini, fin;
        clock_gettime(CLOCK_REALTIME, &ini);
        sum(a, b, N);
        clock_gettime(CLOCK_REALTIME, &fin);    
        t[j][0] = N;
        t[j][1] = fin.tv_nsec - ini.tv_nsec;
        //printf("SUM: %ld\n", fin.tv_nsec - ini.tv_nsec);

        free(a);
        a = malloc(sizeof(int) * N);    
        for(i = 0; i < N; i++){
            a[i] = i*0.1;
            b[i] = i*0.2;
        }
        clock_gettime(CLOCK_REALTIME, &ini);
        sum_sse(a, b, N);
        clock_gettime(CLOCK_REALTIME, &fin);
        //printf("SUM_SSE: %ld\n", fin.tv_nsec - ini.tv_nsec);
        t[j][2] = fin.tv_nsec - ini.tv_nsec;
    }
    printf("Muestras\tSuma\t\tSuma c/ SSE\n");
    for(j = 0; j < TESTS ; j++) {        
        printf("%ld\t\t%ld\t\t%ld\n", t[j][0], t[j][1], t[j][2]);
        promsum += t[j][1];
        promsumsse += t[j][2];
    }
    promsum = promsum / TESTS;
    promsumsse = promsumsse / TESTS;
    perc = promsumsse * 100 / promsum;
    printf("Promedio:\nSuma:\t\t%ld\nSuma c/SSE:\t%ld\n"\
        "Suma SSE %ld porciento mas rapido que la suma normal\n", promsum, 
        promsumsse, perc);
    return 0;
}