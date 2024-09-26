arm-none-eabi-as -o add.o add.s 
arm-none-eabi-ld -Ttext=0x0 -o add.elf add.o
arm-none-eabi-nm -n add.elf
arm-none-eabi-objcopy -O binary add.elf add.bin
