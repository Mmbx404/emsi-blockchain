#include "blockchain.h"

#define G_TIMESTAMP 1537578000
#define G_DATA "Holberton School"
#define G_DATA_LEN 16
#define G_HASH "\xc5\x2c\x26\xc8\xb5\x46\x16\x39\x63\x5d\x8e" \
								"\xdf\x2a\x97\xd4\x8d\x0c\x8e\x00\x09\xc8\x17" \
"\xf2\xb1\xd3\xd7\xff\x2f\x04\x51\x58\x03"

/**
 * blockchain_create - creates a genesis blockchain
 * Return: pointer to new blockchain or NULL on error
 */
blockchain_t *blockchain_create(void)
{
	blockchain_t *initialBlockChain = calloc(1, sizeof(*initialBlockChain));
	block_t *genesisBlock = calloc(1, sizeof(*genesisBlock));
	llist_t *list = llist_create(MT_SUPPORT_TRUE);

	if (!initialBlockChain || !genesisBlock || !list)
	{
		free(initialBlockChain), free(genesisBlock), llist_destroy(list, 1, NULL);
		return (NULL);
	}
	genesisBlock->info.timestamp = G_TIMESTAMP;
	memcpy(&(genesisBlock->data.buffer), G_DATA, G_DATA_LEN);
	genesisBlock->data.len = G_DATA_LEN;
	memcpy(&(genesisBlock->hash), G_HASH, SHA256_DIGEST_LENGTH);

	if (llist_add_node(list, genesisBlock, ADD_NODE_FRONT))
	{
		free(initialBlockChain), free(genesisBlock), llist_destroy(list, 1, NULL);
		return (NULL);
	}
	initialBlockChain->chain = list;
	return (initialBlockChain);
}

