FROM gcc:10
WORKDIR /
COPY main.c ./
RUN gcc main.c -o main
RUN chmod +x main
