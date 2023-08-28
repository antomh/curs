CC := gcc
CFLAGS := -std=c11
LIBS := 
OUTPUT_FOLDER := ./output
PRJ_NAME := curs
SRC := $(wildcard *.c)
OBJ := $(patsubst %.c,$(OUTPUT_FOLDER)/%.o,$(SRC))

#------------------------------------------------------------------------------

$(PRJ_NAME): clean $(OUTPUT_FOLDER) $(OBJ)
	@$(CC) \
		$(CFLAGS) \
		$(OBJ) \
		$(LDFLAGS) \
		-o $(OUTPUT_FOLDER)/$@
	@echo "Binary file compiled!"

#------------------------------------------------------------------------------

$(OUTPUT_FOLDER)/%.o: %.c
	@$(CC) \
		$(CFLAGS) \
		-o $@ \
		-c $^
	@echo "$@ : Object file compiled!"

#------------------------------------------------------------------------------

$(OUTPUT_FOLDER):
	@mkdir $(OUTPUT_FOLDER)

run: $(PRJ_NAME)
	@echo "Program start!\n"
	@$(OUTPUT_FOLDER)/$(PRJ_NAME)

.PHONY: clean

clean:
	@rm -f \
		$(OUTPUT_FOLDER)/$(PRJ_NAME) \
		$(OUTPUT_FOLDER)/*.o
	@echo "Old files removed!"
