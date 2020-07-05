#include "lib/hashcode.h"

static const int HASH_SEED = 5381;
static const int HASH_MULTIPLIER = 33;
static const int HASH_MASK = unsigned(-1) >> 1;