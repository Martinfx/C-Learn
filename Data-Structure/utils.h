#pragma once

/* It return minimun from two values */
#define min(a, b)                                                              \
  ({                                                                           \
    typeof(a) _a = (a);                                                        \
    typeof(b) _b = (b);                                                        \
    (_a) < (_b) ? (_a) : (_b);                                                 \
  })

/* It return maximum from two values */
#define max(a, b)                                                              \
  ({                                                                           \
    typeof(a) _a = (a);                                                        \
    typeof(b) _b = (b);                                                        \
    (_a) > (_b) ? (_a) : (_b);                                                 \
  })
