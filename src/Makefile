CC ?= gcc
CFLAGS_WARN_ALL := -Wno-missing-braces -Wextra -Wno-missing-field-initializers -Wformat=2 \
    -Wswitch-default -Wswitch-enum -Wcast-align -Wpointer-arith \
    -Wbad-function-cast -Wstrict-overflow=5 -Wstrict-prototypes -Winline \
    -Wundef -Wnested-externs -Wcast-qual -Wshadow -Wfloat-equal -Wredundant-decls \
    -Wold-style-definition -Wno-unused-parameter
CFLAGS_ERROR_ALL := $(CFLAGS_WARN_ALL) -Werror
CFLAGS += $(CFLAGS_ERROR_ALL)

EXECUTABLE := websiteChecker

.PHONY: clean all
all: $(EXECUTABLE)

$(EXECUTABLE): $(EXECUTABLE).c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(EXECUTABLE)
