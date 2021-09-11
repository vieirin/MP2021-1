
/**
 * \file testa_velha.cpp
 */

#include "velha.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Testa X vencedor na linha")
{
	int test[3] = {1, 1, 1};
	REQUIRE(VerificaLinha(test) == 1);
}

TEST_CASE("Testa O vencedor na linha")
{
	int test[3] = {2, 2, 2};
	REQUIRE(VerificaLinha(test) == 2);
}

TEST_CASE("Testa empate na linha")
{
	int test[3] = {0, 2, 2};
	REQUIRE(VerificaLinha(test) == -1);
}

TEST_CASE("Testa linha vazia")
{
	int test[3] = {0, 0, 0};
	REQUIRE(VerificaLinha(test) == -1);
}

TEST_CASE("Testa coluna")
{
	int teste1[3][3] = {{2, 0, 1},
						{2, 0, 1},
						{0, 2, 1}};
	REQUIRE(VerificaColuna(teste1, 0) == -1);
	REQUIRE(VerificaColuna(teste1, 1) == -1);
	REQUIRE(VerificaColuna(teste1, 2) == 1);
}

TEST_CASE("Testa diagonal")
{
	int teste1[3][3] = {{0, 1, 1},
						{0, 1, 2},
						{1, 0, 0}};

	REQUIRE(VerificaDiagonal(teste1, esquerda) == -1);
	REQUIRE(VerificaDiagonal(teste1, direita) == 1);
}

TEST_CASE("Testa velha", "[single-file]")
{
	int teste1[3][3] = {{2, 0, 1},
						{2, 0, 1},
						{0, 2, 1}};
	REQUIRE(VerificaVelha(teste1) == 1);
}

TEST_CASE("Testa Velha diagonal")
{
	int teste1[3][3] = {{2, 0, 1},
						{2, 2, 1},
						{0, 2, 2}};
	REQUIRE(VerificaVelha(teste1) == 2);
}
