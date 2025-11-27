#include <iostream>
#include <stdint.h>
#include <iomanip>
#include <Memory_Block.hpp>

struct blk {
    uint8_t _r;
    uint8_t _t;
};

int main(void) {

    Memory_Block mb;

    blk b = { 0x23, 0x65};
    blk b2 = { 0x23, 0x65};
    blk b3 = { 0x23, 0x65};

    uint8_t *file_ptr = (uint8_t*)&b;
    uint8_t *file_ptr2 = (uint8_t*)&b2;
    uint8_t *file_ptr3 = (uint8_t*)&b3;

    uint16_t file = mb.cpy_many_byte_to_mem(file_ptr, sizeof(blk));
    uint16_t file2 = mb.cpy_many_byte_to_mem(file_ptr2, sizeof(blk));
    uint16_t file3 = mb.cpy_many_byte_to_mem(file_ptr3, sizeof(blk));

    std::cout << "file: " << file << "\n";
    std::cout << "file2: " << file2 << "\n";
    std::cout << "file3: " << file3 << "\n";

    
    blk* temp =(blk*)(mb.get_mem_ptr() + file);
    std::cout << "temp r: 0x"<< std::hex << (int)temp->_r 
              << "\ntemp t: 0x" << (int)temp->_t << "\n";
    blk* temp2 =(blk*)(mb.get_mem_ptr() + file2);
    std::cout << "temp2 r: 0x"<< std::hex << (int)temp2->_r 
              << "\ntemp2 t: 0x" << (int)temp2->_t << "\n";
    blk* temp3 =(blk*)(mb.get_mem_ptr() + file3);
    std::cout << "temp3 r: 0x"<< std::hex << (int)temp3->_r 
              << "\ntemp3 t: 0x" << (int)temp3->_t << "\n";
    // std::cout << "temp : 0x"<< std::hex <<(int)*(mb.get_mem_ptr()+file2) << "\n";
    // std::cout << "temp : 0x"<< std::hex <<(int)*(mb.get_mem_ptr()+file3) << "\n";


    return 0;
}