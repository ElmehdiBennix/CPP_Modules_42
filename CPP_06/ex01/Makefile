
EXE := Serialization

CPP := c++ -std=c++98
CPPFLAGS := -Wall -Wextra -Werror -Wshadow

HEADERS := Serializer.hpp
FILES := main.cpp Serializer.cpp

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
