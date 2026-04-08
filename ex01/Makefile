# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/22 20:14:20 by sklaokli          #+#    #+#              #
#    Updated: 2026/04/09 05:34:11 by sklaokli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #

NAME		:=	serialize

SRC_DIR		:=	src
OBJ_DIR		:=	bin
INC_DIR		:=	include

CLASS		:=	Data \
				Serializer
CLASS		:=	Serializer Data

FILES		:=	main.cpp \
				$(addsuffix .cpp, $(CLASS))

SRC			:=	$(addprefix $(SRC_DIR)/, $(FILES))
OBJ			:=	$(addprefix $(OBJ_DIR)/, $(FILES:%.cpp=%.o))
HEADER		:=	$(addprefix $(INC_DIR)/, $(addsuffix .hpp, $(CLASS)))

CXX			:=	c++
WFLAGS		:=	-Wall -Wextra -Werror
STDFLAGS	:=	-std=c++98 -pedantic
INCLUDE		:=	-I$(INC_DIR)

COMPILE		:=	$(CXX) $(WFLAGS) $(STDFLAGS) $(INCLUDE)

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADER) | $(OBJ_DIR)
	$(COMPILE) -c $< -o $@

$(NAME): $(OBJ)
	$(COMPILE) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re