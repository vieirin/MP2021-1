
enum Direcao
{
    direita,
    esquerda
};

enum Player
{
    X,
    O
};

int VerificaVelha(int velha[3][3]);
int VerificaLinha(int velha[3]);
int VerificaColuna(int velha[3][3], int col);
int VerificaDiagonal(int velha[3][3], Direcao dir);
