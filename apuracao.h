#ifndef _APURACAO_2022_H_
#define _APURACAO_2022_H_

/* Biblioteca com funções úteis para baixar e 'parsear' a saída do
 * resultado das eleições de 2022 enquanto a apuração acontece no
 * domingo, dia 30/10
 * 
 * Útil para a aula sobre bibliotecas estáticas da disciplina MAC0216
 * do Bacharelado em Ciência da Computação da USP
 * 
 * Por Prof. Daniel Macêdo Batista <batista@ime.usp.br> em 30/10/2022
 * 
 * Dependências: libcurl4
 * Sugiro instalar também o pacote de documentação para aprender mais
 * sobre a biblioteca:
 * 
 * apt-get install libcurl4  libcurl4-doc libcurl4-openssl-dev
 * 
 * TODO: Inesperadamente o programa abortou com um erro de "Falha de
 * segmentação". Isso precisa ser investigado. É importante testar o
 * código para garantir que ele consegue lidar com saídas do curl
 * inesperadas (por exemplo, se a requisição ao servidor do TSE não
 * retornar o arquivo json pelo fato do servidor estar muito ocupado).
 * 
 */

#include <curl/curl.h>
#include <stdio.h>
#include <string.h>

/* 
 * Função: pegaJson
 * Uso: pegaJson();
 * ---------------------------------
 *
 * Baixa o json que contém o resultado da apuração do segundo turno
 * das eleições presidenciais de 2022 e imprime apenas os nomes dos
 * candidatos e as porcentagens de votos na saída padrão (este arquivo
 * vai sendo atualizado com o passar das horas pelo TSE). A URL do
 * json é
 * 
 * https://resultados.tse.jus.br/oficial/ele2022/545/dados-simplificados/br/br-c0001-e000545-r.json
 *
 * Esse código é praticamente uma cópia do arquivo de exemplo
 *
 * /usr/share/doc/libcurl4/examples/https.c
 *
 * Também usa sugestões de:
 *
 * https://stackoverflow.com/questions/2329571/c-libcurl-get-output-into-a-string
 * 
 */
void pegaJson (void);

/* 
 * Função: cortaJson
 * Uso: curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, cortaJson);
 * ---------------------------------
 *
 * Modifica os parâmetros com várias informações da string resultante
 * de um acesso HTTPS do curl. É uma cópia da sugestão de
 * 
 * https://stackoverflow.com/questions/2329571/c-libcurl-get-output-into-a-string
 * 
 * Você não precisa usar essa função diretamente. A pegaJson acima é quem vai
 * usá-la.
 * 
 * parâmetro 1: (string) o retorno de um acesso feito pelo curl
 * parâmetro 2: (inteiro) sempre vale 1
 * parâmetro 3: (inteiro) o tamanho do parâmetro 1
 * parâmetro 4: (???) 'userdata' (de acordo com a manpage). A
 *                    documentação não deixou muito claro
 * 
 */
void cortaJson (void *, size_t , size_t , void *);

/*
 * Função: imprimeNomesPorcentagens
 * Uso: imprimeNomesPorcentagens(campo4_lin1_json, campo11_lin1_json, campo12_lin1_json, campo4_lin2_json, campo11_lin2_json, campo12_lin2_json);
 * ---------------------------------
 * 
 * Imprime no stdout os nomes e as porcentagens de votos dos dois
 * candidatos. Exemplo de saída:
 *
 * LULA 00.00
 * JAIR BOLSONARO 00.00
 * 
 * Você não precisa usar essa função diretamente. A cortaJson acima é
 * quem vai usá-la.
 * 
 * IMPORTANTE: os campos do json têm que ter no máximo 200 caracteres
 * cada. Se tiver mais que isso vai ser truncado
 * 
 * parâmetro 1: (string) campo 4 da linha 1 do json
 * parâmetro 2: (string) campo 11 da linha 1 do json
 * parâmetro 3: (string) campo 12 da linha 1 do json
 * parâmetro 4: (string) campo 4 da linha 2 do json
 * parâmetro 5: (string) campo 11 da linha 2 do json
 * parâmetro 6: (string) campo 12 da linha 2 do json
 * 
 */
void imprimeNomesPorcentagens (char *, char *, char *, char *, char *, char *);

#endif
