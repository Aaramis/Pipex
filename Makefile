# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agardett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 17:38:06 by agardett          #+#    #+#              #
#    Updated: 2023/03/03 10:25:13 by agardett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############
#  VARIABLES  #
###############

# 	FILES
SRC_F		= ./SRCS/
LIBFT_F		= ./libft
FILES		= childs
BONUS_F		= child_bonus error_bonus files_bonus free_bonus hdoc
 
SRCS		= $(addsuffix .c,$(FILES))
OBJS		= $(addprefix $(SRC_F),$(addsuffix .o,$(FILES)))
SRCS_B		= $(addsuffix .c,$(BONUS_F))
OBJS_B		= $(addprefix $(SRC_F), $(addsuffix .o,$(BONUS_F)))

#	INCLUDES
INC			= ./INCS
INC_L		= $(LIBFT_F)/INCS
NAME_LIB	= libft.a
LIB_F		= $(LIBFT_F)/$(NAME_LIB)

#	COMPILER
CC			= cc -g
SANITIZE	= -fsanitize=address
RM			= rm -f
LINKER		= ar rcs 
WFLAGS		= -Wall -Werror -Wextra
IFLAGS		= -I $(INC) -I $(INC_L)
IFLAGS2		= -I .$(INC) -I .$(INC_L)
OFLAGS		= -O2 -funroll-loops
GFLAGS		= $(WFLAGS) $(IFLAGS) $(OFLAGS)
LIB			= $(LIBFT_F)/$(NAME_LIB)

#	OUTPUT
NAME_EX		= pipex
NAME_B		= pipex_bonus

############
#  COLORS  #
############

BLACK		= "\033[1;30m"
RED			= "\033[1;31m"
GREEN		= "\033[1;32m"
CYAN		= "\033[1;36m"
PURPLE		= "\033[1;35m"
WHITE		= "\033[1;37m"
EOC			= "\033[0;0m"

##############
#  COMMANDS  #
##############

all:		$(NAME_EX)

$(NAME_EX):
		@echo $(CYAN) "\n"					\
		"#######################################\n"		\
		"   Compilation des fichiers en cours   \n"	 	\
		"#######################################\n"		\
		$(EOC)
		@cd $(LIBFT_F) && $(MAKE) all
		@cd $(SRC_F) && $(CC) $(WFLAGS) $(IFLAGS2) -c $(SRCS)
		@$(CC) $(GFLAGS) $(SRC_F)pipex.c $(OBJS) $(LIB_F) -o $(NAME_EX)
		@echo $(CYAN) "\n"					\
		"------- Succeeded : fully compiled -------\n"		\
		$(EOC)

$(NAME_B):
		@echo $(CYAN) "\n"					\
		"#############################################\n"	\
		"   Compilation des fichiers Bonus en cours   \n"	\
		"#############################################\n"	\
		$(EOC)
		@cd $(SRC_F) && $(CC) $(WFLAGS) $(IFLAGS2) -c $(SRCS_B)
		@$(CC) $(GFLAGS) $(SRC_F)pipex_bonus.c $(OBJS_B) $(LIB_F) -o $(NAME_B)
		@echo $(CYAN) "\n"					\
		"------- Succeeded : fully compiled -------\n"		\
		$(EOC)

bonus:	$(NAME_EX) $(NAME_B)

clean:
		@$(RM) $(OBJS) $(OBJS_B)
		@cd $(LIBFT_F) && $(MAKE) clean

fclean:		clean
		@echo $(CYAN) "\n"					\
		"#######################################\n"		\
		"Nettoyage Complet des fichiers en cours\n"	 	\
		"#######################################\n"		\
		$(EOC)
		@cd $(LIBFT_F) && $(MAKE) fclean
		@$(RM) $(NAME_EX) $(NAME_B)
		@echo $(CYAN) "\n"					\
		"------- Succeeded : fully cleaned -------\n"		\
		$(EOC)

re: 		fclean
		@$(MAKE) all
		@$(MAKE) bonus

.PHONY: 	all clean fclean re
.SILENT:	all
