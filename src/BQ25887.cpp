
#include "BQ25887.h"




BQ25887::BQ25887(TwoWire* wire, uint8_t address) : _wire(wire), _address(address) {

};



// TODO add interrupt handler code to handle nINT line
// TODO add getStatus()
// TODO add watchdog timer pings
// TODO add some callbacks, e.g. onChargeCompleted() onChargeStarted() onChargeError() onVBusDisconnected() onVBusConnected()


void BQ25887::begin() {
    _wire->begin();
};



uint8_t BQ25887::readI2C(uint8_t reg) {
    _wire->beginTransmission(_address);
    _wire->write(reg);
    _wire->endTransmission(false);
    _wire->requestFrom(_address, (uint8_t)1);
    int result = _wire->read();
    return result & 0xFF;
};




void BQ25887::writeI2C(uint8_t reg, uint8_t value){
    _wire->beginTransmission(_address);
    _wire->write(reg);
    _wire->write(value);
    _wire->endTransmission();
};




// mV, 3.40V to 4.60V, step is 5mV
uint16_t BQ25887::getVCellReg(){
    uint16_t result = readI2C(BQ25887_REGISTERS::REG00_VCELLREG);
    return result * 5.0f;
};

void BQ25887::setChargeCurrentLimit(REG01_ICHG_TYPE value){
    writeI2C(BQ25887_REGISTERS::REG01_ICHG, value.reg);
};
REG01_ICHG_TYPE BQ25887::getChargeCurrentLimit(){
    REG01_ICHG_TYPE result;
    result.reg = readI2C(BQ25887_REGISTERS::REG01_ICHG);
    return result;
};

void BQ25887::setInputVoltageLimit(REG02_VINDPM_TYPE value){
    writeI2C(BQ25887_REGISTERS::REG02_VINDPM, value.reg);
};
REG02_VINDPM_TYPE BQ25887::getInputVoltageLimit(){
    REG02_VINDPM_TYPE result;
    result.reg = readI2C(BQ25887_REGISTERS::REG02_VINDPM);
    return result;
};

void BQ25887::setInputCurrentLimit(REG03_IINDPM_TYPE value){
    writeI2C(BQ25887_REGISTERS::REG03_IINDPM, value.reg);
};
REG03_IINDPM_TYPE BQ25887::getInputCurrentLimit(){
    REG03_IINDPM_TYPE result;
    result.reg = readI2C(BQ25887_REGISTERS::REG03_IINDPM);
    return result;
};

// in mA, range 50-800mA, 50mA steps
void BQ25887::setPreTermCurrentLimits(REG04_IPRECHG_ITERM_TYPE value){
    writeI2C(BQ25887_REGISTERS::REG04_IPRECHG_ITERM, value.reg);
};
REG04_IPRECHG_ITERM_TYPE BQ25887::getPreTermCurrentLimits(){
    REG04_IPRECHG_ITERM_TYPE result;
    result.reg = readI2C(BQ25887_REGISTERS::REG04_IPRECHG_ITERM);
    return result;
};

void BQ25887::setChargerControl1(REG05_CHGCTL1_TYPE value){
    writeI2C(BQ25887_REGISTERS::REG05_CHGCTL1, value.reg);
};
REG05_CHGCTL1_TYPE BQ25887::getChargerControl1(){
    REG05_CHGCTL1_TYPE result;
    result.reg = readI2C(BQ25887_REGISTERS::REG05_CHGCTL1);
    return result;
};

void BQ25887::setChargerControl2(REG06_CHGCTL2_TYPE value){
    writeI2C(BQ25887_REGISTERS::REG06_CHGCTL2, value.reg);
};
REG06_CHGCTL2_TYPE BQ25887::getChargerControl2(){
    REG06_CHGCTL2_TYPE result;
    result.reg = readI2C(BQ25887_REGISTERS::REG06_CHGCTL2);
    return result;
};


