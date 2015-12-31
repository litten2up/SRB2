// SONIC ROBO BLAST 2
//-----------------------------------------------------------------------------
// Copyright (C) 1993-1996 by id Software, Inc.
// Copyright (C) 1998-2000 by DooM Legacy Team.
// Copyright (C) 1999-2014 by Sonic Team Junior.
//
// This program is free software distributed under the
// terms of the GNU General Public License, version 2.
// See the 'LICENSE' file for more details.
//-----------------------------------------------------------------------------
/// \file  sounds.h
/// \brief Sound and music info

#ifndef __SOUNDS__
#define __SOUNDS__

// Customisable sounds for Skins
typedef enum
{
	SKSSPIN,
	SKSPUTPUT,
	SKSPUDPUD,
	SKSPLPAN1, // Ouchies
	SKSPLPAN2,
	SKSPLPAN3,
	SKSPLPAN4,
	SKSPLDET1, // Deaths
	SKSPLDET2,
	SKSPLDET3,
	SKSPLDET4,
	SKSPLVCT1, // Victories
	SKSPLVCT2,
	SKSPLVCT3,
	SKSPLVCT4,
	SKSTHOK,
	SKSSPNDSH,
	SKSZOOM,
	SKSSKID,
	SKSGASP,
	SKSJUMP,
	NUMSKINSOUNDS
} skinsound_t;

// free sfx for S_AddSoundFx()
#define NUMSFXFREESLOTS 800 // Matches SOC Editor.
#define NUMSKINSFXSLOTS (MAXSKINS*NUMSKINSOUNDS)

//
// SoundFX struct.
//
typedef struct sfxinfo_struct sfxinfo_t;

struct sfxinfo_struct
{
	// up to 6-character name
	const char *name;

	// Sfx singularity (only one at a time)
	boolean singularity;

	// Sfx priority
	INT32 priority;

	// pitch if a link
	INT32 pitch;

	// volume if a link
	INT32 volume;

	// sound data
	void *data;

	// length of sound data
	size_t length;

	// sound that can be remapped for a skin, indexes skins[].skinsounds
	// 0 up to (NUMSKINSOUNDS-1), -1 = not skin specifc
	INT32 skinsound;

	// this is checked every second to see if sound
	// can be thrown out (if 0, then decrement, if -1,
	// then throw out, if > 0, then it is in use)
	INT32 usefulness;

	// lump number of sfx
	lumpnum_t lumpnum;
};

//
// MusicInfo struct.
//
typedef struct
{
	// up to 6-character name
	const char *name;

	// lump number of music
	lumpnum_t lumpnum;

	// music data
	void *data;

	// music handle once registered
	INT32 handle;
} musicinfo_t;

// the complete set of sound effects
extern sfxinfo_t S_sfx[];

// the complete set of music
extern musicinfo_t S_music[];

//
// Identifiers for all music in game.
//

