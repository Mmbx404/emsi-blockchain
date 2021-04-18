#include "blockchain.h"

/**
 * blockchain_create - creates a genesis blockchain
 * Return: pointer to new blockchain or NULL on error
 */
blockchain_t *blockchain_create(void) {
	blockchain_t *initialBlockChain;
	block_t genesisBlock;
        block_info_t genesisBlockInfo;
        block_data_t genesisBlockData;
        llist_t *linkedList = llist_create(MT_SUPPORT_TRUE);
        char *genesisBlockHash = "\xc5\x2c\x26\xc8\xb5\x46\x16\x39\x63\x5d\x8e\xdf\x2a\x97\xd4\x8d\x0c\x8e\x00\x09\xc8\x17\xf2\xb1\xd3\xd7\xff\x2f\x04\x51\x58\x03";
        char *name = "Holberton School";
        int i;
        genesisBlockInfo.index = 0;
        genesisBlockInfo.difficulty = 0;
        genesisBlockInfo.timestamp = 1537578000;
        genesisBlockInfo.nonce = 0;
        for (i=0; i <= 32; i++)
        {
          genesisBlockInfo.prev_hash[i] = (uint8_t) 0;
          genesisBlock.hash[i] = (uint8_t) genesisBlockHash[i];
        }
        for (i=0; i <= 16; i++)
        {
           genesisBlockData.buffer[i] = (int8_t) name[i];
        }
        genesisBlockData.len = 16;
        genesisBlock.info = genesisBlockInfo;
        genesisBlock.data = genesisBlockData;
        if (llist_add_node(linkedList,(llist_node_t) genesisBlock, ADD_NODE_FRONT))
        {
             free(initialBlockChain), free(genesisBlock), llist_destroy(linkedList, 1, NULL);
             return (NULL);
        }
        initialBlockChain->chain = linkedList;
        return (initialBlockChain);
}

