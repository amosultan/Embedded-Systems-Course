# Writing a baremetal software from scratch

In this lesson, a very baisc baremetal software for the uart peripheral of the versatilePB on Qemu emulator will be written, built and tested without any ready made startup or linker script files to send a string to the console.

---

## Dependencies

* [GNU Arm Embedded Toolchain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm)
* [Qemu Emulator](https://www.qemu.org/)

---

## Build Process

* **Compiling the C files without linking and generating the object files:**
```bash
arm-none-eabi-gcc.exe -mcpu=arm926ej-s -c "directory path"/Src/app.c -I "directory path"/Inc/. -o app.o
arm-none-eabi-gcc.exe -mcpu=arm926ej-s -c "directory path"/Src/uart.c -I "directory path"/Inc/. -o uart.o
```
![Compiling the C files](./img/compiling_c_files.png)

* **Compiling the startup file and generating the object file:**
```bash
arm-none-eabi-as.exe -mcpu=arm926ej-s startup.s -o startup.o
```
![Compiling the startup file](./img/compiling_startup_file.png)

* **Linking the the object files and generating the .elf file and the .map file:**

```bash
arm-none-eabi-ld.exe -T linker_script.ld startup.o app.o uart.o -o learn-in-depth.elf -Map=map_file.map
```
![Generating output files](./img/linking_the_object_files.png)

* **Generating the binary file for Qemu:**
```bash
arm-non-eabi-objcopy.exe -O binary learn-in-depth.elf learn-in-depth.bin
```
![Generating the binary file for Qemu](./img/binary_file.png)

---

## Running the binary on Qemu:

Make sure to add the path of the Qemu installation directory to the environment variables or run from the installation path.

```bash
qemu-system-arm -M versatilepb -m 128M -nographic -kernel learn-in-depth.bin
```
![Running the binary on Qemu](./img/qemu_simulation.png)

---

## Analyzing the output files:

* **Chekcing the relocatable memory sections of the C files:**
```bash
arm-none-eabi-objdump.exe -h app.o
arm-none-eabi-objdump.exe -h uart.o
```
![C files relocatable images](./img/c_files_relocatable_images.png)

* **Checking the relocatable memory sections of the startup file:**
```bash
arm-none-eabi-objdump.exe -h startup.o
```
![Startup file relocatable image](./img/startup_relocatable_img.png)

* **Checking the symbol tabel of all object files before linkage:**
```bash
arm-none-eabi-nm.exe app.o
arm-none-eabi-nm.exe uart.o
arm-none-eabi-nm.exe startup.o
```
![Symbol table pre linkage](./img/symbol_table_pre_linkage.png)

* **Checking the locatable memory sections of the final output (.elf) file:**
```bash
arm-none-eabi-objdump.exe -h learn-in-depth.elf
```
![Locatable memory sections](./img/locatable_memory_sections.png)

* **checking the symbol table of the final output (.elf) file:**
```bash
arm-none-eabi-nm.exe learn-in-depth.elf
```
![Symbol table after linkage](./img/output_symbol_table.png)