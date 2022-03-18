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
#	-Ofast -march=native -fno-signed-zeros -fno-trapping-math
CC_OPTS := -Llibs/libft -lft -Llibs/ft_printf -lftprintf -L. -lps

NB_LIST := 615382396 2120813508 2114238543

#NB_LIST := 1861976769 -343798644 -1634469158 -1407278190 -1763699739

# NB_LIST := -3543 -1228 1843 -3066 -3473 -1428 310 -4933 2 -3957
# NB_LIST2 := 3181 -1978 -3211 -2547 -1733 1194 2634 528 -2601 1518
# NB_LIST3 := 4348 -3031 -2522 -3244 1950 -505 1256 4890 4299 4036
# NB_LIST4 := 142 -4987 4475 -100 2197 137 -1808 3463 -4465 -4905
# NB_LIST5 := -3577 -1711 2432 -206 491 -714 760 -2705 40 -894

PROJECT := push_swap
MAIN := push_swap.c
HEADER := push_swap.h
NAME := libps.a
EXEC := push_swap

# ---------------------------------------------------------------------------- #
SRCS_DIR := srcs/
SRCS_LST := init_stack.c error_handling.c stack_ops_utils.c stack_ops_main.c \
			misc_utils.c lis_algo.c lis_misc.c lis_filtering.c testing_functions.c \
			sorting_algo_i.c sorting_algo_ii.c sorting_algo_iii.c 
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

recompile: re ${HEADER} ${MAIN}
	@${CC} ${CC_FLAGS} ${CC_OPTS} ${MAIN} -o ${EXEC}

compile: all ${HEADER} ${MAIN}
	@${CC} ${CC_FLAGS} ${CC_OPTS} ${MAIN} -o ${EXEC}

execute: ${EXEC}
	@./${EXEC} ${NB_LIST}
# @./${EXEC} ${NB_LIST} | ./checker_Mac ${NB_LIST}
# @./${EXEC} ${NB_LIST2}
# @./${EXEC} ${NB_LIST3}
# @./${EXEC} ${NB_LIST4}
# @./${EXEC} ${NB_LIST5}
#@./${EXEC} ${NB_LIST} | wc -l

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
