#include <iostream>
#include <stdint.h>
#include <iomanip>
#include <Memory_Block.hpp>
#include <fstream>
#include <origin.hpp>


int main(void) {

    const size_t mem_size = (81 * 2) + 4;
    Memory_Block<mem_size> mb;

    uint8_t signature[] = { 0x23, 0x65 };

    uint8_t *header = signature;
    uint8_t *footer = signature;

    mb.cpy_many_byte_to_mem(header, sizeof(signature));
    
    // mb.cpy_many_byte_to_mem((uint8_t*)origin::all_ranks, total_ranks);
    // mb.cpy_many_byte_to_mem((uint8_t*)origin::all_types, total_types);
    
    for(int i = 0; i < total_origins; i++){
        origin::origin_t* ori = &origin::all_origin[i];
        mb.cpy_many_byte_to_mem((uint8_t*)ori, 2);
    }
    

    mb.cpy_many_byte_to_mem(footer, sizeof(signature));

    mb.print_full();

    
    std::ofstream fp("bin/origins.core", std::ios::binary);

    fp.write(reinterpret_cast<const char*>(mb.get_mem_ptr()), mem_size);
    

    // uint8_t *file_ptr = (uint8_t*)&b;
    // uint8_t *file_ptr2 = (uint8_t*)&b2;
    // uint8_t *file_ptr3 = (uint8_t*)&b3;

    // uint16_t file  = mb.cpy_many_byte_to_mem(file_ptr, sizeof(origin));
    // uint16_t file2 = mb.cpy_many_byte_to_mem(file_ptr2, sizeof(origin));
    // uint16_t file3 = mb.cpy_many_byte_to_mem(file_ptr3, sizeof(origin));

    // std::cout << "file: " << file << "\n";
    // std::cout << "file2: " << file2 << "\n";
    // std::cout << "file3: " << file3 << "\n";

    
    // origin* temp =(origin*)(mb.get_mem_ptr() + file);
    // origin* temp2 =(origin*)(mb.get_mem_ptr() + file2);
    // origin* temp3 =(origin*)(mb.get_mem_ptr() + file3);

    // std::cout << "temp r: 0x"<< std::hex << (int)temp->_r 
    //           << "\ntemp t: 0x" << (int)temp->_t << "\n";
    // std::cout << "temp2 r: 0x"<< std::hex << (int)temp2->_r 
    //           << "\ntemp2 t: 0x" << (int)temp2->_t << "\n";
    // std::cout << "temp3 r: 0x"<< std::hex << (int)temp3->_r 
    //           << "\ntemp3 t: 0x" << (int)temp3->_t << "\n";


    // std::cout << "================\n";

    // uint8_t* _mem = mb.get_mem_ptr();

    // for(int i = 0; i< 8; i++){
    //     std::cout 
    //         << "0x" 
    //         << std::hex
    //         << (int)*(_mem + i) 
    //         << " "; 
    // }
    // std::cout << "\n";


    // std::cout << "================\n";


    return 0;
}