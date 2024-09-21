
EXE := btc

################################################################################

CPP := c++ -std=c++98
CPPFLAGS := -Wall -Wextra -Werror -Wshadow

HEADER := BitcoinExchange.hpp
FILES  := main.cpp	\
		  BitcoinExchange.cpp

OBJ := $(FILES:.cpp=.o)

# PATH := ./cpp_09/data.csv
# CPPFLAGS += -DDATA_FILE=\"$(PATH)\"

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