// Music list (don't edit this comment!)
typedef enum
{
	mus_None,
	mus_map01m,
	mus_map02m,
	mus_map03m,
	mus_map04m,
	mus_map05m,
	mus_map06m,
	mus_map07m,
	mus_map08m,
	mus_map09m,
	mus_map10m,
	mus_map11m,
	mus_map12m,
	mus_map13m,
	mus_map14m,
	mus_map15m,
	mus_map16m,
	mus_map17m,
	mus_map18m,
	mus_map19m,
	mus_map20m,
	mus_map21m,
	mus_map22m,
	mus_map23m,
	mus_map24m,
	mus_map25m,
	mus_map26m,
	mus_map27m,
	mus_map28m,
	mus_map29m,
	mus_map30m,
	mus_map31m,
	mus_map32m,
	mus_map33m,
	mus_map34m,
	mus_map35m,
	mus_map36m,
	mus_map37m,
	mus_map38m,
	mus_map39m,
	mus_map40m,
	mus_map41m,
	mus_map42m,
	mus_map43m,
	mus_map44m,
	mus_map45m,
	mus_map46m,
	mus_map47m,
	mus_map48m,
	mus_map49m,
	mus_map50m,
	mus_map51m,
	mus_map52m,
	mus_map53m,
	mus_map54m,
	mus_map55m,
	mus_map56m,
	mus_map57m,
	mus_map58m,
	mus_map59m,
	mus_map60m,
	mus_map61m,
	mus_map62m,
	mus_map63m,
	mus_map64m,
	mus_map65m,
	mus_map66m,
	mus_map67m,
	mus_map68m,
	mus_map69m,
	mus_map70m,
	mus_map71m,
	mus_map72m,
	mus_map73m,
	mus_map74m,
	mus_map75m,
	mus_map76m,
	mus_map77m,
	mus_map78m,
	mus_map79m,
	mus_map80m,
	mus_map81m,
	mus_map82m,
	mus_map83m,
	mus_map84m,
	mus_map85m,
	mus_map86m,
	mus_map87m,
	mus_map88m,
	mus_map89m,
	mus_map90m,
	mus_map91m,
	mus_map92m,
	mus_map93m,
	mus_map94m,
	mus_map95m,
	mus_map96m,
	mus_map97m,
	mus_map98m,
	mus_map99m,
	mus_mapa0m,
	mus_mapa1m,
	mus_mapa2m,
	mus_mapa3m,
	mus_mapa4m,
	mus_mapa5m,
	mus_mapa6m,
	mus_mapa7m,
	mus_mapa8m,
	mus_mapa9m,
	mus_mapaam,
	mus_mapabm,
	mus_mapacm,
	mus_mapadm,
	mus_mapaem,
	mus_mapafm,
	mus_mapagm,
	mus_mapahm,
	mus_mapaim,
	mus_mapajm,
	mus_mapakm,
	mus_mapalm,
	mus_mapamm,
	mus_mapanm,
	mus_mapaom,
	mus_mapapm,
	mus_mapaqm,
	mus_maparm,
	mus_mapasm,
	mus_mapatm,
	mus_mapaum,
	mus_mapavm,
	mus_mapawm,
	mus_mapaxm,
	mus_mapaym,
	mus_mapazm,
	mus_mapb0m,
	mus_mapb1m,
	mus_mapb2m,
	mus_mapb3m,
	mus_mapb4m,
	mus_mapb5m,
	mus_mapb6m,
	mus_mapb7m,
	mus_mapb8m,
	mus_mapb9m,
	mus_mapbam,
	mus_mapbbm,
	mus_mapbcm,
	mus_mapbdm,
	mus_mapbem,
	mus_mapbfm,
	mus_mapbgm,
	mus_mapbhm,
	mus_mapbim,
	mus_mapbjm,
	mus_mapbkm,
	mus_mapblm,
	mus_mapbmm,
	mus_mapbnm,
	mus_mapbom,
	mus_mapbpm,
	mus_mapbqm,
	mus_mapbrm,
	mus_mapbsm,
	mus_mapbtm,
	mus_mapbum,
	mus_mapbvm,
	mus_mapbwm,
	mus_mapbxm,
	mus_mapbym,
	mus_mapbzm,
	mus_mapc0m,
	mus_mapc1m,
	mus_mapc2m,
	mus_mapc3m,
	mus_mapc4m,
	mus_mapc5m,
	mus_mapc6m,
	mus_mapc7m,
	mus_mapc8m,
	mus_mapc9m,
	mus_mapcam,
	mus_mapcbm,
	mus_mapccm,
	mus_mapcdm,
	mus_mapcem,
	mus_mapcfm,
	mus_mapcgm,
	mus_mapchm,
	mus_mapcim,
	mus_mapcjm,
	mus_mapckm,
	mus_mapclm,
	mus_mapcmm,
	mus_mapcnm,
	mus_mapcom,
	mus_mapcpm,
	mus_mapcqm,
	mus_mapcrm,
	mus_mapcsm,
	mus_mapctm,
	mus_mapcum,
	mus_mapcvm,
	mus_mapcwm,
	mus_mapcxm,
	mus_mapcym,
	mus_mapczm,
	mus_mapd0m,
	mus_mapd1m,
	mus_mapd2m,
	mus_mapd3m,
	mus_mapd4m,
	mus_mapd5m,
	mus_mapd6m,
	mus_mapd7m,
	mus_mapd8m,
	mus_mapd9m,
	mus_mapdam,
	mus_mapdbm,
	mus_mapdcm,
	mus_mapddm,
	mus_mapdem,
	mus_mapdfm,
	mus_mapdgm,
	mus_mapdhm,
	mus_mapdim,
	mus_mapdjm,
	mus_mapdkm,
	mus_mapdlm,
	mus_mapdmm,
	mus_mapdnm,
	mus_mapdom,
	mus_mapdpm,
	mus_mapdqm,
	mus_mapdrm,
	mus_mapdsm,
	mus_mapdtm,
	mus_mapdum,
	mus_mapdvm,
	mus_mapdwm,
	mus_mapdxm,
	mus_mapdym,
	mus_mapdzm,
	mus_mape0m,
	mus_mape1m,
	mus_mape2m,
	mus_mape3m,
	mus_mape4m,
	mus_mape5m,
	mus_mape6m,
	mus_mape7m,
	mus_mape8m,
	mus_mape9m,
	mus_mapeam,
	mus_mapebm,
	mus_mapecm,
	mus_mapedm,
	mus_mapeem,
	mus_mapefm,
	mus_mapegm,
	mus_mapehm,
	mus_mapeim,
	mus_mapejm,
	mus_mapekm,
	mus_mapelm,
	mus_mapemm,
	mus_mapenm,
	mus_mapeom,
	mus_mapepm,
	mus_mapeqm,
	mus_maperm,
	mus_mapesm,
	mus_mapetm,
	mus_mapeum,
	mus_mapevm,
	mus_mapewm,
	mus_mapexm,
	mus_mapeym,
	mus_mapezm,
	mus_mapf0m,
	mus_mapf1m,
	mus_mapf2m,
	mus_mapf3m,
	mus_mapf4m,
	mus_mapf5m,
	mus_mapf6m,
	mus_mapf7m,
	mus_mapf8m,
	mus_mapf9m,
	mus_mapfam,
	mus_mapfbm,
	mus_mapfcm,
	mus_mapfdm,
	mus_mapfem,
	mus_mapffm,
	mus_mapfgm,
	mus_mapfhm,
	mus_mapfim,
	mus_mapfjm,
	mus_mapfkm,
	mus_mapflm,
	mus_mapfmm,
	mus_mapfnm,
	mus_mapfom,
	mus_mapfpm,
	mus_mapfqm,
	mus_mapfrm,
	mus_mapfsm,
	mus_mapftm,
	mus_mapfum,
	mus_mapfvm,
	mus_mapfwm,
	mus_mapfxm,
	mus_mapfym,
	mus_mapfzm,
	mus_mapg0m,
	mus_mapg1m,
	mus_mapg2m,
	mus_mapg3m,
	mus_mapg4m,
	mus_mapg5m,
	mus_mapg6m,
	mus_mapg7m,
	mus_mapg8m,
	mus_mapg9m,
	mus_mapgam,
	mus_mapgbm,
	mus_mapgcm,
	mus_mapgdm,
	mus_mapgem,
	mus_mapgfm,
	mus_mapggm,
	mus_mapghm,
	mus_mapgim,
	mus_mapgjm,
	mus_mapgkm,
	mus_mapglm,
	mus_mapgmm,
	mus_mapgnm,
	mus_mapgom,
	mus_mapgpm,
	mus_mapgqm,
	mus_mapgrm,
	mus_mapgsm,
	mus_mapgtm,
	mus_mapgum,
	mus_mapgvm,
	mus_mapgwm,
	mus_mapgxm,
	mus_mapgym,
	mus_mapgzm,
	mus_maph0m,
	mus_maph1m,
	mus_maph2m,
	mus_maph3m,
	mus_maph4m,
	mus_maph5m,
	mus_maph6m,
	mus_maph7m,
	mus_maph8m,
	mus_maph9m,
	mus_mapham,
	mus_maphbm,
	mus_maphcm,
	mus_maphdm,
	mus_maphem,
	mus_maphfm,
	mus_maphgm,
	mus_maphhm,
	mus_maphim,
	mus_maphjm,
	mus_maphkm,
	mus_maphlm,
	mus_maphmm,
	mus_maphnm,
	mus_maphom,
	mus_maphpm,
	mus_maphqm,
	mus_maphrm,
	mus_maphsm,
	mus_maphtm,
	mus_maphum,
	mus_maphvm,
	mus_maphwm,
	mus_maphxm,
	mus_maphym,
	mus_maphzm,
	mus_mapi0m,
	mus_mapi1m,
	mus_mapi2m,
	mus_mapi3m,
	mus_mapi4m,
	mus_mapi5m,
	mus_mapi6m,
	mus_mapi7m,
	mus_mapi8m,
	mus_mapi9m,
	mus_mapiam,
	mus_mapibm,
	mus_mapicm,
	mus_mapidm,
	mus_mapiem,
	mus_mapifm,
	mus_mapigm,
	mus_mapihm,
	mus_mapiim,
	mus_mapijm,
	mus_mapikm,
	mus_mapilm,
	mus_mapimm,
	mus_mapinm,
	mus_mapiom,
	mus_mapipm,
	mus_mapiqm,
	mus_mapirm,
	mus_mapism,
	mus_mapitm,
	mus_mapium,
	mus_mapivm,
	mus_mapiwm,
	mus_mapixm,
	mus_mapiym,
	mus_mapizm,
	mus_mapj0m,
	mus_mapj1m,
	mus_mapj2m,
	mus_mapj3m,
	mus_mapj4m,
	mus_mapj5m,
	mus_mapj6m,
	mus_mapj7m,
	mus_mapj8m,
	mus_mapj9m,
	mus_mapjam,
	mus_mapjbm,
	mus_mapjcm,
	mus_mapjdm,
	mus_mapjem,
	mus_mapjfm,
	mus_mapjgm,
	mus_mapjhm,
	mus_mapjim,
	mus_mapjjm,
	mus_mapjkm,
	mus_mapjlm,
	mus_mapjmm,
	mus_mapjnm,
	mus_mapjom,
	mus_mapjpm,
	mus_mapjqm,
	mus_mapjrm,
	mus_mapjsm,
	mus_mapjtm,
	mus_mapjum,
	mus_mapjvm,
	mus_mapjwm,
	mus_mapjxm,
	mus_mapjym,
	mus_mapjzm,
	mus_mapk0m,
	mus_mapk1m,
	mus_mapk2m,
	mus_mapk3m,
	mus_mapk4m,
	mus_mapk5m,
	mus_mapk6m,
	mus_mapk7m,
	mus_mapk8m,
	mus_mapk9m,
	mus_mapkam,
	mus_mapkbm,
	mus_mapkcm,
	mus_mapkdm,
	mus_mapkem,
	mus_mapkfm,
	mus_mapkgm,
	mus_mapkhm,
	mus_mapkim,
	mus_mapkjm,
	mus_mapkkm,
	mus_mapklm,
	mus_mapkmm,
	mus_mapknm,
	mus_mapkom,
	mus_mapkpm,
	mus_mapkqm,
	mus_mapkrm,
	mus_mapksm,
	mus_mapktm,
	mus_mapkum,
	mus_mapkvm,
	mus_mapkwm,
	mus_mapkxm,
	mus_mapkym,
	mus_mapkzm,
	mus_mapl0m,
	mus_mapl1m,
	mus_mapl2m,
	mus_mapl3m,
	mus_mapl4m,
	mus_mapl5m,
	mus_mapl6m,
	mus_mapl7m,
	mus_mapl8m,
	mus_mapl9m,
	mus_maplam,
	mus_maplbm,
	mus_maplcm,
	mus_mapldm,
	mus_maplem,
	mus_maplfm,
	mus_maplgm,
	mus_maplhm,
	mus_maplim,
	mus_mapljm,
	mus_maplkm,
	mus_mapllm,
	mus_maplmm,
	mus_maplnm,
	mus_maplom,
	mus_maplpm,
	mus_maplqm,
	mus_maplrm,
	mus_maplsm,
	mus_mapltm,
	mus_maplum,
	mus_maplvm,
	mus_maplwm,
	mus_maplxm,
	mus_maplym,
	mus_maplzm,
	mus_mapm0m,
	mus_mapm1m,
	mus_mapm2m,
	mus_mapm3m,
	mus_mapm4m,
	mus_mapm5m,
	mus_mapm6m,
	mus_mapm7m,
	mus_mapm8m,
	mus_mapm9m,
	mus_mapmam,
	mus_mapmbm,
	mus_mapmcm,
	mus_mapmdm,
	mus_mapmem,
	mus_mapmfm,
	mus_mapmgm,
	mus_mapmhm,
	mus_mapmim,
	mus_mapmjm,
	mus_mapmkm,
	mus_mapmlm,
	mus_mapmmm,
	mus_mapmnm,
	mus_mapmom,
	mus_mapmpm,
	mus_mapmqm,
	mus_mapmrm,
	mus_mapmsm,
	mus_mapmtm,
	mus_mapmum,
	mus_mapmvm,
	mus_mapmwm,
	mus_mapmxm,
	mus_mapmym,
	mus_mapmzm,
	mus_mapn0m,
	mus_mapn1m,
	mus_mapn2m,
	mus_mapn3m,
	mus_mapn4m,
	mus_mapn5m,
	mus_mapn6m,
	mus_mapn7m,
	mus_mapn8m,
	mus_mapn9m,
	mus_mapnam,
	mus_mapnbm,
	mus_mapncm,
	mus_mapndm,
	mus_mapnem,
	mus_mapnfm,
	mus_mapngm,
	mus_mapnhm,
	mus_mapnim,
	mus_mapnjm,
	mus_mapnkm,
	mus_mapnlm,
	mus_mapnmm,
	mus_mapnnm,
	mus_mapnom,
	mus_mapnpm,
	mus_mapnqm,
	mus_mapnrm,
	mus_mapnsm,
	mus_mapntm,
	mus_mapnum,
	mus_mapnvm,
	mus_mapnwm,
	mus_mapnxm,
	mus_mapnym,
	mus_mapnzm,
	mus_mapo0m,
	mus_mapo1m,
	mus_mapo2m,
	mus_mapo3m,
	mus_mapo4m,
	mus_mapo5m,
	mus_mapo6m,
	mus_mapo7m,
	mus_mapo8m,
	mus_mapo9m,
	mus_mapoam,
	mus_mapobm,
	mus_mapocm,
	mus_mapodm,
	mus_mapoem,
	mus_mapofm,
	mus_mapogm,
	mus_mapohm,
	mus_mapoim,
	mus_mapojm,
	mus_mapokm,
	mus_mapolm,
	mus_mapomm,
	mus_maponm,
	mus_mapoom,
	mus_mapopm,
	mus_mapoqm,
	mus_maporm,
	mus_maposm,
	mus_mapotm,
	mus_mapoum,
	mus_mapovm,
	mus_mapowm,
	mus_mapoxm,
	mus_mapoym,
	mus_mapozm,
	mus_mapp0m,
	mus_mapp1m,
	mus_mapp2m,
	mus_mapp3m,
	mus_mapp4m,
	mus_mapp5m,
	mus_mapp6m,
	mus_mapp7m,
	mus_mapp8m,
	mus_mapp9m,
	mus_mappam,
	mus_mappbm,
	mus_mappcm,
	mus_mappdm,
	mus_mappem,
	mus_mappfm,
	mus_mappgm,
	mus_mapphm,
	mus_mappim,
	mus_mappjm,
	mus_mappkm,
	mus_mapplm,
	mus_mappmm,
	mus_mappnm,
	mus_mappom,
	mus_mapppm,
	mus_mappqm,
	mus_mapprm,
	mus_mappsm,
	mus_mapptm,
	mus_mappum,
	mus_mappvm,
	mus_mappwm,
	mus_mappxm,
	mus_mappym,
	mus_mappzm,
	mus_mapq0m,
	mus_mapq1m,
	mus_mapq2m,
	mus_mapq3m,
	mus_mapq4m,
	mus_mapq5m,
	mus_mapq6m,
	mus_mapq7m,
	mus_mapq8m,
	mus_mapq9m,
	mus_mapqam,
	mus_mapqbm,
	mus_mapqcm,
	mus_mapqdm,
	mus_mapqem,
	mus_mapqfm,
	mus_mapqgm,
	mus_mapqhm,
	mus_mapqim,
	mus_mapqjm,
	mus_mapqkm,
	mus_mapqlm,
	mus_mapqmm,
	mus_mapqnm,
	mus_mapqom,
	mus_mapqpm,
	mus_mapqqm,
	mus_mapqrm,
	mus_mapqsm,
	mus_mapqtm,
	mus_mapqum,
	mus_mapqvm,
	mus_mapqwm,
	mus_mapqxm,
	mus_mapqym,
	mus_mapqzm,
	mus_mapr0m,
	mus_mapr1m,
	mus_mapr2m,
	mus_mapr3m,
	mus_mapr4m,
	mus_mapr5m,
	mus_mapr6m,
	mus_mapr7m,
	mus_mapr8m,
	mus_mapr9m,
	mus_mapram,
	mus_maprbm,
	mus_maprcm,
	mus_maprdm,
	mus_maprem,
	mus_maprfm,
	mus_maprgm,
	mus_maprhm,
	mus_maprim,
	mus_maprjm,
	mus_maprkm,
	mus_maprlm,
	mus_maprmm,
	mus_maprnm,
	mus_maprom,
	mus_maprpm,
	mus_maprqm,
	mus_maprrm,
	mus_maprsm,
	mus_maprtm,
	mus_maprum,
	mus_maprvm,
	mus_maprwm,
	mus_maprxm,
	mus_maprym,
	mus_maprzm,
	mus_maps0m,
	mus_maps1m,
	mus_maps2m,
	mus_maps3m,
	mus_maps4m,
	mus_maps5m,
	mus_maps6m,
	mus_maps7m,
	mus_maps8m,
	mus_maps9m,
	mus_mapsam,
	mus_mapsbm,
	mus_mapscm,
	mus_mapsdm,
	mus_mapsem,
	mus_mapsfm,
	mus_mapsgm,
	mus_mapshm,
	mus_mapsim,
	mus_mapsjm,
	mus_mapskm,
	mus_mapslm,
	mus_mapsmm,
	mus_mapsnm,
	mus_mapsom,
	mus_mapspm,
	mus_mapsqm,
	mus_mapsrm,
	mus_mapssm,
	mus_mapstm,
	mus_mapsum,
	mus_mapsvm,
	mus_mapswm,
	mus_mapsxm,
	mus_mapsym,
	mus_mapszm,
	mus_mapt0m,
	mus_mapt1m,
	mus_mapt2m,
	mus_mapt3m,
	mus_mapt4m,
	mus_mapt5m,
	mus_mapt6m,
	mus_mapt7m,
	mus_mapt8m,
	mus_mapt9m,
	mus_maptam,
	mus_maptbm,
	mus_maptcm,
	mus_maptdm,
	mus_maptem,
	mus_maptfm,
	mus_maptgm,
	mus_mapthm,
	mus_maptim,
	mus_maptjm,
	mus_maptkm,
	mus_maptlm,
	mus_maptmm,
	mus_maptnm,
	mus_maptom,
	mus_maptpm,
	mus_maptqm,
	mus_maptrm,
	mus_maptsm,
	mus_mapttm,
	mus_maptum,
	mus_maptvm,
	mus_maptwm,
	mus_maptxm,
	mus_maptym,
	mus_maptzm,
	mus_mapu0m,
	mus_mapu1m,
	mus_mapu2m,
	mus_mapu3m,
	mus_mapu4m,
	mus_mapu5m,
	mus_mapu6m,
	mus_mapu7m,
	mus_mapu8m,
	mus_mapu9m,
	mus_mapuam,
	mus_mapubm,
	mus_mapucm,
	mus_mapudm,
	mus_mapuem,
	mus_mapufm,
	mus_mapugm,
	mus_mapuhm,
	mus_mapuim,
	mus_mapujm,
	mus_mapukm,
	mus_mapulm,
	mus_mapumm,
	mus_mapunm,
	mus_mapuom,
	mus_mapupm,
	mus_mapuqm,
	mus_mapurm,
	mus_mapusm,
	mus_maputm,
	mus_mapuum,
	mus_mapuvm,
	mus_mapuwm,
	mus_mapuxm,
	mus_mapuym,
	mus_mapuzm,
	mus_mapv0m,
	mus_mapv1m,
	mus_mapv2m,
	mus_mapv3m,
	mus_mapv4m,
	mus_mapv5m,
	mus_mapv6m,
	mus_mapv7m,
	mus_mapv8m,
	mus_mapv9m,
	mus_mapvam,
	mus_mapvbm,
	mus_mapvcm,
	mus_mapvdm,
	mus_mapvem,
	mus_mapvfm,
	mus_mapvgm,
	mus_mapvhm,
	mus_mapvim,
	mus_mapvjm,
	mus_mapvkm,
	mus_mapvlm,
	mus_mapvmm,
	mus_mapvnm,
	mus_mapvom,
	mus_mapvpm,
	mus_mapvqm,
	mus_mapvrm,
	mus_mapvsm,
	mus_mapvtm,
	mus_mapvum,
	mus_mapvvm,
	mus_mapvwm,
	mus_mapvxm,
	mus_mapvym,
	mus_mapvzm,
	mus_mapw0m,
	mus_mapw1m,
	mus_mapw2m,
	mus_mapw3m,
	mus_mapw4m,
	mus_mapw5m,
	mus_mapw6m,
	mus_mapw7m,
	mus_mapw8m,
	mus_mapw9m,
	mus_mapwam,
	mus_mapwbm,
	mus_mapwcm,
	mus_mapwdm,
	mus_mapwem,
	mus_mapwfm,
	mus_mapwgm,
	mus_mapwhm,
	mus_mapwim,
	mus_mapwjm,
	mus_mapwkm,
	mus_mapwlm,
	mus_mapwmm,
	mus_mapwnm,
	mus_mapwom,
	mus_mapwpm,
	mus_mapwqm,
	mus_mapwrm,
	mus_mapwsm,
	mus_mapwtm,
	mus_mapwum,
	mus_mapwvm,
	mus_mapwwm,
	mus_mapwxm,
	mus_mapwym,
	mus_mapwzm,
	mus_mapx0m,
	mus_mapx1m,
	mus_mapx2m,
	mus_mapx3m,
	mus_mapx4m,
	mus_mapx5m,
	mus_mapx6m,
	mus_mapx7m,
	mus_mapx8m,
	mus_mapx9m,
	mus_mapxam,
	mus_mapxbm,
	mus_mapxcm,
	mus_mapxdm,
	mus_mapxem,
	mus_mapxfm,
	mus_mapxgm,
	mus_mapxhm,
	mus_mapxim,
	mus_mapxjm,
	mus_mapxkm,
	mus_mapxlm,
	mus_mapxmm,
	mus_mapxnm,
	mus_mapxom,
	mus_mapxpm,
	mus_mapxqm,
	mus_mapxrm,
	mus_mapxsm,
	mus_mapxtm,
	mus_mapxum,
	mus_mapxvm,
	mus_mapxwm,
	mus_mapxxm,
	mus_mapxym,
	mus_mapxzm,
	mus_mapy0m,
	mus_mapy1m,
	mus_mapy2m,
	mus_mapy3m,
	mus_mapy4m,
	mus_mapy5m,
	mus_mapy6m,
	mus_mapy7m,
	mus_mapy8m,
	mus_mapy9m,
	mus_mapyam,
	mus_mapybm,
	mus_mapycm,
	mus_mapydm,
	mus_mapyem,
	mus_mapyfm,
	mus_mapygm,
	mus_mapyhm,
	mus_mapyim,
	mus_mapyjm,
	mus_mapykm,
	mus_mapylm,
	mus_mapymm,
	mus_mapynm,
	mus_mapyom,
	mus_mapypm,
	mus_mapyqm,
	mus_mapyrm,
	mus_mapysm,
	mus_mapytm,
	mus_mapyum,
	mus_mapyvm,
	mus_mapywm,
	mus_mapyxm,
	mus_mapyym,
	mus_mapyzm,
	mus_mapz0m,
	mus_mapz1m,
	mus_mapz2m,
	mus_mapz3m,
	mus_mapz4m,
	mus_mapz5m,
	mus_mapz6m,
	mus_mapz7m,
	mus_mapz8m,
	mus_mapz9m,
	mus_mapzam,
	mus_mapzbm,
	mus_mapzcm,
	mus_mapzdm,
	mus_mapzem,
	mus_mapzfm,
	mus_mapzgm,
	mus_mapzhm,
	mus_mapzim,
	mus_mapzjm,
	mus_mapzkm,
	mus_mapzlm,
	mus_mapzmm,
	mus_mapznm,
	mus_mapzom,
	mus_mapzpm,
	mus_mapzqm,
	mus_mapzrm,
	mus_mapzsm,
	mus_mapztm,
	mus_mapzum,
	mus_mapzvm,
	mus_mapzwm,
	mus_mapzxm,
	mus_mapzym,
	mus_mapzzm,

	mus_titles, // title screen
	mus_read_m, // intro
	mus_lclear, // level clear
	mus_invinc, // invincibility
	mus_shoes,  // super sneakers
	mus_minvnc, // Mario invincibility
	mus_drown,  // drowning
	mus_gmover, // game over
	mus_xtlife, // extra life
	mus_contsc, // continue screen
	mus_supers, // Super Sonic
	mus_chrsel, // character select
	mus_credit, // credits
	mus_racent, // Race Results
	mus_stjr,   // Sonic Team Jr. Presents

	NUMMUSIC
} musicenum_t;
// Note: song number should be a UINT16, as mapmusic only uses 16 bits for music slot number.
//       (the rest is track number and an internal reload flag)

