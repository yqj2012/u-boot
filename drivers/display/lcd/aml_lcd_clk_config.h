/*
 * drivers/display/lcd/aml_lcd_clk_config.h
 *
 * Copyright (C) 2015 Amlogic, Inc. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
*/

#ifndef _LCD_CLK_CONFIG_H
#define _LCD_CLK_CONFIG_H

#include <linux/types.h>
#include <amlogic/aml_lcd.h>

/* **********************************
 * clk config
 * ********************************** */
struct lcd_clk_config_s { /* unit: kHz */
	/* IN-OUT parameters */
	unsigned int fin;
	unsigned int fout;

	/* pll parameters */
	unsigned int od_fb;
	unsigned int pll_m;
	unsigned int pll_n;
	unsigned int pll_fvco;
	unsigned int pll_od1_sel;
	unsigned int pll_od2_sel;
	unsigned int pll_od3_sel;
	unsigned int pll_level;
	unsigned int pll_frac;
	unsigned int pll_fout;
	unsigned int ss_level;
	unsigned int edp_div0;
	unsigned int edp_div1;
	unsigned int div_pre; /* m6, m8, m8b */
	unsigned int div_post; /* m6, m8, m8b */
	unsigned int div_sel; /* g9tv, g9bb, gxbb */
	unsigned int xd;

	/* clk path node parameters */
	unsigned int ss_level_max;
	unsigned int pll_m_max;
	unsigned int pll_m_min;
	unsigned int pll_n_max;
	unsigned int pll_n_min;
	unsigned int pll_frac_range;
	unsigned int pll_od_sel_max;
	unsigned int div_pre_sel_max; /* m6, m8, m8b */
	unsigned int div_post_sel_max; /* m6, m8, m8b */
	unsigned int div_sel_max; /* g9tv, g9bb, gxbb */
	unsigned int xd_max;
	unsigned int pll_ref_fmax;
	unsigned int pll_ref_fmin;
	unsigned int pll_vco_fmax;
	unsigned int pll_vco_fmin;
	unsigned int pll_out_fmax;
	unsigned int pll_out_fmin;
	unsigned int div_pre_in_fmax; /* m6, m8, m8b */
	unsigned int div_pre_out_fmax; /* m6, m8, m8b */
	unsigned int div_post_out_fmax; /* m6, m8, m8b */
	unsigned int div_in_fmax; /* g9tv, g9bb, gxbb */
	unsigned int div_out_fmax; /* g9tv, g9bb, gxbb */
	unsigned int xd_out_fmax;
	unsigned int err_fmin;
};

/* **********************************
 * pll & clk parameter
 * ********************************** */
/* ******** clk calculation ******** */
#define PLL_WAIT_LOCK_CNT           200
 /* frequency unit: kHz */
#define FIN_FREQ                    (24 * 1000)
/* clk max error */
#define MAX_ERROR                   (2 * 1000)

/* ******** register bit ******** */
/* divider */
#define CRT_VID_DIV_MAX             255

#define DIV_PRE_SEL_MAX             6
#define EDP_DIV0_SEL_MAX            15
#define EDP_DIV1_SEL_MAX            8

/* g9tv, g9bb, gxbb divider */
#define CLK_DIV_I2O     0
#define CLK_DIV_O2I     1
enum div_sel_e {
	CLK_DIV_SEL_1 = 0,
	CLK_DIV_SEL_2,    /* 1 */
	CLK_DIV_SEL_3,    /* 2 */
	CLK_DIV_SEL_3p5,  /* 3 */
	CLK_DIV_SEL_3p75, /* 4 */
	CLK_DIV_SEL_4,    /* 5 */
	CLK_DIV_SEL_5,    /* 6 */
	CLK_DIV_SEL_6,    /* 7 */
	CLK_DIV_SEL_6p25, /* 8 */
	CLK_DIV_SEL_7,    /* 9 */
	CLK_DIV_SEL_7p5,  /* 10 */
	CLK_DIV_SEL_12,   /* 11 */
	CLK_DIV_SEL_14,   /* 12 */
	CLK_DIV_SEL_15,   /* 13 */
	CLK_DIV_SEL_2p5,  /* 14 */
	CLK_DIV_SEL_MAX,
};

/* **********************************
 * GXTVBB
 * ********************************** */
/* ******** register bit ******** */
/* PLL_CNTL 0x10c8 */
#define LCD_PLL_LOCK_GXTVBB         31
#define LCD_PLL_EN_GXTVBB           30
#define LCD_PLL_RST_GXTVBB          28
#define LCD_PLL_N_GXTVBB            9
#define LCD_PLL_M_GXTVBB            0

