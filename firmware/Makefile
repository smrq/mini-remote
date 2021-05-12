CWD := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

DOCKER_IMG := sdcc
ifneq ($(SKIP_DOCKER), true)
	RUN := @docker run -it --rm -e SKIP_DOCKER=true -v $(CWD):/root/workspace $(DOCKER_IMG)
endif

SRCDIR := src
BINDIR := bin

TARGET := $(BINDIR)/firmware.ihx
MAIN := $(SRCDIR)/main.c
SRCS := $(MAIN) $(filter-out $(MAIN),$(wildcard $(SRCDIR)/*.c))
OBJS := $(patsubst $(SRCDIR)/%.c,$(BINDIR)/%.rel,$(SRCS))

CC := sdcc
CFLAGS := -lstm8 -mstm8 --opt-code-size --std-sdcc99 --nogcse --all-callee-saves --debug --verbose --stack-auto --fverbose-asm --float-reent --no-peep -D STM8L101

.PHONY: all clean docker flash

all: $(TARGET)

clean:
	$(RUN) rm -rf $(BINDIR)

docker: Dockerfile
	@docker build -t $(DOCKER_IMG) .

flash: $(TARGET)
	stm8flash -c stlinkv2 -p stm8l101f3 -s flash -w $(TARGET)

$(BINDIR)/%.rel: $(SRCDIR)/%.c
	$(RUN) mkdir -p bin
	$(RUN) $(CC) -c $(CFLAGS) -o $@ $^

$(TARGET): $(OBJS)
	$(RUN) mkdir -p bin
	$(RUN) $(CC) $(CFLAGS) -o $@ $^
