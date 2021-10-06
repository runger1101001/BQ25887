
#ifndef _BQ25887_REGISTERS_H_
#define _BQ25887_REGISTERS_H_

enum BQ25887_REGISTERS {
    REG00_VCELLREG = 0x00,
    REG01_ICHG = 0x01,
    REG02_VINDPM = 0x02,
    REG03_IINDPM = 0x03,
    REG04_IPRECHG_ITERM = 0x04,
    REG05_CHGCTL1 = 0x05,
    REG06_CHGCTL2 = 0x06,
    REG07_CHGCTL3 = 0x07,
    REG08_CHGCTL4 = 0x08,
    REG0A_ICO_ILIM = 0x0A,
    REG0B_STATUS1 = 0x0B,
    REG0C_STATUS2 = 0x0C,
    REG0D_NTC_STATUS = 0x0D,
    REG0E_FAULT_STATUS = 0x0E,
    REG0F_CHG_FLAG1 = 0x0F,
    REG10_CHG_FLAG2 = 0x10,
    REG11_FAULT_FLAG = 0x11,
    REG12_CHG_MASK1 = 0x12,
    REG13_CHG_MASK2 = 0x13,
    REG14_FAULT_MASK = 0x14,
    REG15_ADC_CTL = 0x15,
    REG16_ADC_DISABLE = 0x16,
    REG17_IBUS_ADC1 = 0x17,
    REG18_IBUS_ADC0 = 0x18,
    REG19_ICHG_ADC1 = 0x19,
    REG1A_ICHG_ADC0 = 0x1A,
    REG1B_VBUS_ADC1 = 0x1B,
    REG1C_VBUS_ADC0 = 0x1C,
    REG1D_VBAT_ADC1 = 0x1D,
    REG1E_VBAT_ADC0 = 0x1E,
    REG1F_VCELLTOP_ADC1 = 0x1F,
    REG20_VCELLTOP_ADC0 = 0x20,
    REG21_TS_ADC1 = 0x21,
    REG22_TS_ADC0 = 0x22,
    REG23_TDIE_ADC1 = 0x23,
    REG24_TDIE_ADC0 = 0x24,
    REG25_PARTINFO = 0x25,
    REG26_VCELLBOT_ADC1 = 0x26,
    REG27_VCELLBOT_ADC0 = 0x27,
    REG28_BAL_CTL1 = 0x28,
    REG29_BAL_CTL2 = 0x29,
    REG2A_BAL_STATUS = 0x2A,
    REG2B_BAL_FLAG = 0x2B,
    REG2C_BAL_MASK = 0x2C
};





typedef union {
    struct {
        uint8_t EN_HIZ:1;
        uint8_t EN_ILIM:1;
        uint8_t ICHG:6;
    };
    uint8_t reg;
} REG01_ICHG_TYPE;




typedef union {
    struct {
        uint8_t EN_VINDPM_RST:1;
        uint8_t EN_BAT_DISCHG:1;
        uint8_t PFM_OOA_DIS:1;
        uint8_t VINDPM:5;
    };
    uint8_t reg;
} REG02_VINDPM_TYPE;





typedef union {
    struct {
        uint8_t FORCE_ICO:1;
        uint8_t FORCE_INDET:1;
        uint8_t EN_ICO:1;
        uint8_t IINDPM:5;
    };
    uint8_t reg;
} REG03_IINDPM_TYPE;




typedef union {
    struct {
        uint8_t IPRECHG:4;
        uint8_t ITERM:4;
    };
    uint8_t reg;
} REG04_IPRECHG_ITERM_TYPE;






typedef union {
    struct {
        uint8_t EN_TERM:1;
        uint8_t STAT_DIS:1;
        uint8_t WATCHDOG:2;
        uint8_t EN_TIMER:1;
        uint8_t CHG_TIMER:2;
        uint8_t TMR2X_EN:1;
    };
    uint8_t reg;
} REG05_CHGCTL1_TYPE;




