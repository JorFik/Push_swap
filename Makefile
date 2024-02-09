# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 21:57:25 by JFikents          #+#    #+#              #
#    Updated: 2024/02/09 20:29:41 by JFikents         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# * ---------------------- AVOID CHANGES IN THIS AREA ---------------------- * #
LIB = ar rcs
RM = rm -rf
CC = cc
CALLMAKE = make -C
OBJ = $(addprefix $(SRC_DIR), $(C_FILES:.c=.o))
OBJ+ = $(addprefix $(SRC_DIR), $(BONUS_FILES:.c=.o))
SRC = $(addprefix $(SRC_DIR), $(C_FILES))
CFLAGS = -Wall -Wextra -Werror -Wunreachable-code
INCLUDES = $(addprefix -I, $(HEADERS_DIR))
DEBUG_FLAGS = -fsanitize=address -g3
LDFLAGS = $(patsubst %, -L%/, $(LIBRARIES_DIR))\
$(patsubst lib%,-l%,$(LIBRARIES_DIR))
default_target: all
#_----------------------------------------------------------------------------_#

# ? -------------------------- DO YOU HAVE BONUS? -------------------------- ? #
# If you have bonus, change the value of the variable BONUS to 1 and add the
#  bonus files to the variable BONUS_FILES
BONUS = 1
BONUS_FILES = 
# If it compiles together with the rest of the files, change the value of the
# variable COMPILE_TOGETHER to 1
COMPILE_TOGETHER = 1
#_----------------------------------------------------------------------------_#

# ? --------------------------- IS IT A PROGRAM? --------------------------- ? #
# If it is a program, change the value of the variable PROGRAM to 1 and make
# sure that you have int main(void) in your one of files in C_FILES
PROGRAM = 1

#_----------------------------------------------------------------------------_#

# * --------------------------- CHANGE THIS AREA --------------------------- * #
# NAME is the name of the executable or library
NAME = push_swap

# If you need to add more flags to the compilation, add them here in CFLAGS
# -Wall -Wextra -Werror -Wunreachable-code are already added
CFLAGS = 

#_ If you don't want optimization set the value of the variable OPTIMIZATION
#_ located in DEBUG AREA to 0

# If you need to add libraries, add them to the variable LIBRARIES_DIR
#_ Don't add '/' at the end of the directory
LIBRARIES_DIR = libft

# If your libraries are created in a different directory or with a 
# different name, add the appropriate flags to the variable LDFLAGS
# Example of flags that need to be added:
# LDFLAGS += -lglfw
# The Automatically added flags are created with the following pattern:
# -l$(LIBRARY_DIR - "lib" at the beginning) -L$(LIBRARY_DIR + "/" at the end)
# (e.g. libft -> -lft -Llibft/)
LDFLAGS +=

# Here you can add your includes directory that you need to compile your program
# The headers directories are added with the flag -I to the compilation.
HEADERS_DIR = includes/ libft/h_files/\

# Here you can add the subdirectory where your source files are
SRC_DIR = src/

# Here you can add the files that you need to compile your program
#_ NOTE: to every file in C_FILES, the path in SRC_DIR will be added at the
#_ beginning
C_FILES = main.c errors.c stack_operations.c debug_utils.c arg_parsing.c\
	goal.c price.c move.c push.c sort_3.c checks.c

# Here you can add the files that you need to compile that are not inside the
# SRC_DIR
SRC +=

#_----------------------------------------------------------------------------_#

# * ----------------------------- DEBUG AREA ------------------------------ * #

# Set OPTIMIZATION to 0 for a proper debug
OPTIMIZATION = 0

# To debug your program, just call the rule debug
# It will compile your program with the flag -g and move the executable to the
# folder DEBUGGER
DEBUGGER = debugger/

# If you want to test your program, but just some files, add them to the
# variable TEST and use the rule test
TEST = 

# If you want to add more flags to the debug rule, add them to the variable
# DEBUG_FLAGS
# -g3 and -fsanitize=address are already added
DEBUG_FLAGS += 

c:
	@$(RM) $(DEBUGGER)* 
	@$(RM) *.out *.dSYM *.gch test

