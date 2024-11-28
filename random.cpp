#include "random.h"
unsigned long Random::next = time(0);

int Random::spawnNum() {
    next = next * 1103515245 + 12345; // Linear congruential generator
    return (unsigned int)(next / 65536) % 32768;
}
