#include <iomanip>
#include <stdint.h>
#include <iostream>

#define mem_size (16 * 16)

struct Memory_Block {
    public:
        Memory_Block() = default;        
        ~Memory_Block() = default;        
        
        void print_single(int index);
        void print_full();

        void push(uint8_t data);

        uint16_t cpy_single_byte_to_mem(uint8_t &data);
        uint16_t cpy_many_byte_to_mem(uint8_t* data, uint16_t no_of_bytes);

        uint8_t* get_mem_ptr();


    private:
        uint16_t stack_ptr_m = 0;
        uint8_t mem_m[mem_size] = {};

};