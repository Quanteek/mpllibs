# Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2011.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

SOURCE_ROOT = ../../..

INCLUDES += $(SOURCE_ROOT)
BIN_DIR = $(SOURCE_ROOT)/bin/libs/metatest

LIB = $(BIN_DIR)/libmetatest.a

build : $(LIB)

SOURCES += $(wildcard *.cpp)
OBJECTS += $(addprefix $(BIN_DIR)/, $(SOURCES:.cpp=.o))
DEPS += $(OBJECTS:.o=.d)

# We need it for dependency file generation
CXXFLAGS += -MMD
CXXFLAGS += -MP

$(OBJECTS) : $(BIN_DIR)/%.o : %.cpp
	mkdir -p $(BIN_DIR)
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(foreach i,$(INCLUDES), -I$(i) ) -o $@ $<
	sed -i -e '1s,\($*\)\.o[ :]*,\1.o $*.d: ,' $(BIN_DIR)/$*.d

clean : clean_objects clean_deps

clean_objects:
	-rm $(OBJECTS)

clean_deps:
	-rm $(DEPS)

all : clean
	$(MAKE) build

-include $(DEPS)

$(LIB) : $(OBJECTS)
	ar rcs $@ $^

check : ; echo nothing to check

clean :
	-rm $(LIB)

