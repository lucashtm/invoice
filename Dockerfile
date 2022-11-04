FROM ubuntu:22.04
RUN apt update && apt upgrade
RUN apt install -y build-essential qt6-base-dev cmake
RUN apt install -y mesa-utils libglu1-mesa-dev freeglut3-dev mesa-common-dev
RUN apt install -y libglew-dev libglfw3-dev libglm-dev
RUN apt install -y libao-dev libmpg123-dev
WORKDIR /home/src/build
