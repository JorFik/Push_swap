# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 21:57:25 by JFikents          #+#    #+#              #
#    Updated: 2023/11/28 17:12:30 by JFikents         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs
RM = rm -rf
CC = cc
CALLMAKE = make -C
CFLAGS = -Wall -Wextra -Werror -I./headers
ADD = -fsanitize=address -g
OBJ+ = $(C_FILES:.c=.o) $(BONUS_FILES:.c=.o)
OBJ = $(C_FILES:.c=.o)
LIBS_D = libft
DEBUGGER = debugger/

NAME = push_swap
MAIN =
TEST =
C_FILES = srcs/main.c srcs/push.c srcs/swap.c srcs/rotate.c srcs/rrotate.c\
srcs/del_utils_push_swap.c srcs/utils_push_swap.c srcs/checks.c\

BONUS_FILES =

.PHONY: clean fclean re all c

all: $(NAME)

#bonus: $(OBJ+)
#	@$(LIB) $(NAME) $(OBJ+)

$(NAME) : $(OBJ) a_files
	@echo "	Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(C_FILES) $(LIBS_D).a -o $(NAME)
	@make clean

a_files: $(LIBS_D)
	@for dir in $(LIBS_D); do \
		echo "	Compiling $$dir..."; \
		$(CALLMAKE) $$dir; \
	done

%.o : %.c 
	@echo "	Compiling $@..."
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@echo "	Cleanig traces..."
	@echo "	Ereasing Files .o"
	@$(RM) srcs/$(OBJ+)
	@$(RM) srcs/main.o
	@echo "	Ereasing Files .a"
	@$(RM) *.a

fclean: clean
	@echo "	Ereasing $(NAME)..."
	@$(RM) $(NAME)

re: fclean all

debug: c a_files
	@$(CC) $(ADD) $(CFLAGS) $(H_FILE) $(C_FILES) $(MAIN) $(LIBS_D).a 
	@mv a.out.dSYM $(DEBUGGER)
	@mv a.out $(DEBUGGER)
	@make fclean

test: c a_files
	@$(CC) $(ADD) $(CFLAGS) $(H_FILE) $(TEST) $(LIBS_D).a 
	@mv a.out.dSYM $(DEBUGGER)
	@mv a.out $(DEBUGGER)
	@make fclean

c: fclean
	@$(RM) $(DEBUGGER)* 
	@$(RM) *.out *.dSYM *.gch 