typedef union {
    struct {
        uint8_t reserved:1;
        uint8_t AUTO_INDET_EN:1;
        uint8_t TREG:2;
        uint8_t EN_CHG:1;
        uint8_t CELLLOWV:1;
        uint8_t VCELL_RECHG:2;
    };
    uint8_t reg;
} REG06_CHGCTL2_TYPE;






typedef union {
    struct {
        uint8_t PFM_DIS:1;
        uint8_t WD_RST:1;
        uint8_t TOPOFF_TIMER:2;
        uint8_t reserved:4;
    };
    uint8_t reg;
} REG07_CHGCTL3_TYPE;






typedef union {
    struct {
        uint8_t reserved:3;
        uint8_t JEITA_VSET:2;
        uint8_t JEITA_ISETH:1;
        uint8_t JEITA_ISETC:2;
    };
    uint8_t reg;
} REG08_CHGCTL4_TYPE;






typedef union {
    struct {
        uint8_t reserved:1;
        uint8_t IINDPM_STAT:1;
        uint8_t VINDPM_STAT:1;
        uint8_t TREG_STAT:1;
        uint8_t WD_STAT:1;
        uint8_t CHRG_STAT:3;
    };
    uint8_t reg;
} REG0B_STATUS1_TYPE;





typedef union {
    struct {
        uint8_t PG_STAT:1;
        uint8_t VBUS_STAT:3;
        uint8_t reserved2:1;
        uint8_t ICO_STAT:2;
        uint8_t reserved:1;
    };
    uint8_t reg;
} REG0C_STATUS2_TYPE;






enum NTC_STATUS_VALUE {
    Normal =0x00,
    TS_Warm = 0x02,
    TS_Cool = 0x03,
    TS_Cold = 0x05,
    TS_Hot = 0x06
};



typedef union {
    struct {
        uint8_t VBUS_OVP_STAT:1;
        uint8_t TSHUT_STAT:1;
        uint8_t reserved2:1;
        uint8_t TMR_STAT:1;
        uint8_t reserved:4;
    };
    uint8_t reg;
} REG0E_FAULT_STATUS_TYPE;








typedef union {
    struct {
        uint8_t reserved2:1;
        uint8_t IINDPM_FLAG:1;
        uint8_t VINDPM_FLAG:1;
        uint8_t TREG_FLAG:1;
        uint8_t WD_FLAG:1;
        uint8_t reserved:2;
        uint8_t CHRG_FLAG:1;
    };
    uint8_t reg;
} REG0F_CHG_FLAG1_TYPE;






typedef union {
    struct {
        uint8_t PG_FLAG:1;
        uint8_t reserved3:2;
        uint8_t VBUS_FLAG:1;
        uint8_t reserved2:1;
        uint8_t TS_FLAG:1;
        uint8_t ICO_FLAG:1;
        uint8_t reserved:1;
    };
    uint8_t reg;
} REG10_CHG_FLAG2_TYPE;





typedef union {
    struct {
        uint8_t VBUS_OVP_FLAG:1;
        uint8_t TSHUT_FLAG:1;
        uint8_t reserved2:1;
        uint8_t TMR_FLAG:1;
        uint8_t reserved:4;
    };
    uint8_t reg;
} REG11_FAULT_FLAG_TYPE;






typedef union {
    struct {
        uint8_t ADC_DONE_MASK:1;
        uint8_t IINDPM_MASK:1;
        uint8_t VINDPM_MASK:1;
        uint8_t TREG_MASK:1;
        uint8_t WD_MASK:1;
        uint8_t reserved:2;
        uint8_t CHRG_MASK:1;
    };
    uint8_t reg;
} REG12_CHG_MASK1_TYPE;






typedef union {
    struct {
        uint8_t PG_MASK:1;
        uint8_t reserved3:2;
        uint8_t VBUS_MASK:1;
        uint8_t reserved2:1;
        uint8_t TS_MASK:1;
        uint8_t ICO_MASK:1;
        uint8_t reserved:1;
    };
    uint8_t reg;
} REG13_CHG_MASK2_TYPE;







