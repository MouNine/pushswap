# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 14:57:33 by eboeuf            #+#    #+#              #
#    Updated: 2015/03/14 12:15:31 by eboeuf           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=		push_swap
SRC		=		push_swap.c ft_s.c ft_p.c ft_list.c ft_sort.c ft_r.c ft_check.c
HEADER	=		push_swap.h
OBJ 	=		$(SRC:.c=.o)
CC		=		gcc
CFLAGS	=		-O3 -Wall -Wextra -Werror
OBJFLAG =		-O3 -Wextra -Werror -Wall #03 flag optimisation
LIBDIR	=		libft/
LIB 	=		libft/libft.a

RED		=		\033[33;31m
BLUE	=		\033[33;34m
GREEN	=		\033[33;32m
RESET	=		\033[0m

.PHONY:			all re fclean

all: $(NAME)

$(LIB):			
				@$(MAKE) -C $(LIBDIR)

$(NAME): $(LIB) $(OBJ)
				@$(CC) -o $(NAME) $(CFLAGS) $(LIB) $^
				@echo "[$(GREEN)Compilation$(BLUE)$(NAME)$(GREEN)ok$(RESET)]"

%.o: %.c
				$(CC) -c -o $@ $(CFLAGS) $^

clean:			
				@cd $(LIBDIR) && $(MAKE) $@
				@rm -f $(OBJ)
				@echo "[$(RED)Supression des .o de $(BLUE)$(NAME)$(GREEN)ok$(RESET)]"

fclean:	clean
				@cd $(LIBDIR) && $(MAKE) $@
				@rm -f $(NAME)
				@echo "[$(RED)Supression de $(BLUE)$(NAME)$(GREEN)ok$(RESET)]"

re:	fclean all