void BQ25887::resetWatchdog(){
    REG07_CHGCTL3_TYPE curr;
    curr.reg = readI2C(BQ25887_REGISTERS::REG07_CHGCTL3);
    curr.WD_RST = 1;
    writeI2C(BQ25887_REGISTERS::REG07_CHGCTL3, curr.reg);
};
void BQ25887::setChargerControl3(REG07_CHGCTL3_TYPE value){
    writeI2C(BQ25887_REGISTERS::REG07_CHGCTL3, value.reg);
};
REG07_CHGCTL3_TYPE BQ25887::getChargerControl3(){
    REG07_CHGCTL3_TYPE result;
    result.reg = readI2C(BQ25887_REGISTERS::REG07_CHGCTL3);
    return result;
};

void BQ25887::setChargerControl4(REG08_CHGCTL4_TYPE value){
    writeI2C(BQ25887_REGISTERS::REG08_CHGCTL4, value.reg);
};
REG08_CHGCTL4_TYPE BQ25887::getChargerControl4(){
    REG08_CHGCTL4_TYPE result;
    result.reg = readI2C(BQ25887_REGISTERS::REG08_CHGCTL4);
    return result;
};

uint16_t BQ25887::getICOCurrentLimit(){
    uint16_t result = readI2C(BQ25887_REGISTERS::REG0A_ICO_ILIM);
    return result * 100 + 500;
};

REG0B_STATUS1_TYPE BQ25887::getChargerStatus1(){
    REG0B_STATUS1_TYPE result;
    result.reg = readI2C(BQ25887_REGISTERS::REG0B_STATUS1);
    return result;
};

REG0C_STATUS2_TYPE BQ25887::getChargerStatus2(){
    REG0C_STATUS2_TYPE result;
    result.reg = readI2C(BQ25887_REGISTERS::REG0C_STATUS2);
    return result;
};

NTC_STATUS_VALUE BQ25887::getNTCStatus(){
    NTC_STATUS_VALUE result = (NTC_STATUS_VALUE)readI2C(BQ25887_REGISTERS::REG0D_NTC_STATUS);
    return result;
};

REG0E_FAULT_STATUS_TYPE BQ25887::getFaultStatus(){
    REG0E_FAULT_STATUS_TYPE result;
    result.reg = readI2C(BQ25887_REGISTERS::REG0E_FAULT_STATUS);
    return result;
};

REG0F_CHG_FLAG1_TYPE BQ25887::getChargerFlags1(){
    REG0F_CHG_FLAG1_TYPE result;
    result.reg = readI2C(BQ25887_REGISTERS::REG0F_CHG_FLAG1);
    return result;
};

REG10_CHG_FLAG2_TYPE BQ25887::getChargerFlags2(){
    REG10_CHG_FLAG2_TYPE result;
    result.reg = readI2C(BQ25887_REGISTERS::REG10_CHG_FLAG2);
    return result;
};

REG11_FAULT_FLAG_TYPE BQ25887::getFaultFlags(){
    REG11_FAULT_FLAG_TYPE result;
    result.reg = readI2C(BQ25887_REGISTERS::REG11_FAULT_FLAG);
    return result;
};

void BQ25887::setChargerMask1(REG12_CHG_MASK1_TYPE value){
    writeI2C(BQ25887_REGISTERS::REG12_CHG_MASK1, value.reg);
};
REG12_CHG_MASK1_TYPE BQ25887::getChargerMask1(){
    REG12_CHG_MASK1_TYPE result;
    result.reg = readI2C(BQ25887_REGISTERS::REG12_CHG_MASK1);
    return result;
};

void BQ25887::setChargerMask2(REG13_CHG_MASK2_TYPE value){
    writeI2C(BQ25887_REGISTERS::REG13_CHG_MASK2, value.reg);
};
REG13_CHG_MASK2_TYPE BQ25887::getChargerMask2(){
    REG13_CHG_MASK2_TYPE result;
    result.reg = readI2C(BQ25887_REGISTERS::REG13_CHG_MASK2);
    return result;
};

