FROM debian:stable-slim
RUN apt-get -y update \
  && apt-get install -y --no-install-recommends sdcc make \
  && rm -rf /var/lib/apt/lists/*
VOLUME /root/workspace
WORKDIR /root/workspace
