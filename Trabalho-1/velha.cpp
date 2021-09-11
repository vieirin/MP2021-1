/**
 * \file  velha.cpp
 */

#include "velha.hpp"

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