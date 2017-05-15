# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: voliynik <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/26 16:30:03 by voliynik          #+#    #+#              #
#    Updated: 2017/03/25 15:27:23 by voliynik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAMELIB = libft.a
NAMECHECKER = checker

SRC	=	ft_put.c \
		ft_p_s.c \
		ft_swap.c \
		ft_support.c \
		ft_support2.c \
		ft_support3.c \
		ft_rotate.c \
		ft_rotate2.c \
		ft_second_solution.c \
		ft_sort.c \
		ft_sort2.c 

SRC2 =	ft_checker.c \
		ft_swap.c \
		ft_put.c \
		ft_rotate.c \
		ft_rotate2.c \
		ft_support3.c \
		ft_support.c

OBJ		= $(addprefix $(OBJDIR), $(SRC:.c=.o))
OBJ2	= $(addprefix $(OBJDIR), $(SRC2:.c=.o))

CC		= gcc
CFLAGS  = -Wall -Wextra -Werror
RM 		= rm -f

LIBDIR  = ./libft/
SRCDIR	= ./src/
INCDIR	= ./includes/
OBJDIR	= ./obj/

all: obj $(NAME) $(NAMECHECKER)

obj:
	@mkdir -p $(OBJDIR)
	@echo "creating dir: obj/"
	@mkdir -p $(LIBDIR)
	@echo "creating dir: libft/"
	@printf "\x1b[33mCreating project:\x1b[0m"

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(CC)  $(CFLAGS)  -I $(INCDIR) -c $< -o $@ 
	@printf '\033[0;34m[\033[0;32m✔\033[0;34m]\033[0m' 

$(NAME): $(NAMELIB) $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) -L. -lft
	@echo "\n\x1b[32mPush swap has been created\x1b[0m"

$(NAMECHECKER): $(OBJ2)
	@$(CC) -o $(NAMECHECKER) $(OBJ2) -L. -lft
	@echo "\n\x1b[32mChecker has been created\x1b[0m"

$(NAMELIB):
	@cd $(LIBDIR); make; make clean; mv $(NAMELIB) ../;
	@printf '\n'

clean:
	@echo "Delete old obj"
	@rm -rf $(OBJDIR)

fclean: clean
	@$(RM) $(NAME) $(NAMECHECKER) $(NAMELIB)

re: fclean all
