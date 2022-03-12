# ---------------------------------------------------------------------------- #
# ---------------------------------------------------------------------------- #
# #                                                                          # #
# #       ███╗   ███╗ █████╗ ██╗  ██╗███████╗███████╗██╗██╗     ███████╗     # #
# #       ████╗ ████║██╔══██╗██║ ██╔╝██╔════╝██╔════╝██║██║     ██╔════╝     # #
# #       ██╔████╔██║███████║█████╔╝ █████╗  █████╗  ██║██║     █████╗       # #
# #       ██║╚██╔╝██║██╔══██║██╔═██╗ ██╔══╝  ██╔══╝  ██║██║     ██╔══╝       # #
# #       ██║ ╚═╝ ██║██║  ██║██║  ██╗███████╗██║     ██║███████╗███████╗     # #
# #       ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝╚══════╝╚══════╝     # #
# #                                                                          # #
# ---------------------------------------------------------------------------- #
# ---------------------------------------------------------------------------- #

# --------------------------- Terminal Color Codes --------------------------- #
NC  := \033[31;0m
RED := \033[0;31;1m
YEL := \033[0;33;1m
GRA := \033[0;37;1m
CYN := \033[0;36;1m
GRN := \033[0;32;1m
MGN := \033[0;35;1m
BLU := \033[0;34;1m

# ---------------------------------------------------------------------------- #

define TITLE
${RED}
=======================================================================================================
||                                  ,,                                                               ||
||                                `7MM                                                               ||
||                                  MM                                                               ||
|| `7MMpdMAo. `7MM  `7MM  ,pP"Ybd   MMpMMMb.          ,pP"Ybd `7M'    ,A    `MF' ,6"Yb.  `7MMpdMAo.  ||
||   MM   `Wb   MM    MM  8I   `"   MM    MM          8I   `"   VA   ,VAA   ,V  8)   MM    MM   `Wb  ||
||   MM    M8   MM    MM  `YMMMa.   MM    MM          `YMMMa.    VA ,V  VA ,V    ,pm9MM    MM    M8  ||
||   MM   ,AP   MM    MM  L.   I8   MM    MM          L.   I8     VVV    VVV    8M   MM    MM   ,AP  ||
||   MMbmmd'    `Mbod"YML.M9mmmP' .JMML  JMML.        M9mmmP'      W      W     `Moo9^Yo.  MMbmmd'   ||
||   MM                                                                                    MM        ||
|| .JMML.                                     mmmmmmm                                    .JMML.      ||
||                                                                                                   ||
=======================================================================================================
\n\t\t\t\t\t\t\t\t${GRA} - Created By ${BLU}The-Intruder${NC}
endef
export TITLE

# ---------------------------------------------------------------------------- #
CC := gcc
CC_FLAGS := -Wall -Wextra -Werror
CC_OPTS := -Llibs/libft -lft -Llibs/ft_printf -lftprintf -L. -lps

# NB_LIST := -28 6 80 58 29 -54 -100 2 -38 -84 14 77 -53 9 -44 7 -68 0 -62 27 \
# 	-52 3 55 -14 -42 -27 83 -47 -41 -22 -85 -10 12 -24 -88 -98 -51 81 91 -78 -21 \
# 	-89 -77 -57 42 -9 -30 47 67 84 -71 -75 73 85 -95 -13 -23 -33 11 -48 -93 -40 \
# 	-45 -37 74 32 82 -66 -6 41 61 -34 93 -59 46 -73 63 -69 -3 60 96 -35 16 -58 \
# 	-4 75 -74 54 44 48 -64 89 30 4 56 -86 -91 -80 100 -29

NB_LIST := 79 1 5 59 71 9 64 21 74 2 82 88 96 33 84 81 28 51 22 55 20 72 44 17 41 69 49 42 76 50 13 67 60 92 80 90 16 18 10 63 77 57 12 15 30 95 89 52 87 94 73 38 29 11 99 83 3 35 91 58 75 65 54 24 14 66 37 48 7 53 23 39 61 4 36 0 8 78 93 56 25 85 19 40 43 27 98 34 45 46 31 68 70 86 97 47 62 6 32 26

PROJECT := push_swap
MAIN := push_swap.c
HEADER := push_swap.h
NAME := libps.a
EXEC := push_swap

# ---------------------------------------------------------------------------- #
SRCS_DIR := srcs/
SRCS_LST := init_stack.c error_handling.c stack_ops_utils.c stack_ops_main.c \
			misc_utils.c long_incr_sub.c testing_functions.c \
			lis_filtering.c sorting_algo_i.c sorting_algo_ii.c 
SRCS := ${addprefix ${SRCS_DIR}, ${SRCS_LST}}

OBJS_DIR := objs/
OBJS_LST := ${patsubst %.c, %.o, ${SRCS_LST}}
OBJS := ${addprefix ${OBJS_DIR}, ${OBJS_LST}}

# ---------------------------------------------------------------------------- #
.PHONY: all clean fclean re title libs exclean intro compile

all: title ${NAME}

libs:
	@make -C libs/libft/
	@make -C libs/ft_printf/

${NAME}: libs intro ${OBJS_DIR} ${OBJS} ${HEADER}
	@ar -rcs ${NAME} ${OBJS}
	@echo "$(BLU)Archive file $(GRA)$(NAME)$(BLU) created successfully$(NC)\n"

${OBJS_DIR}%.o: ${SRCS_DIR}%.c ${HEADER}
	@${CC} ${CC_FLAGS} -c $< -o $@
	@echo "${MGN}Object file ${GRA}$@${MGN} created from ${GRA}$<${MGN}${NC}"

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)

clean:
	@make -C libs/ft_printf/ clean
	@make -C libs/libft/ clean
	@rm -rf ${OBJS}
	@echo "${GRA}${PROJECT}${RED}\tobject files have been deleted${NC}"
	@echo "\n"

compile: all ${HEADER} ${MAIN}
	@${CC} ${CC_FLAGS} ${CC_OPTS} ${MAIN} -o ${EXEC}

execute: compile ${EXEC}
	@./${EXEC} ${NB_LIST}
	@./${EXEC} ${NB_LIST} | wc -l
#@make exclean >> /dev/null

fclean: clean
	@make -C libs/ft_printf/ fclean
	@make -C libs/libft/ fclean
	@rm -rf ${NAME}
	@echo "${GRA}${PROJECT}${RED}\tarchive file ${GRA}${NAME}${RED}\t\thas been deleted${NC}"
	@echo "\n"

exclean: fclean
	@rm -f ${EXEC}
	@echo "${GRA}${EXEC}${RED}\texecutable file has been deleted\n${NC}"

re: fclean all

intro:
	@echo "\n${YEL}Entering ${GRA}${PROJECT}${YEL}'s makefile"
	@echo "----------------------------${NC}"

title:
	@clear
	@echo "$$TITLE"

# ---------------------------------------------------------------------------- #
