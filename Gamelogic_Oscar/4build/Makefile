ifneq ($(filter-out clean format tidy, $(MAKECMDGOALS)),)

-include $(DEPS)

endif

SRC=main.cpp gameLogic.cpp
CXXFLAGS=-g -Wall -pedantic
#Set the name of output to as var EXECUTABLE
EXE:=main

ARCH?=x86-64

ifeq ($(ARCH),x86-64)
CXX=g++
BUILD_DIR=build/x86-64/
BIN_DIR=bin/x86-64/
endif

ifeq ($(ARCH),arm)
CXX=arm-rpizw-g++
BUILD_DIR=build/arm/
BIN_DIR=bin/arm/
endif

F_SRC=$(SRC:.cpp=.format)
TIDY=$(SRC:.cpp=.tidy)
OBJ=$(addprefix $(BUILD_DIR),$(SRC:.cpp=.o))
DEPS=$(addprefix $(BUILD_DIR),$(SRC:.cpp=.d))

$(BIN_DIR)$(EXE): $(DEPS) $(OBJ) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

$(BUILD_DIR)%.d:%.cpp | $(BUILD_DIR)
	$(CXX) -MT $@ -MM $(CXXFLAGS) $< > $@
	$(CXX) -MT $(@:.d=.o) -MM $(CXXFLAGS) $< >> $@

$(BUILD_DIR)%.o:%.cpp | $(BUILD_DIR)
	$(CXX) -o $@ -c $< $(CCXFLAGS)


$(BUILD_DIR):
	mkdir -p $@

$(BIN_DIR):
	mkdir -p $@

format: $(F_SRC)
%.format: %.cpp
	@echo "Formatting file '$<'"...
	@clang-format -i $<
	@echo "" > $@

tidy: $(SRC:.cpp=.tidy)
%.tidy: %.cpp
	@echo "Tidying file '$<'"....
	@clang-tidy $< -- $(CXXFLAGS)
	@echo "" > $@

./PHONY: clean
clean:
	rm $(OBJ) $(DEPS) $(TIDY) $(F_SRC) $(EXE)

help:
	@echo $(EXE) : Builds main target
	@echo clean : Cleans directory from object files
	@echo help : Displays this message



