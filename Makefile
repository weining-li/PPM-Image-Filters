# Output Config
TARGET :=PPM
OBJDIR :=bin/

# Compiler bin
CC 		 :=g++
CFLAGS :=-Wall -Wextra -Weffc++ -pedantic -std=c++11 -g
LFLAGS :=-lm

# Find all possible source files
CPP_SRCS := $(shell find * -type f -name '*.cpp')
HDRS 		 := $(shell find * -type f -name '*.h')
OBJS     := $(filter %.o, $(patsubst %.cpp, $(OBJDIR)%.o, $(CPP_SRCS)))

# Link all built objects
$(TARGET): $(OBJS)
	@mkdir -p $(dir $(TARGET))
	$(CC) $(OBJS) -o $(TARGET) $(LFLAGS)

$(OBJDIR)%.o: %.cpp $(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

run:
	./$(TARGET) input.ppm

which:
	@echo "FOUND C++ SOURCES: ${CPP_SRCS}"
	@echo "FOUND HEADERS: ${HDRS}"
	@echo "TARGET OBJS: ${OBJS}"

clean:
	rm -f $(TARGET)
	rm -rf $(OBJDIR)
