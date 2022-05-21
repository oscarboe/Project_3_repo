

SOURCES=RNG.cpp
EXECUTEABLE=exefile
CXXFLAGS=-I.
ARCH?=x86-64

ifeq (${ARCH}, x86-64)
CXX=g++
BUILD_DIR=build/x86-64
endif


ifeq (${ARCH},arm)
CXX=arm-rpizw-g++
BUILD_DIR=build/arm
endif

OBJECTS=$(addprefix $(BUILD_DIR)/,$(SOURCES:.cpp=.o))
DEPS=$(addprefix $(BUILD_DIR)/,$(SOURCES:.cpp=.d))
	
$(EXECUTEABLE): $(DEPS) $(OBJECTS) 
	${CXX} $(CXXFLAGS) -o $@  $(OBJECTS)

$(BUILD_DIR)/%.o:%.cpp
	${CXX} -o $@ -c $< $(CXXFLAGS) 
	
$(BUILD_DIR)/%.d:%.cpp
	$(CXX) -MT $@ -MM $(CXXFLAGS) $<  >$@
	$(CXX) -MT$(@:.d=.o) -MM $(CXXFLAGS) $<  >>$@





	
ifneq ($(MAKECMDGOALS),clean)
-include $(DEPS)
endif

format: $(SOURCES:.cpp=.format)
%.format: %.cpp
	@echo "Formatting file '$<'"...
	@clang-format -i $<
	@echo "" > $@
.PHONY: help
help:
	@echo all: builds main target
	@echo clean: removes files
	@echo help: displays help message
	
.PHONY: clean
clean:
	rm -f $(EXECUTEABLE) $(OBJECTS)
