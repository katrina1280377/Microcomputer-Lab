################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
..\src/cg_src/r_cg_cgc.c \
..\src/cg_src/r_cg_cgc_user.c \
..\src/cg_src/r_cg_dbsct.c \
..\src/cg_src/r_cg_dmac.c \
..\src/cg_src/r_cg_dmac_user.c \
..\src/cg_src/r_cg_hardware_setup.c \
..\src/cg_src/r_cg_intprg.c \
..\src/cg_src/r_cg_main.c \
..\src/cg_src/r_cg_mtu2.c \
..\src/cg_src/r_cg_mtu2_user.c \
..\src/cg_src/r_cg_resetprg.c \
..\src/cg_src/r_cg_s12ad.c \
..\src/cg_src/r_cg_s12ad_user.c \
..\src/cg_src/r_cg_sbrk.c \
..\src/cg_src/r_cg_sci.c \
..\src/cg_src/r_cg_sci_user.c \
..\src/cg_src/r_cg_vecttbl.c 

C_DEPS += \
./src/cg_src/r_cg_cgc.d \
./src/cg_src/r_cg_cgc_user.d \
./src/cg_src/r_cg_dbsct.d \
./src/cg_src/r_cg_dmac.d \
./src/cg_src/r_cg_dmac_user.d \
./src/cg_src/r_cg_hardware_setup.d \
./src/cg_src/r_cg_intprg.d \
./src/cg_src/r_cg_main.d \
./src/cg_src/r_cg_mtu2.d \
./src/cg_src/r_cg_mtu2_user.d \
./src/cg_src/r_cg_resetprg.d \
./src/cg_src/r_cg_s12ad.d \
./src/cg_src/r_cg_s12ad_user.d \
./src/cg_src/r_cg_sbrk.d \
./src/cg_src/r_cg_sci.d \
./src/cg_src/r_cg_sci_user.d \
./src/cg_src/r_cg_vecttbl.d 

OBJS += \
./src/cg_src/r_cg_cgc.obj \
./src/cg_src/r_cg_cgc_user.obj \
./src/cg_src/r_cg_dbsct.obj \
./src/cg_src/r_cg_dmac.obj \
./src/cg_src/r_cg_dmac_user.obj \
./src/cg_src/r_cg_hardware_setup.obj \
./src/cg_src/r_cg_intprg.obj \
./src/cg_src/r_cg_main.obj \
./src/cg_src/r_cg_mtu2.obj \
./src/cg_src/r_cg_mtu2_user.obj \
./src/cg_src/r_cg_resetprg.obj \
./src/cg_src/r_cg_s12ad.obj \
./src/cg_src/r_cg_s12ad_user.obj \
./src/cg_src/r_cg_sbrk.obj \
./src/cg_src/r_cg_sci.obj \
./src/cg_src/r_cg_sci_user.obj \
./src/cg_src/r_cg_vecttbl.obj 


# Each subdirectory must supply rules for building sources it contributes
src/cg_src/%.obj: ../src/cg_src/%.c
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	ccrx  -MM -MP -output=dep="$(@:%.obj=%.d)" -MT="$(@:%.obj=%.obj)" -MT="$(@:%.obj=%.d)" -lang=c99   -include="C:\PROGRA~2\Renesas\RX\2_6_0/include"  -debug -nomessage -isa=rxv2 -optimize=0 -fpu -nologo  -define=__RX=1   "$<"
	ccrx -lang=c99 -output=obj="$(@:%.d=%.obj)"  -include="C:\PROGRA~2\Renesas\RX\2_6_0/include"  -debug -nomessage -isa=rxv2 -optimize=0 -fpu -nologo  -define=__RX=1   "$<"
	@echo 'Finished scanning and building: $<'
	@echo.

