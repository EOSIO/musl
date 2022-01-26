#pragma once
/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */

#include <features.h>
#include <stdint.h>

#define STDIN_FILENO  0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

#ifdef __cplusplus
extern "C" {
#endif
   __attribute__((import_name("isatty"))) 
   __attribute__((__visibility__("hidden")))
   __attribute__((__weak__))
   int isatty(int);
   /**
    * Allocate page(s) of memory to accommodate the
    * requested number of bytes.
    * @brief Allocate page memory
    * @param num_bytes  Number of bytes to add.
    *
    * @return void pointer to the previous end of allocated bytes
    *
    * Example:
    * @code
    * // allocate a whole new page, the returned offset is the pointer to the
    * // newly allocated page
    * char* new_page = static_cast<char*>(sbrk(65536));
    * memset(new_page, 0, 65536);
    * @endcode
    */
   void* sbrk( uint32_t num_bytes );

#ifdef __cplusplus
}
#endif
