
EXE := btc

################################################################################

CXX := c++ -std=c++98

CXXFLAGS := -g -Wall -Wextra -Wshadow -fsanitize=address
# -werror

HEADER := BitcoinExchange.hpp

FILES := main.cpp	BitcoinExchange.cpp

OBJ := $(FILES:.cpp=.o)

# PATH := ./cpp_09/data.csv

# CXXFLAGS += -DDATA_FILE=\"$(PATH)\"

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
