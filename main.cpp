#include <iostream>
#include <stdint.h>
#include <iomanip>

struct Memory_Block {
    private:
        #define mem_size (16 * 16)
        uint16_t stack_ptr = 0;
        uint8_t mem[mem_size] = {};
    public:
        Memory_Block() = default;        
        ~Memory_Block() = default;        
        void print_single(int index) {
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
                    <<(int)*(mem+i) << " ";
            }
            std::cout << "||\n";

        }
        void print_full() {
            std::cout << "============================================================\n";
            std::cout << "||        00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f ||\n";
            for(int i = 0; i< mem_size; i+=16)
            print_single(i);
            std::cout << "============================================================\n";
    
        }

        void push(uint8_t data) {
            *(mem + stack_ptr++) = data;
        }
        uint16_t cpy_to_mem(uint8_t &data) {
            push(data);
            return stack_ptr;
        }

        uint8_t* get_mem_ptr(){
            return mem;
        }

};


struct blk {
    uint8_t _r;
    uint8_t _t;
};

int main(void) {

    std::cout << "Start\n\n";
    
    Memory_Block mb;
    
    mb.print_full();
    
    uint8_t data = 0x23;
    uint16_t file = mb.cpy_to_mem(data);

    mb.print_full();


    std::cout << "End\n\n";

    return 0;
}