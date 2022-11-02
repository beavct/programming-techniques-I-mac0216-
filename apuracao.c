#include "aula18-apuracao.h"

void pegaJson (void) {
    CURL *curl;
    CURLcode res;
    FILE *devnull;

    devnull = fopen("/dev/null", "w");
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://resultados.tse.jus.br/oficial/ele2022/545/dados-simplificados/br/br-c0001-e000545-r.json");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, cortaJson);
#ifdef SKIP_PEER_VERIFICATION
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
#endif

#ifdef SKIP_HOSTNAME_VERIFICATION
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
#endif
        res = curl_easy_perform(curl);

        /* TODO: entender porque o curl_easy_perform retorna erro
         * quando uso uma função de callback. Por causa desse erro que
         * estou enviando a mensagem para o /dev/null
         */
        if(res != CURLE_OK)
            fprintf(devnull, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    fclose(devnull);
}

void cortaJson (void *ptr, size_t size, size_t nmemb, void *stream) {
    char separador[2]=",";
    char nome1[201];
    char nome2[201];
    char inteiro1[201];
    char inteiro2[201];
    char decimal1[201];
    char decimal2[201];

    int i;

    strtok((char *)ptr, separador);

    for (i=1;i<89;i++)
        strtok(NULL, separador);
    /* Nome do candidato em primeiro */
    strncpy(nome1, strtok(NULL, separador), 201);

    for (;i<95;i++)
        strtok(NULL, separador);

    /* Parte inteira da porcentagem do primeiro */
    strncpy(inteiro1, strtok(NULL, separador), 201);
    /* Parte decimal da porcentagem do primeiro */
    strncpy(decimal1, strtok(NULL, separador), 201);

    for (;i<98;i++)
        strtok(NULL, separador);
    /* Nome do candidato em segundo */
    strncpy(nome2, strtok(NULL, separador), 201);

    for (;i<104;i++)
        strtok(NULL, separador);

    /* Parte inteira da porcentagem do primeiro */
    strncpy(inteiro2, strtok(NULL, separador), 201);
    /* Parte decimal da porcentagem do primeiro */
    strncpy(decimal2, strtok(NULL, separador), 201);

    imprimeNomesPorcentagens(nome1, inteiro1, decimal1, nome2, inteiro2, decimal2);
}

void imprimeNomesPorcentagens (char * nome1, char * inteiro1, char * decimal1, char * nome2, char * inteiro2, char * decimal2) {
    char separador[2]="\"";
    int i;
  
    strtok(nome1, separador);
    for (i=0;i<2;i++) 
        strtok(NULL, separador);
    printf("%s ", strtok(NULL, separador));

    strtok(inteiro1, separador);
    for (i=0;i<2;i++) 
        strtok(NULL, separador);
    printf("%s.", strtok(NULL, separador));
    printf("%s\n", strtok(decimal1, separador));

    strtok(nome2, separador);
    for (i=0;i<2;i++) 
        strtok(NULL, separador);
    printf("%s ", strtok(NULL, separador));

    strtok(inteiro2, separador);
    for (i=0;i<2;i++) 
        strtok(NULL, separador);
    printf("%s.", strtok(NULL, separador));
    printf("%s\n", strtok(decimal2, separador));
}
