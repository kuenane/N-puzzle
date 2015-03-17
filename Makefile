# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/04 09:28:52 by vlehuger          #+#    #+#              #
#    Updated: 2015/03/08 22:14:28 by vlehuger         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = n_puzzle

DIRSRC = ./srcs/
DIROBJ = ./obj/
DIROBJCLASS = ./obj/
DIRCLASS = ./classes/

SRC = utils.cpp\
	  main.cpp

CLASSES = Map.cpp\
		  Node.cpp

OBJ = $(SRC:.cpp=.o)
OBJCLASSES = $(CLASSES:.cpp=.o)

DIROBJS = $(addprefix $(DIROBJ), $(OBJ))
DIRSRCS = $(addprefix $(DIRSRC), $(SRC))
DIRCLASSES = $(addprefix $(DIRCLASS), $(CLASSES))
DIROBJCLASSES = $(addprefix $(DIROBJ), $(OBJCLASSES))

HEADERS = ./headers/
INTERFACES = ./interfaces/
INCLUDES = ./includes/

BREWINC = /nfs/zfs-student-3/users/2013_paris/vlehuger/.brew/Cellar/boost/1.57.0/include/

CFLAGS = -Wall -Werror -Wextra
CLANG = clang++

all: $(NAME)

$(NAME):  $(DIROBJCLASSES) $(DIROBJS)
	@printf 'Compiling %s : [\033[32mDONE\033[0m]\n' '$(NAME)'
	@$(CLANG) $(CFLAGS) -o $@ $^

$(DIROBJ)%.o: $(DIRSRC)%.cpp
	@printf 'Compiling %s: [\033[32mDONE\033[0m]\n' '$^'
	@mkdir -p obj
	@$(CLANG) $(CFLAGS) -c $^ -I $(HEADERS) -I $(INTERFACES) -I $(INCLUDES) -I $(BREWINC) -o $@

$(DIROBJCLASS)%.o: $(DIRCLASS)%.cpp
	@printf 'Compiling %s: [\033[32mDONE\033[0m]\n' '$^'
	@mkdir -p obj
	@$(CLANG) $(CFLAGS) -c $^ -I $(HEADERS) -I $(INTERFACES) -I $(INCLUDES) -I $(BREWINC) -o $@

clean:
	@rm -rf $(DIROBJ) $(DIROBJCLASSES)
	@printf 'Clean %s : [\033[32mDONE\033[0m]\n' '$(NAME)'

fclean: clean
	@$(RM) $(RFLAGS) $(NAME) $(TEST)
	@printf 'Fclean %s : [\033[32mDONE\033[0m]\n' '$(NAME)'

re: fclean all

.PHONY: all clean fclean re