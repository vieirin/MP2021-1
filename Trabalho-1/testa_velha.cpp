
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

TEST_CASE("Testa indefinido na linha")
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

	int teste2[3][3] = {{2, 2, 1},
						{2, 1, 2},
						{2, 1, 1}};
	REQUIRE(VerificaVelha(teste2) == 2);

	int teste3[3][3] = {{2, 2, 1},
						{1, 1, 2},
						{2, 1, 1}};
	REQUIRE(VerificaVelha(teste3) == 0);

	int teste4[3][3] = {{0, 2, 1},
						{0, 1, 2},
						{2, 1, 1}};
	REQUIRE(VerificaVelha(teste4) == -1);

	int teste[3][3] = {{1, 1, 1},
					   {2, 1, 2},
					   {2, 2, 1}};
	REQUIRE(VerificaVelha(teste) == 1);

	int teste5[3][3] = {{2, 2, 2},
						{1, 1, 1},
						{0, 0, 0}};
	REQUIRE(VerificaVelha(teste5) == -2);

	int teste6[3][3] = {{1, 2, 0},
						{1, 2, 0},
						{1, 2, 0}};
	REQUIRE(VerificaVelha(teste6) == -2);
}

TEST_CASE("Testa Velha diagonal")
{
	int teste1[3][3] = {{2, 0, 1},
						{2, 2, 1},
						{0, 1, 2}};
	REQUIRE(VerificaVelha(teste1) == 2);
}

TEST_CASE("Testa numero de jogadas do jogador")
{
	int teste1[3][3] = {{2, 0, 1},
						{2, 2, 1},
						{0, 2, 2}};
	REQUIRE(countPlays(teste1, X) == 5);
	REQUIRE(countPlays(teste1, O) == 2);
}

TEST_CASE("Testa é jogo impossível")
{
	int teste1[3][3] = {{2, 0, 1},
						{2, 2, 1},
						{0, 2, 2}};
	REQUIRE(isImpossibleGame(teste1));

	int teste2[3][3] = {{2, 0, 1},
						{2, 2, 1},
						{0, 0, 0}};
	REQUIRE_FALSE(isImpossibleGame(teste2));

	int teste3[3][3] = {{2, 2, 2},
						{2, 2, 2},
						{2, 2, 2}};
	REQUIRE(isImpossibleGame(teste3));

	int teste4[3][3] = {{1, 1, 1},
						{1, 1, 1},
						{1, 1, 1}};
	REQUIRE(isImpossibleGame(teste4));
}

TEST_CASE("Testa jogo indefinido")
{
	int teste1[3][3] = {{0, 0, 1},
						{0, 0, 0},
						{0, 0, 0}};
	REQUIRE(VerificaVelha(teste1) == -1);

	int teste2[3][3] = {{0, 0, 2},
						{0, 0, 0},
						{0, 0, 0}};
	REQUIRE(VerificaVelha(teste1) == -1);

	int teste3[3][3] = {{2, 0, 1},
						{1, 2, 1},
						{0, 0, 2}};

	REQUIRE_FALSE(VerificaVelha(teste3) == -1);
}

TEST_CASE("Testa empate")
{
	int teste1[3][3] = {{1, 2, 1},
						{2, 1, 2},
						{2, 1, 2}};
	REQUIRE(isDraw(teste1));

	int teste2[3][3] = {{1, 2, 1},
						{2, 0, 2},
						{2, 1, 2}};
	REQUIRE_FALSE(isDraw(teste2));
}

TEST_CASE("Testa empate impossível")
{
	int teste1[3][3] = {{2, 2, 1},
						{2, 2, 1},
						{2, 2, 2}};
	REQUIRE_FALSE(isDraw(teste1));
}
