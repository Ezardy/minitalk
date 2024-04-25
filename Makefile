CFLAGS=-Wall -Wextra -Werror
IFLAGS=-Iheader -Ilibft -Ift_printf
LFLAGS=-Llibft -Lft_printf

.PHONY: all re clean fclean bonus

BUILD_DIR=build
SOURCE_DIR=source
CLIENT_MODULES=client
SERVER_MODULES=server
CLIENT_OBJ_DIR=$(BUILD_DIR)/client
SERVER_OBJ_DIR=$(BUILD_DIR)/server
CLIENT_BONUS_MODULES=client_bonus
SERVER_BONUS_MODULES=server_bonus
CLIENT_OBJ=$(addprefix $(CLIENT_OBJ_DIR)/, $(addsuffix .o, $(CLIENT_MODULES)))
SERVER_OBJ=$(addprefix $(SERVER_OBJ_DIR)/, $(addsuffix .o, $(SERVER_MODULES)))

all: client server

client: $(BUILD_DIR) libft/libft.a ft_printf/libftprintf.a $(CLIENT_OBJ)
	cc $(CFLAGS) $(LFLAGS) -o $@ $(CLIENT_OBJ) -lft -lftprintf

server: $(BUILD_DIR) libft/libft.a ft_printf/libftprintf.a $(SERVER_OBJ)
	cc $(CFLAGS) $(LFLAGS) -o $@ $(SERVER_OBJ) -lft -lftprintf

bonus: CLIENT_OBJ=$(addprefix $(CLIENT_OBJ_DIR)/, $(addsuffix .o, $(CLIENT_BONUS_MODULES)))
bonus: SERVER_OBJ=$(addprefix $(SERVER_OBJ_DIR)/, $(addsuffix .o, $(SERVER_BONUS_MODULES)))
bonus: client server

$(BUILD_DIR)/client%_bonus.o: $(SOURCE_DIR)/client%_bonus.c header/client_bonus.h Makefile
	cc $(CFLAGS) $(IFLAGS) -o $@ -c $<

$(BUILD_DIR)/server%_bonus.o: $(SOURCE_DIR)/server%_bonus.c header/server_bonus.h Makefile
	cc $(CFLAGS) $(IFLAGS) -o $@ -c $<

$(BUILD_DIR)/client%.o: $(SOURCE_DIR)/client%.c header/client.h Makefile
	cc $(CFLAGS) $(IFLAGS) -o $@ -c $<

$(BUILD_DIR)/server%.o: $(SOURCE_DIR)/server%.c header/server.h Makefile
	cc $(CFLAGS) $(IFLAGS) -o $@ -c $<
