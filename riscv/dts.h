// See LICENSE for license details.
#ifndef _RISCV_DTS_H
#define _RISCV_DTS_H

#include "processor.h"
#include "mmu.h"
#include <string>

std::string make_dts(size_t insns_per_rtc_tick, size_t cpu_hz,
                     reg_t initrd_start, reg_t initrd_end,
                     std::vector<processor_t*> procs,
                     std::vector<std::pair<reg_t, mem_t*>> mems);

std::string dts_compile(const std::string& dts);

int fdt_parse_clint(void *fdt, reg_t *clint_addr,
                    const char *compatible);
int fdt_parse_pmp_num(void *fdt, reg_t *pmp_num,
                      const char *compatible);
int fdt_parse_pmp_alignment(void *fdt, reg_t *pmp_align,
                            const char *compatible);
#endif
