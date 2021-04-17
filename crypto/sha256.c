#include "hblk_crypto.h"

uint8_t *sha256(int8_t const *s, size_t len, uint8_t digest[SHA256_DIGEST_LENGTH]) {
	if (s == null || digest == null) {
		return null;
	} else {
		return SHA256(s, len, digest);
	}
}
