# libMLV - Simple Graphical library

[![Release new version](https://github.com/OJddJO/libMLV/actions/workflows/release.yml/badge.svg)](https://github.com/OJddJO/libMLV/actions/workflows/release.yml)

> [!NOTE]
> This library isn't originally made by me.
> For further information, see the [README](./README) file.

## A repo for an alternative version of libMLV with precompiled binaries

This repo is for reworked and precompiled versions of `libMLV`. It is based on the [`MLV` library](#Links-to-official-libMLV) (version `3.1.0`). If you find any bugs or have any questions related to the library, please report/ask them in the issues or discussions. **DO NOT** report them to the official library maintainers.

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
#### (*WIP*) Windows (MSYS2)

Use the following command:
```bash
pacman -S libxml2 mingw-w64-x86_64-sdl12-compat mingw-w64-x86_64-SDL_gfx mingw-w64-x86_64-SDL_ttf mingw-w64-x86_64-SDL_image mingw-w64-x86_64-SDL_mixer
```

If you have any questions/issues with the installation, please leave an issue or open a discussion.

## Changes compared to the official release

- Removed `glib2` dependency

## Have an idea for the library ?

Start a discussion and explain what feature you want implemented in the library !

## Links to official libMLV

- [Official Website *(outdated)*](https://www-igm.univ-mlv.fr/~boussica/mlv/index.html) (The latest version is `libMLV3` but the site only references `libMLV2` and previous versions)
- [pkgs.org](https://pkgs.org/download/libmlv3)
- [Debian](https://packages.debian.org/bullseye/arm64/libmlv3)
- [Ubuntu](https://launchpad.net/ubuntu/+source/mlv/)

## Copyright

This library is released under the `GPL-v3` license

```
This file is part of the MLV Library.

Copyright (C) 2010 2011 2012 Adrien Boussicault, Marc Zipstein
Copyright (C) 2025 OJddJO

This library is free software: you can redistribute it and/or modify it under 
the terms of the GNU General Public License as published by the Free Software 
Foundation, either version 3 of the License, or (at your option) any later 
version.

This library is distributed in the hope that it will be useful, but WITHOUT 
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more 
details.

You should have received a copy of the GNU General Public License along with 
this Library.  If not, see <http://www.gnu.org/licenses/>.
```
