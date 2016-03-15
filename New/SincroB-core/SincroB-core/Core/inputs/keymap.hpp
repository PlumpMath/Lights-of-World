#pragma once

/*
 
 Mapa do teclado para ser usado nas funções isKeyPressed, declarado no modulo window.hpp
 na classe Window;
 
*/

#define UNKNOWNKEY            -1

/* Teclas de escrita */
#define SPACEKEY              32
#define APOSTROPHEKEY         39  /* ' */
#define COMMAKEY              44  /* , */
#define MINUSKEY              45  /* - */
#define PERIODKEY             46  /* . */
#define SLASHKEY              47  /* / */

// Numeros;
#define NUMPAD0KEY            48
#define NUMPAD1KEY            49
#define NUMPAD2KEY            50
#define NUMPAD3KEY            51
#define NUMPAD4KEY            52
#define NUMPAD5KEY            53
#define NUMPAD6KEY            54
#define NUMPAD7KEY            55
#define NUMPAD8KEY            56
#define NUMPAD9KEY            57

// Letras a Acentuações;
#define SEMICOLONKEY          59  /* ; */
#define EQUALKEY              61  /* = */
#define AKEY                  65
#define BKEY                  66
#define CKEY                  67
#define DKEY                  68
#define EKEY                  69
#define FKEY                  70
#define GKEY                  71
#define HKEY                  72
#define IKEY                  73
#define JKEY                  74
#define KKEY                  75
#define LKEY                  76
#define MKEY                  77
#define NKEY                  78
#define OKEY                  79
#define PKEY                  80
#define QKEY                  81
#define RKEY                  82
#define SKEY                  83
#define TKEY                  84
#define UKEY                  85
#define VKEY                  86
#define WKEY                  87
#define XKEY                  88
#define YKEY                  89
#define ZKEY                  90
#define LEFTBRACKETKEY        91  /*     [     */
#define RIGHTBRACKETKEY       93  /*     ]     */
#define BACKSLASHKEY          92  /*     \     */
#define GRAVEACCENTKEY        96  /*     `     */
#define WORLD1KEY             161 /* non-US #1 */
#define WORLD2KEY             162 /* non-US #2 */

// Setas
#define RIGHTARROWKEY         262
#define LEFTARROWKEY          263
#define DOWNARROWKEY          264
#define UPARROWKEY            265

// Teclas de Função;
#define ESQKEY                256
#define ENTERKEY              257
#define TABKEY                258
#define BACKSPACEKEY          259
#define INSERTKEY             260
#define DELETEKEY             261

#define PAGEUPKEY             266
#define PAGEDOWNKEY           267
#define HOMEKEY               268 // Windows (botão home) Mac (NÃO exerce função);
#define ENDKEY                269
#define CAPSLOCKKEY           280
#define SCROLLLOCKKEY         281
#define NUMLOCKKEY            282
#define PRINTSCREENKEY        283 // Windows (botão printscreen) Mac (NÃO exerce função);
#define PAUSEKEY              284 // Windows (botão pause) Mac (NÃO exerce função);

// Funcionais;
#define F1KEY                 290
#define F2KEY                 291
#define F3KEY                 292
#define F4KEY                 293
#define F5KEY                 294
#define F6KEY                 295
#define F7KEY                 296
#define F8KEY                 297
#define F9KEY                 298
#define F10KEY                299
#define F11KEY                300
#define F12KEY                301
#define F13KEY                302
#define F14KEY                303
#define F16KEY                304
#define F17KEY                305
#define F18KEY                306
#define F19KEY                307
#define F20KEY                308
#define F21KEY                309
#define F22KEY                310
#define F23KEY                311
#define F24KEY                312
#define F25KEY                313
#define F26KEY                314

#define KP0KEY                320
#define KP1KEY                321
#define KP2KEY                322
#define KP3KEY                323
#define KP4KEY                324
#define KP5KEY                325
#define KP6KEY                326
#define KP7KEY                327
#define KP8KEY                328
#define KP9KEY                329
#define KPDECIMALKEY          330
#define KPDIVIDEKEY           331
#define KPMULTIPLYKEY         332
#define KPSUBTRACTKEY         333
#define KPADDKEY              334
#define KPENTERKEY            335
#define KPEQUALKEY            336

#define LEFTSHIFTKEY          340
#define LEFTCONTROLKEY        341
#define LEFTALTKEY            342
#define LEFTSUPERKEY          343

#define RIGHTSHIFTKEY         344
#define RIGHTCONTROLKEY       345
#define RIGHTALTKEY           346
#define RIGHTSUPERKEY         347

#define MENUKEY               348
#define LASTKEY               MENUKEY

// Teclas Modificadoras;
#define MODSHIFT              0x0001
#define MODCONTROL            0x0002
#define MODALT                0x0004
#define MODSUPER              0x0008 // Command ou Tecla Windows;
