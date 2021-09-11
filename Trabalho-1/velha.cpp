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
