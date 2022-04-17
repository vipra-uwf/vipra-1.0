FROM node:17


ARG IMAGE_DIR=./DockerImages
ARG ACONF_DIR=./Autoconf_files
ARG SOURCE_DIR=./src
ARG API_DIR=./WebAPI
ARG VIPRA_DIR=./VIPRA
ARG INCLUDE_DIR=./include

WORKDIR /root

RUN mkdir ${VIPRA_DIR}
RUN mkdir ${API_DIR}
RUN mkdir ${IMAGE_DIR}
RUN mkdir ${SOURCE_DIR}
RUN mkdir ${INCLUDE_DIR}

RUN cd ${API_DIR} && mkdir BUILDS

#Moving over necessary files
COPY ${IMAGE_DIR} ${IMAGE_DIR}
COPY ${ACONF_DIR} ${ACONF_DIR}
COPY ${API_DIR}   ${API_DIR}
COPY ${VIPRA_DIR} ${VIPRA_DIR}

COPY ${VIPRA_DIR}/configuration  ${SOURCE_DIR}/configuration
COPY ${VIPRA_DIR}/definitions    ${SOURCE_DIR}/definitions
COPY ${VIPRA_DIR}/dsl            ${SOURCE_DIR}/dsl
COPY ${VIPRA_DIR}/entity_sets    ${SOURCE_DIR}/entity_sets
COPY ${VIPRA_DIR}/goals          ${SOURCE_DIR}/goals
COPY ${VIPRA_DIR}/input_data     ${SOURCE_DIR}/input_data
COPY ${VIPRA_DIR}/jsoncpp        ${SOURCE_DIR}/jsoncpp
COPY ${VIPRA_DIR}/models         ${SOURCE_DIR}/models
COPY ${VIPRA_DIR}/readers        ${SOURCE_DIR}/readers
COPY ${VIPRA_DIR}/simulation     ${SOURCE_DIR}/simulation
COPY ${VIPRA_DIR}/writers        ${SOURCE_DIR}/writers
COPY ${VIPRA_DIR}/rapidxml       ${SOURCE_DIR}/rapidxml


RUN apt-get -y update && apt-get -y upgrade

#installing antlr4
RUN apt-get install -y libantlr4-runtime-dev

#build-essential
RUN apt-get install -y build-essential

#autoconf
RUN apt-get install -y autoconf automake libtool

#make
RUN apt-get install -y make

RUN cd ${API_DIR} && npm install

# TODO figure out why bcrypt doesn't install properly first time
RUN cd ${API_DIR} && npm uninstall bcrypt
RUN cd ${API_DIR} && npm install bcrypt

# build generate_main
RUN cd ${VIPRA_DIR} && make

EXPOSE 3000

#TODO clean-up
