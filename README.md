# libMLV - Simple Graphical library

[![Release new version](https://github.com/OJddJO/libMLV/actions/workflows/release.yml/badge.svg)](https://github.com/OJddJO/libMLV/actions/workflows/release.yml)

> [!NOTE]
> This library isn't made by me. I did touch the source code to fix some compilation bugs but it is not mine.
> For further information, see the [README](./README) file.

## A repo for a precompiled version of libMLV

This repo is just a repo for precompiled versions of `libMLV`. If you find any bugs or have any questions related to the library, please report/ask them in the issues or discussions **BEFORE** reporting them to the library maintainer *(Maintainers of official package: Adrien Boussicault <adrien.boussicault@labri.fr> [`source:debian 11/20/2025`](https://bugs.debian.org/cgi-bin/pkgreport.cgi?pkg=libmlv3;dist=unstable))*.

## Description

The `MLV` (stands for `Marne-la-Vallée`) library is a simplified multimedia libary.

The library is perfect for beginners in C programming who want to use graphic and sound effects.
The library permit to:
 - draw figures, text and boxed text,
 - display images,
 - plays musics,
 - get Keyboard and mouse event
 - get informations by input boxes

This tools is a simplified interface of the SDL libraries.

If you are not a beginner, we recommend you to use the SDL libraries (sdl, sdl-gfx, sdl-sound, sdl-ttf) instead of the mlv library.

## Usage

Currently, there's only a Linux version (should work on any `x86_64` Linux, tested on `NixOS`, `ArchLinux` and `Ubuntu`)

Go to the [releases](https://github.com/OJddJO/libMLV/releases) and download the version you need.

You'll also need to install `sdl1.2`, `sdl1.2-mixer`, `sdl1.2-ttf`, `sdl1.2-image`, `sdl1.2-gfx`, `glib` and `libxml2`.

If you have any questions/issues with the installation, please leave an issue or open a discussion.
