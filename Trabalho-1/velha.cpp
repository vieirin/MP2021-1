/**
 * \file  velha.cpp
 */

#include "velha.hpp"
#include "math.h"
/** 
 * @brief verifica situacao do jogo da velha  
 * @author Programador 
 * @param  velha descreve o parametro
 * 
 *  Descrever o que a funcao faz
 */

int VerificaVelha(int velha[3][3])
{
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

	return 0; /*!< retorna zero para teste */
}

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

int VerificaColuna(int velha[3][3], int col)
{
	int column[3] = {velha[0][col],
					 velha[1][col],
					 velha[2][col]};
	return VerificaLinha(column);
}

int VerificaDiagonal(int velha[3][3], Direcao direction)
{
	int column[3];
	auto i = 0;
	for (auto j = (direction == esquerda ? 0 : 2); (direction == esquerda ? j < 3 : j >= 0); direction == esquerda ? j++ : j--, i++)
	{
		column[i] = velha[i][j];
	}

	return VerificaLinha(column);
}

int countPlayer(int velha[3][3], Player player)
{
	int count = 0;
	for (auto i = 0; i < 3; i++)
	{
		for (auto j = 0; j < 3; j++)
		{
			if (velha[i][j] == static_cast<int>(player))
				count++;
		}
	}
	return count;
}

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

bool isImpossibleGame(int velha[3][3])
{
	if (abs(countPlays(velha, X) - countPlays(velha, O)) > 2)
	{
		return true;
	}

	return false;
}
