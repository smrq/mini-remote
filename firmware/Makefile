CWD=$(dir $(abspath $(lastword $(MAKEFILE_LIST))))

DOCKER_IMG := sdcc
ifneq ($(SKIP_DOCKER), true)
	RUN := @docker run -it --rm -e SKIP_DOCKER=true -v $(CWD):/root/workspace $(DOCKER_IMG)
endif

SRCDIR=src
BINDIR=bin
SPLDIR=/root/spl/STM8L10x_StdPeriph_Driver

CC=sdcc
CFLAGS=-lstm8 -mstm8 --opt-code-size --std-sdcc99 --nogcse --all-callee-saves --debug --verbose --stack-auto --fverbose-asm --float-reent --no-peep -D STM8L101

.PHONY: all docker unlock flash

all: $(BINDIR)/blink.ihx

clean:
	$(RUN) rm -rf $(BINDIR)

docker: Dockerfile
	@docker build -t $(DOCKER_IMG) .

unlock:
	$(RUN) stm8flash -c stlinkv2 -p stm8l101f3 -u

flash: $(TARGET)
	$(RUN) stm8flash -c stlinkv2 -p stm8l101f3 -s flash -w $(TARGET)

$(BINDIR)/blink.ihx: $(SRCDIR)/blink.c
	$(RUN) mkdir -p bin
	$(RUN) $(CC) $(CFLAGS) -o $@ $^
