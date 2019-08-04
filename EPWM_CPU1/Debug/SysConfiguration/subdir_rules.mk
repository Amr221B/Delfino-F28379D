################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
SysConfiguration/%.obj: ../SysConfiguration/%.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs910/ccs/tools/compiler/ti-cgt-c2000_18.12.2.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -O4 --include_path="C:/Users/Sherlock/workspace_v9/Example_CPU1" --include_path="C:/ti/ccs910/ccs/tools/compiler/ti-cgt-c2000_18.12.2.LTS/include" --include_path="C:/Users/Sherlock/workspace_v9/Example_CPU1/F2837xD" --advice:performance=all -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="SysConfiguration/$(basename $(<F)).d_raw" --obj_directory="SysConfiguration" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


