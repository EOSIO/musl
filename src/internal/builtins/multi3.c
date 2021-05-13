// Unlike EOSIO, CosmWasm doesn't have `__multi3` import.
// Include this when building libc for CosmWasm.
#include <stdint.h>

void __multi3(__int128* ret, uint64_t la, uint64_t ha, uint64_t lb, uint64_t hb) {
   __int128 lhs = ha;
   __int128 rhs = hb;

   lhs <<= 64;
   lhs |=  la;

   rhs <<= 64;
   rhs |=  lb;

   lhs *= rhs;
   *ret = lhs;
}
