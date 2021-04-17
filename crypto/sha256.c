#include "hblk_crypto.h"

uint8_t *sha256(int8_t const *s, size_t len, uint8_t digest[SHA256_DIGEST_LENGTH]) {
	if (!s) {
		return NULL;
	} else {
		EVP_MD_CTX* evp_md_ctx;
        const EVP_MD* evp_md;
        int md_length;
        evp_md = EVP_sha256();
        evp_md_ctx = EVP_MD_CTX_create();
        EVP_DigestInit_ex(evp_md_ctx, evp_md, NULL);
        EVP_DigestUpdate(evp_md_ctx, s, strlen(s));
        EVP_DigestFinal_ex(evp_md_ctx, digest, &md_length);
        EVP_MD_CTX_destroy(evp_md_ctx);
        EVP_cleanup();
        return digest;
	}
}
