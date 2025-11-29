#pragma once
#include <stdint.h>
#include <iostream>
#include <iomanip>

namespace origin
{

    // _r def vals
    #define _r0 (0 << 0)
    #define _r1 (1 << 0)
    #define _r2 (1 << 1)
    #define _r3 (1 << 2)
    #define _r4 (1 << 3)
    #define _r5 (1 << 4)
    #define _r6 (1 << 5)
    #define _r7 (1 << 6)
    #define _r8 (1 << 7)
    // _t def vals
    #define _t0 (0 << 0)
    #define _t1 (1 << 0)
    #define _t2 (1 << 1)
    #define _t3 (1 << 2)
    #define _t4 (1 << 3)
    #define _t5 (1 << 4)
    #define _t6 (1 << 5)
    #define _t7 (1 << 6)
    #define _t8 (1 << 7)

    #define total_ranks 9
    #define total_types 9

    #define total_origins ( total_ranks * total_types )

    typedef struct __attribute__((packed)) {
        uint8_t _rank;
        uint8_t _type;

        void print() {
            std::cout 
                << "r: 0x" 
                << std::hex 
                << std::setw(2) 
                << std::setfill('0') 
                << (int)_rank 
                << " | t: " 
                << std::hex 
                << std::setw(2) 
                << std::setfill('0') 
                << (int)_type 
                << "\n";
        }
    } origin_t;

    extern uint8_t all_ranks[total_ranks];

    extern uint8_t all_types[total_types];

    extern origin_t all_origin[total_origins];


    namespace rank_0 {

        extern origin_t origin_r0_t0;
        extern origin_t origin_r0_t1;
        extern origin_t origin_r0_t2;
        extern origin_t origin_r0_t3;
        extern origin_t origin_r0_t4;
        extern origin_t origin_r0_t5;
        extern origin_t origin_r0_t6;
        extern origin_t origin_r0_t7;
        extern origin_t origin_r0_t8;
        
    } // namespace rank_0
    namespace rank_1 {

        extern origin_t origin_r1_t0;
        extern origin_t origin_r1_t1;
        extern origin_t origin_r1_t2;
        extern origin_t origin_r1_t3;
        extern origin_t origin_r1_t4;
        extern origin_t origin_r1_t5;
        extern origin_t origin_r1_t6;
        extern origin_t origin_r1_t7;
        extern origin_t origin_r1_t8;
        
    } // namespace rank_1

    namespace rank_2 {

        extern origin_t origin_r2_t0;
        extern origin_t origin_r2_t1;
        extern origin_t origin_r2_t2;
        extern origin_t origin_r2_t3;
        extern origin_t origin_r2_t4;
        extern origin_t origin_r2_t5;
        extern origin_t origin_r2_t6;
        extern origin_t origin_r2_t7;
        extern origin_t origin_r2_t8;
        
    } // namespace rank_2
    
    namespace rank_3 {

        extern origin_t origin_r3_t0;
        extern origin_t origin_r3_t1;
        extern origin_t origin_r3_t2;
        extern origin_t origin_r3_t3;
        extern origin_t origin_r3_t4;
        extern origin_t origin_r3_t5;
        extern origin_t origin_r3_t6;
        extern origin_t origin_r3_t7;
        extern origin_t origin_r3_t8;
        
    } // namespace rank_3
    
    namespace rank_4 {

        extern origin_t origin_r4_t0;
        extern origin_t origin_r4_t1;
        extern origin_t origin_r4_t2;
        extern origin_t origin_r4_t3;
        extern origin_t origin_r4_t4;
        extern origin_t origin_r4_t5;
        extern origin_t origin_r4_t6;
        extern origin_t origin_r4_t7;
        extern origin_t origin_r4_t8;
        
    } // namespace rank_4
    
    namespace rank_5 {

        extern origin_t origin_r5_t0;
        extern origin_t origin_r5_t1;
        extern origin_t origin_r5_t2;
        extern origin_t origin_r5_t3;
        extern origin_t origin_r5_t4;
        extern origin_t origin_r5_t5;
        extern origin_t origin_r5_t6;
        extern origin_t origin_r5_t7;
        extern origin_t origin_r5_t8;
        
    } // namespace rank_5
    
    namespace rank_6 {

        extern origin_t origin_r6_t0;
        extern origin_t origin_r6_t1;
        extern origin_t origin_r6_t2;
        extern origin_t origin_r6_t3;
        extern origin_t origin_r6_t4;
        extern origin_t origin_r6_t5;
        extern origin_t origin_r6_t6;
        extern origin_t origin_r6_t7;
        extern origin_t origin_r6_t8;
        
    } // namespace rank_6
    
    namespace rank_7 {

        extern origin_t origin_r7_t0;
        extern origin_t origin_r7_t1;
        extern origin_t origin_r7_t2;
        extern origin_t origin_r7_t3;
        extern origin_t origin_r7_t4;
        extern origin_t origin_r7_t5;
        extern origin_t origin_r7_t6;
        extern origin_t origin_r7_t7;
        extern origin_t origin_r7_t8;
        
    } // namespace rank_7
    
    namespace rank_8 {

        extern origin_t origin_r8_t0;
        extern origin_t origin_r8_t1;
        extern origin_t origin_r8_t2;
        extern origin_t origin_r8_t3;
        extern origin_t origin_r8_t4;
        extern origin_t origin_r8_t5;
        extern origin_t origin_r8_t6;
        extern origin_t origin_r8_t7;
        extern origin_t origin_r8_t8;
        
    } // namespace rank_8
    
   

} // namespace origin
