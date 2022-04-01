FROM node:17

WORKDIR /usr/src/vipra

RUN mkdir /VIPRA
RUN mkdir /WebAPI

#Moving over necessary files
COPY ./WebAPI ./WebAPI
COPY ./VIPRA ./VIPRA


EXPOSE 3000

RUN apt-get -y update && apt-get -y upgrade

#installing docker
RUN apt-get install -y docker

#installing antlr4
RUN apt-get install -y libantlr4-runtime-dev

#build-essential
RUN apt-get install -y build-essential

#make
RUN apt-get install -y make

RUN cd ./WebAPI && npm install

RUN cd ./VIPRA && make