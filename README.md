# libMLV - Simple Graphical library

[![Release new version](https://github.com/OJddJO/libMLV/actions/workflows/release.yml/badge.svg)](https://github.com/OJddJO/libMLV/actions/workflows/release.yml)

> [!NOTE]
> This library isn't made by me. I did touch the source code to fix some compilation bugs but it is not mine.
> For further information, see the [README](./README) file.

## A repo for a precompiled version of libMLV

This repo is just a repo for precompiled versions of `libMLV`. If you find any bugs or have any questions related to the library, please report/ask them in the issues or discussions **BEFORE** reporting them to the library maintainer *(Maintainers of official package: Adrien Boussicault <adrien.boussicault@labri.fr> [`source:debian 11/20/2025`](https://bugs.debian.org/cgi-bin/pkgreport.cgi?pkg=libmlv3;dist=unstable))*.

## Description

The `MLV` (stands for `Marne-la-Vallée`) library is a simplified multimedia libary.

The library is perfect for beginners in C programming who wants to use graphics and sound effects.
The library allows to:
 - draw figures, text and boxed text,
 - display images,
 - play music,
 - get keyboard and mouse event
 - get informations by input boxes

This tool is a simplified interface of the SDL libraries.

If you are not a beginner, we recommend you to use the SDL libraries (sdl, sdl-gfx, sdl-sound, sdl-ttf) instead of the `MLV` library.

## Usage

Currently, there's only a Linux version (should work on any `x86_64` Linux, tested on `NixOS`, `ArchLinux` and `Ubuntu`)

I'm working on a Windows version. And maybe for MacOS too, though it will be hard...

Go to the [releases](https://github.com/OJddJO/libMLV/releases) and download the version you need.

You'll also need to install `sdl1.2-compat` (cause `SDL1.2` is ultra-deprecated), `sdl1.2-mixer`, `sdl1.2-ttf`, `sdl1.2-image`, `sdl1.2-gfx` and `libxml2`.

#### NixOS
You can use the [`shell.nix`](./shell.nix) file.
#### Arch
Use the following command:
```bash
sudo pacman -S libxml2 sdl12-compat sdl_image sdl_mixer sdl_ttf sdl_gfx
```
#### Ubuntu
Use the following command:
```bash
sudo apt-get install libsdl1.2-compat-dev libsdl-image1.2-dev libsdl-ttf2.0-dev libsdl-mixer1.2-dev libsdl-gfx1.2-dev libxml2-dev
```
#### Windows (MSYS2)
Use the following command:
```bash
pacman -S libxml2 mingw-w64-x86_64-sdl12-compat mingw-w64-x86_64-SDL_gfx mingw-w64-x86_64-SDL_ttf mingw-w64-x86_64-SDL_image mingw-w64-x86_64-SDL_mixer
```

If you have any questions/issues with the installation, please leave an issue or open a discussion.

## Changes compared to the official release
- Removed `glib2` dependency
