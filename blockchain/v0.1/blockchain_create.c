#include "blockchain.h"

blockchain_t *blockchain_create(void) {
	struct blockchain_s initialBlockChain;
	struct block_s genesisBlock;
	struct block_info_s genesisBlockInfo;
	struct block_data_s genesisBlockData;
	char  initialData[] = "Holberton School";
/* 	genesisBlockData.buffer = initialData;
	genesisBlockData.len = strlen("Holberton School"); */
	genesisBlockInfo.index = 0;
	genesisBlockInfo.difficulty = 0;
	genesisBlockInfo.timestamp = 1537578000;
	genesisBlockInfo.nonce = 0;
//	genesisBlockInfo.prev_hash = 0;
	genesisBlock.data = genesisBlockData;
	genesisBlock.info = genesisBlockInfo;
	return initialBlockChain;
}

int main(void)
{
	blockchain_create();
}
