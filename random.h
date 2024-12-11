#ifndef _RANDOM_H
#define _RANDOM_H
#include <ctime> 

extern "C" {
    class Random {
        private:
        static unsigned long next;
        
        public:
        static int spawnNum(); 
    };
}
#endif