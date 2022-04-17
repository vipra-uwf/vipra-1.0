FROM ubuntu:20.04

WORKDIR /usr/src/

COPY ./ ./
RUN mkdir -p Build
RUN mkdir -p Build/configuration
RUN mkdir -p Build/definitions
RUN mkdir -p Build/dsl/actions
RUN mkdir -p Build/dsl/conditions
RUN mkdir -p Build/dsl/generated
RUN mkdir -p Build/dsl/selectors
RUN mkdir -p Build/dsl/transitions
RUN mkdir -p Build/entity_sets
RUN mkdir -p Build/entity_sets/factory
RUN mkdir -p Build/goals
RUN mkdir -p Build/jsoncpp
RUN mkdir -p Build/models
RUN mkdir -p Build/readers
RUN mkdir -p Build/writers
RUN mkdir -p Build/simulation


RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install -y libantlr4-runtime-dev
RUN apt-get install -y g++
RUN apt-get install -y make

RUN make