SRC = src
CMD = cmd
BUILD = build
INCLUDE = -I$(SRC)

CFILES = $(shell find $(SRC)/ -type f -name "*.c")
HFILES = $(shell find $(SRC)/ -type f -name "*.h")

$(BUILD)/hmac: $(BUILD)/ $(BUILD)/lib2104.so cmd/hmac.c
	gcc -L./$(BUILD) -l2104 $(INCLUDE) cmd/hmac.c -o $(BUILD)/hmac

$(BUILD)/lib2104.so: $(BUILD)/ $(CFILES) $(HFILES)
	gcc -shared -fPIC $(INCLUDE) $(CFILES) -o $(BUILD)/lib2104.so

$(BUILD)/:
	mkdir $(BUILD)
