// Unlike EOSIO, CosmWasm doesn't have compiler builtin imports.
// Include this when building libc for CosmWasm.
// TODO: Add remaining compiler builtins
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

void __udivti3(unsigned __int128* ret, uint64_t la, uint64_t ha, uint64_t lb, uint64_t hb) {
   unsigned __int128 lhs = ha;
   unsigned __int128 rhs = hb;

   lhs <<= 64;
   lhs |=  la;

   rhs <<= 64;
   rhs |=  lb;
   //if ( rhs == 0 )
   //   eosio_assert(false, "divide by zero");

   lhs /= rhs;
   *ret = lhs;
}
