// SONIC ROBO BLAST 2
//-----------------------------------------------------------------------------
// Copyright (C) 1993-1996 by id Software, Inc.
// Copyright (C) 1998-2000 by DooM Legacy Team.
// Copyright (C) 1999-2016 by Sonic Team Junior.
//
// This program is free software distributed under the
// terms of the GNU General Public License, version 2.
// See the 'LICENSE' file for more details.
//-----------------------------------------------------------------------------
/// \file  r_data.h
/// \brief Refresh module, data I/O, caching, retrieval of graphics by name

#ifndef __R_DATA__
#define __R_DATA__

#include "r_defs.h"
#include "r_state.h"

#ifdef __GNUG__
#pragma interface
#endif

// Possible alpha types for a patch.
enum patchalphastyle {AST_COPY, AST_TRANSLUCENT}; // , AST_ADD, AST_SUBTRACT, AST_REVERSESUBTRACT, AST_MODULATE, AST_OVERLAY};

// moved here for r_sky.c (texpatch_t is used)

// A single patch from a texture definition,
//  basically a rectangular area within
//  the texture rectangle.
typedef struct
{
	// Block origin (always UL), which has already accounted for the internal origin of the patch.
	INT16 originx, originy;
	UINT16 wad, lump;
	UINT8 flip; // 1 = flipx, 2 = flipy, 3 = both
	UINT8 alpha; // Translucency value
	enum patchalphastyle style;
} texpatch_t;

// A maptexturedef_t describes a rectangular texture,
//  which is composed of one or more mappatch_t structures
//  that arrange graphic patches.
typedef struct
{
	// Keep name for switch changing, etc.
	char name[8];
	INT16 width, height;
	boolean holes;
	UINT8 flip; // 1 = flipx, 2 = flipy, 3 = both

	// All the patches[patchcount] are drawn back to front into the cached texture.
	INT16 patchcount;
	texpatch_t patches[0];
} texture_t;

// all loaded and prepared textures from the start of the game
extern texture_t **textures;

// texture width is a power of 2, so it can easily repeat along sidedefs using a simple mask
extern INT32 *texturewidthmask;

extern fixed_t *textureheight; // needed for texture pegging

extern INT16 color8to16[256]; // remap color index to highcolor
extern INT16 *hicolormaps; // remap high colors to high colors..

extern CV_PossibleValue_t Color_cons_t[];

// Load TEXTURES definitions, create lookup tables
void R_LoadTextures(void);
void R_FlushTextureCache(void);

INT32 R_GetTextureNum(INT32 texnum);
void R_CheckTextureCache(INT32 tex);

// Retrieve column data for span blitting.
UINT8 *R_GetColumn(fixed_t tex, INT32 col);

UINT8 *R_GetFlat(lumpnum_t flatnum);

// I/O, setting up the stuff.
void R_InitData(void);
void R_PrecacheLevel(void);

// Retrieval.
// Floor/ceiling opaque texture tiles,
// lookup by name. For animation?
lumpnum_t R_GetFlatNumForName(const char *name);
#define R_FlatNumForName(x) R_GetFlatNumForName(x)

// Called by P_Ticker for switches and animations,
// returns the texture number for the texture name.
void R_ClearTextureNumCache(boolean btell);
INT32 R_TextureNumForName(const char *name);
INT32 R_CheckTextureNumForName(const char *name);

// Extra Colormap lumps (C_START/C_END) are not used anywhere
// Uncomment to enable
//#define EXTRACOLORMAPLUMPS

// Uncomment to make extra_colormaps order Newest -> Oldest
//#define COLORMAPREVERSELIST

void R_ReInitColormaps(UINT16 num);
void R_ClearColormaps(void);
extracolormap_t *R_CreateDefaultColormap(boolean lighttable);
extracolormap_t *R_GetDefaultColormap(void);
extracolormap_t *R_CopyColormap(extracolormap_t *extra_colormap, boolean lighttable);
void R_AddColormapToList(extracolormap_t *extra_colormap);
boolean R_CheckDefaultColormapValues(extracolormap_t *extra_colormap, boolean checkrgba, boolean checkfadergba, boolean checkparams);
lighttable_t *R_CreateLightTable(extracolormap_t *extra_colormap);
extracolormap_t *R_CreateColormap(char *p1, char *p2, char *p3);
#ifdef EXTRACOLORMAPLUMPS
extracolormap_t *R_ColormapForName(char *name);
const char *R_NameForColormap(extracolormap_t *extra_colormap);
#endif

extern INT32 numtextures;

#endif
