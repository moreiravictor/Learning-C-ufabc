#include <stdio.h>
#include <stdlib.h>

typedef struct atleta_s {
    char nome[100];
    int min;
    int seg;
    int dec;
    int tempo_total;
} atleta;

typedef struct serie_s {
    atleta arrayAtletas[2000];
} serie;

void ordenaAtletas(atleta *listaAtletas, int qtdAtletas) {
    atleta *aux = malloc(sizeof(atleta));
    for (int j = 0;j<qtdAtletas; j++) {
        if (listaAtletas[j].tempo_total == 0) listaAtletas[j].tempo_total = 360000;
    }
    for (int i = 0; i < qtdAtletas-1; i++) {
        for (int j = 0; j < qtdAtletas-1-i; j++) {  
            if (listaAtletas[j].tempo_total > listaAtletas[j+1].tempo_total) {
                *aux = listaAtletas[j];
                listaAtletas[j] = listaAtletas[j+1];
                listaAtletas[j+1] = *aux;
            }
        }
    }
    free(aux);
}

int main() {
    int qtdRaias, qtdAtletas, qtdSeries;
    scanf("%d %d", &qtdRaias, &qtdAtletas);
    atleta *listaAtletas = malloc(qtdAtletas*sizeof(atleta));
    for (int i = 0; i < qtdAtletas; i++) {
        scanf("%s %d %d %d", listaAtletas[i].nome, &listaAtletas[i].min, &listaAtletas[i].seg, &listaAtletas[i].dec);
        //converting to dec
        listaAtletas[i].tempo_total =  listaAtletas[i].dec + (listaAtletas[i].min*60*100) + (listaAtletas[i].seg*100);
    }

    ordenaAtletas(listaAtletas, qtdAtletas);

    int atletas_a_mais = qtdAtletas%qtdRaias;

    //calculating the quantity of series
    if(atletas_a_mais == 0) qtdSeries = qtdAtletas/qtdRaias;
    else qtdSeries = (qtdAtletas/qtdRaias)+1;
    (qtdSeries > 1) ? printf("%d series\n", qtdSeries) : printf("%d serie\n", qtdSeries);
    serie *arraySerie = malloc(qtdSeries*(sizeof(serie)));

    //passando os atletas para array de series
    int k = 0, j = 0;
    for (int i = 0; i < qtdSeries; i++) {
        k = 0;
        if (atletas_a_mais < 3 && atletas_a_mais > 0) {
            if (i == qtdSeries-2) {
                while (k < qtdRaias - (3 - atletas_a_mais)) {
                    arraySerie[i].arrayAtletas[k] = listaAtletas[j];
                    k++;
                    j++;
                }
            }
            else if (i == qtdSeries-1) {
                k = 0;
                while (k < 3) {
                    arraySerie[i].arrayAtletas[k] = listaAtletas[j];
                    k++;
                    j++;
                }
            }
            else {
                k = 0;
                while(k < qtdRaias) {
                    arraySerie[i].arrayAtletas[k] = listaAtletas[j];
                    // printf("%s\n", listaAtletas[j].nome);
                    k++;
                    j++;
                }
            }
        }
        else {
            if (i == qtdSeries-1 && qtdSeries > 1) {
                if (atletas_a_mais > 0) {
                    while (k < atletas_a_mais) {
                        arraySerie[i].arrayAtletas[k] = listaAtletas[j];
                        k++;
                        j++;
                    }
                }
                else {
                    k = 0;
                    while(k < qtdRaias) {
                        arraySerie[i].arrayAtletas[k] = listaAtletas[j];
                        k++;
                        j++;
                    }
                }
            }
            else {
                k = 0;
                while(k < qtdRaias) {
                    arraySerie[i].arrayAtletas[k] = listaAtletas[j];
                    k++;
                    j++;
                }
            }
        }
    }

    //printando as series de atletas
    int serie = 1;
    for (int i = qtdSeries-1; i >= 0; i--) {
        int raia_inicial = qtdRaias/2, poe_tira = 1, raia = qtdRaias/2;
        if (qtdRaias % 2 != 0 ) {
            raia_inicial = (qtdRaias/2)+1;
            raia = raia_inicial;
        }
        
        printf("%da. serie:\n", serie++);
        if (i == qtdSeries-1 && qtdSeries > 1) {
            if (atletas_a_mais > 0 && atletas_a_mais < 3 && qtdAtletas >= 3) {
                for (int j = 0; j < 3; j++) {
                    printf("Raia %d: %s\n",raia, arraySerie[i].arrayAtletas[j].nome);
                    if (j%2 == 0) {
                        raia = raia_inicial + poe_tira;
                        poe_tira++;
                    }
                    else raia = raia_inicial - poe_tira + 1;
                }
            }
            else if (atletas_a_mais > 0) {
                for (int j = 0; j < atletas_a_mais; j++) {
                    printf("Raia %d: %s\n",raia, arraySerie[i].arrayAtletas[j].nome);
                    if (j%2 == 0) {
                        raia = raia_inicial + poe_tira;
                        poe_tira++;
                    }
                    else raia = raia_inicial - poe_tira + 1;
                }
            }
            else {
                for (int j = 0; j < qtdRaias; j++) {
                    printf("Raia %d: %s\n",raia, arraySerie[i].arrayAtletas[j].nome);
                    if (j%2 == 0) {
                        raia = raia_inicial + poe_tira;
                        poe_tira++;
                    }
                    else raia = raia_inicial - poe_tira + 1;
                }
            }
        }
        else {
            if(i == qtdSeries-2) {
                if (atletas_a_mais < 3 && atletas_a_mais > 0) {
                    for (int j = 0; j < qtdRaias - (3 - atletas_a_mais); j++) {
                        printf("Raia %d: %s\n",raia, arraySerie[i].arrayAtletas[j].nome);
                        if (j%2 == 0) {
                            raia = raia_inicial + poe_tira;
                            poe_tira++;
                        }
                        else raia = raia_inicial - poe_tira + 1;
                    }
                }
                else {
                    if (qtdAtletas >= qtdRaias) {
                        for (int j = 0; j < qtdRaias; j++) {
                            printf("Raia %d: %s\n",raia, arraySerie[i].arrayAtletas[j].nome);
                            if (j%2 == 0) {
                                raia = raia_inicial + poe_tira;
                                poe_tira++;
                            }
                            else raia = raia_inicial - poe_tira + 1;
                        }
                    }
                    else {
                        for (int j = 0; j < qtdAtletas; j++) {
                            printf("Raia %d: %s\n",raia, arraySerie[i].arrayAtletas[j].nome);
                            if (j%2 == 0) {
                                raia = raia_inicial + poe_tira;
                                poe_tira++;
                            }
                            else raia = raia_inicial - poe_tira + 1;
                        }
                        
                    }
                }
            }
            else {
                if (qtdAtletas >= qtdRaias) {
                    for (int j = 0; j < qtdRaias; j++) {
                        printf("Raia %d: %s\n",raia, arraySerie[i].arrayAtletas[j].nome);
                        if (j%2 == 0) {
                            raia = raia_inicial + poe_tira;
                            poe_tira++;
                        }
                        else raia = raia_inicial - poe_tira + 1;
                    }
                }
                else {
                    for (int j = 0; j < qtdAtletas; j++) {
                        printf("Raia %d: %s\n",raia, arraySerie[i].arrayAtletas[j].nome);
                        if (j%2 == 0) {
                            raia = raia_inicial + poe_tira;
                            poe_tira++;
                        }
                        else raia = raia_inicial - poe_tira + 1;
                    }
                }
            }
            
        }
    }

    free(listaAtletas);
    return 0;
}
