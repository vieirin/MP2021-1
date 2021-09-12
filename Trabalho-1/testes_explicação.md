# Explicação dos testes e o que passar neles significa

## VerificaLinha

`VerificaLinha` é a função base do código através da qual as outras são construídas
portanto, devemos verificar primeiros seus casos

    - Há um vencedor na linha ou não? Se sim retorna este vencedor
    - a linha é vazia? Se sim então está indefinido
    - Do contrário: indefinido

Se todos os elementos forem iguais em pares `(([0] == [1]) && ([1] == [2]))`, então retona o valor do jogador

### Testa X vencedor na linha

Verifica se dado uma linha onde todos os elemetnos são iguais a X o retorno é igual a X

### Testa O vencedor na linha

Verifica se dado uma linha onde todos os elemetnos são iguais a O o retorno é igual a O

### Testa indefinido na linha

Verifica se a linha não tem um vencedor (caso -1)

### Testa linha vazia

Verifica se dado uma linha onde todos os elemetnos são iguais a 0 o retorno é igual a 0

## VerificaColuna

`VerificaColuna` é reponsável por verificar se há um vencedor numa dada coluna de uma matriz
o processo é executado convertendo a coluna requisitada em uma linha e invocando a função `VerificaLinha`, não sendo necessário extender os casos de teste base.
Os casos então se resumem aos casos da função `VerificaLinha`

### Testa coluna

Dado uma matriz verifica se há algum vencedor em alguma das linhas, verifica-se coluna a coluna, por isso três condições devem ser satisfeitas.

## VerificaDiagonal

`VerificaDiagonal` segue a mesma componentização de `VerificaColuna`, mas no lugar do argumento da posição da coluna, extraimos a diagonal baseado no argumento de direção (esquerda ou direita)

### Testa diagonal

Verifica se para uma dada matriz há um vencedor em suas diagonais, com uma matriz apenas é possível testar os dois casos possíveis (direita e esquerda), já que como `VerificaDiagonal` é construída da composição de `VerificaLinha` basta que a segunda tenha casos suficientes de teste.

## CountPlays

`CountPlays` é uma função auxiliar que serve para contar quantas casas um jogador preencheu em uma matriz

### Testa numero de jogadas do jogador

Dado uma matriz qualquer, é esperado que a função retorne a quantidade correta de jogadas de cada um dos jogadores em um tabuleiro.

## isDraw

`isDraw` verifica se um jogo está empatado, esse caso só é possível se o jogo não for impossível e se a matriz está totalmente preenchida.

### Testa empate

Dado uma matriz qualquer, se houver 0 no tabuleiro é esperado que **não** haja um empate.

### Testa empate impossível

Dado uma matriz representando um tabuleiro impossível a função deve retornar falso

## isImpossibleGame

`isImpossibleGame` verifica se há um jogador com uma diferença maior do que 2 entre o número de jogadas presentes no tabuleiros

### Testa é jogo impossível

Dado uma matriz impossível, deve retornar true, dado uma matriz possível deve retornar false

## VerificaVelha

`VerificaVelha` organiza todas as verificações anteriores e agrupa os retornos das funções auxiliares com o objetivo de informar ao caller se há um vencedor no tabuleiro, se o jogo é impossível, está em empate ou se é indefinido.

### Testa velha

Dado uma matriz qualquer deve retornar o estado do jogo, respeitada as devidas condições e regras do jogo. Há uma serie de requerimentos sendo verificado para cada tipo de retorno esperado.
