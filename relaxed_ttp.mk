##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=relaxed_ttp
ConfigurationName      :=Debug
WorkspacePath          := "/home/dacuna/.codelite/evolutivos"
ProjectPath            := "/home/dacuna/.codelite/evolutivos/relaxed_ttp"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Diego Acuña
Date                   :=11/29/2012
CodeLitePath           :="/home/dacuna/.codelite"
LinkerName             :=gcc
SharedObjectLinkerName :=gcc -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="/home/dacuna/.codelite/evolutivos/relaxed_ttp/relaxed_ttp.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -lm $(shell pkg-config --libs glib-2.0)
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := gcc
CC       := gcc
CXXFLAGS :=  -g $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(shell pkg-config --cflags glib-2.0) $(Preprocessors)


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects=$(IntermediateDirectory)/main$(ObjectSuffix) $(IntermediateDirectory)/read_instance$(ObjectSuffix) $(IntermediateDirectory)/create_solutions$(ObjectSuffix) $(IntermediateDirectory)/operators$(ObjectSuffix) $(IntermediateDirectory)/selection$(ObjectSuffix) $(IntermediateDirectory)/evaluate$(ObjectSuffix) $(IntermediateDirectory)/elitism$(ObjectSuffix) $(IntermediateDirectory)/gengetopt_read_parameters$(ObjectSuffix) $(IntermediateDirectory)/utils$(ObjectSuffix) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects) > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main$(ObjectSuffix): main.c $(IntermediateDirectory)/main$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/dacuna/.codelite/evolutivos/relaxed_ttp/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main$(ObjectSuffix) -MF$(IntermediateDirectory)/main$(DependSuffix) -MM "/home/dacuna/.codelite/evolutivos/relaxed_ttp/main.c"

