_Pragma("once");

#include <iomanip>
#include <stdint.h>
#include <iostream>

// #define mem_size (16 * 16)

template <size_t mem_size>
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

// Template implementations must be in header file

template <size_t mem_size>
void Memory_Block<mem_size>::print_single(int index) {
    // Determine bytes per row based on mem_size (aim for ~16 bytes, but adjust if needed)
    constexpr size_t bytes_per_row = (mem_size <= 256) ? 16 : (mem_size <= 4096) ? 32 : 64;
    
    std::cout << "|| 0x" << std::hex << std::setw(4) << std::setfill('0') << index << " ";
    
    for(size_t i = index; i < index + bytes_per_row; i++){
        if(i < mem_size) {
            std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)*(mem_m + i) << " ";
        } else {
            std::cout << "   ";  // padding for missing bytes
        }
    }
    std::cout << "||\n";
}

template <size_t mem_size>
void Memory_Block<mem_size>::print_full() {
    constexpr size_t bytes_per_row = (mem_size <= 256) ? 16 : (mem_size <= 4096) ? 32 : 64;
    
    // Print header with separator
    std::cout << "============================================================\n";
    std::cout << "||        ";
    for(size_t i = 0; i < bytes_per_row; i++) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << i << " ";
    }
    std::cout << "||\n";
    std::cout << "============================================================\n";
    
    // Print all memory rows
    for(size_t i = 0; i < mem_size; i += bytes_per_row)
        print_single(i);
    
    std::cout << "============================================================\n";
}

template <size_t mem_size>
void Memory_Block<mem_size>::push(uint8_t data) {
    *(mem_m + stack_ptr_m++) = data;
}

template <size_t mem_size>
uint16_t Memory_Block<mem_size>::cpy_single_byte_to_mem(uint8_t &data) {
    if(stack_ptr_m > mem_size) return 0;
    push(data);
    return stack_ptr_m -1;
}

template <size_t mem_size>
uint16_t Memory_Block<mem_size>::cpy_many_byte_to_mem(uint8_t* data, uint16_t no_of_bytes){
    if( stack_ptr_m + no_of_bytes -1 >= mem_size) return 0;

    for(int i = 0; i < no_of_bytes; i++ ){
        push(*(data+i));
    }

    return stack_ptr_m - no_of_bytes;
}

template <size_t mem_size>
uint8_t* Memory_Block<mem_size>::get_mem_ptr(){
    return mem_m;
}