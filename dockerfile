FROM node:latest

WORKDIR /usr/src/VIPRA

RUN apt-get update && apt-get install
RUN apt-get install -y nano
RUN apt-get install -y gdb
RUN apt-get install -y libantlr4-runtime-dev
RUN npm install -g typescript 

RUN mkdir /usr/src/VIPRA/certs
RUN openssl req -newkey rsa:4096 \
            -x509 \
            -sha256 \
            -days 3650 \
            -nodes \
            -out /usr/src/VIPRA/certs/local.crt \
            -keyout /usr/src/VIPRA/certs/local.pem \
            -subj "/C=US/ST=FL/L=Tempe/O=UWF/CN=127.0.0.1"

COPY ./ChainBuilder ./ChainBuilder
COPY ./VIPRA ./VIPRA
COPY ./VIPRA_DEV ./VIPRA_DEV
COPY ./VIPRA_Launcher ./VIPRA_Launcher

RUN ln -s /usr/src/VIPRA/VIPRA_DEV /usr/src/VIPRA/VIPRA_Launcher/server/VIPRA_DEV

RUN cd /usr/src/VIPRA/ChainBuilder && npm install && tsc && npm pack
RUN cd /usr/src/VIPRA/VIPRA_Launcher/server && npm install