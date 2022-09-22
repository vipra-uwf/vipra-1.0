FROM node:latest

EXPOSE 3001

WORKDIR /usr/src/VIPRA

RUN apt-get update && apt-get install
RUN apt-get install -y nano
RUN apt-get install -y gdb
RUN apt-get install -y libantlr4-runtime-dev
RUN npm install -g typescript 

RUN mkdir /usr/src/VIPRA/certs

COPY ./ChainBuilder ./ChainBuilder
RUN cd /usr/src/VIPRA/ChainBuilder && npm install && npm run build && npm pack

COPY ./VIPRA_Launcher/server/package.json ./VIPRA_Launcher/server/package.json
RUN cd /usr/src/VIPRA/VIPRA_Launcher/server && npm install

COPY ./VIPRA_Launcher ./VIPRA_Launcher

RUN cd /usr/src/VIPRA/VIPRA_Launcher/server && npm run build


COPY ./VIPRA_DEV ./VIPRA_DEV
COPY ./Example_Maps ./VIPRA_DEV
COPY ./Example_Modules ./VIPRA_DEV

RUN openssl req -newkey rsa:4096 \
            -x509 \
            -sha256 \
            -days 3650 \
            -nodes \
            -out /usr/src/VIPRA/certs/local.crt \
            -keyout /usr/src/VIPRA/certs/local.pem \
            -subj "/C=US/ST=FL/L=Tempe/O=UWF/CN=127.0.0.1"


CMD ["/bin/bash"]