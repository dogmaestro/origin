FROM ubuntu:22.04 AS builder

RUN apt-get update && apt-get install -y build-essential cmake git clang

WORKDIR /app
RUN mkdir map01_1

RUN git init map01_1 && \
    cd map01_1 && \
    git remote add origin https://github.com/dogmaestro/origin.git && \
    git config core.sparseCheckout true && \
    echo "map/01/map01_1" >> .git/info/sparse-checkout && \
    git pull origin main

WORKDIR /app/map01_1/map/01/map01_1

RUN cmake -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ . && make
RUN mv map01_1 map01_1_gcc

RUN cmake -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ . && make
RUN mv map01_1 map01_1_clang
