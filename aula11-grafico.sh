#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Uso: $0 <arquivo saída do aula11-apuracao.sh>"
    echo "Obs.: esse script depende de dois programas: gnuplot e xloadimage."
    echo "      o gnuplot é essencial. O xloadimage até pode ser desconsiderado"
    echo "      caso você resolva ver o .png em outro visualizador de imagens."
    echo "      Caso você não queira instalar o xloadimage, remova as"
    echo "      chamdas a ele nas linhas abaixo"
    exit 1
fi

TMP1="/tmp/arquivo1.txt"
TMP2="/tmp/arquivo2.txt"
GRAFICO1="/tmp/grafico1.png"
GRAFICO2="/tmp/grafico2.png"

# Pega as linhas de cada candidato, fica apenas com os números e
# guarda em arquivos temporários que serão usados pelo gnuplot para
# gerar os gráficos
grep BOLSONARO $1 | cut -f 3 -d ' ' > ${TMP1}
grep LULA $1 | cut -f 2 -d ' ' > ${TMP2}

# Obs.: o gnuplot é bem poderoso. É possível colocar uma legenda que
# faça sentido e mexer em muita coisa mas o objetivo aqui é ir direto
# ao ponto de gerar os gráficos

# Gerando um primeiro gráfico no gnuplot
echo "set terminal png; plot \"${TMP1}\", \"${TMP2}\"" | gnuplot > ${GRAFICO1}; xloadimage ${GRAFICO1}

# Espera o usuário digitar ENTER para continuar
echo "Pressione ENTER para continuar e gerar outro gráfico"
read

# Gerando um segundo gráfico no gnuplot um pouco diferente do anterior
echo "set terminal png size 1024,768; plot \"${TMP1}\" with lines lt rgb 'blue', \"${TMP2}\" with lines lt rgb 'red'" | gnuplot > ${GRAFICO2}; xloadimage ${GRAFICO2}

# Não preciso mais dos arquivos temporários
rm -f ${TMP1} ${TMP2}

exit 0
