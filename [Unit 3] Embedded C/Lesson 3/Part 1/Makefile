#A basic makefile to automate and organize the build.
#Supports rebuilding if header files were changed.
#Still needs more improvments.
#Author: Abdelrahman Sultan

CC := arm-none-eabi-
CFLAGS := -gdwarf-2 -mcpu=cortex-m3

INCDIR := Inc
SRCDIR := Src
ASMDIR := Startup
OBJDIR := Debug

ASM := $(wildcard $(ASMDIR)/*.s)
ASMOBJ := $(notdir $(patsubst %.s, %.o, $(ASM)))
SRCS := $(wildcard $(SRCDIR)/*.c)
OBJS := $(addprefix $(OBJDIR)/, $(notdir $(patsubst %.c, %.o, $(SRCS))))
INCS := -I $(INCDIR)
LINKER := $(wildcard *.ld)
Project_name := LED_Toggeling


build: $(OBJDIR)/$(Project_name).bin
	@echo "********** Build is done :) **********"

$(OBJDIR)/$(Project_name).bin: $(OBJDIR)/$(Project_name).elf | $(OBJDIR)
	$(CC)objcopy.exe -O binary $< $@

$(OBJDIR)/$(Project_name).elf: $(LINKER) $(ASMOBJ) $(OBJS) | $(OBJDIR)
	$(CC)ld.exe -T $^ -o $@ -Map=$(OBJDIR)/map_file.map

-include $(OBJS:.o=.d)

#Still need to figure out why the linker doesn't support relative or absolute path with the startup.o file
%.o: $(ASMDIR)/%.s | $(OBJDIR)
	$(CC)as.exe $(CFLAGS) $< -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@
	$(CC)gcc.exe -MM $(CFLAGS) $(INCS) $(SRCDIR)/$*.c > $(OBJDIR)/$*.d
	@mv -f $(OBJDIR)/$*.d $(OBJDIR)/$*.d.tmp
	@sed -e 's|^|$(OBJDIR)/|' < $(OBJDIR)/$*.d.tmp > $(OBJDIR)/$*.d
	@rm -f $(OBJDIR)/$*.d.tmp

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR) *.o

.PHONY: clean build