void BQ25887::setFaultMask(REG14_FAULT_MASK_TYPE value){
    writeI2C(BQ25887_REGISTERS::REG14_FAULT_MASK, value.reg);
};
REG14_FAULT_MASK_TYPE BQ25887::getFaultMask1(){
    REG14_FAULT_MASK_TYPE result;
    result.reg = readI2C(BQ25887_REGISTERS::REG14_FAULT_MASK);
    return result;
};

void BQ25887::setADCControl(REG15_ADC_CTL_TYPE value){
    writeI2C(BQ25887_REGISTERS::REG15_ADC_CTL, value.reg);
};
REG15_ADC_CTL_TYPE BQ25887::getADCControl(){
    REG15_ADC_CTL_TYPE result;
    result.reg = readI2C(BQ25887_REGISTERS::REG15_ADC_CTL);
    return result;
};

void BQ25887::setADCFunctions(REG16_ADC_DISABLE_TYPE value){
    writeI2C(BQ25887_REGISTERS::REG16_ADC_DISABLE, value.reg);
};
REG16_ADC_DISABLE_TYPE BQ25887::getADCFunctions(){
    REG16_ADC_DISABLE_TYPE result;
    result.reg = readI2C(BQ25887_REGISTERS::REG16_ADC_DISABLE);
    return result;
};

int16_t BQ25887::getIBus(){
    int16_t result = readI2C(BQ25887_REGISTERS::REG17_IBUS_ADC1)<<8;
    result |= readI2C(BQ25887_REGISTERS::REG18_IBUS_ADC0);
    return result;
};

int16_t BQ25887::getICharge(){
    int16_t result = readI2C(BQ25887_REGISTERS::REG19_ICHG_ADC1)<<8;
    result |= readI2C(BQ25887_REGISTERS::REG1A_ICHG_ADC0);
    return result;
}; // mA

int16_t BQ25887::getVBus(){
    int16_t result = readI2C(BQ25887_REGISTERS::REG1B_VBUS_ADC1)<<8;
    result |= readI2C(BQ25887_REGISTERS::REG1C_VBUS_ADC0);
    return result;
}; // mV

int16_t BQ25887::getVBat(){
    int16_t result = readI2C(BQ25887_REGISTERS::REG1D_VBAT_ADC1)<<8;
    result |= readI2C(BQ25887_REGISTERS::REG1E_VBAT_ADC0);
    return result;
}; // mV

int16_t BQ25887::getVCellTop(){
    int16_t result = readI2C(BQ25887_REGISTERS::REG1F_VCELLTOP_ADC1)<<8;
    result |= readI2C(BQ25887_REGISTERS::REG20_VCELLTOP_ADC0);
    return result;
}; // mV

float BQ25887::getThermistorTemperature(){
    int16_t result = readI2C(BQ25887_REGISTERS::REG21_TS_ADC1)<<8;
    result |= readI2C(BQ25887_REGISTERS::REG22_TS_ADC0);
    float val = 0.0f;
    if (result&0x01) val+= 0.098f;
    if ((result>>1)&0x01) val+= 0.195f;
    if ((result>>2)&0x01) val+= 0.391f;
    if ((result>>3)&0x01) val+= 0.781f;
    if ((result>>4)&0x01) val+= 1.563f;
    if ((result>>5)&0x01) val+= 3.125f;
    if ((result>>6)&0x01) val+= 6.25f;
    if ((result>>7)&0x01) val+= 12.5f;
    if ((result>>8)&0x01) val+= 25.0f;
    if ((result>>9)&0x01) val+= 50.0f;
    return val;
}; // percent of REGN
float BQ25887::getDieTemperature(){
    int16_t result = readI2C(BQ25887_REGISTERS::REG23_TDIE_ADC1)<<8;
    result |= readI2C(BQ25887_REGISTERS::REG24_TDIE_ADC0);
    return result / 2.0f;
}; // centigrade

int16_t BQ25887::getVCellBottom(){
    int16_t result = readI2C(BQ25887_REGISTERS::REG26_VCELLBOT_ADC1)<<8;
    result |= readI2C(BQ25887_REGISTERS::REG27_VCELLBOT_ADC0);
    return result;
}; // mV