$(IntermediateDirectory)/main$(PreprocessSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main$(PreprocessSuffix) "/home/dacuna/.codelite/evolutivos/relaxed_ttp/main.c"

$(IntermediateDirectory)/read_instance$(ObjectSuffix): read_instance.c $(IntermediateDirectory)/read_instance$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/dacuna/.codelite/evolutivos/relaxed_ttp/read_instance.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/read_instance$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/read_instance$(DependSuffix): read_instance.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/read_instance$(ObjectSuffix) -MF$(IntermediateDirectory)/read_instance$(DependSuffix) -MM "/home/dacuna/.codelite/evolutivos/relaxed_ttp/read_instance.c"

$(IntermediateDirectory)/read_instance$(PreprocessSuffix): read_instance.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/read_instance$(PreprocessSuffix) "/home/dacuna/.codelite/evolutivos/relaxed_ttp/read_instance.c"

$(IntermediateDirectory)/create_solutions$(ObjectSuffix): create_solutions.c $(IntermediateDirectory)/create_solutions$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/dacuna/.codelite/evolutivos/relaxed_ttp/create_solutions.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/create_solutions$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/create_solutions$(DependSuffix): create_solutions.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/create_solutions$(ObjectSuffix) -MF$(IntermediateDirectory)/create_solutions$(DependSuffix) -MM "/home/dacuna/.codelite/evolutivos/relaxed_ttp/create_solutions.c"

$(IntermediateDirectory)/create_solutions$(PreprocessSuffix): create_solutions.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/create_solutions$(PreprocessSuffix) "/home/dacuna/.codelite/evolutivos/relaxed_ttp/create_solutions.c"

$(IntermediateDirectory)/operators$(ObjectSuffix): operators.c $(IntermediateDirectory)/operators$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/dacuna/.codelite/evolutivos/relaxed_ttp/operators.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/operators$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/operators$(DependSuffix): operators.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/operators$(ObjectSuffix) -MF$(IntermediateDirectory)/operators$(DependSuffix) -MM "/home/dacuna/.codelite/evolutivos/relaxed_ttp/operators.c"

$(IntermediateDirectory)/operators$(PreprocessSuffix): operators.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/operators$(PreprocessSuffix) "/home/dacuna/.codelite/evolutivos/relaxed_ttp/operators.c"

$(IntermediateDirectory)/selection$(ObjectSuffix): selection.c $(IntermediateDirectory)/selection$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/dacuna/.codelite/evolutivos/relaxed_ttp/selection.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/selection$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/selection$(DependSuffix): selection.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/selection$(ObjectSuffix) -MF$(IntermediateDirectory)/selection$(DependSuffix) -MM "/home/dacuna/.codelite/evolutivos/relaxed_ttp/selection.c"

$(IntermediateDirectory)/selection$(PreprocessSuffix): selection.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/selection$(PreprocessSuffix) "/home/dacuna/.codelite/evolutivos/relaxed_ttp/selection.c"

$(IntermediateDirectory)/evaluate$(ObjectSuffix): evaluate.c $(IntermediateDirectory)/evaluate$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/dacuna/.codelite/evolutivos/relaxed_ttp/evaluate.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/evaluate$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/evaluate$(DependSuffix): evaluate.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/evaluate$(ObjectSuffix) -MF$(IntermediateDirectory)/evaluate$(DependSuffix) -MM "/home/dacuna/.codelite/evolutivos/relaxed_ttp/evaluate.c"

$(IntermediateDirectory)/evaluate$(PreprocessSuffix): evaluate.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/evaluate$(PreprocessSuffix) "/home/dacuna/.codelite/evolutivos/relaxed_ttp/evaluate.c"

$(IntermediateDirectory)/elitism$(ObjectSuffix): elitism.c $(IntermediateDirectory)/elitism$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/dacuna/.codelite/evolutivos/relaxed_ttp/elitism.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/elitism$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/elitism$(DependSuffix): elitism.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/elitism$(ObjectSuffix) -MF$(IntermediateDirectory)/elitism$(DependSuffix) -MM "/home/dacuna/.codelite/evolutivos/relaxed_ttp/elitism.c"

$(IntermediateDirectory)/elitism$(PreprocessSuffix): elitism.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/elitism$(PreprocessSuffix) "/home/dacuna/.codelite/evolutivos/relaxed_ttp/elitism.c"

$(IntermediateDirectory)/gengetopt_read_parameters$(ObjectSuffix): gengetopt/read_parameters.c $(IntermediateDirectory)/gengetopt_read_parameters$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/dacuna/.codelite/evolutivos/relaxed_ttp/gengetopt/read_parameters.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gengetopt_read_parameters$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gengetopt_read_parameters$(DependSuffix): gengetopt/read_parameters.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gengetopt_read_parameters$(ObjectSuffix) -MF$(IntermediateDirectory)/gengetopt_read_parameters$(DependSuffix) -MM "/home/dacuna/.codelite/evolutivos/relaxed_ttp/gengetopt/read_parameters.c"

$(IntermediateDirectory)/gengetopt_read_parameters$(PreprocessSuffix): gengetopt/read_parameters.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gengetopt_read_parameters$(PreprocessSuffix) "/home/dacuna/.codelite/evolutivos/relaxed_ttp/gengetopt/read_parameters.c"

$(IntermediateDirectory)/utils$(ObjectSuffix): utils.c $(IntermediateDirectory)/utils$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/dacuna/.codelite/evolutivos/relaxed_ttp/utils.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/utils$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/utils$(DependSuffix): utils.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/utils$(ObjectSuffix) -MF$(IntermediateDirectory)/utils$(DependSuffix) -MM "/home/dacuna/.codelite/evolutivos/relaxed_ttp/utils.c"

$(IntermediateDirectory)/utils$(PreprocessSuffix): utils.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/utils$(PreprocessSuffix) "/home/dacuna/.codelite/evolutivos/relaxed_ttp/utils.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/main$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/main$(DependSuffix)
	$(RM) $(IntermediateDirectory)/main$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/read_instance$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/read_instance$(DependSuffix)
	$(RM) $(IntermediateDirectory)/read_instance$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/create_solutions$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/create_solutions$(DependSuffix)
	$(RM) $(IntermediateDirectory)/create_solutions$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/operators$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/operators$(DependSuffix)
	$(RM) $(IntermediateDirectory)/operators$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/selection$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/selection$(DependSuffix)
	$(RM) $(IntermediateDirectory)/selection$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/evaluate$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/evaluate$(DependSuffix)
	$(RM) $(IntermediateDirectory)/evaluate$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/elitism$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/elitism$(DependSuffix)
	$(RM) $(IntermediateDirectory)/elitism$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/gengetopt_read_parameters$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/gengetopt_read_parameters$(DependSuffix)
	$(RM) $(IntermediateDirectory)/gengetopt_read_parameters$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/utils$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/utils$(DependSuffix)
	$(RM) $(IntermediateDirectory)/utils$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) "/home/dacuna/.codelite/evolutivos/.build-debug/relaxed_ttp"


