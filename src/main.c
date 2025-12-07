/*
 * Copyright (c) 2024-2025, Erich Styger
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "McuRTOS.h"
#include "platform.h"
#include <stdio.h>
#if PL_CONFIG_USE_GCOV
#include "McuCoverage.h"
#endif

#include "gcov_test.h"

int main(void) {

  volatile int i = 0;
  gcov_test(i);

  PL_Init();
  vTaskStartScheduler();
#if PL_CONFIG_USE_GCOV
  McuCoverage_WriteFiles(); /* write coverage data files */
#endif                      /* PL_CONFIG_USE_GCOV */

  for (;;) {
    /* do not return from main() */
  }
  return 0;
}
