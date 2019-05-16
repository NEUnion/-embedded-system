// arm2131 projec main function
#define vWriteReg(addr, val)            (*((volatile unsigned long *)(addr)) = (val))
#define dReadReg(addr)                  (*((volatile unsigned long *)(addr)))
#define vWriteRegMask(addr, mask, val)  vWriteReg(addr, dReadReg(addr) & (~(mask)) | (val&(mask)))

#define REG_BASE            (0xE0000000)
#define REG_PIN0_SEL        (REG_BASE + 0x2C000)
#define RET_IO0_ST          (REG_BASE + 0x28000)
#define REG_IO0_SET         (REG_BASE + 0x28004)
#define REG_IO0_DIR         (REG_BASE + 0x28008)
#define REG_IO0_CLR         (REG_BASE + 0x2800C)

int main(void)
{
    // P0.0 function select as GPIO
    vWriteRegMask(REG_PIN0_SEL, 0x03, 0x00);
    vWriteReg(REG_IO0_DIR, 1<<0);
    vWriteReg(REG_IO0_CLR, 1<<0);

    while(1);
}

