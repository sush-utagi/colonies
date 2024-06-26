# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -std=c++20
# Raylib libraries
LDFLAGS = -lraylib

# Source and object files
SRCDIR = src
OBJDIR = obj
SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJ = $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# Output executable
TARGET = t1

# Compile and link
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET) $(LDFLAGS)

# Compile source files into object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean the build directory
clean:
	rm -f $(OBJDIR)/*.o $(TARGET)
