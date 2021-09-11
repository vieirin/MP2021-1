
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

TEST_CASE("Testa velha", "[single-file]")
{
	int teste1[3][3] = {{2, 0, 1},
						{2, 0, 1},
						{0, 2, 1}};
	REQUIRE(VerificaVelha(teste1) == 1);
}
