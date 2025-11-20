let
  pkgs = import <nixpkgs> {};
in pkgs.mkShell {
  buildInputs = with pkgs; [
    SDL2
    SDL2_image
    SDL2_mixer
    SDL2_ttf
    SDL2_gfx
    glib
    libxml2
  ];
}