#define LCD_PLL_OD3_GXTVBB          18
#define LCD_PLL_OD2_GXTVBB          22
#define LCD_PLL_OD1_GXTVBB          16

/* ******** frequency limit (unit: kHz) ******** */
/* pll */
#define PLL_FRAC_OD_FB_GXTVBB       0
#define SS_LEVEL_MAX_GXTVBB         5
#define PLL_M_MIN_GXTVBB            2
#define PLL_M_MAX_GXTVBB            511
#define PLL_N_MIN_GXTVBB            1
#define PLL_N_MAX_GXTVBB            1
#define PLL_FRAC_RANGE_GXTVBB       (1 << 10)
#define PLL_OD_SEL_MAX_GXTVBB       3
#define PLL_FREF_MIN_GXTVBB         (5 * 1000)
#define PLL_FREF_MAX_GXTVBB         (25 * 1000)
#define PLL_VCO_MIN_GXTVBB          (3000 * 1000)
#define PLL_VCO_MAX_GXTVBB          (6000 * 1000)

/* video */
#define CLK_DIV_IN_MAX_GXTVBB       (3100 * 1000)
#define CRT_VID_CLK_IN_MAX_GXTVBB   (3100 * 1000)
#define ENCL_CLK_IN_MAX_GXTVBB      (620 * 1000)


/************** GXL **************** */
/* ******** register bit ******** */
/* PLL_CNTL 0x10c8 */
#define LCD_PLL_LOCK_GXL            31
#define LCD_PLL_EN_GXL              30
#define LCD_PLL_RST_GXL             28
#define LCD_PLL_N_GXL               9
#define LCD_PLL_M_GXL               0

#define LCD_PLL_OD3_GXL             19
#define LCD_PLL_OD2_GXL             23
#define LCD_PLL_OD1_GXL             21

/* ******** frequency limit (unit: kHz) ******** */
/* pll */
#define PLL_FRAC_OD_FB_GXL			1
#define SS_LEVEL_MAX_GXL            5
#define PLL_M_MIN_GXL               2
#define PLL_M_MAX_GXL               511
#define PLL_N_MIN_GXL               1
#define PLL_N_MAX_GXL               1
#define PLL_FRAC_RANGE_GXL          (1 << 10)
#define PLL_OD_SEL_MAX_GXL          3
#define PLL_FREF_MIN_GXL            (5 * 1000)
#define PLL_FREF_MAX_GXL            (25 * 1000)
#define PLL_VCO_MIN_GXL             (3000 * 1000)
#define PLL_VCO_MAX_GXL             (6000 * 1000)

/* video */
#define CLK_DIV_IN_MAX_GXL          (3100 * 1000)
#define CRT_VID_CLK_IN_MAX_GXL      (3100 * 1000)
#define ENCL_CLK_IN_MAX_GXL         (620 * 1000)

/* **********************************
 * GXM
 * ********************************** */
/* ******** register bit ******** */
/* PLL_CNTL 0x10c8 */
#define LCD_PLL_LOCK_GXM            31
#define LCD_PLL_EN_GXM              30
#define LCD_PLL_RST_GXM             28
#define LCD_PLL_N_GXM               9
#define LCD_PLL_M_GXM               0

#define LCD_PLL_OD3_GXM             19
#define LCD_PLL_OD2_GXM             23
#define LCD_PLL_OD1_GXM             21

/* ******** frequency limit (unit: kHz) ******** */
/* pll */
#define PLL_FRAC_OD_FB_GXM			1
#define SS_LEVEL_MAX_GXM            5
#define PLL_M_MIN_GXM               2
#define PLL_M_MAX_GXM               511
#define PLL_N_MIN_GXM               1
#define PLL_N_MAX_GXM               1
#define PLL_FRAC_RANGE_GXM          (1 << 10)
#define PLL_OD_SEL_MAX_GXM          3
#define PLL_FREF_MIN_GXM            (5 * 1000)
#define PLL_FREF_MAX_GXM            (25 * 1000)
#define PLL_VCO_MIN_GXM             (3000 * 1000)
#define PLL_VCO_MAX_GXM             (6000 * 1000)

/* video */
#define CLK_DIV_IN_MAX_GXM          (3100 * 1000)
#define CRT_VID_CLK_IN_MAX_GXM      (3100 * 1000)
#define ENCL_CLK_IN_MAX_GXM         (620 * 1000)

/*******  TXL ********************* */
/* ******** register bit ******** */
/* PLL_CNTL 0x10c8 */
#define LCD_PLL_LOCK_TXL            31
#define LCD_PLL_EN_TXL              30
#define LCD_PLL_RST_TXL             28
#define LCD_PLL_N_TXL               9
#define LCD_PLL_M_TXL               0

