#!/bin/bash

# Obs.: se vc quiser gerar um gráfico depois, execute este script
# redirecionando a saída dele para um arquivo. Por exemplo:
# ./aula11-apuracao > ~/tmp/parciais
# Se vc quiser redicionar para um arquivo mas ao mesmo tempo ver a
# saída na tela, use o tee para isso:
# ./aula11-apuracao | tee ~/tmp/parciais

# Link para o arquivo json com os números da eleição presidencial de
# 2022 (Esse arquivo foi descoberto vendo o código-fonte da página da
# apuração do TSE pelo navegador web). Para ver como era o arquivo no
# dia da apuração, veja o arquivo aula11-apuracao.json. Ele foi
# baixado no dia 2/10/2022 às 23:20. No decorrer do dia esse arquivo
# foi sendo atualizado pelo TSE
URL="https://resultados.tse.jus.br/oficial/ele2022/544/dados-simplificados/br/br-c0001-e000544-r.json"

while [ 1 ]; do # Loop infinito
    # A linha abaixo:
    # 1) Faz o download do json mais recente com o curl
    # 2) Pega apenas as linhas com as strings BOLSONARO e LULA com o grep
    # 3) Em cada linha corta apenas os trechos que têm as strings
    #    BOLSONARO e LULA e exatamente esses nomes e os números
    #    associados com os dois cut
    # 4) Substitui as aspas por espaço em branco e a vírgula por ponto com o
    #    tr
    curl -s ${URL} | grep -e BOLSONARO -e LULA | cut -f 4,11,12 -d ',' | cut -f 4,8 -d '"' | tr '",' " ."

    # Só para imprimir um separador permitindo identificar visualmente
    # que aqueles valores são os mais recentes
    echo "###########"

    # Acessa de novo daqui a 1 minuto (não vamos 'floodar' os
    # servidores do TSE!)
    sleep 60
done

exit 0
