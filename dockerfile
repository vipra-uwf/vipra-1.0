FROM node:latest

WORKDIR /usr/src/VIPRA

COPY ./ChainBuilder ./ChainBuilder

COPY ./VIPRA ./VIPRA
COPY ./VIPRA_DEV ./VIPRA_DEV

COPY ./VIPRA_Launcher/server/dist ./VIPRA_Launcher
COPY ./VIPRA_Launcher/server/certs ./VIPRA_Launcher/certs
COPY ./VIPRA_Launcher/server/package.json ./VIPRA_Launcher

COPY ./VIPRA_Launcher/server/certs ./VIPRA_Launcher/certs

RUN apt-get update && apt-get install

RUN apt-get install -y nano
RUN apt-get install -y gdb
RUN apt-get install -y libantlr4-runtime-dev

RUN cd ./ChainBuilder && npm pack