typedef union {
    struct {
        uint8_t VBUS_OVP_MASK:1;
        uint8_t TSHUT_MASK:1;
        uint8_t reserved2:1;
        uint8_t TMR_MASK:1;
        uint8_t SNS_SHORT_MASK:1;
        uint8_t reserved:3;
    };
    uint8_t reg;
} REG14_FAULT_MASK_TYPE;





typedef union {
    struct {
        uint8_t ADC_EN:1;
        uint8_t ADC_RATE:1;
        uint8_t ADC_SAMPLE:2;
        uint8_t reserved:4;
    };
    uint8_t reg;
} REG15_ADC_CTL_TYPE;







enum ADC_DISABLE_VALUES {
    IBUS_ADC_DIS = 0x80,
    ICHG_ADC_DIS = 0x40,
    VBUS_ADC_DIS = 0x20,
    VBAT_ADC_DIS = 0x10,
    TS_ADC_DIS = 0x04,
    VCELL_ADC_DIS = 0x02,
    TDIE_ADC_DIS = 0x01
};



typedef union {
    struct {
        uint8_t IBUS_ADC_DIS:1;
        uint8_t ICHG_ADC_DIS:1;
        uint8_t VBUS_ADC_DIS:1;
        uint8_t VBAT_ADC_DIS:1;
        uint8_t reserved:1;
        uint8_t TS_ADC_DIS:1;
        uint8_t VCELL_ADC_DIS:1;
        uint8_t TDIE_ADC_DIS:1;
    };
    uint8_t reg;
} REG16_ADC_DISABLE_TYPE;






typedef union {
    struct {
        uint8_t VDIFF_END_OFFSET:3;
        uint8_t TCB_QUAL_INTERVAL:1;
        uint8_t TCB_ACTIVE:2;
        uint8_t TSETTLE:2;
    };
    uint8_t reg;
} REG28_BAL_CTL1_TYPE;




enum BAL_STATUS_VALUES {
    CB_CHG_DIS = 0x80,
    CB_AUTO_EN = 0x40,
    CB_STAT = 0x20,
    HS_CV_STAT = 0x10,
    LS_CV_STAT = 0x08,
    HS_OV_STAT = 0x04,
    LS_OV_STAT = 0x02,
    CB_OC_STAT = 0x01
};



typedef union {
    struct {
        uint8_t CB_CHG_DIS:1;
        uint8_t CB_AUTO_EN:1;
        uint8_t CB_STAT:1;
        uint8_t HS_CV_STAT:1;
        uint8_t LS_CV_STAT:1;
        uint8_t HS_OV_STAT:1;
        uint8_t LS_OV_STAT:1;
        uint8_t CB_OC_STAT:1;
    };
    uint8_t reg;
} REG2A_BAL_STATUS_TYPE;




enum BAL_MASK_FLAG_VALUES {
    QCBH_EN = 0x80,
    QCBL_EN = 0x40,
    CB = 0x20,
    HS_CV = 0x10,
    LS_CV = 0x08,
    HS_OV = 0x04,
    LS_OV = 0x02,
    CB_OC = 0x01
};



typedef union {
    struct {
        uint8_t QCBH_EN:1;
        uint8_t QCBL_EN:1;
        uint8_t CB:1;
        uint8_t HS_CV:1;
        uint8_t LS_CV:1;
        uint8_t HS_OV:1;
        uint8_t LS_OV:1;
        uint8_t CB_OC:1;
    };
    uint8_t reg;
} REG2B_BAL_FLAG_TYPE;



typedef union {
    struct {
        uint8_t reserved:2;
        uint8_t CB:1;
        uint8_t HS_CV:1;
        uint8_t LS_CV:1;
        uint8_t HS_OV:1;
        uint8_t LS_OV:1;
        uint8_t CB_OC:1;
    };
    uint8_t reg;
} REG2C_BAL_MASK_TYPE;







#endif