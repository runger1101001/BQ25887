
#ifndef __BQ25887_H__
#define __BQ25887_H__

#include <Arduino.h>
#include <Wire.h>
#include "BQ25887_registers.h"

    
#define BQ25887_I2C_ADDRESS 0x6B


class BQ25887 {
    public:
        BQ25887(TwoWire* wire = &Wire, uint8_t address = BQ25887_I2C_ADDRESS);
        void begin();

        void setBalanceMask(uint8_t mask);
        void setBalanceMask(REG2B_BAL_MASK_TYPE mask);
        REG2B_BAL_MASK_TYPE getBalanceMask();

    private:
        TwoWire* _wire;
        uint8_t _address;
};




#endif