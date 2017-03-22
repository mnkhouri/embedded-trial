CC ?= gcc

CFLAGS_ALL_WARNINGS := -Wall -Wextra -Wformat=2 \
    -Wswitch-default -Wswitch-enum -Wcast-align -Wpointer-arith \
    -Wbad-function-cast -Wstrict-overflow=5 -Wstrict-prototypes -Winline \
    -Wundef -Wnested-externs -Wcast-qual -Wshadow -Wfloat-equal -Wredundant-decls \
    -Wold-style-definition \
    -Wno-unused-parameter -Wno-missing-field-initializers -Wno-missing-braces

CFLAGS := $(CFLAGS_ALL_WARNINGS) -Werror

EXECUTABLE := websiteChecker

.PHONY: clean all
all: $(EXECUTABLE)

$(EXECUTABLE): $(EXECUTABLE).c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(EXECUTABLE) *.o
