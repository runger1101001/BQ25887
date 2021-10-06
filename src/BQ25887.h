
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

        uint16_t getVCellReg(); // mV, 3.40V to 4.60V, step is 5mV

        void setChargeCurrentLimit(REG01_ICHG_TYPE value);
        REG01_ICHG_TYPE getChargeCurrentLimit();

        void setInputVoltageLimit(REG02_VINDPM_TYPE value);
        REG02_VINDPM_TYPE getInputVoltageLimit();

        void setInputCurrentLimit(REG03_IINDPM_TYPE value);
        REG03_IINDPM_TYPE getInputCurrentLimit();
        
        void setPreTermCurrentLimits(REG04_IPRECHG_ITERM_TYPE value); // in mA, range 50-800mA, 50mA steps
        REG04_IPRECHG_ITERM_TYPE getPreTermCurrentLimits();

        void setChargerControl1(REG05_CHGCTL1_TYPE value);
        REG05_CHGCTL1_TYPE getChargerControl1();

        void setChargerControl2(REG06_CHGCTL2_TYPE value);
        REG06_CHGCTL2_TYPE getChargerControl2();

        void setChargerControl3(REG07_CHGCTL3_TYPE value);
        REG07_CHGCTL3_TYPE getChargerControl3();

        void setChargerControl4(REG08_CHGCTL4_TYPE value);
        REG08_CHGCTL4_TYPE getChargerControl4();

        uint16_t getICOCurrentLimit();

        REG0B_STATUS1_TYPE getChargerStatus1();

        REG0C_STATUS2_TYPE getChargerStatus2();

        NTC_STATUS_VALUE getNTCStatus();

        REG0E_FAULT_STATUS_TYPE getFaultStatus();

        REG0F_CHG_FLAG1_TYPE getChargerFlags1();

        REG10_CHG_FLAG2_TYPE getChargerFlags2();

        REG11_FAULT_FLAG_TYPE getFaultFlags();

        void setChargerMask1(REG12_CHG_MASK1_TYPE value);
        REG12_CHG_MASK1_TYPE getChargerMask1();

        void setChargerMask2(REG13_CHG_MASK2_TYPE value);
        REG13_CHG_MASK2_TYPE getChargerMask2();

        void setFaultMask(REG14_FAULT_MASK_TYPE value);
        REG14_FAULT_MASK_TYPE getFaultMask1();

        void setADCControl(REG15_ADC_CTL_TYPE value);
        REG15_ADC_CTL_TYPE getADCControl();

        void setADCFunctions(REG16_ADC_DISABLE_TYPE value);
        REG16_ADC_DISABLE_TYPE getADCFunctions();

        int16_t getIBus(); // mA

        int16_t getICharge(); // mA

        int16_t getVBus(); // mV

        int16_t getVBat(); // mV

        int16_t getVCellTop(); // mV

        float getThermistorTemperature(); // centigrade
        float getDieTemperature(); // centigrade

        uint8_t getChipRevision();
        void registerReset();

        int16_t getVCellBottom(); // mV

        void setBalanceControl1(REG28_BAL_CTL1_TYPE value);
        REG28_BAL_CTL1_TYPE getBalanceControl1();

        void setREG29_VDIFF_START(uint8_t value); // in mV, range 40-190mV, 10mV steps
        void setREG29_VQUAL_TH(uint8_t value); // in mV, range 40-180mV, 10mV steps, 0 = diable pre-qualification
        uint8_t getREG29_VDIFF_START(); // in mV, range 40-190mV, 10mV steps
        uint8_t getREG29_VQUAL_TH(); // in mV, range 40-180mV, 10mV steps, 0 if disabled

        void setBalanceStatus(bool CB_AUTO_EN, bool CB_CHG_DIS);
        REG2A_BAL_STATUS_TYPE getBalanceStatus();

        void setBalanceFlag(REG2B_BAL_FLAG_TYPE flags);
        REG2B_BAL_FLAG_TYPE getBalanceFlag();

        void setBalanceMask(REG2C_BAL_MASK_TYPE mask);
        REG2C_BAL_MASK_TYPE getBalanceMask();

    private:
        TwoWire* _wire;
        uint8_t _address;

        uint8_t readI2C(uint8_t reg);
        void writeI2C(uint8_t reg, uint8_t value);
};




#endif