NAME = libft.a
CC = gcc

LIBDIR	= ./
SRCDIR	= srcs
OBJDIR	= objs

ifeq ($(DEBUG),yes)
	CFLAGS = -m32 -std=gnu99 -Wextra -Wall -g -O0
else ifeq ($(OPTIM),yes)
	# -fno-omit-frame-pointer keep good call trace for panic()
	CFLAGS = -m32 -std=gnu99 -Wextra -Wall -O2 -fno-omit-frame-pointer
else
	CFLAGS = -m32 -std=gnu99 -Wextra -Wall
endif
CFLAGS += -fno-builtin -fno-stack-protector -nostdlib -nodefaultlibs -fno-exceptions
CFLAGS += -nostdinc

IFLAGS = -Iincludes

SRC_USUALS	= memset memset4 bzero memcpy memccpy memmove memchr memcmp \
	strlen strcpy strncpy strcat strncat strlcat \
	strchr strrchr strstr strnstr strcmp strncmp \
	atoi isalpha isdigit isalnum isascii isprint toupper tolower \
	strclr striter striteri \
	strequ strnequ \
	putchar putstr putendl putnbr putnbr_base \
	secure_atoi \
	aligned_memcpy aligned_bzero

SRC_PRINTK	= beacon op_main modifiers extract_args \
	s_string s_char s_numeric_u s_numeric_i \
	s_pointer s_logical_b s_logical_o s_logical_xmin s_logical_xmaj	\
	cast buffer norme

SRC_BTREE	= btree_apply_infix btree_apply_prefix btree_apply_suffix \
	btree_apply_by_level btree_get_node btree_level_count \
	btree_check_binary_tree btree_memory_move \
	btree_delete_node btree_delete_rnb_node btree_insert_node btree_insert_rnb_node \
	btree_limit_items btree_ctor btree_check_rnb_property btree_atomics_op \
	btree_rotation_node btree_family_node \
	btree_insert_strategy btree_delete_strategy \
	btree_smash_checker \
	btree_get_last_valid btree_get_neighbours btree_conditional_insert

SRC_CHAINED	= lst_new lst_del_one lst_del lst_add lst_iter lst_map lst_invert_rec \
	lst_push_front lst_push_back lst_pre_alloc lst_merge lst_create_elem lst_invert_it

SRC_SORT    = fusion_merge_tab fusion_merge_chain_list

USUALS_DIR	= usuals_tools
PRINTK_DIR  = printk
BTREE_DIR   = binary_tree
CHAINED_DIR = chained_tools
SORT_DIR    = sort_tools

SRC = 	$(addprefix $(USUALS_DIR)/, $(addsuffix .c, $(SRC_USUALS))) \
		$(addprefix $(PRINTK_DIR)/, $(addsuffix .c, $(SRC_PRINTK))) \
		$(addprefix $(BTREE_DIR)/, $(addsuffix .c, $(SRC_BTREE))) \
		$(addprefix $(CHAINED_DIR)/, $(addsuffix .c, $(SRC_CHAINED))) \
		$(addprefix $(SORT_DIR)/, $(addsuffix .c, $(SRC_SORT)))

TMP = $(basename $(notdir $(SRC)))
OBJ = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(TMP)))

.PHONY: all re clean fclean help

all: $(NAME)

$(NAME): $(OBJ) includes/libft.h includes/btree.h includes/chained_tools.h srcs/printk/internal_printf.h
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/$(USUALS_DIR)/%.c includes/libft.h
	$(CC) -c $(CFLAGS) $(IFLAGS) -o $@ $<

$(OBJDIR)/%.o: $(SRCDIR)/$(PRINTK_DIR)/%.c srcs/printk/internal_printf.h
	$(CC) -c $(CFLAGS) $(IFLAGS) -o $@ $<

$(OBJDIR)/%.o: $(SRCDIR)/$(SORT_DIR)/%.c includes/libft.h
	$(CC) -c $(CFLAGS) $(IFLAGS) -o $@ $<

$(OBJDIR)/%.o: $(SRCDIR)/$(BTREE_DIR)/%.c includes/btree.h srcs/binary_tree/btree_internal_header.h
	$(CC) -c $(CFLAGS) $(IFLAGS) -o $@ $<

$(OBJDIR)/%.o: $(SRCDIR)/$(CHAINED_DIR)/%.c includes/chained_tools.h
	$(CC) -c $(CFLAGS) $(IFLAGS) -o $@ $<

clean:
	rm -vf $(OBJ)

fclean:
	rm -vf $(OBJ)
	rm -vf $(NAME)

re: fclean all

help:
	@echo
	@echo "Librairy $(NAME)"
	@echo
	@echo "--------------------------------------------------------------------------"
	@echo " Disp rules."
	@echo
	@echo " all     : Compile the librairy if a file has changed, stored in $(LIBDIR)."
	@echo " re      : Recompile all objets of the librairy."
	@echo " clean   : Remove objects."
	@echo " fclean  : Remove objects and executable."
	@echo " help    : Display this."
	@echo "--------------------------------------------------------------------------"
	@echo
