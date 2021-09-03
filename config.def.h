/* appearance */
static const unsigned int borderpx    = 1;      /* border pixel of windows */
static const unsigned int snap        = 30;     /* snap pixel */
static const unsigned int gappih      = 6;      /* horiz inner gap between windows */
static const unsigned int gappiv      = 6;      /* vert inner gap between windows */
static const unsigned int gappoh      = 6;      /* horiz outer gap between windows and screen edge */
static const unsigned int gappov      = 15;     /* vert outer gap between windows and screen edge */
static const int smartgaps            = 0;      /* 1 means no outer gap when there is only one window */
static const int showbar              = 1;      /* 0 means no bar */
static const int topbar               = 1;      /* 0 means bottom bar */
static const double activeopacity     = 1.0f;   /* Window opacity when it's focused (0 <= opacity <= 1) */
static const double inactiveopacity   = 0.875f; /* Window opacity when it's inactive (0 <= opacity <= 1) */
static const int user_bh              = 22;     /* bar height */ 
static const char *fonts[]            = {"Montserrat Semi Bold:size=9:antialias=true:autohint=true",
                                         "FiraCode Nerd Font:size=10:antialias=true:autohint=true"};
static const char *colors[][3]        = {
/* type                fg         bg          border    */ 
[SchemeNorm]      = { "#ECEFF4", "#2E3440",  "#000000"  },
[SchemeSel]       = { "#2E3440", "#8FBCBB",  "#ECEFF4"  },
[SchemeTagsNorm]  = { "#ECEFF4", "#2E3440",  "#000000"  },
[SchemeTagsSel]   = { "#2E3440", "#8FBCBB",  "#000000"  }, 
[SchemeInfoNorm]  = { "#2E3440", "#2E3440",  "#000000"  },
[SchemeInfoSel]   = { "#2E3440", "#8FBCBB",  "#000000"  },
[SchemeStatus]    = { "#ECEFF4", "#2E3440",  "#000000"  }, 
};

/* tagging */
//static const char *tags[] = {  "1", "2", "3", "4", "5", "6", "7", "8", "9" }; 
//static const char *tags[] = {  "  ", "  ", "  ", "  ", "  ", "  ", }; 
static const char *tags[] = { "web", "dev", "mus", "chat", "vid", "doc", "sys", }; 
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact        = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster        = 1;    /* number of clients in master area */
static const int resizehints    = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1;    /* 1 will force focus on the fullscreen window */
static const Layout layouts[]   = {
	/* symbol     arrange  function */
	{ "| ﰧ  |",      tile },     /*  first entry is default */
	{ "|    |",      NULL },     /* no layout function means floating behavior */
	{ "| M  |",    monocle },
};

/* Defining shell cmd and function keys libs */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#include <X11/XF86keysym.h>

/* Defining Application */
static char dmenumon[2]       = "0";    /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-p", "Run:", NULL };
static const char *termcmd[]  = { "alacritty", NULL };

/* Defining Volume and Brightness Keys */
static const char *upvol[]          = { "/usr/bin/pactl",       "set-sink-volume",   "0", "+5%",     NULL };
static const char *downvol[]        = { "/usr/bin/pactl",       "set-sink-volume",   "0", "-5%",     NULL };
static const char *mutevol[]        = { "/usr/bin/pactl",       "set-sink-mute",     "0", "toggle",  NULL };
static const char *upbrightness[]   = { "/usr/bin/xbacklight",  "-inc",                   "10",      NULL };
static const char *downbrightness[] = { "/usr/bin/xbacklight",  "-dec",                   "10",      NULL };

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,                       view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,                       toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,                       tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,                       toggletag,      {.ui = 1 << TAG} },

