# Executable's name (Can be changed)

NAME		= rtv1

# All the directories needed to know where files should be (Can be changed)

ABSDIR		= $(shell pwd)
OBJDIR		= objs/
SRCDIR		= srcs/
LFTDIR		= libft/
LMTHDIR		= libmath/
SDLDIR		= $(ABSDIR)/SDL2-2.0.9/
INCDIR		= ./incs/ ./SDL2-2.0.9/include/ ./libft/ ./libmath/

# Source files (Can be changed)

SRC			= check.c color_tools.c free.c init.c init_objs.c light.c main.c normal.c parse_tools.c parsing.c raytrace.c verif_camera.c verif_light.c verif_objs.c

INCS		= libft/libft.h	\
			  incs/rtv1.h	\
			  libmath/libmath.h

LFT			= ./libft/libft.a
LMTH		= ./libmath/libmath.a

TOOLS		=

# Some tricks in order to get the makefile doing his job the way I want (Can't be changed)

CSRC		= $(addprefix $(SRCDIR), $(SRC))
COBJ		= $(addprefix $(OBJDIR), $(OBJ))
SUBDIRS		= $(foreach dir, $(OBJSUBDIRS), $(OBJDIR)$(dir))
INCLUDES	= $(foreach include, $(INCDIR), -I$(include))
FRAMEWORKS	= $(foreach framework, $(TOOLS), -framework $(framework))

# How files should be compiled with set flags (Can be changed)

CC			= gcc
OBJ			= $(SRC:.c=.o)
LIBS		= -L$(LFTDIR) -lft		\
			  -L$(LMTHDIR) -lmath	\
			  $(shell $(ABSDIR)/SDL2/bin/sdl2-config --libs)
CFLAGS		= $(INCLUDES) -Wall -Wextra -Werror -Ofast -g

# Color codes

RESET		= \033[0m
GREEN		= \033[32m
YELLOW		= \033[33m

# Check if object directory exists, build libft and then the Project

all: SDL2 $(NAME)

SDL2:
	@mkdir -p SDL2/
	@mkdir -p SDL2/build
	@cd SDL2/build; \
		$(SDLDIR)/configure --prefix $(ABSDIR)/SDL2; \
		make -j6; \
		make install \

$(NAME): $(LFT) $(LMTH) $(OBJDIR) $(COBJ)
	@echo "$(YELLOW)\n      - Building $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	@$(CC) $(CFLAGS) $(LIBS) $(FRAMEWORKS) -o $(NAME) $(COBJ)
	@echo "$(GREEN)***   Project $(NAME) successfully compiled   ***\n$(RESET)"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(SUBDIRS):
	@mkdir -p $(SUBDIRS)
	# Redefinition of implicit compilation rule to prompt some colors and file names during the said compilation

$(OBJDIR)%.o: $(SRCDIR)%.c
	@echo "$(YELLOW)      - Compiling :$(RESET)" $<
	@$(CC) $(CFLAGS) -c $< -o $@

# Compilation rule for function library "libft"

$(LFT):
	@make -sC $(LFTDIR) -j

$(LMTH):
	@make -sC $(LMTHDIR) -j

# Deleting all .o files and then the directory where they were located

clean:
	@make -sC$(LFTDIR) clean
	@make -sC$(LMTHDIR) clean
	@echo "$(GREEN)***   Deleting all object from $(NAME)   ...   ***\n$(RESET)"
	@rm -rf $(OBJDIR)

# Deleting the executable after cleaning up all .o files

fclean: clean
	@make -sC $(LFTDIR) fclean
	@make -sC $(LMTHDIR) fclean
	@echo "$(GREEN)***   Deleting executable file from $(NAME)   ...   ***\n$(RESET)"
	@rm -f $(NAME)
	@rm -rf $(OBJDIR)
	@rm -rf SDL2

re: fclean all

PHONY: all clean fclean re
