################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf *.sni *.dbg *.lst *.lis *.lpp *.map *.x *.lbp src/*.src src/*.p src/*.pp src/*.mrc *.bls *.libelf *.lbk *.abs *.fsy

# All of the sources participating in the build are defined here
-include sources.mk
-include src/cg_src/subdir.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_UPPER_DEPS)),)
-include $(CC_UPPER_DEPS)
endif
ifneq ($(strip $(C++_UPPER_DEPS)),)
-include $(C++_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_UPPER_DEPS)),)
-include $(CXX_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_UPPER_DEPS)),)
-include $(CPP_UPPER_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CP_DEPS)),)
-include $(CP_DEPS)
endif
ifneq ($(strip $(SRC_UPPER_DEPS)),)
-include $(SRC_UPPER_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(SRC_DEPS)),)
-include $(SRC_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(CP_UPPER_DEPS)),)
-include $(CP_UPPER_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(OBJ_DEPS)),)
-include $(OBJ_DEPS)
endif
ifneq ($(strip $(ABS_DEPS)),)
-include $(ABS_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(O_DEPS)),)
-include $(O_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

ifneq ($(strip $(SRC_UPPER_SRCS)),)
ALL_ASMS += $(SRC_UPPER_SRCS) 
endif
ifneq ($(strip $(SRC_SRCS)),)
ALL_ASMS += $(SRC_SRCS) 
endif
ifneq ($(strip $(S_UPPER_SRCS)),)
ALL_ASMS += $(S_UPPER_SRCS) 
endif
ifneq ($(strip $(S_SRCS)),)
ALL_ASMS += $(S_SRCS) 
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
CONVERTOR_OUTPUT_OUTPUTS += \
LED_3_5_cmt.mot \

LINKER_OUTPUT_OUTPUTS += \
LED_3_5_cmt.abs \

LIBRARY_GENERATOR_OUTPUTTYPE_OUTPUTS += \
LED_3_5_cmt.lib \

# All Target
all: LED_3_5_cmt.mot
	@echo 'Build complete.'

# Tool invocations
LED_3_5_cmt.mot: $(LINKER_OUTPUT_OUTPUTS)
	@echo 'Invoking: Converter'
	rlink   "C:\Users\katrina\e2_studio\workspace\LED_3_5_cmt\HardwareDebug\LED_3_5_cmt.abs" -form=stype  -output="C:\Users\katrina\e2_studio\workspace\LED_3_5_cmt\HardwareDebug\LED_3_5_cmt.mot" -nomessage
	@echo 'Finished building target:'
	@echo.
	$(MAKE) --no-print-directory post-build

LED_3_5_cmt.abs: $(OBJS) $(LIBRARY_GENERATOR_OUTPUTTYPE_OUTPUTS) $(ALL_ASMS) 
	@echo 'Invoking: Linker'
	@echo 'Building target:'
	rlink  -subcommand="LinkerSubCommand.tmp"  -library="C:\Users\katrina\E2_STU~1\WORKSP~1\LED_3_~1\HARDWA~2\LED_3_5_cmt.lib" -noprelink -list="LED_3_5_cmt.map" -show -nooptimize -debug -output="C:\Users\katrina\e2_studio\workspace\LED_3_5_cmt\HardwareDebug\LED_3_5_cmt.abs" -rom=D=R,D_1=R_1,D_2=R_2 -nocompress -nomessage -nologo
	@echo 'Finished building:'
	@echo.

LED_3_5_cmt.lib:  
	@echo 'Invoking: Standard Library'
	lbgrx -lang=c99 -head=runtime,stdio,stdlib,string,new -isa=rxv2 -fpu -output="LED_3_5_cmt.lib"
	@echo 'Finished building:'
	@echo.

# Other Targets
clean:
ifneq ($(strip $(OBJS)),)
	-$(file > clean_OBJS.tmp , $(OBJS))
	-@ xargs -s 6000 -t -a clean_OBJS.tmp $(RM)
	-@$(RM) clean_OBJS.tmp
endif
ifneq ($(strip $(C_DEPS)),)
	-$(file > clean_C_DEPS.tmp , $(C_DEPS))
	-@ xargs -s 6000 -t -a clean_C_DEPS.tmp $(RM)
	-@$(RM) clean_C_DEPS.tmp
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
	-$(file > clean_C_UPPER_DEPS.tmp , $(C_UPPER_DEPS))
	-@ xargs -s 6000 -t -a clean_C_UPPER_DEPS.tmp $(RM)
	-@$(RM) clean_C_UPPER_DEPS.tmp
endif
ifneq ($(strip $(CPP_DEPS)),)
	-$(file > clean_CPP_DEPS.tmp , $(CPP_DEPS))
	-@ xargs -s 6000 -t -a clean_CPP_DEPS.tmp $(RM)
	-@$(RM) clean_CPP_DEPS.tmp
endif
ifneq ($(strip $(CPP_UPPER_DEPS)),)
	-$(file > clean_CPP_UPPER_DEPS.tmp , $(CPP_UPPER_DEPS))
	-@ xargs -s 6000 -t -a clean_CPP_UPPER_DEPS.tmp $(RM)
	-@$(RM) clean_CPP_UPPER_DEPS.tmp
endif
ifneq ($(strip $(C++_DEPS)),)
	-$(file > clean_C++_DEPS.tmp , $(C++_DEPS))
	-@ xargs -s 6000 -t -a clean_C++_DEPS.tmp $(RM)
	-@$(RM) clean_C++_DEPS.tmp
endif
ifneq ($(strip $(C++_UPPER_DEPS)),)
	-$(file > clean_C++_UPPER_DEPS.tmp , $(C++_UPPER_DEPS))
	-@ xargs -s 6000 -t -a clean_C++_UPPER_DEPS.tmp $(RM)
	-@$(RM) clean_C++_UPPER_DEPS.tmp
endif
ifneq ($(strip $(CP_DEPS)),)
	-$(file > clean_CP_DEPS.tmp , $(CP_DEPS))
	-@ xargs -s 6000 -t -a clean_CP_DEPS.tmp $(RM)
	-@$(RM) clean_CP_DEPS.tmp
endif
ifneq ($(strip $(CP_UPPER_DEPS)),)
	-$(file > clean_CP_UPPER_DEPS.tmp , $(CP_UPPER_DEPS))
	-@ xargs -s 6000 -t -a clean_CP_UPPER_DEPS.tmp $(RM)
	-@$(RM) clean_CP_UPPER_DEPS.tmp
endif
ifneq ($(strip $(CXX_DEPS)),)
	-$(file > clean_CXX_DEPS.tmp , $(CXX_DEPS))
	-@ xargs -s 6000 -t -a clean_CXX_DEPS.tmp $(RM)
	-@$(RM) clean_CXX_DEPS.tmp
endif
ifneq ($(strip $(CXX_UPPER_DEPS)),)
	-$(file > clean_CXX_UPPER_DEPS.tmp , $(CXX_UPPER_DEPS))
	-@ xargs -s 6000 -t -a clean_CXX_UPPER_DEPS.tmp $(RM)
	-@$(RM) clean_CXX_UPPER_DEPS.tmp
endif
ifneq ($(strip $(CC_DEPS)),)
	-$(file > clean_CC_DEPS.tmp , $(CC_DEPS))
	-@ xargs -s 6000 -t -a clean_CC_DEPS.tmp $(RM)
	-@$(RM) clean_CC_DEPS.tmp
endif
ifneq ($(strip $(CC_UPPER_DEPS)),)
	-$(file > clean_CC_UPPER_DEPS.tmp , $(CC_UPPER_DEPS))
	-@ xargs -s 6000 -t -a clean_CC_UPPER_DEPS.tmp $(RM)
	-@$(RM) clean_CC_UPPER_DEPS.tmp
endif
ifneq ($(strip $(ASM_PRNS)),)
	-$(file > clean_ASM_PRNS.tmp , $(ASM_PRNS))
	-@ xargs -s 6000 -t -a clean_ASM_PRNS.tmp $(RM)
	-@$(RM) clean_ASM_PRNS.tmp
endif
ifneq ($(strip $(OBJ_DEPS)),)
	-$(file > clean_OBJ_DEPS.tmp , $(OBJ_DEPS))
	-@ xargs -s 6000 -t -a clean_OBJ_DEPS.tmp $(RM)
	-@$(RM) clean_OBJ_DEPS.tmp
endif
ifneq ($(strip $(ABS_DEPS)),)
	-$(file > clean_ABS_DEPS.tmp , $(ABS_DEPS))
	-@ xargs -s 6000 -t -a clean_ABS_DEPS.tmp $(RM)
	-@$(RM) clean_ABS_DEPS.tmp
endif
ifneq ($(strip $(O_DEPS)),)
	-$(file > clean_O_DEPS.tmp , $(O_DEPS))
	-@ xargs -s 6000 -t -a clean_O_DEPS.tmp $(RM)
	-@$(RM) clean_O_DEPS.tmp
endif
ifneq ($(strip $(S_DEPS)),)
	-$(file > clean_S_DEPS.tmp , $(S_DEPS))
	-@ xargs -s 6000 -t -a clean_S_DEPS.tmp $(RM)
	-@$(RM) clean_S_DEPS.tmp
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
	-$(file > clean_S_UPPER_DEPS.tmp , $(S_UPPER_DEPS))
	-@ xargs -s 6000 -t -a clean_S_UPPER_DEPS.tmp $(RM)
	-@$(RM) clean_S_UPPER_DEPS.tmp
endif
ifneq ($(strip $(SRC_DEPS)),)
	-$(file > clean_SRC_DEPS.tmp , $(SRC_DEPS))
	-@ xargs -s 6000 -t -a clean_SRC_DEPS.tmp $(RM)
	-@$(RM) clean_SRC_DEPS.tmp
endif
ifneq ($(strip $(SRC_UPPER_DEPS)),)
	-$(file > clean_SRC_UPPER_DEPS.tmp , $(SRC_UPPER_DEPS))
	-@ xargs -s 6000 -t -a clean_SRC_UPPER_DEPS.tmp $(RM)
	-@$(RM) clean_SRC_UPPER_DEPS.tmp
endif
ifneq ($(strip $(ASM_DEPS)),)
	-$(file > clean_ASM_DEPS.tmp , $(ASM_DEPS))
	-@ xargs -s 6000 -t -a clean_ASM_DEPS.tmp $(RM)
	-@$(RM) clean_ASM_DEPS.tmp
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
	-$(file > clean_ASM_UPPER_DEPS.tmp , $(ASM_UPPER_DEPS))
	-@ xargs -s 6000 -t -a clean_ASM_UPPER_DEPS.tmp $(RM)
	-@$(RM) clean_ASM_UPPER_DEPS.tmp
endif
	-$(RM) $(LIBRARY_GENERATOR_OUTPUTTYPE_OUTPUTS) $(CONVERTOR_OUTPUT_OUTPUTS) 
	-rm -rf "src/cg_src"/*.obj "src/cg_src"/*.d "src/cg_src"/*.src "src/cg_src"/*.p "src/cg_src"/*.pp "src/cg_src"/*.mrc "src/cg_src"/*.prn "src/cg_src"/*.asm "src/cg_src"/*.lst
	@echo.
	@echo 'Clean complete.'

post-build:
	@echo.
	-C:\Renesas\E2_STU~1\DEBUGC~1\RENESA~1.EXE LED_3_5_cmt.abs LED_3_5_cmt.x 
	@echo.

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