#define LCD_PLL_OD3_TXL             19
#define LCD_PLL_OD2_TXL             23
#define LCD_PLL_OD1_TXL             21

/* ******** frequency limit (unit: kHz) ******** */
/* pll */
#define PLL_FRAC_OD_FB_TXL			1
#define SS_LEVEL_MAX_TXL            5
#define PLL_M_MIN_TXL               2
#define PLL_M_MAX_TXL               511
#define PLL_N_MIN_TXL               1
#define PLL_N_MAX_TXL               1
#define PLL_FRAC_RANGE_TXL          (1 << 10)
#define PLL_OD_SEL_MAX_TXL          3
#define PLL_FREF_MIN_TXL            (5 * 1000)
#define PLL_FREF_MAX_TXL            (25 * 1000)
#define PLL_VCO_MIN_TXL             (3000 * 1000)
#define PLL_VCO_MAX_TXL             (6000 * 1000)

/* video */
#define CLK_DIV_IN_MAX_TXL          (3100 * 1000)
#define CRT_VID_CLK_IN_MAX_TXL      (3100 * 1000)
#define ENCL_CLK_IN_MAX_TXL         (620 * 1000)

/* **********************************
 * TXLX
 * ********************************** */
/* ******** register bit ******** */
/* PLL_CNTL 0x10c8 */
#define LCD_PLL_LOCK_TXLX            31
#define LCD_PLL_EN_TXLX              30
#define LCD_PLL_RST_TXLX             28
#define LCD_PLL_N_TXLX               9
#define LCD_PLL_M_TXLX               0

#define LCD_PLL_OD3_TXLX             19
#define LCD_PLL_OD2_TXLX             23
#define LCD_PLL_OD1_TXLX             21

/* ******** frequency limit (unit: kHz) ******** */
/* pll */
#define PLL_FRAC_OD_FB_TXLX			0
#define SS_LEVEL_MAX_TXLX            6
#define PLL_M_MIN_TXLX               2
#define PLL_M_MAX_TXLX               511
#define PLL_N_MIN_TXLX               1
#define PLL_N_MAX_TXLX               1
#define PLL_FRAC_RANGE_TXLX          (1 << 10)
#define PLL_OD_SEL_MAX_TXLX          3
#define PLL_FREF_MIN_TXLX            (5 * 1000)
#define PLL_FREF_MAX_TXLX            (25 * 1000)
#define PLL_VCO_MIN_TXLX             (3000 * 1000)
#define PLL_VCO_MAX_TXLX             (6000 * 1000)

/* video */
#define CLK_DIV_IN_MAX_TXLX          (3100 * 1000)
#define CRT_VID_CLK_IN_MAX_TXLX      (3100 * 1000)
#define ENCL_CLK_IN_MAX_TXLX         (620 * 1000)

/* AXG */
/* ******** register bit ******** */
/* PLL_CNTL */
#define LCD_PLL_LOCK_AXG            31
#define LCD_PLL_EN_AXG              30
#define LCD_PLL_RST_AXG             29
#define LCD_PLL_OD_AXG              16
#define LCD_PLL_N_AXG               9
#define LCD_PLL_M_AXG               0

/* ******** frequency limit (unit: kHz) ******** */
/* pll */
#define PLL_FRAC_OD_FB_AXG			0
#define SS_LEVEL_MAX_AXG            5
#define PLL_M_MIN_AXG               2
#define PLL_M_MAX_AXG               511
#define PLL_N_MIN_AXG               1
#define PLL_N_MAX_AXG               1
#define PLL_FRAC_RANGE_AXG          (1 << 10)
#define PLL_OD_SEL_MAX_AXG          3
#define PLL_FREF_MIN_AXG            (5 * 1000)
#define PLL_FREF_MAX_AXG            (25 * 1000)
#define PLL_VCO_MIN_AXG             (1500 * 1000)
#define PLL_VCO_MAX_AXG             (3000 * 1000)

/* video */
#define CRT_VID_CLK_IN_MAX_AXG      (3000 * 1000)
#define ENCL_CLK_IN_MAX_AXG         (200 * 1000)

extern int meson_clk_measure(unsigned int clk_mux);

extern struct lcd_clk_config_s *get_lcd_clk_config(void);
extern void lcd_clk_config_print(void);

extern char *lcd_get_spread_spectrum(void);
extern void lcd_set_spread_spectrum(void);
extern void lcd_clk_update(struct lcd_config_s *pconf);
extern void lcd_clk_set(struct lcd_config_s *pconf);
extern void lcd_clk_disable(void);

extern void lcd_clk_generate_parameter(struct lcd_config_s *pconf);
extern void lcd_clk_config_probe(void);

#endif
