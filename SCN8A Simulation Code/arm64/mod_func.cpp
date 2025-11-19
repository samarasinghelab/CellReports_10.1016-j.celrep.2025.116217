#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;
#if defined(__cplusplus)
extern "C" {
#endif

extern void _ECellOlufsen_reg(void);
extern void _IcellWangBuzsaki_reg(void);
extern void _OCellTort_reg(void);

void modl_reg() {
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");
    fprintf(stderr, " \"ECellOlufsen.mod\"");
    fprintf(stderr, " \"IcellWangBuzsaki.mod\"");
    fprintf(stderr, " \"OCellTort.mod\"");
    fprintf(stderr, "\n");
  }
  _ECellOlufsen_reg();
  _IcellWangBuzsaki_reg();
  _OCellTort_reg();
}

#if defined(__cplusplus)
}
#endif
