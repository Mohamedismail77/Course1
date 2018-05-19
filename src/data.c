
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include "memory.h"
#include "platform.h"


uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
    
    uint8_t i = 0;
    int32_t element = 0;
    int32_t temp_data = data;
    //check if it's signed or not
    if(temp_data < 0){
        temp_data *= -1;
    }
    while((temp_data/10) != 0){
        element = temp_data%10;
        *(ptr+i) = (uint8_t)element + 48;
        i++;
        temp_data = temp_data / 10;
    }
    *(ptr+i) = (uint8_t)temp_data + 48;
    if(data < 0){
        //put negative sign at ptr (first address in ptr)
        i++;
        *(ptr+i) = 45;
    }
    return i;
    
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
    
    int32_t number = 0;
    int32_t num;
    
    for(uint8_t i = 0 ; i <= digits; i++){
        num = *(ptr+i) - 48;
        for(uint8_t j = 0 ; j < i; j++){
            num *= 10; 
        }
        if(num < 0){
            number *= -1;
        } else {
            number += num;
        }
        //PRINTF("%d \n",num);
    }

    return number ;
    
}




