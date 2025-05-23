SRC = src
BUILD = build
INCLUDE = -I$(SRC)

CFILES = $(shell find $(SRC)/ -type f -name "*.c")
HFILES = $(shell find $(SRC)/ -type f -name "*.h")

$(BUILD)/lib2104.so: $(BUILD)/ $(CFILES) $(HFILES)
	gcc -shared -fPIC $(INCLUDE) $(CFILES) -o $(BUILD)/lib2104.so

$(BUILD)/:
	mkdir $(BUILD)
