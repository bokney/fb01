CC = clang
PORTMIDI_PREFIX = $(shell brew --prefix portmidi)
CFLAGS = -Wall -O2 -fPIC -Iinclude -I$(PORTMIDI_PREFIX)/include
LDFLAGS = -dynamiclib -L$(PORTMIDI_PREFIX)/lib
BIN_LDFLAGS = -L$(PORTMIDI_PREFIX)/lib
LIBS = -lportmidi

# === Unity Setup ===
UNITY_REPO = https://github.com/ThrowTheSwitch/Unity
UNITY_DIR = third_party/unity
UNITY_SRC = $(UNITY_DIR)/src
UNITY_EXISTS = $(shell [ -d $(UNITY_DIR) ] && echo 1)

# All C source files in src/
SRC = $(wildcard src/*.c)
LIB_SRC = $(filter-out src/main.c, $(SRC))
OBJ = $(LIB_SRC:.c=.o)
OUT = build/libfb01.dylib

# === Targets ===

all: $(OUT)

# Build the shared library
$(OUT): $(OBJ)
	@mkdir -p build
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)

# Clean build artifacts
clean:
	rm -rf build src/*.o test/*.o

# === Unity Tests ===
TEST_SRC = test/test_midi.c $(LIB_SRC) $(UNITY_SRC)/unity.c
TEST_OUT = build/test_midi

clone_unity:
ifeq ($(UNITY_EXISTS),)
	@echo "Cloning Unity..."
	@git clone $(UNITY_REPO) $(UNITY_DIR)
else
	@echo "Unity already exists!"
endif

$(TEST_OUT): clone_unity
	@mkdir -p build
	$(CC) $(CFLAGS) -I$(UNITY_SRC) -o $@ $(TEST_SRC) $(BIN_LDFLAGS) $(LIBS)

test: $(TEST_OUT)
	./$(TEST_OUT)
