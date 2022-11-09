FROM ubuntu:22.04
RUN apt update && apt upgrade
RUN apt install -y build-essential clangd-12 qt6-base-dev cmake
RUN apt install -y mesa-utils libglu1-mesa-dev freeglut3-dev mesa-common-dev
RUN apt install -y libglew-dev libglfw3-dev libglm-dev
RUN apt install -y libao-dev libmpg123-dev
RUN apt install -y curl git
RUN apt install -y ninja-build gettext libtool libtool-bin autoconf automake pkg-config unzip doxygen ripgrep
RUN apt install -y python3-pip
RUN pip3 install cmake-language-server
RUN update-alternatives --install /usr/bin/clangd clangd /usr/bin/clangd-12 100
WORKDIR /home
RUN git clone https://github.com/neovim/neovim
WORKDIR neovim
RUN git checkout stable
RUN make CMAKE_BUILD_TYPE=Release
RUN make install
