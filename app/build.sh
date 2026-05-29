#!/bin/sh

set -e

BUILD_DIR="build"
EXECUTABLE="forge"

# ---------- Colors ----------
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
RESET="\033[0m"

info()  { echo "${BLUE}[INFO]${RESET} $1"; }
ok()    { echo "${GREEN}[OK]${RESET} $1"; }
warn()  { echo "${YELLOW}[WARN]${RESET} $1"; }
error() { echo "${RED}[ERROR]${RESET} $1"; }

# ---------- Build ----------
do_build() {
  info "Configuring project..."
  cmake -S . -B "$BUILD_DIR"
  ok "CMake configured"
}

# ---------- Compile ----------
do_compile() {
  info "Building project..."
  cmake --build "$BUILD_DIR"
  ok "Build complete"
}

# ---------- Check executable ----------
find_executable() {
  if [ -f "$BUILD_DIR/$EXECUTABLE" ]; then
    echo "$BUILD_DIR/$EXECUTABLE"
  elif [ -f "$BUILD_DIR/Debug/$EXECUTABLE" ]; then
    echo "$BUILD_DIR/Debug/$EXECUTABLE"
  elif [ -f "$BUILD_DIR/Release/$EXECUTABLE" ]; then
    echo "$BUILD_DIR/Release/$EXECUTABLE"
  else
    echo ""
  fi
}

# ---------- Run ----------
do_run() {
  EXE_PATH="$(find_executable)"

  if [ -z "$EXE_PATH" ]; then
    warn "Executable not found. Auto-building..."

    do_build
    do_compile

    EXE_PATH="$(find_executable)"
  fi

  if [ -z "$EXE_PATH" ]; then
    error "Build succeeded but executable still not found."
    exit 1
  fi

  info "Running $EXE_PATH"
  "$EXE_PATH"
}

# ---------- Clean ----------
do_clean() {
  info "Cleaning build directory..."
  rm -rf "$BUILD_DIR"
  ok "Clean complete"
}

# ---------- Help ----------
show_help() {
  echo "Usage: ./build.sh [build|compile|run|clean|help]"
  echo ""
  echo "Commands:"
  echo "  build    Generate CMake files"
  echo "  compile  Build project"
  echo "  run      Auto-build if needed, then run"
  echo "  clean    Remove build directory"
  echo "  help     Show this help"
}

# ---------- Dispatcher ----------
case "$1" in
  build)   do_build ;;
  compile) do_compile ;;
  run)     do_run ;;
  clean)   do_clean ;;
  help|*)  show_help ;;
esac