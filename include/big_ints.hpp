#pragma once

#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <iostream>

typedef struct {
    static uint8_t* allocate(std::size_t size){
        return static_cast<uint8_t*>(std::malloc(size));
    }
    static void deallocate(uint8_t* ptr) {
        std::free(ptr);
    }
} alloc_c;

typedef struct {
    uint64_t data[16];
} data_1024_t;

typedef struct uint1024 {

    #define total_byte  128

    uint8_t* data;

    uint1024() {
        data = static_cast<uint8_t*>(std::malloc(total_byte));
    }

    void init(const data_1024_t &src) {
        const uint8_t* ptr = reinterpret_cast<const uint8_t*>(src.data);
        std::memcpy(this->data, ptr, total_byte);
    }

    // void print(){
    //     std::cout << std::hex  ;
    //     for(int i = 0; i < total_byte; i++){
    //         if(i % 8 == 0 && i != 1)
    //         std::cout << "\n";
    //         std::cout<< std::setw(2) << std::setfill('0') << (int)*(data + i  )<< " ";
            
    //     }
    // }
    void print(){
        
        for(int i = 1; i <= 16; i++){
            
            std::cout << std::dec << std::setw(2) << std::setfill('0') << i << " : ";

            for(int j = ( i * 8 ) -1; j >= ( i *  8 ) -8 ; j--){
                // int j = (8 * i );    
                // std::cout<< j << " ";
                std::cout 
                    << std::hex
                    << std::setw(2) 
                    << std::setfill('0') 
                    << (int)*(data + j  ) 
                    << " ";
            }
            std::cout << "\n";
        }
        
    }

    ~uint1024() {
        std::free(data);
    }


} uint1024_t;


