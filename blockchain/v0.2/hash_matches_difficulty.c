#include "blockchain.h"

/**
 * hash_matches_difficulty - checks wether a given hash
 * matches a given difficulty
 * @hash: hash to be tested
 * @difficulty: difficulty used to test the hash
 *
 * Return: 0 | 1
 */
int hash_matches_difficulty(uint8_t const hash[SHA256_DIGEST_LENGTH],
uint32_t difficulty)
{
int i = 0;
for (i = 0; i <= difficulty; i++)
{
if (hash[i] != 0)
return (0);
}
return (1);
}
