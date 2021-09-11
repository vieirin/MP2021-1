#ifndef __VELHA__H__
#define __VELHA__H__

enum Direcao
{
    direita,
    esquerda
};

enum Player
{
    X = 2,
    O = 1
};

int VerificaVelha(int velha[3][3]);
int VerificaLinha(int velha[3]);
int VerificaColuna(int velha[3][3], int col);
int VerificaDiagonal(int velha[3][3], Direcao dir);
int countPlays(int velha[3][3], Player players);
bool isImpossibleGame(int velha[3][3]);

#endif //!__VELHA__H__
