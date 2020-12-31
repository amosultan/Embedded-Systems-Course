#A basic makefile to automate and organize the build.
#Supports rebuilding if header files were changed.
#Still needs more improvments.
#Author: Abdelrahman Sultan

CC := arm-none-eabi-
CFLAGS := -g -gdwarf-2 -mcpu=cortex-m4

INCDIR := Inc
SRCDIR := Src
ASMDIR := Startup
OBJDIR := Debug

ASM := $(wildcard $(ASMDIR)/*.c)
ASMOBJ := $(notdir $(patsubst %.c, %.o, $(ASM)))
SRCS := $(wildcard $(SRCDIR)/*.c)
OBJS := $(addprefix $(OBJDIR)/, $(notdir $(patsubst %.c, %.o, $(SRCS))))
INCS := -I $(INCDIR)
LINKER := $(wildcard *.ld)
Project_name := LED_Toggeling_Cortex_m4


build: $(OBJDIR)/$(Project_name).bin
	@echo "********** Build is done :) **********"

$(OBJDIR)/$(Project_name).bin: $(OBJDIR)/$(Project_name).elf | $(OBJDIR)
	$(CC)objcopy.exe -O binary $< $@

$(OBJDIR)/$(Project_name).elf: $(LINKER) $(ASMOBJ) $(OBJS) | $(OBJDIR)
	$(CC)ld.exe -T $^ -o $@ -Map=$(OBJDIR)/map_file.map
	cp $(OBJDIR)/$(Project_name).elf $(OBJDIR)/$(Project_name).axf

-include $(OBJS:.o=.d)

%.o: $(ASMDIR)/%.c
	$(CC)gcc.exe -c $(CFLAGS) $< -o $@

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