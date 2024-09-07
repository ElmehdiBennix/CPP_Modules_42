
EXE := RPN

CPP := c++ -std=c++98

CPPFLAGS := -g -Wall -Wextra -Wshadow -fsanitize=address
# -werror

HEADER := bitcoinExchange.hpp

FILES := main.cpp	bitcoinExchange.cpp

OBJ := $(FILES:.cpp=.o)

################################################################################

all: $(EXE)

$(EXE): $(OBJ)
	$(CPP) $(OBJ) -o $(EXE)

%.o: %.cpp $(HEADER)
	$(CPP) $(CPPFLAGS) -c -o $@ $<ff

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(EXE)

re: fclean all

git : fclean
	sh ../../push.sh

################################################################################

.PHONY: clean fclean re git
