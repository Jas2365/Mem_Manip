#include <iostream>
#include <stdint.h>
#include <iomanip>
#include <Memory_Block.hpp>

struct blk {
    uint8_t _r;
    uint8_t _t;
}__attribute__((packed));


int main(void) {

    std::cout << "Start\n\n";
    
    Memory_Block mb;
    
    mb.print_full();
    
    blk b = {0xab, 0xcd};
    
    mb.print_full();
    uint8_t *blk_ptr = (uint8_t*)&b;
    
    uint16_t ptr = mb.cpy_many_byte_to_mem(blk_ptr, sizeof(b));
  
    mb.print_full();
    std::cout 
        << "0x"
        << std::hex 
        << std::setw(2) 
        << std::setfill('0') 
        << static_cast<int>(*(mb.get_mem_ptr() + ptr))
        << "\n";
 
    mb.cpy_many_byte_to_mem(blk_ptr, sizeof(b));
    mb.print_full();
    std::cout << "End\n\n";

    return 0;
}