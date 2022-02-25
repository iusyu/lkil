//
// Created by 孙义 on 2022/2/25.
// Benchmark Tools for myself.
//

#ifndef CODE_BH_TOOLS_H
#define CODE_BH_TOOLS_H

#include <stdlib.h>
#include <time.h>

#define OUTPUT_TO_FILE 2

#if OUTPUT_TO_FILE > 1
#define NOTICE_STR "%f "
#else
#define NOTICE_STR "Time spend : %f second\n"
#endif



#define begin() clock_t tbeg = clock()
#define end() printf(NOTICE_STR, (double)(clock() - tbeg)/CLOCKS_PER_SEC)
#define measure(x, times) for( long long i = 0; i <= (times); ++i ) \
                            {   (x); }


static unsigned int* aslr_random() {
    return (unsigned int*)&aslr_random;
}

int get_rand(int begin, int end) {
    int result = 0;
    srand(aslr_random());
    for( result = rand()% end; result < begin; ) {
        result = rand() % end;
    }
    return result;
}


#endif //CODE_BH_TOOLS_H