/* Key Bindings */
static Key keys[] = {
	/* modifier                     key                        function        argument */
	{ MODKEY,                       XK_space,                  spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return,                 spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_w,                      spawn,          SHCMD("$BROWSER") },
	{ MODKEY,                       XK_m,                      spawn,          SHCMD("spotify") },
	{ MODKEY,                       XK_e,                      spawn,          SHCMD("code") },
	{ MODKEY,                       XK_p,                      spawn,          SHCMD("pcmanfm") },
	{ MODKEY|ShiftMask,             XK_j,                      rotatestack,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,                      rotatestack,    {.i = -1 } },
	{ MODKEY,                       XK_j,                      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,                      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,                      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,                      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,                      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,                      setmfact,       {.f = +0.05} },
  { MODKEY|ShiftMask,             XK_equal,                  togglegaps,     {0} },
	{ MODKEY|ShiftMask,             XK_b,                      togglebar,      {0} },
	{ MODKEY|ShiftMask,             XK_f,                      togglefullscr,  {0} },
  { MODKEY|ShiftMask,             XK_Return,                 zoom,           {0} },
	{ MODKEY,                       XK_Tab,                    view,           {0} },
	{ MODKEY,                       XK_q,                      killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_t,                      setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ShiftMask,             XK_m,                      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,             XK_space,                  setlayout,      {0} },
	{ MODKEY,                       XK_0,                      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,                      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,                  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period,                 focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,                  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,                 tagmon,         {.i = +1 } },
	{ 0,                            XF86XK_AudioRaiseVolume,   spawn,          {.v = upvol   } },
  { 0,                            XF86XK_AudioLowerVolume,   spawn,          {.v = downvol } },
	{ 0,                            XF86XK_AudioMute,          spawn,          {.v = mutevol } },
	{ 0,                            XF86XK_MonBrightnessUp,    spawn,          {.v = upbrightness } },
	{ 0,                            XF86XK_MonBrightnessDown,  spawn,          {.v = downbrightness } },
  { MODKEY|ShiftMask,             XK_q,                      quit,           {0} },
	TAGKEYS(                        XK_1,                                      0)
	TAGKEYS(                        XK_2,                                      1)
	TAGKEYS(                        XK_3,                                      2)
	TAGKEYS(                        XK_4,                                      3)
	TAGKEYS(                        XK_5,                                      4)
	TAGKEYS(                        XK_6,                                      5)
	TAGKEYS(                        XK_7,                                      6)
/*  { MODKEY|Mod1Mask,              XK_h,                      incrgaps,       {.i = +1 } },
    { MODKEY|Mod1Mask,              XK_l,                      incrgaps,       {.i = -1 } },
    { MODKEY|Mod1Mask|ShiftMask,    XK_h,                      incrogaps,      {.i = +1 } },
    { MODKEY|Mod1Mask|ShiftMask,    XK_l,                      incrogaps,      {.i = -1 } },
    { MODKEY|Mod1Mask|ControlMask,  XK_h,                      incrigaps,      {.i = +1 } },
    { MODKEY|Mod1Mask|ControlMask,  XK_l,                      incrigaps,      {.i = -1 } },
    { MODKEY|Mod1Mask|ShiftMask,    XK_0,                      defaultgaps,    {0} },
    { MODKEY,                       XK_y,                      incrihgaps,     {.i = +1 } },
    { MODKEY,                       XK_o,                      incrihgaps,     {.i = -1 } },
    { MODKEY|ControlMask,           XK_y,                      incrivgaps,     {.i = +1 } },
    { MODKEY|ControlMask,           XK_o,                      incrivgaps,     {.i = -1 } },
    { MODKEY|Mod1Mask,              XK_y,                      incrohgaps,     {.i = +1 } },
    { MODKEY|Mod1Mask,              XK_o,                      incrohgaps,     {.i = -1 } },
    { MODKEY|ShiftMask,             XK_y,                      incrovgaps,     {.i = +1 } },
    { MODKEY|ShiftMask,             XK_o,                      incrovgaps,     {.i = -1 } },  
	  { Mod1Mask|ShiftMask,           XK_space,                  togglefloating, {0} },
  	{ MODKEY|ShiftMask,             XK_f,                      setlayout,      {.v = &layouts[1]} }, */
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

