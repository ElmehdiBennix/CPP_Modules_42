
EXE := PmergeMe

################################################################################

CPP := c++ -std=c++98
CPPFLAGS := -Wall -Wextra -Wshadow
# -Werror

HEADER := PmergeMe.hpp

FILES  := main.cpp	\
		  PmergeMe.cpp

OBJ := $(FILES:.cpp=.o)

################################################################################

all: $(EXE)

$(EXE): $(OBJ)
	$(CPP) $(OBJ) -o $(EXE)

%.o: %.cpp $(HEADERS)
	$(CPP) $(CPPFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(EXE)

re: fclean all

################################################################################

.PHONY: clean fclean re
