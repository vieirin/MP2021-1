/**
 * \file  velha.cpp
 */

#include "velha.hpp"
#include "math.h"

/** 
 * @brief verifica situacao do jogo da velha  
 * @author Manoel Vieira 
 * @param  velha Matrix 3x3 com valores entre 0-3
 * 
 *  Verifica se o jogo recebido tem um ganhador, se é impossível 
 */
int VerificaVelha(int velha[3][3])
{
	if (isImpossibleGame(velha))
	{
		return -2;
	}

	for (auto i = 0; i < 3; i++)
	{
		auto result = VerificaLinha(velha[i]);
		if (result == 1 || result == 2)
		{
			return result;
		}
	}

	for (auto i = 0; i < 3; i++)
	{
		auto result = VerificaColuna(velha, i);
		if (result == 1 || result == 2)
		{
			return result;
		}
	}

	for (auto i = 0; i < 2; i++)
	{
		auto result = VerificaDiagonal(velha, static_cast<Direcao>(i));
		if (result == 1 || result == 2)
		{
			return result;
		}
	}

	return isDraw(velha) ? 0 : -1;
}

/** 
 * @brief verifica se uma linha contém um vencendor 
 * @author Manoel Vieira 
 * @param  linha vetor de tamanho 3 com valores entre 0-3
 * 
 * Verifica se todas as ocorrências da linha são iguais, caso verdadeiro
 * retorna o valor do elemento repetido (1(x) ou 2(o)), caso falso retorna -1
 * (indefinido);
 * 
 */
int VerificaLinha(int linha[3])
{
	if (!linha[0])
	{
		return -1;
	}

	for (auto elem = 1; elem < 3; elem++)
	{
		if (linha[elem] != linha[elem - 1])
		{
			return -1;
		}
	}

	return linha[0];
}

/** 
 * @brief verifica se uma dada coluna contém um vencedor 
 * @author Manoel Vieira 
 * @param  linha vetor de tamanho 3 com valores entre 0-3
 * @param  col coluna a ser verificada
 * 
 * Extrai a coluna requerida em forma de linha e retorna o resultado
 * de VerificaLinha
 * 
 */
int VerificaColuna(int velha[3][3], int col)
{
	int column[3] = {velha[0][col],
					 velha[1][col],
					 velha[2][col]};
	return VerificaLinha(column);
}

/** 
 * @brief verifica se uma dada diagonal contém um vencedor 
 * @author Manoel Vieira 
 * @param  linha vetor de tamanho 3 com valores entre 0-3
 * @param  dir direção da diagonal (esquerda ou direita)
 * 
 * Extrai a diagonal requerida em forma de linha e retorna o resultado
 * de VerificaLinha
 * 
 */
int VerificaDiagonal(int velha[3][3], Direcao dir)
{
	int column[3];
	auto i = 0;

	for (auto j = (dir == esquerda ? 0 : 2); (dir == esquerda ? j < 3 : j >= 0); dir == esquerda ? j++ : j--, i++)
	{
		column[i] = velha[i][j];
	}

	return VerificaLinha(column);
}

/** 
 * @brief conta as ocorrências de um jogador (X ou O) na matriz 
 * @author Manoel Vieira 
 * @param  velha matrix 3x3 com valores entre 0-3
 * @param  player player a ser contado as ocorrencias
 * 
 * Visita cada elemento da matriz e retorna a quantidade de ocorrencias
 * do jogados player no jogo recebido
 * 
 */
int countPlays(int velha[3][3], Player player)
{
	auto count = 0;
	for (auto i = 0; i < 3; i++)
	{
		for (auto j = 0; j < 3; j++)
		{
			if (velha[i][j] == static_cast<int>(player))
			{
				count++;
			}
		}
	}

	return count;
}

/** 
 * @brief verifica se há um empate no jogo (matriz cheia sem vencedor)
 * @author Manoel Vieira 
 * @param  velha matrix 3x3 com valores entre 0-3
 * 
 * Caso haja algum elemento vazio na matriz, retorna falso, do contrário, verdadeiro.
 * 
 */
bool isDraw(int velha[3][3])
{
	if (isImpossibleGame(velha))
		return false;
	for (auto i = 0; i < 3; i++)
	{
		for (auto j = 0; j < 3; j++)
		{
			if (velha[i][j] == 0)
			{
				return false;
			}
		}
	}
	return true;
}

/** 
 * @brief verifica se é um jogo impossível
 * @author Manoel Vieira 
 * @param  velha matrix 3x3 com valores entre 0-3
 * 
 * A partir do numero de jogadas de cada jogador um jogo impossível é aquele em 
 * que não há um mais de duas ocorrencias a mais de um jogador que do outro
 * 
 */
bool isImpossibleGame(int velha[3][3])
{
	auto xplays = countPlays(velha, X);
	auto oplays = countPlays(velha, O);
	if (abs(xplays - oplays) > 2)
	{
		return true;
	}

	auto winnerCounter = 0;
	for (auto linha = 0; linha < 3; linha++)
	{
		if (VerificaLinha(velha[linha]) > 0)
		{
			winnerCounter++;
		}
	}

	if (winnerCounter > 1)
	{
		return true;
	}

	for (auto col = 0; col < 3; col++)
	{
		if (VerificaColuna(velha, col) > 0)
		{
			winnerCounter++;
		}
	}

	if (winnerCounter > 1)
	{
		return true;
	}

	return false;
}
