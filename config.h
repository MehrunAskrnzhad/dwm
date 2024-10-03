/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx	= 0;        /* border pixel of windows */
static const unsigned int gappx		= 5;        /* gaps between windows */
static const unsigned int snap		= 32;       /* snap pixel */
static const int swallowfloating	= 0;        /* 1 means swallow floating windows by default */
static const int showbar		= 1;        /* 0 means no bar */
static const int topbar			= 0;        /* 0 means bottom bar */
static const int vertpad		= 5;
static const int sidepad		= 5;

static const char *fonts[] = {
    "monospace:size=10",
    "Font Awesome 6 Free:pixelsize=16:size=16:antialias=true:autohint=true",
    "Font Awesome 6 Free Solid:pixelsize=16:size=16:antialias=true:autohint=true",
    "Font Awesome 6 Brands:pixelsize=16:size=16:antialias=true:autohint=true",
    "JoyPixels:pixelsize=16:size=16:antialias=true:autohint=true",
};

static const char norm_fg[]	= "#928374";
static const char norm_bg[]	= "#282828";
static const char norm_bd[]	= "#282828";

static const char slct_fg[]	= "#FBF1C7";
static const char slct_bg[]	= "#282828";
static const char slct_bd[]	= "#FBF1C7";

static const char *colors[][3]      = {
    /*               fg         bg         border   */
    [SchemeNorm] = { norm_fg, norm_bg, norm_bd },
    [SchemeSel]  = { slct_fg, slct_bg, slct_bd },
};

/* tagging */
static char *tags[] = {"", "", "", "", "", "", ""};

static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* class                        instance                 title           tags mask  isfloating  isterminal  noswallow  monitor */
	{ "Gimp",                       NULL,                    NULL,           0,         1,          0,           0,        -1 },
	{ "Firefox",                    NULL,                    NULL,           1 << 3,    0,          0,          -1,        -1 },
	{ "firefoxdeveloperedition",    NULL,                    NULL,           1 << 3,    0,          0,          -1,        -1 },
	{ "firefoxdeveloperedition",    "Places",                NULL,           1 << 3,    1,          0,          -1,        -1 }, /* Downloads List */
	{ "firefoxdeveloperedition",    "Toolkit",               NULL,           1,         1,          0,          -1,        -1 }, /* Picture In Picture Video */
	{ "Spotify",                    "spotify",               NULL,           1 << 6,    0,          0,           0,        -1 }, /* Picture In Picture Video */
	{ "st",                         NULL,                    NULL,           0,         0,          1,           0,        -1 },
	{ "Alacritty",                  NULL,                    NULL,           0,         0,          1,           0,        -1 },
	{ "kitty",                      NULL,                    NULL,           0,         0,          1,           0,        -1 },
	{ "Hiddify",                    NULL,                    NULL,           0,         1,          0,           0,        -1 },
	{ "Localsend_app",              "localsend_app",         NULL,           0,         1,          0,           0,        -1 },
	{ "Surf", 			"surf",			 "surf", 	 0, 	    1,          0,           0,        -1 },
	{ "zenity",                     "zenity",                NULL,           0,         1,          0,           1,        -1 }, /* zenity dialogs */
	{ "Yad",                        "yad",                   NULL,           0,         1,          0,           1,        -1 }, /* yad dialogs */
	{ NULL,                         NULL,                    "Event Tester", 0,         0,          0,           1,        -1 }, /* xev */
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
    /* symbol     arrange function */
    {"", tile}, /* first entry is default */
    {"", NULL}, /* no layout function means floating behavior */
    {"", monocle},
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#define STATUSBAR "dwmblocks"

static Key keys[] = {
    /* modifier                     key        function        argument */
    { MODKEY,                       XK_b,      togglebar,      {0} },
    { Mod1Mask,                     XK_Tab,    focusstack,     {.i = +1} },
    { MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
    { MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
    { MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
    { MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
    { MODKEY|ShiftMask,		        XK_Return, zoom,           {0} },
    { MODKEY,                       XK_Tab,    view,           {0} },
    { MODKEY,			            XK_q,      killclient,     {0} },
    { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
    { MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
    { MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
    { MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
    { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
    TAGKEYS(                        XK_1,                      0)
    TAGKEYS(                        XK_2,                      1)
    TAGKEYS(                        XK_3,                      2)
    TAGKEYS(                        XK_4,                      3)
    TAGKEYS(                        XK_5,                      4)
    TAGKEYS(                        XK_6,                      5)
    TAGKEYS(                        XK_7,                      6)
    TAGKEYS(                        XK_8,                      7)
    TAGKEYS(                        XK_9,                      8)
    { MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click                event mask      button          function        argument */
    { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
    { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
    { ClkWinTitle,          0,              Button2,        zoom,           {0} },
    { ClkStatusText,        0,              Button1,        sigstatusbar,   {.i = 1} },
    { ClkStatusText,        0,              Button2,        sigstatusbar,   {.i = 2} },
    { ClkStatusText,        0,              Button3,        sigstatusbar,   {.i = 3} },	
    { ClkStatusText,        0,              Button4,        sigstatusbar,   {.i = 4} },	
    { ClkStatusText,        0,              Button5,        sigstatusbar,   {.i = 5} },	
    { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
    { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
    { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
    { ClkTagBar,            0,              Button1,        view,           {0} },
    { ClkTagBar,            0,              Button3,        toggleview,     {0} },
    { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

// vim: ft=c:fdm=marker
