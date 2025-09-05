FROM ubuntu:22.04
ENV DEBIAN_FRONTEND=noninteractive
ARG USERNAME=vscode
ARG USER_UID=1000
ARG USER_GID=$USER_UID
RUN apt-get update \
 && apt-get install -y --no-install-recommends \
    build-essential clang clang-tidy clang-format clangd lldb lld \
    cmake ninja-build git ca-certificates curl wget pkg-config \
    gdb valgrind python3 python3-pip unzip xz-utils \
 && rm -rf /var/lib/apt/lists/*
RUN groupadd --gid $USER_GID $USERNAME \
 && useradd -s /bin/bash --uid $USER_UID --gid $USER_GID -m $USERNAME
RUN curl -fsSL https://apt.kitware.com/keys/kitware-archive-latest.asc | gpg --dearmor -o /usr/share/keyrings/kitware-archive-keyring.gpg \
 && echo 'deb [signed-by=/usr/share/keyrings/kitware-archive-keyring.gpg] https://apt.kitware.com/ubuntu/ jammy main' > /etc/apt/sources.list.d/kitware.list \
 && apt-get update && apt-get install -y cmake
USER $USERNAME
WORKDIR /workspace
