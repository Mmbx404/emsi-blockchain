#include "blockchain.h"


/**
 * block_hash - computes the hash of a Block
 * @block: points to the Block to be hashed
 * @hash_buf: The resulting hash must be stored in it
 *
 * Return: pointer to hash_buf
 */
uint8_t *block_hash(block_t const *block,
		uint8_t hash_buf[SHA256_DIGEST_LENGTH])
{
size_t len = sizeof(block->info) + block->data.len;
memset(hash_buf, 0, SHA256_DIGEST_LENGTH);
if (!block || !hash_buf)
return (NULL);
return (sha256((int8_t const *)&(block->info), len, hash_buf));
}

