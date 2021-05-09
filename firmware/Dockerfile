FROM debian:stable-slim
RUN apt-get -y update \
  && apt-get install -y --no-install-recommends build-essential ca-certificates git libusb-1.0-0-dev make pkg-config sdcc \
  && rm -rf /var/lib/apt/lists/*
RUN cd /root \
  && git clone https://github.com/vdudouyt/stm8flash.git \
  && cd /root/stm8flash \
  && make \
  && make install
# RUN echo 'SUBSYSTEM=="usb", ATTRS{idVendor}=="0483", ATTRS{idProduct}=="3748", MODE="0666"' | tee /etc/udev/rules.d/99-stlinkv2.ruleS > /dev/null
VOLUME /root/workspace
WORKDIR /root/workspace
