LIB_SRC_FILES := $(wildcard src/*.c)
LIB_OBJ_FILES := $(patsubst src/%.c,src/%.o,$(LIB_SRC_FILES))

TRANSPILER_SRC_FILES := $(wildcard transpiler/*.c)
TRANSPILER_OBJ_FILES := $(patsubst transpiler/%.c,transpiler/%.o,$(TRANSPILER_SRC_FILES))

JSFUCK_PADDING := 0xfff

ifeq ($(OS),WIN)
TRANSPILER=jsfuck.exe
else
TRANSPILER=jsfuck
endif

$(TRANSPILER): libjsfuck.a
	gcc -O3 -Wall -ansi -I include -L. $(TRANSPILER_SRC_FILES) -ljsfuck -o $(TRANSPILER)

libjsfuck.a: $(LIB_OBJ_FILES)
	ar rcs -o libjsfuck.a $^

src/%.o: src/%.c
	gcc -O3 -Wall -ansi -I include -D JSFUCK_PADDING=$(JSFUCK_PADDING) -c $< -o $@