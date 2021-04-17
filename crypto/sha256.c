#include "hblk_crypto.h"

uint8_t *sha256(int8_t const *s, size_t len, uint8_t digest[SHA256_DIGEST_LENGTH]) {
	if (!s || !digest) {
		return null;
	} else {
		SHA256_CTX c;
		SHA256_Init(&c);
		SHA256_Update(&c, s, len);
		SHA256_Final(digest, &c);
		return digest;
	}
}
