/*
 *   This file is part of the MLV Library.
 *
 *   Copyright (C) 2010,2011,2012 Adrien Boussicault, Marc Zipstein
 *
 *
 *    This Library is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This Library is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this Library.  If not, see <http://www.gnu.org/licenses/>.
 */

/** \~french 
 * \file MLV_keyboard.h
 *
 * \author Adrien Boussicault
 * \author Marc Zipstein
 *
 * \brief Ce fichier définit les prototypes des fonctions permettant 
 *        d'utiliser le clavier.
 *
 */

#ifndef __MLV__MLV_KEYBOARD_H__
#define __MLV__MLV_KEYBOARD_H__

#ifndef MEMORY_DEBUG
#include <SDL2/SDL.h>
#else
#include "memory_debug.h"
#endif

#include "MLV_device_with_buttons.h"

#ifdef __cplusplus
extern "C" {
#endif

/** \~french 
 * \brief Énumère l'ensemble des codes des touches du clavier
 */
typedef enum {
	MLV_KEYBOARD_NONE = SDLK_UNKNOWN,
	MLV_KEYBOARD_UNKNOWN = SDLK_UNKNOWN,
	MLV_KEYBOARD_BACKSPACE = SDLK_BACKSPACE, 
	MLV_KEYBOARD_TAB = SDLK_TAB, 
	MLV_KEYBOARD_CLEAR = SDLK_CLEAR, 
	MLV_KEYBOARD_RETURN = SDLK_RETURN, 
	MLV_KEYBOARD_PAUSE = SDLK_PAUSE, 
	MLV_KEYBOARD_ESCAPE = SDLK_ESCAPE, 
	MLV_KEYBOARD_SPACE = SDLK_SPACE, 
	MLV_KEYBOARD_EXCLAIM = SDLK_EXCLAIM, 
	MLV_KEYBOARD_QUOTEDBL = SDLK_QUOTEDBL, 
	MLV_KEYBOARD_HASH = SDLK_HASH, 
	MLV_KEYBOARD_DOLLAR = SDLK_DOLLAR, 
	MLV_KEYBOARD_AMPERSAND = SDLK_AMPERSAND, 
	MLV_KEYBOARD_QUOTE = SDLK_QUOTE, 
	MLV_KEYBOARD_LEFTPAREN = SDLK_LEFTPAREN, 
	MLV_KEYBOARD_RIGHTPAREN = SDLK_RIGHTPAREN, 
	MLV_KEYBOARD_ASTERISK = SDLK_ASTERISK, 
	MLV_KEYBOARD_PLUS = SDLK_PLUS, 
	MLV_KEYBOARD_COMMA = SDLK_COMMA, 
	MLV_KEYBOARD_MINUS = SDLK_MINUS, 
	MLV_KEYBOARD_PERIOD = SDLK_PERIOD, 
	MLV_KEYBOARD_SLASH = SDLK_SLASH, 
	MLV_KEYBOARD_0 = SDLK_0, 
	MLV_KEYBOARD_1 = SDLK_1, 
	MLV_KEYBOARD_2 = SDLK_2, 
	MLV_KEYBOARD_3 = SDLK_3, 
	MLV_KEYBOARD_4 = SDLK_4, 
	MLV_KEYBOARD_5 = SDLK_5, 
	MLV_KEYBOARD_6 = SDLK_6, 
	MLV_KEYBOARD_7 = SDLK_7, 
	MLV_KEYBOARD_8 = SDLK_8, 
	MLV_KEYBOARD_9 = SDLK_9, 
	MLV_KEYBOARD_COLON = SDLK_COLON, 
	MLV_KEYBOARD_SEMICOLON = SDLK_SEMICOLON, 
	MLV_KEYBOARD_LESS = SDLK_LESS, 
	MLV_KEYBOARD_EQUALS = SDLK_EQUALS, 
	MLV_KEYBOARD_GREATER = SDLK_GREATER, 
	MLV_KEYBOARD_QUESTION = SDLK_QUESTION, 
	MLV_KEYBOARD_AT = SDLK_AT, 

	MLV_KEYBOARD_LEFTBRACKET = SDLK_LEFTBRACKET, 
	MLV_KEYBOARD_BACKSLASH = SDLK_BACKSLASH, 
	MLV_KEYBOARD_RIGHTBRACKET = SDLK_RIGHTBRACKET, 
	MLV_KEYBOARD_CARET = SDLK_CARET, 
	MLV_KEYBOARD_UNDERSCORE = SDLK_UNDERSCORE, 
	MLV_KEYBOARD_BACKQUOTE = SDLK_BACKQUOTE, 
	MLV_KEYBOARD_a = SDLK_a, 
	MLV_KEYBOARD_b = SDLK_b, 
	MLV_KEYBOARD_c = SDLK_c, 
	MLV_KEYBOARD_d = SDLK_d, 
	MLV_KEYBOARD_e = SDLK_e, 
	MLV_KEYBOARD_f = SDLK_f, 
	MLV_KEYBOARD_g = SDLK_g, 
	MLV_KEYBOARD_h = SDLK_h, 
	MLV_KEYBOARD_i = SDLK_i, 
	MLV_KEYBOARD_j = SDLK_j, 
	MLV_KEYBOARD_k = SDLK_k, 
	MLV_KEYBOARD_l = SDLK_l, 
	MLV_KEYBOARD_m = SDLK_m, 
	MLV_KEYBOARD_n = SDLK_n, 
	MLV_KEYBOARD_o = SDLK_o, 
	MLV_KEYBOARD_p = SDLK_p, 
	MLV_KEYBOARD_q = SDLK_q, 
	MLV_KEYBOARD_r = SDLK_r, 
	MLV_KEYBOARD_s = SDLK_s, 
	MLV_KEYBOARD_t = SDLK_t, 
	MLV_KEYBOARD_u = SDLK_u, 
	MLV_KEYBOARD_v = SDLK_v, 
	MLV_KEYBOARD_w = SDLK_w, 
	MLV_KEYBOARD_x = SDLK_x, 
	MLV_KEYBOARD_y = SDLK_y, 
	MLV_KEYBOARD_z = SDLK_z, 
	MLV_KEYBOARD_DELETE = SDLK_DELETE, 

	MLV_KEYBOARD_KP0 = SDLK_KP_0, 
	MLV_KEYBOARD_KP1 = SDLK_KP_1, 
	MLV_KEYBOARD_KP2 = SDLK_KP_2, 
	MLV_KEYBOARD_KP3 = SDLK_KP_3, 
	MLV_KEYBOARD_KP4 = SDLK_KP_4, 
	MLV_KEYBOARD_KP5 = SDLK_KP_5, 
	MLV_KEYBOARD_KP6 = SDLK_KP_6, 
	MLV_KEYBOARD_KP7 = SDLK_KP_7, 
	MLV_KEYBOARD_KP8 = SDLK_KP_8, 
	MLV_KEYBOARD_KP9 = SDLK_KP_9, 
	MLV_KEYBOARD_KP_PERIOD = SDLK_KP_PERIOD, 
	MLV_KEYBOARD_KP_DIVIDE = SDLK_KP_DIVIDE, 
	MLV_KEYBOARD_KP_MULTIPLY = SDLK_KP_MULTIPLY, 
	MLV_KEYBOARD_KP_MINUS = SDLK_KP_MINUS, 
	MLV_KEYBOARD_KP_PLUS = SDLK_KP_PLUS, 
	MLV_KEYBOARD_KP_ENTER = SDLK_KP_ENTER, 
	MLV_KEYBOARD_KP_EQUALS = SDLK_KP_EQUALS, 

	MLV_KEYBOARD_UP = SDLK_UP, 
	MLV_KEYBOARD_DOWN = SDLK_DOWN, 
	MLV_KEYBOARD_RIGHT = SDLK_RIGHT, 
	MLV_KEYBOARD_LEFT = SDLK_LEFT, 
	MLV_KEYBOARD_INSERT = SDLK_INSERT, 
	MLV_KEYBOARD_HOME = SDLK_HOME, 
	MLV_KEYBOARD_END = SDLK_END, 
	MLV_KEYBOARD_PAGEUP = SDLK_PAGEUP, 
	MLV_KEYBOARD_PAGEDOWN = SDLK_PAGEDOWN, 

	MLV_KEYBOARD_F1 = SDLK_F1, 
	MLV_KEYBOARD_F2 = SDLK_F2, 
	MLV_KEYBOARD_F3 = SDLK_F3, 
	MLV_KEYBOARD_F4 = SDLK_F4, 
	MLV_KEYBOARD_F5 = SDLK_F5, 
	MLV_KEYBOARD_F6 = SDLK_F6, 
	MLV_KEYBOARD_F7 = SDLK_F7, 
	MLV_KEYBOARD_F8 = SDLK_F8, 
	MLV_KEYBOARD_F9 = SDLK_F9, 
	MLV_KEYBOARD_F10 = SDLK_F10, 
	MLV_KEYBOARD_F11 = SDLK_F11, 
	MLV_KEYBOARD_F12 = SDLK_F12, 
	MLV_KEYBOARD_F13 = SDLK_F13, 
	MLV_KEYBOARD_F14 = SDLK_F14, 
	MLV_KEYBOARD_F15 = SDLK_F15, 

	MLV_KEYBOARD_NUMLOCK = SDLK_NUMLOCKCLEAR, 
	MLV_KEYBOARD_CAPSLOCK = SDLK_CAPSLOCK, 
	MLV_KEYBOARD_SCROLLOCK = SDLK_SCROLLLOCK, 
	MLV_KEYBOARD_RSHIFT = SDLK_RSHIFT, 
	MLV_KEYBOARD_LSHIFT = SDLK_LSHIFT, 
	MLV_KEYBOARD_RCTRL = SDLK_RCTRL, 
	MLV_KEYBOARD_LCTRL = SDLK_LCTRL, 
	MLV_KEYBOARD_RALT = SDLK_RALT, 
	MLV_KEYBOARD_LALT = SDLK_LALT, 
	MLV_KEYBOARD_RMETA = SDLK_RGUI, 
	MLV_KEYBOARD_LMETA = SDLK_LGUI, 
	MLV_KEYBOARD_LSUPER = SDLK_LGUI, 
	MLV_KEYBOARD_RSUPER = SDLK_RGUI, 
	MLV_KEYBOARD_MODE = SDLK_MODE, 
	MLV_KEYBOARD_COMPOSE = SDLK_APPLICATION, 

	MLV_KEYBOARD_HELP = SDLK_HELP, 
	MLV_KEYBOARD_PRINT = SDLK_PRINTSCREEN, 
	MLV_KEYBOARD_SYSREQ = SDLK_SYSREQ, 
	MLV_KEYBOARD_BREAK = SDLK_PAUSE, 
	MLV_KEYBOARD_MENU = SDLK_MENU, 
	MLV_KEYBOARD_POWER = SDLK_POWER, 
	MLV_KEYBOARD_EURO = SDLK_CURRENCYUNIT, 
	MLV_KEYBOARD_UNDO = SDLK_UNDO, 
} MLV_Keyboard_button;

/** \~french 
 * \brief Énumère l'ensemble des codes associées aux différents modes du clavier
 */
typedef enum {
	MLV_KEYBOARD_KMOD_NONE = KMOD_NONE, 
	MLV_KEYBOARD_KMOD_LSHIFT = KMOD_LSHIFT, 
	MLV_KEYBOARD_KMOD_RSHIFT = KMOD_RSHIFT, 
	MLV_KEYBOARD_KMOD_LCTRL = KMOD_LCTRL, 
	MLV_KEYBOARD_KMOD_RCTRL = KMOD_RCTRL, 
	MLV_KEYBOARD_KMOD_LALT = KMOD_LALT, 
	MLV_KEYBOARD_KMOD_RALT = KMOD_RALT, 
	MLV_KEYBOARD_KMOD_LMETA = KMOD_LGUI, 
	MLV_KEYBOARD_KMOD_RMETA = KMOD_RGUI, 
	MLV_KEYBOARD_KMOD_NUM = KMOD_NUM, 
	MLV_KEYBOARD_KMOD_CAPS = KMOD_CAPS, 
	MLV_KEYBOARD_KMOD_MODE = KMOD_MODE, 
	MLV_KEYBOARD_KMOD_RESERVED = KMOD_RESERVED 
} MLV_Keyboard_modifier;

/** \~french 
 * \brief Suspend l'exécution jusqu'à ce que l'utilisateur appuie sur une touche
 *        du  clavier.
 * 
 * Lorsque l'utilisateur appuie sur une touche, la fonction remplit le contenu 
 * des trois paramètres sym, mod et unicode correspondant respectivement au 
 * code de la touche, au mode dans lequel se trouve le clavier 
 * (majuscule etc ...) et au caractère unicode obtenu en combinant le mode du 
 * clavier et le code de la touche appuyée.
 *
 * La fonction accepte des valeurs nulles pour les pointeurs sym, mod et 
 * unicode.
 * Dans ce cas la fonction ignore les champs en questions.
 *
 * \bug Voir les bugs de la fonction MLV_get_event().
 *
 * \param sym        Le code de la touche.
 * \param mod        Le mode dans lequel se trouve le clavier.
 * \param unicode    Le caractère codé en unicode de la lettre obtenue en combinant
 *                   le code et le mode précédent.
 */
void MLV_wait_keyboard( MLV_Keyboard_button* sym, MLV_Keyboard_modifier* mod, int* unicode );

/** \~french
 * \brief Renvoie le code de la touche clavier correspondant au type clavier
 *        passé en paramètre.
 *
 * \param key_string La chaine de caractères codant le type de la touche.
 *
 * \return Le code de la touche clavier.
 */
MLV_Keyboard_button MLV_convert_string_to_keyboard_button( const char* key_string );

/** \~french
 * \brief Renvoie la chaîne de caractères correspondant au code de la touche
 *        passé en paramètre.
 *
 * \param key_code Le code de la touche.
 *
 * \return La chaine de caractères codant le code de la touche.
 */
const char* MLV_convert_keyboard_button_to_string( MLV_Keyboard_button key_code );

/** \~french
 * \brief Renvoie la chaîne de caractères correspondant au mode du clavier
 *        passé en paramètre.
 *
 * \param keymod_code Le code du mode.
 *
 * \return La chaine de caractères codant le mode du clavier.
 */
char* MLV_convert_keyboard_mod_to_string( MLV_Keyboard_modifier keymod_code );


/** \~french
 *
 * \brief Renvoie l'état (préssé ou relaché) d'une touche donnée d'un clavier.
 *
 * \param keyboard_code Le code de la touche dont il faut renvoyer l'état.
 * \return L'état de la touche. 
 */
MLV_Button_state MLV_get_keyboard_state( MLV_Keyboard_button keyboard_code );

/** \~french
 *
 * \brief Renvoie vrai si le code, passé en paramètre, correspond à l'état appuyé de la touche de combinaison shift du clavier.
 *
 * \param modifier_code Le code de la touche de combinaison.
 * \return Vrai, si la touche de cobinaison shift a été appuyée.
 */
int MLV_shift_key_was_pressed( MLV_Keyboard_modifier modifier_code );

/** \~french
 *
 * \brief Renvoie vrai si le code, passé en paramètre, correspond à l'état appuyé de la touche de combinaison shift gauche du clavier.
 *
 * \param modifier_code Le code de la touche de combinaison.
 * \return Vrai, si la touche de cobinaison shift gauche a été appuyée.
 */
int MLV_left_shift_key_was_pressed( MLV_Keyboard_modifier modifier_code );

/** \~french
 *
 * \brief Renvoie vrai si le code, passé en paramètre, correspond à l'état appuyé de la touche de combinaison shift droit du clavier.
 *
 * \param modifier_code Le code de la touche de combinaison.
 * \return Vrai, si la touche de cobinaison shift droit a été appuyée.
 */
int MLV_right_shift_key_was_pressed( MLV_Keyboard_modifier modifier_code );

/** \~french
 *
 * \brief Renvoie vrai si le code, passé en paramètre, correspond à l'état appuyé de la touche de combinaison ctrl gauche du clavier.
 *
 * \param modifier_code Le code de la touche de combinaison.
 * \return Vrai, si la touche de cobinaison ctrl gauche a été appuyée.
 */
int MLV_left_ctrl_key_was_pressed( MLV_Keyboard_modifier modifier_code );

/** \~french
 *
 * \brief Renvoie vrai si le code, passé en paramètre, correspond à l'état appuyé de la touche de combinaison ctrl droit du clavier.
 *
 * \param modifier_code Le code de la touche de combinaison.
 * \return Vrai, si la touche de cobinaison ctrl droit a été appuyée.
 */
int MLV_right_ctrl_key_was_pressed( MLV_Keyboard_modifier modifier_code );

/** \~french
 *
 * \brief Renvoie vrai si le code, passé en paramètre, correspond à l'état appuyé de la touche de combinaison ctrl du clavier.
 *
 * \param modifier_code Le code de la touche de combinaison.
 * \return Vrai, si la touche de cobinaison ctrl a été appuyée.
 */
int MLV_ctrl_key_was_pressed( MLV_Keyboard_modifier modifier_code );

/** \~french
 *
 * \brief Renvoie vrai si le code, passé en paramètre, correspond à l'état appuyé de la touche de combinaison alt gauche du clavier.
 *
 * \param modifier_code Le code de la touche de combinaison.
 * \return Vrai, si la touche de cobinaison alt gauche a été appuyée.
 */
int MLV_left_alt_key_was_pressed( MLV_Keyboard_modifier modifier_code );

/** \~french
 *
 * \brief Renvoie vrai si le code, passé en paramètre, correspond à l'état appuyé de la touche de combinaison alt droit du clavier.
 *
 * \param modifier_code Le code de la touche de combinaison.
 * \return Vrai, si la touche de cobinaison alt droit a été appuyée.
 */
int MLV_right_alt_key_was_pressed( MLV_Keyboard_modifier modifier_code );

/** \~french
 *
 * \brief Renvoie vrai si le code, passé en paramètre, correspond à l'état appuyé de la touche de combinaison alt du clavier.
 *
 * \param modifier_code Le code de la touche de combinaison.
 * \return Vrai, si la touche de cobinaison alt a été appuyée.
 */
int MLV_alt_key_was_pressed( MLV_Keyboard_modifier modifier_code );

/** \~french
 *
 * \brief Renvoie vrai si le code, passé en paramètre, correspond à l'état appuyé de la touche de combinaison meta gauche du clavier.
 *
 * \param modifier_code Le code de la touche de combinaison.
 * \return Vrai, si la touche de cobinaison meta gauche a été appuyée.
 */
int MLV_left_meta_key_was_pressed( MLV_Keyboard_modifier modifier_code );

/** \~french
 *
 * \brief Renvoie vrai si le code, passé en paramètre, correspond à l'état appuyé de la touche de combinaison meta droit du clavier.
 *
 * \param modifier_code Le code de la touche de combinaison.
 * \return Vrai, si la touche de cobinaison meta droit a été appuyée.
 */
int MLV_right_meta_key_was_pressed( MLV_Keyboard_modifier modifier_code );

/** \~french
 *
 * \brief Renvoie vrai si le code, passé en paramètre, correspond à l'état appuyé de la touche de combinaison meta du clavier.
 *
 * \param modifier_code Le code de la touche de combinaison.
 * \return Vrai, si la touche de cobinaison meta a été appuyée.
 */
int MLV_meta_key_was_pressed( MLV_Keyboard_modifier modifier_code );

/** \~french
 *
 * \brief Renvoie vrai si le code, passé en paramètre, correspond à l'état appuyé de la touche de combinaison num du clavier.
 *
 * \param modifier_code Le code de la touche de combinaison.
 * \return Vrai, si la touche de cobinaison num a été appuyée.
 */
int MLV_num_key_was_pressed( MLV_Keyboard_modifier modifier_code );

/** \~french
 *
 * \brief Renvoie vrai si le code, passé en paramètre, correspond à l'état appuyé de la touche de combinaison cpas du clavier.
 *
 * \param modifier_code Le code de la touche de combinaison.
 * \return Vrai, si la touche de cobinaison caps a été appuyée.
 */
int MLV_caps_key_was_pressed( MLV_Keyboard_modifier modifier_code );

/** \~french
 *
 * \brief Renvoie vrai si le code, passé en paramètre, correspond à l'état appuyé de la touche de combinaison mode du clavier.
 *
 * \param modifier_code Le code de la touche de combinaison.
 * \return Vrai, si la touche de cobinaison mode a été appuyée.
 */
int MLV_mode_key_was_pressed( MLV_Keyboard_modifier modifier_code );


#ifdef __cplusplus
}
#endif

#endif
