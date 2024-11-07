FROM ubuntu:16.04

RUN apt-get update && \
    apt-get install -y g++ nano 

RUN mkdir -p /source

COPY hello.cpp /source/

WORKDIR /source

RUN g++ -o hello hello.cpp

CMD ["./hello"]
