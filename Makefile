CFLAGS=-Wall -Wextra -Werror
IFLAGS=-Iheader -Ilibft -Ift_printf
LFLAGS=-Llibft -Lft_printf

.PHONY: all re clean fclean bonus

BUILD_DIR=build
SOURCE_DIR=source
CLIENT_SRC_DIR=$(SOURCE_DIR)/client
SERVER_SRC_DIR=$(SOURCE_DIR)/server
CLIENT_OBJ_DIR=$(BUILD_DIR)/client
SERVER_OBJ_DIR=$(BUILD_DIR)/server
CLIENT_BONUS_MODULES=main_bonus ft_atoi_safe
SERVER_BONUS_MODULES=main_bonus
CLIENT_MODULES=main ft_atoi_safe
SERVER_MODULES=main
CLIENT_OBJ=$(addprefix $(CLIENT_OBJ_DIR)/, $(addsuffix .o, $(CLIENT_MODULES)))
SERVER_OBJ=$(addprefix $(SERVER_OBJ_DIR)/, $(addsuffix .o, $(SERVER_MODULES)))

all: client server

bonus: CLIENT_OBJ=$(addprefix $(CLIENT_OBJ_DIR)/, $(addsuffix .o, $(CLIENT_BONUS_MODULES)))
bonus: SERVER_OBJ=$(addprefix $(SERVER_OBJ_DIR)/, $(addsuffix .o, $(SERVER_BONUS_MODULES)))
bonus: client server

client: $(CLIENT_OBJ_DIR) libft/libft.a ft_printf/libftprintf.a $(CLIENT_OBJ)
	cc $(CFLAGS) $(LFLAGS) -o $@ $(CLIENT_OBJ) -lft

server: $(SERVER_OBJ_DIR) libft/libft.a ft_printf/libftprintf.a $(SERVER_OBJ)
	cc $(CFLAGS) $(LFLAGS) -o $@ $(SERVER_OBJ) -lft -lftprintf

$(CLIENT_OBJ_DIR)/%.o: $(CLIENT_SRC_DIR)/%.c header/client.h Makefile
	cc $(CFLAGS) $(IFLAGS) -o $@ -c $<

$(SERVER_OBJ_DIR)/%.o: $(SERVER_SRC_DIR)/%.c header/server.h Makefile
	cc $(CFLAGS) $(IFLAGS) -o $@ -c $<

libft/libft.a:
	make -C libft all

ft_printf/libftprintf.a:
	make -C ft_printf all

$(SERVER_OBJ_DIR): | $(BUILD_DIR)
	mkdir $@

$(CLIENT_OBJ_DIR): | $(BUILD_DIR)
	mkdir $@

$(BUILD_DIR):
	mkdir $@

clean:
	rm -rf $(BUILD_DIR)
	make -C libft fclean
	make -C ft_printf fclean

fclean: clean
	rm -f client server

re: fclean all