void BQ25887::setBalanceControl1(REG28_BAL_CTL1_TYPE value){
    writeI2C(BQ25887_REGISTERS::REG28_BAL_CTL1, value.reg);
};
REG28_BAL_CTL1_TYPE BQ25887::getBalanceControl1(){
    REG28_BAL_CTL1_TYPE result;
    result.reg = readI2C(BQ25887_REGISTERS::REG28_BAL_CTL1);
    return result;
};


void BQ25887::setBalanceStatus(bool CB_AUTO_EN, bool CB_CHG_DIS){
    REG2A_BAL_STATUS_TYPE value;
    value.CB_AUTO_EN = CB_AUTO_EN;
    value.CB_CHG_DIS = CB_CHG_DIS;
    writeI2C(BQ25887_REGISTERS::REG2A_BAL_STATUS, value.reg);
};
REG2A_BAL_STATUS_TYPE BQ25887::getBalanceStatus(){
    REG2A_BAL_STATUS_TYPE result;
    result.reg = readI2C(BQ25887_REGISTERS::REG2A_BAL_STATUS);
    return result;
};

void BQ25887::setBalanceFlag(REG2B_BAL_FLAG_TYPE flags){
    writeI2C(BQ25887_REGISTERS::REG2B_BAL_FLAG, flags.reg);
};
REG2B_BAL_FLAG_TYPE BQ25887::getBalanceFlag(){
    REG2B_BAL_FLAG_TYPE result;
    result.reg = readI2C(BQ25887_REGISTERS::REG2B_BAL_FLAG);
    return result;
};

void BQ25887::setBalanceMask(REG2C_BAL_MASK_TYPE mask){
    writeI2C(BQ25887_REGISTERS::REG2C_BAL_MASK, mask.reg);
};
REG2C_BAL_MASK_TYPE BQ25887::getBalanceMask(){
    REG2C_BAL_MASK_TYPE result;
    result.reg = readI2C(BQ25887_REGISTERS::REG2C_BAL_MASK);
    return result;
};







uint8_t BQ25887::getChipRevision(){
    return readI2C(BQ25887_REGISTERS::REG25_PARTINFO)&0x07;
};

void BQ25887::registerReset(){
    writeI2C(BQ25887_REGISTERS::REG25_PARTINFO, 0x80);
};



// in mV, range 40-190mV, 10mV steps
void BQ25887::setREG29_VDIFF_START(uint8_t value){
    if ((40 <= value) && (value <= 190)) {
        value = (value - 40) / 10;
        // read current register value
        uint8_t curr = readI2C(BQ25887_REGISTERS::REG29_BAL_CTL2);
        value = (curr & 0xF0) | (value & 0x0F);
        writeI2C(BQ25887_REGISTERS::REG29_BAL_CTL2, value);
    }
};


 // in mV, range 40-180mV, 10mV steps, out of range values diable pre-qualification
void BQ25887::setREG29_VQUAL_TH(uint8_t value){
    if ((40 <= value) && (value <= 180))
        value = (value - 40) / 10;
    else
        value = 0x0F;
    uint8_t curr = readI2C(BQ25887_REGISTERS::REG29_BAL_CTL2);
    value = (curr & 0x0F) | ((value<<4) & 0xF0);
    writeI2C(BQ25887_REGISTERS::REG29_BAL_CTL2, value);
};


// in mV, range 40-190mV, 10mV steps
uint8_t BQ25887::getREG29_VDIFF_START() {
    uint8_t curr = readI2C(BQ25887_REGISTERS::REG29_BAL_CTL2);
    return (curr & 0x0F) * 10 + 40;
};

// in mV, range 40-180mV, 10mV steps, 0 if disabled
uint8_t BQ25887::getREG29_VQUAL_TH(){
    uint8_t curr = readI2C(BQ25887_REGISTERS::REG29_BAL_CTL2);
    curr = (curr & 0xF0)>>4;
    if (curr==0x0F)
        return 0;
    else
        return curr * 10 + 40;
};