//
// Identifiers for all sfx in game.
//

// List of sounds (don't modify this comment!)
typedef enum
{
	sfx_None,

	// Skin Sounds
	sfx_altdi1,
	sfx_altdi2,
	sfx_altdi3,
	sfx_altdi4,
	sfx_altow1,
	sfx_altow2,
	sfx_altow3,
	sfx_altow4,
	sfx_victr1,
	sfx_victr2,
	sfx_victr3,
	sfx_victr4,
	sfx_gasp,
	sfx_jump,
	sfx_pudpud,
	sfx_putput,
	sfx_spin,
	sfx_spndsh,
	sfx_thok,
	sfx_zoom,
	sfx_skid,

	// Ambience/background objects/etc
	sfx_ambint,

	sfx_alarm,
	sfx_buzz1,
	sfx_buzz2,
	sfx_buzz3,
	sfx_buzz4,
	sfx_crumbl,
	sfx_fire,
	sfx_grind,
	sfx_laser,
	sfx_mswing,
	sfx_pstart,
	sfx_pstop,
	sfx_steam1,
	sfx_steam2,
	sfx_wbreak,

	sfx_rainin,
	sfx_litng1,
	sfx_litng2,
	sfx_litng3,
	sfx_litng4,
	sfx_athun1,
	sfx_athun2,

	sfx_amwtr1,
	sfx_amwtr2,
	sfx_amwtr3,
	sfx_amwtr4,
	sfx_amwtr5,
	sfx_amwtr6,
	sfx_amwtr7,
	sfx_amwtr8,
	sfx_bubbl1,
	sfx_bubbl2,
	sfx_bubbl3,
	sfx_bubbl4,
	sfx_bubbl5,
	sfx_floush,
	sfx_splash,
	sfx_splish,
	sfx_wdrip1,
	sfx_wdrip2,
	sfx_wdrip3,
	sfx_wdrip4,
	sfx_wdrip5,
	sfx_wdrip6,
	sfx_wdrip7,
	sfx_wdrip8,
	sfx_wslap,

	sfx_doora1,
	sfx_doorb1,
	sfx_doorc1,
	sfx_doorc2,
	sfx_doord1,
	sfx_doord2,
	sfx_eleva1,
	sfx_eleva2,
	sfx_eleva3,
	sfx_elevb1,
	sfx_elevb2,
	sfx_elevb3,

	sfx_ambin2,
	sfx_lavbub,
	sfx_rocks1,
	sfx_rocks2,
	sfx_rocks3,
	sfx_rocks4,
	sfx_rumbam,
	sfx_rumble,

	// Game objects, etc
	sfx_appear,
	sfx_bkpoof,
	sfx_bnce1,
	sfx_bnce2,
	sfx_cannon,
	sfx_cgot,
	sfx_cybdth,
	sfx_deton,
	sfx_ding, // old sfx_appear sound
	sfx_dmpain,
	sfx_drown,
	sfx_fizzle,
	sfx_gbeep,
	sfx_gclose,
	sfx_ghit,
	sfx_gloop,
	sfx_gspray,
	sfx_gravch,
	sfx_itemup,
	sfx_jet,
	sfx_jshard,
	sfx_lose,
	sfx_lvpass,
	sfx_mindig,
	sfx_mixup,
	sfx_monton,
	sfx_pogo,
	sfx_pop,
	sfx_rail1,
	sfx_rail2,
	sfx_rlaunc,
	sfx_shield,
	sfx_shldls,
	sfx_spdpad,
	sfx_spkdth,
	sfx_spring,
	sfx_statu1,
	sfx_statu2,
	sfx_strpst,
	sfx_supert,
	sfx_telept,
	sfx_tink,
	sfx_token,
	sfx_trfire,
	sfx_trpowr,
	sfx_turhit,
	sfx_wdjump,
	sfx_mswarp,
	sfx_mspogo,

	// Menu, interface
	sfx_chchng,
	sfx_dwnind,
	sfx_emfind,
	sfx_flgcap,
	sfx_menu1,
	sfx_oneup,
	sfx_ptally,
	sfx_radio,
	sfx_wepchg,
	sfx_wtrdng,
	sfx_zelda,

	// NiGHTS
	sfx_ideya,
	sfx_xideya, // Xmas
	sfx_nbmper,
	sfx_nxbump, // Xmas
	sfx_ncitem,
	sfx_nxitem, // Xmas
	sfx_ngdone,
	sfx_nxdone, // Xmas
	sfx_drill1,
	sfx_drill2,
	sfx_ncspec,
	sfx_nghurt,
	sfx_ngskid,
	sfx_hoop1,
	sfx_hoop2,
	sfx_hoop3,
	sfx_hidden,
	sfx_prloop,
	sfx_timeup, // Was gonna be played when less than ten seconds are on the clock; uncomment uses of this to see it in-context

	// Mario
	sfx_koopfr,
	sfx_mario1,
	sfx_mario2,
	sfx_mario3,
	sfx_mario4,
	sfx_mario5,
	sfx_mario6,
	sfx_mario7,
	sfx_mario8,
	sfx_mario9,
	sfx_marioa,
	sfx_thwomp,

	// Black Eggman
	sfx_bebomb,
	sfx_bechrg,
	sfx_becrsh,
	sfx_bedeen,
	sfx_bedie1,
	sfx_bedie2,
	sfx_beeyow,
	sfx_befall,
	sfx_befire,
	sfx_beflap,
	sfx_begoop,
	sfx_begrnd,
	sfx_behurt,
	sfx_bejet1,
	sfx_belnch,
	sfx_beoutb,
	sfx_beragh,
	sfx_beshot,
	sfx_bestep,
	sfx_bestp2,
	sfx_bewar1,
	sfx_bewar2,
	sfx_bewar3,
	sfx_bewar4,
	sfx_bexpld,
	sfx_bgxpld,

	// Cy-Brak-Demon
	sfx_beelec, // Electric barrier ambience
	sfx_brakrl, // Rocket launcher
	sfx_brakrx, // Rocket explodes

	// S3&K sounds
	sfx_s3k33,
	sfx_s3k34,
	sfx_s3k35,
	sfx_s3k36,
	sfx_s3k37,
	sfx_s3k38,
	sfx_s3k39,
	sfx_s3k3a,
	sfx_s3k3b,
	sfx_s3k3c,
	sfx_s3k3d,
	sfx_s3k3e,
	sfx_s3k3f,
	sfx_s3k40,
	sfx_s3k41,
	sfx_s3k42,
	sfx_s3k43,
	sfx_s3k44,
	sfx_s3k45,
	sfx_s3k46,
	sfx_s3k47,
	sfx_s3k48,
	sfx_s3k49,
	sfx_s3k4a,
	sfx_s3k4b,
	sfx_s3k4c,
	sfx_s3k4d,
	sfx_s3k4e,
	sfx_s3k4f,
	sfx_s3k50,
	sfx_s3k51,
	sfx_s3k52,
	sfx_s3k53,
	sfx_s3k54,
	sfx_s3k55,
	sfx_s3k56,
	sfx_s3k57,
	sfx_s3k58,
	sfx_s3k59,
	sfx_s3k5a,
	sfx_s3k5b,
	sfx_s3k5c,
	sfx_s3k5d,
	sfx_s3k5e,
	sfx_s3k5f,
	sfx_s3k60,
	sfx_s3k61,
	sfx_s3k62,
	sfx_s3k63,
	sfx_s3k64,
	sfx_s3k65,
	sfx_s3k66,
	sfx_s3k67,
	sfx_s3k68,
	sfx_s3k69,
	sfx_s3k6a,
	sfx_s3k6b,
	sfx_s3k6c,
	sfx_s3k6d,
	sfx_s3k6e,
	sfx_s3k6f,
	sfx_s3k70,
	sfx_s3k71,
	sfx_s3k72,
	sfx_s3k73,
	sfx_s3k74,
	sfx_s3k75,
	sfx_s3k76,
	sfx_s3k77,
	sfx_s3k78,
	sfx_s3k79,
	sfx_s3k7a,
	sfx_s3k7b,
	sfx_s3k7c,
	sfx_s3k7d,
	sfx_s3k7e,
	sfx_s3k7f,
	sfx_s3k80,
	sfx_s3k81,
	sfx_s3k82,
	sfx_s3k83,
	sfx_s3k84,
	sfx_s3k85,
	sfx_s3k86,
	sfx_s3k87,
	sfx_s3k88,
	sfx_s3k89,
	sfx_s3k8a,
	sfx_s3k8b,
	sfx_s3k8c,
	sfx_s3k8d,
	sfx_s3k8e,
	sfx_s3k8f,
	sfx_s3k90,
	sfx_s3k91,
	sfx_s3k92,
	sfx_s3k93,
	sfx_s3k94,
	sfx_s3k95,
	sfx_s3k96,
	sfx_s3k97,
	sfx_s3k98,
	sfx_s3k99,
	sfx_s3k9a,
	sfx_s3k9b,
	sfx_s3k9c,
	sfx_s3k9d,
	sfx_s3k9e,
	sfx_s3k9f,
	sfx_s3ka0,
	sfx_s3ka1,
	sfx_s3ka2,
	sfx_s3ka3,
	sfx_s3ka4,
	sfx_s3ka5,
	sfx_s3ka6,
	sfx_s3ka7,
	sfx_s3ka8,
	sfx_s3ka9,
	sfx_s3kaa,
	sfx_s3kab,
	sfx_s3kac,
	sfx_s3kad,
	sfx_s3kae,
	sfx_s3kaf,
	sfx_s3kb0,
	sfx_s3kb1,
	sfx_s3kb2,
	sfx_s3kb3,
	sfx_s3kb4,
	sfx_s3kb5,
	sfx_s3kb6,
	sfx_s3kb7,
	sfx_s3kb8,
	sfx_s3kb9,
	sfx_s3kba,
	sfx_s3kbb,
	sfx_s3kbcs,
	sfx_s3kbcl,
	sfx_s3kbds,
	sfx_s3kbdl,
	sfx_s3kbes,
	sfx_s3kbel,
	sfx_s3kbfs,
	sfx_s3kbfl,
	sfx_s3kc0s,
	sfx_s3kc0l,
	sfx_s3kc1s,
	sfx_s3kc1l,
	sfx_s3kc2s,
	sfx_s3kc2l,
	sfx_s3kc3s,
	sfx_s3kc3l,
	sfx_s3kc4s,
	sfx_s3kc4l,
	sfx_s3kc5s,
	sfx_s3kc5l,
	sfx_s3kc6s,
	sfx_s3kc6l,
	sfx_s3kc7,
	sfx_s3kc8s,
	sfx_s3kc8l,
	sfx_s3kc9s,
	sfx_s3kc9l,
	sfx_s3kcas,
	sfx_s3kcal,
	sfx_s3kcbs,
	sfx_s3kcbl,
	sfx_s3kccs,
	sfx_s3kccl,
	sfx_s3kcds,
	sfx_s3kcdl,
	sfx_s3kces,
	sfx_s3kcel,
	sfx_s3kcfs,
	sfx_s3kcfl,
	sfx_s3kd0s,
	sfx_s3kd0l,
	sfx_s3kd1s,
	sfx_s3kd1l,
	sfx_s3kd2s,
	sfx_s3kd2l,
	sfx_s3kd3s,
	sfx_s3kd3l,
	sfx_s3kd4s,
	sfx_s3kd4l,
	sfx_s3kd5s,
	sfx_s3kd5l,
	sfx_s3kd6s,
	sfx_s3kd6l,
	sfx_s3kd7s,
	sfx_s3kd7l,
	sfx_s3kd8s,
	sfx_s3kd8l,
	sfx_s3kd9s,
	sfx_s3kd9l,
	sfx_s3kdas,
	sfx_s3kdal,
	sfx_s3kdbs,
	sfx_s3kdbl,

	// free slots for S_AddSoundFx() at run-time --------------------
	sfx_freeslot0,
	//
	// ... 60 free sounds here ...
	//
	sfx_lastfreeslot = sfx_freeslot0 + NUMSFXFREESLOTS-1,
	// end of freeslots ---------------------------------------------

	sfx_skinsoundslot0,
	sfx_lastskinsoundslot = sfx_skinsoundslot0 + NUMSKINSFXSLOTS-1,
	NUMSFX
} sfxenum_t;


void S_InitRuntimeSounds(void);
sfxenum_t S_AddSoundFx(const char *name, boolean singular, INT32 flags, boolean skinsound);
void S_RemoveSoundFx(sfxenum_t id);

#endif
