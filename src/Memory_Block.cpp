#include <Memory_Block.hpp>

void Memory_Block::print_single(int index) {
    std::cout
            << "|| 0x" 
            << std::hex 
            << std::setw(4) 
            << std::setfill('0') 
            << index 
            << " ";
    for(int i = index; i < index + 16; i++){
        std::cout
            << std::hex 
            << std::setw(2) 
            << std::setfill('0')  
            <<(int)*(mem_m+i) << " ";
    }
    std::cout << "||\n";

}
void Memory_Block::print_full() {
    std::cout << "============================================================\n";
    std::cout << "||        00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f ||\n";
    for(int i = 0; i< mem_size; i+=16)
    print_single(i);
    std::cout << "============================================================\n";

}

void Memory_Block::push(uint8_t data) {
    *(mem_m + stack_ptr_m++) = data;
}
uint16_t Memory_Block::cpy_single_byte_to_mem(uint8_t &data) {
    if(stack_ptr_m + 1 > mem_size) return 0;
    push(data);
    return stack_ptr_m -1;
}

uint16_t Memory_Block::cpy_many_byte_to_mem(uint8_t* data, uint16_t no_of_bytes){
    if( stack_ptr_m + no_of_bytes >= mem_size) return 0;

    for(int i = 0; i < no_of_bytes; i++ ){
        push(*(data+i));
    }

    return stack_ptr_m - no_of_bytes;
}


uint8_t* Memory_Block::get_mem_ptr(){
    return mem_m;
}