debug: c a_files
	@echo "	Compiling with debug flags..."
	@$(CC) $(CFLAGS) $(SRC) $(DEBUG_FLAGS) $(INCLUDES) $(LDFLAGS)
	@echo "	Moving to $(DEBUGGER)..."
	@mv a.out.dSYM $(DEBUGGER)
	@mv a.out $(DEBUGGER)
	@echo "	Ready to debug!"

test: c a_files
	@$(CC) $(CFLAGS) $(TEST) $(DEBUG_FLAGS) $(INCLUDES) $(LDFLAGS)
	@mv a.out $(DEBUGGER)
	@mv a.out.dSYM $(DEBUGGER)

trun : a_files
	@$(CC) -o test $(CFLAGS) $(TEST) $(INCLUDES) $(LDFLAGS)
	@echo "	arg?"
	@read arg; \
		./test $$arg

#_----------------------------------------------------------------------------_#

# * ----------------------------- EXTRA RULES ----------------------------- * #

# Here you can add extra rules to compile your program

#_----------------------------------------------------------------------------_#

# * ----------------------------- BASIC RULES ----------------------------- * #

.PHONY: clean fclean re all c bonus debug test a_files submodule aclean $(NAME)

ifeq ($(OPTIMIZATION), 1)
CFLAGS += -Ofast -O3
endif

ifeq ($(BONUS), 1)
ifeq ($(COMPILE_TOGETHER), 1)
all: bonus
else
all: $(NAME) bonus
endif
else
all: $(NAME)
endif

ifeq ($(PROGRAM), 1)
$(NAME) : a_files $(OBJ)
	@echo "	Compiling $@..."
	@$(CC) -o $@ $(OBJ) $(CFLAGS) $(INCLUDES) $(LDFLAGS)
else
$(NAME) : a_files $(OBJ)
	@echo "	Compiling $(NAME)..."
	@$(LIB) $(NAME) $(OBJ) $(INCLUDES) $(LDFLAGS)
endif

clean: aclean
	@echo "	Cleanig traces..."
	@echo "	Ereasing Files .o"
	@$(RM) $(OBJ+) $(OBJ)

aclean:
	@for dir in $(LIBRARIES_DIR); do \
		if test -d $$dir; then \
			if test $$dir = libft; then \
				echo "	Cleaning $$dir..."; \
				$(CALLMAKE) $$dir fclean; \
			else \
				echo "	Cleaning $$dir..."; \
				$(CALLMAKE) $$dir clean; \
			fi \
		else \
			echo "	No need to clean $$dir"; \
		fi \
	done

fclean: clean
	@echo "	Ereasing $(NAME)..."
	@$(RM) $(NAME)

re: fclean all

submodule:
	@git submodule update --init --recursive

a_files: submodule $(LIBRARIES_DIR)
	@for dir in $(LIBRARIES_DIR); do \
		echo "	Compiling $$dir..."; \
		$(CALLMAKE) $$dir -s; \
	done

%.o : %.c
	@echo "	Compiling $@..."
	@$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

run : all
	@echo "	arg?"
	@read arg; \
		./$(NAME) $$arg

git : fclean
	@echo "	Preparring to save to git repository..."
	@$(RM) imgui.ini
	@git add .
	@echo "	Added all files"
	@echo "	Commit message:"
	@read msg; \
		echo "	Commiting..."; \
		git commit -m "$$msg"
	@echo "	Tag (leave blank for no tag):"
	@read tag; \
		if [ -n "$$tag" ]; then \
			echo "	Tag message:"; \
			read tag_msg; \
			echo "	Tagging..."; \
			git tag -a $$tag -m "$$tag_msg"; \
		fi
	@git push

#_----------------------------------------------------------------------------_#

# * ----------------------------- BONUS RULES ----------------------------- * #

ifeq ($(BONUS), 1)
ifeq ($(COMPILE_TOGETHER), 1)
bonus: a_files $(OBJ+) $(OBJ)
	@echo "	Compiling $(NAME) with bonus..."
	@$(CC) -o $(NAME) $(OBJ+) $(OBJ) $(CFLAGS) $(INCLUDES) $(LDFLAGS)
endif
else
bonus: a_files $(OBJ+)
	@echo "	Compiling $(NAME)_bonus..."
	@$(CC) -o $(NAME)_bonus $(OBJ+) $(CFLAGS) $(INCLUDES) $(LDFLAGS)
endif

#_----------------------------------------------------------------------------_#
