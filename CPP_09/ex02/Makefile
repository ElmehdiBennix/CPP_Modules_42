
EXE :=

################################################################################

CXX := c++ -std=c++98

CXXFLAGS := -g -Wall -Wextra -Wshadow -fsanitize=address
# -werror

HEADER := .hpp

FILES  := main.cpp	\
		  .cpp

OBJ := $(FILES:.cpp=.o)

################################################################################

all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(EXE)

%.o: %.cpp $(HEADER)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(EXE)

re: fclean all

git : fclean
	sh ../../push.sh

################################################################################

.PHONY: clean fclean re git
