let
  pkgs = import <nixpkgs> {};
in pkgs.mkShell {
  buildInputs = with pkgs; [
    SDL
    SDL_image
    SDL_mixer
    SDL_ttf
    SDL_gfx
    glib
    libxml2
  ];
}